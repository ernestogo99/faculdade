--listar maiores e menores salarios de cada filial
--no resultado deve aparecer o nome da filial
-- o maior salario e o menor salario.

select f.nome as 'vendedores',
max(salario) as 'maior salario',
min(salario) as 'menor salario'
from vendedores v,filiais f
where codfil=f.cod
group by f.cod,f.nome 
order by 2 desc
-- 2 é a segunda coluna da lista da clausula select,mas poderia ter colocado o max salario
-- desc indica que é decrescente