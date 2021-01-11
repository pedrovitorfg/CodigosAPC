a = float(input("Primeiro segmento:"))
b = float(input("Segundo segmento:"))
c = float(input("Terceiro segmento:"))

if a <  b + c  and b <  a + c  and c <  a + b  :
    print("Os segmentos podem formar um triangulo ", end = "")
    if a == b and b == c :
        print("equilatero")
    elif a != b != c != a :
        print("escaleno")
    else:
        print("isóceles")
else :
    print("Triangulo nao existe")
    
    
        