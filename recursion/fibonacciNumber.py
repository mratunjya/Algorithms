num = int(input("Enter the number for which you want fibonacci number : "))
def fibonacci(num):
    if num==0 or num==1:
        return 1
    fib1=fibonacci(num-1)
    fib2=fibonacci(num-2)
    return fib1 + fib2
value = fibonacci(num+1)
print("Fibonacci value for {} is {}".format(num,value)) 