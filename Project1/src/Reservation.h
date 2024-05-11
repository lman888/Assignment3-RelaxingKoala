/*WIP by Amelie*/
#pragma once
#include <map>
#include <string>
using namespace std;

class Reservation
{
public:
    Reservation();
    ~Reservation() = default;

    //Writes created reservation to array - First
    void AddReservation(std::string aName, float aTime);

    //Customer arrives, removes reservation from array
    void RemoveReservation();

    //Returns a list of Reservations
    void ShowReservations() const;

    //updates reservation file after adding or removal of reservation
    void UpdateReservationFile();

    void GetAvailableTimeSlots();
    
private:
    void RetrieveReservationsFromDataBase();

    std::map<std::string, float> reservation;
    
    array<int, 5> TimeSlots[] = {6.0f, 6.3f, 7.0f, 7.3f, 8.0f};
};