import sympy as sp
x, y = sp.symbols('x,y')
g = sp.exp(-x*y)
g
exp(-x*y)
g.series(x, 0)
g.series(y, 0)