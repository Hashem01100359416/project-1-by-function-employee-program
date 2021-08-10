//#include <bits/stdc++.h> // visual studio  مريض بعيد عنكم مش بيشغل هذة المكتبه
//#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#define ll long long
#define vil vector<ll>
#define  endl "\n"
#define ios  std::ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;
struct employee
{
	string Name;
	int Age;
	int Salary;
	char Gender;
};
void manage_company();
void display_menu();
int choose();
void Add_new_employee(int ,struct employee *);
void Delete_employee(int, struct employee*);
void Disply_all(int , struct employee *);
void Edit_employee(int , struct employee *);
int a[100] = { 0 };
int main()
{
	 manage_company();
}
void manage_company()
{
	struct employee num_emp[100];
	int quit = 0, index = 0;
	do
	{
		display_menu();

		switch (choose())
		{
		case 1:                                 // Add new employee
			Add_new_employee(index,num_emp);
				index++;
			break;
		case 2:
			Disply_all(index, num_emp);         // display all employees
			break;
		case 3:
			Delete_employee(index,num_emp);     // delete employee
			break;
		case 4:
			Edit_employee(index,num_emp);       // Edit employee
			break;
		case 5:
			quit = 1;                          // Exit program
			break;

		}
		cout << endl << "=========================================\n";
		cout << "=========================================\n\n";

	} while (quit == 0);
}
void display_menu()
{
	cout << "Choose number of operation : \n";
	cout << "Enter 1 to Add new Employee       : -----> 1\n";
	cout << "Enter 2 to Dispaly all Employees  : -----> 2\n";
	cout << "Enter 3 to Delete employee by Age : -----> 3\n";
	cout << "Enter 4 to update Salary employee : -----> 4\n";
	cout << "Enter 5 to Exit progarm           : -----> 5\n";
}
int choose()
{
	int n;
	cout << "Enter number of operation :";
	cin >> n;
	cout << endl;
	return n;
}
void Add_new_employee(int index,struct employee *emp)
{
	cout << "Enter Name of employee   " << index + 1 << " : ";
	cin >> emp[index].Name;
	cout << "Enter Age of employee    " << index + 1 << " : ";
	cin >> emp[index].Age;
	cout << "Enter Salary of employee " << index + 1 << " : ";
	cin >> emp[index].Salary;
	cout << "Enter Gender of employee " << index + 1 << " : ";
	cin >> emp[index].Gender;
	cout << "\n\n";
}
void Disply_all(int size, struct employee *emp)
{
	cout << endl << "=========================================\n";
	cout << "=========================================\n\n";
	for (int i = 0; i < size; i++)
	{
		if (a[i] == 0)
		{
			cout << "data of Employee ----> " << i + 1 << endl;
			cout << "Name of employee   " << i + 1 << " : " << emp[i].Name << endl;
			cout << "Age of employee    " << i + 1 << " : " << emp[i].Age << endl;
			cout << "Salary of employee " << i + 1 << " : " << emp[i].Salary << endl;
			cout << "Gender of employee " << i + 1 << " : " << emp[i].Gender << endl;
			cout << endl << "=========================================\n";
			cout << "=========================================\n\n";
		}
	}
}
void Edit_employee(int size,struct employee *emp)
{
	string s;
	cout << "\nPlease Enter Name of employee :";
		cin >> s;

	for (int i = 0; i < size; i++)
	{
		if (s == emp[i].Name&&a[i]==0)
		{
			cout << "Enter Name of employee   " << i + 1 << " : ";
			cin >> emp[i].Name;
			cout << "Enter Age of employee    " << i + 1 << " : ";
			cin >> emp[i].Age;
			cout << "Enter Salary of employee " << i + 1 << " : ";
			cin >> emp[i].Salary;
			cout << "Enter Gender of employee " << i + 1 << " : ";
			cin >> emp[i].Gender;
			cout << "\n\n";
			break;
		}
	}
}
void Delete_employee(int size,struct employee* emp)
{
	int from_age=0,to_age = 0;
	cout << "\nPlease Enter first age and last age of employees :";
	cin >> from_age >> to_age;

	for (int i = 0; i < size; i++)
	{
		if (emp[i].Age>=from_age&& emp[i].Age<=to_age)
		{
			a[i]++;
		}
	}
}