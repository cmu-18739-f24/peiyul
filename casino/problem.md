# Casino

- Namespace: picoctf/18739
- ID: casino
- type: custom
- Category: Crypto
- Points: 10

## Description

Guess your way through my casino!
I hope you have enough luck!

## Details

Connect to the program on our server: `nc {{server}} {{port}}`

Download the program: {{url_for("casino.py")}}

## Hints

- What are the weaknesses of RSA?

## Solution Overview

Solver script is included in the file.
chal 1 can be solved by using the malleable properties of RSA.
chal 2 can be solved using the chinese remainder theorem since we are reusing a small exponent 3 with different values of n.

## Learning Objective

Learn about the different weaknesses of RSA, ex. homomorphic encryption and CRT attack on RSA.

## Attributes

- author: lpy
