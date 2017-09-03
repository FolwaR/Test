#!/usr/bin/env python3

bob = dict(name='Bob Shmit', job='softw', age=24, pay=10000)
sue = dict(name='Sue Brown', job='hardw', age=40, pay=10000)
tom = dict(name='Tom Hardy', job='noName', age=27, pay=1705)

db = {}
db['bob'] = bob
db['sue'] = sue
db['tom'] = tom


if __name__ == "__main__":
    for key in db:
        print("{} => {}".format(key, db[key]))

