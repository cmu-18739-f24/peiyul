import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(("localhost", 12345))
s.send(b"dEYDndkIDqEVcdsRBIdb\x00")
print(s.recv(30))
