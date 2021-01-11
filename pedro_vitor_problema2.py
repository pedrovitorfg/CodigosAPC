import math

def calcComprimento(a, x0, x1, e, N):

    f0 = 0
    f1 = 0
    d1 = 0
    d2 = 20
    n = 2
    
    while abs(d1 - d2) > e:

        d2 = d1
        h = (x0-x1)/n

        for i in range(N):

            x1 = x0 + h

            for j in range(N):
                f0 += a[j]*pow(x0,j)
                f1 += a[j]*pow(x1,j)
            
            d1 += math.sqrt(pow(f1-f0,2) + pow(x1-x0,2))
            x0 = x1
            
        n*=2
        
    return d1


N = int(input("Digite o grau de seu polinomio:"))
coef = list()

for i in range(N+1):
    a = float(input("Digite o coeficiente"))
    coef.append(float(a))

x0 = float(input("Digite o limite inferior do polinomio:"))
x1 = float(input("Digite o limite superior do polinomio:"))
precisao = float(input("Digite a precisao desejada:"))

comprimento = calcComprimento(coef, x0, x1, precisao, N+1)

print("Comprimento vale:")
print(comprimento)