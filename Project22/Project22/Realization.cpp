#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

//9,14,15

using namespace  std;

void main(int argc, char *argv[])
{
	zavd(argc, argv);//7

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Post post[5];
	City city;

	Passwords<int, int> pass;
	pass.enterpassword(3060, 9050);

	cout << "Ласкаво просимо! Оберіть дію :\n 1-Адміністратор\n 2-Клієнт" << endl;
	int act;
	cin >> act;

	switch (act){
	case 1: {
		
		cout << "Введіть пароль доступу:";
		int z1;
		cin >> z1;
		if (z1 == pass.passADM(3060)){
			int z;
			cout << "Оберіть дію: \n1-записати інформацію про поштові відділення  \n2-прочитати інформацію про поштові відділення \n3-прочитати інформацію про поштові відділення у вибраному місті \n4-інформація про клієнтів \n5-прийняти на роботу \n6-інформація про працівників" << endl;
			cout << "_____________________________________________________________________________________" << endl;
			cin >> z;
			cout << "_____________________________________________________________________________________" << endl;
			City *city = new City;
			if (z == 1) {

				cout << "Введіть інформацію про поштове відділення." << endl;

				post->enterAddressANDcityANDnumberviddil(4, city);
				post->enterTimeOFwork();
				cout << endl;

				cin.get();
				system("cls");

				cout << "Введена вами інформація була записана у файл." << endl;
				cin.get();
				cin.get();
				system("cls");
			}

			else if (z == 2) {
				ifstream fin("Post.txt");
				int i = 0;

				try{

					while (fin) {
						city->copypost(post, &fin);
						if (i > 4) throw 333;
						post[i].showINFO(post, &fin, i);
						i++;

					}

					fin.close();
				}
				catch (int th){
					cout << "Нестача пам'яті" << endl;
				}

				for (int i = 0; i < 4; i++) {
					post[i].coutINFO(post, i);
				}

			}
			else if (z == 3){
				city->countpost(post);
				cin.get();
			}
			else if (z == 4){
				Clients clients;
				clients.getinfoaboutclients();
			}
			
			
			else if (z == 5){
				
				cout << "Введіть пароль доступу:";
				int k;
				cin >> k;
				if (k == pass.passMAN(9050)){
					Employee *emp = new Employee[6];
					emp->enteremloyee(6, emp);
				}
				else cout << "Неправильний пароль. Перезавантажте програму" << endl;
			}

			else if (z == 6){
				cout << "Введіть пароль доступу:";
				int k;
				cin >> k;
				if (k == pass.passMAN(9050)){
					Employee *emp = new Employee[6];
					emp->read_cout(emp);
					cout << "_____________________________________________________________________________________" << endl;
					emp = emp->deleteemployee(emp);
					cout << "_____________________________________________________________________________________" << endl;
					cout << "Новий склад працівників:" << endl;
					for (int i = 0; i < 5; i++)
						cout << "Ім'я працівника:" << emp[i].name << endl << "Прізвище працівника:" << emp[i].surname << endl << "Заробітна плата(грн):" << emp[i].salary << endl << "Роль на пошті:" << emp[i].function << endl;
				}
				else cout << "Неправильний пароль. Перезавантажте програму" << endl;
			}
			
		}
		else cout << "Неправильний пароль. Перезавантажте програму" << endl;
	}
			break;
	case 2:{
		cout << "Оберіть дію: 1-відправити/забрати відправлення , 2-інформація про відправлення" << endl;
		int k = 0;
		cout << "_____________________________________________________________________________________" << endl;
		cin >> k;

		if (k == 1) {
			Pryimach pryimach;
			pryimach.coutemloyee();
			Client client;
			cout << "Хто ви?(Отримувач або відправник)" << endl;
			client.infoAboutCLIENT();
			client.choosepost(client.home);

			

			if (client.role == "Відправник"){
				Vidpravnik vidpravnik;
			
				vidpravnik.enterdelivery(client.getname());
				cin.get();
				cin.get();
			}
			else if (client.role == "Отримувач")
			{
				Otrymuvach otrymuvach;
				otrymuvach.getdelivery();
				
				cin.get();
				cin.get();
			}
			else
				cout << "Ви не обрали свою роль." << endl;
		}

		else if (k == 2) {
			Parcel *shmotki = new Parcel;//11

			cout << "Для перегляду  інформації про відправлення введіть прізвище відправника:" << endl;
			string *surname2 = new string;
			cin >> *surname2;

			shmotki->showDATAaboutParcel(shmotki, *surname2);
			cin.get();
			cin.get();
			system("cls");
		}
		break;
	}
		default: 
			cout << "Ви не обрали дію" << endl;
			cin.get();
	}
	system("pause");


}