#include <iostream>
#include <string>

using namespace std;

// Specifies clock time units
enum timeUnit {AM, PM};

// Maintains a 12-hour clock using a 24-hour clock object
class time12
{
	public:
	time12(int h = 12, int m = 0, timeUnit tunit = AM); // initialize time24 data member t
	void addTime(int m); // adds m minutes to update current time
	void readTime(); // input time from keyboard in format of hh:mm AM or PM
	void writeTime(); // displays current time
	
	private:
	time24 convert12to24(int h, int m, timeUnit tunit); // build t from standard time
	time24 t; // stores time in a time24 object

};

time12::time12(int h, int m, timeUnit tunit)
{
	convert12to24(h, m, tunit); // takes values of 12-hour clock and creates a 24-hour clock object
}

time24 time12::convert12to24(int h, int m, timeUnit tunit)
{

	// Creates the appropriate 24-hour clock with h hours, m minutes, and either AM or PM based on tunit
	if (tunit == AM && h == 12) 
	{
		t = time24(0, m); // 24-hour clock should start at 0 because it is a new day
	}
	else if (tunit == PM && h == 12) 
	{
		t = time24(h, m); // 24-hour clock can use h and m because it is noon
	}
	else if (tunit == AM) 
	{
		t = time24(h, m); // 24-hour clock can use h and m because it is before noon
	}
	else 
	{
		t = time24(12 + h, m); // 24-hour clock should be offset by 12 hours because it is after noon
	}

}

void time12::writeTime()
{
	
	int hour, minute;
	hour = t.getHour(); // gets current hour of 24-hour clock
	minute = t.getMinute(); // gets current minute of 24-hour clock
	
	// The following if statements check the 24-hour clock object for the current time, and then determine how to re-format 24-hour clock into 12-hour clock. Once the correct value is set, the time is outputted via cout in the hh:mm am/pm format.
	if(hour > 12) 
	{
		// 24-hour clock is past 12 and the hour value must be converted to a 12-hour clock value
		
		hour = hour % 12;
		
		if(hour == 0)
		{
			hour = 12;
		}
		
		cout << hour << ":"; // hour is outputted
		cout.fill('0'); // makes sure that 0s appear before single value minute
		cout << setw(2) << minute; // minute is outputted
	}
	else if (hour != 0) 
	{
		// 24-hour clock and 12-hour clock agree on the numerical value of time 
		
		cout << hour << ":";
		cout.fill('0');
		cout << setw(2) << minute;
	}
	else 
	{
		// 24-hour clock is at hour = 0, which corresponds to the 12-hour clock value of 12 AM
		
		cout << hour + 12 << ":";
		cout.fill('0');
		cout << setw(2) << minute;
	}
	
	// Based on current 24-hour clock time, it is determined whether it is AM or PM, and the correct period is output via cout
	hour = t.getHour();
	
	if(hour < 12)
	{
		cout << " AM";
	}
	else
	{
		cout << " PM";	
	}	
}

void time12::addTime(int m)
{
	t.addTime(m); // adds m minutes to current time24 object
}

void time12::readTime()
{
	// Takes user input for hour, minute, and time of day, and creates a time24 object
	
	cout << "Enter a time in the format of HH:MM AM(OR PM)" << endl;
	string input, hour, minute, unit;

	//	Gets the hour, minute, and time of day from cin, using colon as a delimiter, and stores each of these as strings
	getline(cin, hour, ':');
	cin >> minute;
	cin >> unit;
	
	// Changes string versions of hour and minute to int versions of hour and minute
	int h, m;
	stringstream(hour) >> h;
	stringstream(minute) >> m;
	
	// Determines appropriate time of day to use when creating time24 object
	if(unit == "AM")
	{
		convert12to24(h, m, AM);
	}
	else
	{
		convert12to24(h, m, PM);
	}
}