//See the bottom for a list of things that still need doing!
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
	string DOB;
	string classroom;
	string maths;
	string science;
	string writing;
	string reading;
	string others;
	string progress;
	int parent;//This will be a backend ID #

	//Constructor
	Child(string fn = "", string ln = "", string pn = "", string g = "", string prn = "", string d = "", string cr = "", string m = "", string s = "", string w = "", string r = "", string o = "", string pr = "", int pa = 0) {
		firstName = fn;
		lastName = ln;
		preferredName = pn;
		gender = g;
		pronouns = prn;
		DOB = d;
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
	string childFirstName;
	string childLastName;
	string classroom;
	string username;
	string password;
	string confirmPassword;
	int ID; //This will be a backend ID #

	//Constructor
	Parent(string fn = "", string ln = "", string t = "", string pn = "", string g = "", string prn = "", string d = "", string e = "", string p = "", string ep = "", string un = "", string pw = "", string cpw = "", string cr = "", string cfn = "", string cln = "", int id = 0) {
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
	Admin(string un = "PrincipalAdmin", string pw = "AdminAdmin123+") {
		username = un;
		password = pw;
	}
};

//Function Prototypes
vector <Child> readChildren201();
vector <Teacher> readTeachers();
vector <Parent> readParents();
void mainMenu(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a);
void whichLogin(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a);
void teacherLogin(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a);
void adminLogin(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a);
void parentLogin(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a);
void whichRegister(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a);
void teacherRegister(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a);
void parentRegister(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a);
void childRegister(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a);
void updateChild(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a);
void adminMenu(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a);
void deleteChild(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a);
void teacherMenu(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a, Teacher currentAccount);
void updateGrades(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a, Teacher currentAccount);
bool askUpdate(string field);

int main()
{	
	vector <Child> children = readChildren201();//I'm not sure that we'll actually need to pass these around all the time. I built it with these vectors in case but we may end up passing them a lot less
	vector <Teacher> teachers = readTeachers();
	vector <Parent> parents = readParents();
	Admin admin;
	mainMenu(&children, &teachers, &parents, &admin);
}

//Function Definitions
vector <Child> readChildren201() {
	//Reading from children file
	fstream childList("201.csv", ios::in);//We are using only one classroom file, but if I had multiple I would open them, read from them, push the info into the children vector and one close the file after the other
	string line;
	vector <Child> children;
	Child readChild;
	while (getline(childList, line)) {
		istringstream linestream(line);
		string datum;
		getline(linestream, datum, ',');
		readChild.firstName = datum;
		getline(linestream, datum, ',');
		readChild.lastName = datum;
		getline(linestream, datum, ',');
		readChild.preferredName = datum;
		getline(linestream, datum, ',');
		readChild.gender = datum;
		getline(linestream, datum, ',');
		readChild.pronouns = datum;
		getline(linestream, datum, ',');
		readChild.DOB = datum;
		getline(linestream, datum, ',');
		readChild.classroom = datum;
		getline(linestream, datum, ',');
		readChild.maths = datum;
		getline(linestream, datum, ',');
		readChild.science = datum;
		getline(linestream, datum, ',');
		readChild.reading = datum;
		getline(linestream, datum, ',');
		readChild.writing = datum;
		getline(linestream, datum, ',');
		readChild.others = datum;
		getline(linestream, datum, ',');
		readChild.progress = datum;
		getline(linestream, datum, ',');
		stringstream ss(datum);//converting string into int
		ss >> readChild.parent;//the converted int value will be given to readParent.ID
		//Push to vector
		children.push_back(readChild);
	}
	childList.close();
	return children;
}

vector <Teacher> readTeachers() {
	//Reading from Teacher file
	fstream teacherList("Teachers.csv", ios::in);
	vector <Teacher> teachers;
	string line;
	Teacher readTeacher;
	while (getline(teacherList, line)) {
		istringstream linestream(line);
		string datum;
		getline(linestream, datum, ',');
		readTeacher.firstName = datum;
		getline(linestream, datum, ',');
		readTeacher.lastName = datum;
		getline(linestream, datum, ',');
		readTeacher.title = datum;
		getline(linestream, datum, ',');
		readTeacher.preferredName = datum;
		getline(linestream, datum, ',');
		readTeacher.gender = datum;
		getline(linestream, datum, ',');
		readTeacher.pronouns = datum;
		getline(linestream, datum, ',');
		readTeacher.DOB = datum;
		getline(linestream, datum, ',');
		readTeacher.email = datum;
		getline(linestream, datum, ',');
		readTeacher.Ph = datum;
		getline(linestream, datum, ',');
		readTeacher.classroom = datum;
		getline(linestream, datum, ',');
		readTeacher.year = datum;
		getline(linestream, datum, ',');
		readTeacher.username = datum;
		getline(linestream, datum, ',');
		readTeacher.password = datum;
		//Push to vector
		teachers.push_back(readTeacher);
	}
	teacherList.close();
	return teachers;
}

vector <Parent> readParents() {
	//Reading from Parent file
	fstream parentList("Parents.csv", ios::in);
	vector <Parent> parents;
	string line;
	Parent readParent;
	while (getline(parentList, line)) {
		istringstream linestream(line);
		string datum;
		getline(linestream, datum, ',');
		readParent.firstName = datum;
		getline(linestream, datum, ',');
		readParent.lastName = datum;
		getline(linestream, datum, ',');
		readParent.title = datum;
		getline(linestream, datum, ',');
		readParent.preferredName = datum;
		getline(linestream, datum, ',');
		readParent.gender = datum;
		getline(linestream, datum, ',');
		readParent.pronouns = datum;
		getline(linestream, datum, ',');
		readParent.DOB = datum;
		getline(linestream, datum, ',');
		readParent.email = datum;
		getline(linestream, datum, ',');
		readParent.Ph = datum;
		getline(linestream, datum, ',');
		readParent.emergencyPh = datum;
		getline(linestream, datum, ',');
		readParent.childFirstName = datum;
		getline(linestream, datum, ',');
		readParent.childLastName = datum;
		getline(linestream, datum, ',');
		readParent.classroom = datum;
		getline(linestream, datum, ',');
		readParent.username = datum;
		getline(linestream, datum, ',');
		readParent.password = datum;
		getline(linestream, datum, ',');
		stringstream ss(datum);//converting string into int
		ss >> readParent.ID;//the converted int value will be given to readParent.ID
		//Push to vector
		parents.push_back(readParent);
	}
	parentList.close();
	return parents;
}

void mainMenu(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a) {
	vector<Child> children = *c;
	vector<Teacher> teachers = *t;
	vector<Parent> parents = *p;
	Admin admin = *a;
	
	//Colour scheme
	system("color e7");

	//Menu
	string menu;
	cout << "\n\x1B[31m****************************************************************************************\n";
	cout << "\n\t\t\t\tWelcome to Artificer Academy";
	cout << "\n\t\t\t\t\t---Home Page---";
	cout << "\n\n****************************************************************************************\n";
	cout << "\nPlease select one of the following options by typing its number and pressing enter.\n\n\n\t1. Login\n\n\t2. Register\n\n\t3. Exit\n\n\nPlease enter your chosen option: ";
	cin >> menu;//Menus using string inputs and digit answers through if statements are more robust than other variables or switches. We don't use getline because we don't want values with spaces to be handled fully - if some enters "1 " or "1 Login" this code will read it as "1", which is desirable.
	if (menu == "1") {
		whichLogin(&children, &teachers, &parents, &admin);
	}
	else if (menu == "2") {
		whichRegister(&children, &teachers, &parents, &admin);
	}
	else if (menu == "3") {
		exit(0);//Exit 0 ends the program even if functions are still running
	}
	else {
		cout << "Sorry, that wasn't one of the options. Make sure you're only including the >>number<<\n\nEnter 1 to return to Main Menu ";
		cin >> menu;//"Enter 1" is an instruction that works, but entering anything and pressing enter will work. This input exists to hold the program here while they read the alert above before outputting the main menu again.
		mainMenu(&children, &teachers, &parents, &admin);
	}
}

void whichLogin(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a) {
	vector<Child> children = *c;
	vector<Teacher> teachers = *t;
	vector<Parent> parents = *p;
	Admin admin = *a;

	//Login Menu
	cout << "\n****************************************************************************************\n";
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

	//Username
	string username;
	string password;
	cout << "\n\n****************************************************************************************\n";
	cout << "Please enter your username: ";
	cin.ignore();
	getline(cin, username);
	int match = 0;
	int matchFlag = 0;
	for (int i = 0; i < teachers.size(); i++) {
		if (username == teachers[i].username) {
			matchFlag++;
			match = i;
		}
	}
	if (matchFlag == 1) {
		cout << "Please enter your password: ";
		getline(cin, password);
	}
	else if (matchFlag > 1) {
		cout << ">>Error. Multiple accounts detected. Please contact the administrator to resolve this issue<<\nYou may attempt to log in regardless. Please enter your password: ";
		cout << "Please enter your password: ";
		getline(cin, password);
	}
	else {
		cout << "\n>>No user found with that name.<< Enter a selection:\n\n\t1. Attempt to log in again\n\n\t2. Register an account\n\n\t3. Return to Main Menu\n\n";
		string reenterUserMenu;
		cin >> reenterUserMenu;
		int reenterUserMenuFlag = 0;
		while (reenterUserMenuFlag == 0) {
			if (reenterUserMenu == "1") {
				reenterUserMenuFlag++;
				teacherLogin(&children, &teachers, &parents, &admin);
			}
			else if (reenterUserMenu == "2") {
				reenterUserMenuFlag++;
				teacherRegister(&children, &teachers, &parents, &admin);
			}
			else if (reenterUserMenu == "3") {
				reenterUserMenuFlag++;
				mainMenu(&children, &teachers, &parents, &admin);
			}
			else {
				cout << "Sorry, that wasn't one of the options. Make sure you're only including the >>number<<";
				cin >> reenterUserMenu;
			}
		}
	}

	//Password
	if (password == teachers[match].password) {
		cout << "\n****************************************************************************************\n";
		cout << "\nWelcome " << teachers[match].title << " " << teachers[match].lastName << ", you are now logged in.";
		teacherMenu(&children, &teachers, &parents, &admin, teachers[match]);
	}
	else {
		cout << "\nThat password doesn't match our files. Two attempts remain.\nPlease enter your password.";
		cin.ignore();
		getline(cin, password);
		if (password == teachers[match].password) {
			cout << "\nWelcome " << teachers[match].title << " " << teachers[match].lastName << ", you are now logged in.";
			teacherMenu(&children, &teachers, &parents, &admin, teachers[match]);
		}
		else {
			cout << "\nThat password doesn't match our files. One attempt remains.\nPlease enter your password.";
			cin.ignore();
			getline(cin, password);
			if (password == teachers[match].password) {
				cout << "\nWelcome " << teachers[match].title << " " << teachers[match].lastName << ", you are now logged in.";
				teacherMenu(&children, &teachers, &parents, &admin, teachers[match]);
			}
			else {
				cout << "\nThat password doesn't match our files. This account has now been locked for one hour. Please contact the administrator.\nEnter 1 to return to Main Menu ";//Per the assessment brief, we have included this notification, but the 1 hr lockout is not implemented
				cin >> password;//"Enter 1" is an instruction that works, but entering anything and pressing enter will work. This input exists to hold the program here while they read the alert above before outputting the main menu again.
				mainMenu(&children, &teachers, &parents, &admin);
			}
		}
	}
}

void adminLogin(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a) {
	vector<Child> children = *c;
	vector<Teacher> teachers = *t;
	vector<Parent> parents = *p;
	Admin admin = *a;

	//Username
	string username;
	string password;
	cout << "\n****************************************************************************************\n";
	cout << "Please enter your username: ";
	cin.ignore();
	getline(cin, username);
	if (username == admin.username) {
		cout << "Please enter your password: ";
		getline(cin, password);
	}
	else {
		cout << "\nNo user found with that name. Enter a selection:\n\n\t1. Attempt to log in again\n\n\t2. Return to Main Menu\n\n";
		string reenterUserMenu;
		cin >> reenterUserMenu;
		int reenterUserMenuFlag = 0;
		while (reenterUserMenuFlag == 0) {
			if (reenterUserMenu == "1") {
				reenterUserMenuFlag++;
				adminLogin(&children, &teachers, &parents, &admin);
			}
			else if (reenterUserMenu == "2") {
				reenterUserMenuFlag++;
				mainMenu(&children, &teachers, &parents, &admin);
			}
			else {
				cout << "Sorry, that wasn't one of the options. Make sure you're only including the number.";
				cin >> reenterUserMenu;
			}
		}
	}

	//Password
	if (password == admin.password) {
		cout << "\nWelcome " << admin.username << ", you are now logged in.";
		adminMenu(c, t, p, &admin);
	}
	else {
		cout << "\nThat password doesn't match our files. Two attempts remain.\nPlease enter your password.";
		cin.ignore();
		getline(cin, password);
		if (password == admin.password) {
			cout << "\nWelcome " << admin.username << ", you are now logged in.";
			adminMenu(c, t, p, &admin);
		}
		else {
			cout << "\nThat password doesn't match our files. One attempt remains.\nPlease enter your password.";
			cin.ignore();
			getline(cin, password);

		}
		if (password == admin.password) {
			cout << "\nWelcome " << admin.username << ", you are now logged in.";
			adminMenu(c, t, p, &admin);
		}
		else {
			cout << "\nThat password doesn't match our files. This account has now been locked for one hour.\nEnter 1 to return to Main Menu ";//Per the assessment brief, we have included this notification, but the 1 hr lockout is not implemented
				cin >> password;//"Enter 1" is an instruction that works, but entering anything and pressing enter will work. This input exists to hold the program here while they read the alert above before outputting the main menu again.
			mainMenu(&children, &teachers, &parents, &admin);
		}
	}
}

void parentLogin(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a) {
	vector<Child> children = *c;
	vector<Teacher> teachers = *t;
	vector<Parent> parents = *p;
	Admin admin = *a;

	//Username
	string username;
	string password; 
	cout << "\n****************************************************************************************\n";
	cout << "\nPlease enter your username: ";
	cin.ignore();
	getline(cin, username);
	int match = 0;
	int matchFlag = 0;
	for (int i = 0; i < parents.size(); i++) {
		if (username == parents[i].username) {
			matchFlag++;
			match = i;
		}
	}
	if (matchFlag == 1) {
		cout << "\nPlease enter your password: ";
		getline(cin, password);
	}
	else if (matchFlag > 1) {
		cout << "\n>>Error. Multiple accounts detected. Please contact the administrator to resolve this issue<<\nYou may attempt to log in regardless. Please enter your password: ";
		cout << "\nPlease enter your password: ";
		getline(cin, password);
	}
	else {
		cout << "\nNo user found with that name. Enter a selection:\n\n\t1. Attempt to log in again\n\n\t2. Register an account\n\n\t3. Return to Main Menu\n\n";
		string reenterUserMenu;
		cin >> reenterUserMenu;
		int reenterPassMenuFlag = 0;
		while (reenterPassMenuFlag == 0) {
			if (reenterUserMenu == "1") {
				reenterPassMenuFlag++;
				parentLogin(&children, &teachers, &parents, &admin);
			}
			else if (reenterUserMenu == "2") {
				reenterPassMenuFlag++;
				parentRegister(&children, &teachers, &parents, &admin);
			}
			else if (reenterUserMenu == "1") {
				reenterPassMenuFlag++;
				mainMenu(&children, &teachers, &parents, &admin);
			}
			else {
				cout << "Sorry, that wasn't one of the options. Make sure you're only including the number.";
				cin >> reenterUserMenu;
			}
		}
	}

	//Password
	if (password == parents[match].password) {
		cout << "\nWelcome " << parents[match].title << " " << parents[match].lastName << ", you are now logged in.";
		//PARENTS MENU HERE
	}
	else {
		cout << "\nThat password doesn't match our files. Two attempts remain.\nPlease enter your password.";
		cin.ignore();
		getline(cin, password);
		if (password == parents[match].password) {
			cout << "\nWelcome " << parents[match].title << " " << parents[match].lastName << ", you are now logged in.";
			//PARENTS MENU HERE
		}
		else {
			cout << "\nThat password doesn't match our files. One attempt remains.\nPlease enter your password.";
			cin.ignore();
			getline(cin, password);
			if (password == parents[match].password) {
				cout << "\nWelcome " << parents[match].title << " " << parents[match].lastName << ", you are now logged in.";
				//PARENTS MENU HERE
			}
			else {
				cout << "\nThat password doesn't match our files. This account has now been locked for one hour. Please contact the administrator";//Per the assessment brief, we have included this notification, but the 1 hr lockout is not implemented
				cin >> password;//"Enter 1" is an instruction that works, but entering anything and pressing enter will work. This input exists to hold the program here while they read the alert above before outputting the main menu again.
				mainMenu(c, t, &parents, a);
			}
		}
	}
}

void whichRegister(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a) {
	vector<Child> children = *c;
	vector<Teacher> teachers = *t;
	vector<Parent> parents = *p;
	Admin admin = *a;

	//Registration Menu
	cout << "\n****************************************************************************************\n";
	string menu = "0";
	while (menu != "1" && menu != "2") {
		cout << "\nWhat kind of account are you registering?\n\n\n\t1. Teacher\n\n\t2. Parent\n\n";
		cin >> menu;
		if (menu == "1") {
			teacherRegister(&children, &teachers, &parents, &admin);
		}
		else if (menu == "2") {
			parentRegister(&children, &teachers, &parents, &admin);
		}
		else {
			cout << "\nSorry, that wasn't one of the options. Make sure you're only including the number.";
		}
	}
}


void teacherRegister(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a) {
	vector<Child> children = *c;
	vector<Teacher> teachers = *t;
	vector<Parent> parents = *p;
	Admin admin = *a;

	//Register Teacher Record
	Teacher registrant;
	cout << "\n****************************************************************************************\n";
	cout << "\nPlease enter your first name(s): ";
	cin.ignore();
	getline(cin, registrant.firstName);
	cout << "\nPlease enter your last name(s): ";
	getline(cin, registrant.lastName);
	cout << "\nPlease enter your preferred title: (Mr, Miss, Mx, Dr. etc) ";
	getline(cin, registrant.title);
	cout << "\nPlease enter your preferred name: ";
	getline(cin, registrant.preferredName);
	cout << "\nPlease enter your pronouns: ";
	getline(cin, registrant.pronouns);
	cout << "\nPlease enter your gender: ";
	getline(cin, registrant.gender);
	cout << "\nPlease enter your date of birth: ";
	getline(cin, registrant.DOB);
	cout << "\nPlease enter your email: ";
	getline(cin, registrant.email);
	//Email Validation - is there at least one @ symbol?
	int emailFlag = 0;
	while (emailFlag == 0) {
		for (int i = 0; i < registrant.email.length(); i++) {
			if (registrant.email[i] == '@') {
				emailFlag = 1;
			}
		}
		if (emailFlag == 0) {
			cout << ">>Error. Emails must include '@' symbol. Please re-enter your email<< ";
			getline(cin, registrant.email);
		}
	}
	cout << "\nPlease enter your contact number: ";
	getline(cin, registrant.Ph);
	cout << "\nPlease enter the classroom you'll be working in (e.g. 201, 105): ";
	getline(cin, registrant.classroom);
	cout << "\nPlease enter the year you'll be teaching: ";
	getline(cin, registrant.year);
	cout << "\nPlease enter choose a username: ";
	getline(cin, registrant.username);
	//Check if that username is taken
	int usernameAvailableFlag = 0;
	if (teachers.size() > 0) {//Prevents this code from running on initial registration
		while (usernameAvailableFlag == 0) {
			int subFlag = 0;
			for (int i = 0; i < teachers.size(); i++) {
				if (registrant.username == teachers[i].username) {
					subFlag++;
				}
			}
			if (subFlag != 0) {
				cout << "Sorry, that username has already been taken.";
				cout << "Please enter choose a username: ";
				getline(cin, registrant.username);
			}
			else {
				usernameAvailableFlag++;
			}
		}
	}
	cout << "\nPlease enter choose a password - include a number, uppercase letter, lowercase letter and a special symbol (neither a letter nor a number): ";
	getline(cin, registrant.password);
	//Password Validation
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
			cout << ">>Error. Passwords must be 8 or more characters, including upper and lower case letters, numbers, and non-alphanumeric symbols. Please enter a valid password<< ";
			getline(cin, registrant.password);
		}
	}
	//Password Confirmation
	while (registrant.confirmPassword != registrant.password) {
		cout << "\nPlease confirm your password: ";
		getline(cin, registrant.confirmPassword);
		if (registrant.confirmPassword != registrant.password) {
			cout << "\nPasswords do not match. ";
		}
	}

	//Writing to File
	fstream TeacherList("Teachers.csv", ios::app);//Open file
	//Write registrant details into teacher file:
	TeacherList << registrant.firstName << "," << registrant.lastName << "," << registrant.title << "," << registrant.preferredName << "," << registrant.gender << "," << registrant.pronouns << "," << registrant.DOB << "," << registrant.email << "," << registrant.Ph << "," << registrant.classroom << "," << registrant.year << "," << registrant.username << "," << registrant.password << endl;
	TeacherList.close();//Close file

	//Register another?
	string another = "0";
	while (another != "1" && another != "2") {
		cout << "\nRegister another teacher? Enter 1 to do so or 2 to return to the main menu.";
		cin >> another;
		if (another == "1") {
			teacherRegister(&children, &teachers, &parents, &admin);
		}
		else if (another == "2") {
			mainMenu(&children, &teachers, &parents, &admin);
		}
	}
}

void parentRegister(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a) {
	vector<Child> children = *c;
	vector<Teacher> teachers = *t;
	vector<Parent> parents = *p;
	Admin admin = *a;

	//Register Parent Record 
	Parent registrant;
	cout << "\n****************************************************************************************\n";
	cout << "\nWelcome to the parent registration form. Please note each child can only have one account, and each account can only have one child - if you have multiple children at the school you will have to register a parent's account for each one.";
	cin.ignore();
	//Confirm child identity
	int childFoundFlag = 0;
	int match = 0;
	string menu = "0";
	while (childFoundFlag != 1) {
		cout << "\nPlease enter the first name(s) of your child: ";
		getline(cin, registrant.childFirstName);
		cout << "\nPlease enter the last name(s) of your child: ";
		getline(cin, registrant.childLastName);
		cout << "\nPlease enter your child's classroom (eg 201, 105): ";
		getline(cin, registrant.classroom);
		for (int i = 0; i < children.size(); i++) {
			if (children[i].firstName == registrant.childFirstName && children[i].lastName == registrant.childLastName && children[i].classroom == registrant.classroom) {
				childFoundFlag++;
				match = i;
			}
		}
		if (childFoundFlag == 0) {
			cout << "No student found with those names in the given classroom.";
			while (menu != "1" && menu != "2") {
				cout << "Enter 1 to retry or 2 to return to main menu.";
				cin >> menu;
				if (menu == "2") {
					mainMenu(&children, &teachers, &parents, &admin);
				}
				else if (menu != "1") {
					cout << ">>Error. Please enter only the number 1 or 2.<<";
				}
			}
		}
		else if (childFoundFlag > 1) {
			cout << ">>Error. Multiple records found in this class with that name. Please contact the administrator\n";
			menu = "0";
			while (menu != "1" && menu != "2") {
				cout << "Enter 1 to retry or 2 to return to the main menu.";
				cin >> menu;
				if (menu == "2") {
					mainMenu(&children, &teachers, &parents, &admin);
				}
				else if (menu != "1") {
					cout << ">>Error. Please enter only the number 1 or 2.<<";
				}
			}
		}
		else {
			cin.ignore();
			cout << "\nPlease enter your first name(s): ";
			getline(cin, registrant.firstName);
			cout << "\nPlease enter your last name(s): ";
			getline(cin, registrant.lastName);
			cout << "\nPlease enter your preferred title: (Mr. Mx. Dr. Miss etc) ";
			getline(cin, registrant.title);
			cout << "\nPlease enter your preferred name: ";
			getline(cin, registrant.preferredName);
			cout << "\nPlease enter your pronouns: ";
			getline(cin, registrant.pronouns);
			cout << "\nPlease enter your gender: ";
			getline(cin, registrant.gender);
			cout << "\nPlease enter your date of birth: ";
			getline(cin, registrant.DOB);
			cout << "\nPlease enter your email: ";
			getline(cin, registrant.email);
			//Email Validation
			int emailFlag = 0;
			while (emailFlag == 0) {
				for (int i = 0; i < registrant.email.length(); i++) {
					if (registrant.email[i] == '@') {
						emailFlag = 1;
					}
				}
				if (emailFlag == 0) {
					cout << ">>Error. Emails must include '@' symbol. Please re-enter your email<< ";
					getline(cin, registrant.email);
				}
			}
			cout << "\nPlease enter your contact number: ";
			getline(cin, registrant.Ph);
			cout << "\nPlease enter a daytime contact number to use in emergencies: ";
			getline(cin, registrant.emergencyPh);
			cout << "\nPlease enter choose a username: ";
			getline(cin, registrant.username);
			//Check if that username is taken
			int usernameAvailableFlag = 0;
			if (parents.size() > 0) {// Prevents this code from running on initial registration
				while (usernameAvailableFlag == 0) {
					int subFlag = 0;
					for (int i = 0; i < parents.size(); i++) {
						if (registrant.username == parents[i].username) {
							subFlag++;
						}
					}
					if (subFlag != 0) {
						cout << "Sorry, that username has already been taken.";
						cout << "Please enter choose a username: ";
						getline(cin, registrant.username);
					}
					else {
						usernameAvailableFlag++;
					}
				}
			}
			cout << "\nPlease enter choose a password - include a number, uppercase letter, lowercase letter and a special symbol (neither a letter nor a number): ";
			getline(cin, registrant.password);
			//Password Validation
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
					cout << ">>Error. Passwords must be 8 or more characters, including upper and lower case letters, numbers, and non-alphanumeric symbols. Please enter a valid password<< ";
					getline(cin, registrant.password);
				}
			}
			//Password Confirmation
			while (registrant.confirmPassword != registrant.password) {
				cout << "\nPlease confirm your password: ";
				getline(cin, registrant.confirmPassword);
				if (registrant.confirmPassword != registrant.password) {
					cout << "\nPasswords do not match. ";
				}
			}

			//Assign ID Number, checking that it is not already in use
			srand(time(NULL));
			int id = 0;
			while (registrant.ID == 0) {
				id = rand();
				int IDFlag = 0;
				for (int i = 0; i < parents.size(); i++) {
					if (parents[i].ID == id) {
						IDFlag++;
					}
				}
				if (IDFlag == 0) {
					children[match].parent = id;
					registrant.ID = id;
				}
			}
			
			//Writing to File
			fstream ParentList("Parents.csv", ios::app);//Open file
			//Write registrant details into teacher file
			ParentList << registrant.firstName << "," << registrant.lastName << "," << registrant.title << "," << registrant.preferredName << "," << registrant.gender << "," << registrant.pronouns << "," << registrant.DOB << "," << registrant.email << "," << registrant.Ph << "," << registrant.emergencyPh << "," << registrant.childFirstName << "," << registrant.childLastName << "," << registrant.classroom << "," << registrant.username << "," << registrant.password << "," << registrant.ID << endl;
			ParentList.close();//Close file
			parents = readParents();//rereads file to use updated info

			//Rewriting children file to include ID
			fstream Classroom("201.csv", ios::out);
			for (int i = 0; i < children.size(); i++) {//This completely overwrites the file, presevering the data in order with no gap where the deleted record was
				Classroom << children[i].firstName << "," << children[i].lastName << "," << children[i].preferredName << "," << children[i].gender << "," << children[i].pronouns << "," << children[i].DOB << "," << children[i].classroom << "," << children[i].maths << "," << children[i].science << "," << children[i].reading << "," << children[i].writing << "," << children[i].others << endl;
				Classroom.close();//Close file
			}
			children = readChildren201();//rereads file to use updated info

			//Register another?
			string another = "0";
			while (another != "1" && another != "2") {
				cout << "\nRegister another parent's account? Enter 1 to do so or 2 to return to the main menu.";
				cin >> another;
				if (another == "1") {
					parentRegister(&children, &teachers, &parents, &admin);
				}
				else if (another == "2") {
					mainMenu(&children, &teachers, &parents, &admin);
				}
			}
		}
	}
}

void childRegister(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a) {
	vector<Child> children = *c;
	vector<Teacher> teachers = *t;
	vector<Parent> parents = *p;
	Admin admin = *a;

	//Register Child Record
	cout << "\n****************************************************************************************\n";
	Child registrant;
	cout << "\nPlease enter the student's name(s): ";
	cin.ignore();
	getline(cin, registrant.firstName);
	cout << "\nPlease enter the student's last name(s): ";
	getline(cin, registrant.lastName);
	cout << "\nPlease enter the student's preferred name: ";
	getline(cin, registrant.preferredName);
	cout << "\nPlease enter the student's pronouns: ";
	getline(cin, registrant.pronouns);
	cout << "\nPlease enter the student's date of birth: ";
	getline(cin, registrant.DOB);
	cout << "\nPlease enter the classroom for this student: ";
	getline(cin, registrant.classroom);
	cout << "\nPlease enter the maths results (if known): ";
	getline(cin, registrant.maths);
	cout << "\nPlease enter the science results (if known): ";
	getline(cin, registrant.science);
	cout << "\nPlease enter the reading results (if known): ";
	getline(cin, registrant.reading);
	cout << "\nPlease enter the writing results (if known): ";
	getline(cin, registrant.writing);
	cout << "\nPlease enter the average across other results (if known): ";
	getline(cin, registrant.others);
	//Learning Progress - We take this via a number and write it in plain text to make it guaranteed consistent for the admin report to sleect them all
	string progress = "0";
	while (progress != "1" && progress != "2" && progress != "3") {
		cout << "\nPlease enter the current overall learning progress (if known). Enter 1 for Achieved, 2 for Progressing, or 3 for Needs Help: ";
		cin >> progress;
		if (progress == "1") {
			registrant.progress = "Achieved";
		}
		else if (progress == "2") {
			registrant.progress = "Progressing";
		}
		else if (progress == "3") {
			registrant.progress = "Needs Help";
		}
		else {
			cout << ">>Error. Please type only the number 1, 2, or 3 and press enter<< \n";
		}
	}

	//Writing to File
	fstream Classroom("201.csv", ios::app);//For this assessment, in consultation with our tutor Beula, we have hardcoded a single class file. If we had a real school with defined classrooms we would code a function to write to each of the rooms and create and if/else if/else statement that ran the correct function using the filename that matches the relevant classroom.
	//Write registrant details into teacher file:
	Classroom << registrant.firstName << "," << registrant.lastName << ","  << registrant.preferredName << "," << registrant.gender << "," << registrant.pronouns << "," << registrant.DOB << "," << registrant.classroom << "," << registrant.maths << "," << registrant.science << "," << registrant.reading << "," << registrant.writing << "," << registrant.others << endl;
	Classroom.close();//Close file

	//Register another?
	string another = "0";
	while (another != "1" && another != "2") {
		cout << "\nRegister another teacher? Enter 1 to do so or 2 to return to the main menu. ";
		cin >> another;
		if (another == "1") {
			teacherRegister(&children, &teachers, &parents, &admin);
		}
		else if (another == "2") {
			mainMenu(&children, &teachers, &parents, &admin);
		}
	}
}

void teacherMenu(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a, Teacher currentAccount) {
	vector<Child> children = *c;
	vector<Teacher> teachers = *t;
	vector<Parent> parents = *p;
	Admin admin = *a;
	string menu = "0";
	//CONTINUE BUILDING
	while (menu != "1" && menu != "2") {
		cout << "\nWhat would you like to do?\n\n\n\t1. Update one of your student's grades\n\n\t2. View one of your student's records\n\n\t3. ";
	}
	updateGrades(&children, &teachers, &parents, &admin, currentAccount);
}

void updateGrades(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a, Teacher currentAccount) {
	vector<Child> children = *c;
	vector<Teacher> teachers = *t;
	vector<Parent> parents = *p;
	Admin admin = *a;
	string firstName;
	string lastName;
	Child updatee;
	cout << "\nPlease enter the student's first name(s): ";
	cin.ignore();
	getline(cin, firstName);
	cout << "\nPlease enter the student's last name(s): ";
	getline(cin, lastName);
	int childFoundFlag = 0;
	int match = 0;
	for (int i = 0; i < children.size(); i++) {
		if (children[i].firstName == firstName && children[i].lastName == lastName && children[i].classroom == currentAccount.classroom) {
			childFoundFlag++;
			match = i;
		}
	}
	string menu = "0";
	if (childFoundFlag == 0) {
		cout << "No student found with those names.";
		while (menu != "1" && menu != "2") {
			cout << "Enter 1 to retry or 2 to return to your menu.";
			cin >> menu;
			if (menu == "1") {
				updateGrades(&children, &teachers, &parents, &admin, currentAccount);
			}
			else if (menu == "2") {
				teacherMenu(&children, &teachers, &parents, &admin, currentAccount);
			}
			else {
				">>Error. Please enter only 1 or 2. ";
			}
		}
	}
	else if (childFoundFlag > 1) {
		cout << ">>Error. Multiple records found in this class with that name. Please contact administrator.\n";
		menu = "0";
		while (menu != "1" && menu != "2") {
			cout << "Enter 1 to retry or 2 to return to your menu.";
			cin >> menu;
			if (menu == "1") {
				updateGrades(&children, &teachers, &parents, &admin, currentAccount);
			}
			else if (menu == "2") {
				teacherMenu(&children, &teachers, &parents, &admin, currentAccount);
			}
			else {
				cout << ">>Error. Please enter only the number 1 or 2. ";
			}
		}
	}
	else {
		cout << "\nPlease enter the maths results: ";
		getline(cin, children[match].maths);
		cout << "\nPlease enter the science results: ";
		getline(cin, children[match].science);
		cout << "\nPlease enter the reading results: ";
		getline(cin, children[match].reading);
		cout << "\nPlease enter the writing results: ";
		getline(cin, children[match].writing);
		cout << "\nPlease enter the average across other results: ";
		getline(cin, children[match].others);
		//Learning Progress
		string progress = "0";
		while (progress != "1" && progress != "2" && progress != "3") {
			cout << "Please enter the current overall learning progress. Enter 1 for Achieved, 2 for Progressing, or 3 for Needs Help: ";
			cin >> progress;
			if (progress == "1") {
				children[match].progress = "Achieved";
			}
			else if (progress == "2") {
				children[match].progress = "Progressing";
			}
			else if (progress == "3") {
				children[match].progress = "Needs Help";
			}
			else {
				cout << ">>Error. Please type only the number 1, 2, or 3 and press enter<<\n";
			}
		}

		//Writing to File
		fstream Classroom("201.csv", ios::out);//For this assessment, with the blessing of our tutor Beula, we have hardcoded a single class file. If we had a real school with defined classrooms I would code a function to write to each of the rooms and create and if/else if/else statement that ran the function using the filename that matches the relevant classroom, selected from currentAccount.classroom.
		//Write registrant details into teacher file:
		for (int i = 0; i < children.size(); i++) {//This completely overwrites the file, presevering the data in order with the new grade
			Classroom << children[i].firstName << "," << children[i].lastName << "," << children[i].preferredName << "," << children[i].gender << "," << children[i].pronouns << "," << children[i].DOB << "," << children[i].classroom << "," << children[i].maths << "," << children[i].science << "," << children[i].reading << "," << children[i].writing << "," << children[i].others << endl;
			Classroom.close();//Close file
		}
		children = readChildren201();
				cout << "Please enter 1 to update another student's grades or 2 to return to your menu.";
		menu = "0";
		while (menu != "1" && menu != "2") {
			cout << "Please enter 1 to update another student's grades or 2 to return to your menu.";
			cin >> menu;
			if (menu == "1") {
				updateGrades(&children, &teachers, &parents, &admin, currentAccount);
			}
			else if (menu == "2") {
				teacherMenu(&children, &teachers, &parents, &admin, currentAccount);
			}
			else {
				cout << ">>Error. Please enter only the number 1 or 2. ";
			}
		}
	}
}

void adminMenu(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a) {
	string menu = "0";
	while (menu != "1" && menu != "2") {
		cout << "Please select one of the following by entering its number:\n\n\n\t1. Create a new student record\n\n\t2. Update a student record\n\n\t3. Delete a student record\n\n\t4. View a student record\n\n\t5. View a parent record\n\n\t6. View a list of students at a certain level of learning progress.\n\n\nEnter your selection: ";
		cin >> menu;
		if (menu == "1") {
			childRegister(c, t, p, a);
		}
		else if (menu == "2") {
			updateChild(c, t, p, a);
		}
		else if (menu == "3") {
			deleteChild(c, t, p, a);
		}
		else if (menu == "4") {
			
		}
		else if (menu == "5") {

		}
		else if (menu == "6") {

		}
		else {

		}
	}
}
void updateChild(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a) {
	vector<Child> children = *c;
	vector<Teacher> teachers = *t;
	vector<Parent> parents = *p;
	Admin admin = *a;
	string firstName;
	string lastName;
	string classroom;
	Child updatee;

	//Select a student's record
	cin.ignore();
	cout << "\nPlease enter the student's current first name(s): ";
	getline(cin, firstName);
	cout << "\nPlease enter the student's current last name(s): ";
	getline(cin, lastName);
	cout << "\nPlease enter the student's current classroom: ";
	getline(cin, classroom);
	int childFoundFlag = 0;
	int match = 0;
	for (int i = 0; i < children.size(); i++) {
		if (children[i].firstName == firstName && children[i].lastName == lastName && children[i].classroom == classroom) {
			childFoundFlag++;
			match = i;
		}
	}
	string menu = "0";
	if (childFoundFlag == 0) {
		cout << "No student found with those names in the given classroom.";
		while (menu != "1" && menu != "2") {
			cout << "Enter 1 to retry or 2 to return to your menu.";
			cin >> menu;
			if (menu == "1") {
				updateChild(&children, &teachers, &parents, &admin);
			}
			else if (menu == "2") {
				adminMenu(&children, &teachers, &parents, &admin);
			}
			else {
				">>Error. Please enter only 1 or 2. ";
			}
		}
	}
	else if (childFoundFlag > 1) {
		cout << ">>Error. Multiple records found in this class with that name. Administrator repairs required: examine files and delete duplicates.\n";
		menu = "0";
		while (menu != "1" && menu != "2") {
			cout << "Enter 1 to retry or 2 to return to your menu.";
			cin >> menu;
			if (menu == "1") {
				updateChild(&children, &teachers, &parents, &admin);
			}
			else if (menu == "2") {
				adminMenu(&children, &teachers, &parents, &admin);
			}
			else {
				cout << ">>Error. Please enter only the number 1 or 2. ";
			}
		}
	}
	else {
		//Updating record
		bool update = askUpdate("first name");
		if (update == true) {
			cout << "\nPlease enter the student's new first name(s): ";
			getline(cin, updatee.firstName);
		}
		update = askUpdate("last name");
		if (update == true) {
			cout << "\nPlease enter the student's new last name(s): ";
			getline(cin, updatee.lastName);
		}
		update = askUpdate("preferred name");
		if (update == true) {
			cout << "\nPlease enter the student's new preferred name: ";
			getline(cin, updatee.preferredName);
		}
		update = askUpdate("pronouns");
		if (update == true) {
			cout << "\nPlease enter the student's new pronouns: ";
			getline(cin, updatee.pronouns);
		}
		update = askUpdate("date of birth");
		if (update == true) {
			cout << "\nPlease enter the student's new pronouns: ";
			getline(cin, updatee.DOB);
		}
		update = askUpdate("classroom");
		if (update == true) {
			cout << "\nPlease enter the student's new pronouns: ";
			getline(cin, updatee.classroom);
		}
		update = askUpdate("marks for maths");
		if (update == true) {
			cout << "\nPlease enter the new maths results (if known): ";
			getline(cin, updatee.maths);
		}
		update = askUpdate("marks for science");
		if (update == true) {
			cout << "\nPlease enter the new science results (if known): ";
			getline(cin, updatee.science);
		}
		update = askUpdate("marks for reading");
		if (update == true) {
			cout << "\nPlease enter the new reading results (if known): ";
			getline(cin, updatee.reading);
		}
		update = askUpdate("marks for writing");
		if (update == true) {
			cout << "\nPlease enter the new writing results (if known): ";
			getline(cin, updatee.writing);
		}
		update = askUpdate("marks for other subjects");
		if (update == true) {
			cout << "\nPlease enter the new average across other results (if known): ";
			getline(cin, updatee.others);
		}
		update = askUpdate("learning Progress");
		if (update == true) {
			//Learning Progress
			string progress = "0";
			while (progress != "1" && progress != "2" && progress != "3") {
				cout << "\nPlease enter the current overall learning progress. Enter 1 for Achieved, 2 for Progressing, or 3 for Needs Help: ";
				cin >> progress;
				if (progress == "1") {
					updatee.progress = "Achieved";
				}
				else if (progress == "2") {
					updatee.progress = "Progressing";
				}
				else if (progress == "3") {
					updatee.progress = "Needs Help";
				}
				else {
					cout << ">>Error. Please type only the number 1, 2, or 3 and press enter<<\n";
				}
			}
		}
		children[match] = updatee;
		//Writing to File
		fstream Classroom("201.csv", ios::out);
		for (int i = 0; i < children.size(); i++) {//This completely overwrites the file, presevering the data in order with the new infotmation
			Classroom << children[i].firstName << "," << children[i].lastName << "," << children[i].preferredName << "," << children[i].gender << "," << children[i].pronouns << "," << children[i].DOB << "," << children[i].classroom << "," << children[i].maths << "," << children[i].science << "," << children[i].reading << "," << children[i].writing << "," << children[i].others << endl;
			Classroom.close();//Close file
		}
		children = readChildren201();
	}
	menu = "0";
	while (menu != "1" && menu != "2") {
		cout << "Enter 1 to update another child's records or 2 to return to your menu.";
		cin >> menu;
		if (menu == "1") {
			updateChild(&children, &teachers, &parents, &admin);
		}
		else if (menu == "2") {
			adminMenu(&children, &teachers, &parents, &admin);
		}
		else {
			cout << ">>Error. Please enter only the number 1 or 2. ";
		}
	}
}

void deleteChild(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a) {
	vector<Child> children = *c;
	vector<Teacher> teachers = *t;
	vector<Parent> parents = *p;
	Admin admin = *a;

	//Determine which child's records to delete
	string firstName;
	string lastName;
	string classroom;
	cin.ignore();
	cout << "\nDelete Record\nPlease enter the student's current first name(s): ";
	getline(cin, firstName);
	cout << "\nPlease enter the student's current last name(s): ";
	getline(cin, lastName);
	cout << "\nPlease enter the student's current classroom: ";
	getline(cin, classroom);
	int childFoundFlag = 0;
	int match = 0;
	for (int i = 0; i < children.size(); i++) {
		if (children[i].firstName == firstName && children[i].lastName == lastName && children[i].classroom == classroom) {
			childFoundFlag++;
			match = i;
		}
	}
	string menu = "0";
	if (childFoundFlag == 0) {
		cout << "No student found with those names in the given classroom.";
		while (menu != "1" && menu != "2") {
			cout << "Enter 1 to retry or 2 to return to your menu.";
			cin >> menu;
			if (menu == "1") {
				deleteChild(&children, &teachers, &parents, &admin);
			}
			else if (menu == "2") {
				adminMenu(&children, &teachers, &parents, &admin);
			}
			else {
				">>Error. Please enter only 1 or 2. ";
			}
		}
	}
	else if (childFoundFlag > 1) {
		cout << ">>Error. Multiple records found in this class with that name. Administrator repairs required: examine files and delete duplicates.\n";
		menu = "0";
		while (menu != "1" && menu != "2") {
			cout << "Enter 1 to retry or 2 to return to your menu.";
			cin >> menu;
			if (menu == "1") {
				deleteChild(&children, &teachers, &parents, &admin);
			}
			else if (menu == "2") {
				adminMenu(&children, &teachers, &parents, &admin);
			}
			else {
				cout << ">>Error. Please enter only the number 1 or 2. ";
			}
		}
	}
	else {
		//Confirm Deletion
		cout << "\nRecord found. Are you sure you wish to delete all data stored regarding this child? data? Enter 1 to confirm or 2 to cancel.";
		menu = "0";
		while (menu != "1" && menu != "2") {
			cin >> menu;
			if (menu == "1") {
				children.erase(children.begin() + match);
				//Writing to File
				fstream Classroom("201.csv", ios::out);
				for (int i = 0; i < children.size(); i++) {//This completely overwrites the file, presevering the data in order with no gap where the deleted record was
					Classroom << children[i].firstName << "," << children[i].lastName << "," << children[i].preferredName << "," << children[i].gender << "," << children[i].pronouns << "," << children[i].DOB << "," << children[i].classroom << "," << children[i].maths << "," << children[i].science << "," << children[i].reading << "," << children[i].writing << "," << children[i].others << endl;
					Classroom.close();//Close file
				}
				children = readChildren201();
				cout << "Record successfully deleted.";
				adminMenu(&children, &teachers, &parents, &admin);
			}
			else if (menu == "2") {
				adminMenu(&children, &teachers, &parents, &admin);
			}
			else {
				cout << ">>Error. Enter only 1 (to delete) or 2 (to cancel)<<";
			}
		}
	}
}

bool askUpdate(string field) {
	cout << "\nWould you like to update the student's " << field << "?";

	string answer;
	while (answer != "1" && answer != "2") {
		cout << "\nEnter 1 to update or 2 to leave this data as is.";
		cin >> answer;
		if (answer == "1") {
			return true;
		}
		else if (answer == "2") {
			return false;
		}
		else {
			cout << ">>Error. Please only type the number, then press enter<<";
		}
	}
}

//Functions Still Needed
	//Parent - see child's report
	//Parent - see school notices
	//Admin - see report of progressing students
	//Admin - see report of students who need help "The report should include, classroom number, student full name, learning progress of each subject, teacher nameand their parents contact number."

//Design menus nicely - headings, colours, dividing lines
	//Include cancel options to avoid trapping users
	//Include a "register/update another? prompt where approriate"
	//Include better explanations of input formats (eg classroom numbers) and conditions(eg no two students in the same class with the same name)
	//Maybe output all extant classrooms for classroom questions to help epople select the one? Or make a selection menu with an add a class option? Worth noting Beula says we only need one classroom as a proof of concept
	//Add support for siblings and multiple parents

//Other potential improvements
	//Pass only necessary vectors
	//Login as function? save some lines of code
	//give more options for admin to delete/edit files for parents/teachers