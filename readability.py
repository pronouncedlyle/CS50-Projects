from cs50 import get_string
import math


def readingLevel():
    # input
    sampleText = get_string("Input text sample: ").lower()
    # count letters, words and sentences
    letters, words, sentences = (0.0, 0.0, 0.0)
    
    for i in sampleText:
        # letters
        if i.isalpha() is True:
            letters += 1
        # words
        if i == " ":
            words += 1
        # sentences
        if i == '.' or i == '!' or i == '?':
            sentences += 1
    if letters > 0:
        words += 1
    # calculate reading level
    gradeLevel = round((0.0588 * ((letters * 100) / words)) - (0.296 * ((sentences * 100) / words)) - 15.8)
    # print results
    if gradeLevel < 1:
        print("Before Grade 1")
    elif gradeLevel >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {gradeLevel}")

        
readingLevel()