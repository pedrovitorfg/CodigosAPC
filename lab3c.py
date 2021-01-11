matricula = []
trab1 = []
trab2 =[]
p1 = []
p2 = []
p3 = []



n = input("Digite a quantidade de alunos:")

for i in range(int(n)):
    print("Digite a matricula do aluno ", i+1, ":")
    x = input()
    matricula.insert(int(n), int(x))

    print("Digite a nota do tabalho 1 do aluno ", i+1, ":")
    x = input()
    trab1.insert(int(n), x)

    print("Digite a nota do tabalho 2 do aluno ", i+1, ":")
    x = input()
    trab2.insert(int(n), x)

    print("Digite a nota da prova 1 do aluno ", i+1, ":")
    x = input()
    p1.insert(int(n), x)

    print("Digite a nota da prova 2 do aluno ", i+1, ":")
    x = input()
    p2.insert(int(n), x)

    print("Digite a nota da prova 3 do aluno ", i+1, ":")
    x = input()
    p3.insert(int(n), x)


fp = open("notas.txt", "w")

for i in range(int(n)):
    fp.write("%d " %matricula[i])
    fp.write("%.2f " %float(trab1[i]))
    fp.write("%.2f " %float(trab2[i]))
    fp.write("%.2f " %float(p1[i]))
    fp.write("%.2f " %float(p2[i]))
    fp.write("%.2f\n" %float(p3[i]))
