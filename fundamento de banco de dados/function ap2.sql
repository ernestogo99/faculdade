CREATE FUNCTION Q3 (@mat_ent INT)
RETURNS @tab_result TABLE
(
    disciplina VARCHAR(50)
)
AS
BEGIN
    DECLARE @matricula INT
    DECLARE @tabelaAux TABLE (disciplina NVARCHAR(MAX))

    SET @matricula = @mat_ent

    INSERT INTO @tabelaAux (disciplina)
    SELECT
        disc.nome AS disciplina
    FROM
        aluno al
        INNER JOIN curso cur ON al.cod_curso = cur.cod_curso
        INNER JOIN aluno_disc ad ON ad.matr_aluno = al.matr_aluno
        INNER JOIN disciplina disc ON disc.cod_disc = ad.cod_disc
    WHERE
        al.matr_aluno = @matricula AND
        ((af IS NULL AND (I_AP + II_AP) / 2 > 7) OR
        (af IS NOT NULL AND (I_AP + II_AP + AF) / 3 > 7)) AND
        cur.nome LIKE 'Ciencia da computacao'
    GROUP BY
        disc.nome;

    IF EXISTS (SELECT 1 FROM @tabelaAux)
    BEGIN
        INSERT INTO @tab_result (disciplina)
        SELECT disciplina FROM @tabelaAux;
    END
    ELSE
    BEGIN
        INSERT INTO @tab_result (disciplina)
        SELECT
            disc.nome AS disciplina
        FROM
            aluno al
            INNER JOIN curso cur ON al.cod_curso = cur.cod_curso
            INNER JOIN aluno_disc ad ON ad.matr_aluno = al.matr_aluno
            INNER JOIN disciplina disc ON disc.cod_disc = ad.cod_disc
        WHERE
            ((af IS NULL AND (I_AP + II_AP) / 2 < 7) OR
            (af IS NOT NULL AND (I_AP + II_AP + AF) / 3 < 7)) AND
            cur.nome LIKE 'Ciencia da computacao'
        GROUP BY
            disc.nome;
    END

    RETURN;
END