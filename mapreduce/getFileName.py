#!/usr/bin/python

import os
path = "./data"
output = open("customerBehaviorFiles", "w")
for name in os.listdir(path):
	if name[0] != '.':
		output.write(name)
		output.write("\n")
output.close()
