#!/usr/bin/env python3
import pickle

dbFileName = "dbPeoplePickle"

def saveDBase(dataBase):
    try:
        with open(dbFileName, 'wb') as dbfile:
            pickle.dump(dataBase, dbfile)
    except:
        print("Nie udało się otworzyć pliku {}".format(dbFileName))

def loadDbase(dbfilename=dbFileName):
    try:
        with open(dbFileName, 'rb') as dbfile:
            db = pickle.load(dbfile)
            for key in db:
                print("{} => {}".format(key, db[key]))
    except:
        print("Nie udało się otworzyć pliku {}".format(dbFileName))


if __name__ == '__main__':
    from initdata import db
    saveDBase(db)
    loadDbase()
