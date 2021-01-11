import random
import math

def crie_matriz_aleatoria(n_linhas, n_colunas):
    
    matriz = []    
    
    for i in range(int(n_linhas)):    
        linha = []        
        for j in range(int(n_linhas)):        
            linha.append(random.randint(1,256))           
    
    matriz.append(linha)    
    
    return matriz

def matriz_GLCM(M, n_linhas, n_colunas, N):
    
    M = list()         
    GLCM = list()
    
    for i in range(int(N)):    
        linha = []        
        for j in range(int(N)):        
            linha.append(0)           
        GLCM.append(linha)

    for i in range(int(n_linhas)):    
        for j in range(int(n_colunas)-1):        
            a = M[i][j]
            b = M[i][j+1]
            GLCM[a][b] +=1
            
    return GLCM

def dimGLCM (M, n_linhas, n_colunas):
    A = list()
    N = 0
    
    for i in range(int(n_linhas)):
        linha = []
        for j in range(int(n_colunas)):  
           linha.append(M[i][j])           
        A.append(linha) 
            
            
    for i in range(int(n_linhas)):        
         for j in range(int(n_colunas)):        
             if ( A[i][j] > N):
                 N = A[i][j] + 1
    return N

print("Digite o numero de linhas da matriz:\n")
linhas = input()

print("Digite o numero de colunas da matriz:\n")
colunas = input()

mat = crie_matriz_aleatoria(linhas, colunas)

#dimGLCM = 0    

Nglcm = dimGLCM(mat, linhas, colunas)
             
G =  matriz_GLCM(mat, linhas, colunas, Nglcm)

for i in range(linhas):
    for j in range(colunas):
            print(mat[i][j])
    print("\n")
    
for i in range(Nglcm):    
    for j in range(Nglcm):        
            print(G[i][j])
    print("\n")     
    
energia = 0
entropia = 0
contraste = 0
homogeneidade = 0

for i in range(Nglcm):    
    for j in range(Nglcm):        
            energia += (G[i][j])*(G[i][j])
    print("\n")

for i in range(Nglcm):    
    for j in range(Nglcm):        
            entropia += -math.log(G[i][j])*(G[i][j])
    print("\n")     

for i in range(Nglcm):    
    for j in range(Nglcm):        
            contraste += (G[i][j])*(i-j)*(i-j)
    print("\n")
    
for i in range(Nglcm):    
    for j in range(Nglcm):        
            homogeneidade += (G[i][j])/(1+(i-j)*(i-j))
    print("\n")

print(energia)
print(entropia)
print(contraste)
print(homogeneidade)
