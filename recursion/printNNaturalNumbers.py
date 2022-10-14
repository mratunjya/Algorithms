num = int(input("Enter till which number you want to print : "))
def printNum(start,num):
    if start == num :
        print(start)
    else :
        print(start)
        printNum(start+1,num)
printNum(1,num)
