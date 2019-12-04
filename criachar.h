#ifndef CRIA_CHAR_H_INCLUDED
#define CRIA_CHAR_H_INCLUDED
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
using namespace std;
#define max 4

int
rd ()
{
  int soma, i;
  soma = 0;
  for (i = 0; i < 10; i++)
    {
      soma += 1 + rand () % 6;
    }


  return soma;
}

class Champ
{
public:

  int atk = rd ();
  int def = rd ();
  int mp = rd ();
  int life = 3 * rd ();
  int act;
 virtual void setclasse (int guild);
  string getclasse ();
   string classe;
private:
   
 };

 
void Champ::setclasse (int guild)
{
  if (guild == 1)
    {
      this->atk += 30;
      this->def += 20;
      this->mp += 20;
      this->life += 20;
      this->classe = "Lutador";
    }
  else if (guild == 2)
    {
      this->atk += 5;
      this->def -= 5;
      this->mp = this->mp * 2;
      this->life=+10;
      this->classe = "Mago";
    }
  else if (guild == 3)
    {
      this->atk -= 5;
      this->def += 15;
      this->mp -= 10;
      this->life = this->life * 2;
      this->classe = "Tank";
    }
  else if (guild == 4)
    {
      this->atk += 5;
      //this->def =;
      this->mp += 25;
      this->life += 10;
      this->classe = "Curandeiro";
    }
  else
    {
      throw 1;
    }
    }

string
Champ::getclasse()
{
    return classe;
}


class Inimigo:public Champ{
    public:
    int getnivel(){
        return lv;
    }
    Inimigo(int nivel):lv(nivel){
        lv=nivel;
       }
       void setclasse (int guild) override{
  if (guild == 1)
    {
      this->atk += 10+(lv/2);
      this->def += 10+(lv/2);
      this->mp += 10+(lv/2);
      this->life += 10+(lv/2);
      this->classe = "Lutador";
    }
  else if (guild == 2)
    {
      this->atk -= 15-(lv/2);
      this->def -= 5-(lv/2);
      this->mp = this->mp * 2+(lv/2);
      //this->life=+10;
      this->classe = "Mago";
    }
  else if (guild == 3)
    {
      this->atk -= 10-(lv/2);
      this->def += 10+(lv/2);
      this->mp -= 15-(lv/2);
      this->life = this->life * 2+(lv/2);
      this->classe = "Tank";
    }
  else if (guild == 4)
    {
      this->atk -= 5-(lv/2);
      //this->def =;
      this->mp += 5+(lv/2);
      this->life += 10+(lv/2);
      this->classe = "Curandeiro";
    }
  else
    {
      throw 1;
    }
    }
       private:
       int lv;
      };

#endif
