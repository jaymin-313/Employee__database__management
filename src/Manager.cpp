#include "../include/Manager.h"
#include "../include/Employee.h"
#include "../include/log.h"

using logs::Log;
void Manager::setManagementExperience() {
    std::cout << "Enter Manager Experience in years: ";
    std::cin >> management_experience;
}
void Manager::setProjectTitle() {
    std::cout << "Enter Manager's Project Title: ";
    std::cin.ignore();
    std::getline(std::cin, project_title);
}

void Manager::insertManager() {
    if (insertEmployee()) {

        setManagementExperience();
        setProjectTitle();

        std::string insertQuery = "INSERT INTO Manager(id, management_experience , project_title) VALUES ("
            + std::to_string(Employee::getId()) + ","
            + std::to_string(management_experience) + ",'"
            + project_title + "');";

        if (Database::getInstance().executeQuery(insertQuery)) {
            std::cout << "Inserted Manager Succesfully ! \n\n";
            Log::getInstance().Info("Manager Inserted for id : ", getId());
        }
        else
            std::cout << Database::getInstance().getError() << "\n";
    }
 
};
void Manager::deleteManager() {
    setId();
    std::string checkManager = "SELECT id FROM Manager WHERE id = " + std::to_string(getId());

    if (!Database::getInstance().executeQueryCallback(checkManager)) {
        std::cout << Database::getInstance().getError() << std::endl;
    }

    if (int rows = Database::getInstance().getRow(); rows > 0)
        deleteEmployeeById(getId());
    else
        std::cout << "Manager Not exist" << "\n\n";
};
void Manager::updateManager() {
    int choice;
    std::string updateQuery{};
    std::cout << "1. To update Employee Table related details\n";
    std::cout << "2. To update Manager Table related details\n";

    std::cout << "Select from above given choices:";
    std::cin >> choice;
    switch (choice) {
    case 1:
        updateEmployee();
        break;
    case 2:
        
        int id;
        std::cout << "Enter Employee id to update: \n";
        std::cin >> id;


        std::cout << "Please select an attribute to update:\n";
        std::cout << "1. Manager's Experience\n";
        std::cout << "2. Project Title\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice (1-3): ";

        std::cin >> choice;
        std::cout << "\n";

        switch (choice) {
        case 1:
            setManagementExperience();
            updateQuery = "UPDATE Manager SET management_experience = '" + std::to_string(getManagementExperience()) + "' WHERE id = " + std::to_string(id);
            break;
        case 2:
            setProjectTitle();
            updateQuery = "UPDATE Manager SET project_title= '" + getProjectTitle() + "' WHERE id = " + std::to_string(id);
            break;
        case 3:
            break;
        default:
            std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            updateManager();
            break;
        }

        if (Database::getInstance().executeQuery(updateQuery)) {

            int changes = sqlite3_changes(Database::getInstance().db);

            std::cout << changes << " row affected \n\n";
            if (changes != 0) {
                std::cout << "Manager Updated Succesfully ! \n\n";
            }

        }
        else
            std::cout << Database::getInstance().getError() << "\n";
        break;
    default:
        std::cout << "Invalid choice Please Enter a number 1 or 2 only\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
    }

};
void Manager::viewManager() {
    std::string selectQuery{};

    int choice;

    std::cout << "Please select a column to view a Manager:\n";
    std::cout << "1. ALL\n";
    std::cout << "2. Employee Id\n";
    std::cout << "3. Exit\n";

    std::cout << "Enter your choice (1-3): ";


    std::cin >> choice;
    std::cout << "\n";

    switch (choice) {
    case 1:
        selectQuery = "SELECT * FROM Employee NATURAL JOIN Manager WHERE Employee.id==Manager.id ";
        break;
    case 2:
        setId();
        selectQuery = "SELECT * FROM Employee NATURAL JOIN Manager WHERE Employee.id==Manager.id AND Employee.id =" + std::to_string(getId());
        break;
    case 3:
        break;
    default:
        std::cout << "Invalid choice. Please enter a number between 1 and 3.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        viewManager();
        break;
    }

    if (!Database::getInstance().executeQueryCallback(selectQuery)) {
        std::cout << Database::getInstance().getError() << std::endl;
    }
};
void Manager::describeManager()
{

    if (!Database::getInstance().executeQueryCallback("pragma table_info('Manager');")) {
        std::cout << Database::getInstance().getError();
    }
    else {
        Log::getInstance().Info("Manager Described.");
    }

}

void Manager::action() {
    bool flag = true;

    std::cout << "Manager Table\n";
    std::cout << "Please select a value to perform actions:\n";
    std::cout << "1. Insert\n";
    std::cout << "2. Delete\n";
    std::cout << "3. Update\n";
    std::cout << "4. View\n";
    std::cout << "5. Restore old data\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice (1-6): ";
    while (flag) {
        int choice;
        std::cin >> choice;


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
        case 5:
            describeManager();
            break;
        case 6: 
            Database::getInstance().import_from_csv("Manager", "Manager.csv");
            std::cout << "Manager data restored from file\n";
            break;
        case 7: // Exit
            flag = false;
            break;
        default:
            std::cerr << "Invalid choice. Please enter a number between 1 and 7.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
}
