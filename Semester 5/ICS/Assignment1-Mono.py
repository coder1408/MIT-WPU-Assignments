#Monoalphabetic Cipher
import string
import random

def generate_cipher_alphabet():
    alphabet = list(string.ascii_lowercase)
    shuffled_alphabet = alphabet[:]
    random.shuffle(shuffled_alphabet)
    return dict(zip(alphabet, shuffled_alphabet))

def encrypt_message(plaintext, cipher_alphabet):
    encrypted_message = []
    for char in plaintext:
        if char.isalpha():
            if char.islower():
                encrypted_message.append(cipher_alphabet[char])
            else:
                encrypted_message.append(cipher_alphabet[char.lower()].upper())
        else:
            encrypted_message.append(char)
    return ''.join(encrypted_message)

def main():
    plaintext = input("Enter the plaintext message: ")
    cipher_alphabet = generate_cipher_alphabet()
    encrypted_message = encrypt_message(plaintext, cipher_alphabet)
    
    print(f"Cipher Alphabet: {cipher_alphabet}")
    print(f"Encrypted Message: {encrypted_message}")

if __name__ == "__main__":
    main()
