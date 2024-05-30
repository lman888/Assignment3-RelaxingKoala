#include "Staff.h"
#include "DeliveryStaff.h"
#include "Waiter.h"
#include "KitchenStaff.h"

std::unique_ptr<Staff> Staff::createStaff(const std::string &type, Reservation &reservation)
{
    if (type == "Delivery")
    {
        return std::make_unique<DeliveryStaff>(reservation);
    }
    else if (type == "Waiter")
    {
        return std::make_unique<Waiter>(reservation);
    }
    else if (type == "Kitchen")
    {
        return std::make_unique<KitchenStaff>(reservation);
    }
    else
    {
        throw std::runtime_error("Unsupported staff type!");
    }
}
