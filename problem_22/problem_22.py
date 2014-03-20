#!/usr/bin/env python

from sys import argv

alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
alpha_order = {}

for i, c in enumerate(alphabet):
	alpha_order[c] = i + 1

def cal_score(word):
	score = 0

	for c in word:
		score += alpha_order[c]

	return score

def load_names(filename):
	f = open(filename)
	names = []

	for l in f:
		origin_names = l.strip().split(',')

		for name in origin_names:
			names.append(name.strip().replace('"', ''))

	return names

if __name__ == '__main__':
	if len(argv) <= 1:
		print 'Usage:', argv[0], ' filename'
	else:
		print sum([cal_score(name) * (i + 1)
			for i, name in enumerate(sorted(load_names(argv[1])))])
