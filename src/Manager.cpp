#include "../include/Manager.h"

void Manager::insertManager() { return; };
void Manager::deleteManager() {return;};
void Manager::updateManager() {return;};
void Manager::viewManager() {return;};


void Manager::action() {
    bool flag = true;

    std::cout << "Manager Table\n";
    std::cout << "Please select a value to perform actions:\n";
    std::cout << "1. Insert\n";
    std::cout << "2. Delete\n";
    std::cout << "3. Update\n";
    std::cout << "4. View\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice (1-5): ";

    int choice;
    std::cin >> choice;

    while (flag) {
        switch (choice) {
        case 1:
            insertManager();
            break;
        case 2:
            deleteManager();
            break;
        case 3:
            updateManager();
            break;
        case 4:
            viewManager();
            break;
        case 5: // Exit
            flag = false;
            break;
        default:
            std::cerr << "Invalid choice. Please enter a number between 1 and 5.\n";
            break;
        }
    }
}
