# pylint: disable=all
def troca(L, i, j):
    L[i], L[j] = L[j], L[i]



def varredura(v,inicio,fim):
    for i in range(inicio,fim-1):
        if(v[i]>v[i+1]):
            troca(v,i,i+1)
            
            
def intercalacao(lista, inicio, meio, fim):
    aux = []
    i = inicio  
    j = meio + 1
    

    while i <= meio and j <= fim:
        if lista[i] <= lista[j]:
            aux.append(lista[i])
            i += 1
        else:
            aux.append(lista[j])
            j += 1


    while i <= meio:
        aux.append(lista[i])
        i += 1


    while j <= fim:
        aux.append(lista[j])
        j += 1


    for k in range(len(aux)):
        lista[inicio + k] = aux[k]

    return lista


def particao(lista,inicio,fim):
    pivo=lista[inicio]
    i=inicio+1
    j=fim
    while j>=i:
        if lista[i]<pivo:
            i+=1
        else:
            troca(lista,i,j)
            j-=1
    troca(lista,inicio,j)
    return j      
        
