# Employee Database Management System

This project is an Employee Database Management System implemented in C++. It provides functionalities to manage various aspects of employee data, including departments, salaries, engineers, and managers.

## Components

The project consists of the following components:

### 1. Employee

- Manages basic information about employees, such as ID, name, email, and date of birth.

### 2. Engineer

- Inherits from the Employee class and adds specific information for engineers, such as specialization and years of experience.

### 3. Manager

- Inherits from the Employee class and includes additional details specific to managers, such as department and team size.

### 4. Department

- Stores information related to departments, including department ID and name.

### 5. Salary

- Manages salary-related data for employees, including base salary, bonus, and total salary.

### 6. Database

- Handles database operations, including table creation, deletion, data manipulation, and user queries.

### 7. Log

- Provides logging functionalities, including logging errors, warnings, and information.

### 8. Validation

- Contains functions for input validation, such as validating alphabetic, numeric, email, phone number, and date of birth inputs.

### 9. Prompt

- Implements functions for user prompts and interactions, including actions on tables and the main menu.

## Features

- Creation, deletion, and manipulation of tables (employees, engineers, managers, departments, and salaries).
- User-friendly prompts for performing actions on tables and navigating the main menu.
- Input validation to ensure data integrity and prevent errors.
- Logging of errors, warnings, and information for debugging and monitoring purposes.
- Export to CSV, export data from tables to CSV files, making it easier to share or analyze data using spreadsheet software.

## Usage

To use the Employee Database Management System, follow these steps:

1. Compile the project using a C++ compiler.
2. Run the executable file generated after compilation.
3. Follow the on-screen prompts to perform various actions on tables and navigate the main menu.
4. Input data as requested and observe the system's responses.

## Requirements

- C++ compiler that supports C++17 standard.
- SQLite database library.
- Standard C++ libraries.

