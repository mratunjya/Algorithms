base = int(input("Enter base number : "))
power = int(input("Enter power number : "))

def pow(base , power):
    if power==1:
        return base
    else :
        value = base * pow(base , power-1)
    return value

value = pow(base , power)
print("{} to power {} : {}".format(base,power,value))