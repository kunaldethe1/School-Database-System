#include<iostream>
#include<fstream>
#include<iomanip>
#include<string.h>
#include<vector>
using namespace std;
#include"headers.h"



//***************************************************************
//    	function declaration
//****************************************************************

void write_student();	//write the record in binary file
void display_all();		//read all records from binary file
void display_sp(int);	//accept rollno and read record from binary file
void modify_student(int);	//accept rollno and update record of binary file
void delete_student(int);	//accept rollno and delete selected records from binary file
void class_result();	//display all records in tabular format from binary file
void result();	//display result menu
void intro();	//display welcome screen
void entry_menu();	//display entry menu on screen
void employee_menu(); // display employee menu on screen
void modify_employee(int n);
void delete_employee(int n);
void write_inventory();
void inventory_menu();
void displayinventory();
void update_object(int); //update the details of a specific object in the inventory
void bus_menu();
void writebusdata();
void display_sp_bus(int);



//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************


int main()
{
	char choice; // for user input choice
	cout.setf(ios::fixed|ios::showpoint);
	cout<<setprecision(2); // program outputs decimal number to two decimal places
	intro();
	do
	{
		system("cls");
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. RESULT MENU";
		cout<<"\n\n\t02. ENTRY/EDIT MENU";
		cout<<"\n\n\t03. Employee MENU";
		cout<<"\n\n\t04. Inventory Menu";
		cout<<"\n\n\t05. Bus Menu";
		cout<<"\n\n\t06. EXIT";
		cout<<"\n\n\tPlease Select Your Option (1-6) ";
		cin>>choice;
		switch(choice)
		{
			case '1': result();
				break;
			case '2': entry_menu();
				break;
			case '3': employee_menu();
				break;
			case '4': inventory_menu();
				break;
			case '5': bus_menu();
				break;
			case '6':
				break;
			default :cout<<"\a";
		}
    }while(choice!='5');
	return 0;
}

//****************************************************************
//    	function to write in file
//****************************************************************

void write_student()
{
	student st;
	ofstream outFile;
	outFile.open("student.dat",ios::binary|ios::app);
	st.getdata();
	outFile.write(reinterpret_cast<char *> (&st), sizeof(student));
	outFile.close();
    cout<<"\n\nStudent record Has Been Created ";
	cin.ignore();
	cin.get();
}

//***************************************************************
//    	function to read all records from file
//****************************************************************

void display_all()
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be opened !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		st.showdata();
		cout<<"\n\n====================================\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

//***************************************************************
//    	function to read specific record from file
//****************************************************************

void display_sp(int n)
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		if(st.retrollno()==n)
		{
	  		 st.showdata();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nrecord not exist";
	cin.ignore();
	cin.get();
}

//***************************************************************
//    	function to modify record of file
//****************************************************************

void modify_student(int n)
{
	bool found=false;
	student st;
	fstream File;
	File.open("student.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}

	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&st), sizeof(student));
		if(st.retrollno()==n)
		{
			st.showdata();
			cout<<"\n\nPlease Enter The New Details of student"<<endl;
			st.getdata();
		    int pos=(-1)*static_cast<int>(sizeof(st));
		    File.seekp(pos,ios::cur);
		    File.write(reinterpret_cast<char *> (&st), sizeof(student));
		    cout<<"\n\n\t Record Updated";
		    found=true;
		}
	}
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
	cin.ignore();
	cin.get();

}

//***************************************************************
//    	function to delete record of file
//****************************************************************

void delete_student(int n)
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("Temp.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		if(st.retrollno()!=n) //if returned roll no is n;
		{
			outFile.write(reinterpret_cast<char *> (&st), sizeof(student));
		}
	}
	outFile.close();
	inFile.close();
	remove("student.dat");
	rename("Temp.dat","student.dat");
	cout<<"\n\n\tRecord Deleted ..";
	cin.ignore();
	cin.get();
}
//************************************************************************************************************
// EMPLOYEES ZONE 
//************************************************************************************************************

//****************************************************************
//    	function to write in file
//****************************************************************

void write_employee()
{
	employee emp;
	ofstream outFile;
	outFile.open("employee.dat",ios::binary|ios::app);
	emp.getemployeedata();
	outFile.write(reinterpret_cast<char *> (&emp), sizeof(employee));
	outFile.close();
    cout<<"\n\nEmployee record Has Been Created ";
	cin.ignore();
	cin.get();
}

//***************************************************************
//    	function to read all records from file
//****************************************************************

void display_allemployees()
{
	employee emp;
	ifstream inFile;
	inFile.open("employee.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
	while(inFile.read(reinterpret_cast<char *> (&emp), sizeof(employee)))
	{
		emp.showemployeedata();
		cout<<"\n\n====================================\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

//***************************************************************
//    	function to read specific record from file
//****************************************************************

void display_sp_emplist(int n) // display employee list
{
	employee emp;
	ifstream inFile;
	inFile.open("employee.dat",ios::binary); 
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&emp), sizeof(employee)))
	{
		if(emp.retempno()==n)
		{
	  		 emp.showemployeedata();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nrecord not exist";
	cin.ignore();
	cin.get();
}

//***************************************************************
//    	function to modify record of file
//****************************************************************

void modify_employee(int n) // to modify employee
{
	bool found=false;
	employee emp;
	fstream File;
	File.open("employee.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}

	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&emp), sizeof(employee));
		if(emp.retempno()==n)
		{
			emp.showemployeedata();
			cout<<"\n\nPlease Enter The New Details of employee"<<endl;
			emp.getemployeedata();
		    int pos=(-1)*static_cast<int>(sizeof(emp));
		    File.seekp(pos,ios::cur);
		    File.write(reinterpret_cast<char *> (&emp), sizeof(employee));
		    cout<<"\n\n\t Record Updated";
		    found=true;
		}
	}
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
	cin.ignore();
	cin.get();

}

//***************************************************************
//    	function to delete record of file
//****************************************************************

void delete_employee(int n)
{
	employee emp;
	ifstream inFile;
	inFile.open("employee.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("Temp.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&emp), sizeof(employee)))
	{
		if(emp.retempno()!=n) //if returned roll no is n;
		{
			outFile.write(reinterpret_cast<char *> (&emp), sizeof(employee));
		}
	}
	outFile.close();
	inFile.close();
	remove("employee.dat");
	rename("Temp.dat","employee.dat");
	cout<<"\n\n\tRecord Deleted ..";
	cin.ignore();
	cin.get();
}

//************************************************************************************************************
//END OF EMPLOYEES ZONE_______________________________________________________________________________________
//************************************************************************************************************

//************************************************************************************************************
//Inventory_______________________________________________________________________________________
//************************************************************************************************************




void write_inventory()
{
	inventory inv;
	ofstream outFile;
	outFile.open("inventory.dat",ios::binary|ios::app);
	inv.getnewobject();
	outFile.write(reinterpret_cast<char *> (&inv), sizeof(inventory));
	outFile.close();
    cout<<"\n\nObject record Has Been Created ";
	cin.ignore();
	cin.get();
}


void update_object(int n)
{
	bool found=false;
	inventory inv;
	fstream File;
	File.open("inventory.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}

	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&inv), sizeof(inventory));
		if(inv.retobjnum()==n)
		{
			inv.showobject();
			cout<<"\n\nPlease Enter The New Details of Object"<<endl;
			inv.getnewobject();
		    int pos=(-1)*static_cast<int>(sizeof(inv));
		    File.seekp(pos,ios::cur);
		    File.write(reinterpret_cast<char *> (&inv), sizeof(inventory));
		    cout<<"\n\n\t Record Updated";
		    found=true;
		}
	}
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
	cin.ignore();
	cin.get();

}

void displayinventory()
{
	inventory inv;
	ifstream inFile;
	inFile.open("inventory.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\t\tInventory \n\n";
	cout<<"==================================================================\n";
	cout<<"Obj no       Name        Qty   Info  "<<endl;
	cout<<"==================================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&inv), sizeof(student)))
	{
		inv.show_inv_tabular();
	}
	cin.ignore();
	cin.get();
	inFile.close();
}



//************************************************************************************************************
//End of Inventory_______________________________________________________________________________________
//************************************************************************************************************

//************************************************************************************************************
//Bus Data_______________________________________________________________________________________
//************************************************************************************************************

void writebusdata()
{
	bus b;
	ofstream outFile;
	outFile.open("bus.dat",ios::binary|ios::app);
	b.getnewobject();
	b.getbusdata();
	outFile.write(reinterpret_cast<char *> (&b), sizeof(bus)+sizeof(inventory));
	outFile.close();
    cout<<"\n\nStudent record Has Been Created ";
	cin.ignore();
	cin.get();
}

void display_sp_bus(int n)
{
	bus b;
	ifstream inFile;
	inFile.open("bus.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&b), sizeof(bus)))
	{
		if(b.retbusno()==n)
		{
	  		 b.showbusdata();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nrecord not exist";
	cin.ignore();
	cin.get();
}

//************************************************************************************************************
//End of Bus Data_______________________________________________________________________________________
//************************************************************************************************************

//***************************************************************
//    	function to display all students grade report
//****************************************************************

void class_result()
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\t\tALL STUDENTS RESULT \n\n";
	cout<<"==========================================================\n";
	cout<<"R.No       Name        P   C   M   E   CS   %age   Grade"<<endl;
	cout<<"==========================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		st.show_tabular();
	}
	cin.ignore();
	cin.get();
	inFile.close();
}

//***************************************************************
//    	function to display result menu
//****************************************************************

void result()
{
	char choice;
	int rno;
	system("cls");
	cout<<"\n\n\n\tRESULT MENU";
	cout<<"\n\n\n\t1. Class Result";
	cout<<"\n\n\t2. Student Report Card";
	cout<<"\n\n\t3. Back to Main Menu";
	cout<<"\n\n\n\tEnter Choice (1/2/3)? ";
	cin>>choice;
	system("cls");
	switch(choice)
	{
	case '1' :	class_result(); break;
	case '2' :	cout<<"\n\n\tEnter Roll Number Of Student : "; cin>>rno;
				display_sp(rno); break;
	case '3' :	break;
	default:	cout<<"\a";
	}
}

//***************************************************************
//    	INTRODUCTION FUNCTION
//****************************************************************

void intro()
{
	cout<<"\n\n\n\t\t    School";
	cout<<"\n\n\t\tDatabase Management";
	cout<<"\n\n\t\t     PROJECT";
	cin.get();
}

//***************************************************************
//    	ENTRY / EDIT MENU FUNCTION
//****************************************************************

void entry_menu()
{
	char choice;
	int num;
	system("cls");
	cout<<"\n\n\n\tENTRY MENU";
	cout<<"\n\n\t1.CREATE STUDENT RECORD";
	cout<<"\n\n\t2.DISPLAY ALL STUDENTS RECORDS";
	cout<<"\n\n\t3.SEARCH STUDENT RECORD ";
	cout<<"\n\n\t4.MODIFY STUDENT RECORD";
	cout<<"\n\n\t5.DELETE STUDENT RECORD";
	cout<<"\n\n\t6.BACK TO MAIN MENU";
	cout<<"\n\n\tPlease Enter Your Choice (1-6) ";
	cin>>choice;
	system("cls");
	switch(choice)
	{
	case '1':	write_student(); break;
	case '2':	display_all(); break;
	case '3':	cout<<"\n\n\tPlease Enter The roll number "; cin>>num;
				display_sp(num); break;
	case '4':	cout<<"\n\n\tPlease Enter The roll number "; cin>>num;
				modify_student(num);break;
	case '5':	cout<<"\n\n\tPlease Enter The roll number "; cin>>num;
				delete_student(num);break;
	case '6':	break;
	default:	cout<<"\a"; entry_menu();
	}
}

void employee_menu()
{
	char choice;
	int num;
	system("cls");
	cout<<"\n\n\n\tEMPLOYEE MENU";
	cout<<"\n\n\t1.CREATE EMPLOYEE RECORD";
	cout<<"\n\n\t2.DISPLAY ALL EMPLOYEES RECORDS";
	cout<<"\n\n\t3.SEARCH EMPLOYEE RECORD ";
	cout<<"\n\n\t4.MODIFY EMPLOYEE RECORD";
	cout<<"\n\n\t5.DELETE EMPLOYEE RECORD";
	cout<<"\n\n\t6.BACK TO MAIN MENU";
	cout<<"\n\n\tPlease Enter Your Choice (1-6) ";
	cin>>choice;
	system("cls");
	switch(choice)
	{
	case '1':	write_employee(); break;
	case '2':	display_allemployees(); break;
	case '3':	cout<<"\n\n\tPlease Enter The Employee number "; cin>>num;
				display_sp_emplist(num); break;
	case '4':	cout<<"\n\n\tPlease Enter The Employee number "; cin>>num;
				modify_employee(num);break;
	case '5':	cout<<"\n\n\tPlease Enter The Employee number "; cin>>num;
				delete_employee(num);break;
	case '6':	break;
	default:	cout<<"\a"; entry_menu();
	}
}

void inventory_menu()
{
	char choice;
	int num;
	system("cls");
	cout<<"\n\n\n\tINVENTORY MENU";
	cout<<"\n\n\t1.CREATE OBJECT RECORD";
	cout<<"\n\n\t2.DISPLAY INVENTORY";
	cout<<"\n\n\t3.UPDATE OBJECT";
	cout<<"\n\n\t4.BACK TO MAIN MENU";
	cout<<"\n\n\tPlease Enter Your Choice (1-4) ";
	cin>>choice;
	system("cls");
	switch(choice)
	{
	case '1':	write_inventory(); break;
	case '2':	displayinventory(); break;
	case '3':	cout<<"\n\n\tPlease Enter The Object number "; cin>>num;
				update_object(num); break;
	case '4':	break;
	default:	cout<<"\a"; entry_menu();
	}
}

void bus_menu(){
	char choice;
	int num;
	system("cls");
	cout<<"\n\n\n\tBus Menu";
	cout<<"\n\n\t1.CREATE BUS RECORD";
	cout<<"\n\n\t2.DISPLAY SELECTED BUS DATA";
	cout<<"\n\n\t3.BACK TO MAIN MENU";
	cout<<"\n\n\tPlease Enter Your Choice (1-3) ";
	cin>>choice;
	system("cls");
	switch(choice)
	{
	case '1':	writebusdata(); break;
	case '2':	cout<<"\n\n\tPlease enter the bus number";cin>>num;
				display_sp_bus(num); break;
	case '3':	break;
	default:	cout<<"\a"; entry_menu();
	}
}
//***************************************************************
//    			END OF PROJECT
//***************************************************************