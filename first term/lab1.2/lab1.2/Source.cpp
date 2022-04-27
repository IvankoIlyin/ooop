#include<iostream>
#include<vector>
#include<cmath>
using namespace std; 
struct Time {
	int hour;
	int minute;
	int sec;
};
struct Date
{
	int yaer;
	int month;
	int day;
	Time time;
};

bool isDateTrue(Date date){
	bool flag = true;
	bool hiYear = false;
	if (date.yaer % 4 == 0) { hiYear = true; }
	switch (date.month)
	{
	case 1: if (date.day > 31 || date.day < 1) { flag = false; } break;

	case 3:if(date.day > 31 || date.day < 1) { flag = false; } break;
	case 4:if (date.day > 30 || date.day < 1) { flag = false; } break; 
	case 5:if (date.day > 31 || date.day < 1) { flag = false; } break;
	case 6:if (date.day > 30 || date.day < 1) { flag = false; } break;
	case 7:if (date.day > 31 || date.day < 1) { flag = false; } break;
	case 8:if (date.day > 31 || date.day < 1) { flag = false; } break;
	case 9:if (date.day > 30 || date.day < 1) { flag = false; } break;
	case 10:if (date.day > 31 || date.day < 1) { flag = false; } break;
	case 11:if (date.day > 30 || date.day < 1) { flag = false; } break;
	case 12:if (date.day > 31 || date.day < 1) { flag = false; } break;
	default:
		break;
	}
	if (date.month == 2 && hiYear == true && date.day > 29 && date.day < 1) { flag = false; }
	if (date.month == 2 && hiYear == false && date.day > 28 && date.day < 1) { flag = false; }
	if (flag == true) { cout << "date true" << endl; }
	if (flag ==false) { cout << "date false" << endl; }
	return flag;
}

long long DateInSec(Date date) {
	bool hiYe = false;
	long long date1secsY=0, date1secsM=0, date1secsD,secs; 
	for (int i = 0; i < date.yaer-1; i++) {
		if (date.yaer % 4 != 0) { date1secsY = date1secsY + 31536000; }
		if (date.yaer % 4 == 0) { date1secsY = date1secsY + 31622400; hiYe = true; }
	}
	for (int i = 0; i < date.month-1; i++) {
		if (date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7 || date.month == 8 || date.month == 10 || date.month == 12) {
			date1secsM = date1secsM + 2678400;
		}
		if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) { date1secsM = date1secsM + 2592000; }
		if(date.month==2 && hiYe==true){ date1secsM = date1secsM + 2505600; }
		if (date.month == 2 && hiYe == false) { date1secsM = date1secsM + 2419200; }
	}
	date1secsD = date.day * 86400;
	secs = date1secsY + date1secsM + date1secsD + (date.time.hour * 3600) + (date.time.minute * 60) + date.time.sec;

	return secs;
}

long long subtractionDate(Date date1, Date date2) {
	long long secs1, secs2,ans;
	secs1 = DateInSec(date1);
	secs2 = DateInSec(date2);
	ans = secs1 - secs2;
	return ans;
}

Date summationDate(long long secs, Date date) {
	bool hiY = false;
	int i = 0;
	while (secs> 31536000||secs> 31622400) {
		if (i % 4 != 0) { secs = secs - 31536000; date.yaer++; }
		else { secs = secs - 31622400; date.yaer++; hiY = true; }
		i++;
	} 
	// считаем годы
	while (secs > 2678400 || secs > 2592000 || secs > 2505600 || secs > 2419200) {
		if (date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7 || date.month == 8 || date.month == 10 || date.month == 12) {
			secs = secs - 2678400; date.month++;
			
		}
		if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) {
			secs = secs - 2592000; date.month++;
			
		}
		if (date.month == 2 && hiY == true) {
			secs = secs - 2505600; date.month++;
			
		}
		else {
			secs = secs - 2419200; date.month++;
			if (date.day > 28) { date.month++; date.day = 1; }
		}
		if (date.month > 12) { date.yaer++; date.month = 1; }
	}
	// считаем месяцы
	while (secs > 86400) {
		secs = secs - 8640;
		date.day++;
		if (date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7 || date.month == 8 || date.month == 10 || date.month == 12) {
			if (date.day > 31) { date.month++; date.day = 1; }
		}
		if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) {
			if (date.day > 30) { date.month++; date.day = 1; }
		}
		if (date.month == 2 && hiY == true) {
			if (date.day > 29) { date.month++; date.day = 1; }
		}

		if (date.month == 2 && hiY == false) {
			if (date.day > 28) { date.month++; date.day = 1; }
		}


				}
				// считаем дни
	while (secs > 3600) {
					secs = secs - 3600;
					date.time.hour++;
					if (date.time.hour > 23) { date.day++; date.time.hour = 0; }
				}
				//считаем часы
	while (secs > 60) {
					secs = secs - 60;
					date.time.minute++;
					if (date.time.minute > 59) { date.time.hour++; date.time.minute = 0; }
				}
				// считаем минуты
				date.time.sec = date.time.sec + secs; //считаем секунды
				if (date.time.sec > 59) { date.time.minute++; date.time.sec = date.time.sec - 60; }
				return date;
			}
		

Date minusDate(long long secs, Date date) {
	bool hiY = false;
	int i = 0;
	while (secs > 31536000 || secs > 31622400) {
		if (i % 4 != 0) { secs = secs - 31536000; date.yaer--; }
		else { secs = secs - 31622400; date.yaer--; hiY = true; }
		i++;
	}
	// считаем годы
	if (date.yaer <= 0) { cout << "dude, no no no no, its bad, are you God? Please help me" << endl; }
	while (secs > 2678400 || secs > 2592000 || secs > 2505600 || secs > 2419200) {
		if (date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7 || date.month == 8 || date.month == 10 || date.month == 12) {
			secs = secs - 2678400; date.month--;
		}
		if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) {
			secs = secs - 2592000; date.month--;
		}
		if (date.month == 2 && hiY == true) {
			secs = secs - 2505600; date.month--;
		}
		else {
			secs = secs - 2419200; date.month--;
		}

	}
	// считаем месяцы
	while (secs > 86400) {
		secs = secs - 8640;
		date.day--;
		if (date.day < 1) {
			date.month--;
			if (date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7 || date.month == 8 || date.month == 10 || date.month == 12) { date.day = 31; }
			if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) { date.day = 30; }
			if (date.month == 2 && hiY == true) { date.day = 29; }
			if (date.month == 2 && hiY == false) { date.day = 28; }
		}
	}
	// считаем дни
	while (secs > 3600) {
		secs = secs - 3600;
		date.time.hour--;
		if (date.time.hour < 0) { date.day--; date.time.hour = 23; }
	}
	//считаем часы
	while (secs > 60) {
		secs = secs - 60;
		date.time.minute--;
		if (date.time.minute < 1) { date.time.hour--; date.time.minute = 59; }
	}
	// считаем минуты
	date.time.sec = date.time.sec - secs;//считаем секунды
	if (date.time.sec < 1) { date.time.minute--; date.time.sec = 59; }
	return date;
}

void dayOfWeek(Date date) {
	int Mcode, Ycode,dof;
	Ycode = ((6 + date.yaer % 100 + date.yaer % 100) / 4) % 7;
	switch (date.month)
	{
	case 1:Mcode = 1; break;
	case 10:Mcode=1; break;
	case 5:Mcode = 2; break;
	case 8:Mcode = 3; break;
	case 2:Mcode = 4; break;
	case 3:Mcode = 4; break;
	case 11:Mcode = 4; break;
	case 6:Mcode = 5; break;
	case 9:Mcode = 6; break;
	case 12:Mcode = 6; break;
	case 4:Mcode = 0; break;
	case 7:Mcode = 0; break;
	default:
		break;
	}
	dof = (date.day + Mcode + Ycode) % 7;
	switch (dof)
	{
	case 3:cout << "day is Monday" << endl; break;
	case 4:cout << "day is Tuesday" << endl; break;
	case 5:cout << "day is Wednesday" << endl; break;
	case 6:cout << "day is Thursday" << endl; break;
	case 0:cout << "day is Friday" << endl; break;
	case 1:cout << "day is Saturday" << endl; break;
	case 2:cout << "day is Sunday" << endl; break;
	default:
		break;
	}
 }

Date EnterDate() {
	Date date;
	cout << " Enter date" << endl;
	cout << endl;
	cout << "year:" << endl;
	cin >> date.yaer;
	cout << "month:" << endl;
	cin >> date.month;
	cout << "day:" << endl;
	cin >> date.day;
	cout << "hour:" << endl;
	cin >> date.time.hour;
	cout << "minutes:" << endl;
	cin >> date.time.minute;
	cout << "secs:" << endl;
	cin >> date.time.sec;
	return date;
}
void PrintDate(Date date) {
	cout<<"Date:"<<"  " << date.day << "." << date.month << "." << date.yaer << endl;
	cout << "Time:" << "  " << date.time.hour << "//" << date.time.minute << "//" << date.time.sec << endl;
}
int main()
{ 
	
	bool f = true;
	Date date,date1,date2;
	while (f) {
		int comm;
		long long secs2,secs1,sec;
		cout << "Please enter command" << endl;
		cout << "1 - check date" << endl;
		cout << "2 - subtraction date1 & date2(date1>date2)" << endl;
		cout << "3 - summation date" << endl;
		cout << "4 - minus date" << endl;
		cout << " 5 - day of week" << endl;
		cout << "6 - exit" << endl;
		cin >> comm;
		switch (comm)
		{
		case 1:date = EnterDate(); isDateTrue(date);break;
		case 2: date1 = EnterDate(); date2 = EnterDate();  sec = subtractionDate(date1, date2); cout << sec << "secs" << endl;  break;
		case 3:date = EnterDate(); 
			cout << "Enter secs" << endl;
			cin >> secs1;
			date =summationDate(secs1, date);
			PrintDate(date);
			break;
		case 4: 
			date = EnterDate();
			cout << "Enter secs" << endl;
			cin >> secs2;
			date =minusDate(secs2, date);
			PrintDate(date);
			break;
		case 5: 
			date = EnterDate();
			dayOfWeek(date);
			break;
		default:
			break;
		}
		if (comm == 6) { break; }
	}
	return 0;
}