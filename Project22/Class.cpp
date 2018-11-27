#define _CRT_SECURE_NO_WARNINGS

#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

class Post;
class Parcel;
class City;
class Client;
class Vidpravnik;
class Otrymuvach;
class Clients;
class MoneyParce;
class DocumentsParcel;
class VantazhneParcel;
class ReloadedOperators;
class LEFT;

int Post::endOFwork = 20;
int Post::startOFwork = 10;

ReloadedOperators ReloadedOperators::operator+(int f){
	ReloadedOperators *reloader=new ReloadedOperators;
	reloader->x = reloader->x + f;
	reloader->y = reloader->y + f;

	cout << reloader->x << reloader->y;

	return *reloader;
}

ReloadedOperators ReloadedOperators::operator-(int f){
	ReloadedOperators *reloader = new ReloadedOperators;
	reloader->x = reloader->x - f;
	reloader->y = reloader->y - f;

	cout << reloader->x << reloader->y;

	return *reloader;
}

ReloadedOperators ReloadedOperators::operator*(int f){
	ReloadedOperators *reloader = new ReloadedOperators;
	reloader->x = reloader->x * f;
	reloader->y = reloader->y * f;

	cout << reloader->x << reloader->y;

	return *reloader;
}

ReloadedOperators ReloadedOperators::operator=(int f){
	ReloadedOperators *reloader = new ReloadedOperators;
	reloader->x =  f;
	reloader->y =  f;

	cout << reloader->x << reloader->y;

	return *reloader;
}

ReloadedOperators ReloadedOperators::operator-=(int f){
	ReloadedOperators *reloader = new ReloadedOperators;
	reloader->x -= f;
	reloader->y -= f;

	cout << reloader->x << reloader->y;

	return *reloader;
}

ReloadedOperators& ReloadedOperators::operator[](int n){
	x = n;
	y = n;
	return *this;
}

Parcel& Parcel::operator++(){
	fromgetdelivered = true;
	return *this;
}

ReloadedOperators ReloadedOperators::operator++(int){
	++(*this);
	return *this;
}

Parcel& Parcel::operator--(){
	fromgetdelivered = false;
	return *this;
}

Employee& Employee::operator+=(string currency){

	this->salary += currency;
	return *this;

}

Otrymuvach& Otrymuvach::operator*=( int n){
	this->price *= n;
	return *this;
}

//class Post methods 
Post::Post() {
}

Post::~Post() {
	}

void Post::enterAddressANDcityANDnumberviddil(int j, City *city) {
	file.open("Post.txt");

	if (file.is_open()) {
		for (int i = 0; i < j; i++) {
			cout << "Введіть інформацію про місто:" << endl;
			city->enterinfo();
			misto = city->city;
			file << misto << endl;
		
			cout << "Введіть адресу:" << endl;
			cin >> address;
			file << address << endl;

			cout << "Введіть номер відділення:" << endl;
			cin >> numberviddil;
			file << numberviddil << endl;
			cin.get();
		}
	}

	file.close();
}

void Post::showINFO(Post *post, ifstream *fin, int i) {

	if (fin->is_open()) {

		*fin >> post[i].misto;
		*fin >> post[i].address;
		*fin >> post[i].numberviddil;
	}

}

void Post::coutINFO(Post *post, int i) {
	cout << "Місто:" << post[i].misto << endl << "Адреса:" << post[i].address << endl << "Номер відділення:" << post[i].numberviddil << endl;
}

void Post::enterTimeOFwork() {
	ofstream file;
	file.open("Time.txt");
	
	if (file.is_open()) {

		cout << "Введіть початок робочого дня:" << endl;
		cin >> startOFwork;
		file << startOFwork << endl;

		cout << "Введіть кінець робочого дня:" << endl;
		cin >> endOFwork;
		file << endOFwork << endl;
	}
	file.close();
}

void Post::showINFO(int startOFwork, int endOFwork) {
	fin.exceptions(ifstream::badbit | ifstream::failbit);
	try{
		fin.open("Time.txt");
		if (fin.is_open()) {
			while (fin >> startOFwork) {
				fin >> endOFwork;
				cout << "Початок робочого дня:" << startOFwork << endl << "Кінець робочого дня:" << endOFwork << endl;
			}
		}
		fin.close();
	}
	catch (const std::exception &ex){
		cout << ex.what() << "Error" << endl;
	}
}

//class Parcel methods 
Parcel::Parcel() {

}

Parcel::~Parcel() {
}

void Parcel::enterDATAaboutParcel(string surnamev) {
	file.open("Parcel.txt", ios_base::app);

	if (file.is_open()) {
		cout << "Введіть тип відправлення: " ;
		cin >> this->type;
		file << this->type << endl;

		cout << "Введіть вагу відправлення: " ;
		cin >> this->weight;
		file << this->weight << endl;

		cout << "Введіть вартість доставки: " ;
		cin >> this->price;
		file << this->price << endl;

		cout << "Прізвище відправника: " ;
		cout << surnamev << endl;
		file << surnamev << endl;

		cout << "Введіть прізвище отримувача: ";
		cin >> this->otrymuvach;
		file << this->otrymuvach << endl;

		cout << "Введіть дату відправлення: " ;
		cin >> this->startDelivery;
		file << this->startDelivery << endl;

		cout << "Введіть дату отримання: " ;
		cin >> this->endDelivery;
		file << this->endDelivery << endl;

		cout << "Серійний номер: " ;
		srand(time(NULL));
		this->seria = rand() % 5000;
		cout << this->seria;
		file << this->seria << endl;

		if (this->weight > 20)
			cout << endl << "НЕ відправлено у зв'язку з перевищенням ваги посилки." << endl;
	}

	file.close();
}

void Parcel::showDATAaboutParcel() {
	fin.open("Parcel.txt");

	if (fin.is_open()) {
		while (fin >> type)
		{
			fin >> weight;
			fin >> price;
			fin >> vidpravnik;
			fin >> otrymuvach;
			fin >> startDelivery;
			fin >> endDelivery;
			fin >> seria;

			cout << "Тип відправлення:" << type << endl << "Вага відправлення:" << weight << endl << "Вартість  доставки:" << price << endl << "Відправник:" << vidpravnik << endl << "Отримувач: " << otrymuvach << endl << "Дата відправки:" << startDelivery << endl << "Дата отримання:" << endDelivery << endl << "Серійний номер:" << seria << endl;
		}
	}
}

void Parcel::showDATAaboutParcel(Parcel *parcel, string surname) {
	ifstream fin("Parcel.txt");
	if (fin.is_open())
	{
		while (fin >> type)
		{

			fin >> weight;
			fin >> price;
			fin >> vidpravnik;
			fin >> otrymuvach;
			fin >> startDelivery;
			fin >> endDelivery;
			fin >> seria;

			if (surname == vidpravnik)
			{

				cout << "Тип відправлення:" << type << endl << "Вага відправлення:" << weight << endl << "Вартість  доставки:" << price << endl << "Відправник:" << vidpravnik << endl << "Отримувач:" << otrymuvach << endl << "Дата відправки:" << startDelivery << endl << "Дата отримання:" << endDelivery << endl << "Серійний номер:" << seria << endl;

				if (weight >= 20) {
					parcel->delivered(--parcel); 
					break;
				}

				else {
					parcel->delivered(++parcel);
					break;
				}

			}
		}
	}

}

void Parcel::delivered(bool fromgetdelivered) {
	if (fromgetdelivered == true)
		cout << "Посилка відправлена. " << endl;

	if (fromgetdelivered == false)
		cout << " Посилка не відправлена." << endl;
}

void Parcel::left() {

	int *seria = new int[10];
	for (int i = 0; i < 10; i++)
		seria[i] = rand() % 100;

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 9; j++)
			if (seria[j] < seria[j + 1])
				swap(seria[j], seria[j + 1]);

	for (int i = 0; i < 10; i++)
		cout << seria[i] << ',';

	cin.get();
	cin.get();
}

//class City methods 
City::~City(){
}

void City::copypost(Post *post, ifstream *fin)
{
	int i = 0;
	if (fin->is_open()){
		while (!fin->eof()){
			post[i].showINFO(post, fin, i);
		
		if (post[i].misto == "Львів"){
			ofstream file("LvivPosts.txt",ios_base::app);
			file <<  post[i].misto << endl <<  post[i].address << endl <<  post[i].numberviddil << endl;
			file.close();
		}
		else if (post[i].misto == "Тернопіль"){
			ofstream file("TernopilPosts.txt", ios_base::app);
			file <<  post[i].misto << endl  << post[i].address << endl  << post[i].numberviddil << endl;
			file.close();
		}
		else if (post[i].misto == "Хмельницький"){
			ofstream file("KhmelPosts.txt", ios_base::app);
			file << post[i].misto << endl  << post[i].address << endl  << post[i].numberviddil << endl;
			file.close();
		}
		else{
			ofstream file("OtherPosts.txt", ios_base::app);
			file  << post[i].misto << endl  << post[i].address << endl << post[i].numberviddil << endl;
			file.close();
		}
		i++;
		}	
	}
}

void City::countpost(Post *post){
	int choose;
	cout << "Оберіть дію:\n" << "Кількість поштових відділень у Львові та інформація про них - 1" << endl << "Кількість поштових відділень у Хмельницькому та інформація про них - 2" << endl << "Кількість поштових відділень у Тернополі та інформація про них - 3" << endl << "Кількість поштових відділень та інформація про них у інших містах-4" << endl<<"Загальна кількість поштових відділень-5" << endl;
	cin >> choose;

	if (choose == 1){
		ifstream fin("LvivPosts.txt");
		int i = 0;
		if (fin.is_open()){
			do {
				post[i].showINFO(post, &fin, i);				
				post[i].coutINFO(post, i);
				i++;
			} while ((fin>>post[i].misto) && (fin >> post[i].address) && (fin>> post[i].numberviddil));
			
			cout <<"Кількість відділень: "<< i << endl;
		}
		fin.close();
		cin.get();
		cin.get();
	}

	else if (choose == 2){
		ifstream fin("KhmelPosts.txt");
		int i = 0;
		if (fin.is_open()){
			do {
				post[i].showINFO(post, &fin, i);
				post[i].coutINFO(post, i);
				i++;
			} while ((fin >> post[i].misto) && (fin >> post[i].address) && (fin >> post[i].numberviddil));

			cout << "Кількість відділень: " << i << endl;
		}
		fin.close();
		cin.get();
		cin.get();
	}

	else if (choose == 3){
		ifstream fin("TernopilPosts.txt");
		int i = 0;
		if (fin.is_open()){
			do {
				post[i].showINFO(post, &fin, i);
				post[i].coutINFO(post, i);
				i++;
			} while ((fin >> post[i].misto) && (fin >> post[i].address) && (fin >> post[i].numberviddil));

			cout << "Кількість відділень: " << i << endl;
		}
		fin.close();
		cin.get();
		cin.get();
	}

	else if (choose == 4){
		ifstream fin("OtherPosts.txt");
		int i = 0;
		if (fin.is_open()){
			do {
				post[i].showINFO(post, &fin, i);
				post[i].coutINFO(post, i);
				i++;
			} while ((fin >> post[i].misto) && (fin >> post[i].address) && (fin >> post[i].numberviddil));

			cout << "Кількість відділень: " << i << endl;
		}
		fin.close();
		cin.get();
		cin.get();
	}

	else if (choose == 5){
		ifstream fin("Post.txt");
		int i = 0;
		while (fin) {
			post[i].showINFO(post, &fin, i);
			i++;
		}
	
		for (int i = 0; i < 4; i++) {
			post[i].coutINFO(post, i);
		}
			cout << "Кількість відділень: " << i-1 << endl;
		cin.get();
		cin.get();
		fin.close();
		
	}

	
}

City::City(string &misto, string &obl, string &koduvannia){
	this->oblast6 = obl;
	this->city = misto;
	this->kod = koduvannia;
}

void City::enterinfo(){
	ofstream file("Cities.txt", ios_base::app);

	if (file.is_open()) {
		cout << "Введіть місто:" << endl;
		cin >> city;
		file << city << endl;

		cout << "Введіть область:" << endl;
		cin >> oblast6;
		file << oblast6 << endl;

		cout << "Введіть код міста:" << endl;
		cin >> kod;
		file << kod << endl;
		cin.get();
	}

	file.close();
}

//function 
void coutJ(){
	City *city=new City;
	cout << "Реалізація дружньої функції" << endl << city->city << endl;
}

long long int just(Parcel *parcel){
	long long int podatok = parcel->price;
	podatok = podatok + 10;
	return podatok;
	
}

float just(Parcel &parcel){
	float podatok = parcel.price;
	podatok += 10;
	return podatok;
}


//class Client methods 
Client::Client(){

}

Client::~Client(){

}

void Client::infoAboutCLIENT(){
	ofstream file("Clients.txt", ios_base::app);
	if (file.is_open()){

		cout << "Ваша роль:" << endl;
		cin >> role;
		file << role << endl;

		cout << "Введіть ім'я:" << endl;
		cin >> name;
		file << name << endl;

		cout << "Введіть прізвище:" << endl;
		cin >> surname;
		file << surname << endl;;

		cout << "Ваше місто:" << endl;
		cin >> home;
		file << home << endl;

		cout << "Ваш вік:" << endl;
		cin >> age;
		file << age << endl;

		cout << "Номер телефону:" << endl;
		cin >> phone;
		file << phone << endl;
	}
	file.close();


}

string Client::getname(){

	return this->surname;
}

void Client::choosepost( string misto){
	ifstream fin("Post.txt");
	Post post[5];
	int i = 0;
	while (fin) {
		post[i].showINFO(post, &fin, i);
		i++;
	}
	cout << "Найближче до Вас поштове відділення" << endl << "______________________________________" << endl;
	for (int i = 0; i < 5; i++){
		if (misto == post[i].misto)
			post[i].coutINFO(post, i);	
		else cout << "";
	}
	fin.close();
}

void Client::readclient(Client *client,ifstream *fin) {
	int i = 0;
		while (*fin >> client[i].role){
			*fin >> client[i].name;
			*fin >> client[i].surname;
			*fin >> client[i].home;
			*fin >> client[i].age;
			*fin >> client[i].phone;	
			cout << "Клієнт: " << client[i].role << endl << "Ім'я: " << client[i].name << endl << "Прізвище: " << client[i].surname << endl << "Місце проживання:" << client[i].home << endl << "Вік:" << client[i].age << endl << "Номер телефону: " << client[i].phone << endl;

			i++; if (i > 100) break;
		}
	}


//class Otrymuvach methods 
void Otrymuvach::getdelivery(){
	cout << "Введіть серійний номер відправлення: " << endl;
	int seriaforotr;
	cin >> seriaforotr;
	ifstream fin;
	fin.open("Parcel.txt");


	if (fin.is_open()) {
		while (fin >> type)
		{	
			fin >> weight;
			fin >> price;
			fin >> vidpravnik;
			fin >> otrymuvach;
			fin >> startDelivery;
			fin >> endDelivery;
			fin >> seria;	
			if (seriaforotr == seria) break;
		} 
		cout <<endl << "Інформація" << endl<<"___________________________" << endl;
		cout << "Тип відправлення:" << type << endl << "Вага відправлення:" << weight << endl << "Вартість  доставки:" << price << endl << "Відправник:" << vidpravnik << endl << "Отримувач: " << otrymuvach << endl << "Дата відправки:" << startDelivery << endl << "Дата отримання:" << endDelivery << endl << "Серійний номер:" << seria << endl;
	
		if (type == "Переказ_грошей"){
	
		//))))
			
			*this *= 10;
			cout << "Ваш рахунок попонено на " << price << "гривень" << endl;
	}
	else return;
	cout <<"_____________________"<<endl<< "Відправлення отримано" << endl;

	}
	

	fin.close();
}

Otrymuvach::~Otrymuvach(){
}

//class Vidpravnik methods 
Vidpravnik::~Vidpravnik(){

}

void Vidpravnik::enterdelivery(string surname){

	int N;
	cout << "Кількість посилок:" << endl;
	cin >> N;
	long long int cost;

	int typeOFparcel;
	cout << "Ваше відправлення передбачає : 1-переказ грошей, 2-пересилка документів, 3-вантажне перевезення, 4-інше" << endl;
	cin >> typeOFparcel;

	switch (typeOFparcel){
	case 1:{
		MoneyParcel *moneyparcel = new MoneyParcel[N];

		cout << "Введіть дані про відправлення: " << endl;
		costs = 2000;
		for (int i = 0; i < N; i++) {

			moneyparcel[i].enterDATAaboutParcel(surname);
			

		
			
		if (moneyparcel[i].weight < 20){
			cost = costs -  moneyparcel[i].price-savesuma(moneyparcel[i].suma);
			cout << endl << " Ваш рахунок: " << cost << endl;

		}
		else {
			cout << "Не відправлено" << endl;
			cost = costs;
			cout << endl << " Ваш рахунок: " << cost << endl;
		}
	}
				

	}
		   break;
	case 2:{
		Parcel *parcel;
		DocumentsParcel *docsparcel = new DocumentsParcel[N];

		parcel = docsparcel;

		cout << "Введіть дані про відправлення: " << endl;
		costs = 2000;
		for (int i = 0; i < N; i++) {
			parcel[i].enterDATAaboutParcel(surname);

		if (parcel[i].weight < 20){
			cost = costs - parcel[i].price;
			cout << endl << " Ваш рахунок: " << cost << endl;

		}
		else {
			cout << "Не відправлено" << endl;
			cost = costs;
			cout << endl << " Ваш рахунок: " << cost << endl;
		}
			
		}
		

		
	}
		   break;
	case 3:{
		VantazhneParcel *vantazhneparcel = new VantazhneParcel[N];

		cout << "Введіть дані про відправлення: " << endl;
		costs = 2000;
		for (int i = 0; i < N; i++) {

			vantazhneparcel[i].enterDATAaboutParcel(surname);
		if (vantazhneparcel[i].weight < 20){
			cost = costs - vantazhneparcel[i].price;
			cout << endl << " Ваш рахунок: " << cost << endl;

		}
		else {
			cout << "Не відправлено" << endl;
			cost = costs;
			cout << endl << " Ваш рахунок: " << cost << endl;
		}
		}
		


	}
		   //doddatk
	case 4:{
		Parcel* parcel;
		MoneyParcel moneyparcel;
		parcel = &moneyparcel;
		

		cout << "Введіть дані про відправлення: " << endl;
		costs = 2000;
		

			parcel->enterDATAaboutParcel(surname);

			VantazhneParcel vantazh;
			parcel = &vantazh;

			parcel->enterDATAaboutParcel(surname);


			DocumentsParcel docs;
			parcel = &docs;

			parcel->enterDATAaboutParcel(surname);
		}
		   break;
		   
	case 5:{
		Parcel parcel;
		MoneyParcel moneyparcel;
		VantazhneParcel vantazhneparcel;

		Parcel *moneyparcelP = &parcel;
		moneyparcelP->enterDATAaboutParcel(surname);

		moneyparcelP = (Parcel *)&moneyparcel;
		moneyparcel.enterDATAaboutParcel(surname);

		moneyparcelP = (Parcel*)&vantazhneparcel;
		vantazhneparcel.enterDATAaboutParcel(surname);

	}
		   break;
		   //
	default:{
		Parcel *parcel = new Parcel[N];

		cout << "Введіть дані про відправлення: " << endl;
		costs = 2000;
		for (int i = 0; i < N; i++) {	
			
			parcel[i].enterDATAaboutParcel(surname);

		if (parcel[i].weight < 20){
			cost = costs - parcel[i].price;
			cout << endl << " Ваш рахунок: " << cost << endl;

		}
		else {
			cout << "Не відправлено" << endl;
			cost = costs;
			cout << endl << " Ваш рахунок: " << cost << endl;
		}
		
  }
		
			}
	}
}

//class Vidpravnik methods 
void Clients::getinfoaboutclients(){

	Client *client = new Client[100];
	ifstream fin("Clients.txt");
	int i = 0;
	if (fin.is_open()) {

		client[i].readclient(client,&fin); 
		i++;
	}
		
}

void Pryimach::coutemloyee(){
	cout << "Вас обслуговує:"  << endl;

	Employee *emp = new Employee[6];

	ifstream fin("Employee.txt");
	int i = 0;
	if (fin.is_open()) {
		emp[i].reademployee(emp,&fin);
		i++;
	}
	
	srand(time(NULL));
	int j = rand() % 4;
	cout << emp[j].name << " "<< emp[j].surname << endl;

}

void Employee::enteremloyee(int j, Employee *emp){
	ofstream file("Employee.txt",ios_base::app);

	for (int i = 0; i < j; i++){
		cout << "Ім'я працівника:";
		cin >> emp[i].name;
		file << emp[i].name<<endl;
		cout << "Прізвище працівника:";
		cin >> emp[i].surname;
		file << emp[i].surname << endl;
		cout << "Заробітна плата(грн):";
		Manager man;
		int z;
		cin >> z;
		file << man.getsalary(z)<<endl;
		cout << "Роль на пошті:";
		cin >> emp[i].function;
		file << emp[i].function << endl;
	}

}

Employee* Employee::deleteemployee(Employee *empl){
	Employee *newempl = new Employee[6];
	string deleted;
	cout << "Введіть прізвище працівника , якого хочете видалити:";
	cin >> deleted;
	int j = 0;
	for (int i = 0; i < 6; i++){
		if (deleted != empl[i].surname){
			newempl[j] = empl[i];
			j++;
		}
		
	}
	return newempl;
}

void Employee::reademployee(Employee *empl, ifstream *fin){

	int i = 0;
	while (*fin >> empl[i].name){
		*fin >> empl[i].surname;
		*fin >> empl[i].salary;
		*fin >> empl[i].function;
	

		i++; 
		if (i > 10) break;
	}
}

void Employee::read_cout(Employee *emp){
	ifstream fin("Employee.txt");
	int i = 0;
	
	while (fin>>emp[i].name){
		fin >> emp[i].surname;
		fin >> emp[i].salary;
		fin >> emp[i].function;
		emp[i] += " гривень";
		cout << "Ім'я працівника:" << emp[i].name << endl << "Прізвище працівника:" << emp[i].surname << endl << "Заробітна плата(грн):" << emp[i].salary << endl << "Роль на пошті:" << emp[i].function << endl;
	
		i++;
	}
	fin.close();
}

void DocumentsParcel::enterDATAaboutParcel(string surnamev){
		file.open("Parcel.txt", ios_base::app);

		if (file.is_open()) {
			cout << "Введіть тип відправлення: ";
			cout << "Відправка_документів" << endl;
			file <<"Відправка_документів" << endl;

			weight = 0;
			file << this->weight << endl;

			cout << "Вартість доставки: ";
			price = 20;
			cout << price<<endl;
			file << this->price << endl;

			cout << "Прізвище відправника: ";
			cout << surnamev << endl;
			file << surnamev << endl;

			cout << "Введіть прізвище отримувача: ";
			cin >> this->otrymuvach;
			file << this->otrymuvach << endl;

			cout << "Введіть дату відправлення: ";
			cin >> this->startDelivery;
			file << this->startDelivery << endl;

			cout << "Введіть дату отримання: ";
			cin >> this->endDelivery;
			file << this->endDelivery << endl;

			cout << "Серійний номер: ";
			srand(time(NULL));
			this->seria = rand() % 5000;
			cout << this->seria;
			file << this->seria << endl;

				}

		file.close();
	}

void VantazhneParcel::enterDATAaboutParcel(string surnamev){
	file.open("Parcel.txt", ios_base::app);

	if (file.is_open()) {
		cout << "Тип відправлення: ";
		cout << "Відправка_вантажу" << endl;
		file << "Відправка_вантажу" << endl;

		cout << "Введіть вагу відправлення: ";
		cin >> this->weight;
		file << this->weight << endl;

		cout << "Вартість доставки: ";
		if (this->weight < 10){
			price = 100;
			cout << price;
		}
		else if (this->weight >= 10 && this->weight < 20){
			price = 150;
			cout << price;
		}
		else if (this->weight > 20){
			price = 0;
			cout << price;
		}
		file << this->price << endl;

		cout << "Прізвище відправника: ";
		cout << surnamev << endl;
		file << surnamev << endl;

		cout << "Введіть прізвище отримувача: ";
		cin >> this->otrymuvach;
		file << this->otrymuvach << endl;

		cout << "Введіть дату відправлення: ";
		cin >> this->startDelivery;
		file << this->startDelivery << endl;

		cout << "Введіть дату отримання: ";
		cin >> this->endDelivery;
		file << this->endDelivery << endl;

		cout << "Серійний номер: ";
		srand(time(NULL));
		this->seria = rand() % 5000;
		cout << this->seria;
		file << this->seria << endl;

	}

	file.close();
}

void MoneyParcel::enterDATAaboutParcel(string surnamev){
	file.open("Parcel.txt", ios_base::app);
	
	if (file.is_open()) {
		cout << "Тип відправлення: ";
		cout << "Переказ_грошей" << endl;
		file << "Переказ_грошей" << endl;

		cout << "Вага відправлення: ";
		weight = 0;
		cout << weight;
		file << this->weight << endl;

		cout << "Сума переказу:" << endl;
		
		cin >> suma;
		savesuma(suma);

		cout << "Вартість доставки: ";
		price = suma/10;
		cout << price << endl;
		file << this->price << endl;

		cout << "Прізвище відправника: ";
		cout << surnamev << endl;
		file << surnamev << endl;

		cout << "Введіть прізвище отримувача: ";
		cin >> this->otrymuvach;
		file << this->otrymuvach << endl;

		cout << "Введіть дату відправлення: ";
		cin >> this->startDelivery;
		file << this->startDelivery << endl;

		cout << "Введіть дату отримання: ";
		cin >> this->endDelivery;
		file << this->endDelivery << endl;

		cout << "Серійний номер: ";
		srand(time(NULL));
		this->seria = rand() % 5000;
		cout << this->seria;
		file << this->seria << endl;

	}

	file.close();
}

long int savesuma(long int suma){
	long int notpateria = suma;
	return notpateria;
}

void zavd(int argc, char *argv[]){
	cout << argv[0] << endl;//шлях до застосунку
	if (argc > 1){
		ofstream file(argv[1]);
		file << "Start working with program" << endl;
		file.close();
	}
}