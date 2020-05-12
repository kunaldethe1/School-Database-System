//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************

#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;


//***************************************************************
//                   CLASSES USED IN PROJECT
//****************************************************************

class student
{
	int rollno;
	char name[50];
	int p_marks, c_marks, m_marks, e_marks, cs_marks;
	double per;
	char grade;
	void calculate();	//function to calculate grade
public:
	void getdata();	//function to accept data from user
	void showdata() const;	//function to show data on screen
	void show_tabular() const;
	int retrollno() const;
}; //class ends here

class employee{
	int employeenumber;
	char name[50];
	int salary;
	int DOB;
	char subject_taught;
	char department;
	char position;
public:
    void getemployeedata();
	void showemployeedata() const;
    void display_sp_emplist(int);
    int retempno() const;
    void modify_employee(int n);
    void delete_employee(int n);

};

void student::calculate()
{
	per=(p_marks+c_marks+m_marks+e_marks+cs_marks)/5.0;
	if(per>=60)
		grade='A';
	else if(per>=50)
		grade='B';
	else if(per>=33)
		grade='C';
	else
		grade='F';
}

void student::getdata()
{
	cout<<"\nEnter The roll number of student ";
	cin>>rollno;
	cout<<"\n\nEnter The Name of student ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nEnter The marks in physics out of 100 : ";
	cin>>p_marks;
	cout<<"\nEnter The marks in chemistry out of 100 : ";
	cin>>c_marks;
	cout<<"\nEnter The marks in maths out of 100 : ";
	cin>>m_marks;
	cout<<"\nEnter The marks in english out of 100 : ";
	cin>>e_marks;
	cout<<"\nEnter The marks in computer science out of 100 : ";
	cin>>cs_marks;
	calculate();
}

void student::showdata() const
{
	cout<<"\nRoll number of student : "<<rollno;
	cout<<"\nName of student : "<<name;
	cout<<"\nMarks in Physics : "<<p_marks;
	cout<<"\nMarks in Chemistry : "<<c_marks;
	cout<<"\nMarks in Maths : "<<m_marks;
	cout<<"\nMarks in English : "<<e_marks;
	cout<<"\nMarks in Computer Science :"<<cs_marks;
	cout<<"\nPercentage of student is  :"<<per;
	cout<<"\nGrade of student is :"<<grade;
}



void student::show_tabular() const
{
	cout<<rollno<<setw(6)<<" "<<name<<setw(10)<<p_marks<<setw(4)<<c_marks<<setw(4)<<m_marks<<setw(4)<<e_marks<<setw(4)<<cs_marks<<setw(8)<<per<<setw(6)<<grade<<endl;
}
	 
int  student::retrollno() const
{
	return rollno;
}


void employee::getemployeedata()
{
	cout<<"\nEnter Employee number ";
	cin>>employeenumber;
	cout<<"\n\nEnter The Name of Teacher ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nEnter the teacher's Salary";
	cin>>salary;
	cout<<"\nEnter Date of Birth";
	cin>>DOB;
	cout<<"\nEnter The subject taught by teacher ";
	cin>>subject_taught;
	cout<<"\nEnter teacher's department ";
	cin>>department;
	cout<<"\nEnter teacher's position";
	cin>>position;
}

void employee::showemployeedata() const
{
	cout<<"\nEmployee number"<<employeenumber;
	cout<<"\nName of Employee : "<<name;
	cout<<"\nEmployee's Salary"<<salary;
	cout<<"\nDate of Birth"<<DOB;
	cout<<"\nSubjects Taught : "<<subject_taught;
	cout<<"\nEmployee's Department"<<department;
	cout<<"\nPosition"<<position;
}
int employee::retempno() const
{
	return employeenumber;
}

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
		cout<<"\n\n\t04. EXIT";
		cout<<"\n\n\tPlease Select Your Option (1-3) ";
		cin>>choice;
		switch(choice)
		{
			case '1': result();
				break;
			case '2': entry_menu();
				break;
			case '3': employee_menu();
				break;
			case '4':
				break;
			default :cout<<"\a";
		}
    }while(choice!='4');
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
	cout<<"\n\n\n\t\t  STUDENT";
	cout<<"\n\n\t\tREPORT CARD";
	cout<<"\n\n\t\t  PROJECT";
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
	cout<<"\n\n\n\tENTRY MENU";
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

//***************************************************************
//    			END OF PROJECT
//***************************************************************