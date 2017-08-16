#!/usr/bin/env python3
from socket import *


def main():
    serverHost = ''
    serverPort = 50008

    sSock = socket(AF_INET, SOCK_STREAM)
    sSock.bind((serverHost, serverPort))
    sSock.listen(3)

    while True: 
        conn, addr = sSock.accept()
        print('Client Connection: {}'.format(addr))
        
        while 1:
            data = conn.recv(1024)
            if not data: break
            print('Server Received: {}'.format(data))
            newData = data.decode()
            newData = newData.replace('Client', 'Processed')
            conn.send(newData.encode())
        conn.close()    

if __name__ == "__main__":
    main()

