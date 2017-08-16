#!/usr/bin/env python3

import os
import sys
import snapshothelper


#DISPLAYS MENU
def menu():
    os.system('clear')
    print(
    """
    DIRECTORY/FILE COMPARISON TOOL
    ===============================
    Please type a number and pressenter:
    1. Create a snapshot
    2. List snapshot files
    3. Compare snapshots
    4. Help
    5. Exit 
    """
    )
    return int(input("> "))

def create_snapshot():
    os.system('clear')
    
    print("""
    CREATE SNAPSHOT
    ===============================
    """)
    
    snap_dir = input("Podaj nazwę katalogu, którego snapa chcesz zrobić: ")
    snap_file = input("Podaj nazwę katalogu wyjściowego: ")
    snapshothelper.createSnapshot(snap_dir, snap_file)
    
    
def list_snapshot(): 
    os.system('clear')
    
    print("""
    LIST SNAPSHOT
    ===============================
    Enter the file extension for your snapshot files
    (for example, ‘snp’ if your files end in ‘.snp’):
    """)

    snap_extension = input()
    snapshothelper.listSnapshots(snap_extension)

def compare_snapshot():
    os.system('clear')
    
    print("""
    COMPARE SNAPSHOT
    """)

    snap1 = input("Enter the filename of snapshot 1: ")
    snap2 = input("Enter the filename of snapshot 2: ")
    snapshothelper.compareSnapshots(snap1, snap2)

def display_help():
    napshothelper.showHelp()



#MAIN FUNCTION
def main(): 
    choice = menu()

    while choice != 5:
        if choice == 1:
            create_snapshot()
        elif choice == 2:
            list_snapshot()
        elif choice == 3:
            compare_snapshot()
        elif choice == 4:
            display_help()
        choice = menu()

if __name__=="__main__":
    main()



