# babyshark

- Namespace: picoctf/18739f24
- ID: babyshark
- Type: custom
- Category: Reverse Engineering

## Description

Can you find out what this binary does?

## Details

Connect to the program on our server: `nc {{server}} {{port}}`
Download the program: {{url_for("babyshark.exe")}}


## Solution Overview

This windows executable camouflages the win32 apis called on by using GetModuleHandleA and GetProcAddress. This makes it more difficult for decompilers to recognize the function signatures immediately.

A key point would be to use x64-dbg and set breakpoints on those functions and figure out which APIs are being called. It can also be done manually via xor, but its easier when its done dynamically.

After resolving those functions, it will be clear that the executable is creating a server on the users machine and is listening for connections. We would have to create a client and send matching strings for the server to decrypt its secrets and give us the link to a flag.

Another alternative solution would be to use process monitor or similar tools to see that the executable is opening a server. Then, go into the executable and match the behavior to the code, and figure out the strings to feed the server. This would bypass the requirement to do static analysis and would be a faster solution.

## Learning Objective

Learning about malware obfuscation methods and DLL linking.

## Tags

- windows

## Attributes

- author: lpy
- organization: picoCTF
- event: picoCTF Problem Developer Training
