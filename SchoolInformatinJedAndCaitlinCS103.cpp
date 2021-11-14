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
	string classroom;
	string maths;
	string science;
	string writing;
	string reading;
	string others;
	string progress;
	int parent;//This will be a backend ID #

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
bool askUpdate(string field);

int main()
{	
	vector <Child> children;//I'm not sure that we'll actually need to pass these around all the time. I built it with these vectors in case but we may end up passing them a lot less
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

	//Menu
	string menu;
	cout << "\nPlease select one of the following options by typing its number and pressing enter.\n\n\n\t1. Login\n\n\t2. Register\n\n\t3. Exit\n\n";
	cin >> menu;//Menus using string inputs and digit answers through if statements are more robust than other variables or switches. We don't use getline because we don't want values with spaces to be handled fully - if some enters "1 " this code will read it as "1", which is desirable.
	if (menu == "1") {
		whichLogin(&children, &teachers, &parents, &admin);
	}
	else if (menu == "2") {
		whichRegister(&children, &teachers, &parents, &admin);
	}
	else if (menu == "3") {
		exit(0);//Exit 0 ends the program even if a bunch of functions are still running
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

	//Login Menu
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
	cout << "Please enter your username: ";
	cin.ignore();
	getline(cin, username);
	//FILES check against usernames
	//Add if for if username not in file

	//Password
	string password;
	cout << "Please enter your password: ";
	getline(cin, password);
	//FILES check password against file
	//Add if for if password doesn't match, 3 attempts only
}

void adminLogin(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a) {
	vector<Child> children = *c;
	vector<Teacher> teachers = *t;
	vector<Parent> parents = *p;
	Admin admin = *a;

	//Username
	string username;
	cout << "Please enter your username: ";
	cin.ignore();
	getline(cin, username);
	//FILES check against usernames
	//Add if for if username not in file

	string password;
	//FILES check against usernames
	cout << "Please enter your password: ";
	getline(cin, password);
	//FILES check password against file
	//Add if for if password doesn't match, 3 attempts only
}

void parentLogin(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a) {
	vector<Child> children = *c;
	vector<Teacher> teachers = *t;
	vector<Parent> parents = *p;
	Admin admin = *a;
	//Username
	string username;
	cout << "Please enter your username: ";
	cin.ignore();
	getline(cin, username);
	//FILES check against usernames
	//Add if for if username not in file

	string password;
	//FILES check against usernames
	cout << "Please enter your password: ";
	getline(cin, password);
	//FILES check password against file
	//Add if for if password doesn't match, 3 attempts only
}

void whichRegister(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a) {
	vector<Child> children = *c;
	vector<Teacher> teachers = *t;
	vector<Parent> parents = *p;
	Admin admin = *a;

	//Registration Menu
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

	//Register Teacher Record
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
	//Email Validation - is there at least one @ symbol?
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
	//FILES Check against all extant usernames, alert and offer input again if conflict
	cout << "Please enter choose a password - include a number, uppercase letter, lowercase letter and a special symbol (neither a letter nor a number): ";
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
			cout << "Error. Passwords must be 8 or more characters, including upper and lower case letters, numbers, and non-alphanumeric symbols. Please enter a valid password: ";
			getline(cin, registrant.password);
		}
	}
	//Password Confirmation
	while (registrant.confirmPassword != registrant.password) {
		cout << "Please confirm your password: ";
		getline(cin, registrant.confirmPassword);
		if (registrant.confirmPassword != registrant.password) {
			cout << "Passwords do not match. ";
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
		cout << "Register another teacher? Enter 1 to do so or 2 to return to the main menu.";
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
	cout << "Welcome to the parent registration form. Please note each child can only have one account, and each account can only have one child - if you have multiple children at the school you will have to register a parent's account for each one. \nPlease enter your first name(s): ";
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
	//Email Validation
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
	cout << "Please enter the first name(s) of your child: ";
	getline(cin, registrant.childFirstName);
	cout << "Please enter the last name(s) of your child: ";
	getline(cin, registrant.childLastName);
	cout << "Please enter your child's classroom (eg 201, 105): ";
	getline(cin, registrant.classroom);
	//FILES Check classroom file for matching child, retake names and class if none found or tell them to contact admin
	cout << "Please enter choose a username: ";
	getline(cin, registrant.username);
	//FILES Check against all extant parent usernames, retake input if taken
	cout << "Please enter choose a password - include a number, uppercase letter, lowercase letter and a special symbol (neither a letter nor a number): ";
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
			cout << "Error. Passwords must be 8 or more characters, including upper and lower case letters, numbers, and non-alphanumeric symbols. Please enter a valid password: ";
			getline(cin, registrant.password);
		}
	}
	//Password Confirmation
	while (registrant.confirmPassword != registrant.password) {
		cout << "Please confirm your password: ";
		getline(cin, registrant.confirmPassword);
		if (registrant.confirmPassword != registrant.password) {
			cout << "Passwords do not match. ";
		}
	}

	//Assign ID Number
	srand(time(NULL));
	int IDFlag = 0;
	while (IDFlag == 0) {
		int id = rand();
		//FILES compare ID against all ID numbers in parent file. If not found there, registrant.ID = id, IDFLag++
		IDFlag++;
	}

	//Writing to File
	fstream ParentList("Parents.csv", ios::app);//Open file
	//Write registrant details into teacher file:
	ParentList << registrant.firstName << "," << registrant.lastName << "," << registrant.title << "," << registrant.preferredName << "," << registrant.gender << "," << registrant.pronouns << "," << registrant.DOB << "," << registrant.email << "," << registrant.Ph << "," << registrant.emergencyPh << "," << registrant.childFirstName << "," << registrant.childLastName << "," << registrant.classroom << "," << registrant.username << "," << registrant.password << endl;
	ParentList.close();//Close file

	//Register another?
	string another = "0";
	while (another != "1" && another != "2") {
		cout << "Register another parent's account? Enter 1 to do so or 2 to return to the main menu.";
		cin >> another;
		if (another == "1") {
			parentRegister(&children, &teachers, &parents, &admin);
		}
		else if (another == "2") {
			mainMenu(&children, &teachers, &parents, &admin);
		}
	}

	//FILES Write parent ID number into child's file
}

void childRegister(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a) {
	vector<Child> children = *c;
	vector<Teacher> teachers = *t;
	vector<Parent> parents = *p;
	Admin admin = *a;

	//Register Child Record
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
	//Learning Progress - We take this via a number and write it in plain text to make it guaranteed consistent for the admin report to sleect them all
	string progress = "0";
	while (progress != "1" && progress != "2" && progress != "3") {
		cout << "Please enter the current overall learning progress (if known). Enter 1 for Achieved, 2 for Progressing, or 3 for Needs Help: ";
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
			cout << "Error. Please type only the number 1, 2, or 3 and press enter.\n";
		}
	}

	//Writing to File
	fstream Classroom("201.csv", ios::app);//For this assessment, with the blessing of our tutor Beula, we have hardcoded a single class file. If we had a real school with defined classrooms I would code a function to write to each of the rooms and create and if/else if/else statement that ran the function using the filename that matches the relevant classroom.
	//Write registrant details into teacher file:
	Classroom << registrant.firstName << "," << registrant.lastName << ","  << registrant.preferredName << "," << registrant.gender << "," << registrant.pronouns << "," << registrant.classroom << "," << registrant.maths << "," << registrant.science << "," << registrant.reading << "," << registrant.writing << "," << registrant.others << endl;
	Classroom.close();//Close file

	//Register another?
	string another = "0";
	while (another != "1" && another != "2") {
		cout << "Register another teacher? Enter 1 to do so or 2 to return to the main menu.";
		cin >> another;
		if (another == "1") {
			teacherRegister(&children, &teachers, &parents, &admin);
		}
		else if (another == "2") {
			mainMenu(&children, &teachers, &parents, &admin);
		}
	}
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
	//FILES Look through this teacher's classroom file, find student by name, copy into updatee
	cout << "Please enter the maths results: ";
	getline(cin, updatee.maths);
	cout << "Please enter the science results: ";
	getline(cin, updatee.science);
	cout << "Please enter the reading results: ";
	getline(cin, updatee.reading);
	cout << "Please enter the writing results: ";
	getline(cin, updatee.writing);
	cout << "Please enter the average across other results: ";
	getline(cin, updatee.others);
	//FILES write updatee over record in classroom file

//Learning Progress
	string progress = "0";
	while (progress != "1" && progress != "2" && progress != "3") {
		cout << "Please enter the current overall learning progress. Enter 1 for Achieved, 2 for Progressing, or 3 for Needs Help: ";
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
			cout << "Error. Please type only the number 1, 2, or 3 and press enter.\n";
		}
	}
	//FILES overwrite child's file with updatee
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

	//Select a student's record
	cin.ignore();
	cout << "Please enter the student's current first name(s): ";
	getline(cin, firstName);
	cout << "Please enter the student's current last name(s): ";
	getline(cin, lastName);
	cout << "Please enter the student's current classroom: ";
	getline(cin, classroom);
	//FILES Find child record and import to updatee

	//Updating record
	//Needs an if for each statement asking them if they want to update that field
	bool update = askUpdate("first name");
	if (update == true) {
		cout << "Please enter the student's new first name(s): ";
		getline(cin, updatee.firstName);
	}
	update = askUpdate("last name");
	if (update == true) {
		cout << "Please enter the student's new last name(s): ";
		getline(cin, updatee.lastName);
	}
	update = askUpdate("preferred name");
	if (update == true) {
		cout << "Please enter the student's new preferred name: ";
		getline(cin, updatee.preferredName);
	}
	update = askUpdate("pronouns");
	if (update == true) {
		cout << "Please enter the student's new pronouns: ";
		getline(cin, updatee.pronouns);
	}
	update = askUpdate("marks for maths");
	if (update == true) {
		cout << "Please enter the new maths results (if known): ";
		getline(cin, updatee.maths);
	}
	update = askUpdate("marks for science");
	if (update == true) {
		cout << "Please enter the new science results (if known): ";
		getline(cin, updatee.science);
	}
	update = askUpdate("marks for reading");
	if (update == true) {
		cout << "Please enter the new reading results (if known): ";
		getline(cin, updatee.reading);
	}
	update = askUpdate("marks for writing");
	if (update == true) {
		cout << "Please enter the new writing results (if known): ";
		getline(cin, updatee.writing);
	}
	update = askUpdate("marks for other subjects");
	if (update == true) {
		cout << "Please enter the new average across other results (if known): ";
		getline(cin, updatee.others);
	}
	update = askUpdate("learning Progress");
	if (update == true) {
		//Learning Progress
		string progress = "0";
		while (progress != "1" && progress != "2" && progress != "3") {
			cout << "Please enter the current overall learning progress. Enter 1 for Achieved, 2 for Progressing, or 3 for Needs Help: ";
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
				cout << "Error. Please type only the number 1, 2, or 3 and press enter.\n";
			}
		}
	}
	//FILES overwrite file with updatee
}

void childDelete(vector<Child>* c, vector<Teacher>* t, vector<Parent>* p, Admin* a) {
	vector<Child> children = *c;
	vector<Teacher> teachers = *t;
	vector<Parent> parents = *p;
	Admin admin = *a;

	//Determine Which Child's records to delete
	string firstName;
	string lastName;
	string classroom;
	cin.ignore();
	cout << "Delete Record\nPlease enter the student's current first name(s): ";
	getline(cin, firstName);
	cout << "Please enter the student's current last name(s): ";
	getline(cin, lastName);
	cout << "Please enter the student's current classroom: ";
	getline(cin, classroom);
	//FILES Find child record, retake inputs if 

	//Confirm Deletion
	cout << "Record found. Are you sure you wish to delete this data? Enter 1 to confirm or 2 to cancel.";
	string selection;
	cin >> selection;
	while (int selectedFlag = 0 == 0) {
		if (selection == "1") {
			//FILES Delete data
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

bool askUpdate(string field) {
	cout << "Would you like to update the student's " << field << "?";
	bool update;
	string answer;
	while (answer != "1" && answer != "2") {
		cout << "\nEnter 1 to update or 2 to leave this data as is.";
		cin >> answer;
		if (answer == "1") {
			update = true;
		}
		else if (answer == "2") {
			update = false;
		}
		else {
			cout << "Error. Please only type the number, then press enter.";
		}
	}
	return update;
}

//All Files work needs doing
	//File for teachers
	//File for parents
	//File containing all classroom names
	//File for each class containing student records

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