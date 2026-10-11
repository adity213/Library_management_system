#include "../include/LMS.h"

int main() {
    // Load existing data from CSV files
    book_data.loadFromFile("data/books.csv");
    user_data.loadFromFile("data/students.csv", "data/professors.csv");

    // Start the application loop
    start();

    // Save data back to CSV files before exiting
    book_data.saveToFile("data/books.csv");
    user_data.saveToFile("data/students.csv", "data/professors.csv");

    return 0; 
}
