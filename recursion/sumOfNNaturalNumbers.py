num = int(input("Enter the number : "))
def add(num):
    if num == 1:
        return 1
    else :
        num = num + add(num-1)
    return num
sum = add(num)
print("SUM TILL NATURAL NUMBER {} : {}".format(num,sum))