a = float(input("Digite o valor de uma dimensão da folha:"))
b = float(input("Digite o valor de outra dimensão da folha:"))
x1 = float(input("Digite o valor de x1:"))
x2 = float(input("Digite o valor de x2:"))
erro = float(input("Digite o valor da precisão necessária:"))

h = abs(x1 - x2)/3

xi = 0
xj = 0
vi = 0
vj = 0

while abs(x1 - x2) > erro :
    
    h = abs(x1 - x2)/3
    
    if x1 < x2:
        xi = x1 + h
        xj = x2 - h
    else:
        xi = x1 - h
        xj = x2 + h
    
    vi = ( a - 2*xi )*( b - 2*xi )*xi
    vj = ( a - 2*xj )*( b - 2*xj )*xj
    
    if vi < vj:
        x1 = xi
    else:
        x2 = xj

xmax = (x1 + x2)/2

print("Xmax =")
print(xmax)
    
    