f = open('day6_7', 'r')
s = f.readlines()

pules = ['yo']
i = 1
pules.append(open(str(i)+'.c', 'w'))
pules[i].write('/*\n')

for x in s:
	if(x == '\n'):
		pules[i].write('*/\n\n\n')
		pules[i].close()
		i += 1
		pules.append(open(str(i)+'.c', 'w'))
		pules[i].write('/*\n')
	else:
		pules[i].write(x)

pules[i].write('*/\n\n\n')
pules[i].close()
f.close()
