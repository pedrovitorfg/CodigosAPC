pop1 = float(input("Digite o valor inicial da populacao A:"))
pop2 = float(input("Digite o valor inicial da populacao B:"))
tx1 = float(input("Digite o valor do crescimento da populacao A:"))
tx2 = float(input("Digite o valor do crescimento da populacao B:"))
tempo = 0

while pop1 < pop2:
    tempo += 1
    pop1 = pop1*(1+tx1/100)
    pop2 = pop2*(1+tx2/100)
print("O tempo decorrido é:")
print(tempo)