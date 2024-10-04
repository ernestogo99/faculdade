 goto main
 wb 0

r ww 0 
a ww 3 
b ww 3 
c ww 3
u ww 1

main add_x x, a # caso a=c 
     sub_x x, c
     jz_x x, resultado
     add_x x, c # caso a!=c
     mov_x x, a
     add_y y, u
     mov_y y, r
     goto final
resultado add_x x, b
     mov_x x, c
final halt

