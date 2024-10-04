 goto main
 wb 0

r ww 0 
b ww 2
c ww 10 
u ww 1
m ww 0

main add_y y, b
     mov_y y, m
     sub_y y, m

     add_y y, c
     add_x x, u
laco jz_y y, resultado # o multiplicador zera o y    
     mov_y y, r

     mult_x x, m
     mov_x x, m // m é o acumulo das multiplicacoes, 2.2.2.2 = 8.2 ,8 é m
     sub_x x, m
     add_x x, b

     add_y y, r // recupera o y e tira 1 para fazer a contagem de vezes que vai ocorrer a multiplicacao
     sub_y y, u
     goto laco
resultado add_y y, m
          mov_y y, r
final halt

     
     
     
     
