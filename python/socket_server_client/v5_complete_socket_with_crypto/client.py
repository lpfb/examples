import socket
import fcntl
import os
import errno
from time import sleep

# Wireshark filter (tcp.port == 52456)

class server_socket():
    def __init__(self, host, port):
        self.host = host
        self.port = port
        self.socket_fd = None
        self.create_socket()

    def create_socket(self):
        self.socket_fd = socket.socket(socket.AF_INET, socket.SOCK_STREAM)


    def wait_for_server(self):
        while(True):
            try:
                self.socket_fd.connect((self.host, self.port))
                break
            except ConnectionRefusedError:
                continue

        fcntl.fcntl(self.socket_fd, fcntl.F_SETFL, os.O_NONBLOCK)


    def get_socket_data(self):
        msg = None

        try:
            msg = self.socket_fd.recv(4096)
        except socket.error as e:
            err = e.args[0]
            if err == errno.EAGAIN or err == errno.EWOULDBLOCK:
                msg = ""
                sleep(1)
            else:
                # a "real" error occurred
                print(f'Error: {err}')

        return msg


    def send_socket_data(self, data):
        try:
            self.socket_fd.sendall(data.encode('utf-8'))
        except BrokenPipeError:
            print("Server disconnected")
            return -1

        return 0

    def close(self):
        self.socket_fd.close()