#include "../include/Engineer.h"

void Engineer::insertEngineer() { 
    std::cout << "Insert Engineer \n";
};
void Engineer::deleteEngineer() {return;};
void Engineer::updateEngineer() {return;};
void Engineer::viewEngineer() {return;};


void Engineer::action() {
    bool flag = true;
    int choice;
    

    while (flag) {

        std::cout << "Engineer Table\n";
        std::cout << "Please select a value to perform actions:\n";
        std::cout << "1. Insert\n";
        std::cout << "2. Delete\n";
        std::cout << "3. Update\n";
        std::cout << "4. View\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice (1-5): ";


        std::cin >> choice;

        switch (choice) {
        case 1:
            insertEngineer();
            break;
        case 2:
            deleteEngineer();
            break;
        case 3:
            updateEngineer();
            break;
        case 4:
            viewEngineer();
            break;
        case 5: 
            flag = false;
            break;
        default:
            std::cerr << "Invalid choice. Please enter a number between 1 and 5.\n";
            break;
        }
    }

}
