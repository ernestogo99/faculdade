--visões 
alter view  V1 (nome_filial,nome_vendedor)
as
select f.nome, v.nome
from filiais f inner join vendedores v
on codfil=cod

