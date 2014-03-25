#!/usr/bin/env python

powers = set()
for a in range(2, 101):
	for b in range(2, 101):
		powers.add(a ** b)

print len(powers)