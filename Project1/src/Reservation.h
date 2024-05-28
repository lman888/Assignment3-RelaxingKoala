/*WIP by Amelie*/
#pragma once
#include <map>
#include <string>
#include <vector>
#include <array>
#include <list>
using namespace std;

#include "ISubject.h"
#include "IObserver.h"

class Reservation : public ISubject
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

    //Shows all available time for Reservation
    void ShowAvailableTimes();

    //Customer arrives, removes reservation from array
    void RemoveReservation();

    //Returns a list of Reservations
    void ShowReservations();

    ///OVERRIDING ISUBJECT INTERFACE
    void Attach(IObserver* observer);
    void Detach(IObserver* observer);
    void Notify();
    void CreateMessage(string msg);
    void HowManyObservers();


private:
    void RetrieveReservationsFromDataBase();


    std::map<std::string, float> ReservationTimes;

    vector<string> AvailableTimesVector;
    vector<vector<string>> AvailableTimesInDaysVector;
    vector<Reservation> ReservationVector;


    std::list<IObserver*> list_observer_;
    std::string message_;
};