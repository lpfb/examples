import socket
import fcntl
import os
import errno
from time import sleep

HOST = "localhost"
PORT = 65432


def creat_socket():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    return s


def wait_for_server(s, host, port):
    while(True):
        try:
            s.connect((host, port))
            break
        except ConnectionRefusedError:
            continue

    fcntl.fcntl(s, fcntl.F_SETFL, os.O_NONBLOCK)
    print("Connected")


def get_socket_data(s):
    msg = None

    try:
        msg = s.recv(4096)
    except socket.error as e:
        err = e.args[0]
        if err == errno.EAGAIN or err == errno.EWOULDBLOCK:
            msg = ""
            sleep(1)
        else:
            # a "real" error occurred
            print(f'Error: {err}')
            exit(1)

    return msg


def send_socket_data(s, data):
    try:
        s.sendall(data.encode('utf-8'))
    except BrokenPipeError:
        print("Server disconnected")
        return -1

    return 0


s = creat_socket()
print("Trying to connect to server socket")

try:
    while(True):
        s = creat_socket()
        wait_for_server(s, HOST, PORT)

        while(True):
            data = "CLIENT"
            ret = send_socket_data(s, data)

            if(ret < 0):
                s.close()
                break

            data = get_socket_data(s)

            if(data is not None and data):
                print(f"Rx: {data.decode('utf-8')}")

            if(data is None):
                break


            sleep(0.3)

except KeyboardInterrupt:
    print("CTRL+C pressed, exiting program")
    s.close()
    exit(0)
