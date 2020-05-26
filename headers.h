//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************

#include<iostream>
#include<fstream>
#include<iomanip>
#include<string.h>
#include<vector>
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
	char position;
public:
    void getemployeedata();
	void showemployeedata() const;
    void display_sp_emplist(int);
    int retempno() const;


};

class inventory{
	int objnum;
	char name[50];
	int quantity;
	string info;
public:
	void getnewobject();
	void showobject() const;
	int retobjnum() const;
	void show_inv_tabular() const;

};

class bus: public inventory{
	int bus_number;
	string bus_area;
	int number_of_students;
	vector<string> students_travelling;
	public:
	void getbusdata();
	void showbusdata() const;
	int retbusno() const;
};