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

	cout << "������� �������! ������ �� :\n 1-�����������\n 2-�볺��" << endl;
	int act;
	cin >> act;

	switch (act){
	case 1: {
		
		cout << "������ ������ �������:";
		int z1;
		cin >> z1;
		if (z1 == pass.passADM(3060)){
			int z;
			cout << "������ ��: \n1-�������� ���������� ��� ������ ��������  \n2-��������� ���������� ��� ������ �������� \n3-��������� ���������� ��� ������ �������� � ��������� ��� \n4-���������� ��� �볺��� \n5-�������� �� ������ \n6-���������� ��� ����������" << endl;
			cout << "_____________________________________________________________________________________" << endl;
			cin >> z;
			cout << "_____________________________________________________________________________________" << endl;
			City *city = new City;
			if (z == 1) {

				cout << "������ ���������� ��� ������� ��������." << endl;

				post->enterAddressANDcityANDnumberviddil(4, city);
				post->enterTimeOFwork();
				cout << endl;

				cin.get();
				system("cls");

				cout << "������� ���� ���������� ���� �������� � ����." << endl;
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
					cout << "������� ���'��" << endl;
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
				
				cout << "������ ������ �������:";
				int k;
				cin >> k;
				if (k == pass.passMAN(9050)){
					Employee *emp = new Employee[6];
					emp->enteremloyee(6, emp);
				}
				else cout << "������������ ������. �������������� ��������" << endl;
			}

			else if (z == 6){
				cout << "������ ������ �������:";
				int k;
				cin >> k;
				if (k == pass.passMAN(9050)){
					Employee *emp = new Employee[6];
					emp->read_cout(emp);
					cout << "_____________________________________________________________________________________" << endl;
					emp = emp->deleteemployee(emp);
					cout << "_____________________________________________________________________________________" << endl;
					cout << "����� ����� ����������:" << endl;
					for (int i = 0; i < 5; i++)
						cout << "��'� ����������:" << emp[i].name << endl << "������� ����������:" << emp[i].surname << endl << "�������� �����(���):" << emp[i].salary << endl << "���� �� ����:" << emp[i].function << endl;
				}
				else cout << "������������ ������. �������������� ��������" << endl;
			}
			
		}
		else cout << "������������ ������. �������������� ��������" << endl;
	}
			break;
	case 2:{
		cout << "������ ��: 1-���������/������� ����������� , 2-���������� ��� �����������" << endl;
		int k = 0;
		cout << "_____________________________________________________________________________________" << endl;
		cin >> k;

		if (k == 1) {
			Pryimach pryimach;
			pryimach.coutemloyee();
			Client client;
			cout << "��� ��?(��������� ��� ���������)" << endl;
			client.infoAboutCLIENT();
			client.choosepost(client.home);

			

			if (client.role == "³��������"){
				Vidpravnik vidpravnik;
			
				vidpravnik.enterdelivery(client.getname());
				cin.get();
				cin.get();
			}
			else if (client.role == "���������")
			{
				Otrymuvach otrymuvach;
				otrymuvach.getdelivery();
				
				cin.get();
				cin.get();
			}
			else
				cout << "�� �� ������ ���� ����." << endl;
		}

		else if (k == 2) {
			Parcel *shmotki = new Parcel;//11

			cout << "��� ���������  ���������� ��� ����������� ������ ������� ����������:" << endl;
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
			cout << "�� �� ������ ��" << endl;
			cin.get();
	}
	system("pause");


}