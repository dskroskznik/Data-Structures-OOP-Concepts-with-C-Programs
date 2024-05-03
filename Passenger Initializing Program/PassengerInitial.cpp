// The keyword “const” indicates that the member function
// isFrequentFlyer is an accessor (only read class data)
#include <string>
#include <iostream>

enum MealType
{
    NO_PREF,
    REGULAR,
    LOW_FAT,
    VEGETARIAN
};

class Passenger
{
public:
    // default constructor
    Passenger();
    Passenger(const std::string &nm, MealType mp, const std::string &ffn = "NONE");
    Passenger(const Passenger &pass); // copy constructor
    bool isFrequentFlyer() const;
    void makeFrequentFlyer(const std::string &newFreqFlyerNo);
    void print()
    {
        std::cout << "Passenger: " << std::endl;
        std::cout << '\t' << this->name << " " << this->mealPref << " " << this->freqFlyerNo << std::endl;
    }

private:
    std::string name;
    MealType mealPref;
    bool isFreqFlyer;
    int freqFlyerNo = 0;
};

bool Passenger::isFrequentFlyer() const
{
    return isFreqFlyer;
}

void Passenger::makeFrequentFlyer(const std::string &newFreqFlyerNo)
{
    isFreqFlyer = true;
    freqFlyerNo = 0;
}
Passenger::Passenger()
{
    name = "--NO NAME--";
    mealPref = NO_PREF;
    isFreqFlyer = false;
    freqFlyerNo = 0;
}

Passenger::Passenger(const std::string &nm, MealType mp, const std::string &ffn)
{
    name = nm;
    mealPref = mp;
    isFreqFlyer = (ffn != "NONE"); // true only if ffn given
    freqFlyerNo = 0;
}

Passenger::Passenger(const Passenger &pass)
{
    name = pass.name;
    mealPref = pass.mealPref;
    isFreqFlyer = pass.isFreqFlyer;
    freqFlyerNo = pass.freqFlyerNo;
}

int main()
{
    // default constructor
    Passenger p1;

    // 2nd constructor
    Passenger p2("John Smith", VEGETARIAN, "293145");
    p2.print();
    // 2nd constructor
    Passenger p3("Pocahontas", REGULAR);
    p3.print();
    // Copy constructor
    Passenger p4(p3);

    // Copy constructor
    Passenger p5 = p2;
    p5.print();
    // default constructor
    Passenger *pp1 = new Passenger;
    // 2nd constructor
    Passenger *pp2 = new Passenger("JoeBlow", NO_PREF);
    pp2->print();
    // default constructor
    Passenger pa[20];

    return 0;
}