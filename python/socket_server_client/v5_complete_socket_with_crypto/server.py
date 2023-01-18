import socket
import fcntl
import os
import errno
from time import sleep

class server_socket():
    def __init__(self, host, port):
        self.host = host
        self.port = port
        self.socket_fd = None
        self._client_socket = None
        self._client_addr = None
        self.create_socket()


    def create_socket(self):
        self.socket_fd = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.socket_fd.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.socket_fd.bind((self.host, self.port))
        self.socket_fd.listen(1)
        fcntl.fcntl(self.socket_fd, fcntl.F_SETFL, os.O_NONBLOCK)


    def wait_for_client(self):
        while(True):
            try:
                self._client_socket,  self._client_addr = self.socket_fd.accept()
                break
            except BlockingIOError:
                self._client_socket = None
                sleep(0.3)


    def receive_data(self):
        msg = None

        try:
            msg = self._client_socket.recv(1024)
        except socket.error as e:
            err = e.args[0]
            if err == errno.ECONNRESET:
                print("Client Disconnected")

        return msg

    def send_data(self, message):
        self._client_socket.sendall(message)