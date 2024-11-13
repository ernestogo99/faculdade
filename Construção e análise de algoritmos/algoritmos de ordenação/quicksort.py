from utils.auxiliares import particao

def quicksort(lista,inicio,fim):
    if inicio==fim:
        return
    pos=particao(lista,inicio,fim)
    quicksort(lista,inicio,pos-1)
    quicksort(lista,pos+1,fim)
    
    
lista=[10,120,1,2,4,6,7]
fim=len(lista)
quicksort(lista,0,fim-1)
print(f'lista ordenada: {lista} ')