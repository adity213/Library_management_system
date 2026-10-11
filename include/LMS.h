#ifndef LMS_H
#define LMS_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

struct Date {
    int d, m, y;
};

// Utility functions
int countLeapYears(Date d);
int getDifference(Date dt1, Date dt2);

class Book {
public:
    string title;
    string author;
    string isbn;
    string publication;
    bool issued;
    string issued_by;
    Date issue_date;

    Book();
    // For CSV formatting
    string toCSV() const;
    static Book fromCSV(const string& line);
};

class Book_db {
public:
    vector<Book> Book_list;
    void Add();
    void Update();
    void Delete();
    void Search();
    void list_books();
    
    // File I/O
    void saveToFile(const string& filename);
    void loadFromFile(const string& filename);
};

class User {
public:
    string id;
    string password;
    string name;

    // Virtual methods for polymorphic behavior
    virtual void Calculate_fine() = 0;
    virtual void Clear_fine_amount() = 0;
    virtual void Issue() = 0;
    virtual void Return() = 0;
    virtual void list_your_books() = 0;
    virtual string getRole() const = 0;
    virtual ~User() {}
};

class Student : public User {
public:
    int total_fine;
    vector<Book> books;

    Student() { total_fine = 0; }
    void Calculate_fine() override;
    void Clear_fine_amount() override;
    void Issue() override;
    void Return() override;
    void list_your_books() override;
    string getRole() const override { return "Student"; }

    string toCSV() const;
    static Student fromCSV(const string& line);
};

class Professor : public User {
public:
    int total_fine;
    vector<Book> books;

    Professor() { total_fine = 0; }
    void Calculate_fine() override;
    void Clear_fine_amount() override;
    void Issue() override;
    void Return() override;
    void list_your_books() override;
    string getRole() const override { return "Professor"; }

    string toCSV() const;
    static Professor fromCSV(const string& line);
};

class Librarian : public User {
public:
    Librarian();
    bool login();
    void run();

    void Calculate_fine() override {}
    void Clear_fine_amount() override {}
    void Issue() override {}
    void Return() override {}
    void list_your_books() override {}
    string getRole() const override { return "Librarian"; }
};

class User_db {
public:
    vector<Student> Student_list;
    vector<Professor> Professor_list;

    void Add();
    void Update();
    void Delete();
    void Search_student();
    void Search_professor();
    void list_users();
    void run_stud();
    void run_prof();
    int login_stud();
    int login_prof();

    // File I/O
    void saveToFile(const string& studFile, const string& profFile);
    void loadFromFile(const string& studFile, const string& profFile);
};

// Global external instances
extern User_db user_data;
extern Book_db book_data;

void start();

#endif // LMS_H
