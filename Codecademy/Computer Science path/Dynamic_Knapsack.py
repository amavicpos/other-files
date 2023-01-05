def dynamic_knapsack(weight_cap, weights, values):
  n = len(values)
  matrix = [[-1 for x in range(weight_cap + 1)] for x in range(n + 1)]
  for i in range(n + 1):
    for w in range(weight_cap + 1):
      if (i == 0 or w == 0):
        matrix[i][w] = 0
      elif weights[i-1] <= w:
        matrix[i][w] = max(values[i-1] + matrix[i-1][w-weights[i-1]], matrix[i-1][w])
      else:
        matrix[i][w] = matrix[i-1][w]
  return matrix[n][weight_cap]

weight_cap = 50
weights = [31, 10, 20, 19, 4, 3, 6]
values = [70, 20, 39, 37, 7, 5, 10]
print(dynamic_knapsack(weight_cap, weights, values))