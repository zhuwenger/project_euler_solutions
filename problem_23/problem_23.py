#!/usr/bin/env python

border = 28123

def seq_sum(n):
	return n * (n + 1) / 2

def get_divisors(n):
	divisors = []

	for i in range(1, n / 2 + 1):
		if n % i == 0:
			divisors.append(i)

	return divisors

def is_abundant(n):
	return sum(get_divisors(n)) > n

abundant_list = filter(is_abundant, [x for x in range(1, border + 1)])
abundant_list.sort()

two_abundant_set = set()

for i, x in enumerate(abundant_list):
	if 2 * x > border:
		break
	else:
		j = i
		while j < len(abundant_list):
			tmp = x + abundant_list[j]
			if tmp <= border:
				two_abundant_set.add(tmp)
			j += 1

print seq_sum(border) - sum(two_abundant_set)