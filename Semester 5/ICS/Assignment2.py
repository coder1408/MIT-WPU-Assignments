def feistel_function(data, key):
    # Example Feistel function: simple XOR with the key
    return data ^ key

def feistel_encrypt(plaintext, rounds, key):
    # Split plaintext into left and right halves
    left = plaintext >> 8
    right = plaintext & 0xFF
    
    for _ in range(rounds):
        temp = right
        right = left ^ feistel_function(right, key)
        left = temp
        
    # Combine left and right halves
    ciphertext = (left << 8) | right
    return ciphertext

def feistel_decrypt(ciphertext, rounds, key):
    # Split ciphertext into left and right halves
    left = ciphertext >> 8
    right = ciphertext & 0xFF
    
    for _ in range(rounds):
        temp = left
        left = right ^ feistel_function(left, key)
        right = temp
        
    # Combine left and right halves
    plaintext = (left << 8) | right
    return plaintext

def text_to_hex(text):
    hex_text = text.encode('utf-8').hex()
    return int(hex_text, 16)

def hex_to_text(hex_num):
    hex_text = hex(hex_num)[2:]
    bytes_object = bytes.fromhex(hex_text)
    return bytes_object.decode('utf-8')

# Get input from the user
plaintext_text = input("Enter the plaintext in English: ")
plaintext = text_to_hex(plaintext_text[:2])  # Only using the first 2 characters for simplicity
rounds = int(input("Enter the number of rounds: "))
key = int(input("Enter the key (as an 8-bit hexadecimal number, e.g., 0x3F): "), 16)

# Encrypt and decrypt the plaintext
ciphertext = feistel_encrypt(plaintext, rounds, key)
decrypted = feistel_decrypt(ciphertext, rounds, key)
decrypted_text = hex_to_text(decrypted)

# Print the results
print(f"Plaintext: {plaintext_text[:2]}")
print(f"Plaintext (hex): 0x{plaintext:04X}")
print(f"Ciphertext: 0x{ciphertext:04X}")
print(f"Decrypted (hex): 0x{decrypted:04X}")
print(f"Decrypted text: {decrypted_text}")
