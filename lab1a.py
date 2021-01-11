
print("Digite o primeiro algarismo (mais a esquerda): ")
    
a = input()
    
print("Digite o segundo algarismo (central): ")
    
b = input()
    
print("Digite o terceiro algarismo (mais a direita): ")
    
c = input()
    
DV = 11 - ( 2*c + 3*b + 4*a )%11
    
print("O digito verificador vale ")

print(DV)
    