#Caesar Cipher

def caesar_cipher_encrypt(plaintext, shift):
    encrypted_message = []
    
    for char in plaintext:
        if char.isalpha():
            shift_amount = shift % 26  # Ensure the shift is within the range of 0-25
            if char.islower():
                encrypted_char = chr((ord(char) - ord('a') + shift_amount) % 26 + ord('a'))
            else:
                encrypted_char = chr((ord(char) - ord('A') + shift_amount) % 26 + ord('A'))
            encrypted_message.append(encrypted_char)
        else:
            encrypted_message.append(char)
    
    return ''.join(encrypted_message)

def main():
    plaintext = input("Enter the plaintext message: ")
    shift = int(input("Enter the shift amount: "))
    encrypted_message = caesar_cipher_encrypt(plaintext, shift)
    
    print(f"Encrypted Message: {encrypted_message}")

if __name__ == "__main__":
    main()
