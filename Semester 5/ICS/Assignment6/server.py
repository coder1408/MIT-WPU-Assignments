import random
import socket

def generate_private_key(p):
    return random.randint(2, p - 2)

def compute_public_key(private_key, g, p):
    return pow(g, private_key, p)

def compute_shared_secret(received_public_key, private_key, p):
    return pow(received_public_key, private_key, p)

def main():
    # Parameters
    p = 23  # A small prime number for simplicity
    g = 5   # A small base for simplicity
    
    # Generate server's private and public keys
    server_private_key = generate_private_key(p)
    server_public_key = compute_public_key(server_private_key, g, p)
    
    # Setup socket connection
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(('localhost', 12345))
    server_socket.listen(1)
    print("Server is listening for connections...")
    
    conn, addr = server_socket.accept()
    print("Connected to client.")
    
    # Send public key to client
    conn.sendall(server_public_key.to_bytes(2, byteorder='big'))
    
    # Receive client's public key
    client_public_key = int.from_bytes(conn.recv(2), byteorder='big')
    
    # Compute the shared secret
    shared_secret = compute_shared_secret(client_public_key, server_private_key, p)
    print(f"Shared Secret: {shared_secret}")
    
    conn.close()

if __name__ == "__main__":
    main()
