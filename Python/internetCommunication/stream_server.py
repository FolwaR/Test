#!/usr/bin/env python3

import socket
import socketserver
import string

class myTCPServer(socketserver.StreamRequestHandler):
    def handle (self):
        while 1:
            peer = self.connection.getpeername()[0]
            line = self.rfile.readline()
            print("{} wrote: {}".format(peer, line.decode()))
            sck = self.connection.getsockname()[0]
            self.wfile.write("{}: bytessuccessfuly received.".format(sck).encode())

def main():
    serv = socketserver.TCPServer(("",50011),myTCPServer)
    serv.serve_forever()   


if __name__=="__main__":
    main()


