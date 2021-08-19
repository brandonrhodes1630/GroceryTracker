import re
import string
from collections import Counter # Module helps us count the occurances of an item in a list,
# which converts to a dictionary with occurances as values of the items(keys)


#Read from the input file and place items in a dictionary where product is key and frequency is value
input_file = open("InputFile.txt", 'r')
content = input_file.read()
file_list = content.split("\n")
input_file.close()
occurances = Counter(file_list) # Setting the dictionary to a variable to allow manipulation
  

def ItemOccurance(): #Simple function to display products per day with corresponding frequency
    print("************ Items Purchased ***************")
    print("--------------------------------------------")
    for key in occurances:
        print("            ", key, "", occurances[key])
    print("--------------------------------------------")
        


#Function to take user input, look for user input match in dictionary and out put the result of that search
def specificItem(userItem):

    for key in occurances:
        
        if key == userItem:
            itemFreq = occurances[key] #Variable to hold result
            break
        else:
            continue
         
    return itemFreq

    
#Function that creates the .dat file that holds the products and their frequency
def fileCreation():
    with open("frequency.dat", 'w') as f:
        for key, value in occurances.items():
            f.write('%s %s\n' % (key, value))

