#include<iostream>
#include<ctime>
#include<cstdlib>
#include"bank.h"
using namespace std;

int musteriSirasiniBul(AtmSystem musteriler[], int toplamMusteri, double istenenId){

	for (int i = 0; i <toplamMusteri; ++i)
	{
		if ((int)musteriler[i].getid() == (int)istenenId)//doublelarin kiyaslanmasi esit ligi bulmak adina sorun yaratir
			return i;
	}

	return -1;
}

int main()
{
	string nName,nSurName;
	double nId, nPassword, nMoney;
	AtmSystem musteriler[100];
	int ifsecim = 5, toplamMusteri = 0, islemdekiMusteriSirasi = 0;	

	while(ifsecim!=0){
		cout<<"Bankamiza Hosgeldiniz"<<endl;
		cout<<"Lutfen yapmak istediginiz islemi seciniz"<<endl;
		cout<<"(0)	Cikis"<<endl;
		cout<<"(1)	Islem yapma "<<endl;
		cout<<"(2)	Kayit Olusturma"<<endl;

		cin>>ifsecim;

		if(ifsecim==1)
		{
			double idV,passV;
			char secim;

			if (toplamMusteri == 0)
			{
				cout<<"Bankanizda hic musteri kayidi bulunmamaktadir!"<<endl<<"exit : no recorded client"<<endl;
				exit(1);
			}
			else{
				cout<<"Lutfen islem yapmak istediginiz musterinin Id numarasini giriniz"<<endl<<"ID: ";
				cin>>idV;
				islemdekiMusteriSirasi = musteriSirasiniBul(musteriler, toplamMusteri, idV);
			}

			if (islemdekiMusteriSirasi == -1){
				cout<<"Boyle bir musteri id'si bulunmamaktadir!"<<endl<<"exit : no such that client id"<<endl;
				exit(1);
			}

			do{
			interface(musteriler[islemdekiMusteriSirasi]);
				cout << "Baska bir islem yapmak istiyor musunuz (y/n)? "; 
	        	cin >> secim;              
	        	} 
	     		while(secim=='y'||secim=='Y');
		}

		else if (ifsecim == 2){

			cout<<"Enter the name: ";
			cin>>nName;
			cout<<"Enter the surname: ";
			cin>>nSurName;
			cout<<"Enter the Id: ";
			cin>>nId;
			cout<<"Enter the password: ";
			cin>>nPassword;
			cout<<"Enter the initial money: ";//baslangic parasi
			cin>>nMoney;

			musteriler[toplamMusteri] = AtmSystem(nName, nSurName, nId, nPassword, nMoney);
		
			toplamMusteri++;
		}
	}	
}
