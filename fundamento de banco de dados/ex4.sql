-- mostrar a quantidade de itens vendidos e o numero de vendas
-- por vendedor e por item
-- resultado deve estar ordenado pelo nome do vendedor

select v.nome as 'vendedor',coditem,
sum(qtde) as 'quantidade vendida',count(*) 'numero de vendas'
from vendedores v,historico h
where matrvend=matr
group by  matr,v.nome,coditem
order by v.nome