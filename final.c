/******************************************************************************

desenvolver um projeto que detecta se uma sequência de DNA pertence a um humano ou a um símio.
AGCCAGCCGCCAACCG 4X4
ACAACTATCTATCGCCCGCTCGGAA  5X5
AGTCTGCGATAGTCGGATGTAAAAGTCCTTAGCTCACCCGTAGTATCAT 7X7
AGTCTGCAGTGATAGTCGATGGATGTACCGAAAGGCCATCTTAGCTCGTCACCCGTATCAGTATCATCGTAGGCCAGCTCTCGTCTTTACCGGAAATAGT 10X10

//36
//seq para teste coluna: agtcgtAcgttgAccggtatccgtatcgtcatggtc
//seq para teste linha:  ccccctacgtcgtttcgtcgatcgtcgttcgtgcaa
//seq para teste dp: acgtcgtAcgtcgtAtcgtcgatcgtcgatcgtgca
//seq para teste humano: ctgctgcgacgtcagagagaatcatccactcgtgcg hum
//seq para teste dp: cagctgcgacgtcagagagaataatccactcgtgcg simio
//seq para teste ds: ctgctgcgacgtcagggagagtcatccactcgtgcg simio

//25
//seq para teste linha: aaaactgctgcgtactacgtcgtac
//seq para teste coluna: acgtatgacgagttacgatgagcgg
//seq para teste dp: atcattgtcggactcctgatgactc
//seq para teste ds: atcatgggcgtactcacgatcatgc
//seq para teste humano: ctgctgcgacgtcagagagaatcat



*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <math.h> 
#include <ctype.h>

int tTabela(){
    int tam, erro;
    int certo = 1;
    printf("Olá, digite a quantidade de caracteres que contem o seu DNA\n");
    scanf("%i", &tam);
        do{
            if(tam != 0 && tam >=16){
                for(int r = 0; r < tam; r++)
                {
                    if(r * r == tam)
                    {
                        certo = 0;
                    }
                }
            }
        }
    while (certo == 1 && tam > 0);
    return tam;
}


    
void guarda (int tam, char seq[tam]) // seq[36] cada letra em um quadrado
    {
      if (tam > 0)
        {
          printf("Esse algoritmo só consegue detectar diferenças entre A,G,T,C\n");
          printf ("\nPor favor insira a sequencia de DNA para verificacao!\n");
          scanf ("%s", seq);
        }
    }
    
int procuraRaiz (int tam)//pra construir a matriz necessitamos da raiz do numero
    {
      int raiz = sqrt (tam);//raiz de tam
      return raiz;
    }
    
void verificaLetras (int tam, char seq[tam]){ // verifica se a quantidade de letras e se as letras estao corretas                              
  int tTabela, erro;
  if (tam > 0)
    {
      do
	{
	  tTabela = strlen (seq);
	  erro = 0; // se o erro for 1 ele volta a função, se o erro for 0 ele passa dessa funcao
    	  if (tTabela != tam)
        	    {
        	      printf
        		("\nA sequencia ideal para ser verificada deve conter apenas %i letras",
        		 tam);
        	      printf ("\nPor favor digite ela novamente!\n\n");
        	      scanf ("%s", seq);
        	    }
    	  for (int i = 0; i < tam && tTabela == tam; i++)
        	    {
        	      if (seq[i] != 'a' && seq[i] != 't' && seq[i] != 'c'
        		  && seq[i] != 'g' && seq[i] != 'A' && seq[i] != 'T'
        		  && seq[i] != 'C' && seq[i] != 'G')
                		{
                		  erro = erro + 1;
                		  printf
                		    ("\nHC! um erro na %i letra, (%c), ela nao faz parte do conjunto de DNA!\n",
                		     i + 1, seq[i]);
                		}
        	    }
    	  if (erro > 0)
        	    {
            	      printf("\nA sequencia ideal para ser verificada deve conter apenas as letras A, T, C e G!");
            	      printf ("\nPor favor digite ela novamente!\n\n");
            	      scanf ("%s", seq);
        	    }
	}
      while (tTabela > tam || erro > 0); //enquanto estiver errado vai voltar ao inicio dessa funcao
    }
}    

void escreve(int tam){
    printf("esse eh o tam:%i\n", tam);
}// verificar se o tam está correto

void seqEmMaisculo (int tam, int raiz, char seq[tam], char dna[][raiz])//seq em maiusclo 
{
    // transforma minusculos em maiusculos
  if (tam > 0)
        {
          printf ("\n\nA sequencia escrita foi:\n");//mostra a sequencia
          int d = 0;
              for (int i = 0; i < raiz; i++)
            	{
            	  for (int j = 0; j < raiz; j++, d++)
                	    {
                	      dna[i][j] = seq[d];
                	      if (dna[i][j] == 'a' || dna[i][j] == 't' || dna[i][j] == 'c'
                		  || dna[i][j] == 'g')
                        		{
                        		  dna[i][j] = toupper (dna[i][j]);
                        		}
                	      printf ("%c\t", dna[i][j]);
                	    }
            	  printf ("\n");
            	}
        }
}				//mostra a seq

int analiseLinhas (int raiz, char dna[][raiz])
{
  int simios = 0;
  for (int i = 0; i < raiz && raiz > 0 && simios < 3; i++)
        {
          for (int j = 0; j < raiz && simios < 3; j++)
        	{
        	  if (dna[i][j] == dna[i][j + 1])
        	    {
        	      simios = simios + 1;
        	    }
        	  else if (j + 1 != raiz && simios < 3)
        	    {
        	      simios = 0;
        	    }
        	}
        }
  return simios;
}				//analisa as linhas

int analiseCol (int raiz, char dna[][raiz], int simios)
    {
      for (int i = 0; i < raiz && raiz > 0; i++)
            {
              for (int j = 0; j < raiz && simios < 3; j++)
            	{
            	  if (dna[j][i] == dna[j + 1][i])
            	    {
            	      simios = simios + 1;
            	    }
            	  else if (j + 1 != raiz && simios < 3)
            	    {
            	      simios = 0;
            	    }
            	}
            }
      return simios;
    }				//analisa as colunas

int analiseDP (int raiz, char dna[][raiz], int simios)
{
  int diagonais = ((raiz - 4) * 2) + 1;	//((raiz-4)*2)+1 //  5
  int lin, col, cont, x;
  lin = raiz - 4; // 2
  col = x = 0;
      if (simios < 3 && raiz > 0) //transformar em 0 se antes nao conseguiu comprovar simio
        {
          simios = 0;
          do
        	{
        	  cont = 0;
        	  for (int i = lin, j = col; (i + 1) != raiz && (j + 1) != raiz;i++, j++)// i = raiz - 4 que é o quad da matriz j = 0+1
        	    {
        	         if (dna[i][j] == dna[i + 1][j + 1]){
        		        cont = cont + 1;
        	         }
        	            else if (i + 1 != raiz && j + 1 != raiz && cont < 3){ //so entra se o cont for menor q 3 condicional muito especifica
        		        cont = 0;
        	            }
        	    }
        	  
        	  if (simios < cont)
        	    {
        	      simios = cont;
        	    }
            	  if (lin > col)
            	    {
            	      lin--;
            	    }
            	  else
            	    {
            	      col++;
            	    }
        	  x = x + 1;
        	}
      while (x < diagonais);
    }
  return simios;
}				//analisa as diagonais maiores ou iguais a 4 no mesmo sentido da principal

int analiseDS (int raiz, char dna[][raiz], int simios)
{
  int diagonais = ((raiz - 4) * 2) + 1;	//((raiz-4)*2)+1 //5
  int cont, lin, col;
  int x = 0;
  lin = cont = 0;
  col = 3;
  if (simios < 3 && raiz > 0)
    {
      simios = 0;
      do
	{
	  cont = 0;
	  for (int i = lin, j = col; (i + 1) != raiz && (j - 1) != -1;i++, j--)
    	    {
        	      if (dna[i][j] == dna[i + 1][j - 1])
        		{
        		  cont = cont + 1;
        		}
        	      else if (i + 1 != raiz && j - 1 != 0 && cont < 3)
        		{
        		  cont = 0;
        		}
    	    }
    	  if (simios < cont)
    	    {
    	      simios = cont;
    	    }
    	  if (col + 1 != raiz)
    	    {
    	      col++;
    	    }
    	  else
    	    {
    	      lin++;
    	    }
    	  x = x + 1;
	}
      while (x < diagonais);
    }
  return simios;
}				//analisa as diagonais maiores ou iguais a 4 no mesmo sentido da secundC!ria

void
ehSIMIO (int simios, int tam)
{
  if (tam > 0)
    {
      if (simios >= 3)
	{
	  printf ("\nessa sequencia genetica eh de um simio!\n\n");
	}
      else
	{
	  printf ("\nEssa sequencia genetica eh de um humano!\n\n");
	}
    }
}				//verifica se é simio ou nao




int main(void)
{
    int tam, raiz, simio, escrever, testes = 0;
      do
        {
          tam = tTabela ();
          raiz = procuraRaiz(tam);
          char seq[tam], dna[raiz][raiz];
          guarda (tam, seq);
          verificaLetras (tam, seq);
          seqEmMaisculo (tam, raiz, seq, dna);
          simio = analiseLinhas(raiz, dna);
          simio = analiseCol(raiz, dna, simio);
          simio = analiseDP(raiz, dna, simio);
          simio = analiseDS (raiz, dna, simio);
          ehSIMIO(simio,tam);
          
          
          
          escreve(tam);
          
        }
  while (tam != 0);

  printf ("voce apertou 0 então acabamos por aqui!");

  return 0;
}





