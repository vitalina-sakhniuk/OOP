#define _CRT_SECURE_NO_WARNINGS

#include "Classes.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <msclr\marshal_cppstd.h>


using namespace std;
using namespace msclr::interop;

class Post;
class Parcel;
class City;
class Client;
class Vidpravnik;
class Otrymuvach;


Post::Post() {
}
Post::~Post() {
}
Parcel::Parcel() {

}
Parcel::~Parcel() {
}
City::City(){
}
City::~City(){
}
Client::Client(){

}
Client::~Client(){

}
Otrymuvach::~Otrymuvach(){
}
Vidpravnik::~Vidpravnik(){

}

void Post::enterAddressANDcityANDnumberviddil(City *city,  std::string misto, std::string oblact6, std::string kod, std::string address, std::string numberviddil) {
	file.open("Post.txt",ios_base::app);

	if (file.is_open()) {
		
			cout << "������ ���������� ��� ����:" << endl;
			city->enterinfo(misto,oblact6,kod);
			file << misto << endl;

			cout << "������ ������:" << endl;
			cin >> address;
			file << address << endl;

			cout << "������ ����� ��������:" << endl;
			cin >> numberviddil;
			file << numberviddil << endl;
			cin.get();
		
	}

	file.close();
}
void City::enterinfo(std::string city, std::string oblact6, std::string kod){
	ofstream file("Cities.txt", ios_base::app);

	if (file.is_open()) {
		cout << "������ ����:" << endl;
		cin >> city;
		file << city << endl;

		cout << "������ �������:" << endl;
		cin >> oblast6;
		file << oblast6 << endl;

		cout << "������ ��� ����:" << endl;
		cin >> kod;
		file << kod << endl;
		cin.get();
	}

	file.close();
}

void Client::infoAboutCLIENT(std::string role,std::string name, std::string surname, std::string age, std::string phone){
	ofstream file("Clients.txt", ios_base::app);
	if (file.is_open()){

		cout << "���� ����:" << endl;
		cin >> role;
		file << role << endl;

		cout << "������ ��'�:" << endl;
		cin >> name;
		file << name << endl;

		cout << "������ �������:" << endl;
		cin >> surname;
		file << surname << endl;

		cout << "��� ��:" << endl;
		cin >> age;
		file << age << endl;

		cout << "����� ��������:" << endl;
		cin >> phone;
		file << phone << endl;
	}
	file.close();


}
void Parcel::enterDATAaboutParcel(std::string type, std::string weight, std::string surnamev, std::string otrymuvach,int seria) {
	file.open("Parcel.txt", ios_base::app);

	if (file.is_open()) {
		cout << "������ ��� �����������: ";
		cin >> type;
		file << type << endl;

		cout << "������ ���� �����������: ";
		cin >> weight;
		file << weight << endl;

	
		cout << "������� ����������: ";
		cout << surnamev << endl;
		file << surnamev << endl;

		cout << "������ ������� ����������: ";
		cin >> otrymuvach;
		file << otrymuvach << endl;

		file << seria << endl;
	}

	file.close();
}

Parcel *Parcel::getdelivery(Parcel *parcel, int seriaforotr){
		ifstream fin;
	fin.open("Parcel.txt");


	if (fin.is_open()) {
		while (fin >> type)
		{
			fin >> weight;
			fin >> vidpravnik;
			fin >> otrymuvach;
			fin >> seria;
			if (seriaforotr == seria) break;
		}
	}
	fin.close();
		return parcel;
}
Parcel *Parcel::getinfo(Parcel *parcel, std::string person){
	ifstream fin("Parcel.txt");
	if (fin.is_open())
	{
		while (fin >> type)
		{

			fin >> parcel->weight;
			fin >> vidpravnik;
			fin >> otrymuvach;
			fin >> parcel->seria;

			if (person == vidpravnik) break;

			}
		}
	fin.close();
	return parcel;
	}
