#!/usr/bin/env python

thousand_str = [ '0' for i in range(1000) ]
thousand_str[0] = '1'
thousand_num = int(''.join(thousand_str))

x, y, z = 0, 1, 1
term = 2

while z < thousand_num:
	x = y
	y = z
	z = x + y
	term += 1

print term, z
