//Nome completp: Gabrielly Antônio Almeida Borges
//Matrícula: UC221100287
//Curso: Engenharia de Software

//Projeto Prático 01: Descobrir o perfil das pessoas que frequentam esse cinema

//Entradas: 1.quantidade de sessões que serão realizadas, 2.o nome do filme,  
//3.quantidade de pessoas que  assistiram o filme, 4.sexo, 5.idade. 
//6.sessão 3D, 7. meia entrada infantil
//Saída: a.nome do filme, b.quantidade de pessoas do sexo feminino,quantidade 
//de pessoas do sexo masculino que assistiram ao filme

//Os comentários que estão no formato "//*'conceito - Capítulo 'x': 'definição'" 
//estão baseados nos conceitos do livro: Código limpo, Série de Robert C. Martin

////*comentários informativos - Capítulo 4: Todos os comentários possui, claramente, informações da atividade feita por aquela linha
//além de indicar muitas vezes onde começa e onde termina uma condicional por exemplo.
//*Comentários redundantes - Capítulo 4: Se o meu printf vai apresentar na tela "Quantas sessões serão realizadas?" eu certamente 
//não deveria comentar algo tão óbvio. O mesmo para scanf que se repete em vários momentos no código coma mesma função.

 

#include<stdio.h> //biblioteca para entrada e saída: pintf e scanf
#include<locale.h> //biblioteca para utilização de acentos gráficos: setlocale
#include<string.h> //biblioteca para manipulamento de strings: strlen e strcmp
#include<ctype.h> //biblioteca para converter letras minúsculas e letras maiúsculas: toupper e tolower
#include <stdlib.h> //biblioteca para formatação: system("função")
#include<math.h> //biblioteca que permite efetuar operações matemáticas

int main (){ 
//declaração de váriáveis:
//*nomes significativos - Capítulo 2: foram utilizados para declaração de variáveis nomes que possuem significados por si só.

    int sessoes, pessoas, idade, mulheres = 0, homens = 0, opcao, contador = 0; //armazena números inteiros
    int crianca = 0, adolescente = 0, adulto = 0, idoso = 0, mulheresAdultas = 0, homensAdultos = 0;
    char sexo, filme[50]; //armazena caracteres
    
	 setlocale (LC_ALL, "portuguese"); //acentuação gráfica nas mensagens para os usuários 
//receber e processar dados: printf / scanf
//mostrar na tela ao usuário mensagem inicial. apresentação
    printf("CINEMA DE BRASÍLIA\n -Seja Bem-Vindo(a)-\n"); 
    printf ("Para Iniciar a sessão nos informe alguns dados:\n");

//inicia o pedido de dados: sessões
         do{ //validar a quantidade de seções. não aceitando valores != de 1 e 2, repetir esse bloco do-while
         	printf("\nQuantas sessões serão realizadas? [1 ou 2]\n >"); 
         	scanf("%d", &sessoes);
         	fflush(stdin); //limpeza do buffer do teclaco
         	if (sessoes == 1 || sessoes == 2){ //condição para número de sessões. caso o número de sessões for =1 ou =2 executar 
         	  printf("Confirmada %d sessão / sessões!\n", sessoes);
         	   } else{ (sessoes == 0 || sessoes > 2); //caso o número seja invalido, sendo o 1° e o 2° else falso executar
         	          printf("Valor de sessões Invalido! Tente novamente:\n"); //informar na tela ao asuario que o número é invalido
            }//final do if-else
			}while (sessoes == 0 || sessoes > 2); //repetir esse bloco inteiro caso essa condição for verdadeira
  system("cls"); //a formatação cls limpa a tela interior. isso vai permitir que a tela não mantenha muitas informações e não confunda o usuário 
         
//pedir dados do filme que será assistido ao usuário
    printf("CINEMA DE BRASÍLIA\n -Seja Bem-Vindo(a)-\n"); 
    printf ("Para Iniciar a sessão nos informe alguns dados:\n");
		 do{ //validar o nome do filme, não sendo aceito um campo vazio [filme < 1] e não acito o nome "vazio"
			printf("\nQue filme você irá assistir hoje?\n >"); //apresentar na tela : nome do filme
            fgets(filme, 50, stdin); //especifica em qual variável será armazenada a informação
            fflush(stdin); //limpeza do buffer do teclado
            if (strlen(filme) <= 2){ //se essa condição for verdadeira, tendo o nome do filme >2 caracteres executar
              printf("Esse nome é muito curto! Tente novamente:\n");
                 }else if(strlen(filme) >= 3){//se o nome do filme for <1 ou = 'vazio´ executar  //caso a condição de if seja falsa executar
                  printf("Muito bem! Próximo dado:\n");
			} //final do if-else
			}while (strlen(filme) <= 2); //repetir esse bloco inteiro caso essa condição for verdadeira
  system("cls"); //limpando tela anterior 

//apresentar ao usuário as opções do filme 
    printf("CINEMA DE BRASÍLIA\n -Seja Bem-Vindo(a)-\n"); 
    printf ("Para Iniciar a sessão nos informe alguns dados:\n"); 
    printf("\nA sua sessão será:\n 1. Comum\n 2. 3D\n >");
    scanf("%d", &opcao);
  switch(opcao){ //permite o usuário escolher entre duas opções  
		case 1: printf("Confirmado: sessão comum!"); break;
		case 2: printf("Confirmado: sessão 3D!\n"); break;
		default: printf("Inválido!"); break;
    } //fim da execução switch
  system("cls"); //limpando tela anterior
  
//pedir e processar informação de quantas pessoas na sessão
    printf("CINEMA DE BRASÍLIA\n -Seja Bem-Vindo(a)-\n"); 
    printf ("Para Iniciar a sessão nos informe alguns dados:\n");
         do{ //validar quantidade de pessoas que assistiram ao filme. não aceitando valores <10
            printf("\nQuantas pessoas assistirão ao filme?\n >");
            scanf("%d", &pessoas);
            fflush(stdin); //limpeza do buffer do teclado
            if (pessoas < 10){//caso o valor for invalido sendo <10 executar
              printf("Número de pessoas inferior ao permitido! Tente novamente:\n");
                }
            if (pessoas >= 10){
              printf("Legal! Agora nos informe os dados das %d pessoas:\n", pessoas);
            		}
                   //final do if-else
			}while(pessoas < 10); //repetir esse bloco inteiro caso essa condição for verdadeira
			
//pedir e processar dados de cada pessoa nesta sessão
	for(contador = 0; contador < pessoas; contador++){ //conta cada dado inserido de acordo com a quantidade de pessoas na sessão
	
		    do{ //validação do sexo. não permitindo caracter != de F/f ou M/f
		       printf("\nDiga o sexo sendo F. para feminino e M. para masculino:\n >");
		       scanf("%c", &sexo);
		       fflush(stdin); //limpeza do buffer do teclado
		       sexo = toupper(sexo); //caso o usuário digite em letra minúscula converter para letra maiuscula
		       if(sexo != 'F' && sexo != 'M'){ //se sexo for verdadeiro para a condição F.feminino executar 
		         printf("Invalido!\n");
		        }//final do if-else
		   }while (sexo != 'F' && sexo != 'M');

//Validação da idade indicado a faixa etária
    printf("Digite a idade:\n >");
	scanf("%d", &idade);
	fflush(stdin); //limpeza do buffer do teclado
//
	if (idade >= 3 && idade <= 13){
	  crianca++;
	    printf("Legal! você garante meia entrada infantil!\n\n");
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
	
	
//executa leitura de informações da quantidade de mulheres e homens adultos	
	if (sexo == 'F'){	
	  mulheres++;			   	      
	    }else{ (sexo == 'M');
		  homens++;
	} //final do if-else

//executa leitura de informações da quantidade de mulheres e homens adultos						
	if (idade >= 18 && sexo == 'F'){
	  mulheresAdultas++;
	    }else{ (idade >= 18 && sexo == 'M');
	      homensAdultos++;
	} //final do if-else
} //final for
 system("cls");
  //limpando tela anterior
  
//apresentar na tela tabela com os dados processados ao usuário
    	printf("Aqui está os dados confirmados para a sessão %d %s", opcao, filme);
    	printf("\n Pessoas na sessão    Faixa etária    Classificação    Entrada\n");
    	printf(" |       %d         ||  3 à 13 anos  ||   criança    ||   Meia  |\n", crianca);
    	printf(" |       %d         ||  14 à 17 anos ||  adolescente || Inteira |\n", adolescente);
    	printf(" |       %d         ||  18 à 64 anos ||    adulto    || Inteira |\n", adulto);
    	printf(" |       %d         ||  0 à 3 anos   ||    idoso     || Inteira |\n", idoso);
    	
    	printf("\nNa seção %s estão presentes:\n ", filme);
    	printf("        Sexo            Total\n");
    	printf(" |     Mulher     ||     %d        |\n",  mulheres);
    	printf(" |     Homem      ||     %d        |\n", homens);
    	
    	printf("\nSendo:\n");
    	printf("Mulheres Adultas: %d\n", mulheresAdultas);
    	printf("Homens Adultos: %d\n", homensAdultos);
    	
    	printf("\nNós agradecemos sua presença! Aproveite sua sessão!");
    return 0;
}
