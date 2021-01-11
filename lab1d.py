from math import log, sin

coef3 = float(input("Digite o valor do coeficiente de x^3:"))
coef2 = float(input("Digite o valor do coeficiente de x^2:"))
coef1 = float(input("Digite o valor do coeficiente de x:"))
coef0 = float(input("Digite o valor do coeficiente independente:"))
coefsen = float(input("Digite o valor do coeficiente de sen(x):"))
coefln = float(input("Digite o valor do coeficiente de ln(x):"))
x1 = float(input("Digite o valor de x1:"))
x2 = float(input("Digite o valor de x2:"))
erro = float(input("Digite o valor da precisão necessária:"))

xm = (x1+x2)/2

raiz = x1

while abs(x1-x2) > erro and raiz != xm :
    
    xm = (x1+x2)/2
    
    if x1 != 0 and x2 != 0 :

            f1 = coef3 * pow(x1,3) + coef2 * x1 * x1 + coef1 * x1 + coef0 + coefsen * sin(x1) + coefln * log(x1)

            f2 = coef3 * pow(x2,3) + coef2 * x2 * x2 + coef1 * x2 + coef0 + coefsen * sin(x2) + coefln * log(x2)

            fm = coef3 * pow(xm,3) + coef2 * xm * xm + coef1 * xm + coef0 + coefsen * sin(xm) + coefln * log(xm)

    else :

            f1 = coef3 * pow(x1,3) + coef2 * x1 * x1 + coef1 * x1 + coef0 + coefsen * sin(x1)

            f2 = coef3 * pow(x2,3) + coef2 * x2 * x2 + coef1 * x2 + coef0 + coefsen * sin(x2)

            fm = coef3 * pow(xm,3) + coef2 * xm * xm + coef1 * xm + coef0 + coefsen * sin(xm)
            
    if f1 < 0 and f2 > 0 :
        if fm < 0:
            x1 = xm
            x2 = x2
            raiz = x2
        elif fm > 0:
            x1 = x1
            x2 = xm
        else:
            raiz = xm
    else :
        if fm < 0:
            x1 = x1
            x2 = xm
        elif fm > 0:
            x1 = xm
            x2 = x2
            raiz = x2
        else:
            raiz = xm
            
raiz = xm

print("A raiz é:")
print(raiz)
        