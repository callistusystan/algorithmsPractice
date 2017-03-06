def knapsack(values, weights, weightLimit):
	return knapsackRecursive(values, weights, weightLimit, 0, weightLimit, {})

def knapsackRecursive(values, weights, weightLimit, i, remainingCapacity, memo):
	if i >= len(weights):
		return 0
	if remainingCapacity < 0:
		return 0

	if (i, remainingCapacity) in memo:
		return memo[(i, remainingCapacity)]

	if remainingCapacity < weights[i]:
		maxValue = knapsackRecursive(values, weights, weightLimit, i+1, remainingCapacity, memo)
	else:
		valueIfIncludeCurrent = values[i] + knapsackRecursive(values, weights, weightLimit, i+1, remainingCapacity - weights[i], memo)
		valueIfNoIncludeCurrent = knapsackRecursive(values, weights, weightLimit, i+1, remainingCapacity, memo)
		maxValue = max(valueIfIncludeCurrent, valueIfNoIncludeCurrent)

	memo[(i, remainingCapacity)] = maxValue

	return maxValue

print(knapsack([22, 20, 15, 30, 24, 54, 21, 32, 18, 25], [4, 2, 3, 5, 5, 6, 9, 7, 8, 10], 30))