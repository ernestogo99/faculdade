-- vendedores sem vendas
--operador diferen�a(except)
-- mostra a diferen�a entre duas tabelas

select matr from vendedores
except
select matrvend from historico

-- vendedores com vendas
select matr from vendedores
intersect
select matrvend from historico
