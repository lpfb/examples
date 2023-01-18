import socket
import fcntl
import os
import errno
from time import sleep

HOST = "127.0.0.1"
PORT = 65432


def creat_socket(host, port):
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind((HOST, PORT))
    s.listen()
    fcntl.fcntl(s, fcntl.F_SETFL, os.O_NONBLOCK)
    return s


def wait_for_client(s):
    while(True):
        try:
            conn, addr = s.accept()
            break
        except BlockingIOError:
            sleep(0.3)

    fcntl.fcntl(s, fcntl.F_SETFL, os.O_NONBLOCK)
    print("Connected")
    return conn, addr


def get_socket_data(conn):
    msg = None

    try:
        msg = conn.recv(1024)
    except socket.error as e:
        err = e.args[0]
        if err == errno.ECONNRESET:
            print("Client Disconnected")

    return msg


s = creat_socket(HOST, PORT)

try:
    while(True):
        conn, addr = wait_for_client(s)

        with conn:
            print(f"Connected by {addr}")
            while True:
                data = get_socket_data(conn)

                if(data is None):
                    break

                print(data)
                conn.sendall(data)
except KeyboardInterrupt:
    print("CTRL+C pressed, finishing program")
    s.close()
    exit(0)
