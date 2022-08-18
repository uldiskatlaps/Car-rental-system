#include <iostream>
#include <string>
#include <map>
#include <ctime>
#include <typeinfo>

class Rental {
public:
    std::map<std::string, int> allPrices = {
        {"Audi Q7", 60},
        {"BMW X6", 65},
        {"Opel Zafira", 15},
        {"Toyota Prius", 25}
    };

    std::map<std::string, std::string> allCars = {
        {"Audi Q7", "Colour: Red\nYear: 2016\nMileage: 142 000\n"},
        {"BMW X6", "Colour: Black\nYear: 2017\nMileage: 133 000\n"},
        {"Opel Zafira", "Colour: Grey\nYear: 2010\nMileage: 265 000\n"},
        {"Toyota Prius", "Colour: White\nYear: 2010\nMileage: 176 000\n"}
    };   

    std::map<std::string, int> carPrice = allPrices;
    std::map<std::string, std::string> carList = allCars;

    void showList() {      
        int count = 1;

        for (auto& iter : carList) {
            std::cout << "( " << count << " )\n";
            count++;
            std::cout << iter.first << std::endl;
            std::cout << iter.second;
            std::cout << "Price: " << carPrice.at(iter.first) << " EUR/day.\n" << std::endl;
        }
    }

    void chooseCar(int number) {
        int count = 0;
        int size = carList.size();

        std::string* keyArray = new std::string[size];

        for (auto& iter : carList) {
            keyArray[count] = iter.first;
            count++;
        }

        carList.erase(keyArray[number - 1]);  

        delete[] keyArray;
    }

    std::string carKey(int number) {
        int count = 0;
        int size = carPrice.size();

        std::string* keyArray = new std::string[size];

        for (auto& iter : carPrice) {
            keyArray[count] = iter.first;
            count++;
        }     

        return keyArray[number - 1];

        carPrice.erase(keyArray[number - 1]);

        delete[] keyArray;
    }

    int payment(int days, std::string car) {
        int price = carPrice.at(car);
        return days * price;
    }

    void dialog() {
        int size = carList.size();
        int pickNumber, days;

        std::cout << "Welcom to car rental paradise. Please pick your car...\n\n\n";
        showList();

        do {
            std::cout << "Enter number between 1 and " << size << ".\nYour choice : ";
            std::cin >> pickNumber;
        } while (pickNumber < 1 || pickNumber > size);
            
        chooseCar(pickNumber);

        do {
            std::cout << "Time (days): ";
            std::cin >> days;
        } while (days < 1 || days > 14);

        system("cls");

        std::cout << "Payment: " << payment(days, carKey(pickNumber)) << " EUR.\n";
    }
};

int main()
{
    Rental uldis;
    uldis.dialog();
    system("pause");
    system("cls");
    uldis.dialog();
}