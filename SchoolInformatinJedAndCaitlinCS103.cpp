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
	string classroom;
	string maths;
	string science;
	string writing;
	string reading;
	string others;
	string progress;
	int parent;

	//Constructor
	Child(string fn = "", string ln = "", string pn = "", string g = "", string prn = "", string cr = "", string m = "", string s = "", string w = "", string r = "", string o = "", string pr = "", int pa = 0) {
		firstName = fn;
		lastName = ln;
		preferredName = pn;
		gender = g;
		pronouns = prn;
		classroom = cr;
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

	//Constructor
	Teacher(string fn = "", string ln = "", string t = "", string pn = "", string g = "", string prn = "", string d = "", string e = "", string p = "", string c = "", string y = "", string un = "", string pw = "", string cpw = "") {
		firstName = fn;
		lastName = ln;
		title = t;
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
	string title;
	string preferredName;
	string gender;
	string pronouns;
	string DOB;
	string email;
	string Ph;
	string emergencyPh;
	string coCarers;
	string childFirstName;
	string childLastName;
	string classroom;
	string username;
	string password;
	string confirmPassword;
	int ID;

	//Constructor
	Parent(string fn = "", string ln = "", string t = "", string pn = "", string g = "", string prn = "", string d = "", string e = "", string p = "", string ep = "", string un = "", string pw = "", string cpw = "", string cc = "", string cr = "", string cfn = "", string cln = "", int id = 0) {
		firstName = fn;
		lastName = ln;
		title = t;
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
		childFirstName = cfn;
		childFirstName = cln;
		ID = id;
	}
};

struct Admin {
	string username;
	string password;

	//Constructor, currently with hardcoded values
	Admin(string un = "smithDeborah", string pw = "Adminadmin123+") {
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
void childRegister(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a);
void childUpdate(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a);
void childDelete(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a);

int main()
{	
	vector <Child> children;// I'm not sure that we'll actually need to pass these around all the time. I built it with these vectors in case but we may end up passing them a lot less
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
	cin >> menu;//Menus using string inputs and digit answers through if statements are more robust than alt variables
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
	//check against usernames

	string password;
	cout << "Please enter your password: ";
	getline(cin, password);
	//check password against file
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
	getline(cin, registrant.year);
	cout << "Please enter choose a username: ";
	getline(cin, registrant.username);
	//Check against all extant usernames
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
		if (registrant.password.length() > 8 && digitFlag == 1 && upperFlag == 1 && lowerFlag == 1 && symbolFlag == 1) {
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
	//write registrant into files
}

void parentRegister(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a) {
	vector<Child> children = *c;
	vector<Teacher> teachers = *t;
	vector<Parent> parents = *p;
	Admin admin = *a;
	Parent registrant;
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
	cout << "Please enter a daytime contact number to use in emergencies: ";
	getline(cin, registrant.emergencyPh);
	cout << "Please enter the names of any co-carers: ";
	getline(cin, registrant.coCarers);
	cout << "Please enter the first name of your child: ";
	getline(cin, registrant.childFirstName);
	cout << "Please enter the last name of your child: ";
	getline(cin, registrant.childLastName);
	cout << "Please enter your child's classroom (eg 201, 105): ";
	getline(cin, registrant.classroom);
	//Check files for matching child, retake names and class if none found or tell them to contact admin
	cout << "Please enter choose a username: ";
	getline(cin, registrant.username);
	//Check against all extant usernames
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
		if (registrant.password.length() > 8 && digitFlag == 1 && upperFlag == 1 && lowerFlag == 1 && symbolFlag == 1) {
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
	//append registrant to files
	//generate parent ID number, compare with extant IDs, if fresh assign
	//Write parent ID number into child's file
}

void childRegister(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a) {
	vector<Child> children = *c;
	vector<Teacher> teachers = *t;
	vector<Parent> parents = *p;
	Admin admin = *a;
	Child registrant;
	cout << "Please enter the student's name(s): ";
	cin.ignore();
	getline(cin, registrant.firstName);
	cout << "Please enter the student's last name(s): ";
	getline(cin, registrant.lastName);
	cout << "Please enter the student's preferred name: ";
	getline(cin, registrant.preferredName);
	cout << "Please enter the student's pronouns: ";
	getline(cin, registrant.pronouns);
	cout << "Please enter the classroom for this student: ";
	getline(cin, registrant.classroom);
	cout << "Please enter the maths results (if known): ";
	getline(cin, registrant.maths);
	cout << "Please enter the science results (if known): ";
	getline(cin, registrant.science);
	cout << "Please enter the reading results (if known): ";
	getline(cin, registrant.reading);
	cout << "Please enter the writing results (if known): ";
	getline(cin, registrant.writing);
	cout << "Please enter the average across other results (if known): ";
	getline(cin, registrant.others);
	cout << "Please enter the current overall learning progress (if known). Recommended assessments are Achieved, Progressing, Need Help: ";
	getline(cin, registrant.progress);
	//append registrant to files
}

void updateGrades(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a) {
	vector<Child> children = *c;
	vector<Teacher> teachers = *t;
	vector<Parent> parents = *p;
	Admin admin = *a;
	string firstName;
	string lastName;
	Child updatee;
	cout << "Please enter the student's first name(s): ";
	cin.ignore();
	getline(cin, firstName);
	cout << "Please enter the student's last name(s): ";
	getline(cin, lastName);
	//Look through classroom file, find student by name, copy into updatee
	cout << "Please enter the maths results (if known): ";
	getline(cin, updatee.maths);
	cout << "Please enter the science results (if known): ";
	getline(cin, updatee.science);
	cout << "Please enter the reading results (if known): ";
	getline(cin, updatee.reading);
	cout << "Please enter the writing results (if known): ";
	getline(cin, updatee.writing);
	cout << "Please enter the average across other results (if known): ";
	getline(cin, updatee.others);
	cout << "Please enter the current overall learning progress (if known). Recommended assessments are Achieved, Progressing, Need Help: ";
	getline(cin, updatee.progress);
	//overwrite child's file with updatee
}

void childUpdate(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a) {
	vector<Child> children = *c;
	vector<Teacher> teachers = *t;
	vector<Parent> parents = *p;
	Admin admin = *a;
	string firstName;
	string lastName;
	string classroom;
	Child updatee;
	cin.ignore();
	cout << "Please enter the student's current first name(s): ";
	getline(cin, firstName);
	cout << "Please enter the student's current last name(s): ";
	getline(cin, lastName);
	cout << "Please enter the student's current classroom: ";
	getline(cin, classroom);
	//Find child record and import to updatee
	cout << "Please enter the student's new first name(s): ";
	getline(cin, updatee.firstName);
	cout << "Please enter the student's new last name(s): ";
	getline(cin, updatee.lastName);
	cout << "Please enter the student's new preferred name: ";
	getline(cin, updatee.preferredName);
	cout << "Please enter the student's new pronouns: ";
	getline(cin, updatee.pronouns);
	cout << "Please enter the new maths results (if known): ";
	getline(cin, updatee.maths);
	cout << "Please enter the new science results (if known): ";
	getline(cin, updatee.science);
	cout << "Please enter the new reading results (if known): ";
	getline(cin, updatee.reading);
	cout << "Please enter the new writing results (if known): ";
	getline(cin, updatee.writing);
	cout << "Please enter the new average across other results (if known): ";
	getline(cin, updatee.others);
	cout << "Please enter the new current overall learning progress (if known). Recommended assessments are Achieved, Progressing, Need Help: ";
	getline(cin, updatee.progress);
	//overwrite file with updatee
}

void childDelete(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a) {
	vector<Child> children = *c;
	vector<Teacher> teachers = *t;
	vector<Parent> parents = *p;
	Admin admin = *a;
	string firstName;
	string lastName;
	string classroom;
	cin.ignore();
	cout << "Please enter the student's current first name(s): ";
	getline(cin, firstName);
	cout << "Please enter the student's current last name(s): ";
	getline(cin, lastName);
	cout << "Please enter the student's current classroom: ";
	getline(cin, classroom);
	//Find child record
	cout << "Record found. Are you sure you wish to delete this data? Enter 1 to confirm or 2 to cancel.";
	string selection;
	cin >> selection;
	while (int selectedFlag = 0 == 0) {
		if (selection == "1") {
			//Delete data
			selectedFlag++;
			//adminmenu
		}
		else if (selection == "2") {
		
			selectedFlag++;
			//adminmenu
		}
		else {
			cout << "Error. Enter 1 or 2 only.";
			cin >> selection;
		}
	}
}