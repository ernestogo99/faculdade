/* essencialmente exceções são um mecanismo que permite separar a detecção
de um erro de seu tratamento.

mais especificamente , se f1 -> f2 ->f3 -> f4 é uma sequencia de chamada
de funções tais que a execução da função f1 chama f2  que durante sua execução
chama f3, que por sua vez chama f4, e se f4 joga/dispara uma excessao ,então:

1) f4 pode,ela mesma , tratar a exceção, e se o fizer, o fluxo da execução continua
em f4 a partir desse tratamento

2) se porem,f4 não tratar a a exceção ,então a execução  de f4 sera encerrada
e  o fluxo retorna a f3 , que pode tratar a exceção,retomando a execução a partir
dai

3)se f3 não tratar a exceção, repete-se o processo, f3 é encerrado e o fluxo retorna
a f2,que pode ou não tratar o processo.

4) se a exceção chegar a f1 e f1 não trata-la,o programa é encerrado,devido
a exceção não tratada (isso supondo que f1 é a função principal, e que portan
to não havia sido chamada por nenhuma outra)
*/