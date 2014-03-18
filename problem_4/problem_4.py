#!/usr/bin/env python

def is_palindrome(n):
	s = str(n)
	l = len(s)

	for i in range(l / 2):
		if s[i] != s[l - i - 1]:
			return False

	return True

def find_max():
	palindrome = []

	for x in range(999, 100, -1):
		for y in range(999, 100, -1):
			n = x * y
			
			if is_palindrome(n):
				palindrome.append(n)

	return max(palindrome)

print find_max()