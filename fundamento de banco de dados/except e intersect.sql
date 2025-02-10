-- vendedores sem vendas
--operador diferença(except)
-- mostra a diferença entre duas tabelas

select matr from vendedores
except
select matrvend from historico

-- vendedores com vendas
select matr from vendedores
intersect
select matrvend from historico
