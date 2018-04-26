# BinaryTree

Neste repositório é implementado o container denominado __Árvore de Busca Binária__ referente à atividade da 2ª unidade da disciplina de
_Estrutura de Dados II_ do bacharelado de Tecnologia da Informação (__UFRN__). 


## O que é Árvore de busca binária?

Em Ciência da computação, uma árvore binária de busca (ou árvore binária de pesquisa) é uma estrutura de dados de árvore binária baseada em nós, onde todos os nós da subárvore esquerda possuem um valor numérico inferior ao nó raiz e todos os nós da subárvore direita possuem um valor superior ao nó raiz (esta é a forma padrão, podendo as subárvores serem invertidas, dependendo da aplicação).

O objetivo desta árvore é estruturar os dados de forma a permitir busca binária.[^1]  


| Algoritmo 	| Pior caso 	|
| :--			|			--:	|
| Busca			|	O(n)		|
| Inserção		|	O(n)		|
| Remoção		|	O(n)		|


[^1]: https://pt.wikipedia.org/wiki/%C3%81rvore_bin%C3%A1ria_de_busca

## Etapa de compilação e execução

	Obs: Todos os códigos digitados no terminal deverão ser na respectiva pasta do programa.

Depois de clonar o repositório na respectiva pasta local, digite ```make``` para 
realizar a compilação, resultando na criação do arquivo binário(executável) 
denominado ***binarytree***. Em seguida, digite ```./binarytree``` para executar o programa.

###  Documentação e exclusão dos objetos e do executável

Caso deseje verificar a documentação, digite ```make doxy```. Diante disso, abra a pasta **html**, depois abra o arquivo chamado **index.html** o qual possui a documentação.  

Além disso, caso deseje fazer o debugger do programa, primeiro digite no terminal ```make debug```, depois digite ```gdb ./binarytree```.  Ou, se quiser apagar os objetos e o executável, digite ```make clean```.

## Autor

Samuel Lucas de Moura Ferino(_samuel1797@gmail.com_)


