#include <iostream>

using namespace std;

string doctername;
string availableday[3];
string timeslot[5]={"9:00-09:30", "09:30-10:00", "10:00-10:30", "10:30-11:00", "11:00-11:30"};
bool isboo={"false"};

void docter(){
    cout<< "Enter the name of the doctor: ";
    cin >> doctername;

}