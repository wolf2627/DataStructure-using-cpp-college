#include <iostream>

// ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

int main() {
    std::cout << "This is " << RED << "red" << RESET << " text." << std::endl;
    std::cout << "This is " << GREEN << "green" << RESET << " text." << std::endl;
    std::cout << "This is " << YELLOW << "yellow" << RESET << " text." << std::endl;
    std::cout << "This is " << BLUE << "blue" << RESET << " text." << std::endl;

    return 0;
}
