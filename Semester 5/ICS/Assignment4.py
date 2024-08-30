import random
from sympy import isprime, mod_inverse

# Function to generate a prime number
def generate_prime(bits=8):
    while True:
        num = random.getrandbits(bits)
        if isprime(num):
            return num

# Function to generate RSA keys
def generate_rsa_keys(bits=8):
    p = generate_prime(bits)
    q = generate_prime(bits)
    n = p * q
    phi_n = (p - 1) * (q - 1)

    e = 65537  # A common choice for e

    # Compute d, the modular multiplicative inverse of e mod phi_n
    d = mod_inverse(e, phi_n)
    
    return (e, n), (d, n)  # public_key, private_key

# Function to encrypt a message
def encrypt(message, public_key):
    e, n = public_key
    return [pow(ord(char), e, n) for char in message]

# Function to decrypt a message
def decrypt(encrypted_message, private_key):
    d, n = private_key
    return ''.join([chr(pow(char, d, n)) for char in encrypted_message])

# Example usage
public_key, private_key = generate_rsa_keys(bits=8)

message = "Hello!"
print(f"Original Message: {message}")

encrypted_message = encrypt(message, public_key)
print(f"Encrypted Message: {encrypted_message}")

decrypted_message = decrypt(encrypted_message, private_key)
print(f"Decrypted Message: {decrypted_message}")
