#!/usr/bin/env python3

import cgi


def main():
    form = cgi.FieldStorage()
    user = cgi.escape(form['user'].value)
    passwd = cgi.escape(form['passwd'].value)
    print("Content-type: text/html\n")
    print('<title>Reply Page</title>')


    if user == '':
        if passwd == '':
            print("<h1>Witaj <i>{}</i></h1>".format(cgi.escape(form['user'].value)))
        else:
            print("Wrong password")
    else:
        print("I dont konow you!")
        print("You typed {} {}".format(user, passwd))


if __name__=="__main__":
    main()
