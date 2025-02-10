-- Consultas SQL AP1 parte 2
-- José Alberto Rodrigues Neto - 547872
-- Gabriel Victor Magalhães da Silva - 539922

-- 1. a)
SELECT A.nome_aluno
FROM Aluno AS A
INNER JOIN Aluno-Disc AS AD ON A.matr_aluno = AD.matr_aluno
WHERE AD.Semestre = '2022.2'


-- 1. b)
SELECT ua.nome
FROM Unidade_Academica ua
WHERE (
  NOT EXISTS (
    SELECT 1
    FROM Departamento d
    WHERE d.cod_ua = ua.cod_ua
  )
)
OR (
  EXISTS (
    SELECT 1
    FROM Departamento d
    WHERE d.cod_ua = ua.cod_ua
  )
  AND NOT EXISTS (
    SELECT 1
    FROM Dep_Curso dc, Curso c
    WHERE dc.Cod_curso = c.Cod_curso
  )
)


-- 2. a)
SELECT ua.nome,
	COUNT(DISTINCT d.cod_dep) AS 'Total de Departamentos',
    COUNT(DISTINCT dc.cod_curso) AS 'Total de Cursos',
    COUNT(DISTINCT a.matr_aluno) AS 'Total de Alunos'
FROM unidade_academica ua
	LEFT JOIN departamento d ON ua.cod_ua = d.cod_ua
	LEFT JOIN dep_curso dc ON d.cod_dep = dc.cod_dep
	LEFT JOIN curso c ON dc.cod_curso = c.cod_curso
	LEFT JOIN aluno a ON c.cod_curso = a.cod_curso
GROUP BY ua.cod_ua, ua.nome


-- 2. b)
SELECT a.nome, d.nome, qtde_creditos, 1_AP, 2_AP, ISNULL(CAST(AF AS CHAR(10)), '--')
FROM curso c
	INNER JOIN aluno a ON c.cod_curso = a.cod_curso
	INNER JOIN aluno_disc ad ON a.matr_aluno = ad.matr_aluno
	INNER JOIN disciplina d ON ad.cod_disc = d.cod_disc
WHERE c.nome LIKE 'Ciencia da Computacao'
ORDER BY a.matr_aluno


-- 2. c)
SELECT p.matr_professor, ISNULL(SUM(qtde_creditos), 0) AS 'Quantidade de Creditos',
    ISNULL(CAST(semestre AS CHAR(25)), 'Nunca lecionou disciplina') AS 'Semestre'
FROM professor p
	LEFT OUTER JOIN Prof_Disc pd ON p.matr_professor = pd.matr_professor
	INNER JOIN disciplina d ON pd.cod_disc = d.cod_disc
WHERE semestre IN (20181, 20172) OR semestre IS NULL
GROUP BY p.matr_professor, semestre
HAVING ISNULL(SUM(qtde_creditos), 0) < 8


-- 2. d)
SELECT matr_aluno FROM aluno_disc ad
GROUP BY matr_aluno
HAVING (SELECT AVG(m.med) FROM
((SELECT matr_aluno, (1_AP + 2_AP + AF)/3 AS med
FROM aluno_disc
WHERE matr_aluno=ad.matr_aluno AND AF IS NOT NULL) UNION
(SELECT matr_aluno, (1_AP+2_AP)/2 AS med
FROM aluno_disc
WHERE matr_aluno=ad.matr_aluno AND AF IS NULL)) m
GROUP by m.matr_aluno) >=all (SELECT avg(m.med) FROM
((SELECT matr_aluno, (1_AP + 2_AP + AF)/3 AS med
FROM aluno_disc
WHERE AF IS NOT NULL) UNION
(SELECT matr_aluno, (1_AP+2_AP)/2 AS med
FROM aluno_disc
WHERE AF IS NULL)) m
GROUP by m.matr_aluno)

