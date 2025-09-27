n = int(input())
a = [int(input()) for _ in range(n)]
k = int(input())

# Sort the array in descending order to apply 20% profit to the highest values
a.sort(reverse=True)

total_profit = 0

for i in range(n):
    if i < k:
        # Apply 20% profit for the first k items
        profit = a[i] * 0.20
    else:
        # Apply 10% profit for the remaining items
        profit = a[i] * 0.10
    total_profit += profit

# Since the problem expects integer output (as per sample), we'll convert to int if it's a whole number
if total_profit == int(total_profit):
    print(int(total_profit))
else:
    print(total_profit)