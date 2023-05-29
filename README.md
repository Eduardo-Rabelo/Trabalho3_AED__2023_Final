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

</p>
	
<p align="justify">
	Todo o processo para percorrer matriz está implementado no método "void percorreMatriz()" da classe Matriz. Além das regras de transporte já citadas, dentro da mesma matriz, ou fase, o transporte ocorre de modo aleatório sendo que cada elemento da matriz gera efeitos no personagem, ou impede o movimento pela fase. O símbolo "#" simboliza uma parede intransponível, de modo que, se o movimento sorteado levar o personagem a uma posição que contém uma parede, o movimento é desfeito e sorteado novamente. O símbolo "*", por sua vez, representa um perigo, que retira uma vida do personagem cada vez que este passa por ele. Por fim, números representam itens. Ao passar por um número, o personagem ganha um item, e o número é reduzido em um, até no mínimo 0. Quando o número chega a zero, não é mais possível retirar itens de sua posição. A cada 4 itens que o personagem pega, ele ganha uma vida.
</p>

<p align="justify">
	Caso as vidas do personagem acabem, o jogo acaba em uma tela de "GAME OVER" que é representada na imagem a seguir. Nela, são exibidas as mensagens "GANME OVER" e "YOU LOST", bem como o total de itens consumidos pelo personagem, ou sua pontuação total, o número total de perigos pelos quais ele passou, o número total de casas que foram visitadas ao menos uma vez no jogo inteiro, e o número de casas que nunca sequer foram visitadas. A tela de vitória é basicamente idêntica, porém as mensagens "GANME OVER" e "YOU LOST" são substituídas pela mensagem "VICTORY". A condição de vitória é o personagem passar por todas as fases do jogo, sem ganhar itens e sem morrer, e retornar a posição inicial do jogo, que é a posição [0][0] da primeira fase. Faltou aida dizer que da última fase, o personagem se transporta para a primeira.
</p>


	
![TELAdeDERROTA](https://github.com/Eduardo-Rabelo/Trabalho2_AED1_2023/blob/main/Imagens/telaDerrota.png)


![telaVitoria](https://github.com/Eduardo-Rabelo/Trabalho2_AED1_2023/blob/main/Imagens/telaVitoria.png)
	
	
	
# Custo
<p align="justify">
	As matrizes são extraídas do arquivo "input.txt" e operadas uma a uma, ou seja, o custo do algoritmo, em questão de memória alocada, depende apenas da ordem das matrizes, não da quantidade delas. Já em questão de custo computacional, para criar os arquivos separados de cada matriz, o custo seria igual a k vezes o número n de elementos de cada matriz, porém, como as matrizes são escritas e retiradas dos arquivos uma a uma, seu custo é n. Para percorrer a matriz, no entanto, o custo pertenceria à classe Teta de n, pois seu custo é, aproximadamente, 47n, dependendo do caminho percorrido,  ou seja, menor que 100n e maior que 2n, por exemplo, o que o enquadra o método "void percorreMatriz()" nessa classe de algoritmos. Como estruturas condicionais sao caras computacionalmente, e este método é o que mais faz uso delas, ele é o mais caro do algoritmo, portanto, é correto dizer que o algoritmo pertence à classe Teta de n. 
</p>


# Conclusão
<p align="justify">
	É importante dizer que, em questão de tempo de execução, o algoritmo é imprevisível, pois o método escolhido para percorrer a matriz foi a aleatoriedade, portanto, o personagem pode andar por todas as fases muitas vezes antes de uma das condições de parada ser satisfeita. Inclusive, é muito mais provável que o personagem morra, do que ele sobreviva a todas as fases até passar por todas elas e volte a posição de início de jogo sem ter adquirido itens na última vez que passou por todas as fases. Ou seja, tendo como objetivo a vitória no jogo, convém estudar outro método de percorrer a matriz, porém, como a execução do programa termina caso o personagem morra, sua execução, no geral, é rápida. Caso houver poucos, ou nenhum perigo, porém, o programa pode demorar muito para ser executado, a depender do tamanho e do número de matrizes.
</p>	



# Output
<p align="justify">
O output do programa,além do arquivo "output.data", o qual será explanado adiante, consiste em prints na tela de todas as matrizes do seguinte modo: primeiro, é printada a matriz antes de ser percorrida, depois a posição inicial para o percorrimento, depois o caminho percorrido, incluindo a indicação de por onde o personagem saiu da matriz, porém em caixa alta, a matriz após ser percorrida e, por fim, estatos importantes como pontos ganhos ao percorrer a fase, perigos enfrentados na fase naquela iteraçao,	casas percorridas ao menos uma vez na fase com o decorrer do jogo, pontos totais acumulados, vidas e itens do personagem.
</p>	

![telaOutput](https://github.com/Eduardo-Rabelo/Trabalho2_AED1_2023/blob/main/Imagens/telaOutput.png)

<p align="justify">
Todas as matrizes são printadas dessa forma cada vez que são percorridas e, sempre que a primeira matriz é percorrida, printa-se também o número de vezes que ela já foi percorrida. Se for a primeira vez que ela estiver sendo percorrida, o número printado será 1. Na imagem a seguir, por exemplo, é a quinta vez que o personagem alcança a fase 1.
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


