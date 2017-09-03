#!/usr/bin/env  python3

dbfilename = 'people-file'
ENDDB = 'enddb'
ENDREC = 'endrec.'
RECSEP = '=>'

def storeDbase(db):
    "formated dump of database to flat file"
    try:
        with open(dbfilename, 'w') as dbfile:
            for key in db:
                print(key, file=dbfile)
                for (name, value) in db[key].items():
                    print(name + RECSEP + repr(value), file=dbfile)
                print(ENDREC, file=dbfile)
            print(ENDDB, file=dbfile)
            dbfile.close()
    except:
        print("Nie udało się otworzyć pliku {}".format(dbfilename))


def loadDbase(dbfilename=dbfilename):
    "parse data to reconstruct database"
    try:
        with open(dbfilename) as dbfile:
            import sys
            sys.stdin = dbfile
            db = {}
            key = input()
            while key != ENDDB:
                rec = {}
                field = input()
                while field != ENDREC:
                    name, value = field.split(RECSEP)
                    rec[name] = eval(value)
                    field = input()
                db[key] = rec
                key = input()
            return db
    except:
        print("Nie udało się otworzyć pliku {}".format(dbfilename))


if __name__ == '__main__':
    from initdata import db
    storeDbase(db)
