import socket

HOST = "127.0.0.1"  # Standard loopback interface address (localhost)
PORT = 65432  # Port to listen on (non-privileged ports are > 1023)

# AF_INET: IPv4
# SOCK_STREAM: Protocolo TCP
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT)) # associating the socket with an interface and port

    s.listen() # enable server to accept client conections

    # Blocks until receive a client conection
    # conn: Object representting client connection
    # addr: Conected client IP and port
    conn, addr = s.accept()

    # Sending massage back to the client
    with conn:
        print(f"Connected by {addr}")
        while True:
            data = conn.recv(1024) # Waiting for client packet with a byte up to 1024 bytes
            if not data: # If socket was closed by client
                break
            conn.sendall(data) # Send client packet back
