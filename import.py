import sys
import csv
from cs50 import SQL
db = SQL("sqlite:///students.db")


def housesImport():
    
    # check command line argument
    
    argc = len(sys.argv)
    if argc != 2:
        print("Invalid Input")
        quit()

# Open CSV file given in CLA.

    with open(sys.argv[1], 'r') as file:
        reader = csv.DictReader(file)
        
        # For each row, split name into first, middle, last. split method. Make sure to check for only 2 names. Also use None for students without one. 
        
        for row in reader:
            names = str.split(row["name"])
            if len(names) == 2:
                firstName = names[0]
                middleName = None
                lastName = names[1]
            else:
                firstName = names[0]
                middleName = names[1]
                lastName = names[2] 
            
            # Insert each student into the students table of students.db. Use db.execute to INSERT a row into table
            
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)",
                       firstName, middleName, lastName, row["house"], row["birth"])
                        

housesImport()