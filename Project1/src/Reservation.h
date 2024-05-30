/*WIP by Amelie*/
#pragma once
#include <map>
#include <string>
#include <vector>
#include <array>
using namespace std;

//ISUBJECT
#include <list>
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

    string numOfTablesPerTime = "3";//change the number of tables able to be booked at a time
    int maxPeoplePerTable = 10;

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
    void AttachObserver(IObserver* observer);
    void DetachObserver(IObserver* observer);
    void NotifyObservers();
    void MessageToBeNotifiedToObservers(string msg);
    void HowManyObservers();


private:
    void RetrieveReservationsFromDataBase();


    map<string, float> ReservationTimes;

    vector<string> AvailableTimesVector;
    vector<vector<string>> AvailableTimesInDaysVector;
    vector<Reservation> ReservationVector;

    //ISUBJECT
    list<IObserver*> list_observer_;
    string message_;

    //ISUBJECT
   /* std::list<IObserver*> list_observer_;
    std::string message_;*/
};