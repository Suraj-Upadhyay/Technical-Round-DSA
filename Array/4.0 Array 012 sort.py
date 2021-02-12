# Sort an array which only consists of 0s, 1s and 2s

n = int(input())
arr = list(map(int, input().strip().split()))
sorting_array = [0, 0, 0]
sorted_array = []

for x in arr:
    sorting_array[x] += 1

for i, x in enumerate(sorting_array):
    sorted_array += [i] * x

print(sorted_array)
