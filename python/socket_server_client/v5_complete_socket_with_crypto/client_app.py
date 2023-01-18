from time import sleep
import client as cl
import crypto as cp

def main():
	print("===Starting Client App===")

	print("#> Generating crypto keys")
	crypt = cp.crypto("client_pub.pm", "client_priv.pm")

	try:
	    while(True):
	        print("Trying to connect to server socket")
	        server = cl.server_socket("localhost", 65432)
	        server.wait_for_server()

	        server_pub_key = server.get_socket_data()
	        print(server_pub_key)
	        exit()

	        while(True):
	            data = "CLIENT"
	            ret = server.send_socket_data(data)

	            if(ret < 0):
	                server.close()
	                break

	            data = server.get_socket_data()

	            if(data is not None and data):
	                print(f"Rx: {data.decode('utf-8')}")

	            if(data is None):
	                break

	            sleep(0.3)

	except KeyboardInterrupt:
	    print("CTRL+C pressed, exiting program")
	    server.close()
	    exit(0)

if __name__ == "__main__":
    main()