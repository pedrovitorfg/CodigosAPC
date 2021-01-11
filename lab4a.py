def buscabinaria(target, array, p0, pN):
    pM = int((p0 + pN)/2)
    
    if array[pM] == target:
        return pM
    elif p0 >= pN:
        return -1
    else:
        if array[pM] < target:
            return buscabinaria(target, array, pM+1, pN)
        else:
            return buscabinaria(target, array, p0, pM+1)

def bubblesort(elm, tamanho):
    
    for i in range(tamanho):
        for j in range(tamanho-1):
            if elm[j] > elm[j+1]:
                t = elm[j]
                elm[j] = elm[j+1]
                elm[j+1] = t
    
    return elm

vetor = list()

N = int(input("Digite a quantidade de elementos do vetor:"))

for i in range(N):
    print("Digite o componente ", i+1," do vetor:")
    x = input()
    vetor.insert(int(N), int(x))
    
vetor = bubblesort(vetor, N)

p = float(input("Digite o valor a ser encontrado no vetor:"))

y = buscabinaria(float(p), vetor, 0, int(N-1))

if y == -1:
    print("O numero", p, "nao esta no vetor")
else:
    print("O numero", p,"esta na posicao", y+1)


