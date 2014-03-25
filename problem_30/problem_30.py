#!/usr/bin/env python

from functools import partial

fifth = 5

def is_digit_power(n, power):
	if n == 1:
		return False
	elif n == sum([int(s) ** power for s in str(n)]):
		return True
	return False

is_digit_fifth_power = partial(is_digit_power, power = 5)

print sum(filter(is_digit_fifth_power, [i for i in range(9 ** fifth * 10)]))