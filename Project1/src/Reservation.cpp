/*WIP by Amelie*/
#include "Reservation.h"

#include <array>
#include <vector>
#include <tuple>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

Reservation::Reservation()
{
    RetrieveReservationsFromDataBase();
    GetAvailableTimeSlots();
}


void Reservation::Attach(IObserver* observer) {
    list_observer_.push_back(observer);
}
void Reservation::Detach(IObserver* observer) {
    list_observer_.remove(observer);
}
void Reservation::Notify() {
    std::list<IObserver*>::iterator iterator = list_observer_.begin();
    this->HowManyObservers();
    while (iterator != list_observer_.end()) {
        (*iterator)->Update(message_);
        ++iterator;
    }
}

void Reservation::CreateMessage(std::string message = "Empty") {
    this->message_ = message;
    this->Notify();
}
void Reservation::HowManyObservers() {
    std::cout << "There are " << list_observer_.size() << " observers observing the reservation list.\n";
}


//Look through a document and grab the variables and pass the two variables into an array - ONLY runs when app starts
void Reservation::RetrieveReservationsFromDataBase()
{
    //cout << "Getting all available reservations from database! (RetrieveReservationsFromDataBase(),Reservation.cpp)" << endl;//Remove later

    ifstream ReservationFile("ReservationDatabase/Reservations.txt");
    string NameOfReserver;
    int NumOfPeople;
    string Time;
    int Day;
    int Month;
    int Year;

    if (ReservationFile.is_open())
    {
        string Line;

        while (getline(ReservationFile, Line))
        {
            istringstream StringStream(Line);

            //Extract the data from the txt file
            if (StringStream >> Day >> Month >> Year >> Time >> NameOfReserver >> NumOfPeople)
            {
                ReservationVector.push_back(Reservation(Day, Month, Year, Time, NameOfReserver, NumOfPeople));
            }
            else
            {
                cout << "Error Parsing Line " << Line << endl;
            }
        }

        ReservationFile.close();
    }
    else
    {
        cerr << "Unable to open file!" << endl;
    }
}

//Loop through AvailableTimes.txt file and add to a vector that has a vector of strings 
//- runs when app starts called by UpdateReservationFile()
void Reservation::GetAvailableTimeSlots()
{
    //cout << "Getting all available timeslots for reservation here! (GetAvailableTimeSlots(),Reservation.cpp)" << endl;//Remove later

    ifstream FileWithAvailableTimesForReservation("ReservationDatabase/AvailableTimes.txt");

    if (FileWithAvailableTimesForReservation.is_open())
    {
        string Line;
        int Duplicates;

        while (getline(FileWithAvailableTimesForReservation, Line))
        {
            istringstream StringStream(Line);

            //Extract the data from the .txt file
            if (StringStream >> Day >> Month >> Year >> Time)
            {   //A vector with strings
                AvailableTimesVector.clear();
                AvailableTimesVector.push_back(to_string(Day)); //AvailableTimesInDaysVector[i][0]
                AvailableTimesVector.push_back(to_string(Month));//AvailableTimesInDaysVector[i][1]
                AvailableTimesVector.push_back(to_string(Year));//AvailableTimesInDaysVector[i][2]
                AvailableTimesVector.push_back(Time);//AvailableTimesInDaysVector[i][3]
                //A vector with vector of strings
                AvailableTimesInDaysVector.push_back(AvailableTimesVector);
            }
            else
            {
                cout << "Error Parsing Line " << Line << endl;
            }
        }

        for (int i = 0; i < AvailableTimesInDaysVector.size(); i++) {
            Duplicates = 0;
            for (int j = 0; j < ReservationVector.size(); j++) {
                if (to_string(ReservationVector[j].Day) == AvailableTimesInDaysVector[i][0] && to_string(ReservationVector[j].Month) == AvailableTimesInDaysVector[i][1] && to_string(ReservationVector[j].Year) == AvailableTimesInDaysVector[i][2] && ReservationVector[j].Time == AvailableTimesInDaysVector[i][3]) {
                    Duplicates += 1;//AvailableTimesInDaysVector[i][4]
                }
            }
            AvailableTimesInDaysVector[i].push_back(to_string(Duplicates));
        }
        FileWithAvailableTimesForReservation.close();
    }
    else
    {
        cerr << "Unable to open file!" << endl;
    }
}

//Update .txt file with ReservationVector - called by AddReservation() & RemoveReservation()
void Reservation::UpdateReservationFile()
{
    //cout << "Updating reservation file here! (UpdateReservationFile(),Reservation.cpp)" << endl;//Remove later

    ofstream ReservationFile("ReservationDatabase/Reservations.txt");
    if (ReservationFile.is_open()) {
        for (auto& Reservation : ReservationVector) {
            ReservationFile << Reservation.Day << " " << Reservation.Month << " " << Reservation.Year << " " << Reservation.Time << " " << Reservation.NameOfReserver << " " << Reservation.NumOfPeople << "\n";
        }
        ReservationFile.close();
    }
    GetAvailableTimeSlots();
}

//Prompt to enter day month year time and numOfPeople to add reservation into vector - used by customer
void Reservation::AddReservation()//Currently does not check for name dupes in same booking time n day
{

    cout << "Create a reservation here! (AddReservation(),Reservation.cpp)" << endl;//Remove later
    ShowAvailableTimes();
    cout << "Enter the reservation you want to create with the name, time, num of people, day, month and year for reservation" << endl;

    //Comment during development
    /*cout << "Enter NameOfReserver (string)" << endl;
    cin >> NameOfReserver;
    cout << "Enter Time (string)" << endl;
    cin >> Time;
    cout << "Enter NumOfPeople (int)" << endl;
    cin >> NumOfPeople;
    cout << "Enter Day (int)" << endl;
    cin >> Day;
    cout << "Enter Month (int)" << endl;
    cin >> Month;
    cout << "Enter Year (int)" << endl;
    cin >> Year;*/

    //For development testing
    /* Day = 1;
     Month = 2;
     Year = 1903;
     Time = "10:45";
     NameOfReserver = "Jason";
     NumOfPeople = 100;*/

     //For development testing 2
    cout << "DEV MODE INPUT\n";
    Day = 11;
    Month = 5;
    Year = 2024;
    Time = "11:30";
    NameOfReserver = "Jason";
    NumOfPeople = 20;

    for (int i = 0; i < AvailableTimesInDaysVector.size(); i++) {
        if (AvailableTimesInDaysVector[i][0] == to_string(Day) && AvailableTimesInDaysVector[i][1] == to_string(Month) && AvailableTimesInDaysVector[i][2] == to_string(Year) && AvailableTimesInDaysVector[i][3] == Time && AvailableTimesInDaysVector[i][4] != "3") {
            cout << "Reservation made!\n";
            ostringstream msg;
            msg << "A reservation was made by " << NameOfReserver << " on " << to_string(Day) << "-" << to_string(Month) << "-" << to_string(Year) << " at " << Time << " for " << to_string(NumOfPeople) << " people.";
            this->CreateMessage(msg.str());
            ReservationVector.push_back(Reservation(Day, Month, Year, Time, NameOfReserver, NumOfPeople));
            UpdateReservationFile();
            return;
        }
    }
    cout << "That time is not available. Please choose another from the following list.\n";
    ShowAvailableTimes();
}

void Reservation::ShowAvailableTimes() {
    cout << "Available reservation times are: \n";
    for (int i = 0; i < AvailableTimesInDaysVector.size(); i++) {
        if (AvailableTimesInDaysVector[i][4] != "3") {
            cout << AvailableTimesInDaysVector[i][0] << "-" << AvailableTimesInDaysVector[i][1] << "-" << AvailableTimesInDaysVector[i][2] << " " << AvailableTimesInDaysVector[i][3] << "\n";
        }
    }
}

//Remove reservation from vector and update the .txt file 
//- called by customer (in case they messed up their reservation) and staff to remove customers who have arrived
void Reservation::RemoveReservation()
{
    cout << "Remove a reservation here! (RemoveReservation(),Reservation.cpp)" << endl;
    cout << "Enter the reservation you want to remove with the name, time, day, month and year of reservation" << endl;

    cout << "Enter NameOfReserver (string)" << endl;
    cin >> NameOfReserver;
    cout << "Enter Time (string)" << endl;
    cin >> Time;
    cout << "Enter Day (int)" << endl;
    cin >> Day;
    cout << "Enter Month (int)" << endl;
    cin >> Month;
    cout << "Enter Year (int)" << endl;
    cin >> Year;

    //For development testing
    /*Day = 11;
    Month = 5;
    Year = 2024;
    Time = "11:30";
    NameOfReserver = "Jason";*/

    for (int i = 0; i < ReservationVector.size(); i++) {
        if (ReservationVector[i].Day == Day && ReservationVector[i].Month == Month && ReservationVector[i].Year == Year && ReservationVector[i].Time == Time && ReservationVector[i].NameOfReserver == NameOfReserver) {
            ReservationVector.erase(ReservationVector.begin() + i);
            cout << "Reservation cancelled!\n";
            UpdateReservationFile();
            return;
        }
    }
    cout << "That booking does not exist.\n";
}

//Show all reservations - called by staff logged in
void Reservation::ShowReservations()
{
    cout << "Show all reservation here! (ShowReservations(),Reservation.cpp)" << endl;//Remove later

    //For pretty UI 
    cout << "Day\t|Month\t|Year\t|Time\t|Num Of People\t|Name of Reserver\n";
    cout << "----\t----\t----\t----\t----\t------------\t\n";
    for (auto& Reservation : ReservationVector) {
        cout << Reservation.Day << "\t|" << Reservation.Month << "\t|" << Reservation.Year << "\t|" << Reservation.Time << "\t|" << Reservation.NumOfPeople << "\t\t|" << Reservation.NameOfReserver << "\n";
    }
}