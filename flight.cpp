#include <flight.h>
#include <fstream>
#include <iostream>

using namespace std;

// ap = airport


class flight{
private:
string flyNumber , sAirport , destiny , company , date;
int duration;
float price;

public:
    flight(string sybNumber , string sourceAp , string destination , string companyName , dateTime) {
    
    flyNumber = sybNumber;
    sAirport = sourceAp; 
    destiny = destination;
    company = companyName;
    date = dateTime;
}

    ofstream addfile("backData.cvs" , ios::app);

    if(!addfile.is_open())
    {
     cout << "Database file not opening..." << endl;
    }
    else
    {
     addfile << flyNumber << "," << sAirport << "," << destiny << "," << company << "," << date << "\n";
     addfile.close();
    }


    




};
