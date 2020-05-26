#include<iostream>
#include<fstream>
#include<iomanip>
#include<string.h>
#include<vector>
#include "headers.h"
using namespace std;

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
	cout<<"\n\nEnter The Name of Employee ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nEnter the Employee's Salary";
	cin>>salary;
	cout<<"\nEnter Date of Birth";
	cin>>DOB;
	cout<<"\nEnter Employee's position";
	cin>>position;
}

void employee::showemployeedata() const
{
	cout<<"\nEmployee number"<<employeenumber;
	cout<<"\nName of Employee : "<<name;
	cout<<"\nEmployee's Salary"<<salary;
	cout<<"\nDate of Birth"<<DOB;
	cout<<"\nPosition"<<position;
}
int employee::retempno() const
{
	return employeenumber;
}

void inventory::show_inv_tabular() const
{
	cout<<objnum<<setw(10)<<" "<<name<<setw(10)<<quantity<<setw(6)<<info<<setw(8)<<endl;
}

void bus::getbusdata(){
	cout<<"\nEnter Bus number ";
	cin>>bus_number;
	cout<<"\nEnter the area the bus covers:";
	cin>>bus_area;
	cout<<"\nEnter the number of students";
	cin>>number_of_students;
	for(int i=0; i< number_of_students; i++){
		string input;
		cout <<"Enter Student's Name";
		cin>> input;
		students_travelling.push_back(input);
	}
}

void bus::showbusdata() const
{
	cout<<"\nBus number"<<bus_number;
	cout<<"\nArea thebus covers: "<<bus_area;
	cout<<"\nNumber of students travelling in bus"<<number_of_students;
	for(int i = 0; i < sizeof(students_travelling); i++){
		cout<< students_travelling[i];
	}
}

int bus::retbusno() const
{
	return bus_number;
}

void inventory::getnewobject()
{
	cout<<"\nEnter The Object number";
	cin>>objnum;
	cout<<"\n\nEnter The Name of the object ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nEnter The number of the entered objects available ";
	cin>>quantity;
	cout<<"\nEnter object description.";
	cin>>info;
}

int inventory::retobjnum() const{
	return objnum;
} 

void inventory::showobject() const
{
	cout<<"\nObject number : "<<objnum;
	cout<<"\nObject name : "<<name;
	cout<<"\nObject Quantity : "<<quantity;
	cout<<"\nObject Description : "<<info;

}