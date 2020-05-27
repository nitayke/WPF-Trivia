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

msg = '{"username": "nitayke", "password": "1234567890"}'
print("Sending: 0000" + str(len(msg)) + str(msg)) # supposed to be 1
sock.sendall(bytes([0, 0, 0, 0, len(str(msg))]) + str(msg).encode())
sock.recv(1024)

msg = '{"username": "nitayke", "password": "1234567890", "email": "nitayke1@gmail.com"}'
print("Sending: 1000" + str(len(msg)) + str(msg)) # supposed to be 0
sock.sendall(bytes([1, 0, 0, 0, len(str(msg))]) + str(msg).encode())
sock.recv(1024)

msg = '{"username": "nitayke", "password": "123456", "email": "nitayke123@gmail.com"}'
print("Sending: 1000" + str(len(str(msg))) + str(msg)) # supposed to be 1
sock.sendall(bytes([1, 0, 0, 0, len(str(msg))]) + str(msg).encode())
sock.recv(1024)

msg = '{"username": "nitayke", "password": "1234567890"}'
print("Sending: 0000" + str(len(str(msg))) + str(msg)) # supposed to be 0
sock.sendall(bytes([0, 0, 0, 0, len(str(msg))]) + str(msg).encode())
sock.recv(1024)

msg = '{"username": "nitayke", "password": "1234567890"}'
print("Sending: 0000" + str(len(str(msg))) + str(msg)) # supposed to be 3
sock.sendall(bytes([0, 0, 0, 0, len(str(msg))]) + str(msg).encode())
sock.recv(1024)

sock.close()