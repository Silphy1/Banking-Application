//Header Files
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <filesystem>
#include <stdlib.h>
#include <cstdlib>

//Namespace
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;
using std::fstream;
using std::vector;
using std::ios;
using std::filesystem::directory_iterator;
namespace fs = std::filesystem;

//Global Function
int main();
void openacc();
void baleq();
void deposit();
void withdl();
void closeacc();
void showalacc();
void exitapp();

int main()
{
	// Main Screen
	cout << "***Bank Management System***\n";
	cout << " " << endl;
	cout << "    Select One Option Below\n";
	cout << "    1 Open An Account\n";
	cout << "    2 Balance Enquiry\n";
	cout << "    3 Deposit\n";
	cout << "    4 Withdrwal\n";
	cout << "    5 Close An Account\n";
	cout << "    6 Quit\n";
	
	//User Responce
	int useresp;
	cout << "Enter Responce here: ";
	cin >> useresp;

	//Link to Functions for user responce 
	if (useresp == 1)
	{
		openacc();
	}
	else if (useresp == 2)
	{
		baleq();
	}
	else if (useresp == 3)
	{
		deposit();
	}
	else if (useresp == 4)
	{
		withdl();
	}
	else if (useresp == 5)
	{
		closeacc();
	}
	else if (useresp == 6)
	{
		exitapp();
	}
	else
		cout << "Please try again, your responce doesnt correctly match what is on the screen.\n";

	return 0;
}

//Open Account
void openacc()
{
	//User Info
	string fname;
	string lname;
	float indep, accnum;

	//Getting user input
	cout << "Enter Account Num: ";
	cin >> accnum;
	cout << "Enter First Name: ";
	cin >> fname;
	cout << "Enter Last Name: ";
	cin >> lname;
	cout << "Enter Inital Deposit: ";
	cin >> indep;

	//storing it to the file
	fstream file;
	file.open(fname + ".DAT", std::ios_base::app);

	file << fname << endl;
	file << lname << endl;
	file << accnum << endl;
	file << indep << endl;

	file.close();

	//Link to main and exit funciton
	int numre;
	cout << "Your Acount has been created, would you like to go back to the main screen or exit?\n";
	cout << "First Name: " << fname << endl;
	cout << "Last Name: " << lname << endl;
	cout << "Account Number: " << accnum << endl;
	cout << "Balance: " << indep << endl;
	cout << "Enter 1 for Yes & 2 For Exit: ";
	cin >> numre;


	if (numre == 1)
	{
		main();
	}
	else if (numre == 2)
	{
		exitapp();
	}
	else
		cout << "No correlating responce took in, Exiting you out! Have a good day :)";
	    exitapp();
}

//Blance Enquiry
void baleq()
{
	//User Input
	string fname, accnum, lname, indep;

	cout << "Enter Account Num: ";
	cin >> accnum;
	cout << "Enter First Name: ";
	cin >> fname;

	//Reading from the file
	ifstream read(fname + ".DAT");
	getline(read, fname);
	getline(read, lname);
	getline(read, accnum);
	getline(read, indep);
	
	// Outputting account information
	cout << "First Name: " << fname << endl;
	cout << "Last Name: " << lname << endl;
	cout << "Account Number: " << accnum << endl;
	cout << "Balance: $" << indep << endl;

	int numbr;
	cout << "Enter 1 to go the the main menu and 2 to go to exit the applicaiton" << endl;
	cout << "Input here: ";
	cin >> numbr;
	
	if (numbr == 1)
	{
		main();
	}
	else if (numbr == 2)
	{
		exitapp();
	}
}

//Deposit
void deposit()
{
	//intializing variables
	string fname, lname,accnum, indep;
	int bal;
	int newbal;
	int numbr;

	//getting user input
	cout << "Enter Account Num: ";
	cin >> accnum;
	cout << "Enter First Name: ";
	cin >> fname;

	//Reading from the file
	ifstream read(fname + ".DAT");
	getline(read, fname);
	getline(read, lname);
	getline(read, accnum);
	getline(read, indep);

	//turning string balance to an int
	bal = stoi(indep);

	//Adding Money
	cout << "How much would you like Deposit? ";
	cin >> numbr;
	newbal = numbr + bal;
	string line;
	vector<string> lines;
	std::ifstream inputStream(fname + ".DAT");

	//Deleting old balance while creating a new balance
	while (getline(inputStream, line)) {
		lines.push_back(line);
	}
	inputStream.close();

	std::fstream outputStream(fname +".DAT", ios::out | ios::trunc);
	if (outputStream.is_open())
	{
		for (int i = 0; i < lines.size() - 1; i++)
		{
			outputStream << lines[i] << "\n";
		}
		outputStream.close();
	}
	//writing new balance to the file
	fstream file;
	file.open(fname + ".DAT", std::ios_base::app);
	file << newbal << endl;
	file.close();
	
	//displaying new balance
	cout << "Your new balance is: $";
	cout << newbal << endl;

	//Exit or main menu
	cout << "Enter 1 to go the the main menu and 2 to go to exit the applicaiton" << endl;
	cout << "Input here: ";
	cin >> numbr;

	if (numbr == 1)
	{
		main();
	}
	else if (numbr == 2)
	{
		exitapp();
	}
}

//Withdrawl
void withdl()
{
	//intializing variables
	string fname, lname, accnum, indep;
	int bal;
	int newbal;
	int numbr;

	//getting user input
	cout << "Enter Account Num: ";
	cin >> accnum;
	cout << "Enter First Name: ";
	cin >> fname;

	//Reading from the file
	ifstream read(fname + ".DAT");
	getline(read, fname);
	getline(read, lname);
	getline(read, accnum);
	getline(read, indep);

	//turning string balance to an int
	bal = stoi(indep);

	//Adding Money
	cout << "How much would you like withdrawl? ";
	cin >> numbr;
	newbal = bal - numbr;
	string line;
	vector<string> lines;
	std::ifstream inputStream(fname + ".DAT");

	//Deleting old balance while creating a new balance
	while (getline(inputStream, line)) {
		lines.push_back(line);
	}
	inputStream.close();

	std::fstream outputStream(fname + ".DAT", ios::out | ios::trunc);
	if (outputStream.is_open())
	{
		for (int i = 0; i < lines.size() - 1; i++)
		{
			outputStream << lines[i] << "\n";
		}
		outputStream.close();
	}
	//writing new balance to the file
	fstream file;
	file.open(fname + ".DAT", std::ios_base::app);
	file << newbal << endl;
	file.close();

	//displaying new balance
	cout << "Your new balance is: $";
	cout << newbal << endl;

	//Exit or main menu
	cout << "Enter 1 to go the the main menu and 2 to go to exit the applicaiton" << endl;
	cout << "Input here: ";
	cin >> numbr;

	if (numbr == 1)
	{
		main();
	}
	else if (numbr == 2)
	{
		exitapp();
	}
}

//Close Account
void closeacc()
{
	//intializing variables
	string accnum;
	string fname;
	int status;
	//getting user input
	cout << "Enter Account Num: ";
	cin >> accnum;
	cout << "Enter First Name: ";
	cin >> fname;
	string filename(fname + ".DAT");
	status = remove(filename.c_str());
	if (status == 0)
		cout << "Account Terminated Successfully!";
		//Exit or main menu
		cout << "Enter 1 to go the the main menu and 2 to go to exit the applicaiton" << endl;
		cout << "Input here: ";
		int numbr;
		cin >> numbr;

		if (numbr == 1)
		{
			main();
		}
		else if (numbr == 2)
		{
			exitapp();
		}
	else
		cout << "\nError Occurred!";
	cout << endl;
	
}

//Exit Application
void exitapp()
{
	exit(1);
}