from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height > 0 and height < 9:
        break

# nested for loop to determine composition of each row (will need 4 variables.)
while i in range(1, height + 1):
    
    # left sides spaces
    for j in range(height - i):
        print(" ", end="")
    # left side hashes
    for k in range(i):
        print("#", end="")
    # middle gap
    print("  ", end="")
    # right side hashes
    for l in range(i):
        print("#", end="")
    print()