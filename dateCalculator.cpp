/*David Archer
Date Calculator*/

#include <iostream>

using namespace std;

int nums1(int, int, int, int);
int leapyear(int);
void nums2(int&, int&, int&, int);
int days(int, int);

int main()
{
    int month, day, year, num1, leap;

    do {
        cout << "Please use number/s for the month: ";
        cin >> month;
        cout << "Please use number/s for the day: ";
        cin >> day;
        cout << "Please use number/s for the year: ";
        cin >> year;
        leap = leapyear(year);
        cout << endl;
        num1 = nums1(day, month, year, leap);
        if (num1 == 0)
            cout << "invalid date\n";
    } 
    while(num1 != 1);
    cout << "Today's date is " << month << "/" << day << "/" << year << endl;
    nums2(month, day, year, leap);
    cout << "Tomorrow's date is " << month << "/" << day << "/" << year << endl;
    system("pause");
    return 0;
}
int days(int month, int leap)
{
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12: return 31;
    case 4:
    case 6:
    case 9:
    case 11: return 30;
    case 2: return 28 + leap;
    }
}
void nums2(int& month, int& day, int& year, int leap)
{
    ++day;
    if(day > days(month, leap))
    {
        ++month;
        day = 1;
        if(month > 12)
        {
            month = 1;
            ++year;
        }
    }
}
int nums1(int day, int month, int year, int leap)
{
    if(day <= 0)
        return 0;
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12: if 
             (day > 31) 
             return 0; 
             else return 1;
    case 4:
    case 6:
    case 9:
    case 11: if
              (day > 30) 
              return 0; 
              else return 1;
    case 2: if(day > 28 + leap)
        return 0;
          else
        return 1;

    }

}
int leapyear(int year)
{
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;
    else
        return 0;
}

