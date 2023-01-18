from time import sleep
import server as sv
import crypto as cp

def main():
    print("===Starting Server App===")
    print("#> Generating crypto keys")
    crypt = cp.crypto("server_pub.pm", "server_priv.pm")


    server = sv.server_socket("localhost", 65432)

    try:
        while(True):
            print("Waiting client connection")
            server.wait_for_client()

            with server._client_socket:
                print(f"Connected by {server._client_addr}")

                print(f"Sending server public key {crypt.public_key}")
                server.send_data(crypt.public_key)
                exit()

                while True:
                    data = "SERVER"
                    server.send_data(data.encode('utf-8'))

                    data = server.receive_data()
                    if(data is None):
                        break
                    print(f"Rx: {data.decode('utf-8')}")


    except KeyboardInterrupt:
        print("CTRL+C pressed, finishing program")
        s.close()
        exit(0)

if __name__ == "__main__":
    main()