-- vendedores sem vendas
--operador diferenša(except)
-- mostra a diferenša entre duas tabelas

select matr from vendedores
except
select matrvend from historico

-- vendedores com vendas
select matr from vendedores
intersect
select matrvend from historico
