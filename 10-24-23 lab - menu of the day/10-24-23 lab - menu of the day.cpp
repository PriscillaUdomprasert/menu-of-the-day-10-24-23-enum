#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

enum class Days {mon, tue, wed, thu, fri, sat, sun, none};

struct MenuItem
{
	string name;
	int price = 0;
	string day;
	bool equals(const MenuItem& to_compare);
};

bool MenuItem::equals(const MenuItem& to_compare)
{
	return (name == to_compare.name && day == to_compare.day);
}

Days get_day(string input)
{
	if (input == "Mon" || input == "mon")
		return Days::mon;
	else if (input == "Tue" || input == "tue")
		return Days::tue;
	else if (input == "Wed" || input == "wed")
		return Days::wed;
	else if (input == "Thu" || input == "thu")
		return Days::thu;
	else if (input == "Fri" || input == "fri")
		return Days::fri;
	else if (input == "Sat" || input == "sat")
		return Days::sat;
	else if (input == "Sun" || input == "sun")
		return Days::sun;
	else
		return Days::none;
}

string get_dayString(Days ocInput)
{
	if (ocInput == Days::mon)
		return "mon";
	else if (ocInput == Days::tue)
		return "tue";
	else if (ocInput == Days::wed)
		return "wed";
	else if (ocInput == Days::thu)
		return "thu";
	else if (ocInput == Days::fri)
		return "fri";
	else if (ocInput == Days::sat)
		return "sat";
	else if (ocInput == Days::sun)
		return "sun";
}

void load_menu_from_file(vector<MenuItem>& menu);
vector<MenuItem> menu;

const string infile = "menu.txt";

int main()
{
	load_menu_from_file(menu);
	cout << "Menu of the Day" << endl << endl;
	cout << "COMMAND MENU" << endl;
	cout << "Specify the day using the three-letter format (mon, tue, wed, thu, fri, sat, sun) . Or, enter 'exit' to exit." << endl;

	string input = "exit";

	do 
	{

		cout << "\nDay: ";
		cin >> input;

		for (int i = 0; i < menu.size(); i++)
		{
			if (menu[i].day == input) //compare day to user input
			{
				cout << left << setw(8) << menu[i].name << right << setw(12) << menu[i].price << endl;
			}
		}

	} while (input != "exit");
	
	cout << "\nBye!";
}

void load_menu_from_file(vector<MenuItem>& menu)
{
	ifstream infile;
	infile.open("menu.txt");


	if (infile)
	{
		MenuItem temp_item;

		stringstream ss;

		string line;

		string dummy;

		while (getline(infile, line))
		{
			ss.str(line);

			ss.clear();

			getline(ss, temp_item.name, '\t'); //to read name until tab

			ss >> temp_item.price; //read price

			getline(ss, dummy, '\t'); //to simulate the tab between price and day

			getline(ss, temp_item.day); //read day

			menu.push_back(temp_item);


		}//end while

		infile.close();
	}//end if

}

