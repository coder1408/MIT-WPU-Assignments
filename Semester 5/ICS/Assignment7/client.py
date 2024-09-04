import socket
import binascii

def main():
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect(("127.0.0.1", 9999))

    # Send message to sign
    msg_to_sign = input("Enter the message to sign: ")
    client.send(msg_to_sign.encode())
    signature = client.recv(1024).decode()
    print("Signature:", signature)

    # Send message and signature to verify
    msg_to_verify = input("Enter the message to verify: ")
    client.send(msg_to_verify.encode())
    client.send(signature.encode())
    verification_result = client.recv(1024).decode()
    print(verification_result)

    client.close()

if __name__ == "__main__":
    main()