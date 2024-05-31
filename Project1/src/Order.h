#pragma once
#include <map>
#include <string>

//ISUBJECT
#include<list>
#include<string>
#include "ISubject.h"
#include "IObserver.h"

//Forward Declaration
class Menu;

class Order: public ISubject
{
public:

    Order(Menu* aMenu);
    ~Order() = default;
    
    void AddToOrder(const std::string& aItem);

    void RemoveFromOrder(const std::string& aItem);

    void ShowOrder() const;

    void ClearOrder();

    void ShowTotalCost() const;

    void GenerateReceipt(std::string orderType) const;



    ///OVERRIDING ISUBJECT INTERFACE
    void AttachObserver(IObserver* observer);
    void DetachObserver(IObserver* observer);
    void NotifyObservers();
    void MessageToBeNotifiedToObservers(std::string msg);
    void HowManyObservers();
    
private:

    bool CaseSensitiveStringCompare(const std::string& aItem, const std::string& aMenuItem);
    
    std::multimap<std::string, float> OrderItems;

    float TotalCost;

    Menu* MenuItems;

    //ISUBJECT
    std::list<IObserver*> list_observer_;
    std::string message_;
};
