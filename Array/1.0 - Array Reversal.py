# Input Number of elements in the array
num = int(input())

# Input the array
array = list(map(int, input().strip().split()))

# Iterative Method O(n)
c_array = [i for i in array]
def inverse_iterative(c_array, start, end):
    while start < end :
        c_array[start], c_array[end] = c_array[end], c_array[start]
        start += 1
        end -= 1
    return c_array

print(inverse_iterative(c_array, 0, num - 1))

# Recursive method
c_array = [i for i in array]

def inverse_recursive(c_array, start, end):
    if start >= end:
        return c_array
    c_array[start], c_array[end] = c_array[end], c_array[start]
    c_array = inverse_recursive(c_array, start + 1, end - 1)
    return c_array

print(inverse_recursive(c_array, 0, num - 1))
