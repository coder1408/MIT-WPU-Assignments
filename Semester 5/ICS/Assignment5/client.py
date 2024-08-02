import socket

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect(('localhost', 8080))

response = client_socket.recv(1024)
print(response.decode('utf-8'))
username = input()
client_socket.sendall(username.encode('utf-8'))

response = client_socket.recv(1024)
print(response.decode('utf-8'))
password = input()
client_socket.sendall(password.encode('utf-8'))

response = client_socket.recv(1024)
print(response.decode('utf-8'))

client_socket.close()
