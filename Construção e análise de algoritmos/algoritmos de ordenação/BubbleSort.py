from utils.auxiliares import varredura

def bubblesort(Lista):
    tamanho=len(Lista)
    for i in range(0,tamanho-1):
        varredura(Lista,0,tamanho-i)
                
    
lista=[10,120,1,2,4,6,7]

bubblesort(lista)

print("lista ordenada: ",lista)