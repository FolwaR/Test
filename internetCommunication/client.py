#!/usr/bin/env python3

import sys
from socket import *

def main():
    serverHost = 'localhost'
    serverPort = 50008

    message = ['Client Message1', 'Client Message2']
    
    sSock = socket(AF_INET, SOCK_STREAM)
    sSock.connect((serverHost, serverPort))

    for item in message:
        sSock.send(item.encode())
        data = sSock.recv(1024)
        print('Client received: {}'.format(data))
    
    sSock.close()


if __name__=="__main__":
    main()



