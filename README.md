# Labirinto por Profundidade (DFS) e Largura (BFS)
<p align="justify">
	O algoritmo aqui apresentado,assim como no trabalho anterior, tem como objetivo extrair matrizes de um arquivo "input.data", percorrê-las de seuindo regras pré determinadas e salva-las em um arquivo "output.data" sem alterar as informações de "input.data". Porém, além do metodo aleatório para percorrer a matriz, dois novos métodos muito mais previsíveis foram implementados, sendo eles a busca em profundidade (DFS) e a busca em largura (BFS). 
</p>
<p align="justify">
	Na busca em profundidade, o personagem anda pelo labirinto seguindo sempre a mesma direção até chegar a uma extremidade, ou borda da matriz, ou a um caractere especial, que pode ser uma parede (#), um marcador de caminho já percorrido (x) ou o indicador de fim de jogo (?). Caso alguma condição de parada seja satisfeita, o personagem toma outro caminho baseado em uma ordem pré definida de prioridades. Ele primeiro escolhe o caminho da diagonal direita pra baixo, depois baixo, direita, diagonal esquerda pra baixo, diagonal direta pra cima, cima, diagonal esquerda pra cima e, por fim, esquerda.
</p>
<p align="justify">
	Já na busca em largura, a matriz é percorrida de modo que todas as possibilidades válidas de caminho são tomadas ao mesmo tempo. De modo que a partir da posição em que o personagem está, ele acessa todas as casas ao redor. Da posição (0,0) da matriz, por exemplo, as posições (1,0), (0,1) e (1,1) são acessadas, caso não haja uma parede impedindo a passagem do personagem. Para se implementar esse método foi utilizada uma fila, estrutura de dados do tipo "First in, First out", o que faz com que após prcorrer todas as posições possíveis da casa inicial, por exemplo, o personagem volte para a posição (1,1), que é a primeira casa acessada após a inicial. A ordem de prioridade deste método é a mesma do DFS.
</p>

<p align="justify">
	Assim como no trabalho anterior, há perigos (*) pelo caminho, agora porém, esses parigos fazem o personagem voltar para o início da matriz, sendo que a única mudança, na própria matriz, é a troca do perigo por um item (1),para evitar que a matriz seja reiniciada infinitas vezes. Todo o caminho percorrido pelo personagem antes de chegar no perigo é apagado e o percorrimento recomeça. Isso torna o processo muito mais custoso, em termos de tempo de execução e a diferença de tempo entre os métodos de busca se torna evidente. No geral, o BFS é bom para encontrar a condição de finalização (?) caso ela esteja próxima ao início da matriz, e o DFS é melhor quando ela fica mais próxima ao final.
</p>

![ProfundoPe](https://github.com/Eduardo-Rabelo/Trabalho2_AED1_2023/blob/main/Imagens/direita.png)

		
<p align="justify">	
	Na imagem acima, é mostrado como a busca em profundidade ocorre, primeiro, o personagem tenta as duas primeiras direções na ordem de prioridade, porém há paredes bloqueando seu caminho, de modo que ele vai para a direita. Ao parar na borda da matriz, ele vai direto para a quarta direção prioritária. Caso as demais direções além das três de maior prioridade estivessem bloqueadas, ele voltaria na mais prioritaria, depois na segunda e na terceira até uma ser possível. E, caso não seja, a posição é desempilhada e o personagem volta para a casa que estava anteriormente, mesmo ela sendo já marcada.
</p>

![LarguraPe](https://github.com/Eduardo-Rabelo/Trabalho2_AED1_2023/blob/main/Imagens/Diagonal.png)
	COLOCAR IMAGEM AQUI

<p align="justify">
	A última imagem, por sua vez, mostra como a busca em largura funciona. Como o personagem toma todas as direções possíveia a partir de onde ele está, ele tende a encontrar muito mais perigos e percorrer mais casas, sobretudo quando a condição de fim se encontra próxima ao final da matriz, como é demonstrado na imagem a seguir. 
</p>

![LarguraG](https://github.com/Eduardo-Rabelo/Trabalho2_AED1_2023/blob/main/Imagens/Diagonal.png)
	COLOCAR IMAGEM AQUI
<p align="justify">
	Para a mesma matriz, o DFS segue somente uma direção, ou seja, o personagem anda muito menos casas que no método BFS. Porém, caso a interrogação estivesse logo abaixo da casa inicial,o custo de percorrer a matriz seria teta de 1. 
</p>

![LProfundoG](https://github.com/Eduardo-Rabelo/Trabalho2_AED1_2023/blob/main/Imagens/Diagonal.png)
	COLOCAR IMAGEM AQUI


	
	
	
# Custo
<p align="justify">
	O custo do algoritmo, em questão de memória alocada, depende da ordem das matrizes. Para percorrer a matriz, o custo pertence à classe Teta de n, sendo n o numero de elementos da matriz. No mínimo o custo seria 2n para criar os vectors que representa a matriz e a matriz verdade,,porém,dependendo do número de perigos e do método usado, o custo aumenta, podendo chegar no pior caso, que seria uma matriz composta somente por perigos, a Teta de n! .
</p>


# Conclusão
<p align="justify">
	Em suma, comparados ao método aleatório, os métodos BFS e DFS são muito mais previsíveis e, portanto, mais indicados, porém, há casos em que eles se tornão tão ruins, ou piores que o aleatório, de modo que, se houver alguma informação a respeito do local provável de se encontrar a condição de finalização, é possível escolher o método que provavelmente busca melhor na matriz.
</p>	



# Output
<p align="justify">
No arquivo "output.data",  são mostradas a matriz percorrida e a matriz verdade de cada um dos três métodos, aleatório, DFS e BFS respectivamente. Na figura a seguir, é mostrado o output do DFS.
</p>	

![telaOutput](https://github.com/Eduardo-Rabelo/Trabalho2_AED1_2023/blob/main/Imagens/telaOutput.png)

<p align="justify">
Já na própria tela, são printadas a matriz a ser percorrida, a matriz percorrida, o número de casas percorridas ao menos uma vez na matriz,
</p>

![telaOutputPrimeiraFase](https://github.com/Eduardo-Rabelo/Trabalho2_AED1_2023/blob/main/Imagens/telaOutputPrimeiraFase.png)

<p align="justify">
	O caminho printado mostra também as tentativas de se passar pela parede, porém não mostra o movimento de retorno para a posição anterior. Para se ler o caminho,é preciso ter em mente que, caso o personagem tente atravessar a parede, o movimento não ocorre e ele fica na posição em que estava anteriormente.
</p>

<p align="justify">
Com relação ao arquivo "output.data", ele é constituido das matrizes já percorridas depois do jogo ter acabado e das matrizes verdade, que marcam os locais que foram visitados ao menos uma vez pelo personagem com o símbolo "1".
</p>

![telaOutputData](https://github.com/Eduardo-Rabelo/Trabalho2_AED1_2023/blob/main/Imagens/telaOutputData.png)


# Compilação e Execução

<p align="justify">
O arquivo Makefile permite o uso das seguintes diretrizes de execução:
</p>


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a pasta build                                        |
|  `make`                | Executa a compilação e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |


