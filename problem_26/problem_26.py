#!/usr/bin/env python

def find_recurring(n):
	reminder_set = set()
	reminder = 1

	while reminder not in reminder_set:
		reminder_set.add(reminder)
		reminder = reminder * 10 % n

	return len(reminder_set)

print reduce(
	lambda x, y: x if x[1] > y[1] else y,
	[(i, find_recurring(i)) for i in range(2, 1000)])