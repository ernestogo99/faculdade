import ufc2x as cpu
import memory as mem
import clock as clk

mem.write_word(50, 21) 
mem.write_word(100, 32)


# X <- X + memory[50]
mem.write_byte(1, 2)      # X <- X + memory...
mem.write_byte(2, 50)     # ...[50]

# memory[150] = X
mem.write_byte(9, 10)
mem.write_byte(10, 150)    
    
# stop
mem.write_byte(11, 255)


clk.start([cpu])

print(mem.read_word(150))