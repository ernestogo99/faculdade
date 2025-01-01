def menor_maior(l, inicio, fim):
 
    if inicio == fim:
        return l[inicio], l[inicio]
    

    if fim == inicio + 1:
        if l[inicio] < l[fim]:
            return l[inicio], l[fim]
        else:
            return l[fim], l[inicio]
    

    meio = (inicio + fim) // 2
    menor1, maior1 = menor_maior(l, inicio, meio)
    menor2, maior2 = menor_maior(l, meio + 1, fim)
    

    if menor1 < menor2:
        menor = menor1
    else:
        menor = menor2
    

    if maior1 > maior2:
        maior = maior1
    else:
        maior = maior2
    
    return menor, maior


l = [1, 3, 45, 5, 20, 40]
menor, maior = menor_maior(l, 0, len(l) - 1)
print(f'O maior elemento da lista é {maior} e o menor é {menor}')

