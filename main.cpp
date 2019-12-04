/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "cria_char.h"
#include "luta.h"
#include <iostream>
#include <string>
using namespace std;
#define max 4


int main ()
{
  srand (time (NULL));
  string continua;
  int i,score=0;
  bool erro = false,vitoria;
  do{
  Champ *player = new Champ ();                     // inicio criaçaõ do jogador
  cout << "seus status iniciais sao:" << endl;
  cout << "ataque" << player->atk << endl;
  cout << "defesa" << player->def << endl;
  cout << "mana" << player->mp << endl;
  cout << "vida" << player->life << endl;
  cout << "Escolha a classe desejada...(leia o readme para especificacoes) "
    << endl;
  cout << "1=lutador" << endl << "2=mago" << endl << "3=tank" << endl <<
    "4=curandeiro" << endl;
  cin >> i;
  do{
  try
  {
     player->setclasse (i);
	 erro = false;
      }
  
  catch (int falha)
  { if (falha==1){
    cout << "Entrada invalida!Digite novamente..." <<endl;
    cin >> i;
        }
        erro = true;
  }
        
    }while (erro);         
    
  cout << "Voce e um " << player->getclasse() << " e estes sao seus status:" << endl;
  cout << "seus pontos de ataque " << player->atk << endl;
  cout << "seus pontos de defesa " << player->def << endl;
  cout << "seus pontos de mana " << player->mp << endl;
  cout << "seus pontos de vida " << player->life << endl;  // fim criaçaõ do jogador
    
    do{
  Inimigo *inimigo = new Inimigo(score);         //criaçaõ do inimigo
  i= 1+ rand () % 4;
   inimigo->setclasse (i);
  cout << "Voce lutara contra um " << inimigo->getclasse()<< endl;
  
 vitoria = luta (player,inimigo);
 if (vitoria){
     score ++;
     cout << "continue??(y se sim)... Aperte qualquer outro botao para finalizar: "; 
     cin>>continua;
     }
     else
       { 
         cout << score<<endl;
         score =0 ;
      cout << " ...continue??(y se sim)... Aperte qualquer outro botao para finalizar: "; 
       cin>>continua;
        }
  delete inimigo;
    }while((continua=="y"||continua=="Y")&&score!=0);
    if(score!=0){
    cout <<"seu score foi "<< score<<endl;}
    delete player;
  }while (continua=="y"||continua=="Y");
  
 
  return 0;
}
