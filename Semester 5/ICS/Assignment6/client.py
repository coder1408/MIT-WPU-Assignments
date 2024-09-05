import random
import socket

def generate_private_key(p):
    return random.randint(2, p - 2)

def compute_public_key(private_key, g, p):
    return pow(g, private_key, p)

def compute_shared_secret(received_public_key, private_key, p):
    return pow(received_public_key, private_key, p)

def main():
    # Parameters (must match the server's parameters)
    p = 23  # A small prime number for simplicity
    g = 5   # A small base for simplicity
    
    # Generate client's private and public keys
    client_private_key = generate_private_key(p)
    client_public_key = compute_public_key(client_private_key, g, p)
    
    # Setup socket connection
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect(('localhost', 12345))
    
    # Receive server's public key
    server_public_key = int.from_bytes(client_socket.recv(2), byteorder='big')
    
    # Send public key to server
    client_socket.sendall(client_public_key.to_bytes(2, byteorder='big'))
    
    # Compute the shared secret
    shared_secret = compute_shared_secret(server_public_key, client_private_key, p)
    print(f"Shared Secret: {shared_secret}")
    
    client_socket.close()

if __name__ == "__main__":
    main()
