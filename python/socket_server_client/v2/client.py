import socket
import time

HOST = "127.0.0.1"  # Standard loopback interface address (localhost)
PORT = 65432  # Port to listen on (non-privileged ports are > 1023)

# AF_INET: IPv4
# SOCK_STREAM: Protocolo TCP
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    print("Trying to connect to server socket")

    try:
        while(True):
            try:
                s.connect((HOST, PORT))
                break
            except ConnectionRefusedError:
                time.sleep(0.3)
                continue
        print("Connected")

        s.sendall(b"Hello, world")
        data = s.recv(1024)

        print(f"Received {data!r}")
    except KeyboardInterrupt:
        print("CTRL+C pressed, exiting program")
        exit(0)
