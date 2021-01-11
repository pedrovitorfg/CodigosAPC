import math

class complexo:

    def __init__(self, initX, initY, initFormato):

        self.x = float(initX)
        self.y = float(initY)
        self.formato = initFormato
 
    def convert(point1, FS):
        
        if point1.formato != FS :
            if FS == 'E':
                point1.x =  ((float(point1.x) ** 2) + (float(point1.y) ** 2)) ** 0.5
                point1.y =  math.atan(float(point1.y)/float(point1.x))
                
            elif FS == 'C':
                point1.x = float(point1.x) * math.cos(float(point1.y))
                point1.y = float(point1.x) * math.sin(float(point1.y))
                
        elif point1.formato == FS :
            point1.x = point1.x
            point1.y = point1.y
            
    def complexOp (self, p1, p2, operacao, FS):
            
       if operacao == 'M' :
           p1.convert('E')
           p2.convert('E')
           R.x = p1.x*p2.x
           R.y = p1.y+p2.y
           R.formato = 'E'
       elif operacao == 'D' :  
           p1.convert('E')
           p2.convert('E')
           R.x = p1.x/p2.x
           R.y = p1.y-p2.y
           R.formato = 'E'
       elif operacao == 'A' :  
           p1.convert('C')
           p2.convert('C')
           R.x = p1.x+p2.x
           R.y = p1.y+p2.y
           R.formato = 'C'
       elif operacao == 'S' :  
           p1.convert('C')
           p2.convert('C')
           R.x = p1.x-p2.x
           R.y = p1.y-p2.y
           R.formato = 'C'
                
       if FS == 'C' :
           R.convert('C')
       elif FS == 'E':
           R.convert('E')
        
A = complexo(0,0,'C')
B = complexo(0,0,'C')
R = complexo(0,0,'C')

print("Calculadora de números complexos:")
print("*********************************")
print("Escolha uma opção:")
print(" C => Conversão de coordenadas")
print(" O => Operação entre numeros complexos")
print(" Z => Sair do programa")
opcao = input()

while opcao != "Z":
    
    if opcao == "O":

        A.formato = input("Sistema de coordenadas do primeiro numero:")
        
        if A.formato == 'C':
            A.x = float(input("Parte real do primeiro numero:"))
            A.y = float(input("Parte imaginaria do primeiro numero:"))
        
        elif A.formato == 'E' :
            A.x = float(input("Modulo do primeiro numero:"))
            A.y = float(input("Fase do primeiro numero:"))
        else: 
            print("Opção inválida.")
            
        B.formato = input("Sistema de coordenadas do segundo numero:")
        
        if B.formato == 'C':
            B.x = float(input("Parte real do segundo numero:"))
            B.y = float(input("Parte imaginaria do segundo numero:"))
        
        elif B.formato == 'E' :
            B.x = float(input("Modulo do segundo numero:"))
            B.y = float(input("Fase do segundo numero:"))
        else: 
            print("Opção inválida.")
        
        op = input("Digite a operação desejada:")  
        
        out = input("Digite o formato de saida desejado:")
        
        R.complexOp(A,B,op,out)
        
        if out == 'E':
            print("Modulo:")
            print(R.x)
            print("Fase:")
            print(R.y)
        elif out == 'C':
            print("Real:")
            print(R.x)
            print("Imaginária:")
            print(R.y)
            
        print("Escolha uma opção:")
        print(" C => Conversão de coordenadas")
        print(" O => Operação entre numeros complexos")
        print(" Z => Sair do programa")
        opcao = input()
            
    elif opcao == "C":
        
        A.formato = input("Sistema de coordenadas de seu numero:")
        
        if A.formato == 'C':
            A.x = float(input("Parte real de seu numero:"))
            A.y = float(input("Parte imaginaria de seu numero:"))
        
        elif A.formato == 'E' :
            A.x = float(input("Modulo de seu numero:"))
            A.y = float(input("Fase de seu numero:"))
        else: 
            print("Opção inválida.")
        
        out = input("Digite o formato de saida desejado:")
        
        A.convert(out)
        
        if out == 'E':
            print("Modulo:")
            print(A.x)
            print("Fase:")
            print(A.y)
        elif out == 'C':
            print("Real:")
            print(A.x)
            print("Imaginária:")
            print(A.y)
            
        print("Escolha uma opção:")
        print(" C => Conversão de coordenadas")
        print(" O => Operação entre numeros complexos")
        print(" Z => Sair do programa")
        opcao = input()
        
