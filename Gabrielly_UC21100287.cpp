//Nome completp: Gabrielly Ant�nio Almeida Borges
//Matr�cula: UC221100287
//Curso: Engenharia de Software

//Projeto Pr�tico 01: Descobrir o perfil das pessoas que frequentam esse cinema

//Entradas: 1.quantidade de sess�es que ser�o realizadas, 2.o nome do filme,  
//3.quantidade de pessoas que  assistiram o filme, 4.sexo, 5.idade. 
//6.sess�o 3D, 7. meia entrada infantil
//Sa�da: a.nome do filme, b.quantidade de pessoas do sexo feminino,quantidade 
//de pessoas do sexo masculino que assistiram ao filme

//Os coment�rios que est�o no formato "//*'conceito - Cap�tulo 'x': 'defini��o'" 
//est�o baseados nos conceitos do livro: C�digo limpo, S�rie de Robert C. Martin

////*coment�rios informativos - Cap�tulo 4: Todos os coment�rios possui, claramente, informa��es da atividade feita por aquela linha
//al�m de indicar muitas vezes onde come�a e onde termina uma condicional por exemplo.
//*Coment�rios redundantes - Cap�tulo 4: Se o meu printf vai apresentar na tela "Quantas sess�es ser�o realizadas?" eu certamente 
//n�o deveria comentar algo t�o �bvio. O mesmo para scanf que se repete em v�rios momentos no c�digo coma mesma fun��o.

 

#include<stdio.h> //biblioteca para entrada e sa�da: pintf e scanf
#include<locale.h> //biblioteca para utiliza��o de acentos gr�ficos: setlocale
#include<string.h> //biblioteca para manipulamento de strings: strlen e strcmp
#include<ctype.h> //biblioteca para converter letras min�sculas e letras mai�sculas: toupper e tolower
#include <stdlib.h> //biblioteca para formata��o: system("fun��o")
#include<math.h> //biblioteca que permite efetuar opera��es matem�ticas

int main (){ 
//declara��o de v�ri�veis:
//*nomes significativos - Cap�tulo 2: foram utilizados para declara��o de vari�veis nomes que possuem significados por si s�.

    int sessoes, pessoas, idade, mulheres = 0, homens = 0, opcao, contador = 0; //armazena n�meros inteiros
    int crianca = 0, adolescente = 0, adulto = 0, idoso = 0, mulheresAdultas = 0, homensAdultos = 0;
    char sexo, filme[50]; //armazena caracteres
    
	 setlocale (LC_ALL, "portuguese"); //acentua��o gr�fica nas mensagens para os usu�rios 
//receber e processar dados: printf / scanf
//mostrar na tela ao usu�rio mensagem inicial. apresenta��o
    printf("CINEMA DE BRAS�LIA\n -Seja Bem-Vindo(a)-\n"); 
    printf ("Para Iniciar a sess�o nos informe alguns dados:\n");

//inicia o pedido de dados: sess�es
         do{ //validar a quantidade de se��es. n�o aceitando valores != de 1 e 2, repetir esse bloco do-while
         	printf("\nQuantas sess�es ser�o realizadas? [1 ou 2]\n >"); 
         	scanf("%d", &sessoes);
         	fflush(stdin); //limpeza do buffer do teclaco
         	if (sessoes == 1 || sessoes == 2){ //condi��o para n�mero de sess�es. caso o n�mero de sess�es for =1 ou =2 executar 
         	  printf("Confirmada %d sess�o / sess�es!\n", sessoes);
         	   } else{ (sessoes == 0 || sessoes > 2); //caso o n�mero seja invalido, sendo o 1� e o 2� else falso executar
         	          printf("Valor de sess�es Invalido! Tente novamente:\n"); //informar na tela ao asuario que o n�mero � invalido
            }//final do if-else
			}while (sessoes == 0 || sessoes > 2); //repetir esse bloco inteiro caso essa condi��o for verdadeira
  system("cls"); //a formata��o cls limpa a tela interior. isso vai permitir que a tela n�o mantenha muitas informa��es e n�o confunda o usu�rio 
         
//pedir dados do filme que ser� assistido ao usu�rio
    printf("CINEMA DE BRAS�LIA\n -Seja Bem-Vindo(a)-\n"); 
    printf ("Para Iniciar a sess�o nos informe alguns dados:\n");
		 do{ //validar o nome do filme, n�o sendo aceito um campo vazio [filme < 1] e n�o acito o nome "vazio"
			printf("\nQue filme voc� ir� assistir hoje?\n >"); //apresentar na tela : nome do filme
            fgets(filme, 50, stdin); //especifica em qual vari�vel ser� armazenada a informa��o
            fflush(stdin); //limpeza do buffer do teclado
            if (strlen(filme) <= 2){ //se essa condi��o for verdadeira, tendo o nome do filme >2 caracteres executar
              printf("Esse nome � muito curto! Tente novamente:\n");
                 }else if(strlen(filme) >= 3){//se o nome do filme for <1 ou = 'vazio� executar  //caso a condi��o de if seja falsa executar
                  printf("Muito bem! Pr�ximo dado:\n");
			} //final do if-else
			}while (strlen(filme) <= 2); //repetir esse bloco inteiro caso essa condi��o for verdadeira
  system("cls"); //limpando tela anterior 

//apresentar ao usu�rio as op��es do filme 
    printf("CINEMA DE BRAS�LIA\n -Seja Bem-Vindo(a)-\n"); 
    printf ("Para Iniciar a sess�o nos informe alguns dados:\n"); 
    printf("\nA sua sess�o ser�:\n 1. Comum\n 2. 3D\n >");
    scanf("%d", &opcao);
  switch(opcao){ //permite o usu�rio escolher entre duas op��es  
		case 1: printf("Confirmado: sess�o comum!"); break;
		case 2: printf("Confirmado: sess�o 3D!\n"); break;
		default: printf("Inv�lido!"); break;
    } //fim da execu��o switch
  system("cls"); //limpando tela anterior
  
//pedir e processar informa��o de quantas pessoas na sess�o
    printf("CINEMA DE BRAS�LIA\n -Seja Bem-Vindo(a)-\n"); 
    printf ("Para Iniciar a sess�o nos informe alguns dados:\n");
         do{ //validar quantidade de pessoas que assistiram ao filme. n�o aceitando valores <10
            printf("\nQuantas pessoas assistir�o ao filme?\n >");
            scanf("%d", &pessoas);
            fflush(stdin); //limpeza do buffer do teclado
            if (pessoas < 10){//caso o valor for invalido sendo <10 executar
              printf("N�mero de pessoas inferior ao permitido! Tente novamente:\n");
                }
            if (pessoas >= 10){
              printf("Legal! Agora nos informe os dados das %d pessoas:\n", pessoas);
            		}
                   //final do if-else
			}while(pessoas < 10); //repetir esse bloco inteiro caso essa condi��o for verdadeira
			
//pedir e processar dados de cada pessoa nesta sess�o
	for(contador = 0; contador < pessoas; contador++){ //conta cada dado inserido de acordo com a quantidade de pessoas na sess�o
	
		    do{ //valida��o do sexo. n�o permitindo caracter != de F/f ou M/f
		       printf("\nDiga o sexo sendo F. para feminino e M. para masculino:\n >");
		       scanf("%c", &sexo);
		       fflush(stdin); //limpeza do buffer do teclado
		       sexo = toupper(sexo); //caso o usu�rio digite em letra min�scula converter para letra maiuscula
		       if(sexo != 'F' && sexo != 'M'){ //se sexo for verdadeiro para a condi��o F.feminino executar 
		         printf("Invalido!\n");
		        }//final do if-else
		   }while (sexo != 'F' && sexo != 'M');

//Valida��o da idade indicado a faixa et�ria
    printf("Digite a idade:\n >");
	scanf("%d", &idade);
	fflush(stdin); //limpeza do buffer do teclado
//
	if (idade >= 3 && idade <= 13){
	  crianca++;
	    printf("Legal! voc� garante meia entrada infantil!\n\n");
	      }else if (idade >= 14 && idade <= 17){
	        adolescente++;
	          printf("Confirmado! %d anos: Adolescente\n\n", idade);
	            }else if (idade >= 18 && idade <= 64){
				  adulto++;
				    printf("Confirmado! %d anos: Adulto\n ", idade);
				   	  }else if (idade >=65 && idade <= 100){
				   	    idoso++;
				   	      printf("Confirmado! %d anos: Idoso\n", idade);
				   	        }else{
						      printf("Invalido! Tente novamente:\n");}
	
	
//executa leitura de informa��es da quantidade de mulheres e homens adultos	
	if (sexo == 'F'){	
	  mulheres++;			   	      
	    }else{ (sexo == 'M');
		  homens++;
	} //final do if-else

//executa leitura de informa��es da quantidade de mulheres e homens adultos						
	if (idade >= 18 && sexo == 'F'){
	  mulheresAdultas++;
	    }else{ (idade >= 18 && sexo == 'M');
	      homensAdultos++;
	} //final do if-else
} //final for
 system("cls");
  //limpando tela anterior
  
//apresentar na tela tabela com os dados processados ao usu�rio
    	printf("Aqui est� os dados confirmados para a sess�o %d %s", opcao, filme);
    	printf("\n Pessoas na sess�o    Faixa et�ria    Classifica��o    Entrada\n");
    	printf(" |       %d         ||  3 � 13 anos  ||   crian�a    ||   Meia  |\n", crianca);
    	printf(" |       %d         ||  14 � 17 anos ||  adolescente || Inteira |\n", adolescente);
    	printf(" |       %d         ||  18 � 64 anos ||    adulto    || Inteira |\n", adulto);
    	printf(" |       %d         ||  0 � 3 anos   ||    idoso     || Inteira |\n", idoso);
    	
    	printf("\nNa se��o %s est�o presentes:\n ", filme);
    	printf("        Sexo            Total\n");
    	printf(" |     Mulher     ||     %d        |\n",  mulheres);
    	printf(" |     Homem      ||     %d        |\n", homens);
    	
    	printf("\nSendo:\n");
    	printf("Mulheres Adultas: %d\n", mulheresAdultas);
    	printf("Homens Adultos: %d\n", homensAdultos);
    	
    	printf("\nN�s agradecemos sua presen�a! Aproveite sua sess�o!");
    return 0;
}
