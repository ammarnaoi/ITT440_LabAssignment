import socket
import sys
import math
from multiprocessing import Process

boleh_message = '\nHTTP/1.0 200 OK\n\n'
takboleh_message = '\nHTTP/1.0 404 NotFound\n\n'

def log(x):
    return math.log(x)

def sqrt(x):
    return math.sqrt(x)

def exp(x):
    return math.exp(x)

def start_process(serversocket):
  serversocket.send(str.encode('Server working:'))
  
  while True:
    data = serversocket.recv(2048)
    data = data.decode("utf-8")

    menu= (("\n1.Logarithmic") +
            ("\n2.Square Root") +
            ("\n3.Exponential") +
            ("\n4.Exit") )
    
    serversocket.send(str.encode(menu)) #send 1
    print("Waiting for response..")
    
    try:
      math, value = data.split
      choice=str(math)
      num=int(value)
      
      if choice == '1':
        ans = log(num)
        mystring = "Log Value"
        
      elif choice == '2':
           ans = sqrt(num)
           mystring = "The square root"
            
      elif choice == '3':
           ans = exp(num)
           mystring = "Exponential"
            
      myans = (str(mystring) + ' = ' + str(ans))
      print ('Done!')
      
      except:
        print ('wrong input!')
        sendAnswer = ('wrong input!')
        
         if not choice:
            break
      
       serversocket.send(str.encode(myans))

    serversocket.close()

if __name__ == '__main__':
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind(("",2705))                                   
    print("waiting..")
    s.listen(10)                                         
    
    try:
        while True:
            try:
                serversocket, s_addr = s.accept()
                p = Process(target=start_process, args=(serversocket,))
                p.start()

            except socket.error:

                print('socket failure!')

            except Exception as e:        
                print("an exception occurred!")
                print(e)
                sys.exit(1)
    finally:
     	   s.close()
        
     
