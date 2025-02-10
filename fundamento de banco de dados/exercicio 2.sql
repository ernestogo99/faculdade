-- listar codigo dos fornecedores que nao tiveram vendas

select cod from fornecedores
except
select codfor from historico,estoque
where cod=coditem