import socket
from Crypto.PublicKey import RSA
from Crypto.Signature.pkcs1_15 import PKCS115_SigScheme
from Crypto.Hash import SHA256
import binascii

# Generate RSA key pair
keyPair = RSA.generate(bits=1024)
pubKey = keyPair.publickey()

def handle_client(client_socket):
    # Receive message to sign
    msg_to_sign = client_socket.recv(1024).decode()
    hash = SHA256.new(msg_to_sign.encode())
    signer = PKCS115_SigScheme(keyPair)
    signature = signer.sign(hash)
    client_socket.send(binascii.hexlify(signature))

    # Receive message and signature to verify
    msg_to_verify = client_socket.recv(1024).decode()
    signature_to_verify = binascii.unhexlify(client_socket.recv(1024).decode())
    hash = SHA256.new(msg_to_verify.encode())
    verifier = PKCS115_SigScheme(pubKey)
    try:
        verifier.verify(hash, signature_to_verify)
        client_socket.send(b"Signature is valid.")
    except:
        client_socket.send(b"Signature is invalid.")

    client_socket.close()

def main():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind(("0.0.0.0", 9999))
    server.listen(5)
    print("Server listening on port 9999")

    while True:
        client_socket, addr = server.accept()
        print(f"Accepted connection from {addr}")
        handle_client(client_socket)

if __name__ == "__main__":
    main()