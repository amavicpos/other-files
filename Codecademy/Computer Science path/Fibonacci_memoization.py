memo = {}
count = []

def fibonacci(num, memo):
  count.append(1)
  if num < 0:
    print("Not a valid number")
    return None
  if num <= 1:
    return num
  elif memo.get(num):
    return memo.get(num)
  else:
    memo[num] = fibonacci(num - 1, memo) + fibonacci(num - 2, memo)
    return memo[num]

num = int(input("What number of Fibonacci do you want to calculate? "))
print(f"Fibonacci number {num}: Count:")
print(fibonacci(num, memo), sum(count))
