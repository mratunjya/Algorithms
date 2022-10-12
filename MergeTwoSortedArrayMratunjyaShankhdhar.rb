# Merge two sorted Arrays

def mergeSortedArrays(arr1, arr2)
    arr1.concat(arr2).sort
    end

arr1 = [1, 2, 3, 4, 12]
arr2 = [6, 7, 8, 9, 10]
puts mergeSortedArrays(arr1, arr2)
