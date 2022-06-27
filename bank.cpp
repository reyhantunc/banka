#include<iostream>
#include"bank.h"
#include<ctime>
#include<cstdlib>
using namespace std;

void AtmSystem::addrecord()
{   
	setname("noName");
	setsurname("noSurname");
	setid(-1);
	setpassword(-1);
	setmoney(-1);
	system("cls");
	cout<<"KAYIT OLUSTURULDU"<<endl;
}
void AtmSystem::printrecord()
{
	system("cls");
	cout<<"Ad Soyad: "<<getname()<<" "<<getsurname()<<endl;
	cout<<"ID: "<<getid()<<endl;
	cout<<"money = "<<money<<endl;
	
}
void AtmSystem::addmoney()
{
	system("cls");
	double tempmoney;
	cout<<"Mevcut bakiyeniz "<<getmoney()<<"TL"<<endl;
	cout<<"Eklemek istediginiz para tutarini giriniz"<<endl;
	cin>>tempmoney;
	tempmoney=tempmoney+getmoney();
	money = tempmoney;
	/*cout<<"tempmoney = "<<tempmoney<<endl;
	setmoney(tempmoney);*/
}

void AtmSystem::takemoney()
{
	system("cls");
	double tempmoney=0;
	cout<<"Mevcut bakiyeniz "<<getmoney()<<"TL"<<endl;
	cout<<"Cekmek istediginiz para tutarini giriniz"<<endl;
	cin>>tempmoney;
	if(getmoney()>=tempmoney)
	{
		tempmoney=getmoney()-tempmoney;
	}
	setmoney(tempmoney);
}

void AtmSystem::showmoney()
{
	system("cls");
	cout<<"Mevcut bakiyeniz: "<<money<<" TL dir"<<endl;
}
AtmSystem::AtmSystem()
{
		name="noname";
		surname="nosurname";
		id=0;
		password=0;
		
		money = 0;
}
AtmSystem::	AtmSystem(string nName, string nSurname, double nId, double nPassword, double nMoney):name(nName),surname(nSurname),id(nId),password(nPassword), money(nMoney){}
double AtmSystem::accountid()
{
	system("cls");
	double account;
	account=100000+getid();
	cout<<"Bu islemi gecici bir sure aktif olarak kullanamamaktasýnýz. Lutfen id numaranýz ile islem yapýnýz"<<endl;
	return account;
}

void AtmSystem::transfermoney()
{
	system("cls");
	cout<<"Bu islemi suan gerceklestiremiyoruz"<<endl;
	
		
}
void AtmSystem::creditcarddebtpay(){
double borc,odeme;
 	system("cls");	
  srand(time(0));

  for(int i = 0; i < 0; i++){
    cout << rand() << endl;
  }
  borc=rand();
  cout<<"Kredi kartý borcunuz  "<<borc<<" tl dir"<<endl<<endl;
  cout<<"Ne kadar kredi kartý borcu ödemek istiyorsunuz."<<endl;	
  cin>>odeme;
  if(odeme<=getmoney())
  {
	borc=getmoney()-odeme;
	setmoney(getmoney()-odeme);
  }
  else
  cout<<"Hesabinizda yeterli bakiye bulunmamaktadir";	
  cout<<borc<<" tl borcunuz kalmýþtýr."<<endl<<endl;	
 		
 }
void AtmSystem::changepassword(){
	system("cls");
	double newpassword;
	cout<<"lütfen yeni þifrenizi giriniz"<<endl;
	cin>>newpassword;
	password=newpassword;
		
}
 

 void AtmSystem::taxpay(){
	double tax,taxpayment,temp,odeme;
  srand(time(0));

  for(int i = 0; i < 0; i++){
    cout << rand() << endl;
  }
  tax=rand()%10;
  cout<<"Vergi borcunuz "<<tax<<" tl dir"<<endl<<endl;
  cout<<"Ne kadar vergi borcu ödemek istiyorsunuz."<<endl;	
  cin>>taxpayment;
  if(taxpayment<=getmoney())
  	{
  tax=getmoney()-taxpayment;
  temp=getmoney()-odeme;
  setmoney(temp);
	}
  else
  {
  	cout<<"Hesabinizda yeterli bakiye bulunmamaktadir";	
  }
  cout<<tax<<" tl vergi borcunuz kalmýþtýr."<<endl<<endl;	
 	
}


	void interface(AtmSystem& arg){
		cout<<" Online islem sistemine hosgeldiniz Asagida isleminizi secebilir ve uygulayabilirsiniz "<<endl;
		cout<<"    (1)    Musteri hizmetlerine mesaj olarak sorun iletme                "<<endl;
		cout<<"    (2)    Guncel bilgilerinizi ogrenme                                        "<<endl;
		cout<<"    (3)    Hesaba para ekleme                                        "<<endl;
		cout<<"    (4)    Hesaptan para cekme                                        "<<endl;
		cout<<"    (5)    Mevcut hesap bakiyesi ogrenme                                        "<<endl;
		cout<<"    (6)    Hesap numarasi olusturulmasi                                        "<<endl;
		cout<<"    (7)    Para transferi islemleri                                        "<<endl;
		cout<<"    (8)    Vergi odeme                                      "<<endl;
		cout<<"    (9)    Kredi karti borcu odeme                                       "<<endl;
		cout<<"    (10)   Sifre degistirme                                    "<<endl;
		cout<<endl;
		cout<<"    (0)	Cikis"<<endl;
		int choices;
		string mesaj;
		cin>>choices;
		cout<<endl;
		
		switch(choices)
	{
		case 0:
			break;
		case 1:
			cin>>mesaj;
			cout<<endl;
			cout<<"Mesajiniz iletilmistir"<<endl;
			break;
		case 2:
			arg.printrecord();
			break;
		case 3:
			arg.addmoney();
			break;		
		case 4:
			arg.takemoney();
			break;
		case 5:
			arg.showmoney();
			break;
		case 6:
			arg.accountid();
			break;
		case 7:
			arg.transfermoney();
			break;
		case 8:
			arg.taxpay();
			break;
		case 9:
			arg.creditcarddebtpay();
			break;
		case 10:
			arg.changepassword();
			break;
		default:
		cout<<"Lutfen 0 den 10 a kadar olan sayilari giriniz "<<endl;
		break;							
	}
			
}
