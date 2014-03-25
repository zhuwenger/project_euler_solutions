#!/usr/bin/env python

from math import sqrt
from functools import partial

prime = set()
not_prime = set()

def _is_prime(n):
	for i in range(2, int(sqrt(n) + 1)):
		if n % i == 0:
			return False
	return True

def is_prime(n):
	if n <= 0:
		return False
	elif n in prime:
		return True
	elif n in not_prime:
		return False
	else:
		n_is_prime = _is_prime(n)

		if n_is_prime:
			prime.add(n)
		else:
			not_prime.add(n)

		return n_is_prime

def prime_quadratic_formular(n, a, b):
	return n * n + a * n + b

def find_maximum_coefficients(max_range):
	maximum_num = 0
	max_a, max_b = 0, 0

	for x in range(-max_range, max_range):
		for y in range(-max_range, max_range):
			formular = partial(prime_quadratic_formular, a = x, b = y)
			n = 0

			while True:
				if is_prime(formular(n)):
					n += 1
				else:
					if n > maximum_num:
						maximum_num = n
						max_a, max_b = x, y

					break

	return max_a, max_b, maximum_num

a, b, num = find_maximum_coefficients(1000)
print a, b, num, a * b