from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad
from Crypto.Random import get_random_bytes

def encrypt(plaintext, key):
    cipher = AES.new(key, AES.MODE_CBC)
    ciphertext = cipher.encrypt(pad(plaintext, AES.block_size))
    return cipher.iv + ciphertext

def decrypt(ciphertext, key):
    iv = ciphertext[:AES.block_size]
    cipher = AES.new(key, AES.MODE_CBC, iv)
    plaintext = unpad(cipher.decrypt(ciphertext[AES.block_size:]), AES.block_size)
    return plaintext

def main():
    key = get_random_bytes(16)  # 16 bytes = 128 bits key
    
    plaintext = input('Enter the plaintext: ').encode()

    print(f'Original plaintext: {plaintext}')
    print(f'Key = {key}')

    ciphertext = encrypt(plaintext, key)
    print(f'Ciphertext: {ciphertext.hex()}')

    decrypted = decrypt(ciphertext, key)
    print(f'Decrypted text: {decrypted}')

if __name__ == "__main__":
    main()
