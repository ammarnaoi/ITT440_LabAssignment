import socket

s = socket.socket()

port = 8888

s.connect(('169.254.156.75', port))

data = s.recv(1024)

s.send(b'Hi, saya client. Terima Kasih!');

print (data)

s.close()
