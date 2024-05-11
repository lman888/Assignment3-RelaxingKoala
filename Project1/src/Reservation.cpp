/*WIP by Amelie*/
#include "Reservation.h"

#include <array>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

Reservation::Reservation()
{
    //RetrieveReservationsFromDataBase();
}

void Reservation::RetrieveReservationsFromDataBase()
{
    //Look through a document and grab the variables and pass the two variables into an array

    ifstream ReservationFile("ReservationDatabase/Reservations.txt");

    if (ReservationFile.is_open())
    {
        string Line;

        while (getline(ReservationFile, Line))
        {
            istringstream StringStream(Line);

            string NameOfReserver;
            int NumOfPeople;
            float Time;
            int Day;
            int Month;
            int Year;

            //Extract the data from the txt file
            if (StringStream >> NameOfReserver >> NumOfPeople >> Time >> Day >> Month >> Year)
            {
                //can i make a Reservation Object and append it to an array of reservations? 
                //unsure if we're only supposed to have one instance of each class
                //so afterwards i can do RemoveFromReservation() with 
                //'for eachReservation in array, if eachReservation.NameOfReserver == xyz: dropfromarray & rewrite .txt file'
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

void Reservation::AddReservation(std::string aName, float aTime)
{
    //prompt to enter day month year time and numOfPeople to add into array

    //Amelia - aTime (5, 6)
    //Check for duplicates
    
    //Adds Reservation to a Map
    reservation[aName] = aTime;


    //
}

void Reservation::RemoveReservation()
{
    //remove reservation from array 
    
}

void Reservation::ShowReservations() const
{
   //show entire array of all reservations
}

void Reservation::UpdateReservationFile() 
{
    //update .txt file of whatever reservation was added or removed
}

void Reservation::GetAvailableTimeSlots()
{
    //Loop through TimeSlots array
    // cout
}