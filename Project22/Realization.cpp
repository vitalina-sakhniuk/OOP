#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>

//9,14,15

using namespace  std;

void main(int argc, char *argv[])
{
	zavd(argc, argv);//7

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Post post[5];
	City city;



	Passwords<int, string> pass;
	pass.enterpassword(3060, 9050);
	string log = pass.enterlogin("login");
	string log2;
	cin >> log2;
	if (log == log2){
		cout << endl;
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
	else cout << "������������ ����";

	

	//1.1
	vector <LEFT> vectorsSP(5);
	vector <LEFT> ::iterator iter;
	LEFT cl1, cl2, cl3;
	vectorsSP.push_back(cl1);
	vectorsSP.push_back(cl2);
	vectorsSP.push_back(cl3);
	cout << "Vector size:" << vectorsSP.size() << endl;
	for (iter = vectorsSP.begin(); iter != vectorsSP.end(); ++iter) {
		(*iter).setrole("fff");
	}
	for (iter = vectorsSP.begin(); iter != vectorsSP.end(); ++iter) {
		cout << (*iter).getrole() << " ";
	}
	vectorsSP.clear();
	
	//1.2
	list<ReloadedOperators> spisok;
	ReloadedOperators posilka;
	spisok.push_front(posilka);
	int var = spisok.size();
	spisok.clear();

	//1.3
	deque <ReloadedOperators> dequequeSP;
	ReloadedOperators re;
	dequequeSP.push_front(re);
	int var2 = dequequeSP.size();
	dequequeSP.clear();

	//1.4
	set <string> MySET;
	Client employee, cleaner, teacher;
	employee.setrole("���������");
	cleaner.setrole("�������������");
	teacher.setrole("���������");
	MySET.insert(employee.getrole());
	MySET.insert(cleaner.getrole());
	MySET.insert(teacher.getrole());
	int size = MySET.size();
	cout << "\nMy set sizE:" << size << endl;



	//1.5
	multiset <string> MySETM;
	multiset<string>::iterator it;
	Client employee2, cleaner2, teacher2;
	employee2.setrole("���������");
	cleaner2.setrole("�������������");
	teacher2.setrole("���������");
	MySETM.insert(employee2.getrole());
	MySETM.insert(cleaner2.getrole());
	MySETM.insert(teacher2.getrole());
	int size2 = MySETM.size();



	//1.6
	map <string, int> myMap;
	map<string, int>::iterator iter1;

	myMap.insert(pair<string, int>("Or", 15));
	myMap.insert(pair<string, int>("Pr", 49));
	cout << "\nmyMap:\n";
	//2.4-2.5
	for (iter1 = myMap.end(); iter1 != myMap.begin(); --iter1)
	{
		if (iter1 != myMap.end())
		{
			cout << (*iter1).second << " " << (*iter1).first << " ";
		}
	}
	//1.7
	multimap <char, int> myMultimap;

	myMultimap.insert(pair<char, int>('O', 1010));
	myMultimap.insert(pair<char, int>('O', 2020));
	myMultimap.insert(pair<char, int>('P', 3030));

	cout << "\nMultimap:\n";
	for (auto oopm = myMultimap.begin(); oopm != myMultimap.end(); ++oopm)
	{
		cout << oopm->first << " : " << oopm->second << endl;
	}



	//1.8
	stack <int> myStack;
	
	myStack.push(4);
	myStack.push(5);
	myStack.push(45);
	myStack.push(54);

	cout << " \nStack size:" << myStack.size() << endl;

	while (!myStack.empty()){
		cout << myStack.top() << endl;
		myStack.pop();
	}

	//1.9
	queue <string> myQueue;
	myQueue.push("Hi");
	myQueue.push("OOP krut6");

	if (myQueue.empty() == 1)
		cout << "Queue is empty";
	else cout << "Queue size:\n" << myQueue.size() << endl;

	//1.10
	priority_queue <float> myPQ1, myPQ2, myPQ3;
	myPQ1.push(3.67);
	myPQ2.push(3.6847);
	myPQ2.push(4.6847);
	myPQ2.push(5.6847);

	myPQ3.push(myPQ1.size() + myPQ2.size());
	cout << "Sum of size PQ1 and PQ2:" << myPQ3.top() << endl;
	cout << "Element from PQ2: " << myPQ2.top() << endl;
	
	less <int> a;
	if (a(myPQ1.size(), myPQ2.size()));

	greater <int> b;
	if (b(myPQ1.size(), myPQ2.size()));

	plus <string> a2;
	Client cl,cl12;
	cl.setrole("³��������");
	cl12.setrole("���������");
    a2(cl1.getrole(),cl12.getrole());


	negate <int> neg;
	int minusneg = neg(minusneg);

	multiplies <int> m;
	int ml = m(4, 5);
	

	logical_or<bool> log1;
	if (log1(!myPQ1.empty(), !myPQ2.empty()))
	{
		myPQ2.emplace(myPQ1.top());
	
	}

	cout << max(myPQ1.top(), myPQ2.top());

	cin.get();
	cin.get();

}
