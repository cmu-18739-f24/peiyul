"""
Code used to generate the public and private RSA keys in challenge 1
"""

from Crypto.PublicKey import RSA

mykey = RSA.generate(1024)

with open("myprivatekey.pem", "wb") as f:
    data = mykey.export_key(
        pkcs=8,
        protection="PBKDF2WithHMAC-SHA512AndAES256-CBC",
    )
    f.write(data)
    f.close()

with open("mypublickey.pem", "wb") as f:
    data = mykey.public_key().export_key(
        pkcs=8,
        protection="PBKDF2WithHMAC-SHA512AndAES256-CBC",
    )
    f.write(data)
    f.close()
