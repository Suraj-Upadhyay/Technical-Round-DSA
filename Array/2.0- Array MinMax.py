# There are three methods to solve this problem as given in gfg guide.
# 1. Linear Comparison
# 2. Tournament Method
# 3. Pair wise

size = int(input("Input the size : "))
array = list(map(int, input("Enter the array : ").strip().split()))

class Pair:
    def __init__(self, mx = 0, mn = 0):
        self.max = mx
        self.min = mn

    def __repr__(self):
        return 'Min : {}, Max: {}'.format(self.min, self.max)

########################
# 1. Linear Comparison #
########################

def linear_getMinMax(arr: int, size: int):
    if size == 1:
        return Pair(arr[0], arr[0])

    pair = Pair()

    if arr[0] > arr[1]:
        pair.max = arr[0]
        pair.min = arr[1]
    else:
        pair.max = arr[1]
        pair.min = arr[0]

    for i in range(2, size):
        if pair.max < arr[i]:
            pair.max = arr[i]
        elif pair.min > arr[i]:
            pair.min = arr[i]

    return pair

print("Linear Comparison : ", linear_getMinMax(array, size))

########################
# 2. Tournament Method #
########################

def tournament_getMinMax(arr: int, high: int, low: int):
    if high == low:
        return arr[high], arr[high]

    if high == low + 1:
        return max(arr[high], arr[low]), min(arr[high], arr[low])

    mid = (high + low) // 2
    max1, min1 = tournament_getMinMax(arr, high, mid + 1)
    max2, min2 = tournament_getMinMax(arr, mid, low)
    return max(max1, max2), min(min1, min2)

print("Tournament methods : ", Pair(*tournament_getMinMax(array, size - 1, 0)))

########################
#    3. Pair Method    #
########################

def pair_getMinMax(arr: int, size: int):
    if size % 2 == 0:
        mx = max(arr[0], arr[1])
        mn = min(arr[0], arr[1])
        i = 2
    else:
        mx = mn = arr[0]
        i = 1
    while i < size - 1:
        if arr[i] < arr[i - 1]:
            mx = max(mx, arr[i - 1])
            mn = min(mn, arr[i])
        else:
            mx = max(mx, arr[i])
            mn = min(mn, arr[i])
        i += 2
    return mx, mn

print("Pair method : ", Pair(*pair_getMinMax(array, size)))
