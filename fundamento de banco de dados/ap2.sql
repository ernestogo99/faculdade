create VIEW V5 (nome_aluno, nome_curso, disciplinas_cursadas, creditos_obtidos)
AS
SELECT
    a.nome,
    c.nome,
    COUNT(DISTINCT CASE WHEN media_final >= 5 THEN ad.cod_disc END),
    COALESCE(SUM(CASE WHEN media_final >= 5 THEN d.qtde_creditos ELSE 0 END), 0) 
FROM
    aluno a
LEFT JOIN
    (SELECT 
        matr_aluno,
        cod_disc,
        CASE
            WHEN (I_AP + II_AP) / 2 >= 7 THEN (I_AP + II_AP) / 2
            WHEN af IS NOT NULL AND ((I_AP + II_AP) / 2 + af) / 2 >= 5 THEN ((I_AP + II_AP) / 2 + af) / 2
            ELSE 0
        END AS media_final
     FROM aluno_disc) ad ON a.matr_aluno = ad.matr_aluno
LEFT JOIN
    disciplina d ON ad.cod_disc = d.cod_disc
LEFT JOIN
    cur_disc cd ON d.cod_disc = cd.cod_disc
LEFT JOIN
    curso c ON cd.cod_curso = c.cod_curso
GROUP BY
    a.nome, c.nome, a.matr_aluno;
