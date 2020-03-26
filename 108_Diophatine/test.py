from sympy.ntheory import factorint
import inspect

source = inspect.getsource(factorint)

print(source)
