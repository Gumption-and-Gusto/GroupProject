//School Information System
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
void displayStudentRecordTeacher(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a, Teacher currentAccount);
void displayParentsRecordTeacher(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a, Teacher currentAccount);
void displayStudentRecordAdmin(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a, string room);
void displayParentsRecordAdmin(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a,  string room);
bool askUpdate(string field);
void displayProgressLevel(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a, string pl);
void parentMenu(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a, int currentID);
bool askUpdateParent(string field);

int main()
{	
	vector <Child> children = readChildren201();
	vector <Teacher> teachers = readTeachers();
	vector <Parent> parents = readParents();
	Admin admin;
	mainMenu(&children, &teachers, &parents, &admin);//I'm not sure that we'll actually need to pass these around all the time. I built it with these vectors in case but we may end up passing them a lot less
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
	while (menu != "1" && menu != "2" && menu != "3") {
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
			cout << ">>Error. That wasn't one of the options. Make sure you're only including the number<<\n";
		}
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
	string menu;
	while (menu != "1" && menu != "2" && menu != "3") {
		cin >> menu;
		if (menu == "1") {
			teacherLogin(&children, &teachers, &parents, &admin);
		}
		else if (menu == "2") {
			parentLogin(&children, &teachers, &parents, &admin);
		}
		else if (menu == "3") {
			adminLogin(&children, &teachers, &parents, &admin);
		}
		else {
			cout << ">>Error. That wasn't one of the options. Make sure you're only including the number.<<\n";
		}
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
		cout << "\n>>No user found with that name<<\n Enter a selection:\n\n\t1. Attempt to log in again\n\n\t2. Register an account\n\n\t3. Return to Main Menu\n\n";
		string menu = "0";
		while (menu != "1" && menu != "2" && menu != "3") {
			cin >> menu;
			if (menu == "1") {
				teacherLogin(&children, &teachers, &parents, &admin);
			}
			else if (menu == "2") {
				teacherRegister(&children, &teachers, &parents, &admin);
			}
			else if (menu == "3") {
				mainMenu(&children, &teachers, &parents, &admin);
			}
			else {
				cout << ">>Error. That wasn't one of the options. Make sure you're only including the number<<\n";
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
		string menu;
		while (menu != "1" && menu != "2") {
		cin >> menu;
			if (menu == "1") {
				adminLogin(&children, &teachers, &parents, &admin);
			}
			else if (menu == "2") {
				mainMenu(&children, &teachers, &parents, &admin);
			}
			else {
				cout << ">>Error. That wasn't one of the options. Make sure you're only including the number<<\n";
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
		string menu = "0";
		while (menu != "1" && menu != "2" && menu != "3") {
			cin >> menu;
			if (menu == "1") {
				parentLogin(&children, &teachers, &parents, &admin);
			}
			else if (menu == "2") {
				parentRegister(&children, &teachers, &parents, &admin);
			}
			else if (menu == "3") {
				mainMenu(&children, &teachers, &parents, &admin);
			}
			else {
				cout << ">>Error. That wasn't one of the options. Make sure you're only including the number<<\n";
			}
		}
	}

	//Password
	if (password == parents[match].password) {
		cout << "\nWelcome " << parents[match].title << " " << parents[match].lastName << ", you are now logged in.";
		parentMenu(&children, &teachers, &parents, &admin, parents[match].ID);
	}
	else {
		cout << "\nThat password doesn't match our files. Two attempts remain.\nPlease enter your password.";
		cin.ignore();
		getline(cin, password);
		if (password == parents[match].password) {
			cout << "\nWelcome " << parents[match].title << " " << parents[match].lastName << ", you are now logged in.";
			parentMenu(&children, &teachers, &parents, &admin, parents[match].ID);
		}
		else {
			cout << "\nThat password doesn't match our files. One attempt remains.\nPlease enter your password.";
			cin.ignore();
			getline(cin, password);
			if (password == parents[match].password) {
				cout << "\nWelcome " << parents[match].title << " " << parents[match].lastName << ", you are now logged in.";
				parentMenu(&children, &teachers, &parents, &admin, parents[match].ID);
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
		cout << "\nWhat kind of account are you registering?\n\n\n\t1. Teacher\n\n\t2. Parent\n\n\n";
		cin >> menu;
		if (menu == "1") {
			teacherRegister(&children, &teachers, &parents, &admin);
		}
		else if (menu == "2") {
			parentRegister(&children, &teachers, &parents, &admin);
		}
		else {
			cout << ">>Error. That wasn't one of the options. Make sure you're only including the number<<";
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
	cout << "\nPlease enter the classroom you'll be working in (e.g. 201): ";
	getline(cin, registrant.classroom);
	cout << "\nPlease enter the year you'll be teaching (eg year 9): ";
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
	while (passwordFlag == 0) {
	int upperFlag = 0;
	int lowerFlag = 0;
	int digitFlag = 0;
	int symbolFlag = 0;
	int symbolSubFlag = 0;
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
	teachers = readTeachers();

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
	cout << "\nWelcome to the parent registration form.\nPlease note each child can only have one account, and each account can only have one child.\nIf you have multiple children at the school you will have to register a parent's account for each one.\nIf you have co-carers who need access you will need to share the account with them.\n";
	//Confirm child identity
	int childFoundFlag = 0;
	int match = 0;
	string menu = "0";
	while (childFoundFlag != 1) {
	cin.ignore();
		cout << "\nPlease enter the first name(s) of your child: ";
		getline(cin, registrant.childFirstName);
		cout << "\nPlease enter the last name(s) of your child: ";
		getline(cin, registrant.childLastName);
		cout << "\nPlease enter your child's classroom (eg 201): ";
		getline(cin, registrant.classroom);
		for (int i = 0; i < children.size(); i++) {
			if (children[i].firstName == registrant.childFirstName && children[i].lastName == registrant.childLastName && children[i].classroom == registrant.classroom) {
				if (children[i].parent == 0) {
					childFoundFlag++;
					match = i;
				}
				else {
					cout << ">>Error. There is already a parent account associated with that child. Please confirm account details with any co-carers who may have already registered an account or contact the administrator to resolve this issue<<\nEnter 1 to return to the main menu";
					cin >> menu;
					mainMenu(&children, &teachers, &parents, &admin);
				}
			}
		}
		if (childFoundFlag == 0) {
			cout << ">>Error. No student found with those names in the given classroom.<<\n";
			while (menu != "1" && menu != "2") {
				cout << "Enter 1 to retry or 2 to return to main menu.\n";
				cin >> menu;
				if (menu == "2") {
					mainMenu(&children, &teachers, &parents, &admin);
				}
				else if (menu != "1") {
					cout << ">>Error. Please enter only the number 1 or 2.<<\n";
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
			while (passwordFlag == 0) {
			int upperFlag = 0;
			int lowerFlag = 0;
			int digitFlag = 0;
			int symbolFlag = 0;
			int symbolSubFlag = 0;
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
					cout << "assigned ID to children[i].parent: " << id;
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
				Classroom << children[i].firstName << "," << children[i].lastName << "," << children[i].preferredName << "," << children[i].gender << "," << children[i].pronouns << "," << children[i].DOB << "," << children[i].classroom << "," << children[i].maths << "," << children[i].science << "," << children[i].reading << "," << children[i].writing << "," << children[i].others << "," << children[i].progress << "," << children[i].parent << endl;
			}
			Classroom.close();//Close file
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

void childRegister(vector<Child>* c, vector<Teacher>*t, vector<Parent>* p, Admin* a) {
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
	cout << "\nPlease enter the student's gender: ";
	getline(cin, registrant.gender);
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
		cout << "\nPlease enter the current overall learning progress. Enter 1 for Achieved, 2 for Progressing, or 3 for Needs Help: ";
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
	Classroom << registrant.firstName << "," << registrant.lastName << ","  << registrant.preferredName << "," << registrant.gender << "," << registrant.pronouns << "," << registrant.DOB << "," << registrant.classroom << "," << registrant.maths << "," << registrant.science << "," << registrant.reading << "," << registrant.writing << "," << registrant.others << "," << registrant.progress << "," << registrant.parent << endl;
	Classroom.close();//Close file
	children = readChildren201();
	cout << children[1].firstName;

	//Register another?
	string another = "0";
	while (another != "1" && another != "2") {
		cout << "\nRegister another student? Enter 1 to do so or 2 to return to your menu. ";
		cin >> another;
		if (another == "1") {
			childRegister(&children, &teachers, &parents, &admin);
		}
		else if (another == "2") {
			adminMenu(&children, &teachers, &parents, &admin);
		}
	}
}

void teacherMenu(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a, Teacher currentAccount) {
	vector<Child> children = *c;
	vector<Teacher> teachers = *t;
	vector<Parent> parents = *p;
	Admin admin = *a;
	string menu = "0";
	while (menu != "1" && menu != "2" && menu != "3" && menu != "4") {
		cout << "\nWhat would you like to do?\n\n\n\t1. Update one of your student's grades\n\n\t2. View one of your student's records\n\n\t3. View a parent's details\n\n\t4. Log out and return to the main menu\n\n\n";
		cin >> menu;
		if (menu == "1") {
			updateGrades(&children, &teachers, &parents, &admin, currentAccount);
		}
		else if (menu == "2") {
			displayStudentRecordTeacher(&children, &teachers, &parents, &admin, currentAccount);
		}
		else if (menu == "3") {
			displayParentsRecordTeacher(&children, &teachers, &parents, &admin, currentAccount);
		}
		else if (menu == "4") {
			mainMenu(&children, &teachers, &parents, &admin);
		}
		else {
			cout << ">>Error. That wasn't one of the options. Please enter only the number<<\n";
		}
	}
}

void updateGrades(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a, Teacher currentAccount) {
	vector<Child> children = *c;
	vector<Teacher> teachers = *t;
	vector<Parent> parents = *p;
	Admin admin = *a;
	string firstName;
	string lastName;

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
		cout << ">>Error. No student found with those names.<<\n";
		while (menu != "1" && menu != "2") {
			cout << "Enter 1 to retry or 2 to return to your menu.\n";
			cin >> menu;
			if (menu == "1") {
				updateGrades(&children, &teachers, &parents, &admin, currentAccount);
			}
			else if (menu == "2") {
				teacherMenu(&children, &teachers, &parents, &admin, currentAccount);
			}
			else {
				">>Error. Please enter only 1 or 2.<<\n";
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
			Classroom << children[i].firstName << "," << children[i].lastName << "," << children[i].preferredName << "," << children[i].gender << "," << children[i].pronouns << "," << children[i].DOB << "," << children[i].classroom << "," << children[i].maths << "," << children[i].science << "," << children[i].reading << "," << children[i].writing << "," << children[i].others << "," << children[i].progress << "," << children[i].parent << endl;
		}
		Classroom.close();//Close file
		children = readChildren201();

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
				cout << ">>Error. Please enter only the number 1 or 2.<<\n";
			}
		}
	}
}

void displayStudentRecordTeacher(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a, Teacher currentAccount) {
	vector<Child> children = *c;
	vector<Teacher> teachers = *t;
	vector<Parent> parents = *p;
	Admin admin = *a;
	string firstName;
	string lastName;
	Child display;
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
		cout << ">>Error. No student found with those names.<<\n";
		while (menu != "1" && menu != "2") {
			cout << "Enter 1 to retry or 2 to return to your menu.\n";
			cin >> menu;
			if (menu == "1") {
				displayStudentRecordTeacher(&children, &teachers, &parents, &admin, currentAccount);
			}
			else if (menu == "2") {
				teacherMenu(&children, &teachers, &parents, &admin, currentAccount);
			}
			else {
				">>Error. Please enter only 1 or 2.<<\n";
			}
		}
	}
	else if (childFoundFlag > 1) {
		cout << ">>Error. Multiple records found in this class with that name. Please contact administrator.<<\n";
		menu = "0";
		while (menu != "1" && menu != "2") {
			cout << "Enter 1 to retry or 2 to return to your menu.";
			cin >> menu;
			if (menu == "1") {
				displayStudentRecordTeacher(&children, &teachers, &parents, &admin, currentAccount);
			}
			else if (menu == "2") {
				teacherMenu(&children, &teachers, &parents, &admin, currentAccount);
			}
			else {
				cout << ">>Error. Please enter only the number 1 or 2.<< ";
			}
		}
	}
	else {
		cout << "\nRecord found\n\n" <<children[match].firstName << " " << children[match].lastName << "\nPrefers to be called " << children[match].preferredName << "\nGender: " << children[match].gender << " (uses " << children[match].pronouns << " pronouns)\nBorn " << children[match].DOB << "\nCurrent grades:\nMaths: " << children[match].maths << "\nScience: " << children[match].science << "\nWriting: " << children[match].writing << "\nReading: " << children[match].reading << "\nOthers: " << children[match].others << "\nOverall assessment of learning progress: " << children[match].progress;
		teacherMenu(&children, &teachers, &parents, &admin, currentAccount);
	}
}

void displayParentsRecordTeacher(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a, Teacher currentAccount) {
	vector<Child> children = *c;
	vector<Teacher> teachers = *t;
	vector<Parent> parents = *p;
	Admin admin = *a;
	string firstName;
	string lastName;
	Child display;
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
		cout << ">>Error. No student found with those names.<<\n";
		while (menu != "1" && menu != "2") {
			cout << "Enter 1 to retry or 2 to return to your menu.\n";
			cin >> menu;
			if (menu == "1") {
				displayParentsRecordTeacher(&children, &teachers, &parents, &admin, currentAccount);
			}
			else if (menu == "2") {
				teacherMenu(&children, &teachers, &parents, &admin, currentAccount);
			}
			else {
				">>Error. Please enter only 1 or 2.<<\n";
			}
		}
	}
	else if (childFoundFlag > 1) {
		cout << ">>Error. Multiple records found in this class with that name. Please contact administrator.<<\n";
		menu = "0";
		while (menu != "1" && menu != "2") {
			cout << "Enter 1 to retry or 2 to return to your menu.\n";
			cin >> menu;
			if (menu == "1") {
				displayParentsRecordTeacher(&children, &teachers, &parents, &admin, currentAccount);
			}
			else if (menu == "2") {
				teacherMenu(&children, &teachers, &parents, &admin, currentAccount);
			}
			else {
				cout << ">>Error. Please enter only the number 1 or 2.<<\n";
			}
		}
	}
	else {
		int parentFoundFlag = 0;
		int parentMatch = 0;
		for (int i = 0; i < parents.size(); i++) {
			if (children[match].parent == parents[i].ID) {
				parentFoundFlag++;
				parentMatch = i;
			}
		}
		menu = "0";
		if (parentFoundFlag == 0) {
			cout << ">>No parent found linked to that student's record<<\n";
			while (menu != "1" && menu != "2") {
				cout << "Enter 1 to retry or 2 to return to your menu.\n";
				cin >> menu;
				if (menu == "1") {
					displayParentsRecordTeacher(&children, &teachers, &parents, &admin, currentAccount);
				}
				else if (menu == "2") {
					teacherMenu(&children, &teachers, &parents, &admin, currentAccount);
				}
				else {
					">>Error. Please enter only 1 or 2.<<\n";
				}
			}
		}
		else if (parentFoundFlag > 1) {
			cout << ">>Error. Multiple parent records found linked to that student's record. Please contact administrator.<<\n";
			menu = "0";
			while (menu != "1" && menu != "2") {
				cout << "Enter 1 to retry or 2 to return to your menu.";
				cin >> menu;
				if (menu == "1") {
					displayParentsRecordTeacher(&children, &teachers, &parents, &admin, currentAccount);
				}
				else if (menu == "2") {
					teacherMenu(&children, &teachers, &parents, &admin, currentAccount);
				}
				else {
					cout << ">>Error. Please enter only the number 1 or 2.<< ";
				}
			}
		}
		else {
			cout << "\nRecord found\n\n" << parents[parentMatch].title << " " << parents[parentMatch].firstName << " " << parents[parentMatch].lastName << "\nPrefers to be called " << parents[parentMatch].preferredName << "\nGender: " << parents[parentMatch].gender << " (uses " << parents[parentMatch].pronouns << " pronouns)\nBorn " << parents[parentMatch].DOB << "\nContact details:\nemail: " << parents[parentMatch].email << "\nPhone: " << parents[parentMatch].Ph << "\nDaytime emergency phone: " << parents[parentMatch].emergencyPh;
			menu = "0";
			while (menu != "1" && menu != "2") {
				cout << "\nEnter 1 to check another parent's record or 2 to return to your menu.";
				cin >> menu;
				if (menu == "1") {
					displayParentsRecordTeacher(&children, &teachers, &parents, &admin, currentAccount);
				}
				else if (menu == "2") {
					teacherMenu(&children, &teachers, &parents, &admin, currentAccount);
				}
				else {
					cout << ">>Error. Please enter only the number 1 or 2.<< ";
				}
			}
		}
	}
}

void adminMenu(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a) {
	string menu = "0";
	while (menu != "1" && menu != "2" && menu != "3" && menu != "4" && menu != "5" && menu != "6" && menu != "7") {
		cout << "\n\nPlease select one of the following by entering its number:\n\n\n\t1. Create a new student record\n\n\t2. Update a student record\n\n\t3. Delete a student record\n\n\t4. View a student record\n\n\t5. View a parent record\n\n\t6. View a list of students at a certain level of learning progress\n\n\t7. Log out and return to main menu\n\n\nEnter your selection: ";
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
			string room;
			cout << "Which classroom is the child in (eg 201)? ";
			cin >> room;
			if (room == "201"){
				displayStudentRecordAdmin(c, t, p, a, room);
			}
			//If I had other classrooms they would have their own else if statements calling functions that handle their files 
			else {
				cout << ">>Error. No classroom " << room << " found.<<\n";
				adminMenu(c, t, p, a);
			}
		}
		else if (menu == "5") {
			string room;
			cout << "Which classroom is the parent's child in (eg 201)? ";
			cin >> room;
			if (room == "201") {
				displayParentsRecordAdmin(c, t, p, a, room);
			}
			else {
				cout << ">>Error. No classroom " << room << " found.<<\n";
				adminMenu(c, t, p, a);
			}
		}
		else if (menu == "6") {
			string progressLevel = "0";
			while (progressLevel != "1", progressLevel != "2", progressLevel != "3") {
				cout << "What progress level would you like to see?\n\n\n\t1. Achieved\n\n\t2. Progressing\n\n\t3. Needs help\n\n\n";
				cin >> progressLevel;
				if (progressLevel == "1" || progressLevel == "2" || progressLevel == "3") {
					displayProgressLevel(c, t, p, a, progressLevel);
					adminMenu(c, t, p, a);
				}
				else {
					cout << ">>Error. That wasn't one of the options<<\n";
					adminMenu(c, t, p, a);
				}
			}
		}
		else if (menu == "7") {
			mainMenu(c, t, p, a);
		}
		else {
			cout << ">>Error. That wasn't one of the options<<\n";
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
		cout << ">>Error. No student found with those names in the given classroom.<<\n";
		while (menu != "1" && menu != "2") {
			cout << "Enter 1 to retry or 2 to return to your menu.\n";
			cin >> menu;
			if (menu == "1") {
				updateChild(&children, &teachers, &parents, &admin);
			}
			else if (menu == "2") {
				adminMenu(&children, &teachers, &parents, &admin);
			}
			else {
				">>Error. Please enter only 1 or 2.<<\n";
			}
		}
	}
	else if (childFoundFlag > 1) {
		cout << ">>Error. Multiple records found in this class with that name. Administrator repairs required: examine files and delete duplicates.<<\n";
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
				cout << ">>Error. Please enter only the number 1 or 2.\n";
			}
		}
	}
	else {
		//Updating record
		bool update = askUpdate("first name");
		if (update == true) {
			cout << "\nPlease enter the student's new first name(s): ";
			cin.ignore();
			getline(cin, children[match].firstName);
		}
		update = askUpdate("last name");
		if (update == true) {
			cout << "\nPlease enter the student's new last name(s): ";
			cin.ignore();
			getline(cin, children[match].lastName);
		}
		update = askUpdate("preferred name");
		if (update == true) {
			cout << "\nPlease enter the student's new preferred name: ";
			cin.ignore();
			getline(cin, children[match].preferredName);
		}
		update = askUpdate("gender");
		if (update == true) {
			cout << "\nPlease enter the student's new gender: ";
			cin.ignore();
			getline(cin, children[match].gender);
		}
		update = askUpdate("pronouns");
		if (update == true) {
			cout << "\nPlease enter the student's new pronouns: ";
			cin.ignore();
			getline(cin, children[match].pronouns);
		}
		update = askUpdate("date of birth");
		if (update == true) {
			cout << "\nPlease enter the student's new pronouns: ";
			cin.ignore();
			getline(cin, children[match].DOB);
		}
		update = askUpdate("classroom");
		if (update == true) {
			cout << "\nPlease enter the student's new pronouns: ";
			cin.ignore();
			getline(cin, children[match].classroom);
		}
		update = askUpdate("marks for maths");
		if (update == true) {
			cout << "\nPlease enter the new maths results: ";
			cin.ignore();
			getline(cin, children[match].maths);
		}
		update = askUpdate("marks for science");
		if (update == true) {
			cout << "\nPlease enter the new science results: ";
			cin.ignore();
			getline(cin, children[match].science);
		}
		update = askUpdate("marks for reading");
		if (update == true) {
			cout << "\nPlease enter the new reading results: ";
			cin.ignore();
			getline(cin, children[match].reading);
		}
		update = askUpdate("marks for writing");
		if (update == true) {
			cout << "\nPlease enter the new writing results: ";
			cin.ignore();
			getline(cin, children[match].writing);
		}
		update = askUpdate("marks for other subjects");
		if (update == true) {
			cout << "\nPlease enter the new average across other results: ";
			cin.ignore();
			getline(cin, children[match].others);
		}
		update = askUpdate("learning progress");
		if (update == true) {
			//Learning Progress
			string progress = "0";
			while (progress != "1" && progress != "2" && progress != "3") {
				cout << "\nPlease enter the current overall learning progress. Enter 1 for Achieved, 2 for Progressing, or 3 for Needs Help: ";
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
		}
		//Writing to File
		fstream Classroom("201.csv", ios::out);
		for (int i = 0; i < children.size(); i++) {//This completely overwrites the file, presevering the data in order with the new infotmation
			Classroom << children[i].firstName << "," << children[i].lastName << "," << children[i].preferredName << "," << children[i].gender << "," << children[i].pronouns << "," << children[i].DOB << "," << children[i].classroom << "," << children[i].maths << "," << children[i].science << "," << children[i].reading << "," << children[i].writing << "," << children[i].others << "," << children[i].progress << "," << children[i].parent << endl;
		}
		Classroom.close();//Close file
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
		cout << ">>Error. No student found with those names in the given classroom.<<\n";
		while (menu != "1" && menu != "2") {
			cout << "Enter 1 to retry or 2 to return to your menu.\n";
			cin >> menu;
			if (menu == "1") {
				deleteChild(&children, &teachers, &parents, &admin);
			}
			else if (menu == "2") {
				adminMenu(&children, &teachers, &parents, &admin);
			}
			else {
				">>Error. Please enter only 1 or 2.<<\n";
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
					Classroom << children[i].firstName << "," << children[i].lastName << "," << children[i].preferredName << "," << children[i].gender << "," << children[i].pronouns << "," << children[i].DOB << "," << children[i].classroom << "," << children[i].maths << "," << children[i].science << "," << children[i].reading << "," << children[i].writing << "," << children[i].others << "," << children[i].progress << "," << children[i].parent << endl;
				}
				Classroom.close();//Close file
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

void displayStudentRecordAdmin(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a, string room) {
		vector<Child> children = *c;
		vector<Teacher> teachers = *t;
		vector<Parent> parents = *p;
		Admin admin = *a;
		string firstName;
		string lastName;
		Child display;
		cout << "\nPlease enter the student's first name(s): ";
		cin.ignore();
		getline(cin, firstName);
		cout << "\nPlease enter the student's last name(s): ";
		getline(cin, lastName);
		int childFoundFlag = 0;
		int match = 0;
		for (int i = 0; i < children.size(); i++) {
			if (children[i].firstName == firstName && children[i].lastName == lastName && children[i].classroom == room) {
				childFoundFlag++;
				match = i;
			}
		}
		string menu = "0";
		if (childFoundFlag == 0) {
			cout << ">>Error. No student found with those names.<<\n";
			while (menu != "1" && menu != "2") {
				cout << "Enter 1 to retry or 2 to return to your menu.\n";
				cin >> menu;
				if (menu == "1") {
					displayStudentRecordAdmin(&children, &teachers, &parents, &admin, room);
				}
				else if (menu == "2") {
					adminMenu(&children, &teachers, &parents, &admin);
				}
				else {
					">>Error. Please enter only 1 or 2.<<\n";
				}
			}
		}
		else if (childFoundFlag > 1) {
			cout << ">>Error. Multiple records found in this class with that name. Please contact administrator.<<\n";
			menu = "0";
			while (menu != "1" && menu != "2") {
				cout << "Enter 1 to retry or 2 to return to your menu.";
				cin >> menu;
				if (menu == "1") {
					displayStudentRecordAdmin(&children, &teachers, &parents, &admin, room);
				}
				else if (menu == "2") {
					adminMenu(&children, &teachers, &parents, &admin);
				}
				else {
					cout << ">>Error. Please enter only the number 1 or 2.<< ";
				}
			}
		}
		else {
			cout << "\nRecord found\n\n" <<children[match].firstName << " " << children[match].lastName << "\nPrefers to be called " << children[match].preferredName << "\nGender: " << children[match].gender << " (uses " << children[match].pronouns << " pronouns)\nBorn " << children[match].DOB << "\nCurrent grades:\nMaths: " << children[match].maths << "\nScience: " << children[match].science << "\nWriting: " << children[match].writing << "\nReading: " << children[match].reading << "\nOthers: " << children[match].others << "\nOverall assessment of learning progress: " << children[match].progress;
			adminMenu(&children, &teachers, &parents, &admin);
		}
	}
	
	void displayParentsRecordAdmin(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a, string room) {
		vector<Child> children = *c;
		vector<Teacher> teachers = *t;
		vector<Parent> parents = *p;
		Admin admin = *a;
		string firstName;
		string lastName;
		Child display;
		cout << "\nPlease enter the student's first name(s): ";
		cin.ignore();
		getline(cin, firstName);
		cout << "\nPlease enter the student's last name(s): ";
		getline(cin, lastName);
		int childFoundFlag = 0;
		int match = 0;
		for (int i = 0; i < children.size(); i++) {
			if (children[i].firstName == firstName && children[i].lastName == lastName && children[i].classroom == room) {
				childFoundFlag++;
				match = i;
			}
		}
		string menu = "0";
		if (childFoundFlag == 0) {
			cout << ">>Error. No student found with those names.<<\n";
			while (menu != "1" && menu != "2") {
				cout << "Enter 1 to retry or 2 to return to your menu.\n";
				cin >> menu;
				if (menu == "1") {
					displayParentsRecordAdmin(&children, &teachers, &parents, &admin, room);
				}
				else if (menu == "2") {
					adminMenu(&children, &teachers, &parents, &admin);
				}
				else {
					">>Error. Please enter only 1 or 2.<<\n";
				}
			}
		}
		else if (childFoundFlag > 1) {
			cout << ">>Error. Multiple records found in this class with that name. Please contact administrator.<<\n";
			menu = "0";
			while (menu != "1" && menu != "2") {
				cout << "\nEnter 1 to retry or 2 to return to your menu.";
				cin >> menu;
				if (menu == "1") {
					displayParentsRecordAdmin(&children, &teachers, &parents, &admin, room);
				}
				else if (menu == "2") {
					adminMenu(&children, &teachers, &parents, &admin);
				}
				else {
					cout << ">>Error. Please enter only the number 1 or 2.<< ";
				}
			}
		}
		else {
			int parentFoundFlag = 0;
			int parentMatch = 0;
			for (int i = 0; i < parents.size(); i++) {
				if (children[match].parent == parents[i].ID) {
					parentFoundFlag++;
					parentMatch = i;
				}
			}
			menu = "0";
			if (parentFoundFlag == 0) {
				cout << "No parent found linked to that student's record";
				while (menu != "1" && menu != "2") {
					cout << "Enter 1 to retry or 2 to return to your menu.";
					cin >> menu;
					if (menu == "1") {
						displayParentsRecordAdmin(&children, &teachers, &parents, &admin, room);
					}
					else if (menu == "2") {
						adminMenu(&children, &teachers, &parents, &admin);
					}
					else {
						">>Error. Please enter only 1 or 2.<< ";
					}
				}
			}
			else if (parentFoundFlag > 1) {
				cout << ">>Error. Multiple parent records found linked to that student's record. Please contact administrator.<<\n";
				menu = "0";
				while (menu != "1" && menu != "2") {
					cout << "\nEnter 1 to retry or 2 to return to your menu.";
					cin >> menu;
					if (menu == "1") {
						displayParentsRecordAdmin(&children, &teachers, &parents, &admin, room);
					}
					else if (menu == "2") {
						adminMenu(&children, &teachers, &parents, &admin);
					}
					else {
						cout << ">>Error. Please enter only the number 1 or 2.<< ";
					}
				}
			}
			else {
				cout << "\nRecord found\n\n" << parents[parentMatch].title << " " << parents[parentMatch].firstName << " " << parents[parentMatch].lastName << "\nPrefers to be called " << parents[parentMatch].preferredName << "\nGender: " << parents[parentMatch].gender << " (uses " << parents[parentMatch].pronouns << " pronouns)\nBorn " << parents[parentMatch].DOB << "\nContact details:\nemail: " << parents[parentMatch].email << "\nPhone: " << parents[parentMatch].Ph << "\nDaytime emergency phone: " << parents[parentMatch].emergencyPh;
				menu = "0";
				while (menu != "1" && menu != "2") {
					cout << "\nEnter 1 to check another parent's record or 2 to return to your menu.";
					cin >> menu;
					if (menu == "1") {
						displayParentsRecordAdmin(&children, &teachers, &parents, &admin, room);
					}
					else if (menu == "2") {
						adminMenu(&children, &teachers, &parents, &admin);
					}
					else {
						cout << ">>Error. Please enter only the number 1 or 2.<< ";
					}
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

void displayProgressLevel(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a, string pl) {
	vector<Child> children = *c;
	vector<Teacher> teachers = *t;
	vector <Parent> parents = *p;
	string target;
	if (pl == "1") {
		target = "Achieved";
	}
	else if (pl == "2") {
		target = "Progressing";
	}
	else {
		target = "Needs Help";
	}
	//If had multiple classrooms, this would be in a function, and I would pass an argument to the function (along with all the vectors) that told it which file to check (via an if statement in the function). I would run that function passing the instruction to check each file.
	for (int i = 0; i < children.size(); i++) {
		if (children[i].progress == target) {
			cout << children[i].firstName << " " << children[i].lastName << "\nClass: " << children[i].classroom << " " << "\nPrefers to be called " << children[i].preferredName << "\nGender: " << children[i].gender << " (uses " << children[i].pronouns << " pronouns)\nBorn " << children[i].DOB << "\nCurrent grades:\nMaths: " << children[i].maths << "\nScience: " << children[i].science << "\nWriting: " << children[i].writing << "\nReading: " << children[i].reading << "\nOthers: " << children[i].others << "\nOverall assessment of learning progress: " << children[i].progress;
			for (int j = 0; j < parents.size(); j++) {
				if (parents[j].ID == children[i].parent) {
					cout << "\nParent details: " << parents[j].firstName << " " << parents[j].lastName << "\nPrefers to be called " << parents[j].preferredName << "\nGender: " << parents[j].gender << " (uses " << parents[j].pronouns << " pronouns)\nEmail: " << parents[j].email << "\nPhone Number: " << parents[j].Ph << " or " << parents[j].emergencyPh << " for daytime emergency contact";
				}
			}
			for (int j = 0; j < teachers.size(); j++) {
				if (teachers[j].classroom == children[i].classroom) {
					cout << "\nTeacher: " << teachers[j].title << " " << teachers[j].firstName << " " << teachers[j].lastName << ", " << teachers[j].email;
				}
			}
		}
	}
}

void parentMenu(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a, int currentID) {
	vector<Child> children = *c;
	vector<Teacher> teachers = *t;
	vector <Parent> parents = *p;
	int match = -1;
	for (int i = 0; i < parents.size(); i++) {
		if (currentID == parents[i].ID) {
			match = i;
		}
	}
	int childMatch = -1;
	for (int i = 0; i < children.size(); i++) {
		if (currentID == children[i].parent) {
			childMatch = i;
		}
	}
	string menu = "0";
	while (menu != "1" && menu != "2" && menu != "3" && menu != "4" && menu != "5") {
		cout << "\nWhat would you like to do?\n\n\n\t1. View " << children[childMatch].firstName << "'s report\n\n\t2. Update " << children[childMatch].firstName << "'s details\n\n\t3. Update your details\n\n\t4. View school notices\n\n\t5. Log out and return to the main menu\n\n\n";
		cin >> menu;
		if (menu == "1") {
			cout << children[childMatch].firstName << " " << children[childMatch].lastName << "'s Report:\nOverall progress: " << children[childMatch].progress << "\nMaths: " << children[childMatch].maths << "\nScience: " << children[childMatch].science << "\nReading: " << children[childMatch].reading << "\nWriting" << children[childMatch].writing << "\nOther Subjects: " << children[childMatch].others << "\n\nEnter 1 to return to your menu\n";
			cin >> menu;
			parentMenu(&children, &teachers, &parents, a, currentID);
		}
		else if (menu == "2") {
			bool update = askUpdate("first name");
			if (update == true) {
				cout << "\nPlease enter the student's new first name(s): ";
				cin.ignore();
				getline(cin, children[childMatch].firstName);
			}
			update = askUpdate("last name");
			if (update == true) {
				cout << "\nPlease enter the student's new last name(s): ";
				cin.ignore();
				getline(cin, children[childMatch].lastName);
			}
			update = askUpdate("preferred name");
			if (update == true) {
				cout << "\nPlease enter the student's new preferred name: ";
				cin.ignore();
				getline(cin, children[childMatch].preferredName);
			}
			update = askUpdate("gender");
			if (update == true) {
				cout << "\nPlease enter the student's new gender: ";
				cin.ignore();
				getline(cin, children[childMatch].gender);
			}
			update = askUpdate("pronouns");
			if (update == true) {
				cout << "\nPlease enter the student's new pronouns: ";
				cin.ignore();
				getline(cin, children[childMatch].pronouns);
			}
			//Writing to File
			fstream Classroom("201.csv", ios::out);
			for (int i = 0; i < children.size(); i++) {//This completely overwrites the file, presevering the data in order with the new infotmation
				Classroom << children[i].firstName << "," << children[i].lastName << "," << children[i].preferredName << "," << children[i].gender << "," << children[i].pronouns << "," << children[i].DOB << "," << children[i].classroom << "," << children[i].maths << "," << children[i].science << "," << children[i].reading << "," << children[i].writing << "," << children[i].others << "," << children[i].progress << "," << children[i].parent << endl;
			}
			Classroom.close();//Close file
			children = readChildren201();
			cout << "Records updated. Enter 1 to return to your menu\n";
			cin >> menu;
			parentMenu(&children, &teachers, &parents, a, currentID);
		}
		else if (menu == "3") {	
			bool update;
			update = askUpdateParent("first name");
			if (update == true) {
				cin.ignore();
				cout << "\nPlease enter your first name(s): ";
				getline(cin, parents[match].firstName);
			}
			update = askUpdateParent("last name");
			if (update == true) {
				cin.ignore();
				cout << "\nPlease enter your last name(s): ";
				getline(cin, parents[match].lastName);
			}
			update = askUpdateParent("title");
			if (update == true) {
				cin.ignore();
				cout << "\nPlease enter your preferred title: (Mr. Mx. Dr. Miss etc) ";
				getline(cin, parents[match].title);
			}
			update = askUpdateParent("preferred name");
			if (update == true) {
				cin.ignore();
				cout << "\nPlease enter your preferred name: ";
				getline(cin, parents[match].preferredName);
			}
			update = askUpdateParent("pronouns");
			if (update == true) {
				cin.ignore();
				cout << "\nPlease enter your pronouns: ";
				getline(cin, parents[match].pronouns);
			}
			update = askUpdateParent("gender");
			if (update == true) {
				cin.ignore();
				cout << "\nPlease enter your gender: ";
				getline(cin, parents[match].gender);
			}
			update = askUpdateParent("email");
			if (update == true) {
				cin.ignore();
				cout << "\nPlease enter your email: ";
				getline(cin, parents[match].email);
			}
			//Email Validation
			int emailFlag = 0;
			while (emailFlag == 0) {
				for (int i = 0; i < parents[match].email.length(); i++) {
					if (parents[match].email[i] == '@') {
						emailFlag = 1;
					}
				}
				if (emailFlag == 0) {
					cout << ">>Error. Emails must include '@' symbol. Please re-enter your email<< ";
					getline(cin, parents[match].email);
				}
			}
			update = askUpdateParent("contact number");
			if (update == true) {
				cin.ignore();
				cout << "\nPlease enter your contact number: ";
				getline(cin, parents[match].Ph);
			}
			update = askUpdateParent("emergency contact number");
			if (update == true) {
				cin.ignore();
				cout << "\nPlease enter a daytime contact number to use in emergencies: ";
				getline(cin, parents[match].emergencyPh);
			}
			update = askUpdateParent("password");
			if (update == true) {
				cin.ignore();
				cout << "\nPlease enter choose a password - include a number, uppercase letter, lowercase letter and a special symbol (neither a letter nor a number): ";
				//Password Validation
				int passwordFlag = 0;
				while (passwordFlag == 0) {
				int upperFlag = 0;
				int lowerFlag = 0;
				int digitFlag = 0;
				int symbolFlag = 0;
				int symbolSubFlag = 0;
					getline(cin, parents[match].password);
					for (int i = 0; i < parents[match].password.length(); i++) {
						symbolSubFlag = 0;
						if (islower(parents[match].password[i])) {
							lowerFlag = 1;
							symbolSubFlag++;
						}
						if (isupper(parents[match].password[i])) {
							upperFlag = 1;
							symbolSubFlag++;
						}
						if (isdigit(parents[match].password[i])) {
							digitFlag = 1;
							symbolSubFlag++;
						}
						if (symbolSubFlag == 0) {
							symbolFlag = 1;
						}
					}
					if (parents[match].password.length() > 7 && digitFlag == 1 && upperFlag == 1 && lowerFlag == 1 && symbolFlag == 1) {
						passwordFlag++;
					}
					if (passwordFlag == 0) {
						cout << ">>Error. Passwords must be 8 or more characters, including upper and lower case letters, numbers, and non-alphanumeric symbols. Please enter a valid password<< ";
					}
				}
				//Password Confirmation
				while (parents[match].confirmPassword != parents[match].password) {
					cout << "\nPlease confirm your password: ";
					getline(cin, parents[match].confirmPassword);
					if (parents[match].confirmPassword != parents[match].password) {
						cout << "\nPasswords do not match. ";
					}
				}
			}
			//Writing to File
			fstream ParentList("Parents.csv", ios::out);
			for (int i = 0; i < parents.size(); i++) {//This completely overwrites the file, presevering the data in order with the new information
				ParentList << parents[i].firstName << "," << parents[i].lastName << "," << parents[i].title << "," << parents[i].preferredName << "," << parents[i].gender << "," << parents[i].pronouns << "," << parents[i].DOB << "," << parents[i].email << "," << parents[i].Ph << "," << parents[i].emergencyPh << "," << parents[i].childFirstName << "," << parents[i].childLastName << "," << parents[i].classroom << "," << parents[i].username << "," << parents[i].password << "," << parents[i].ID << endl;
			}
			ParentList.close();//Close file
			parents = readParents();
			parentMenu(&children, &teachers, &parents, a, currentID);
		}
		else if (menu == "4") {
			cout << "Athletics day 28th January - wear your house colours and comfortable running shoes!\n\nAuditions for the school production of CHESS! The Musical - 3:30pm in room 201 Tuesday afternoon\n\nYu-Gi-Oh trading card ban is tentatively lifted, but we will not hesitate to reinstate it if there is another incident\n\n\nEnter 1 to return to your menu\n";
			cin >> menu;
			parentMenu(&children, &teachers, &parents, a, currentID);
		}
		else if (menu == "5") {
			mainMenu(&children, &teachers, &parents, a);
		}
		else {
			cout << "\n>>Error. Enter only the number<<\n";
		}
	}
}

bool askUpdateParent(string field) {
	cout << "\nWould you like to update your " << field << "?";
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

//Still Needed
	//update teacher records as admin or teahcer
	//Include better explanations of input formats (eg classroom numbers) and conditions(eg no two students in the same class with the same name)
	//give more options for admin to delete/edit files for parents/teachers
	//refactoring