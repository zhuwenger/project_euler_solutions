#!/usr/env/bin python
	
def find_longest_collatz_seq(size):
	max_length, max_num = 0, 0
	
	for i in xrange(1, size + 1):
		num_seq = 1
		num = i
		
		while num != 1:
			if num % 2 == 0:
				num /= 2
			else:
				num = 3 * num + 1
			num_seq += 1
		
		if num_seq > max_length:
			max_length = num_seq
			max_num = i
	
	return max_length, max_num

print find_longest_collatz_seq(1000000)