from utils.auxiliares import intercalacao

def mergesort(lista,inicio,fim):
    if(fim<=inicio):
        return
    meio=(inicio+fim)//2
    mergesort(lista,inicio,meio)
    mergesort(lista,meio+1,fim)
    intercalacao(lista,inicio,meio,fim)
    
    
    
lista=[10,120,1,2,4,6,7]
fim=len(lista)

mergesort(lista,0,fim-1)
print(f'lista ordenada: {lista}')