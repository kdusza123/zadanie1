#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>

using namespace std;

class Enemy
{
public:
	   int thievery;   //kradziez zlota
	   int life;       //jego zycie
	   int power;      // jego sila zabierajaca zycie bohaterowi
	   void enemy_life()
   	   {
   	    	cout<<"wrog"<<endl;
		}
};
class Alien : public Enemy
{
public:
	int thievery = 10;
	int life = 300;
	int power = 90;
};

class Gnome : public Enemy
{
public:
	int thievery = 230;
	int life = 70;
	int power = 60;
};

class Monster : public Enemy
{
public:
		int thievery = 60;
		int life = 220;
		int power = 130;
};
class Weapon
{
public:
	int weapon_points=0;
	int cost=0;
	void show_parameter()
	{
	cout<<"Punkty dodatnie broni: "<<weapon_points<<endl;
	cout<<"Koszt broni: "<<cost<<endl;
	}
};

class Arrow : public Weapon
{
public:
	int weapon_points = 50;
	int cost = 20;
	void show_parameter()
	 {
	 	cout<<"Punkty dodatnie broni: "<<weapon_points<<endl;
	 	cout<<"Koszt broni: "<<cost<<endl;
	 }
};

class Sword : public Weapon
{
public:
	int weapon_points = 150;
	int cost=50;
};
class Skin
{
public:
	virtual void dress() = 0;
};

class Armour : public Skin
{
public:
	int type = 100;
	int price = 30;
	void dress()
	{
		cout<<"Punkty dodatnie ubioru: "<<type<<endl;
		cout<<"Cena ubioru: "<<price<<endl;
	}
};

class Tatters : public Skin
{
public:
	int price=0;
	int type=20;
	void dress()
	{
		cout<<"Punkty dodatnie ubioru: "<<type<<endl;
		cout<<"Cena ubioru: "<<price<<endl;
	}
};

class Character
{
public:
	   int hero_bonus;
	void defence();
	void attack();
	void if_alive()
 	{
	 }
};
class Fairy: public Character
{
public:
	int hero_bonus = 80;
	void defence()
	{
		cout << "*POOF*" << endl; //znikanie
	}
	void attack()
	{
		cout << "'Magiczny pyl'" <<endl;
	}
	void decide()
	{
		cout<<"Atak[1] czy Obrona[2]"<<endl;
		int a;
		cin>>a;
		if(a==1)
		
		{
			attack();
		}
		else
		{
			defence();
		}
	}
	void if_alive();
};
class Ninja : public Character
{
public:
	int hero_bonus = 130;
	void defence()
	{
		cout << "Uciekanie" << endl;
	}
	void attack()
	{	
		cout << "Walka" << endl;
	}
	void if_alive();    
};
class Statistics      
{                     //mozna przeciazyc operatory
public:
	void fairy()
	{
		Fairy *a = new Fairy();
		cout<<a->hero_bonus<<endl;
	}
	void ninja()
	{
		Ninja *b = new Ninja();
		cout<<b->hero_bonus<<endl;	
	}
	int Health_Points()
	{
		static int hero_pt;
		static int money;
		cout<<"Wybierz bron: "<<endl;
		cout<<"1.Strzala  2.Miecz"<<endl;
		int d;
		cin>>d;
		if(d==1)
		{
			Arrow *one = new Arrow();
			one->show_parameter();
			hero_pt += one->weapon_points;
			money += one->cost;
		}
		else if(d==1)
		{
			Sword *two = new Sword();
			two->show_parameter();
			hero_pt += two->weapon_points;
			money += two->cost;
		}
		else
		{
			string wyjatek= "Nie ma takiej opcji";
			throw wyjatek;
		}
		cout<<"Wybierz kostium: "<<endl;
		cout<<"1.Tatters 2.Armour"<<endl;
		int e;
		cin>>e;
		
		if(e==1)
		{
			Tatters *first = new Tatters();
			first->dress();
			hero_pt += first->type;
			money += first->price;
		}
		else if(e==2)
		{
			Armour *second = new Armour();
			second->dress();
			hero_pt += second->type;
			money += second->price;
		}
		else
		{
			string wyjatek= "Nie ma takiej opcji";
			throw wyjatek;
		}
		
	
	
	 	cout<< hero_pt<<endl; // weapon points + outfit pt 
	    return money;
	}
void wyjatek()
{
	try
	{
		Health_Points();
	}
	catch(string w)
	{
		cout<<"Wyjatek: "<<w<<endl;
	}
}
};

class Location
{
public:
	   void step()
	   {
	   	 	 Monster *d= new Monster();
			 Gnome *e= new Gnome();
		 	 Alien *f= new Alien();
		 	int a;
	   		cin>>a;
	   		if(a%5==0 || a%7==0)
	   		{
	   		 cout<<"droga wolna"<<endl;	
   			}
   			else if(a%2==0)
   			{
   			 cout<<"Przeciwnik na twojej drodze. Wpisz 1, 2, 3"<<endl;
		  	
			 int b;
			 cin>>b;
			 switch(b)
			 {
			 	case 1:
			 		{
			 			cout<<"STATYSTYKI PRZECIWNIKA: "<<endl;
			 			cout<<"Kradziez pieniedzy: "<<d->thievery<<endl<<"zycie potwora: "<<d->life<<endl<<"Sila umiejetnosci: "<<d->power<<endl;
			 			break;	
					}		 	
					case 2:
			 		{
			 			cout<<"STATYSTYKI PRZECIWNIKA: "<<endl;
			 			cout<<"Kradziez pieniedzy: "<<e->thievery<<endl<<"zycie potwora: "<<e->life<<endl<<"Sila umiejetnosci: "<<e->power<<endl;
			 			break;
					 }
			 	case 3:
			 		{
			 			cout<<"STATYSTYKI PRZECIWNIKA: "<<endl;
			 			cout<<"Kradziez pieniedzy: "<<f->thievery<<endl<<"zycie potwora: "<<f->life<<endl<<"Sila umiejetnosci: "<<f->power<<endl;
			 		 	break;
					 }
			 }
			 
   			}
   			else if(a%3==0)
   			{
   				cout<<"znajdujesz skarb i zdobywasz pieniadze"<<endl;
   			}
  		}	
};

class Manage
{
public:
  void cli()
	   {
	   	cout<<"Witamy w grze"<<endl<<"Wybierz zawodnika"<<endl;
	    cout<<"1. Wrozka Beata  2.Mag Andrzej  3.Muszkieter Marek  4.Ninja Nadia  5.Strzelec Szymon"<<endl;
	    Fairy*a = new Fairy();
	    Character*c = new Character();
    	Location*g = new Location();
   	 	Statistics *s = new Statistics();
    	int b;
	    cin>>b;
	    switch(b)
	    {
	    	case 1: 
	    	{
	    		cout<<"Wybierz krok"<<endl;
		 		g->step();
				//twoje statystyki
				cout<<"STATYSTYKI BOHATERA: "<<endl;
		 		cout<<"Moc bohatera: "<<endl;
				s->fairy();
				s->wyjatek();
				a->decide();
				break;
			}
 			case 2: 
 			{
				c->if_alive(); // ?
				break;
			}
			case 3:
			{
				cout<<"Muszkieter Marek jest obecnie niedostępny"<<endl;
				cout<<"wybierz ponownie"<<endl;
				break;
			}
			case 4:
			{
				cout<<"Postać dostępna z dodatkiem"<<endl;
				break;
			}
			default:
			{
				cout<<"wystąpił nieoczekiwany błąd"<<endl;
				break;
			}
		}
	}	
};

int main()
{
//wywolanie interfejsu
Manage*x = new Manage();
x->cli();

system("pause");
return 0;
}

