import socket
import hashlib

def sha1_hash(data):
    sha1 = hashlib.sha1()
    sha1.update(data.encode('utf-8'))
    return sha1.hexdigest()

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(('localhost', 8080))
server_socket.listen(1)
print("Server listening on port 8080...")

USERNAME = "user"
PASSWORD_HASH = sha1_hash("password")

while True:
    client_socket, client_address = server_socket.accept()
    print(f"Connection from {client_address} has been established!")

    client_socket.sendall(b"Enter username: ")
    username = client_socket.recv(1024).decode('utf-8').strip()

    client_socket.sendall(b"Enter password: ")
    password = client_socket.recv(1024).decode('utf-8').strip()

    if username == USERNAME and sha1_hash(password) == PASSWORD_HASH:
        client_socket.sendall(b"Authentication successful!\n")
    else:
        client_socket.sendall(b"Authentication failed!\n")

    client_socket.close()
