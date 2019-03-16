from sympy import Symbol, pprint
def print_series(n):
	x = Symbol('x')
	series = (x**n)/n
	for i in range(2, n+1):
		series = series + (x**i)/i

	pprint(series)
n=input('Enter the number of terms you want in the series: ')
print_series(int(n))