ENTRADAS = list()
PESOS = list()
resposta = 0

def fneuronio ( E , W , T ):
    SOMAP = 0
    for i in range(3):
        SOMAP += E[i]*W[i]
    if SOMAP > T:
        y = 1
    else: 
        y = 0
    return y

for i in range(3):
    print("Digite o elemento", i+1, "do vetor entradas")
    a = input()
    ENTRADAS.append(int(a))

for i in range(3):
    print("Digite o elemento", i+1, "do vetor pesos")
    b = input()
    PESOS.append(int(b))

print("Digite o valor do limiar:")
T = float(input())

resposta = fneuronio( ENTRADAS, PESOS, T)

if resposta == 1:
    print("O neurônio está ativado")
elif resposta == 0:
    print("O neurônio está inibido")