#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	srand(time(0));	
	
	//vetores com as letras de cada pa�s//////////
	char brasil[6] = {'b', 'r', 'a', 's', 'i', 'l'};
	char alemanha[8] = {'a', 'l', 'e', 'm', 'a', 'n', 'h', 'a'}; 
	char estadosUnidos[14] = {'e', 's', 't', 'a', 'd', 'o', 's', ' ', 'u', 'n', 'i', 'd', 'o', 's'};
	char belgica[7] = {'b', 'e', 'l', 'g', 'i', 'c', 'a'};
	////////////////////////////////////////////////////
	
	//letra digitada pelo usu�rio//////////////////////
	char letraUsuario;
	
	//vetor de letras digitadas pelo usu�rio//////////
	char letrasUsadas[26];
	
	//op��o pro usu�rio jogar novamente ou n�o///////
	char restart;
	
	//vari�vel para randomizar a palavra sorteada///
	int palavraSorteada;
	
	//vari�vel que governa o progresso do vetor das letras digitadas
	int chute;
	
	//tentativas que o usu�rio possui antes de perder
	int tentativas;
	
	//vari�vel de contagem
	int i;
	
	//progresso do jogador para verificar quando ele vence
	int finalizado;
	
	//vari�vel que verifica se a letra digitada est� correta ou n�o
	int letraCorreta;
	
	jogo:
	
	finalizado = 0;
	tentativas = 6;
	chute = 0;
	palavraSorteada = rand() % 4 + 1;;
	
	//limpeza de vetor
	for(i = 0; i < 26; ++i)
	{
		letrasUsadas[i] = NULL;
	}
	
	switch(palavraSorteada)
	{
		case 1: //brasil
		{
			printf("\nSua palavra j� foi sorteada:\n\n");
			for(i = 0; i < 6; ++i)
			{
				printf("? ");
				
			}
			
			int resposta[6];
			
			//limpeza de vetor
			for(i = 0; i < 6; ++i)
			{
				resposta[i] = NULL;
			}
			
			//in�cio de fato do jogo
			while(tentativas > 0)
			{
				//scan da letra digitada pelo usu�rio
				printf("\n\nDigite uma letra: ");
				letraUsuario = getch();
				
				//la�o para verificar se a letra do usu�rio j� havia sido digitada previamente
				for(i = 0; i < chute; ++i)
				{
					if(letraUsuario == letrasUsadas[i])
					{
						printf("\nLetra j� utilizada, digite outra\n");
						letraUsuario = getch();
						
						break;
					}
				}
				
				//vetor que armazena a letra digitada
				letrasUsadas[chute] = letraUsuario;
				++chute;
			
				printf("\n\nLetras utilizadas: ");
				for(i = 0; i < chute; ++i)
				{
			   	   	printf("%c ", letrasUsadas[i]);
  	  	  	    }	
        		printf("\n\n");
        
        		//vari�vel que verifica se a letra digitada � correta ou n�o
        		letraCorreta = 0;
	        
				for(i = 0; i < 6; ++i)
				{
					//verifica se a letra digitada � uma letra do pa�s
					if(letraUsuario == brasil[i])
					{
						resposta[i] = letraUsuario;
				   	   	printf("%c ", resposta[i]);
				   	   	
				   	   	//linha pra dizer que a letra digitada foi a letra correta
						letraCorreta++;
						
						//linha que aumenta o progresso de conclus�o da palavra
						finalizado++;
					
					}
					//condicioal pra evitar que uma letra anteriormente digitada se perca
					else if(resposta[i] == brasil[i])
					{
				   	   	resposta[i] = brasil[i];
				   	   	printf("%c ", resposta[i]);
					}
					else
					{
						printf("? ");
					}
					
				}
		
				//condicional pra diminuir as chances restantes do jogador caso ele erre
				if(letraCorreta == 0)
				{
					tentativas -= 1;
					
					//desenho do bonequinho
					switch(tentativas)
					{
					case 5:
						printf("\n O");
						break;
					case 4:
						printf("\n O\n/");
						break;
					case 3:
						printf("\n O\n/I");
						break;
					case 2:
						printf("\n O\n/I\\");
						break;
					case 1:
						printf("\n O\n/I\\\n/");
						break;
					case 0:
						printf("\n O\n/I\\\n/\\");
						break;
					}
					
			
					printf("\n %d chances restantes!\n", tentativas);
					
				
					if(tentativas == 0)
					{
						printf("\nVoc� perdeu!");
					}
				}
				//condicional pra verificar se o jogador concluiu a palavra
				else if(finalizado == 6)
				{
					printf("\nParab�ns, voc� venceu!");
					break;
				}
		
			}
			
			
		}break;
		
		case 2: //alemanha
		{	
			printf("Sua palavra j� foi sorteada:\n\n");
			for(i = 0; i < 8; ++i)
			{
				printf("? ");
				
			}
			
			int resposta[8];
			
			//limpeza de vetor
			for(i = 0; i < 8; ++i)
			{
				resposta[i] = NULL;
			}
			
			while(tentativas > 0)
			{
				printf("\n\nDigite uma letra: ");
				letraUsuario = getch();
				
				for(i = 0; i < chute; ++i)
				{
					if(letraUsuario == letrasUsadas[i])
					{
						printf("\nLetra j� utilizada, digite outra\n");
						letraUsuario = getch();
						
						break;
					}
				}
			
				letrasUsadas[chute] = letraUsuario;
				++chute;
			
				printf("\n\nLetras utilizadas: ");
				for(i = 0; i < chute; ++i)
				{
					printf("%c ", letrasUsadas[i]);
	            }	
				printf("\n\n");
        
        		letraCorreta = 0;
	        
				for(i = 0; i < 8; ++i)
				{
					if(letraUsuario == alemanha[i])
					{
						resposta[i] = letraUsuario;
						printf("%c ", resposta[i]);
						letraCorreta++;
						
						//condicional para evitar que o jogador receba projeto desnecess�rio
						if(letraUsuario == 'a')
						{
							finalizado++;
						}
						else
						{
							finalizado++;
						}
					
					}
					else if(resposta[i] == alemanha[i])
					{
						resposta[i] = alemanha[i];
						printf("%c ", resposta[i]);
					}
					else
					{
						printf("? ");
					}
			
				
				}
		
				if(letraCorreta == 0)
				{
					tentativas -= 1;
					
					switch(tentativas)
					{
					case 5:
						printf("\n O");
						break;
					case 4:
						printf("\n O\n/");
						break;
					case 3:
						printf("\n O\n/I");
						break;
					case 2:
						printf("\n O\n/I\\");
						break;
					case 1:
						printf("\n O\n/I\\\n/");
						break;
					case 0:
						printf("\n O\n/I\\\n/\\");
						break;
					}
			
					printf("\n %d chances restantes!", tentativas);
					if(tentativas == 0)
					{
						printf("\nVoc� perdeu!");
					  }	
				}
				else if(finalizado == 8)
				{
					printf("\nParab�ns, voc� venceu!");
					break;
				}
		
			}
		}break;
		
		case 3: //estados unidos
		{
			printf("Sua palavra j� foi sorteada:\n\n");
			for(i = 0; i < 14; ++i)
			{
				printf("? ");
				
				if(i == 7)
				{
					printf(" ");
				}
			}
			
			int resposta[14];
			
			//limpeza de vetor
			for(i = 0; i < 14; ++i)
			{
				resposta[i] = NULL;
			}
			
			while(tentativas > 0)
			{
				printf("\n\nDigite uma letra: ");
				letraUsuario = getch();
				
				for(i = 0; i < chute; ++i)
				{
					if(letraUsuario == letrasUsadas[i])
					{
						printf("\nLetra j� utilizada, digite outra\n");
						letraUsuario = getch();
						
						break;
					}
				}
			
				letrasUsadas[chute] = letraUsuario;
				++chute;
			
				printf("\n\nLetras utilizadas: ");
				for(i = 0; i < chute; ++i)
				{
					printf("%c ", letrasUsadas[i]);
	            }	
				printf("\n\n");
        
        		letraCorreta = 0;
	        
				for(i = 0; i < 14; ++i)
				{
					if(letraUsuario == estadosUnidos[i])
					{
						resposta[i] = letraUsuario;
						printf("%c ", resposta[i]);
						letraCorreta++;
						
						//condicional para evitar que o jogador receba progresso desnecess�rio
						if(letraUsuario == 's' || letraUsuario == 'd' || letraUsuario == 'o')
						{
						finalizado++;
						}
						else
						{
							finalizado++;
					   	}
					}
					else if(resposta[i] == estadosUnidos[i])
					{
						resposta[i] = estadosUnidos[i];
						printf("%c ", resposta[i]);
					}
					else
					{
						if(i == 7)
						{
							printf(" ");
						}
						else
						{
							printf("? ");
						}
					}
				}
		
				if(letraCorreta == 0)
				{
					tentativas -= 1;
					
					switch(tentativas)
					{
					case 5:
						printf("\n O");
						break;
					case 4:
						printf("\n O\n/");
						break;
					case 3:
						printf("\n O\n/I");
						break;
					case 2:
						printf("\n O\n/I\\");
						break;
					case 1:
						printf("\n O\n/I\\\n/");
						break;
					case 0:
						printf("\n O\n/I\\\n/\\");
						break;
					}
			
					printf("\n %d chances restantes!", tentativas);
					if(tentativas == 0)
					{
						printf("\nVoc� perdeu!");
					  }	
				}
				else if(finalizado == 13)
				{
					printf("\nParab�ns, voc� venceu!");
					break;
				}
		
			}
			
		}break;
		
		case 4: //belgica
		{
			printf("Sua palavra j� foi sorteada:\n\n");
			for(i = 0; i < 7; ++i)
			{
				printf("? ");
				
			}
			
			int resposta[7];
			
			//limpeza de vetor
			for(i = 0; i < 7; ++i)
			{
				resposta[i] = NULL;
			}
			
			while(tentativas > 0)
			{
				printf("\n\nDigite uma letra: ");
				letraUsuario = getch();
				
				for(i = 0; i < chute; ++i)
				{
					if(letraUsuario == letrasUsadas[i])
					{
						printf("\nLetra j� utilizada, digite outra\n");
						letraUsuario = getch();
						
						break;
					}
				}
			
				letrasUsadas[chute] = letraUsuario;
				++chute;
			
				printf("\n\nLetras utilizadas: ");
				for(i = 0; i < chute; ++i)
				{
					printf("%c ", letrasUsadas[i]);
	            }	
				printf("\n\n");
        
        		letraCorreta = 0;
	        
				for(i = 0; i < 7; ++i)
				{
					if(letraUsuario == belgica[i])
					{
						resposta[i] = letraUsuario;
						printf("%c ", resposta[i]);
						letraCorreta++;
						finalizado++;
					
					}
					else if(resposta[i] == belgica[i])
					{
						resposta[i] = belgica[i];
						printf("%c ", resposta[i]);
					}
					else
					{
						printf("?");
					}
			
				
				}
		
				if(letraCorreta == 0)
				{
					tentativas -= 1;
					
					switch(tentativas)
					{
					case 5:
						printf("\n O");
						break;
					case 4:
						printf("\n O\n/");
						break;
					case 3:
						printf("\n O\n/I");
						break;
					case 2:
						printf("\n O\n/I\\");
						break;
					case 1:
						printf("\n O\n/I\\\n/");
						break;
					case 0:
						printf("\n O\n/I\\\n/\\");
						break;
					}
			
					printf("\n %d chances restantes!", tentativas);
					if(tentativas == 0)
					{
						printf("\nVoc� perdeu!");
	  	  	        }	
				}
				else if(finalizado == 7)
				{
					printf("\nParab�ns, voc� venceu!");
					break;
				}
		
			}
			
		}break;
	}
	
	printf("\n\nDeseja jogar novamente (s ou n)?");
	restart = getch();
	
	//condicional para restart do jogo
	if(restart == 's')
	{
		system("cls");
		goto jogo;
	}
	else
	{
		exit(0);
	}
	
	
	return 0;
}