select f.nome as 'nome',avg(salario) as 'media salarial'
from filiais f,vendedores v
where codfil=f.cod
group  by f.cod,f.nome
having count(matr)>4

