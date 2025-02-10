select d.nome, d.qtde_cred, fd.semestre, ad.1ap, ad.2ap, CAST(ad.af, '--')
from Curso c, Aluno a, Aluno_disc ad, Disciplina d, Prof_Disc fd
where c.cod_curso=a.cod_curso and a.matr_aluno=ad.matr_aluno and d.cod_disc=ad.cod_disc and fd.cod_disc=d.cod_disc
and c.nome='Ciência da computação'