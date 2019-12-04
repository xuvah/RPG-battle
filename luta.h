#ifndef LUTA_H_INCLUDED
#define LUTA_H_INCLUDED
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
using namespace std;
#define max 4
int
ult (Champ *p)
{
    if(p->getclasse()=="Lutador"){
         p->mp-=20;
        if (p->mp<=0){
        cout<< "mana insuficiente!!!!!";
        p->mp+=20;
        return 0;
        }else{
           
            p->def+=1;
            p->atk+=10;
             return rd();
        }
       
      }
      
      
      else if(p->getclasse()=="Mago"){
           p->mp-=25;
          if (p->mp<=0){
        cout<< "mana insuficiente!!!!!";
         p->mp+=25;
        return 0;
        }else{
         
            return 2* rd () + p->atk + p->def/2;
       }
      }
      
      
      else if(p->getclasse()=="Tank"){
           p->mp-=15;
          if (p->mp<=0){
        cout<< "mana insuficiente!!!!!";
         p->mp+=15;
        return 0;
        }else{
         
          p->def+=5;
         return  (rd () + p->atk)/ 2;
       }
      }
      
      
      else {
           p->mp-=15;
          if (p->mp<=0){
        cout<< "mana insuficiente!!!!!";
         p->mp+=15;
        return 0;
        }else{
         
          p->life+= (rd () + p->atk)/ 2;
          return  p->life/ 4;
        }
        
    }
 
}



void
atk (Champ * p1, Inimigo * p2)
{
    int dano1,dano2,escudo1,escudo2;
    switch(p1->act){
        case 1 :
         dano1 = rd () + p1->atk;
         escudo1 = rd () + p1->def;
        break;
         case 2 :
          dano1 = 0;
          escudo1 = rd () + (p1->def)*2;
          cout<<"Voce defendeu e por isso não causara dano "<<endl;
        break;
         case 3 :
          dano1 = ult(p1);
          escudo1 = rd () + (p1->def)/2;
          cout<<"Voce usou a ira do "<<p1->getclasse()<<"!!"<<endl;
        break;
    }
     
  switch(p2->act){
      case 1:
      dano2 = rd () + p2->atk;
      escudo2 = rd () + p2->def;
      cout<<"Voce causou "<<dano1<<" de dano...Defesa executada "<<escudo2<<endl;
      cout<<"Voce recebeu "<<dano2<<" de dano...Defesa executada "<<escudo1<<endl;
      break;
      case 2:
      dano2 = 0;
      escudo2 = rd () + (p2->def)*2;
      cout<<"Voce causou "<<dano1<<" de dano...Defesa executada "<<escudo2<<endl;
      cout<<"O oponente defendeu seu ataque e por isso não causara dano "<<endl;
      break;
      case 3:
      dano2 = ult(p2);
      escudo2 = rd () + (p2->def)/2;
      cout<<"Voce causou "<<dano1<<" de dano...Defesa executada "<<escudo2<<endl;
      cout<<"Seu oponente usou a ira do "<<p2->getclasse()<<" ...Boa sorte!!"<<endl;
      break;
  }
    
 
  if (escudo2 >= dano1)
    {
      cout<< " Voce nao causou dano !! "<<endl;
    }
  else{
    p2->life += escudo2 - dano1;
    cout<< " Voce causou  " <<  dano1 - escudo2 << " de dano... Vida restante do oponente " << p2->life <<endl;
      
  }
    
    if (escudo1 >= dano2)
    {
      cout<< " Voce nao sofreu dano !! "<< endl;
    }
  else
   { p1->life += escudo1 - dano2;
     cout<< " Voce recebeu " << dano2 - escudo1 << " de dano... Vida restante " << p1->life<<endl;
   }
       
}

void imprime_status(Champ*p){
    cout << " pontos de ataque " << p->atk << endl;
    cout << " pontos de defesa " << p->def << endl;
    cout << " pontos de mana " << p->mp << endl;
    cout << " pontos de vida " << p->life << endl;
    
}





bool
luta (Champ * p1, Inimigo * p2)
{
  int act1,act2;
  bool erro = false;
  string stat;
cout << "********************INICIO DA BATALHA************************" << endl;

  while (p1->life > 0 && p2->life > 0)
      {
	cout << "Qual sera sua jogada?" << endl;
	cout << "1 para atacar " << endl;
	cout << "2 para defender " << endl;
	cout << "3 para especial " << endl;
	cin >> p1->act;
	if(p2->mp==0){
	    p2->act= 1+rand () %2;
	}else{
    p2->act= 1+rand () %3;}
	
	do
	  {
	    if (p1->act<1||p1->act>3)
	      {
	          erro = true;
	          cout << "entrada invalida digite novamente"<<endl;
	          cin>>p1->act;
	          
	      }
	    else 
	      {
		   atk(p1,p2);
			erro = false;
	      }
	    
	     
	}while (erro);
	if (p2->life <= 0)
	  {
	   cout << "Voce ganhou esta luta!!! score +1..."<<endl;
	     return true;
	  }
	 
	if (p1->life <= 0)
	  {
	    cout << "Voce perdeu ..."<<endl;
	    return false;
	  }
	  cout <<"Deseja ver seus status?(y se sim)... Aperte qualquer outro botao para continuar: ";
	  cin>>stat;
	  if(stat=="y"||stat=="Y"){
	      imprime_status(p1);
	  }
	  	  cout <<"Deseja status do oponente?(y se sim)... Aperte qualquer outro botao para continuar: ";
	  cin>>stat;
	  if(stat=="y"||stat=="Y"){
	      imprime_status(p2);
	  } 
	  p1-> mp +=5;
	  p2-> mp +=5;
      }
    }



#endif
