#include <iostream>
#include <fstream>
#include <string>
//1-5,13
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



long int savesuma(long int suma);
long long int just(Parcel *parcel);//13
float just(Parcel &parcel);//14
void zavd(int argc, char *argv[]);



class Post
{		static	int startOFwork, endOFwork;
			friend class City;//11
		private:
			string  address, numberviddil;
			ofstream file;
			ifstream fin;

		public:
		
			string misto;
			Post();
			~Post();
			void enterAddressANDcityANDnumberviddil(int j, City *city);
			static void enterTimeOFwork();//12
			void showINFO(Post *post, ifstream *fin, int i);
			void showINFO(int  startOFwork, int  endOFwork);
			void aboutparcel(Parcel *parcel, string surname);
			void coutINFO(Post *post, int i);
			
		
};

class Parcel
{
		protected:
			string  vidpravnik, otrymuvach;
			long int seria, startDelivery, endDelivery;
			bool fromgetdelivered;
			ofstream file;
			ifstream fin;
			Post *post = new Post;
		
		public:	
			long long int price;
			string type;
			float  weight;
			Parcel();
			virtual ~Parcel();
			virtual	void enterDATAaboutParcel(string surnamev);
			void showDATAaboutParcel();
			void showDATAaboutParcel(Parcel *parcel, string surname);
			void delivered(bool fromgetdelivered);
			void left();//12
			Parcel& operator++();
			Parcel& operator--();
};

class City{
		private:
			string city, oblast6, kod;
			int number, kst;
			friend class Post;
		public:
			//City();//без параметрів
			City() :city("Назва міста за замовчуванням"), oblast6("Область за замовчуванням"), kod("0000"){};//5
			City(string &misto , string &obl, string &koduvannia);//конструктор копіювання , конструктор з параметрами, 4
			~City();
			friend void coutJ();//10
			void countpost(Post *post);
			void copypost(Post *post, ifstream *fin);
			void enterinfo();
};

class Client{
		protected:
				string name, surname;
				long long int age, phone, costs;
				Post *post = new Post;
				Parcel parcel;
		public:
	
				string getname();
				string role, home;
				Client();
				Client(string name, string surname, string home, long long int age, long long int phone, float costs);
				~Client();
				void infoAboutCLIENT();
				void choosepost(string misto);
				void readclient(Client *client,ifstream *fin);
};

class Vidpravnik : protected Client{
		public:
			using Client::surname;
			Vidpravnik() :Client(){};
			~Vidpravnik();
			void enterdelivery(string surname);
};

class Otrymuvach : public Client,public Parcel{
		public:
			Parcel parcel;
			Otrymuvach() :Client(){};
			~Otrymuvach();
			void getdelivery();
			Otrymuvach& operator*=(int n);
};

class Clients : public Vidpravnik, private Otrymuvach, public Client{
		public:
			void getinfoaboutclients();
			Clients(string name, string surname, string home, long long int age, long long int phone, float costs) :Client(name, surname, home, age, phone, costs){};
			~Clients(){};
			Clients() :Client(){};
};

class Employee{

public:
	string salary;
	string name, surname, function;
	Employee(){};
	~Employee(){};
	void enteremloyee(int j, Employee *emp);
	void reademployee(Employee *empl,ifstream *fin);
	Employee* deleteemployee(Employee *empl);
	void read_cout(Employee *emp);
	Employee& operator+=(string currency);
};

class Pryimach :public Employee{
	
public:
	Pryimach() :Employee(){};
	void coutemloyee();
	
};

class Manager :public Employee, public Pryimach{
	public:
		
		Manager(){ };
		~Manager(){};

		template <typename getsalary> getsalary getsalary(getsalary a){
			return a;
		};
};

class MoneyParcel :public Parcel{
public:
	long int suma;
	MoneyParcel(){};
	~MoneyParcel() override{};
	void enterDATAaboutParcel(string surnamev) override;
	
};

class VantazhneParcel:public Parcel{
public:
	VantazhneParcel() {};
	~VantazhneParcel() override {};
	void enterDATAaboutParcel(string surnamev) override;
};

class DocumentsParcel :public Parcel{
public:
	DocumentsParcel()  {};
	~DocumentsParcel() override{};

	void enterDATAaboutParcel(string surnamev) override;

}; 

class ReloadedOperators{
public:
	int x=60, y=5;
	ReloadedOperators(){};
	~ReloadedOperators(){};
	ReloadedOperators operator+(int f);
	ReloadedOperators operator-(int f);
	ReloadedOperators operator*(int f);
	ReloadedOperators operator=(int f);
	ReloadedOperators operator-=(int f);
	ReloadedOperators& operator[](int n);

};

template <class T1, class T2>
class Passwords{
private:
	T1 passwordFORadmin;
	T2 passwordFORmanager;
public:
	
	int passADM(T1 passwordFORadmin){ return passwordFORadmin; };
	int passMAN(T2 passwordFORmanager){ return passwordFORmanager; };
	void enterpassword(T1 passwordFORadm, T2 passwordFORman){
		
		passwordFORadmin = passADM(passwordFORadm);
		passwordFORmanager = passMAN(passwordFORman);
		cout << "adm:" << passwordFORadmin << endl;
		cout << "manager:" << passwordFORmanager << endl;
	};

	
};