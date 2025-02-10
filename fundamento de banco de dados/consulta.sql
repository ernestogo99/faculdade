select v.nome as 'nome vendedor',
f.nome as 'nome filial', 
cast (salario*1.15 as dec(11,2)) as 'salario com aumento'
from vendedores v, filiais f
where cod=codfil