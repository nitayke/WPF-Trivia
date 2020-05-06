import socket

SERVER_IP = "127.0.0.1"
SERVER_PORT = 2222

try:
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    print("Socket successfully created")
except socket.error as err:
    print("socket creation failed with error %s") % err

server_address = (SERVER_IP, SERVER_PORT)
sock.connect(server_address)

server_msg = sock.recv(5)
print(server_msg.decode())

if server_msg == "Hello":
    client_msg = "Hello"
    sock.sendall(client_msg.encode())

sock.close()