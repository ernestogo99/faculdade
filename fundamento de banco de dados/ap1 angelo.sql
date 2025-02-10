--a)Listar a relação de unidades acadêmicas, com o total de departamentos, cursos e
--alunos. No resultado deve aparecer ordenado de forma decrescente por número de
--alunos. No resultado deve aparecer apenas o nome da unidade acadêmica e os totais
--solicitados.

select  dbo.unidade_academica.nome as "nome da unidade",
	count( distinct dep.cod_dep)as "quantidade de departamentos",count(  distinct curso.cod_curso) as "quantidade de cursos",
	count(aluno.matr_aluno) as "quantidade de alunos" 
from dbo.unidade_academica
	left join dbo.Departamento as dep on  dep.cod_ua=dbo.unidade_academica.cod_ua
	left join dbo.dep_curso as dep_curso on dep.cod_dep=dep_curso.cod_dep
	left join dbo.Curso as curso on curso.cod_curso=dep_curso.cod_curso
	left join dbo.Aluno as aluno on aluno.cod_curso=curso.cod_curso
group by  dbo.unidade_academica.nome
order by "quantidade de alunos" desc



--b)Listar o histórico escolar dos alunos do curso de Ciência da Computação, informando
--o nome da disciplina, quantidade de créditos, semestre cursado, nota 1a. AP, nota 2a.
--AP e AF. Para alunos que não fizeram AF, a coluna referente a este atributo deve
--aparecer --. Sugestão: utilize a função cast para converter o atributo AF e string (tipo
--char)

select 
    d.nome as nome_disciplina,
    d.qtde_creditos,
    ad.semestre,
    ad.I_AP,
    ad.II_AP,
    coalesce(cast(ad.AF as char), '--') as AF
from 
    dbo.Aluno a
inner join 
    dbo.Aluno_Disc ad on a.matr_aluno = ad.matr_aluno
inner join 
    dbo.Disciplina d on d.cod_disc = ad.cod_disc
inner join 
    dbo.Curso c on a.cod_curso = c.cod_curso
where 
    c.nome = 'Ciencia da Computacao'



--c)Listar o nome dos professores do Centro de Ciências que ministraram menos de 8
--créditos por semestre, nos semestres 2018.1 e 2018.2.


select dbo.Professor.nome,sum(dbo.Disciplina.qtde_creditos) as 'quantidade de creditos'
from dbo.Professor
left join dbo.Prof_Disc on dbo.Prof_Disc.matr_professor=dbo.Professor.matr_professor
left join dbo.Disciplina on dbo.Disciplina.cod_disc=dbo.Prof_Disc.cod_disc
where dbo.Prof_Disc.semestre in ('20181','20182') 
group by  dbo.Professor.nome
having sum(dbo.Disciplina.qtde_creditos)<8



--d)d)Listar nomes dos alunos do Centro de Ciências com maior média global. A média
--global é calculada pela média aritmética das médias das disciplinas cursadas pelo
--aluno. Observe que há alunos que não fazem a avaliação final, pois atingem média 7
--com as notas de 1a. AP e 2a. AP. Nestes casos, os alunos ficam com valor de AF
--igual a NULL.


