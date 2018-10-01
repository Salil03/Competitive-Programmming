a = input('Input coefficient of x' + chr(0x00B2) + ': ')
b = input('Input coefficient of x: ')
c = input('Input constant term: ')
a = float(a)
b = float(b)
c = float(c)

if int((b**2 - 4*a*c)) < 0:
    print("No real roots exist but imaginary roots exist")
elif int((b**2 - 4*a*c)) == 0:
    print("Identical real roots exist")
elif int((b**2 - 4*a*c)) > 0:
    print("Real roots exist")

root_a = str((-b + (b**2 - 4*a*c)**0.5)/(2*a))
root_b = str((-b - (b**2 - 4*a*c)**0.5)/(2*a))

print("alpha" + ' = ' + root_a)
print("beta" + ' = ' + root_b)
