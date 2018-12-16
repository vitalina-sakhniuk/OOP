#include <iostream>
#include <fstream>
#include <string>
#include <msclr\marshal_cppstd.h>
using namespace msclr::interop; 

using namespace std;

class Post;
class Parcel;
class City;
class Client;
class Vidpravnik;
class Otrymuvach;


class Post
{
	public:
	friend class City;//11
	string  address, numberviddil;
	ofstream file;
	ifstream fin;
	string misto;
	Post();
	~Post();
	void Post::enterAddressANDcityANDnumberviddil(City *city, std::string misto, std::string oblact6, std::string kod,std::string address, std::string numberviddil);
};

class Parcel
{
public:
	string  vidpravnik, otrymuvach;
	int seria;
	bool fromgetdelivered;
	ofstream file;
	ifstream fin;
	Post *post = new Post;
	string type, weight;
	Parcel();
	~Parcel();
	void enterDATAaboutParcel(std::string type, std::string weight, std::string surnamev, std::string otrymuvach,int seria);
	void showDATAaboutParcel();
	void showDATAaboutParcel(Parcel *parcel, string surname);
	void delivered(bool fromgetdelivered);
	Parcel *getdelivery(Parcel *parcel, int seriaforotr);
	Parcel *getinfo(Parcel *parcel, std::string person);
};

class City{
public:
	string city, oblast6, kod;
	friend class Post;

	City();
	~City();
	void enterinfo(std::string city, std::string oblact6, std::string kod);
};

class Client{
public:
	string name, surname,age, phone,role, home;
	Client();
	~Client();
	void infoAboutCLIENT(std::string role, std::string name, std::string surname, std::string age, std::string phone);
};

class Vidpravnik : protected Client{
public:
	using Client::surname;
	Vidpravnik();
	~Vidpravnik();
	void enterdelivery(string surname);
};

class Otrymuvach : public Client, public Parcel{
public:
	Parcel parcel;
	Otrymuvach();
	~Otrymuvach();
	void getdelivery();
};