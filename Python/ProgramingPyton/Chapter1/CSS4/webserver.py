#!/usr/bin/env python3


import os, sys

from http.server import HTTPServer, CGIHTTPRequestHandler

webdir = '.'
port = 80

os.chdir(webdir)
srvraddr = ("", port)
srvrobj = HTTPServer(srvraddr, CGIHTTPRequestHandler)
srvrobj.serve_forever()

