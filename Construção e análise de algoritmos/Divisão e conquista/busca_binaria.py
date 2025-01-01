def busca_binaria(numero,lista_ordenada):
    if len(lista_ordenada==0):
        return
    inicio=lista_ordenada[0]
    fim=lista_ordenada[-1]
    meio=(inicio+fim)//2