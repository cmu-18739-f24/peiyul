# Casino Problem Creation Walkthrough

## Overview

The main theme of this challenge is centered around RSA properties and weaknesses.

The first chal prompts the user to guess a given number correctly for 10 times. Users are given an encryption oracle and decryption oracle where they can get the ciphertexts of any number they send, and also decrypt any ciphertext they send (as long as its not the ciphertext of the initial number). It focuses on the malleable property of RSA, which allows for homomorphic encryption. This means that any multiplication of two ciphertexts will also be a valid ciphertext. The trick is to send in a value constructed through homomorphism to the decryption oracle. With that value, we can then do a division to get the solution number.

The second chal is based on the Hastad's Broadcast Attack on RSA systems. It is due to the use of e = 3 (small exponent) with different values of N. This allows resolving the plaintext by using the Chinese Remainder Theorem.

## Walkthrough

### File Listing

1. [casino.py](/casino.py) this is the challenge file.

1. [myprivatekey.pem](/myprivatekey.pem): private key for chal 1

1. [mypublickey.pem](/mypublickey.pem): public key for chal 1

1. [start.sh](start.sh) starts a listener
   that receives connections. This script is ran as the last step in the
   Dockerfile. For this problem, we use socat to connect the output of our
   vulnerable script to a port, allowing users to interact with our script
   through the network.

1. [setup-challenge.py](setup-challenge.py)
   This script generates the flag for the problem and saves it in the important
   file, `/challenge/metadata.json`, which is required for every cmgr problem.

1. [Dockerfile](/Dockerfile) this is the main
   setup for our problem. We pull down a pinned Ubuntu image, update it and
   install the required packages. We create the `/challenge` directory with
   specific permissions so only root can access it. `/challenge` is an
   important directory and contains files that cmgr needs to deploy a problem.
   We add `artifacts.tar.gz` to this directory as well, which contains a copy
   of the source for the service being run on the container.

