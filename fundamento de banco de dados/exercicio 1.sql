-- listar nome das filiais que venderam itens de fornecedores
-- localizados na cidade de sp

select  distinct fi.nome
from filiais fi,vendedores v,historico h,estoque e,fornecedores f
where fi.cod=v.codfil and matr=matrvend and coditem=e.cod
and codfor=f.cod and  f.cid like '__o _aulo'
