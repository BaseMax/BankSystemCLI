#include<iostream>
#include<string>
#include<iomanip>

using namespace std;
string Moshtari[50][6];

bool Rig(string user, string password) {
	int a = 0;
	while (a < 50) {
		if (Moshtari[a][2] == user && Moshtari[a][3] == password)
			return true;
	}
	return false;
	a++;
}
void dis() {
	cout << "name" << setw(10) << "lastname" << setw(10) << "user" << setw(10) << "pass" << setw(10) << "HesabNo" << setw(10) << "Mojodi\n\n";
}
void display(int a)

{
	dis();
	for (int b = 0; b < 6; b++)
		cout << Moshtari[a][b] << setw(10);
}
void report() {
	cout << "lastname" << setw(10) << "HesabNo" << setw(10) << "Mojodi";
	int a = 0;
	while (a < 50) {

		for (int b = 0; b < 6; b++) {
			if ((b != 0) || (b != 2) || (b != 3)) {
				cout << Moshtari[a][b] << setw(10);

			}
		}
		cout << endl;
		a++;
	}
}
void search() {
	int s;
	int flag = 0;
	cin >> s;
	switch (s) {
	case 1:
		{
			string Ac;
			cout << "shomare hesab ra vared konid : ";
			getline(cin, Ac);

			int a = 0;
			while (a < 50) {

				if (Ac == Moshtari[a][4]) {
					display(a);
					flag = 1;

				}
				a++;

			}
			if (flag != 1)
				cout << "not found";
			break;
		}
	case 2:
		{
			string name,
			lastname;
			cout << "lotfan name ra vared konid : ";
			getline(cin, name);
			cout << "lotfan nameKhanevadegi ra vared konid : ";
			getline(cin, lastname);
			for (int a = 0; a < 50; a++) {
				if (Moshtari[a][0] == name && Moshtari[a][1] == lastname) {
					display(a);
					flag = 1;
				}
			}
			if (flag != 1)
				cout << "not found";
			break;
		}

	}

}

void variz() {
	int mablagh;

	string acno;
	cout << "mablagh ra vared konid : ";
	cin >> mablagh;
	cout << "shomare hesab ra vared konid : ";
	cin >> acno;
	int a = 0;
	while (a < 50) {

		if (Moshtari[a][4] == acno) {
			Moshtari[a][5] = to_string(stoi(Moshtari[a][5]) + mablagh);

		}
		a++;
	}

}
void bardasht() {
	int mablagh;

	string acno;
	cout << "mablagh ra vared konid : ";
	cin >> mablagh;
	cout << "shomare hesab ra vared konid : ";
	cin >> acno;
	int a = 0;
	while (a < 50) {

		if (Moshtari[a][4] == acno) {
			if (stoi(Moshtari[a][5]) - mablagh > 10000)
				Moshtari[a][5] = to_string(stoi(Moshtari[a][5]) - mablagh);

		}
	}
	a++;
}
void entegh() {
	int mablagh;
	cout << "mablagh ra vared konid : ";
	cin >> mablagh;
	string ac1, ac2;
	cout << "shomare hesab mabda ra vared konid : ";
	getline(cin, ac1);
	cout << "shomare hesab  maghsad ra vared konid : ";
	getline(cin, ac2);
	int tmp = -1;
	int tmp2 = -1;
	int a = 0;
	while (a < 50) {

		if (Moshtari[a][4] == ac1) {
			tmp = a;
		}
		if (Moshtari[a][4] == ac2) {
			tmp2 = a;
		}
		a++;

	}
	if ((tmp = -1) || (tmp2 = -1))
		cout << "shomare hesab mojod nist";
	else {
		if (mablagh < stoi(Moshtari[tmp][5]) - 10000) {
			Moshtari[tmp][5] = to_string(stoi(Moshtari[tmp][5]) - mablagh);
			Moshtari[tmp2][5] = to_string(stoi(Moshtari[tmp2][5]) + mablagh);
		}
	}
}
void totalMojodi() {
	int Mojodi = 0;
	int a = 0;
	while (a < 50) {

		Mojodi += stoi(Moshtari[a][5]);
		a++;
	}
	cout << "Mojodi Kol : " << Mojodi;
}
void add() {
	int tmp = -1;
	int a = 0;
	while (a < 50) {

		if (Moshtari[a][0] == "!") {
			tmp = a;
		}
		a++;

	}
	cout << "lotfan nam ra vared konid : ";
	cin >> Moshtari[tmp][0];
	cout << "lotfan last name ra vared konid : ";
	cin >> Moshtari[tmp][1];
	cout << "lotfan nam karbari ra vared konid : ";
	cin >> Moshtari[tmp][2];
	cout << "lotfan ramz ra vared konid : ";
	cin >> Moshtari[tmp][3];
	cout << "lotfan shomare hesab ra vared konid : ";
	cin >> Moshtari[tmp][4];
	cout << "lotfan Mojodi ra vared konid bayad bishtar az 100000 bashad : ";
	cin >> Moshtari[tmp][5];

}
void del() {
	string ac1;
	cout << "lotfan shomare hesab ra vared konid : ";
	getline(cin, ac1);
	int a = 0;
	while (a < 50) {

		if (Moshtari[a][4] == ac1) {
			for (int b = 0; b < 6; b++)
				Moshtari[a][b] = '!';

		}
	}
	a++;
}
void virayesh() {
	string ac1;
	cout << "lotfan shomare hesab ra vared konid : ";
	getline(cin, ac1);
	int tmp = -1, flag = 0;
	int a = 0;
	while (a < 50) {

		if (Moshtari[a][4] == ac1) {
			tmp = a;
			flag = 1;

		}
		a++;
	}
	if (flag == 1) {
		int s;
		cout << "kodam ghesmat ra mikhahid virayesh konid   \n1-name \n2-lastname \n3-name karbari \n4-ramz obor \n 5-shomare hesab \n6-mojodi ";
		cin >> s;
		cout << "lotfan meghdar jadid ra vared konid";
		cin >> Moshtari[tmp][s - 1];
		display(tmp);
	}
}

void admin()

{
	string user;
	int password;
	cout << "lotfan name karbari ra vared konid : ";
	getline(cin, user);
	cout << "lotfan ramz obor   ra vared konid : ";
	cin >> password;
	if (((user == "admin")) && (password == 123)) {
		cout << "Menu admin\n1-add\n2-delete\n3-edit\n4-search\n5-report\n6-enteghal\n7-variz\n8-bardasht\n9-mojodi bank\n10-quit:";
		int s;
		cin >> s;
		do {

			switch (s) {
			case 1:
				add();
				break;
			case 2:
				del();
				break;
			case 3:
				virayesh();
				break;
			case 4:
				search();
				break;
			case 5:
				report();
				break;
			case 6:
				entegh();
				break;
			case 7:
				variz();
				break;
			case 8:
				bardasht();
				break;
			case 9:
				totalMojodi();
				break;

			}

		} while (s != 10);
	}
}
void Mojodi(string user) {
	int a = 0;
	while (a < 50) {

		if (Moshtari[a][2] == user) {
			Moshtari[a][5] = to_string(stoi(Moshtari[a][5]) - 1000);
			cout << Moshtari[a][5];
			break;

		}
		a++;
	}

}
void changepass(string user) {
	int a = 0;
	while (a < 50) {

		if (Moshtari[a][2] == user) {
			string pass;
			cout << "lotfan ramz jadid ra vared konid : ";

			cin >> pass;
			Moshtari[a][3] = pass;
			cout << "amalit ba movafaghiatt anjam shod";
			break;

		}
		a++;
	}
}
void charge(string user) {
	cout << "1- 10000R \n2- 20000R \n3- 30000R";
	int s;
	cin >> s;
	int flag = 0;
	int a = 0;
	while (a < 50) {

		if (Moshtari[a][2] == user && stoi(Moshtari[a][5]) - 100000 > s * 10000) {

			cout << "\n" << rand() % 90000 + 10000 << endl;
			Moshtari[a][5] = to_string(stoi(Moshtari[a][5]) - s * 10000);
			cout << "\n Mojodi : " << Moshtari[a][5] << endl;
			flag = 1;
			break;

		}
		a++;
	}
	if (flag == 0)
		cout << "Mojodi kafi nist";

}
void user() {
	string user, password;
	int s;
	cout << "lotfan name karbari ra vared konid : ";
	getline(cin, user);
	cout << "lotfan ramz obor   ra vared konid : ";
	getline(cin, password);
	if (Rig(user, password)) {
		do {
			cout << "user Menu \n1-Mojodi (kasr Karmozd)\n2-taghir ramz\n3-kharid charge\n4-khoroj\n--> : ";
			cin >> s;
			switch (s) {
			case 1:
				{
					Mojodi(user);
					break;
				}
			case 2:
				{
					changepass(user);
					break;
				}
			case 3:
				charge(user);
				break;

			}
		} while (s != 4);

	}

}
int main() {
	int a = 0;
	while (a < 50) {
		for (int b = 0; b < 6; b++) {
			Moshtari[a][b] = "!";
		}
		a++;
	}
	cout << "\n1-admin \n2-Moshtari \n vared konid : ";
	int s;
	cin >> s;
	switch (s) {
	case 1:
		admin();
		break;
	case 2:
		user();
		break;
	}
}
