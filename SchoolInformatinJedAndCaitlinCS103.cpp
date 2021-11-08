//testing :D//Testing again//one more test!!
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
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
	string title;
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
	string child;

	Parent(string fn = "", string ln = "", string pn = "", string g = "", string prn = "", string d = "", string e = "", string p = "", string ep = "", string un = "", string pw = "", string cpw = "", string cc = "", string cr = "", string c = "") {
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
		child = c;
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

//Function Prototypes
void mainMenu(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a);
void whichLogin(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a);
void teacherLogin(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a);
void adminLogin(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a);
void parentLogin(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a);
void whichRegister(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a);
void teacherRegister(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a);
void parentRegister(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a);

int main()
{	
	vector <Child> children;
	vector <Teacher> teachers;
	vector <Parent> parents;
	Admin admin;
	mainMenu(&children, &teachers, &parents, &admin);
}

//Function Definitions
void mainMenu(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a) {
	vector<Child> children = *c;
	vector<Teacher> teachers = *t;
	vector<Parent> parents = *p;
	Admin admin = *a;
	string menu;
	cout << "\nPlease select one of the following options by typing its number and pressing enter.\n\n\n\t1. Login\n\n\t2. Register\n\n\t3. Exit\n\n";
	cin >> menu;
	if (menu == "1") {
		whichLogin(&children, &teachers, &parents, &admin);
	}
	else if (menu == "2") {
		whichRegister(&children, &teachers, &parents, &admin);
	}
	else if (menu == "3") {
		exit(0);
	}
	else {
		cout << "Sorry, that wasn't one of the options. Make sure you're only including the number.";
		mainMenu(&children, &teachers, &parents, &admin);
	}
}

void whichLogin(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a) {
	vector<Child> children = *c;
	vector<Teacher> teachers = *t;
	vector<Parent> parents = *p;
	Admin admin = *a;
	cout << "\nWhat kind of account are you logging in?\n\n\n\t1. Teacher\n\n\t2. Parent\n\n\t3. Admin\n\n";
	string submenu;
	cin >> submenu;
	if (submenu == "1") {
		teacherLogin(&children, &teachers, &parents, &admin);
	}
	else if (submenu == "2") {
		parentLogin(&children, &teachers, &parents, &admin);
	}
	else if (submenu == "3") {
		adminLogin(&children, &teachers, &parents, &admin);
	}
	else{
		cout << "Sorry, that wasn't one of the options. Make sure you're only including the number.";
		whichLogin(&children, &teachers, &parents, &admin);
	}
}

void teacherLogin(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a) {
	vector<Child> children = *c;
	vector<Teacher> teachers = *t;
	vector<Parent> parents = *p;
	Admin admin = *a;
	string username;
	cout << "Please enter your username: ";
	cin.ignore();
	getline(cin, username);
	string password;
	cout << "Please enter your password: ";
	getline(cin, password);
}

void adminLogin(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a) {
	vector<Child> children = *c;
	vector<Teacher> teachers = *t;
	vector<Parent> parents = *p;
	Admin admin = *a;
	string username;
	cout << "Please enter your username: ";
	cin.ignore();
	getline(cin, username);
	string password;
	cout << "Please enter your password: ";
	getline(cin, password);
}

void parentLogin(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a) {
	vector<Child> children = *c;
	vector<Teacher> teachers = *t;
	vector<Parent> parents = *p;
	Admin admin = *a;
	string username;
	cout << "Please enter your username: ";
	cin.ignore();
	getline(cin, username);
	string password;
	cout << "Please enter your password: ";
	getline(cin, password);
}



void whichRegister(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a) {
	vector<Child> children = *c;
	vector<Teacher> teachers = *t;
	vector<Parent> parents = *p;
	Admin admin = *a;
	cout << "\nWhat kind of account are you registering?\n\n\n\t1. Teacher\n\n\t2. Parent\n\n";
	int submenu;
	cin >> submenu;
	switch (submenu) {
	case 1:
		teacherRegister(&children, &teachers, &parents, &admin);
		break;
	case 2:
		parentRegister(&children, &teachers, &parents, &admin);
		break;
	default:
		cout << "Sorry, that wasn't one of the options. Make sure you're only including the number.";
		whichLogin(&children, &teachers, &parents, &admin);
		break;
	}
}

void teacherRegister(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a) {
	vector<Child> children = *c;
	vector<Teacher> teachers = *t;
	vector<Parent> parents = *p;
	Admin admin = *a;
	Teacher registrant;
	cout << "Please enter your first name(s): ";
	cin.ignore();
	getline(cin, registrant.firstName);
	cout << "Please enter your last name(s): ";
	getline(cin, registrant.lastName);
	cout << "Please enter your preferred title: (Mr, Miss, Mx, Dr. etc) ";
	getline(cin, registrant.title);
	cout << "Please enter your preferred name: ";
	getline(cin, registrant.preferredName);
	cout << "Please enter your pronouns: ";
	getline(cin, registrant.pronouns);
	cout << "Please enter your gender: ";
	getline(cin, registrant.gender);
	cout << "Please enter your date of birth: ";
	getline(cin, registrant.DOB);
	cout << "Please enter your email: ";
	getline(cin, registrant.email);
	int emailFlag = 0;
	while (emailFlag == 0) {
		for (int i = 0; i < registrant.email.length(); i++) {
			if (registrant.email[i] == '@') {
				emailFlag = 1;
			}
		}
		if (emailFlag == 0) {
			cout << "Error. Emails must include '@' symbol. Please re-enter your email: ";
			getline(cin, registrant.email);
		}
	}
	cout << "Please enter your contact number: ";
	getline(cin, registrant.Ph);
	cout << "Please enter the classroom you'll be working in (e.g. 201, 105): ";
	getline(cin, registrant.classroom);
	cout << "Please enter the year you'll be teaching: ";
	getline(cin, registrant.classroom);
	cout << "Please enter choose a username: ";
	getline(cin, registrant.username);
	cout << "Please enter choose a password - include a number, uppercase letter, lowercase letter and a special symbol (neither a letter nor a number): ";
	getline(cin, registrant.password);
	int passwordFlag = 0;
	int upperFlag = 0;
	int lowerFlag = 0;
	int digitFlag = 0;
	int symbolFlag = 0;
	int symbolSubFlag = 0;
	while (passwordFlag == 0) {
		for (int i = 0; i < registrant.password.length(); i++) {
			symbolSubFlag = 0;
			if (islower(registrant.password[i])) {
				lowerFlag = 1;
				symbolSubFlag++;
			}
			if (isupper(registrant.password[i])) {
				upperFlag = 1;
				symbolSubFlag++;
			}
			if (isdigit(registrant.password[i])) {
				digitFlag = 1;
				symbolSubFlag++;
			}
			if (symbolSubFlag == 0) {
				symbolFlag = 1;
			}
		}
		if (registrant.password.length() > 7 && digitFlag == 1 && upperFlag == 1 && lowerFlag == 1 && symbolFlag == 1) {
			passwordFlag++;
		}
		if (passwordFlag == 0) {
			cout << "Error. Passwords must be 8 or more characters, including upper and lower case letters, numbers, and non-alphanumeric symbols. Please enter a valid password: ";
			getline(cin, registrant.password);
		}
	}
	while (registrant.confirmPassword != registrant.password) {
		cout << "Please confirm your password: ";
		getline(cin, registrant.confirmPassword);
		if (registrant.confirmPassword != registrant.password) {
			cout << "Passwords do not match. ";
		}
	}
}

void parentRegister(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a) {
	vector<Child> children = *c;
	vector<Teacher> teachers = *t;
	vector<Parent> parents = *p;
	Admin admin = *a;
}