def bubblesort(elm, tamanho):
    
    for i in range(tamanho):
        for j in range(tamanho-1):
            if elm[j] > elm[j+1]:
                t = elm[j]
                elm[j] = elm[j+1]
                elm[j+1] = t
    
    return elm

def mediana(vetor, n):
    if n%2 == 0:
        a = vetor[n//2]
        b = vetor[(n//2)-1]
        med = (a+b)/2
    else:
        med = vetor[n//2]
    
    return med

a = []
t = 0
tamanho = 0

while t != 11:
    print("Adicione um numero:")
    t = float(input("(Digite 11 para encerrar)"))
    if (t >= 0) and (t <= 10):
        tamanho += 1
        a.insert(int(tamanho)-1, t)
    elif t != 11:
        print("\nNumero invalido! Somente permitido numeros entre 0 e 10!\n")

print("\nVetor digitado: ", a)


a = bubblesort(a,int(tamanho))

print("\nSequencia ordenada: ", a)

m = mediana(a, int(tamanho))

print("\nMediana: ", m)

        