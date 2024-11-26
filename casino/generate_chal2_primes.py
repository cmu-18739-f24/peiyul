"""
Code used to generate the p, q, n in challenge 2
"""

from Crypto.Util import getPrime
import math

found_primes = False
while not found_primes:
    e = 3
    p = getPrime(1024)
    q = getPrime(1024)
    n = p * q
    d = 1
    if math.gcd(e, (p - 1) * (q - 1)) == 1:
        found_primes = True
        d = pow(e, -1, (p - 1) * (q - 1))
print("I precomputed all my public keys to save time!")
