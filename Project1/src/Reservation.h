/*WIP by Amelie*/
#pragma once
#include <map>
#include <string>
#include <vector>
#include <array>
using namespace std;

class Reservation
{
public:
    Reservation();
    ~Reservation() = default;

    string NameOfReserver;
    int NumOfPeople;
    string Time;
    int Day;
    int Month;
    int Year;

    Reservation(int aDay, int aMonth, int aYear, string aTime, string aNameOfReserver, int aNumOfPeople)
    {
        Day = aDay;
        Month = aMonth;
        Year = aYear;
        Time = aTime;
        NameOfReserver = aNameOfReserver;
        NumOfPeople = aNumOfPeople;
    }

    //Determines reservable times set by owner 
    void GetAvailableTimeSlots();

    //Updates reservation .txt file 
    void UpdateReservationFile();

    //Writes created reservation to array 
    void AddReservation();

    //Customer arrives, removes reservation from array
    void RemoveReservation();

    //Returns a list of Reservations
    void ShowReservations();

    

    
    
private:
    void RetrieveReservationsFromDataBase();


    std::map<std::string, float> ReservationTimes;

    vector<string> AvailableTimesVector;
    vector<vector<string>> AvailableTimesInDaysVector;
    vector<Reservation> ReservationVector;
};