import sys
import csv
import pandas as pd


def dna():
    
    # check for correct number of CL arguments (CSV file)
    argc = len(sys.argv)
    if argc != 3:
        print("Invalid Input")
        quit()
        
    # read csv file and commit it to memory (dictionary)
    people = {}
    # definitely stole this from mjrezaee on stackoverflow
    with open(sys.argv[1]) as data_file:
        reader = csv.DictReader(data_file)
        df = pd.DataFrame(reader)
        # set name column as index
        df = df.set_index('name')
        # transpose to make dict with indexes
        people = df.transpose().to_dict()
            
    # Open DNA sequence and read its contents to memory
    with open(sys.argv[2], 'r') as csvfile:
        sequence = csv.reader(csvfile)
        for row in sequence:
            dnaList = row
    dnaSequence = dnaList[0]
    dnaSequenceDict = {}

    # for each of the STR, compute longest run of consecutive repeats of the STR in the DNA sequence. Inspiration taken from Federico-abss github
    for k, v in people.items():
        for k1, v1 in v.items():
            j = len(k1)
            tempMax = 0
            temp = 0
            
            # this keeps in continuing after it finds a match
            for i in range(len(dnaSequence)):
                while temp > 0:
                    temp -= 1
                    continue
                
                # counts when it finds match
                if dnaSequence[i: i + j] == k1:
                    while dnaSequence[i - j: i] == dnaSequence[i: i + j]:
                        temp += 1
                        i += j
                    if temp > tempMax:
                        tempMax = temp
                        
            # saves number to sequence dictionary   
            dnaSequenceDict[k1] = tempMax + 1
    
    # if it matches an individual, print their name
    for k, v in people.items():
        match = 0
        result = k
        for k1, v1 in v.items():  # k1 is DNA thing, v1 is number
            for k, v in dnaSequenceDict.items():
                if k == k1:
                    if v == int(v1):
                        match = match + 1
        if match == (len(dnaSequenceDict.items())):
            print(result)
            quit()
            
    # if it doesn't print "No Match"        
    print("No match")
    
              
dna()
