create procedure Q3_Aprovados
AS
BEGIN
  
SELECT
    a.nome AS nome_aluno, c.nome as nome_curso,
	sum(disc.qtde_creditos) as creditos,
    AVG(CASE
        WHEN af IS NULL THEN (I_AP + II_AP) / 2
        ELSE (I_AP + II_AP + AF) / 3
      END) AS media_notas,
	disc.nome AS nome_disciplina
  FROM
    aluno a
    INNER JOIN curso c ON a.cod_curso = c.cod_curso
    INNER JOIN aluno_disc ad ON ad.matr_aluno = a.matr_aluno
	INNER JOIN disciplina disc ON disc.cod_disc = ad.cod_disc
  WHERE
    ((af IS NULL AND (I_AP + II_AP) / 2 >= 7) OR
    (af IS NOT NULL AND (I_AP + II_AP + AF) / 3 > =7)) AND
	c.nome LIKE 'Ciencia da computacao'
  GROUP BY
    a.nome, c.nome, disc.nome,disc.qtde_creditos;


END;