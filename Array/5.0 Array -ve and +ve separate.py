n = int(input("Enter Size : "))
arr = list(map(int, input("Enter Array : ").strip().split()))

def partition_method(arr: list, n: int):
    j = 0
    for i in range(n):
        if arr[i] < 0:
            arr[i], arr[j] = arr[j], arr[i]
            j += 1
    return arr

print(partition_method([x for x in arr], n))

def two_pointer_approach(arr, n):
    i, j = 0, n - 1
    while i <= j:
        if arr[i] < 0 and arr[j] < 0:
            i += 1
        elif arr[i] > 0 and arr[j] < 0:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
            j -= 1
        elif arr[i] > 0 and arr[j] > 0:
            j -= 1
        else:
            i += 1
            j -= 1
    return arr
print(two_pointer_approach([x for x in arr], n))
