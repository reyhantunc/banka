#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
#ifndef BANK_H
#define BANK_H

class AtmSystem 
{
	public:
	AtmSystem();//default constructor	//Burak
	AtmSystem(string nName, string nSurname, double nId, double nPassword, double nMoney);//parameter constructor	//Burak

	void addrecord();  //kayýt olusturna islemi //Cemal
	void printrecord();	//olusturulan kaydýn ekrana bastýrýlmasý //Cemal
	void addmoney();	//para ekleme islemi  //Cemal
	void takemoney();	//para cekme islemi  //Cemal
	void showmoney();	//para miktarini gosterme islemi  //Cemal
	double accountid();	//her bireye özgü bir hesap numarasý olusturulmasý  //Cemal
	void transfermoney();	//para transferi yapan islem  //Cemal
	void changepassword();	//sifre degistirme islemi  //Furkan
	void taxpay();//vergi ödeme   //Furkan
	void creditcarddebtpay();//kredi kartý borcu ödeme  //Furkan

	
	void setname(string newName){name = newName;}   // Burak
	void setsurname(string newSurname){surname = newSurname;}  
	void setid(double newId){id = newId;}  
	void setpassword(double newPassword){password = newPassword;}   // Burak
	void setmoney(double moneyV){money = moneyV;}
	
	string getname()const{return name;}; // Burak
	string getsurname()const{return surname;} // Burak
	double getid()const{return id;}; // Burak
	double getpassword()const{return password;} // Burak
	double getmoney()const{return money;} // Burak
	friend void interface(AtmSystem& arg);

	private:
		string name;
		string surname;
		double id;
		double password;
		double money;
};
 void interface(AtmSystem& arg);//Furkan
void menu();//Burak Furkan Cemal
#endif
