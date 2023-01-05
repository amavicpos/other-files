# Functional programming principles: conciseness and avoiding side-effects

import csv
from functools import reduce

def count(predicate, itr):
	count_filter = filter(predicate, itr)
	count_reduce = reduce(lambda x, y: x + 1, count_filter, 0)
	return count_reduce

def avg_helper(curr_count, itr, curr_sum):
	try:
		return avg_helper(curr_count + 1, itr, curr_sum + next(itr))
	except:
		return curr_sum / curr_count

def average(itr):
	# If itr is not iterable, this will generate an iterator.  
	return avg_helper(0, itr, 0)

with open('utils/1kSalesRec.csv', newline = '') as csvfile:
	reader = csv.reader(csvfile, delimiter=',', quotechar='|')
	fields = next(reader)
	count_belgiums = count(lambda x: x[1] == "Belgium", reader)
	print(count_belgiums)
	csvfile.seek(1)
	avg_portugal = average(map(lambda x: float(x[13]), filter(lambda x: x[1] == "Portugal", reader)))
	print(avg_portugal)
