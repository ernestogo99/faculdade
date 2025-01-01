# pylint: disable=all

# maior salto

#1) algoritmo ruim O(n^2)

def maior_salto_ruim(l):
    salto = l[1] - l[0]  
    for i in range(len(l) - 1):  
        for j in range(i + 1, len(l)): 
            if l[j] - l[i] > salto: 
                salto = l[j] - l[i]  
    return salto


l=[6,8,5,7,9,2,4,1,3,6,5,2]

maior_salto=maior_salto_ruim(l)
print(f'o maior salto na lista é {maior_salto}')

#Mas agora, n´os podemos tentar conseguir um algoritmo melhor aplicando o m´etodo da divis˜ao e
#conquista.
#Quer dizer, a ideia ´e a seguinte
##1. primeiro, a gente encontra o maior salto na 1a metade
#2. depois, a gente encontra o maior salto na 2a metade
#3. da´ı, a gente encontra o maior salto envolvendo elementos das duas metades
#4. finalmente, nós pegamos o maior salto de todos
#



