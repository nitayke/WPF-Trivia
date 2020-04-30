import socket

SERVER_IP = "127.0.0.1"
SERVER_PORT = 2222

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_address = (SERVER_IP, SERVER_PORT)
sock.connect(server_address)

server_msg = sock.recv(5)
server_msg = server_msg.decode()
if server_msg == "Hello":
    client_msg = "Hello"
    sock.sendall(client_msg.encode())