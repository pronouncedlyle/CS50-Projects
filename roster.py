import sys
import csv
from cs50 import SQL
db = SQL("sqlite:///students.db")


def housesRoster():

    # Check CLA
    argc = len(sys.argv)
    if argc != 2:
        print("Invalid Input")
        quit()
        
    # Query DB for all students in chosen year. db.execute SELECT. Return value will be a python dict. each dict is a row in the table. Check for null values
    houseRoster = db.execute("SELECT first, middle, last, birth FROM students WHERE house = (?) ORDER BY last, first;", sys.argv[1])
    
    # print, sorted by last name, then first name
    for row in houseRoster:
        if row["middle"] == None:
            print(row["first"] + " " + row["last"] + ", born " + str(row["birth"]))
        else:
            print(row["first"] + " " + row["middle"] + " " + row["last"] + ", born " + str(row["birth"]))
        
        
housesRoster()