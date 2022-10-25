num = int(input("Enter the number you want to check if it is prsent in list or not : "))
list = [23,45,78,13,53,9]
def check(list,si,num):
    l = len(list)
    if si == l:
        return False
    if list[si] == num:
        return True
    return check(list,si+1,num)
print(check(list,0,num))
