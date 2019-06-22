#include<iostream>
#include<mutex>
#include<string>
using namespace std;
//mutex mtx;
class Account1 {
private:
public:
	string name;
	string surname;
	double balance; //$
	
	Account1() {
		cout << "Constuctor1" << endl;
		name = "Heghine";
		surname = "Aghajanyan";
		balance = 100;
	}
	Account1(const string&name, const string&surname, const double&balance) {
		this->name = name;
		this->surname = surname;
		this->balance = balance;
	}
		void Print() {
		cout << "Name ---- " << name << "\nSurname ---- " << surname << "\nBalance ---- " << balance << endl;
	}
	void cinAccount(){
		cout << "Name --> ";
		cin >> name;
		cout << "Surname --> ";
		cin >> surname;
		cout << "Balance --> ";
		cin >> balance;
		cout << endl;
	}
	virtual ~Account1() {
		cout << "Destructor1" << endl;
		system("pause");
	}
};
class Account2 : virtual public Account1{
private:
public:
	Account2() : Account1(name, surname, balance){

		cout << "Constructor2" << endl;
		name = "Adolf";
		surname = "Hitler";
		balance = 200000; //$ 
	}
	void Print(){
		Account1::Print();
	}
	void cinAccount() {
		Account1::cinAccount();
	}
	//int Transfer();
	virtual ~Account2() {
		cout << "Destructor2" << endl;
		system("pause");
	}
	void doSmth() {
		Account1*p = new Account2;
		delete p;
	}
};

/*int Account2::Transfer() {
	
}*/

int main() {
	Account1 b1;
	cout << "Enter your data." << endl;
	//b1.cinAccount();
	b1.Print();
	cout << endl;
	Account2 b2;
	cout << "Enter the receiver's data." << endl;
	//b2.cinAccount();
	b2.Print();
	double a;
	cout << "\nTransferring money = ";
	cin >> a;
	b1.balance = b1.balance - a;
	b2.balance = b2.balance + a;
	cout << "\nFinal:\n" << b1.name <<" "<<b1.surname<<" ---- " << b1.balance<<endl
		<< b2.name <<" "<<b2.surname<< " ---- " << b2.balance << endl;
	system("pause");
	return 0;
}
