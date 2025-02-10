select nome,sum(cod_dep) as "tot dep"
, sum(cod_curso) as "tot c",
sum(matr_alu) as "tot alu"
from unidade_academica ua ,departamento d, dep_curso dc,curso c,
aluno a
where
ua.cod_ua=d.cod_ua 
and
d.cod_dep=dc.cod_dep
and
c.cod_curso=a.cod_curso
