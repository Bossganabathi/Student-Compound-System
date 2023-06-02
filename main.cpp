#include<iostream>
#include<mysql.h>
#include<sstream>
#include<fstream>

using namespace std;

int aa;
int qstate;
MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res;

void MainPage();
void AddCompound();
//void DisplayStudent();
void UpdateStudent();
void DeleteRecord();
void IndividualRecord();
void Payment();
void MonthlyRecord();
void AddStaffRecord();
void DeleteStaffRecord();
void CategoryCase();
void DataPercentage();
void DailyRecord();
void RangeRecord();

int main() {

	system("title Connect C++");

	class db_response
	{
	public:
		static void ConnectionFunction()
		{
			conn = mysql_init(0);
			if (conn)
			{

				//cout << "Database Connected" << endl;
				system("cls");
			}

			else
				cout << "Failed to connect" << mysql_errno(conn) << endl;
			conn = mysql_real_connect(conn, "localhost", "root", "", "compoundsystem", 3306, NULL, 0);
			if (conn)
			{

				//cout << "Database connected to mysql" << conn << endl;
				//system("pause");

			}
			else
				cout << "Failed to connect" << mysql_errno(conn) << endl;
		}
	};

	db_response::ConnectionFunction();
	
	

	char choice;
	string username, password;

	cout << "\n\t\t\t\t********************************************************************************* ";
	cout << "\n\t\t\t\t|                                                                               | ";
	cout << "\n\t\t\t\t|                       WELCOME TO UNIVERSITY COMPOUND SYSTEM                   | ";
	cout << "\n\t\t\t\t|                                                                               | ";
	cout << "\n\t\t\t\t********************************************************************************* ";
	cout << "\n\t\t\t\t|                                                                               | ";
	cout << "\n\t\t\t\t|                                LOGIN PAGE                                     |";
	cout << "\n\t\t\t\t|                                                                               | ";
	cout << "\n\t\t\t\t********************************************************************************* ";
	cout << "\n\n\n\n\t\t\t\t\t\tEnter Your Username: ";
	cin >> username;
	cout << "\n\n\t\t\t\t\t\tEnter Your Password: ";
	cin >> password;

	qstate = mysql_query(conn, "SELECT * FROM stafflogin");

	if (!qstate)
	{
		res = mysql_store_result(conn);
		while ((row = mysql_fetch_row(res)))
		{
			if (username == row[1] && password == row[2])
			{
				cout << "\n\n\n\n\n\t\t\t\t********************************************************************************* ";
				cout << "\n\t\t\t\t|                    SUCCESFULLY LOGIN INTO THE SYSTEM !!                       |";
				cout << "\n\t\t\t\t*********************************************************************************";
				cout << endl;

				cout << "\n\n\t\t\t\tPress N to proceed to the Main Page or press any other key to Exit : ";
				cin >> choice;
				if (choice == 'N' || choice == 'n')
				{
					MainPage();
				}
				else
				{
					exit(0);
				}
			}
			else
			{
				cout << endl;
				cout << "\n\n\n\n\n\t\t\t\t********************************************************************************* ";
				cout << "\n\t\t\t\t|                    FAIL TO LOGIN INTO THE SYSTEM !!                           |";
				cout << "\n\t\t\t\t|                                                                               | ";
				cout << "\n\t\t\t\t|                 ATTENTION : WRONG USERNAME OR PASSWORD...                     | ";
				cout << "\n\t\t\t\t|                          PLEASE TRY AGAIN.                                    | ";
				cout << "\n\t\t\t\t|                                                                               | ";
				cout << "\n\t\t\t\t*********************************************************************************";
				cout << endl;

				cout << "\n\n\t\t\t\tPress Y to go Login Menu again or press N to Exit : ";
				cout << "\n\t\t\t\tDo You Wish to Try Again to Login ? [ Y | N ] : ";
				cin >> choice;
				if (choice == 'Y' || choice == 'y')
				{
					main();
				}
				else if (choice == 'N' || choice == 'n')
				{
					exit(0);
				}
				else
				{
					cout << "\n\n\t\tWrong Choice is Selected..." << endl;
				}
			}
		}
	}
	return 0;

}

void MainPage() {

	system("cls");

	int choose2;

		int chooseAdmin;
		int chooseRecord;

		cout << "\n\t\t\t\t********************************************************************************* ";
		cout << "\n\t\t\t\t|                             Welcome Staff Portal                              | ";
		cout << "\n\t\t\t\t|  CHOOSE ANY ONE:                                                              | ";
		cout << "\n\t\t\t\t********************************************************************************* ";
		cout << "\n\t\t\t\t|          1.Add compound                                                       | ";
		cout << "\n\t\t\t\t|          2.Data Pertange                                                      |";
		cout << "\n\t\t\t\t|          3.Update student compound Record                                     | ";
		cout << "\n\t\t\t\t|          4.Delete student compound                                            | ";
		cout << "\n\t\t\t\t|          5.Compound Payment                                                   | ";
		cout << "\n\t\t\t\t|          6.Total Record                                                       | ";
		cout << "\n\t\t\t\t|          7.Setting                                                            | ";
		cout << "\n\t\t\t\t|          8.Exit															   | ";
		cout << "\n\t\t\t\t********************************************************************************* ";
		cout << "\n\n\n\n\t\t\t\t\t\tSelect Option >>";
		cin >> choose2;

		switch (choose2)
		{
		case 1: AddCompound();
			break;

		case 2: DataPercentage();
			break;

		case 3: UpdateStudent();
			break;

		case 4: DeleteRecord();
			break;

		case 5: Payment();
			break;

		case 6:

			cout << "\n\t\t\t\t********************************************************************************* ";
			cout << "\n\t\t\t\t|                             Choose Record                                     | ";
			cout << "\n\t\t\t\t|  CHOOSE ANY ONE:                                                              | ";
			cout << "\n\t\t\t\t********************************************************************************* ";
			cout << "\n\t\t\t\t|          1.Individual Record                                                  | ";
			cout << "\n\t\t\t\t|          2.Monthly Record                                                     |";
			cout << "\n\t\t\t\t|          3.Category cases                                                     | ";
			cout << "\n\t\t\t\t|          4.Daily Record                                                       | ";
			cout << "\n\t\t\t\t|          5.Range Record                                                       | ";
			cout << "\n\t\t\t\t********************************************************************************* ";
			cout << "\n\n\n\n\t\t\t\t\t\tSelect Option >> ";

			cin >> chooseRecord;

			switch (chooseRecord) {

			case 1: IndividualRecord();
				break;

			case 2: MonthlyRecord();
				break;

			case 3: CategoryCase();
				break;

			case 4: DailyRecord();
				break;

			case 5: RangeRecord();
				break;
			}

			break;

		case 7:

			cout << "Setting \n";

			cout << "1. Add Staff Account:\n";
			cout << "2. Delete Staff Account:\n";

			cout << "Please choose any one:";
			cin >> chooseAdmin;

			switch (chooseAdmin) {

			case 1: AddStaffRecord();
				break;

			case 2: DeleteStaffRecord();
				break;

			}

			break;

		case 8:


			exit(0);

			break;
		}
}

void AddCompound() {

	system("cls");

	string Id;
	string Matric;
	string Name;
	string Reason;
	string Day;
	string Month;
	string Year;
	string Amount;
	string Payment = "Pending";
	char reason11;

	cout << "\n\t\t\t\t********************************************************************************* ";
	cout << "\n\t\t\t\t|                             Enter Student Deatil                              | ";
	cout << "\n\t\t\t\t********************************************************************************* ";
	cout <<"\n\t\t\t\t Enter student Name:";
	cin >> Name;
	cout <<"\n\t\t\t\tEnter student Matric no:";
	cin >> Matric;
	cout <<"\n\t\t\t\tList of Offence: \n";
	cout <<"\n\t\t\t\tA. Academic dishonesty (Academic): \n";
	cout <<"\n\t\t\t\tB. Falsification of documents (Falsification): \n";
	cout <<"\n\t\t\t\tC. Library Late Book Return (LBR): \n";
	cout <<"\n\t\t\t\tD. Parking (Parking): \n";
	cout <<"\n\t\t\t\tE. Litering (Litering): \n";
	cout <<"\n\t\t\t\tF. Interference with University functions (Interference) : \n";
	cout <<"\n\t\t\t\tEnter The offence(A - F):";
	cin >> reason11;
	if (reason11=='A') {

		Reason = "Academic";
	}
	else if (reason11 == 'B') {

		Reason = "Falsification";

	}
	else if (reason11 == 'C') {

		Reason = "LBR";

	}
	else if (reason11 == 'D') {

		Reason = "Parking";

	}
	else if (reason11 == 'E') {

		Reason = "Litering";

	}
	else if (reason11 == 'F') {

		Reason = "Interference";

	}
	else {

		cout <<"\n\t\t\t\tENTER PROPER VALUE";

	}
	cout <<"\n\t\t\t\tEnter Day(1 - 31):";
	cin >> Day;
	cout <<"\n\t\t\t\tEnter Month(1 - 12):";
	cin >> Month;
	cout <<"\n\t\t\t\tEnter Year:";
	cin >> Year;
	cout <<"\n\t\t\t\tEnter Compound Amount(RM):";
	cin >> Amount;

	string insert_query1 = "INSERT INTO studentcompound(NAME,MATRIC,Reason,Day,Month,Year,Amount,Payment) VALUES('" + Name +"', '"+  Matric +"','"+ Reason +"','"+ Day +"','"+ Month +"','"+ Year +"','"+ Amount +"','"+ Payment +"') ";
	//string insert_query1 = "INSERT INTO studentrecord(STUD_ID,NAME,MATRIC,Reason,Payment,Amount) VALUES('" + Id + "','" + Name + "', '" + Matric + "','" + Reason + "','" + Payment + "','" + Amount + "') ";
	const char* q = insert_query1.c_str();
	qstate = mysql_query(conn, q);


	if (!qstate)
	{
		cout << endl << "\n\t\t\t\tData Added Sucessfully" << endl;
		system("pause");
		MainPage();

	}
	else {

		cout << "\n\t\t\t\tQuery execution problem!" << mysql_errno(conn) << endl;

	}

}

  /*  void DisplayStudent() {

	system("cls");
	char choose;
	double sum;
	string actualmonth;
	string aa;

	cout << "List of all student \n";

	cout << "type \n";
	cin >> aa;

	qstate = mysql_query(conn, "SELECT COUNT(NAME) FROM studentcompound WHERE Month= '4' ");
	res = mysql_store_result(conn);
	while ((row = mysql_fetch_row(res)))
	{
		cout << "TOTAL PENDING CASES:" << row[0] << endl;
	}

	qstate = mysql_query(conn, "SELECT COUNT(NAME) FROM studentcompound");
	res = mysql_store_result(conn);
	while ((row = mysql_fetch_row(res)))
	{
		cout << "TOTAL CASES RECORDED:" << row[0] << endl;
	}

	qstate = mysql_query(conn, "SELECT COUNT(NAME) FROM studentcompound WHERE Payment='Paid' ");
	res = mysql_store_result(conn);
	while ((row = mysql_fetch_row(res)))
	{
		cout << "TOTAL PAID CASES:" << row[0] << endl;
	}

	qstate = mysql_query(conn, "SELECT SUM(amount) FROM totalamount");
	res = mysql_store_result(conn);
	while ((row = mysql_fetch_row(res)))
	{
		cout << "TOTAL amount:" << row[0] << endl;
	}



	qstate = mysql_query(conn, "SELECT * FROM studentcompound");
	if (!qstate) {

		res = mysql_store_result(conn);
		
			printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
			printf("|                                               LIST ALL STUDENT                                                                           |\n");
			printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
			printf("| %-25s | %-25s | %-15s |  %-10s  | %-10s | %-10s | %-10s | %-10s |\n", "Name", "Matric","Reason","Day","Month","Year","Amount","Payment");
			printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
			while ((row=mysql_fetch_row(res)))
			{
				
				printf("| %-25s | %-25s | %-15s |  %-10s  | %-10s | %-10s | %-10s | %-10s |\n", row[0],row[1],row[2],row[3],row[4], row[5], row[6], row[7]);
				
			}
			printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
	
	}


	else
	{
		cout << "Query execution problem" << mysql_errno(conn)<<endl;
	}

}  */

void DataPercentage() {

	system("cls");
	double r1;
	double r2;
	double r3;
	double r4;
	double r5;
	double r6;
	double r7;
	double r8;
	double rACADEMIC_DISHONESTY;
	double rFALSIFICATION_OF_DOCUMENTS;
	double rviolence;
	double rsexual;
	double rintimidation;
	double rInterference;
	double rAlcohol;

	char choice;
	char choiceprint;
	string  strID;
	
	cout << "\n\t\t\t\t********************************************************************************* ";
	cout << "\n\t\t\t\t                             Annual Record                                        ";
	cout << "\n\t\t\t\t********************************************************************************* ";
	cout << "\n\n\n\n\t\t\t\t\t\tEnter Year >>";
	cin >> strID;

	string findbyid_query = "SELECT COUNT(NAME) FROM studentcompound WHERE Year='" + strID + "'";
	const char* qi = findbyid_query.c_str();
	qstate = mysql_query(conn, qi);

	if (!qstate)
	{
		res = mysql_store_result(conn);
		cout << endl;

		
		while ((row = mysql_fetch_row(res)))
		{
			cout <<"TOTAL CASES RECORDED:"<< row[0];
			r1 = stoi(row[0]);
		}
		
	}

	string findbyid_query1 = "SELECT COUNT(NAME) FROM studentcompound WHERE Reason='Academic' AND Year='" + strID + "'";
	const char* qi1 = findbyid_query1.c_str();
	qstate = mysql_query(conn, qi1);

	if (!qstate)
	{
		res = mysql_store_result(conn);
		cout << endl;


		while ((row = mysql_fetch_row(res)))
		{
			cout << "TOTAL ACADEMIC_DISHONESTY cases:" << row[0] << endl;
			r2 = stoi(row[0]);
			rACADEMIC_DISHONESTY = (r2 / r1) * 100;

			cout << "Percentage:" << rACADEMIC_DISHONESTY << endl;
		}

	}

	string findbyid_query2 = "SELECT COUNT(NAME) FROM studentcompound WHERE Reason='Falsification' AND Year='" + strID + "'";
	const char* qi2 = findbyid_query2.c_str();
	qstate = mysql_query(conn, qi2);

	if (!qstate)
	{
		res = mysql_store_result(conn);
		cout << endl;


		while ((row = mysql_fetch_row(res)))
		{
			cout << "TOTAL FALSIFICATION_OF_DOCUMENTS cases:" << row[0] << endl;
			r3 = stoi(row[0]);
			rFALSIFICATION_OF_DOCUMENTS = (r3 / r1) * 100;

			cout << "Percentage:" << rFALSIFICATION_OF_DOCUMENTS << endl;
		}

	}

	string findbyid_query3 = "SELECT COUNT(NAME) FROM studentcompound WHERE Reason='LBR' AND Year='" + strID + "'";
	const char* qi3 = findbyid_query3.c_str();
	qstate = mysql_query(conn, qi3);

	if (!qstate)
	{
		res = mysql_store_result(conn);
		cout << endl;


		while ((row = mysql_fetch_row(res)))
		{
			cout << "TOTAL Late Book return cases :" << row[0] << endl;
			r4 = stoi(row[0]);
			rviolence = (r4 / r1) * 100;

			cout << "Percentage:" << rviolence << endl;
		}

	}

	string findbyid_query4 = "SELECT COUNT(NAME) FROM studentcompound WHERE Reason='Parking' AND Year='" + strID + "'";
	const char* qi4 = findbyid_query4.c_str();
	qstate = mysql_query(conn, qi4);

	if (!qstate)
	{
		res = mysql_store_result(conn);
		cout << endl;


		while ((row = mysql_fetch_row(res)))
		{
			cout << "TOTAL Parking cases:" << row[0] << endl;
			r5 = stoi(row[0]);
			rsexual = (r5 / r1) * 100;

			cout << "Percentage:" << rsexual << endl;
		}

	}

	string findbyid_query5 = "SELECT COUNT(NAME) FROM studentcompound WHERE Reason='Litering' AND Year='" + strID + "'";
	const char* qi5 = findbyid_query5.c_str();
	qstate = mysql_query(conn, qi5);

	if (!qstate)
	{
		res = mysql_store_result(conn);
		cout << endl;


		while ((row = mysql_fetch_row(res)))
		{
			cout << "TOTAL Litering cases:" << row[0] << endl;
			r6 = stoi(row[0]);
			rintimidation = (r6 / r1) * 100;

			cout << "Percentage:" << rintimidation << endl;
		}

	}

	string findbyid_query6 = "SELECT COUNT(NAME) FROM studentcompound WHERE Reason='Interference' AND Year='" + strID + "'";
	const char* qi6 = findbyid_query6.c_str();
	qstate = mysql_query(conn, qi6);

	if (!qstate)
	{
		res = mysql_store_result(conn);
		cout << endl;


		while ((row = mysql_fetch_row(res)))
		{
			cout << "TOTAL Interference with University functions cases:" << row[0] << endl;
			r7 = stoi(row[0]);
			rInterference = (r7 / r1) * 100;

			cout << "Percentage:" << rInterference << endl;
		}

	}


	cout << "\n\n\t\t\t\tPress N to proceed to the Main Page or press any other key to Exit : ";
	cin >> choice;
	if (choice == 'N' || choice == 'n')
	{
		MainPage();
	}
	else
	{
		exit(0);
	}
	
}

void UpdateStudent() {

	system("cls");

	string matricno="";
	string name="";
	string reason = "";
	string day = "";
	string month = "";
	string year = "";
	string amount = "";
	string payment = "";

	string items[5000];
	int indexForId = 0;
	string studID;
	bool HaveException = false;
	bool NotInDatabase = false;

	//store Variable;
	string storeid = "";
	string storename = "";
	string storematricno = "";
	string storereason = "";
	string storeday ="";
	string storemonth = "";
	string storeyear = "";
	string storeamount = "";
	string storepayment = "";

	cout << "Update Student \n";

	qstate = mysql_query(conn, "SELECT * FROM studentcompound");
	if (!qstate)
	{
		
		res = mysql_store_result(conn);

		printf("---------------------------------------------------------------------------------------------------------------------------- \n");
		printf("|                                               LIST ALL STUDENT                                                           | \n");
		printf("---------------------------------------------------------------------------------------------------------------------------- \n");
		printf("| %-25s | %-25s | %-15s |  %-10s  | %-10s | %-10s | \n", "Name", "Matric", "Reason", "Day", "Month", "Year", "Amount", "Payment");
		printf("---------------------------------------------------------------------------------------------------------------------------- \n");
		while ((row = mysql_fetch_row(res)))
		{
			printf("| %-25s | %-25s | %-15s |  %-10s  | %-10s | %-10s | \n", row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7]);
			items[indexForId] = row[0];
			indexForId++;
		}
		printf("---------------------------------------------------------------------------------------------------------------------------- \n");

	}
	else {

		cout << "Query Execute Problem" << mysql_errno(conn) << endl;

	}

	try
	{
		cout << endl;
		cout << "Enter Student ID(Matric No): \n";
		cin >> studID;
		cout << endl;
	}
	catch (exception e)
	{
		cout << "Please enter the valid value" << endl;
		HaveException = true;
		//goto Exit;
	}
	if (HaveException == false) {

		stringstream streamid;
		string strID;
		streamid << studID;
		streamid >> strID;

		for (int i = 0; i < indexForId; i++) {

			if (strID != items[i]) {

				NotInDatabase = false;

			}
			else {

				NotInDatabase = false;


			}
		}

		if (NotInDatabase == false) {

			string findbyid_query = "SELECT * FROM studentcompound WHERE Matric='" + strID + "'";
			const char* qi = findbyid_query.c_str();
			qstate = mysql_query(conn, qi);


			if (!qstate)
			{
				res = mysql_store_result(conn);
				cout << endl;
				while ((row = mysql_fetch_row(res)))
				{

					cout <<"Name:" << row[0] << "\nMatric:"<<row[1]<<"\nReason:"<<row[2]<<"\nDay:"<<row[3]<<"\nMonth:"<<row[4]<<"\nYear:"<<row[5]<<"\nAmount:"<<row[6]<< endl << endl;
					//storeid = row[0];
					storename = row[0];
					storematricno = row[1];
					storereason = row[2];
					storeday = row[3];
					storemonth = row[4];
					storeyear = row[5];
					storeamount = row[6];

				}
			}

			else {

				cout << "Query Execution Problem" << mysql_errno(conn) << endl;

			}

			cin.ignore(1, '\n');

			/*       
			
			getline(cin, matricno);
			if (matricno == "0") {

				matricno = storematricno;

			}
	
			*/
			//cout << "Enter Matric No(0 to not change): ";
			
			cout << "Enter Student Name(0 to not change): ";
			getline(cin, name);
			if (name == "0") {

				name = storename;

			}
			cout << "Enter Reason(0 to not change): ";
			getline(cin, reason);
			if (reason == "0") {

				reason = storereason;

			}
			cout << "Enter Day(0 to not change): ";
			getline(cin, day);
			if (day == "0") {

				day = storeday;

			}
			cout << "Enter Month(0 to not change): ";
			getline(cin, month);
			if (month == "0") {

				month = storemonth;

			}
			cout << "Enter Year(0 to not change): ";
			getline(cin, year);
			if (year == "0") {

				year = storeyear;

			}
			
			cout << "Enter Amount(0 to not change): ";
			getline(cin, amount);
			if (amount == "0") {

				amount = storeamount;

			}

		}

		string update_query = "UPDATE studentcompound SET NAME = '"+ name +"', Reason = '" + reason + "', Day = '" + day + "', Month = '" + month + "', Year = '" + year + "', Amount = '" + amount + "'WHERE Matric = '" + strID + "' ";
		//string update_query = "UPDATE studentrecord SET MATRIC =  '" + matricno + "', NAME = '"+ name +"', Reason = '" + reason +  "'WHERE STUD_ID = '" + strID + "' ";
		const char* qu = update_query.c_str();
		qstate = mysql_query(conn, qu);

		if (!qstate)
		{
			cout << endl << "Successfully saved in database" << endl;
			system("pause");
			MainPage();

		}
		else {

			cout << "Failed to update" << mysql_errno(conn) << endl;

		}

	}
	else {

		cout << "Not FOUND in database";
	}
}

void DeleteRecord() {

	system("cls");

	string matricno = "";
	string name = "";
	string reason = "";
	string day = "";
	string month = "";
	string year = "";
	string amount = "";
	string payment = "";

	string items[5000];
	int indexForId = 0;
	string studID;
	bool HaveException = false;
	bool NotInDatabase = false;


	cout << "\n\t\t\t\tDELETE STUDENT RECORD \n";

	qstate = mysql_query(conn, "SELECT * FROM studentcompound");
	if (!qstate)
	{

		res = mysql_store_result(conn);

		printf("---------------------------------------------------------------------------------------------------------------------------- \n");
		printf("|                                               LIST ALL STUDENT                                                           | \n");
		printf("---------------------------------------------------------------------------------------------------------------------------- \n");
		printf("| %-25s | %-25s | %-15s |  %-10s  | %-10s | %-10s | \n", "Name", "Matric", "Reason", "Day", "Month", "Year", "Amount", "Payment");
		printf("---------------------------------------------------------------------------------------------------------------------------- \n");
		while ((row = mysql_fetch_row(res)))
		{
			printf("| %-25s | %-25s | %-15s |  %-10s  | %-10s | %-10s | \n", row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7]);
			items[indexForId] = row[0];
			indexForId++;
		}
		printf("---------------------------------------------------------------------------------------------------------------------------- \n");

	}
	else {

		cout << "Query Execute Problem" << mysql_errno(conn) << endl;

	}

	try
	{
		cout << endl;
		cout << "\n\t\t\t\t********************************************************************************* ";
		cout << "\n\t\t\t\tEnter Student ID(Matric No):";
		cin >> studID;
		cout << endl;
	}
	catch (exception e)
	{
		cout << "Please enter the valid value" << endl;
		HaveException = true;
		//goto Exit;
	}
	if (HaveException == false) {

		stringstream streamid;
		string strID;
		streamid << studID;
		streamid >> strID;

		for (int i = 0; i < indexForId; i++) {

			if (strID != items[i]) {

				NotInDatabase = false;

			}
			else {

				NotInDatabase = false;


			}
		}

		if (NotInDatabase == false) {

			string delete_query = "DELETE FROM studentcompound WHERE Matric =  '" + strID + "' ";
			const char* qd = delete_query.c_str();
			qstate = mysql_query(conn, qd);

			if (!qstate)
			{
				cout << endl << "Data Delete " << endl;
				system("pause");
				MainPage();
			}
			else {

				cout << "Failed to delete" << mysql_errno(conn) << endl;

			}

		}

	}
	else {

		cout << "Not FOUND in database";
	}

}

void IndividualRecord() {

	system("cls");

	string items[5000];
	int indexForId = 0;
	string studID;
	string payment="Pending";
	char choice;
	bool HaveException = false;
	bool NotInDatabase = false;

		cout << "\n\t\t\t\t********************************************************************************* ";
		cout << "\n\t\t\t\t|                             Individual Record                                 | ";
		cout << "\n\t\t\t\t********************************************************************************* ";
		cout << "\n\t\t\t\tEnter Matric Number:";
		cin >> studID;


	if (HaveException == false) {

		stringstream streamid;
		string strID;
		streamid << studID;
		streamid >> strID;

		for (int i = 0; i < indexForId; i++) {

			if (strID != items[i]) {

				NotInDatabase = false;
			}
			else {

				NotInDatabase = false;
			}
		}

		if (NotInDatabase == false) {

			string findbyid_query = "SELECT * FROM studentcompound WHERE Matric='" + strID + "'";
			const char* qi = findbyid_query.c_str();
			qstate = mysql_query(conn, qi);


			if (!qstate)
			{
				res = mysql_store_result(conn);
				cout << endl;
				
				printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
				printf("|                                               INDIVIDUAL RECORD                                                                               |\n");
				printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
				printf("| %-25s | %-25s | %-15s |  %-10s  | %-10s | %-10s | %-10s | %-10s |\n", "Name", "Matric", "Reason", "Day", "Month", "Year", "Amount","Payment");
				printf("------------------------------------------------------------------------------------------------------------------------------------------------ \n");
				while ((row = mysql_fetch_row(res)))
				{
					printf("| %-25s | %-25s | %-15s |  %-10s  | %-10s | %-10s | %-10s | %-10s | \n", row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7]);
				}
				printf("------------------------------------------------------------------------------------------------------------------------------------------------ \n");


				/*   
				
				string findbyid_query1 = "SELECT SUM(Amount) FROM studentcompound WHERE Matric='" + strID + "'  && Payment='" + payment + "' ";
				const char* qi1 = findbyid_query1.c_str();
				qstate = mysql_query(conn, qi1);

				if (!qstate)
				{
					res = mysql_store_result(conn);
					cout << endl;

					while ((row = mysql_fetch_row(res)))
					{
						cout << "\n\t\t\tTOTAL AMOUNT SHOULD PAY:" << row[0];
					}

					

				}
				
				
				
				*/


				cout << "\n\n\t\t\t\tPress N to proceed to the Main Page or press any other key to Exit : ";
				cin >> choice;
				if (choice == 'N' || choice == 'n')
				{
					MainPage();
				}
				else
				{
					exit(0);
				}


			}

			else {

				cout << "Query Execution Problem" << mysql_errno(conn) << endl;

			}

		}

	}
	else {

		cout << "Not FOUND in database";
	}

}

void MonthlyRecord() {

	system("cls");

	string items[5000];
	int indexForId = 0;
	string month;
	string name;
	string payment = "Pending";
	bool HaveException = false;
	bool NotInDatabase = false;
	char choiceprint;
	int mon;
	string year;
	char choice;

	

	cout << "\n\t\t\t\t********************************************************************************* ";
	cout << "\n\t\t\t\t|                            MONTHLY RECORDED CASES                             | ";
	cout << "\n\t\t\t\t********************************************************************************* ";

	cout << "\n\t\t\t\t Enter Month:";
	cin >> month;
	cout << "\n\t\t\t\t Enter Year:";
	cin >> year;
	cout << endl;


	if (HaveException == false) {

		stringstream streamid;
		string strID;
		streamid << month;
		streamid >> strID;

		for (int i = 0; i < indexForId; i++) {

			if (strID != items[i]) {

				NotInDatabase = false;

			}
			else {

				NotInDatabase = false;


			}
		}

		if (NotInDatabase == false) {

			string findbyid_query = "SELECT * FROM studentcompound WHERE Month='" + strID + "' && Payment='"+  payment + "' && Year='" + year + "' ";
			const char* qi = findbyid_query.c_str();
			qstate = mysql_query(conn, qi);


			if (!qstate)
			{
				res = mysql_store_result(conn);
				cout << endl;

				printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
				printf("|                                               MONTHLY RECORD  (PENDING CASES)                                                                 | \n");
				printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
				printf("| %-25s | %-25s | %-15s | %-10s | %-10s | %-10s | %-10s | %-10s | \n", "Name", "Matric", "Reason", "Day", "Month", "Year", "Amount", "Payment");
				printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
				while ((row = mysql_fetch_row(res)))
				{
					printf("| %-25s | %-25s | %-15s | %-10s | %-10s | %-10s | %-10s | %-10s | \n", row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7]);
					

				}
				printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");



				cout << "---------------------------------------------------------------------------------------------------------------------------------------------\n";
				cout << "                                                UNIVERCITY TECHNICAL MALAYSIA MELAKA                                                         \n";
				if (month == "1") {

					cout <<"\n\t\t\t\tJANUARY CASES";

				}
				else if (month == "2") {

					cout <<"\n\t\t\t\tFEBRUARY CASES";

				}
				else if (month == "3") {

					cout <<"\n\t\t\t\tMARCH CASES";

				}
				else if (month == "4") {

					cout <<"\n\t\t\t\tAPRIL CASES";

				}
				else if (month == "5") {

					cout <<"\n\t\t\t\tMAY CASES";

				}
				else if (month == "6") {

					cout <<"\n\t\t\t\tJUNE CASES";

				}
				else if (month == "7") {

					cout <<"\n\t\t\t\tJULY CASES";

				}
				else if (month == "8") {

					cout <<"\n\t\t\t\tAUGEST CASES";

				}
				else if (month == "9") {

					cout <<"\n\t\t\t\tSEPTEMBER CASES";

				}
				else if (month == "10") {

					cout <<"\n\t\t\t\tOCTOBER CASES";

				}
				else if (month == "11") {

					cout <<"\n\t\t\t\tNOVEMBER CASES";

				}
				else if (month == "12") {

					cout <<"\n\t\t\t\tDECEMBER CASES";

				}



				string findbyid_query1 = "SELECT COUNT(NAME) FROM studentcompound WHERE Month='" + strID + "'  && Year='" + year + "' && Payment='" + payment + "' && Reason='Academic' ";
				const char* qi1 = findbyid_query1.c_str();
				qstate = mysql_query(conn, qi1);

				if (!qstate)
				{
					res = mysql_store_result(conn);
					cout << endl;

					while ((row = mysql_fetch_row(res)))
					{
						cout << "\n\t\t\tTOTAL Academic CASES:" << row[0];
					}

				}

				string findbyid_query2 = "SELECT COUNT(NAME) FROM studentcompound WHERE Month='" + strID + "'  && Year='" + year + "' && Payment='" + payment + "' && Reason='Falsification' ";
				const char* qi2 = findbyid_query2.c_str();
				qstate = mysql_query(conn, qi2);

				if (!qstate)
				{
					res = mysql_store_result(conn);
					cout << endl;

					while ((row = mysql_fetch_row(res)))
					{
						cout << "\n\t\t\tTOTAL Falsification CASES:" << row[0];
					}

				}

				string findbyid_query3 = "SELECT COUNT(NAME) FROM studentcompound WHERE Month='" + strID + "'  && Year='" + year + "' && Payment='" + payment + "' && Reason='LBR' ";
				const char* qi3 = findbyid_query3.c_str();
				qstate = mysql_query(conn, qi3);

				if (!qstate)
				{
					res = mysql_store_result(conn);
					cout << endl;

					while ((row = mysql_fetch_row(res)))
					{
						cout << "\n\t\t\tTOTAL LBR CASES:" << row[0];
					}

				}

				string findbyid_query4 = "SELECT COUNT(NAME) FROM studentcompound WHERE Month='" + strID + "'  && Year='" + year + "' && Payment='" + payment + "' && Reason='Parking' ";
				const char* qi4 = findbyid_query4.c_str();
				qstate = mysql_query(conn, qi4);

				if (!qstate)
				{
					res = mysql_store_result(conn);
					cout << endl;

					while ((row = mysql_fetch_row(res)))
					{
						cout << "\n\t\t\tTOTAL Parking CASES:" << row[0];
					}

				}

				string findbyid_query5 = "SELECT COUNT(NAME) FROM studentcompound WHERE Month='" + strID + "'  && Year='" + year + "' && Payment='" + payment + "' && Reason='Litering' ";
				const char* qi5 = findbyid_query5.c_str();
				qstate = mysql_query(conn, qi5);

				if (!qstate)
				{
					res = mysql_store_result(conn);
					cout << endl;

					while ((row = mysql_fetch_row(res)))
					{
						cout << "\n\t\t\tTOTAL Litering CASES:" << row[0];
					}

				}

				string findbyid_query6 = "SELECT COUNT(NAME) FROM studentcompound WHERE Month='" + strID + "'  && Year='" + year + "' && Payment='" + payment + "' && Reason='Interference' ";
				const char* qi6 = findbyid_query6.c_str();
				qstate = mysql_query(conn, qi6);

				if (!qstate)
				{
					res = mysql_store_result(conn);
					cout << endl;

					while ((row = mysql_fetch_row(res)))
					{
						cout << "\n\t\t\tTOTAL Interference CASES:" << row[0];
					}

				}

				string findbyid_query8 = "SELECT SUM(Amount) FROM studentcompound WHERE Month='" + strID + "'  && Year='" + year + "' && Payment='" + payment + "'";
				const char* qi8 = findbyid_query8.c_str();
				qstate = mysql_query(conn, qi8);

				if (!qstate)
				{
					res = mysql_store_result(conn);
					cout << endl;

					while ((row = mysql_fetch_row(res)))
					{
						cout <<"\n\t\t\tTOTAL AMOUNT SHOULD PAY:" << row[0];
					}

				}

				string findbyid_query81 = "SELECT SUM(Amount) FROM studentcompound WHERE Month='" + strID + "'  && Year='" + year + "' && Payment='Paid' ";
				const char* qi81 = findbyid_query81.c_str();
				qstate = mysql_query(conn, qi81);

				if (!qstate)
				{
					res = mysql_store_result(conn);
					cout << endl;

					while ((row = mysql_fetch_row(res)))
					{
						cout << "\n\t\t\tTOTAL AMOUNT SO FAR COLLECTED:" << row[0];
					}

				}

				string findbyid_query9 = "SELECT COUNT(NAME) FROM studentcompound WHERE Month='" + strID + "'  && Year='" + year + "' && Payment='" + payment + "' ";
				const char* qi9 = findbyid_query9.c_str();
				qstate = mysql_query(conn, qi9);

				if (!qstate)
				{
					res = mysql_store_result(conn);
					cout << endl;


					while ((row = mysql_fetch_row(res)))
					{
						cout <<"\n\t\t\tTOTAL PENDING CASES IN MONTH "<< strID <<":" << row[0];
					}

				}

				string findbyid_query10 = "SELECT COUNT(NAME) FROM studentcompound WHERE Month='" + strID + "'  && Year='" + year + "' ";
				const char* qi10 = findbyid_query10.c_str();
				qstate = mysql_query(conn, qi10);

				if (!qstate)
				{
					res = mysql_store_result(conn);
					cout << endl;


					while ((row = mysql_fetch_row(res)))
					{
						cout <<"\n\t\t\tTOTAL REGISTER CASES IN MONTH " << strID << ":" << row[0];
					}

				}

			}

			else {

				cout << "Query Execution Problem" << mysql_errno(conn) << endl;

			}


			cout << "\n\n\t\t\t\tPress N to print the data in excel or press T to print the report in notepad  or Press M to Main Page : ";
			cin >> choiceprint;
			if (choiceprint == 'N' || choiceprint == 'n')
			{
				
				ofstream myFile;
				myFile.open("Monthly Data.csv");

				myFile << "Name" <<","<<"Matric"<<","<<"Reason"<<","<<"Day"<<","<<"Month" <<","<<"Year"<<","<<"Amount"<<","<<"Payment"<<"\n";

				string findbyid_query = "SELECT * FROM studentcompound WHERE Month='" + strID + "' AND Payment='" + payment + "' ";
				const char* qi = findbyid_query.c_str();
				qstate = mysql_query(conn, qi);

				res = mysql_store_result(conn);
				cout << endl;

				while ((row = mysql_fetch_row(res)))
				{
					//myFile<<row[0]<<row[1]<<row[2]<<row[3]<<row[4]<<row[5]<<row[6]<<row[7];
					myFile << row[0] <<","<<row[1]<<","<< row[2] << ","<<row[3] << ","<< row[4] << ","<<row[5]<<","<<row[6]<<","<<row[7]<<"\n";
				}


			}
			else if(choiceprint == 'T' || choiceprint == 't')
			{
				ofstream myFile;
				myFile.open("test.txt");
				myFile << "\n List of student should pay month " << strID << " Fines \n";

				string findbyid_query = "SELECT * FROM studentcompound WHERE Month='" + strID + "' AND Payment='" + payment + "' ";
				const char* qi = findbyid_query.c_str();
				qstate = mysql_query(conn, qi);

				res = mysql_store_result(conn);
				cout << endl;



				while ((row = mysql_fetch_row(res)))
				{
					//myFile<<row[0]<<row[1]<<row[2]<<row[3]<<row[4]<<row[5]<<row[6]<<row[7];

					
					myFile <<"\n Name:"<<row[0];
					myFile <<"\n Matric:"<<row[1];
					myFile <<"\n Reason:"<<row[2];
					myFile <<"\n Amount should Pay:"<<row[6];

					

				}
			}
			else if(choiceprint == 'M' || choiceprint == 'm')
			{
				MainPage();
			}


		}

	}
	else {

		cout << "Not FOUND in database";
	}

}

void DailyRecord() {

		system("cls");

		string items[5000];
		int indexForId = 0;
		string studID;
		string Day;
		string Month;
		string Year;
		char choice;
		bool HaveException = false;
		bool NotInDatabase = false;

		cout << "\n\t\t\t\t********************************************************************************* ";
		cout << "\n\t\t\t\t|                             Daily Record                                      | ";
		cout << "\n\t\t\t\t********************************************************************************* ";
		cout << "\n\t\t\t\tEnter Day: ";
	    cin >> Day;
		cout << "\n\t\t\t\tEnter Month: ";
		cin >> studID;
		cout << "\n\t\t\t\tEnter Year:  ";
		cin >> Year;
		cout << "\n\t\t\t\t********************************************************************************* ";


		if (HaveException == false) {

			stringstream streamid;
			string strID;
			streamid << studID;
			streamid >> strID;

			for (int i = 0; i < indexForId; i++) {

				if (strID != items[i]) {

					NotInDatabase = false;

				}
				else {

					NotInDatabase = false;


				}
			}

			if (NotInDatabase == false) {

				string findbyid_query = "SELECT * FROM studentcompound WHERE Day='" + Day + "' && Month='"+ strID +"' && Year='"+ Year +"' ";
				const char* qi = findbyid_query.c_str();
				qstate = mysql_query(conn, qi);


				if (!qstate)
				{
					res = mysql_store_result(conn);
					cout << endl;

					printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
					printf("|                                                    DAILY RECORD                                                                                |\n");
					printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
					printf("| %-25s | %-25s | %-15s |  %-10s  | %-10s | %-10s | %-10s | %-10s |\n", "Name", "Matric", "Reason", "Day", "Month", "Year", "Amount", "Payment");
					printf("------------------------------------------------------------------------------------------------------------------------------------------------ \n");
					while ((row = mysql_fetch_row(res)))
					{
						printf("| %-25s | %-25s | %-15s |  %-10s  | %-10s | %-10s | %-10s | %-10s | \n", row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7]);
					}
					printf("------------------------------------------------------------------------------------------------------------------------------------------------ \n");

					cout << "\n\n\t\t\t\tPress N to proceed to the Main Page or press any other key to Exit : ";
					cin >> choice;
					if (choice == 'N' || choice == 'n')
					{
						MainPage();
					}
					else
					{
						exit(0);
					}
				}

				else {

					cout << "Query Execution Problem" << mysql_errno(conn) << endl;

				}

			}

		}
		else {

			cout << "Not FOUND in database";
		}

	

}

void Payment() {

	system("cls");

	string matricno = "";
	string name = "";
	string reason = "";
	string day = "";
	string month = "";
	string year = "";
	string amount = "";
	string payment = "";
	char choice;
	char choice1;
	double a1, a2, a3;

	string items[5000];
	int indexForId = 0;
	string studID;
	bool HaveException = false;
	bool NotInDatabase = false;

	//store Variable;
	string storeid = "";
	string storename = "";
	string storematricno = "";
	string storereason = "";
	string storeday = "";
	string storemonth = "";
	string storeyear = "";
	string storeamount = "";
	string storepayment = "";
	string payment1 = "Pending";

	cout << "\n\t\t\t\tPayment Student \n";

	qstate = mysql_query(conn, "SELECT * FROM studentcompound LIMIT 5");
	if (!qstate)
	{

		
		
		res = mysql_store_result(conn);
		printf("------------------------------------------------------------------------------------------------------------------------------------------ \n");
		printf("|                                               STUDENT RECORD                                                                           | \n");
		printf("------------------------------------------------------------------------------------------------------------------------------------------ \n");
		printf("| %-25s | %-25s | %-15s |  %-10s  | %-10s | %-10s | %-10s | %-10s | \n", "Name", "Matric", "Reason", "Day", "Month", "Year", "Amount", "Payment");
		printf("------------------------------------------------------------------------------------------------------------------------------------------ \n");
		while ((row = mysql_fetch_row(res)))
		{
			printf("| %-25s | %-25s | %-15s |  %-10s  | %-10s | %-10s | %-10s | %-10s |\n", row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], row[8]);
			items[indexForId] = row[0];
			indexForId++;
		}
		printf("------------------------------------------------------------------------------------------------------------------------------------------- \n");

		
		
		
	}
	else {

		cout <<"\n\t\t\t\tQuery Execute Problem" << mysql_errno(conn) << endl;

	}

	try
	{
		cout << endl;
		cout <<"\n\t\t\t\tEnter Student ID(Matric No):";
		cin >> studID;
		cout << endl;
	}
	catch (exception e)
	{
		cout << "Please enter the valid value" << endl;
		HaveException = true;
		//goto Exit;
	}
	if (HaveException == false) {

		stringstream streamid;
		string strID;
		streamid << studID;
		streamid >> strID;

		for (int i = 0; i < indexForId; i++) {

			if (strID != items[i]) {

				NotInDatabase = false;

			}
			else {

				NotInDatabase = false;


			}
		}

		if (NotInDatabase == false) {

			string findbyid_query = "SELECT * FROM studentcompound WHERE Matric='" + strID + "'";
			const char* qi = findbyid_query.c_str();
			qstate = mysql_query(conn, qi);


			if (!qstate)
			{
				res = mysql_store_result(conn);
				cout << endl;
				while ((row = mysql_fetch_row(res)))
				{

					cout <<"Name:" << row[0] << "\nMatric:" << row[1] << "\nReason:" << row[2] << "\nDay:" << row[3] << "\nMonth:" << row[4] << "\nYear:" << row[5] << "\nAmount:" << row[6]<<"\nPayment:"<<row[7]<< endl << endl;
				
					storename = row[0];
					storematricno = row[1];
					storereason = row[2];
					storeday = row[3];
					storemonth = row[4];
					storeyear = row[5];
					storeamount = row[6];
					storepayment = row[7];

				}
			}

			else {

				cout << "Query Execution Problem" << mysql_errno(conn) << endl;

			}

			string findbyid_query1 = "SELECT SUM(Amount) FROM studentcompound WHERE Matric='" + strID + "'  && Payment='" + payment1 + "' ";
			const char* qi1 = findbyid_query1.c_str();
			qstate = mysql_query(conn, qi1);

			if (!qstate)
			{
				res = mysql_store_result(conn);
				cout << endl;

				while ((row = mysql_fetch_row(res)))
				{
					cout << "\n\t\t\tTOTAL AMOUNT:" << row[0]<<"\n";
				}
			}

			string findbyid_query2 = "SELECT * FROM studentcompound WHERE Matric='" + strID + "'  && Payment='" + payment1 + "' ";
			const char* qi2 = findbyid_query2.c_str();
			qstate = mysql_query(conn, qi2);

			if (!qstate)
			{
				res = mysql_store_result(conn);
				cout << endl;

				while ((row = mysql_fetch_row(res)))
				{
					
					cout << "\n\t\t\tA.LESS THAN 1 MONTH:(No penalty)";
					cout << "\n\t\t\tB.MORE THAN 3 MONTH:(10% penalty)";
					cout << "\n\t\t\tC.MORE THAN 6 MONTH:(50% penalty)";
					cout << "\n\t\t\tD.MORE THAN 1 YEAR:(100% penalty)";

					cout << "\n\t\t\tENTER WHICH CATEGORY:";
					cin >> choice1;

					if (choice1 == 'A' || choice1 == 'a') {

						a1 = stoi(row[6]);
						cout << "\n\t\t\tTOTAL AMAOUNT SHOULD PAY: RM" << a1 << endl;


					}
					else if (choice1 == 'B' || choice1 == 'b') {

						a1 = stoi(row[6]);
						a2 = (10.0 / 100) * a1;
						a3 = a1 + a2;
						cout << "\n\t\t\tTOTAL AMAOUNT SHOULD PAY: RM" << a3 << endl;


					}
					else if (choice1 == 'C' || choice1 == 'c') {

						a1 = stoi(row[6]);
						a2 = (50.0 / 100) * a1;
						a3 = a1 + a2;
						cout << "\n\t\t\tTOTAL AMAOUNT SHOULD PAY: RM" << a3 << endl;


					}
					else if (choice1 == 'D' || choice1 == 'd') {

						a1 = stoi(row[6]);
						a2 = (100.0 / 100) * a1;
						a3 = a1 + a2;
						cout << "\n\t\t\tTOTAL AMAOUNT SHOULD PAY: RM" << a3 << endl;

					}
					else {

						cout << "\n\t\t\tEnter valid value \n";


					}

				}
			}

			cin.ignore(1, '\n');

			cout << "Enter Payment(0 to not change): ";
			getline(cin, payment);
			if (payment == "0") {

				payment = storepayment;

			}

		}

		string update_query = "UPDATE studentcompound SET Payment = '"  + payment + "'WHERE Matric = '" + strID + "' ";
		//string update_query = "UPDATE studentrecord SET MATRIC =  '" + matricno + "', NAME = '"+ name +"', Reason = '" + reason +  "'WHERE STUD_ID = '" + strID + "' ";
		const char* qu = update_query.c_str();
		qstate = mysql_query(conn, qu);

		if (!qstate)
		{
			cout << endl << "\n\t\t\t\tSuccessfully Paid" << endl;

			cout << "\n\n\t\t\t\tPress N to proceed to the Main Page or press any other key to Exit : ";
			cin >> choice;
			if (choice == 'N' || choice == 'n')
			{
				MainPage();
			}
			else
			{
				exit(0);
			}

		}
		else {

			cout << "\n\t\t\t\tFailed to update" << mysql_errno(conn) << endl;

			cout << "\n\n\t\t\t\tPress N to proceed to the Main Page or press any other key to Exit : ";
			cin >> choice;
			if (choice == 'N' || choice == 'n')
			{
				MainPage();
			}
			else
			{
				exit(0);
			}


		}

	}
	else {

		cout << "Not FOUND in database";
	}
}

void AddStaffRecord() {

	system("cls");

	string Id;
	string password;
	string username;
	

	cout << "\n\t\t\tEnter Satff ID: ";
	cin >> Id;
	cout << "\n\t\t\tEnter Username: ";
	cin >> username;
	cout << "\n\t\t\tEnter Password: ";
	cin >> password;
	

	string insert_query1 = "INSERT INTO stafflogin(StaffId,username,password) VALUES('" + Id + "','" + username + "','" + password + "') ";
	//string insert_query1 = "INSERT INTO studentrecord(STUD_ID,NAME,MATRIC,Reason,Payment,Amount) VALUES('" + Id + "','" + Name + "', '" + Matric + "','" + Reason + "','" + Payment + "','" + Amount + "') ";
	const char* q = insert_query1.c_str();
	qstate = mysql_query(conn, q);


	if (!qstate)
	{


		cout << endl << "Data Added Sucessfully" << endl;
		MainPage();


	}
	else {

		cout << "Query execution problem!" << mysql_errno(conn) << endl;


	}


}

void DeleteStaffRecord() {

	system("cls");

	string matricno = "";
	string name = "";
	string reason = "";
	string day = "";
	string month = "";
	string year = "";
	string amount = "";
	string payment = "";
	char choice;
	string items[5000];
	int indexForId = 0;
	string studID;
	bool HaveException = false;
	bool NotInDatabase = false;


	cout << "DELETE STAFF RECORD \n";

	qstate = mysql_query(conn, "SELECT * FROM  stafflogin");
	if (!qstate)
	{

		res = mysql_store_result(conn);

		printf("------------------------------------------------------------ \n");
		printf("|                       LIST ALL STAFF RECORD              | \n");
		printf("-------------------------------------------------------------\n");
		printf("| %-10s | %-25s | %-15s | \n", "Id", "USERNAME", "PASSWORD");
		printf("-------------------------------------------------------------\n");
		while ((row = mysql_fetch_row(res)))
		{
			printf("| %-10s | %-25s | %-15s | \n", row[0], row[1], row[2]);
			items[indexForId] = row[0];
			indexForId++;
		}
		printf("-------------------------------------------------------------\n");


	}
	else {

		cout << "Query Execute Problem" << mysql_errno(conn) << endl;

	}

	try
	{
		cout << endl;
		cout << "Enter Staff ID: \n";
		cin >> studID;
		cout << endl;
	}
	catch (exception e)
	{
		cout << "Please enter the valid value" << endl;
		HaveException = true;
		//goto Exit;
	}
	if (HaveException == false) {

		stringstream streamid;
		string strID;
		streamid << studID;
		streamid >> strID;

		for (int i = 0; i < indexForId; i++) {

			if (strID != items[i]) {

				NotInDatabase = false;

			}
			else {

				NotInDatabase = false;


			}
		}

		if (NotInDatabase == false) {

			string delete_query = "DELETE FROM stafflogin WHERE StaffId =  '" + strID + "' ";
			const char* qd = delete_query.c_str();
			qstate = mysql_query(conn, qd);

			if (!qstate)
			{
				cout << endl << "\t\t\tData Delete " << endl;

				cout << "\n\n\t\t\t\tPress N to proceed to the Main Page or press any other key to Exit : ";
				cin >> choice;
				if (choice == 'N' || choice == 'n')
				{
					MainPage();
				}
				else
				{
					exit(0);
				}

			}
			else {

				cout << "\t\t\tFailed to delete" << mysql_errno(conn) << endl;

			}

		}

	}
	else {

		cout << "Not FOUND in database";
	}



}

 /* void Overdue() {
	 
		system("cls");

		string items[5000];
		int indexForId = 0;
		string studID;
		string name;
		bool HaveException = false;
		bool NotInDatabase = false;


		cout << "Enter month: \n";
		cin >> name;


		if (HaveException == false) {

			stringstream streamid;
			string strID;
			streamid << studID;
			streamid >> strID;

			for (int i = 0; i < indexForId; i++) {

				if (strID != items[i]) {

					NotInDatabase = false;

				}
				else {

					NotInDatabase = false;


				}
			}

			if (NotInDatabase == false) {

				string findbyid_query = "SELECT * FROM studentcompound WHERE Month <'" + name + "' && Payment='Pending' ";
				const char * qi = findbyid_query.c_str();
				qstate = mysql_query(conn, qi);

				if (!qstate)
				{
					res = mysql_store_result(conn);
					cout << endl;

					printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
					printf("|                                               INDIVIDUAL RECORD                                                                               |\n");
					printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
					printf("| %-25s | %-25s | %-15s |  %-10s  | %-10s | %-10s | %-10s | %-10s |\n", "Name", "Matric", "Reason", "Day", "Month", "Year", "Amount", "Payment");
					printf("------------------------------------------------------------------------------------------------------------------------------------------------ \n");
					while ((row = mysql_fetch_row(res)))
					{
						printf("| %-25s | %-25s | %-15s |  %-10s  | %-10s | %-10s | %-10s | %-10s | \n", row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7]);
					}
					printf("------------------------------------------------------------------------------------------------------------------------------------------------ \n");


				}

				else {

					cout << "Query Execution Problem" << mysql_errno(conn) << endl;

				}

			}

		}
		else {

			cout << "Not FOUND in database";
		}

	
}
*/

void CategoryCase() {

	system("cls");

	string items[5000];
	int indexForId = 0;
	char month1;
	string month;
	string name;
	string year;
	char choice;
	string payment = "Pending";
	bool HaveException = false;
	bool NotInDatabase = false;
	char choiceprint;

	cout << "\n\t\t\t\t********************************************************************************* ";
	cout << "\n\t\t\t\t|                             CATEGORY CASES                                    | ";
	cout << "\n\t\t\t\t********************************************************************************* ";
	cout << "\n";
	cout << "\n\t\t\t\tA. Academic dishonesty (Academic): \n";
	cout << "\n\t\t\t\tB. Falsification of documents (Falsification): \n";
	cout << "\n\t\t\t\tC. Late Book Return (LBR): \n";
	cout << "\n\t\t\t\tD. Parking (Parking): \n";
	cout << "\n\t\t\t\tE. Litering (Litering): \n";
	cout << "\n\t\t\t\tF. Interference with University functions (Interference) : \n";
	cout << "\n";
	cout << "\n\t\t\t\tEnter Category:";
	cin >> month1;
	cout << "\n\t\t\t\tEnter Year:";
	cin >> year;

	if (month1=='A') {

		month = "Academic";

	}
	else if (month1 == 'B') {

		month = "Falsification";

	}
	else if (month1 == 'C') {

		month = "LBR";

	}
	else if (month1 == 'D') {

		month = "Parking";

	}
	else if (month1 == 'E') {

		month = "Litering";

	}
	else if (month1 == 'F') {

		month = "Interference";

	}

	if (HaveException == false) {

		stringstream streamid;
		string strID;
		streamid << month;
		streamid >> strID;

		for (int i = 0; i < indexForId; i++) {

			if (strID != items[i]) {

				NotInDatabase = false;

			}
			else {

				NotInDatabase = false;

			}
		}

		if (NotInDatabase == false) {

			string findbyid_query = "SELECT * FROM studentcompound WHERE Reason='" + strID + "' AND Year='" + year + "' ";
			const char* qi = findbyid_query.c_str();
			qstate = mysql_query(conn, qi);


			if (!qstate)
			{
				res = mysql_store_result(conn);
				cout << endl;

				printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
				printf("|                                                CATEGORY CASES                                                                                   |\n");
				printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
				printf("| %-25s | %-25s | %-15s | %-10s | %-10s | %-10s | %-10s | %-10s | \n", "Name", "Matric", "Reason", "Day", "Month", "Year", "Amount", "Payment");
				printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
				while ((row = mysql_fetch_row(res)))
				{
					printf("| %-25s | %-25s | %-15s | %-10s | %-10s | %-10s | %-10s | %-10s | \n", row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7]);
				}
				printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");


				string findbyid_query1 = "SELECT COUNT(NAME) FROM studentcompound WHERE Reason='" + strID + "'  && Year='" + year + "' ";
				const char* qi1 = findbyid_query1.c_str();
				qstate = mysql_query(conn, qi1);

				if (!qstate)
				{
					res = mysql_store_result(conn);
					cout << endl;

					while ((row = mysql_fetch_row(res)))
					{
						cout << "\n\t\t\tTOTAL "<<strID<<" CASES:" << row[0];
					}

				}


				cout << "\n\n\t\t\t\tPress N to proceed to the Main Page or press any other key to Exit : ";
				cin >> choice;
				if (choice == 'N' || choice == 'n')
				{
					MainPage();
				}
				else
				{
					exit(0);
				}

			}

			else {

				cout << "Query Execution Problem" << mysql_errno(conn) << endl;

			}
			
		}

	}
	else {

		cout << "Not FOUND in database";
	}

}

void RangeRecord() {

	system("cls");

	string items[5000];
	int indexForId = 0;
	string studID;
	string Day;
	string Year;
	string Day1;
	string studID1;
	char choice;
	bool HaveException = false;
	bool NotInDatabase = false;

	cout << "\n\t\t\t\t********************************************************************************* ";
	cout << "\n\t\t\t\t|                             Daily Record                                      | ";
	cout << "\n\t\t\t\t********************************************************************************* ";
	cout << "\n\t\t\t\t Starting";
	cout << "\n";
	cout << "\n\t\t\t\tEnter Day: ";
	cin >> Day;
	cout << "\n\t\t\t\tEnter Month start: ";
	cin >> studID;
	cout << "\n\t\t\t\t End";
	cout << "\n\t\t\t\tEnter Day: ";
	cin >> Day1;
	cout << "\n\t\t\t\tEnter Month End: ";
	cin >> studID1;
	cout << "\n\t\t\t\tEnter Year:  ";
	cin >> Year;
	cout << "\n";
	

	cout << "\n\t\t\t\t********************************************************************************* ";


	if (HaveException == false) {

		stringstream streamid;
		string strID;
		streamid << studID;
		streamid >> strID;

		for (int i = 0; i < indexForId; i++) {

			if (strID != items[i]) {

				NotInDatabase = false;

			}
			else {

				NotInDatabase = false;

			}
		}

		if (NotInDatabase == false) {

			string findbyid_query = "SELECT * FROM studentcompound WHERE Year='"+ Year +"' && Day BETWEEN '"+ Day +"' AND '"+ Day1 +"' && Month BETWEEN '" + studID + "' AND '"+ studID1 +"' ";
			const char* qi = findbyid_query.c_str();
			qstate = mysql_query(conn, qi);


			if (!qstate)
			{
				res = mysql_store_result(conn);
				cout << endl;

				printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
				printf("|                                                    DAILY RECORD                                                                                |\n");
				printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
				printf("| %-25s | %-25s | %-15s |  %-10s  | %-10s | %-10s | %-10s | %-10s |\n", "Name", "Matric", "Reason", "Day", "Month", "Year", "Amount", "Payment");
				printf("------------------------------------------------------------------------------------------------------------------------------------------------ \n");
				while ((row = mysql_fetch_row(res)))
				{
					printf("| %-25s | %-25s | %-15s |  %-10s  | %-10s | %-10s | %-10s | %-10s | \n", row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7]);
				}
				printf("------------------------------------------------------------------------------------------------------------------------------------------------ \n");



				string findbyid_query1 = "SELECT COUNT(NAME) FROM studentcompound WHERE Year='" + Year + "' && Day BETWEEN '" + Day + "' AND '" + Day1 + "' && Month BETWEEN '" + strID + "' AND '" + studID1 + "' ";
				const char* qi1 = findbyid_query1.c_str();
				qstate = mysql_query(conn, qi1);

				if (!qstate)
				{
					res = mysql_store_result(conn);
					cout << endl;

					while ((row = mysql_fetch_row(res)))
					{
						cout << "\n\t\t\tTOTAL NUMBER OF CASES REGISTER FROM " << Day << "/"<< strID <<" TO "<< Day1<<"/"<<studID1<< " CASES:" << row[0];
					}

				}

				cout << "\n\n\t\t\t\tPress N to proceed to the Main Page or press any other key to Exit : ";
				cin >> choice;
				if (choice == 'N' || choice == 'n')
				{
					MainPage();
				}
				else
				{
					exit(0);
				}

			}

			else {

				cout <<"\n Query Execution Problem" << mysql_errno(conn) << endl;

			}

		}

	}
	else {

		cout << "Not FOUND in database";
	}

}