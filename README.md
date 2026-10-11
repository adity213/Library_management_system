# C++ Library Management System

A robust, terminal-based Library Management System built to demonstrate core Object-Oriented Programming (OOP) principles in C++. This project acts as a digital librarian, handling user roles, inventory tracking, and dynamic fine calculations.

## Core Features

- **Role-Based Access Control (RBAC):** Distinct privileges for Librarians (Admin), Professors, and Students.
- **Inventory Management:** Full CRUD (Create, Read, Update, Delete) operations for books and users.
- **Transaction Tracking:** Issue and return books with automated date difference calculations.
- **Dynamic Fine System:** Custom fine policies applied based on the user's role (Polymorphism).
- **Data Persistence:** Serializes library state to CSV files to ensure data is preserved across sessions using File I/O.

## Technical Architecture & OOP Principles

- **Inheritance:** Implements a hierarchical class structure. Both `Student` and `Professor` classes inherit common attributes (id, password, name) from a base `User` class.
- **Polymorphism:** Utilizes virtual functions in the base `User` class (e.g., `calculateFine()`) to dynamically resolve the correct fine calculation algorithm at runtime based on the derived object type.
- **Encapsulation:** Protects internal state (like lists of borrowed books and total accumulated fines) by exposing them only through controlled class methods.

## Directory Structure
```text
Library-Management-System/
├── src/           # C++ source code (.cpp)
├── include/       # Header files (.h)
└── data/          # CSV files for database persistence
```
