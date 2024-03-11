#include "../include/Engineer.h"

void Engineer::setProgrammingLanguage()
{
    std::cout << "Enter Programming Language (seperated by comma if multiple) : \n";
    std::cin.ignore();
    std::getline(std::cin, programming_language);
}

void Engineer::setSpecialization()
{
    std::cout << "Enter Specialization : \n";
    std::cin >> specialization;
}

void Engineer::insertEngineer() {

    insertEmployee();
    setProgrammingLanguage();
    setSpecialization();

    std::string insertQueryEngineer = "INSERT INTO Engineer (id, programming_language,specialization) VALUES ("
        + std::to_string(getId()) + ", '" +
        programming_language + "', '" +
        specialization + "'" +
        ");";

    if (Database::getInstance().executeQuery(insertQueryEngineer))
        std::cout << "Inserted Engineer Succesfully ! \n\n";
    else
        std::cout << Database::getInstance().getError() << "\n\n";

};

void Engineer::deleteEngineer() {

    setId();
    std::string checkEngineer = "SELECT id FROM Engineer WHERE id = " + std::to_string(getId());

    if (!Database::getInstance().executeQueryCallback(checkEngineer)) {
        std::cout << Database::getInstance().getError() << std::endl;
    }

    if (int rows = Database::getInstance().getRow(); rows > 0)
        deleteEmployeeById(getId());
    else
        std::cout << "Engineer Not exist" << "\n\n";


};
void Engineer::updateEngineer() {
    int choice;
    std::string updateQuery{};
    std::cout << "1. To update Employee Table related details\n";
    std::cout << "2. To update Engineer Table related details\n";

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
        std::cout << "1. Programming Language \n";
        std::cout << "2. Specialization \n";
        std::cout << "3. Exit \n";
        std::cout << "Enter your choice (1-3): ";

        std::cin >> choice;
        std::cout << "\n";

        switch (choice) {
        case 1:
            setProgrammingLanguage();
            updateQuery = "UPDATE Engineer SET programming_language = '" + getProgrammingLanguage() + "' WHERE id = " + std::to_string(id);
            break;
        case 2:
            setSpecialization();
            updateQuery = "UPDATE Engineer SET specialization= '" + getSpecialization() + "' WHERE id = " + std::to_string(id);
            break;
        case 3:
            break;
        default:
            std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
            updateEngineer();
            break;
        }

        if (Database::getInstance().executeQuery(updateQuery)) {

            int changes = sqlite3_changes(Database::getInstance().db);

            std::cout << changes << " row affected \n\n";
            if (changes != 0) {
                std::cout << "Engineer Updated Succesfully ! \n\n";
            }

        }
        else
            std::cout << Database::getInstance().getError() << "\n";
        break;
    default:
        std::cout << "Invalid choice Please Enter a number 1 or 2 only\n";
        break;
    }

};
void Engineer::viewEngineer() {

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
        selectQuery = "SELECT * FROM Employee NATURAL JOIN Engineer WHERE Employee.id==Engineer.id ";
        break;
    case 2:
        setId();
        selectQuery = "SELECT * FROM Employee NATURAL JOIN Engineer WHERE Employee.id==Engineer.id AND Employee.id =" + std::to_string(getId());
        break;
    case 3:
        break;
    default:
        std::cout << "Invalid choice. Please enter a number between 1 and 3.\n";
        viewEngineer();
        break;
    }

    if (!Database::getInstance().executeQueryCallback(selectQuery)) {
        std::cout << Database::getInstance().getError() << std::endl;
    }

};


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