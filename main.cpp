// Max Base
// https://github.com/BaseMax/BankSystemCLI
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

int hasAuth=0;
int customerIndex=-1;
const int MAX=1000;
int SIZE=0;

#define NAME 0
#define FAMILY 1
#define NAMES 2
#define USERNAME 3
#define PASSWORD 4
#define NUMBER 5
#define BALANCE 6
#define BANK_TAX 10000

// struct customer {
// 	string name;
// 	string family;
// 	string names;
// 	string username;
// 	string password;
// 	int number=-1;
// 	int balance=0;
// };

string customers[MAX][7];

int GetCustomerIndexByNames(string names) {
	for(int i=0;i<SIZE;i++) {
		if(stoi(customers[i][NUMBER]) == -1) {
			continue;
			// return -1;
			// break;
		}
		if(customers[i][NAMES].find(names) != std::string::npos) {
			return i;
		}
	}
	return -1;
}

int GetCustomerIndexByName(string name) {
	for(int i=0;i<SIZE;i++) {
		if(stoi(customers[i][NUMBER]) == -1) {
			continue;
			// return -1;
			// break;
		}
		if(customers[i][NAME] == name) {
			return i;
		}
	}
	return -1;
}

int GetCustomerIndexByUsername(string username) {
	for(int i=0;i<SIZE;i++) {
		if(stoi(customers[i][NUMBER]) == -1) {
			continue;
			// return -1;
			// break;
		}
		if(customers[i][USERNAME] == username) {
			return i;
		}
	}
	return -1;
}

int GetCustomerIndexByUserPass(string username, string password) {
	for(int i=0;i<SIZE;i++) {
		if(stoi(customers[i][NUMBER]) == -1) {
			continue;
			// return -1;
			// break;
		}
		if(customers[i][USERNAME] == username && customers[i][PASSWORD] == password) {
			return i;
		}
	}
	return -1;
}

int GetCustomerIndexByFamily(string family) {
	for(int i=0;i<SIZE;i++) {
		if(stoi(customers[i][NUMBER]) == -1) {
			continue;
			// return -1;
			// break;
		}
		if(customers[i][FAMILY] == family) {
			return i;
		}
	}
	return -1;
}

int GetCustomerIndexByNumber(int number) {
	// for(int i=0;i<MAX;i++) {
	for(int i=0;i<SIZE;i++) {
		if(stoi(customers[i][NUMBER]) == -1) {
			continue;
			// return -1;
			// break;
		}
		if(stoi(customers[i][NUMBER]) == number) {
			return i;
		}
	}
	return -1;
}

void displayCustomerByIndex(int i) {
	if(i < SIZE) {
		cout << "Error: cannot find details of this customer!\n";
		return;
	}
	cout << "Customer details:::::::::::::::::::::::::::::::\n";
	cout << "\tname: " << customers[i][NAME] << "\n";
	cout << "\tfamily: " << customers[i][FAMILY] << "\n";
	cout << "\tusername: " << customers[i][USERNAME] << "\n";
	cout << "\tpassword: " << customers[i][PASSWORD] << "\n";
	cout << "\tnumber: " << customers[i][NUMBER] << "\n";
	cout << "\tbalance: " << customers[i][BALANCE] << "\n";
	cout << "\n";
}

void displayCustomerByNumber(int number) {
	int i=GetCustomerIndexByNumber(number);
	if(i == -1) {
		cout << "Error: cannot find details of this customer!\n";
		return;
	}
	displayCustomerByIndex(i);
}

void insertCustomer(string name, string family, string username, string password, int number, int balance) {
	customers[SIZE][NAME]=name;
	customers[SIZE][FAMILY]=family;
	customers[SIZE][NAMES]=name + " " + family;
	customers[SIZE][USERNAME]=username;
	customers[SIZE][PASSWORD]=password;
	customers[SIZE][NUMBER]=to_string(number);
	customers[SIZE][BALANCE]=to_string(balance);
	SIZE++;
}

void panelAdmin() {
	cout << "\nWhat you want?\n";
	cout << "\t1. insert, delete, modify a customer\n";
	cout << "\t2. search in customer looking for bank number or name\n";
	cout << "\t3. push or pull money from a customer\n";
	cout << "\t4. transfer money between two bank account\n";
	cout << "\t5. get report and display list of data\n";
	cout << "\t6. calc balance of bank and all customers\n";
	cout << "\t7. modify password of a customer\n";
	cout << "\t8. logout from account\n";
	cout << "\t9. exit and goodbye!\n";
	int whatType;
	cout << ">";
	cin >> whatType;
	cout << "\n";
	if(whatType == 1) {
		cout << "Do you want insert or delete or edit? (1 for insert, 2 for delete, 3 for edit)\n";
		cout << ">";
		int type;
		cin >> type;
		if(type == 1) {
			cout << "Inserting a new customer::::::::::::::::::\n";
			string name, family, username, password;
			int balance, number;

			cout << "Enter name:";
			cin >> name;

			cout << "Enter family:";
			cin >> family;

			// string names=name + " " + family;

			cout << "Enter username:";
			cin >> username;

			while(username == "admin" || (customerIndex=GetCustomerIndexByUsername(to_string(number))) != -1) {
				if(username == "admin") {
					cout << "Error: you cannot set admin as your username, it's not allowed!\n";
				}
				else {
					cout << "Error: you cannot set dublicate value for account number!\n";
				}
				cout << "Enter new username:";
				cin >> username;
			}

			cout << "Enter password:";
			cin >> password;

			cout << "Enter number:";
			cin >> number;

			while(GetCustomerIndexByNumber(number) != -1) {
				cout << "Error: you cannot set dublicate value for account number!\n";
				cout << "Enter new number:";
				cin >> number;
			}

			cout << "Enter balance:";
			cin >> balance;
			while(balance < 100000) {
				cout << "Error: you cannot set low value for account balance!\n";
				cout << "Enter new balance:";
				cin >> balance;
			}

			insertCustomer(name, family, username, password, number, balance);
			cout << "Customer succesfully inserted!\n";
		}
		else if(type == 2) {
			string number;
			cout << "Enter a customer card number: ";
			cin >> number;
			while(customerIndex=GetCustomerIndexByNumber(stoi(number)) == -1) {
				cout << "Error: this card number not found!\n";
				cout << "Enter new card number to search in bank:";
				cin >> number;
			}
			customers[customerIndex][NUMBER]="-1";

			customers[customerIndex][BALANCE]="0";
			customers[customerIndex][NAME]="";
			customers[customerIndex][FAMILY]="";
			customers[customerIndex][NAMES]="";
			customers[customerIndex][USERNAME]="";
			customers[customerIndex][PASSWORD]="";
			cout << "Deleted!\n";
		}
		else if(type == 3) {
			string number;
			cout << "Enter a customer card number: ";
			cin >> number;
			while(customerIndex=GetCustomerIndexByNumber(stoi(number)) == -1) {
				cout << "Error: this card number not found!\n";
				cout << "Enter new card number to search in bank:";
				cin >> number;
			}
			customers[customerIndex][NUMBER]="-1";

			customers[customerIndex][BALANCE]="0";
			customers[customerIndex][NAME]="";
			customers[customerIndex][FAMILY]="";
			customers[customerIndex][NAMES]="";
			customers[customerIndex][USERNAME]="";
			customers[customerIndex][PASSWORD]="";

			string name, family, username, password;
			int balance;

			cout << "Enter name:";
			cin >> name;

			cout << "Enter family:";
			cin >> family;

			// string names=name + " " + family;

			cout << "Enter username:";
			cin >> username;

			while(username == "admin" || GetCustomerIndexByUsername(number) != -1) {
				if(username == "admin") {
					cout << "Error: you cannot set admin as your username, it's not allowed!\n";
				}
				else {
					cout << "Error: you cannot set dublicate value for account number!\n";
				}
				cout << "Enter new username:";
				cin >> username;
			}

			cout << "Enter password:";
			cin >> password;

			cout << "Enter number:";
			cin >> number;

			while(GetCustomerIndexByNumber(stoi(number)) != -1) {
				cout << "Error: you cannot set dublicate value for account number!\n";
				cout << "Enter new number:";
				cin >> number;
			}

			cout << "Enter balance:";
			cin >> balance;
			while(balance < 100000) {
				cout << "Error: you cannot set low value for account balance!\n";
				cout << "Enter new balance:";
				cin >> balance;
			}

			insertCustomer(name, family, username, password, stoi(number), balance);
			cout << "Customer succesfully updated!\n";
		}
		else {
			cout << "Error!\n";
		}
	}
	else if(whatType == 2) {
		cout << "Do you want search order by name or bank number? (1 for full-name, 2 for first name, 3 for last name/family, 4 for bank number)\n";
		cout << ">";
		int type;
		cin >> type;
		if(type == 1) {
			string names;
			cout << "Enter your name: ";
			cin >> names;
			int i=GetCustomerIndexByNames(names);
			if(i == -1) {
				cout << "Not exists!\n";
			}
			else {
				displayCustomerByIndex(i);
			}
		}
		else if(type == 2) {
			string name;
			cout << "Enter your first name: ";
			cin >> name;
			int i=GetCustomerIndexByName(name);
			if(i == -1) {
				cout << "Not exists!\n";
			}
			else {
				displayCustomerByIndex(i);
			}
		}
		else if(type == 3) {
			string family;
			cout << "Enter your last name/family: ";
			cin >> family;
			int i=GetCustomerIndexByFamily(family);
			if(i == -1) {
				cout << "Not exists!\n";
			}
			else {
				displayCustomerByIndex(i);
			}
		}
		else if(type == 4) {
			int number;
			cout << "Enter your bank number: ";
			cin >> number;
			int i=GetCustomerIndexByNumber(number);
			if(i == -1) {
				cout << "Not exists!\n";
			}
			else {
				displayCustomerByIndex(i);
			}
		}
		else {
			cout << "Error!\n";
		}
	}
	else if(whatType == 3) {
		string number;
		cout << "Enter a customer card number: ";
		cin >> number;
		while(customerIndex=GetCustomerIndexByNumber(stoi(number)) == -1) {
			cout << "Error: this card number not found!\n";
			cout << "Enter new card number to search in bank:";
			cin >> number;
		}

		int type;
		cout << "Do you want to import money to bank or export? (1 for import, 2 for export) ";
		cin >> type;
		if(type == 1) {
			int price;
			cout << "Enter your price: ";
			cin >> price;

			customers[customerIndex][BALANCE]=to_string(stoi(customers[customerIndex][BALANCE]) + price);
			cout << "Moved!\n";
		}
		else if (type == 2) {
			int price;
			cout << "Enter your price: ";
			cin >> price;

			if(stoi(customers[customerIndex][BALANCE]) - BANK_TAX >= price) {
				customers[customerIndex][BALANCE]=to_string(stoi(customers[customerIndex][BALANCE]) - price);
				cout << "Moved!\n";
			}
			else {
				cout << "No money, You cannot get this price!\n";
			}
		}
		else {
			cout << "Error type!\n";
		}
	}
	else if(whatType == 4) {
		int customerIndex1, customerIndex2;
		string number1;
		cout << "Enter a card number as sender: ";
		cin >> number1;
		while((customerIndex1=GetCustomerIndexByNumber(stoi(number1))) == -1) {
			cout << "Error: this card number not found!\n";
			cout << "Enter new card number to search in bank:";
			cin >> number1;
		}

		string number2;
		cout << "Enter a card number as target: ";
		cin >> number2;
		while((customerIndex2=GetCustomerIndexByNumber(stoi(number2))) == -1) {
			cout << "Error: this card number not found!\n";
			cout << "Enter new card number to search in bank:";
			cin >> number2;
		}

		if(customerIndex1 == customerIndex2) {
			cout << "Cannot send a money from a account to itself!\n";
		}
		else {
			int price;
			cout << "Enter a money price to move: ";
			cin >> price;
			if(stoi(customers[customerIndex1][BALANCE]) - BANK_TAX >= price) {
				customers[customerIndex2][BALANCE]=to_string(stoi(customers[customerIndex2][BALANCE]) + price);
				cout << "Moved!\n";
			}
			else {
				cout << "Sender not have this price!\n";
			}
		}
	}
	else if(whatType == 5) {
		cout << "NAME\tFAMILY\tUSERNAME\tPASSWORD\tNUMBER\tBALANCE\n";
		for(int i=0;i<SIZE;i++) {
			if(stoi(customers[i][NUMBER]) == -1) {
				continue;
			}
			cout << customers[i][NAME] << "\t";
			cout << customers[i][FAMILY] << "\t";
			cout << customers[i][USERNAME] << "\t";
			cout << customers[i][PASSWORD] << "\t";
			cout << customers[i][NUMBER] << "\t";
			cout << customers[i][BALANCE] << "";
			cout << "\n";
		}
		cout << "\n";
	}
	else if(whatType == 6) {
		int sum=0;
		for(int i=0;i<SIZE;i++) {
			if(stoi(customers[i][NUMBER]) == -1) {
				continue;
			}
			sum+=stoi(customers[i][BALANCE]);
		}
		cout << "Sum of all customers is: " << sum << "\n";
	}
	else if(whatType == 7) {
		string username;
		cout << "Enter a customer username: ";
		cin >> username;
		while(username == "admin" || (customerIndex=GetCustomerIndexByUsername(username)) == -1) {
			if(username == "admin") {
				cout << "Error: you cannot access to admin account, it's not allowed!\n";
			}
			else {
				cout << "Error: you cannot change password of an undefined username!\n";
			}
			cout << "Enter new username to search in bank:";
			cin >> username;
		}

		cout << "Enter current password:";
		string password_now;
		cin >> password_now;

		cout << "Enter new password:";
		string passeord_new;
		cin >> passeord_new;

		cout << "Repeat new password again:";
		string passeord_new2;
		cin >> passeord_new2;

		while(passeord_new != passeord_new2) {
			cout << "Error: repeat of your new password is not same!\n";

			cout << "Enter new password:";
			string passeord_new;
			cin >> passeord_new;

			cout << "Repeat new password again:";
			string passeord_new2;
			cin >> passeord_new2;
		}

		if(customers[customerIndex][PASSWORD] != password_now) {
			cout << "Current password is not valid!\n";
		}
		else {
			customers[customerIndex][PASSWORD]=passeord_new;
			cout << "Password changed!\n";
		}
	}
	else if(whatType == 8) {
		cout << "Logout...\n";
		hasAuth=0;
	}
	else if(whatType == 9) {
		cout << "GoodBye!\n";
		exit(0);
	}
	else {
		cout << "Error!\n";
	}
}

void panelCustomer() {
	cout << "\nWhat you want?\n";
	cout << "\t1. calc balance of your account\n";
	cout << "\t2. modify password\n";
	cout << "\t3. pay bull for simcard\n";
	cout << "\t4. logout from account\n";
	cout << "\t5. exit and goodbye!\n";
	int whatType;
	cout << ">";
	cin >> whatType;
	cout << "\n";
	if(whatType == 1) {
		if(stoi(customers[customerIndex][BALANCE]) >= 1000) {
			// cout << "Your current balance is: " << customers[customerIndex][BALANCE]<< "\n";
			customers[customerIndex][BALANCE]=to_string(stoi(customers[customerIndex][BALANCE]) - 1000);
			cout << "Your current balance is: " << customers[customerIndex][BALANCE]<< "\n";
		}
		else {
			cout << "Error: You not have enough balance to see your account balance!\n";
		}
	}
	else if(whatType == 2) {
		cout << "Enter your current password:";
		string password_now;
		cin >> password_now;

		cout << "Enter new password:";
		string passeord_new;
		cin >> passeord_new;

		cout << "Repeat new password again:";
		string passeord_new2;
		cin >> passeord_new2;

		while(passeord_new != passeord_new2) {
			cout << "Error: repeat of your new password is not same!\n";

			cout << "Enter new password:";
			string passeord_new;
			cin >> passeord_new;

			cout << "Repeat new password again:";
			string passeord_new2;
			cin >> passeord_new2;
		}

		if(customers[customerIndex][PASSWORD] != password_now) {
			cout << "Your current password is not valid!\n";
		}
		else {
			customers[customerIndex][PASSWORD]=passeord_new;
			cout << "Password changed!\n";
		}
	}
	else if(whatType == 3) {
		cout << "Enter your value to buy bill: ";
		int value;
		cin >> value;
		if(stoi(customers[customerIndex][BALANCE]) >= value) {
			customers[customerIndex][BALANCE]=to_string(stoi(customers[customerIndex][BALANCE]) - value);
			cout << "You did buied charge, enjoy from it.\n";
		}
		else {
			cout << "Error: You not have suitable balance to buy this, try again fewer price of bill!\n";
		}
	}
	else if(whatType == 4) {
		cout << "Logout...\n";
		hasAuth=0;
	}
	else if(whatType == 5) {
		cout << "GoodBye!\n";
		exit(0);
	}
	else {
		cout << "Error!\n";
	}
}

void authAdmin() {
	string username, password;
	cout << "Enter username: ";
	cin >> username;
	cout << "Enter password: ";
	cin >> password;
	if(username == "admin" && password == "123") {
		hasAuth=1;
		while(hasAuth == 1) {
			panelAdmin();
		}
	}
	else {
		hasAuth=0;
		cout << "Auth not valid, password or username was wrong!\n";
	}
}

void authCustomer() {
	string username, password;
	cout << "Enter username: ";
	cin >> username;
	cout << "Enter password: ";
	cin >> password;
	hasAuth=0;
	// customerIndex=-1;
	customerIndex=GetCustomerIndexByUserPass(username, password);
	if(customerIndex != -1) {
		hasAuth=1;
		while(hasAuth == 1) {
			panelCustomer();
		}
	}
	else {
		hasAuth=0;
		cout << "Auth not valid, password or username was wrong!\n";
	}
}

int main(int argc, char const *argv[]) {
	cout << "Hello, World!\n";
	while(true) {
		cout << "Enter your user type? (1 for admin, 2 for customer)\n>";
		int userType;
		cin >> userType;
		if(userType == 1) {
			authAdmin();
		}
		else if(userType == 2) {
			authCustomer();
		}
		else {
			cout << "Error!\n";
		}
	}
	return 0;
}
