#!/usr/bin/env python

from sys import argv

if __name__ == '__main__':
	if len(argv) > 1:
		f = open(argv[1])
		numbers = []

		for l in f:
			numbers.append()(int(l))

		print str(sum(numbers))[:10]

