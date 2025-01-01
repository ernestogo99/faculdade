#O(log n)
def busca_binaria(numero,lista_ordenada):
    if len(lista_ordenada)==0:
        return
    meio=len(lista_ordenada)//2
    if lista_ordenada[meio]==meio:
        return numero
    if numero<lista_ordenada[meio]:
        return busca_binaria(numero,lista_ordenada[:meio])
    else:
        return busca_binaria(numero,lista_ordenada[meio+1:])
    
lista=[1,2,3,4,5,6]
numero_achado=busca_binaria(3,lista)

print(numero_achado)

# O(n)
def buscar(numero,lista):
    for item in lista:
        if(numero not in lista):
            return 'número não encontrado'
        else:
            return numero
        
numero=buscar(9,lista)
print(numero)

#lista 5 q4
def elemento_majoritario(lista,inicio,fim):
    if(inicio==fim):
        return lista[inicio]
    meio=(inicio+fim)//2
    esquerdo=elemento_majoritario(lista,inicio,meio)
    direito=elemento_majoritario(lista,meio+1,fim)
    if esquerdo==direito:
        return esquerdo
    
    esquerdo_count=0
    direito_count=0
    for i in range(inicio,fim+1):
        if lista[i]==esquerdo:
            esquerdo_count+=1
        if lista[i]==direito:
            direito_count+=1

    if esquerdo_count>direito_count:
        return esquerdo
    else:
        return direito
    

lista_maj = [3, 3, 4, 2, 4, 4, 2, 4, 4]
majoritario=elemento_majoritario(lista_maj,0,len(lista_maj)-1)
print(majoritario)

