#!/usr/bin/env python

def get_divisors(n):
	divisors = []

	for i in range(1, n / 2 + 1):
		if n % i == 0:
			divisors.append(i)

	return divisors

def check_amicable(n):
	m = sum(get_divisors(n))

	if n != m and n == sum(get_divisors(m)):
		return True

print sum(filter(check_amicable, [x for x in range(1, 10001)]))