from Crypto.PublicKey import RSA
from Crypto.Signature.pkcs1_15 import PKCS115_SigScheme
from Crypto.Hash import SHA256
import binascii

# Generate RSA key pair
keyPair = RSA.generate(bits=1024)
pubKey = keyPair.publickey()

# Take input from the user for the message to sign
msg_to_sign = input("Enter the message to sign: ").encode()

# Sign the message
hash = SHA256.new(msg_to_sign)
signer = PKCS115_SigScheme(keyPair)
signature = signer.sign(hash)
print("Signature:", binascii.hexlify(signature))

# Take input from the user for the message to verify
msg_to_verify = input("Enter the message to verify: ").encode()

# Verify the signature
hash = SHA256.new(msg_to_verify)
verifier = PKCS115_SigScheme(pubKey)
try:
    verifier.verify(hash, signature)
    print("Signature is valid.")
except:
    print("Signature is invalid.")