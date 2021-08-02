def total(initial = 5,*number,**keywords):
	print 'initial',initial
	print 'number',number
	print 'keywords',keywords
	count =initial
	for number in numbers:
		count += number
	for key in keywords:
		count += keywords[key]
	return count

print total(10,1,2,3,veg=50,fruits=100)
