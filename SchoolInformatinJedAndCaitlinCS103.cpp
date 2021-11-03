//testing :D//Testing again
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

//Structure Definition

struct Child {
	string firstName;
	string lastName;
	string preferredName;
	string gender;
	string pronouns;
	string maths;
	string science;
	string writing;
	string reading;
	string others;
	string progress;
	string parent;

	Child(string fn = "", string ln = "", string pn = "", string g = "", string prn = "", string m = "", string s = "", string w = "", string r = "", string o = "", string pr = "", string pa = "") {
		firstName = fn;
		lastName = ln;
		preferredName = pn;
		gender = g;
		pronouns = prn;
		maths = m;
		science = s;
		writing = w;
		reading = r;
		others = o;
		progress = pr;
		parent = pa;
	}
};

struct Teacher {
	string firstName;
	string lastName;
	string preferredName;
	string gender;
	string pronouns;
	string DOB;
	string email;
	string Ph;
	string classroom;
	string year;
	string username;
	string password;
	string confirmPassword;

	Teacher(string fn = "", string ln = "", string pn = "", string g = "", string prn = "", string d = "", string e = "", string p = "", string c = "", string y = "", string un = "", string pw = "", string cpw = "") {
		firstName = fn;
		lastName = ln;
		preferredName = pn;
		gender = g;
		pronouns = prn;
		DOB = d;
		email = e;
		Ph = p;
		classroom = c;
		year = y;
		username = un;
		password = pw;
		confirmPassword = cpw;
	}
};

struct Admin {
	string username;
	string password;

	Admin(string un = "smithDeborah", string pw = "adminadmin123") {
		username = un;
		password = pw;
	}
};

struct Parent {
	string firstName;
	string lastName;
	string preferredName;
	string gender;
	string pronouns;
	string DOB;
	string email;
	string Ph;
	string emergencyPh;
	string username;
	string password;
	string confirmPassword;
	string coCarers;
	string classroom;

	Parent(string fn = "", string ln = "", string pn = "", string g = "", string prn = "", string d = "", string e = "", string p = "", string ep = "", string un = "", string pw = "", string cpw = "", string cc = "", string cr = "") {
		firstName = fn;
		lastName = ln;
		preferredName = pn;
		gender = g;
		pronouns = prn;
		DOB = d;
		email = e;
		Ph = p;
		emergencyPh = ep;
		username = un;
		password = pw;
		confirmPassword = cpw;
		coCarers = cc;
		classroom = cr;
	}
};

//Function Prototypes
void teacherLogin();
void adminLogin();
void parentLogin();
void mainMenu();
void whichLogin();
void whichRegister();
void teacherRegister();
void parentRegister();

int main()
{
	mainMenu();
}

//Function Definitions

void mainMenu() {
	int menu;
	cout << "\nPlease select one of the following options by typing its number and pressing enter.\n\n\n\t1. Login\n\n\t2. Register\n\n";
	cin >> menu;
	switch (menu) {
	case 1:
		whichLogin();
		break;
	case 2:
		whichRegister();
		break;
	default:
		cout << "Sorry, that wasn't one of the options. Make sure you're only including the number.";
			mainMenu();
		break;
	}
}

void teacherLogin() {
	string username;
	cout << "Please enter your username: ";
	cin.ignore();
	getline(cin, username);
	string password;
	cout << "Please enter your password: ";
	cin.ignore();
	getline(cin, password);
}

void adminLogin() {
	string username;
	cout << "Please enter your username: ";
	cin.ignore();
	getline(cin, username);
	string password;
	cout << "Please enter your password: ";
	cin.ignore();
	getline(cin, password);
}

void parentLogin() {
	string username;
	cout << "Please enter your username: ";
	cin.ignore();
	getline(cin, username);
	string password;
	cout << "Please enter your password: ";
	cin.ignore();
	getline(cin, password);
}

void whichLogin() {
	cout << "\nWhat kind of account are you logging in?\n\n\n\t1. Teacher\n\n\t2. Parent\n\n\t3. Admin\n\n";
	int submenu;
	cin >> submenu;
	switch (submenu) {
	case 1:
		teacherLogin();
		break;
	case 2:
		parentLogin();
		break;
	case 3:
		adminLogin();
		break;
	default:
		cout << "Sorry, that wasn't one of the options. Make sure you're only including the number.";
		whichLogin();
		break;
	}
}

void whichRegister() {
	cout << "\nWhat kind of account are you registering?\n\n\n\t1. Teacher\n\n\t2. Parent\n\n";
	int submenu;
	cin >> submenu;
	switch (submenu) {
	case 1:
		teacherRegister();
		break;
	case 2:
		parentRegister();
		break;
	default:
		cout << "Sorry, that wasn't one of the options. Make sure you're only including the number.";
		whichLogin();
		break;
	}
}

void teacherRegister() {

}

void parentRegister() {

}