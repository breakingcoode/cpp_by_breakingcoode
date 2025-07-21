#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

class lawyer {
private:
	int id;
	char name[50];
	char phone[40];
	int casehandle, yearspend, revenue, casewon;
	bool admit;
	float totalRating;
	int totalReviews;
public:
	lawyer() {
		id = 0;
		casehandle = 0;
		yearspend = 0;
		revenue = 0;
		casewon = 0;
		admit = false;
		totalRating = 0;
		totalReviews = 0;

	}

	lawyer(int i, char n[50], char p[40], int c, int y, int r, int cas, bool a,float tr,int tv) {
		id = i;
		for (int i = 0; i < 50; i++)
			name[i] = n[i];
		for (int i = 0; i < 40; i++)
			phone[i] = p[i];
		casehandle = c;
		yearspend = y;
		revenue = r;
		casewon = cas;
		admit = a;
		totalRating = tr;
		totalReviews = tv;
		
	}

	lawyer(const lawyer& other) {
		id = other.id;
		for (int i = 0; i < 50; i++)
			name[i] = other.name[i];
		for (int i = 0; i < 40; i++)
			phone[i] = other.phone[i];
		casehandle = other.casehandle;
		yearspend = other.yearspend;
		revenue = other.revenue;
		casewon = other.casewon;
		admit = other.admit;
		totalRating = other.totalRating;
		totalReviews = other.totalReviews;
		
	}
	int getid() const {
		return id;
	}

	const	char* getname() const {
		return name;
	}

	const	char* getphone() const {
		return phone;
	}

	int getcasehandle() const {
		return casehandle;
	}

	int getyearspend() const  {
		return yearspend;
	}

	int getrevenue() const  {
		return revenue;
	}

	int getcasewon() const {
		return casewon;
	}

	bool getadmit() const  {
		return admit;
	}

	void displaysuccess() {
		if (casehandle == 0) {
			cout << "No case handled so far, success rate is undefined  " << endl;
		}
		else {
			double rate = (double)casewon / casehandle*100.0;
			cout << "Success rate : " << rate << " % " << endl;
		}
	}

	void addFeedback(float rating) {
		if (rating >= 1 && rating <= 10) {
			totalRating += rating;
			totalReviews++;
			cout << "Thank you for your feedback!" << endl;
		}
		else {
			cout << "Invalid rating. Please enter a rating between 1 and 10." << endl;
		}
	}

	float getAverageRating() const {
		if (totalReviews == 0)
			return 0;
		return totalRating / totalReviews;
	}

	void displayRating() const {
		if (totalReviews == 0) {
			cout << "No ratings yet." << endl;
		}
		else {
			cout << "Average Rating: " << getAverageRating() << " (" << totalReviews << " reviews)" << endl;
		}
	}


	void display() {
		cout << "\nLawyer ID : " << id << endl;
		cout << "Lawyer Name : " << name << endl;
		cout << "Phone Number : " << phone << endl;
		cout << "Cases Handled : " << casehandle << endl;
		cout << "Years of Experience : " << yearspend << endl;
		cout << "Revenue Generated : " << revenue << endl;
	}

	int getid() {
		return id;
	}

	void discharge() {
		admit = false;
	}
};

class client {
private:
	int id;
	char name[50];
	char phone[60];
	char address[70];
	char cnic[80];
public:
	client() {
		id = 0;
	}

	client(int ci, char cn[50], char cp[60], char ca[70], char cc[80]) {
		id = ci;
		for (int i = 0; i < 50; i++)
			name[i] = cn[i];
		for (int i = 0; i < 60; i++)
			phone[i] = cp[i];
		for (int i = 0; i < 70; i++)
			address[i] = ca[i];
		for (int i = 0; i < 80; i++)
			cnic[i] = cc[i];
	}

	client(const client& other) {
		id = other.id;
		for (int i = 0; i < 50; i++)
			name[i] = other.name[i];
		for (int i = 0; i < 60; i++)
			phone[i] = other.phone[i];
		for (int i = 0; i < 70; i++)
			address[i] = other.address[i];
		for (int i = 0; i < 80; i++)
			cnic[i] = other.cnic[i];
	}
	int getid() const {
		return id;
	}

	const char* getname() const {
		return name;
	}

	const char* getphone() const {
		return phone;
	}

	const char* getaddress() const {
		return address;
	}

	const char* getcnic() const {
		return cnic;
	}

	void display() {
		cout << "\nClient ID : " << id << endl;
		cout << "Name : " << name << endl;
		cout << "Phone : " << phone << endl;
		cout << "Address : " << address << endl;
		cout << "CNIC : " << cnic << endl;
	}

	int getid() {
		return id;
	}

	void discharge() {
		id = false; 
	}
};

class appointment {
private:
	char date[10];
	char time[20];
	int lid;
	int cid;
public:
	appointment() {
		lid = 0;
		cid = 0;
	}

	appointment(char d[10], char t[20], int lawyerid, int clientid) {
		for (int i = 0; i < 10; i++)
			date[i] = d[i];
		for (int i = 0; i < 20; i++)
			time[i] = t[i];
		lid = lawyerid;
		cid = clientid;
	}

	appointment(const appointment& other) {
		for (int i = 0; i < 10; i++)
			date[i] = other.date[i];
		for (int i = 0; i < 20; i++)
			time[i] = other.time[i];
		lid = other.lid;
		cid = other.cid;
	}

	void display() {
		cout << "\nAppointment Date: " << date << endl;
		cout << "Time: " << time << endl;
		cout << "Lawyer ID: " << lid << endl;
		cout << "Client ID: " << cid << endl;
	}
};

class caseinfo {
protected:
	int id;
	char title[50];
	char status[30];
	int lawyerid;
	int clientid;

public:
	caseinfo() {
		id = 0;
		title[0] = '\0';
		status[0] = '\0';
		lawyerid = 0;
		clientid = 0;
	}

	virtual void set(int cid, char ct[50], char cs[30], int lid, int clid) {
		id = cid;
		for (int i = 0; i < 50; i++) title[i] = ct[i];
		for (int i = 0; i < 30; i++) status[i] = cs[i];
		lawyerid = lid;
		clientid = clid;
	}

	virtual void display() {
		cout << "Case ID: " << id << endl;
		cout << "Title: " << title << endl;
		cout << "Status: " << status << endl;
		cout << "Lawyer ID: " << lawyerid << endl;
		cout << "Client ID: " << clientid << endl;
	}
};

class criminalcase : public caseinfo {
public:
	void display() {
		cout << "=== Criminal Case ===" << endl;
		caseinfo::display();
	}
};

class civilcase : public caseinfo {
public:
	void display() {
		cout << "=== Civil Case ===" << endl;
		caseinfo::display();
	}
};

class familycase : public caseinfo {
public:
	void display() {
		cout << "=== Family Case ===" << endl;
		caseinfo::display();
	}
};


class view {
private:
	lawyer lawyers[100];
	client clients[200];
	appointment appointments[300];
	int lawyerl;
	int clientc;
	int appointmenta;
	criminalcase crim[50];
	civilcase civ[50];
	familycase fam[50];
	int crimc;
	int civc;
	int famc;

public:
	view() {
		lawyerl = 0;
		clientc = 0;
		appointmenta = 0;
		crimc = 0;
		civc = 0;
		famc = 0;
	}

	void addlawyer() {
		int id, casehandle, yearspend, revenue,casewon, totalReview;
		float totalRating;
		char name[50], phone[40];
		cout << "Enter Lawyer ID: ";
		cin >> id;
		cin.ignore();
		cout << "Enter Name: ";
		cin.getline(name, 50);
		cout << "Enter Phone: ";
		cin.getline(phone, 40);
		cout << "Cases Handled: ";
		cin >> casehandle;
		cout << "Years of Experience: ";
		cin >> yearspend;
		cout << "Revenue: ";
		cin >> revenue;
		cout << "Enter case he/she won : ";
		cin >> casewon;
		cout << "Enter total rating : ";
		cin >> totalRating;
		cout << "Enter total review : ";
		cin >> totalReview;
		lawyers[lawyerl++] = lawyer(id, name, phone, casehandle, yearspend, revenue,casewon, false,totalRating,totalReview);
		cout << "Lawyer added successfully!\n";
	}

	void addclient() {
		int id;
		char name[50], phone[60], address[70], cnic[80];
		cout << "Enter Client ID: ";
		cin >> id;
		cin.ignore();
		cout << "Enter Name: ";
		cin.getline(name, 50);
		cout << "Enter Phone: ";
		cin.getline(phone, 60);
		cout << "Enter Address: ";
		cin.getline(address, 70);
		cout << "Enter CNIC: ";
		cin.getline(cnic, 80);		
				clients[clientc++] = client(id, name, phone, address, cnic);
				cout << "Client added successfully!\n";
				
	}

	void viewlawyer() {
		cout << "\n--- All Lawyers ---\n";
		for (int i = 0; i < lawyerl; i++)
			lawyers[i].display();
	}

	void viewclient() {
		cout << "\n--- All Clients ---\n";
		for (int i = 0; i < clientc; i++)
			clients[i].display();
	}

	void createappointment() {
		int lid, cid;
		char date[10], time[20];
		cout << "Enter Lawyer ID: ";
		cin >> lid;
		cin.ignore();
		cout << "Enter Client ID: ";
		cin >> cid;
		cin.ignore();

		bool lawyerExists = false;
		bool clientExists = false;
		for (int i = 0; i < lawyerl; i++) {
			if (lawyers[i].getid() == lid) 
				lawyerExists = true;
		}
		for (int i = 0; i < clientc; i++) {
			if (clients[i].getid() == cid) 
				clientExists = true;
		}
		if (!lawyerExists) {
			cout << "Lawyer not found. Add lawyer first.\n";
			return;
		}
		if (!clientExists) {
			cout << "Client not found. Add client first.\n";
			return;
		}

		cout << "Enter Date (date only): ";
		cin.getline(date, 10);
		cout << "Enter Time (e.g. 2PM): ";
		cin.getline(time, 20);

		appointments[appointmenta++] = appointment(date, time, lid, cid);
		cout << "Appointment created successfully!\n";
	}

	void discharge(int deleteID) {
		bool found = false;
		for (int i = 0; i < clientc; i++) {
			if (clients[i].getid() == deleteID) {
				for (int j = i; j < clientc - 1; j++) {
					clients[j] = clients[j + 1];
				}
				clientc--;
				cout << "Client deleted successfully.\n";
				found = true;
				break;
			}
		}
		if (!found) {
			cout << "Client is not added yet.\n";
		}
	}


	void dischargelawyer(int deleteID) {
		bool found = false;
		for (int i = 0; i < lawyerl; i++) {
			if (lawyers[i].getid() == deleteID) {
				for (int j = i; j < lawyerl - 1; j++) {
					lawyers[j] = lawyers[j + 1];
				}
				lawyerl--;
				cout << "Lawyer deleted successfully.\n";
				found = true;
				break;
			}
		}
		if (!found) {
			cout << "Lawyer is not added yet.\n";
		}
	}


	void searchlawyer() {
		int id;
		cout << "Enter Lawyer ID to search: ";
		cin >> id;
		bool found = false;

		for (int i = 0; i < lawyerl; i++) {
			if (lawyers[i].getid() == id) {
				lawyers[i].display();
				found = true;
				break;
			}
		}
		if (!found) {
			cout << "Lawyer is not added yet.\n";
		}
	}


	void searchclient() {
		int id;
		cout << "Enter Client ID to search: ";
		cin >> id;
		bool found = false;

		for (int i = 0; i < clientc; i++) {
			if (clients[i].getid() == id) {
				clients[i].display();
				found = true;
				break;
			}
		}
		if (!found) {
			cout << "Client is not added yet.\n";
		}
	}

	void addlawyertofile() {
		ofstream file("lawyer.txt");
		if (!file) {
			cout << "Error opening file to write" << endl;
			return;
		}
		for (int i = 0; i < lawyerl; i++) {
			file << "Lawyer ID : " << lawyers[i].getid() << endl;
			file << "Name : ";
			for (int j = 0; j < 50 && lawyers[i].getname()[j] != '\0'; j++) {
				file << lawyers[i].getname()[j];
			}
			file << endl;
			file << "Phone :";
			for (int j = 0; j < 40 && lawyers[i].getphone()[j] != '\0'; j++) {
				file << lawyers[i].getphone()[j];
			}
			file << endl;
			file << "Cases handled : " << lawyers[i].getcasehandle() << endl;
			file << "Years spend : " << lawyers[i].getyearspend() << endl;
			file << "Revenue generated : " << lawyers[i].getrevenue() << endl;
			file << "..................................................." << endl;
		}
		file.close();
		cout << "All lawyer data saved to lawyer.txt " << endl;
	}

	void addclienttofile() {
		ofstream file1("client.txt");
		if (!file1) {
			cout << "Error opening the writing file" << endl;
			return;
		}
		for (int i = 0; i < clientc; i++) {
			file1 << "Client ID : " << clients[i].getid() << endl;

			file1 << "Client Name : " << clients[i].getname() << endl;
			file1 << "Client Phone : " << clients[i].getphone() << endl;
			file1 << "Client Address : " << clients[i].getaddress() << endl;
			file1 << "Client CNIC : " << clients[i].getcnic() << endl;

			file1 << "......................................" << endl;
		}
		file1.close();
		cout << "All client data saved to client.txt" << endl;
	}

	void viewsuccessratebyid() {
		int id;
		cout << "Enter ID of that lawyer whose success rate you want to see :";
		cin >> id;
		bool found = false;
		for (int i = 0; i < lawyerl; i++) {
			if (lawyers[i].getid() == id) {
				cout << "Lawyer name : " << lawyers[i].getname() << endl;
				lawyers[i].displaysuccess();
				found = true;
				break;
			}
		}
		if (!found) {
			cout << "Lawyer is not found" << endl;
		}
	}

	void giveFeedback() {
		int id;
		cout << "Enter Lawyer ID to give feedback: ";
		cin >> id;

		for (int i = 0; i < lawyerl; i++) {
			if (lawyers[i].getid() == id) {
				float rating;
				cout << "Enter rating (1 to 10): ";
				cin >> rating;
				lawyers[i].addFeedback(rating);
				cout << "Updated Rating: ";
				lawyers[i].displayRating();
				return;
			}
		}
		cout << "Lawyer not found.\n";
	}
	void addcase() {
		int type;
		int id;
		int lid;
		int cid;
		char title[50];
		char status[30];

		cout << "Enter Case ID: ";
		cin >> id;
		cin.ignore();
		cout << "Enter Case Title: ";
		cin.getline(title, 50);
		cout << "Enter Case Status (Open/Closed): ";
		cin.getline(status, 30);
		cout << "Enter Lawyer ID: ";
		cin >> lid;
		cout << "Enter Client ID: ";
		cin >> cid;
		cout << "1. Criminal case" << endl;
		cout << "2. Civil case " << endl;
		cout << "3. Family case " << endl;
		cout << "Select Case Type : ";
		cin >> type;

		if (type == 1) {
			crim[crimc].set(id, title, status, lid, cid);
			crimc++;
		}
		else if (type == 2) {
			civ[civc].set(id, title, status, lid, cid);
			civc++;
		}
		else {
			fam[famc].set(id, title, status, lid, cid);
			famc++;
		}
		cout << "Case added successfully." << endl;
	}

	void viewallcases() {
		cout << "========== Criminal Cases ==========" << endl;
		for (int i = 0; i < crimc; i++) {
			crim[i].display();
			cout << "-----------------------\n";
		}
		cout << "========== Civil Cases ==========" << endl;
		for (int i = 0; i < civc; i++) {
			civ[i].display();
			cout << "-----------------------\n";
		}
		cout << "========== Family Cases ==========" << endl;
		for (int i = 0; i < famc; i++) {
			fam[i].display();
			cout << "-----------------------\n";
		}
	}


};



int main() {
	view views;
	int choice;
	do {
		cout << "  =================================================" << endl;
		cout << " |                                                 | " << endl;
		cout << " |         LEGAL CASE MANAGEMENT SYSTEM            |" << endl;
		cout << " |                                                 |" << endl;
		cout << "  =================================================" << endl;
		cout << "1.  Add New Lawyer" << endl;
		cout << "2.  Add New Client" << endl;
		cout << "3.  View All Lawyers" << endl;
		cout << "4.  View All Clients" << endl;
		cout << "5.  Create Appointment" << endl;
		cout << "6.  Search Lawyer by ID " << endl;
		cout << "7.  Search Client by ID " << endl;
		cout << "8.  Remove Client" << endl;
		cout << "9.  Remove lawyer" << endl;
		cout << "10. Add lawyer data to file" << endl;
		cout << "11. Add client data to file" << endl;
		cout << "12. View success rate of lawyer by ID " << endl;
		cout << "13. Give feedback to a lawyer " << endl;
		cout << "14. Add new case " << endl;
		cout << "15. View all cases " << endl;
		cout << "16. Exit" << endl;
		cout << "===================================================" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1: 
			views.addlawyer();
			break;
		case 2:
			views.addclient();
			break;
		case 3:
			views.viewlawyer();
			break;
		case 4:
			views.viewclient();
			break;
		case 5:
			views.createappointment();
			break;
		case 6: 
			views.searchlawyer();
			break;
		case 7:
			views.searchclient();
			break;
		case 8:
			int id;
			cout << "Enter Client ID to delete ";
			cin >> id;
			views.discharge(id);
			break;
		case 9:
			int iD;
			cout << "Enter Lawyer ID to delete ";
			cin >> iD;
			views.dischargelawyer(iD);
			break;
		case 10:
			views.addlawyertofile();
			break;
		case 11:
			views.addclienttofile();
			break;
		case 12:
			views.viewsuccessratebyid();
			break;
		case 13:
			views.giveFeedback();
			break;
		case 14:
			views.addcase();
			break;
		case 15:
			views.viewallcases();
			break;
		case 16:
			cout << "Exiting...\n"; 
			break;
		default:
			cout << "Invalid choice!\n";
		}
	} while (choice != 16);

	system("pause");
	return 0;
}
