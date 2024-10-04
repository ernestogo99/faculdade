 goto main
 wb 0

r ww 0 
b ww 12
u ww 1
m ww 0
n ww 0

main add_x x, b
     add_y y, b
laco sub_y y, u
     jz_y y, resultado
     mov_y y, r
     goto troca //inverte x e r de posicao
multi mult_x x, r
     add_y y, n //n agora é o valor original de y
     goto laco

troca mov_y y, n
      sub_y y, n
      add_y y, r // salva o valor de r em y
      mov_y y, n // salva o y em n
      sub_y y, n  // limpa y

      mov_x x, r // r <- x
      sub_x x, r // limpa x
      add_x x, n // x <- n, n era o antigo r
      goto multi

resultado mov_x x, r
final halt
      