import hashlib

def sha1_hash(data):
    sha1 = hashlib.sha1()
    sha1.update(data.encode('utf-8'))
    return sha1.hexdigest()

def md5_hash(data):
    md5 = hashlib.md5()
    md5.update(data.encode('utf-8'))
    return md5.hexdigest()

data = input("Enter data to be hashed: ")
print(f"SHA-1 Hash: {sha1_hash(data)}")
print(f"MD5 Hash: {md5_hash(data)}")
