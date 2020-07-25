from cs50 import get_int, get_string


def creditCardCheck():
    
    def sum_digits(digit):
        if digit < 10:
            return digit
        else:
            sum = (digit % 10) + (digit // 10)
            return sum

    # Prompt for input
    cc_num = get_string("Enter Credit Card Number Here: ")
    if (len(cc_num) < 13 and len(cc_num) > 16):
        print("INVALID")
        
    # Luhn's thingie: Some code taken from dev.to article by Anurag Rana
        
    # reverse the credit card number
    cc_num_working = cc_num[::-1]
    # convert to integer list
    cc_num_working = [int(x) for x in cc_num_working]
    # double every second digit
    doubled_second_digit_list = list()
    digits = list(enumerate(cc_num_working, start=1))
    for index, digit in digits:
        if index % 2 == 0:
            doubled_second_digit_list.append(digit * 2)
        else:
            doubled_second_digit_list.append(digit)

    # add the digits if any number is more than 9
    doubled_second_digit_list = [sum_digits(x) for x in doubled_second_digit_list]
    # sum all digits
    sum_of_digits = sum(doubled_second_digit_list)
    # return True or False
    if sum_of_digits % 10 != 0:
        print("INVALID")
        quit()
    
    # If passes Luhn's thingie, loop to determine which kind of card it is. Print it.
    
    # American Express
    if len(cc_num) == 15:
        if cc_num[0] == 3 and cc_num[1] == 4 or 7:
            print("AMEX")
        else:
            print("INVALID 1")
    # Visa
    elif len(cc_num) == 13 and cc_num[0] == "4":
        print("VISA")
    # MasterCard or Visa
    elif len(cc_num) == 16:
        if cc_num[0] == "4":
            print("VISA")
        elif cc_num[0] == "5":
            if cc_num[1] == "1" or "2" or "3" or "4" or "5":
                print("MASTERCARD")
        else:
            print("INVALID")
    else: 
        print("INVALID")


creditCardCheck()