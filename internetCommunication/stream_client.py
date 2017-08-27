#!/usr/bin/env python3

import sys
from socket import *

def main():
    serverHost="localhost"
    serverPort=50011
    
    sSock = socket(AF_INET, SOCK_STREAM)
    sSock.connect((serverHost, serverPort))

    line = ""
    while line != 'bye':
        line = input("Send to %s: " % (serverHost))
        sSock.send((line+'\n').encode())
        data = sSock.recv(1024)
        print(data.decode())
    sSock.shutdown(0)
    sSock.close()
    


if __name__=="__main__":
    main()




