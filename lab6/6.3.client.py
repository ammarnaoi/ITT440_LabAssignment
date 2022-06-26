import socket
import signal
import sys

ClientSocket = socket.socket()
host='169.254.156.75'
port = 2705

print('connecting..')
try:
  ClientSocket.connect((host,port))
  except socket.error as r:
    print(str(e))
  res= ClientSocket.recv(2048)
  
While True:
  try:
    menu=ClientSocket.recv(2048)
    print(menu.decode("utf-8"))
    
    Input= input('Mathematical Function: ')
    ClientSocket.send(str.encode(Input))
    
    if Input == '4' :
      break
    else
       ClientSocket.send(str.encode(Input))
      answer= ClientSocket.recv(2048)
      print(answer.decode("utf-8"))
      
    except KeyboardInterrupt:
      print('\nCtrl + C is pressed, Lost Connection')
        sys.exit()
      
ClientSocket.close()
    
