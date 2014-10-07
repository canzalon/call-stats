/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Project: call_stats
Author: Christopher M. Anzalone		

Description: This program calculates the cost of a phone call based on
the length of the call (in minutes) and the number of relay stations used
to transmit the signal of said phone call. The calculations include the 
net cost before tax, the tax based on relay stations, and the total cost
derived from the aforementioned tax and net cost. The input from the user
will be handled by the "input" function, the calculations are inside the
"process" function, and the code for printing the report is in the "output"
function. The main function contains the variables for the entire program, 
and the function calls for each function, wrapped inside a loop if the user
wants repeat use of the program.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

/*Preprocessor Directives*/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

/*Function Prototypes*/
//---------------------------------------------------------------
void input(string&, double&, double&);
//---------------------------------------------------------------
//FUNCTION NAME: input
//DESCRIPTION: This function accepts input from the user for the 
//initialization of three output parameters.
//PRECONDITIONS: The variables for the cell phone number, number 
//of relay stations, and length of phone call have been declared 
//but are not yet initialized.
//POSTCONDITIONS: Cell phone number, number of relay stations,
//and length of phone call have been initialized.
//---------------------------------------------------------------
void process(double, double, double&, double&, double&);
//---------------------------------------------------------------
//FUNCTION NAME: process
//DESCRIPTION: This function calculates the net cost, tax, and 
//the total cost of a phone call.
//PRECONDITIONS: The number of relay stations and the length of 
//the phone call have been initialized and are input parameters.
//The variables for net cost, tax, and total cost of the phone
//call are output parameters that have been previously declared; 
//they will be assigned values based on calculations.
//POSTCONDITIONS: The net cost, tax, and total cost of the phone
//call have been calculated and their values assigned to the 
//appropriate variables.
//---------------------------------------------------------------
void output(string&, double, double, double&, double&, double&);
//---------------------------------------------------------------
//FUNCTION NAME: output
//DESCRIPTION: This function prints the information for the
//current phone number being processed; this includes the number
//itself, the number of relay stations and length of the call, net
//cost, tax, and total cost of the call.
//PRECONDITIONS: The variables for the cell phone number, relay
//stations, and length of the phone call have been initialized.
//The variables representing the net cost, tax, and total cost
//have been given values based on calculations from the process
//function.
//POSTCONDITIONS: The aforementioned variables have been printed
//to the screen.
//---------------------------------------------------------------

/*Function Implementations*/
void input(string&cell, double& r_stat, double& l_min)
{
	/*cell phone number*/
	cout<<"Enter cell phone number: ";
	cin>>cell; 
	cout<<endl;

	/*relay stations*/
	cout<<"Enter number of relay stations: ";
	cin>>r_stat; 
	cout<<endl;

	/*length of call*/
	cout<<"Enter length of call (in minutes): ";
	cin>>l_min; 
	cout<<endl;
}

void process(double rest, double lemi, double& netc, double& taxc, double& totalc)
{
	double rate=0.0;

	/*calculate tax rate (%)*/
	if (rest>=1 && rest<=5)
		rate=1;
	else if (rest>=6 && rest<=11)
		rate=3;
	else if (rest>=12 && rest<=20)
		rate=5;
	else if (rest>=21 && rest<=50)
		rate=8;
	else if (rest>50)
		rate=12;

	/*calculate net cost*/
	netc=((rest/50)*(0.40)*(lemi));

	/*calculate tax on call*/
	taxc=(netc*(rate/100));

	/*calculate total*/
	totalc=netc+taxc;
}

void output(string& cell, double r_stat, double l_min, double& net, double& tax, double& total)
{
	/*format output*/
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	/*output for user*/
	cout<<"\n*********************"
		<<"*********************\n"
		<<"Cell Phone Number: "
		<<cell.substr(0,3)<<"-"
		<<cell.substr(3,3)<<"-"
		<<cell.substr(6,4)<<endl
		<<"*********************"
		<<"*********************\n"<<endl;

	cout<<"Number of Relay Stations: \t"
		<<r_stat<<endl<<endl;

	cout<<"Length of Call in Minutes: \t"
		<<l_min<<endl<<endl;

	cout<<"Net Cost of Call: \t\t"
		<<net<<endl<<endl;

	cout<<"Tax of Call: \t\t\t"
		<<tax<<endl<<endl;
	
	cout<<"Total Cost of Call: \t\t"
		<<total<<endl<<endl<<endl;
}

int main()
{
	/*variable declarations*/
	double 
		r_stat=0.0,
		l_min=0.0,
		net=0.0,
		tax=0.0,
		total=0.0;
	char 
		choice=' ';
	string
		cell;
	
	/*function calls and loop*/
	do 
	{
		cout<<endl;

		input(cell, r_stat, l_min);
		process(r_stat, l_min, net, tax, total);
		output(cell, r_stat, l_min, net, tax, total); 

		cout<<"Would you like to do another calculation\n for another employee (enter y or n)? ";
		cin>>choice;
		
	} while(choice=='y' || choice=='Y');

	cout<<endl;
}