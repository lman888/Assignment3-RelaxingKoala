//
//  Waiter.h
//  Assignment3
//
//  Created by Stefanus Wilfrid Admaja on 18/5/2024.
//

#ifndef WAITER_H
#define WAITER_H

#include "Staff.h"
#include <string>
#include <map>

enum class MenuAction
{
    Add,
    Delete
};

class Waiter : public Staff
{
public:
    Waiter();
    virtual ~Waiter();

    void performTask(Order &order) override;
    void updateMenuAvailability(MenuAction action, const std::map<std::string, float> &items);
    void promptUpdateMenu();
};

#endif /* WAITER_H */
