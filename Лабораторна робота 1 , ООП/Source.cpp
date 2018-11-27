#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>

using namespace std;

void RW();
void RD();
//void RW();
//void RD();

typedef struct StudentINFO{
	string name;
	string surname;
	string address;
	string number;

}StIn;


typedef struct StudentINFOAddress{
	string surname;
	string address;
}StInAddr;

//typedef struct StudentINFO2{
//	string name;
//	string surname;
//	string gender;
//	int course;
//	string group;
//}StIn2;
//
//typedef struct StudentINFOAlphabet{
//	string surname;
//	int course;
//	string group;
//
//}StInA;


void RW(){
	
	int number;
	cout << "Enter a number:";
	cin >> number;
	ofstream fout;
	fout.open("INFO.dat", ios_base::binary);
	StIn student;
	
	for (int i = 0; i < number; i++){
		cout << i + 1 << " -th student" << endl;

		cout << "Enter name:";		
		getline(cin, student.name);
		cout << "Enter surname:";
		getline(cin, student.surname);
		cout << "Enter address:";
		getline(cin, student.address);
		cout << "Enter number:";
		getline(cin, student.number);
		
		
		fout << "Name" << endl;
		fout.write((char*)&student.name, sizeof(StIn));
		fout << "Surname" << endl;
		fout.write((char*)&student.surname, sizeof(StIn));
		fout << "Address" << endl;
		fout.write((char*)&student.address, sizeof(StIn));
		fout << "Number" << endl;
		fout.write((char*)&student.number, sizeof(StIn));
		
		fout.close();

	}

}



void RD(){
	ifstream fin;
	fin.open("INFO.dat", ios_base::binary);
	StIn tmp;
fin.read( (char*)&tmp,sizeof(StIn));
	do{
		
		fin >> tmp.name >> tmp.surname >> tmp.address >> tmp.number ;
		cout << tmp.name << endl;
		cout << tmp.surname << endl;
		cout << tmp.address << endl;
		cout << tmp.number << endl;
	} while (!fin.eof());



	/*do
	{
		fin.read((char*)&tmp.name, sizeof(StIn));
		fin.read((char*)&tmp.surname, sizeof(StIn));
		fin.read((char*)&tmp.address, sizeof(StIn));
		fin.read((char*)&tmp.number, sizeof(StIn));

		cout << tmp.name << endl;
		cout << tmp.surname << endl;
		cout << tmp.address << endl;
		cout << tmp.number << endl;
	} while (!fin.eof());
*/
	fin.close();

}
int main(){
	cout << "Write to file..." << endl;
	RW();
	cout << "Read from file.." << endl;
	RD();
	cin.get();
	cin.get();
	return 0;
}