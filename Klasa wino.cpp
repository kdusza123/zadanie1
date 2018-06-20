#include <iostream>
#include <string>
using namespace std;

class wino
{
	private:
		string nazwa;
		string rodzaj;
		
	public:
		double vol;
		double cena;
		string x;
		string z;
	
			
	wino(double cena_a,double vol_a)
		{
		    cena_a = cena;
			vol_a = vol;
		}
	
		void set_nazwa(string x)
			{
		 	 	 nazwa = x;
			}
		string get_nazwa()
			{
				return nazwa;
			}
		
		void set_rodzaj(string z)
			{
				rodzaj = z;
			}
		string get_rodzaj()
			{
				return rodzaj;
			}
			
	void wpisz()
	{
		
		cout<< "Wpisz nazwe wina: "<<endl;
		cin>>x;
		set_nazwa(x);
		
		if(x=="amarena")
		{
			z="czerwone";
			vol = 13.6;
			cena = 6.59;
		}
		else if(x=="carlo")
		{
			z="rozowe";
			vol= 10;
			cena=18.99;
		}
			else if(x=="fresco")   
		{
			z="rozowe";
			vol = 10;
			cena = 12.49;
		}
			else if(x=="bulgarius")   
		{
			cout<<"prestige prestige"<<endl;
			z="biale";
			vol = 11;
			cena=8,90;
		}
			else if(x=="porto")
		{
			z="czerwone";
			vol = 20;
			cena=86.90;
		}
		else
		{
			z="najtansze w kartonie";
			vol = 9;
			cena = 5.78;
		}
			
			cout<<z<<endl;
			cout<<vol<<" %"<<endl;
			cout<<cena<<" zl"<<endl;
	}
		 
	void stezenie()
	{
		double stezenie;
		double m;
		string g;
		cout<<"Sprawdz zawartosc alkoholu we krwi "<<endl;
		cout<<"(po wypiciu polowy butelki(majacej 750ml) wybranego napoju)."<<endl;
		//przyjmujemy ze 100 ml alkoholu wazy 100g
		
		cout<<"podaj wage: "<<endl;
		cin>>m;
		cout<<"podaj plec [k lub m]"<<endl;
		cin>>g;
		if(g=="m")
			{
			 	  stezenie = (375 * vol * 0.01) / (0.7 * m);
			 	  cout<<stezenie<<"‰"<<endl;
			}
		else if(g=="k")
			{
   			 stezenie = (375 * vol * 0.01) / (0.6 * m);
			 	  cout<<stezenie<<" promili"<<endl; 	
			}
		else
			{
			 	cout<<" ? "<<endl;	
			}
	
	}
	void koszyk()
	{
		int ilosc;
 	 	cout<<"Wybierz wino: "<<endl;
 	 	wpisz();
 	 	cout<<"Wybierz ilosc: "<<endl;
 	 	cin>>ilosc;
 	 	cout<<"Koszt zakupow: "<<ilosc* cena<<endl;
 	  	
	}
wino(string x,string z)
{
	koszyk();
	stezenie();
}

};

int main()
{
	string x;
	string z;
	
 	wino winko = wino(x,z);
 	
	
	system("pause");
	return 0;
}
