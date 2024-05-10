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

    //Writes created reservation to array
    void AddReservation();

    //Customer arrives, removes reservation from array
    void RemoveReservation();

    //Returns a list of Reservations
    void ShowReservations() const;

    //updates reservation file after adding or removal of reservation
    void UpdateReservationFile();

private:
    void RetrieveReservationsFromDataBase();
};