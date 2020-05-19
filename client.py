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

msg = {"username": "nitayke", "password": "1234567890", "email": "nitayke1@gmail.com"}
sock.sendall(bytes([1, 0, 0, 0, len(str(msg))]) + str(msg).encode())
print(sock.recv(1024).decode())

msg = {"username": "nitayke", "password": "1234567890"}
sock.sendall(bytes([0, 0, 0, 0, len(str(msg))]) + str(msg).encode())
print(sock.recv(1024).decode())

sock.close()

