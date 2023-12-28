#include <iostream>
#include <string>
#include <limits> // Include the <limits> header

// Define a custom exception class
class UserCriteriaException : public std::exception {
public:
    UserCriteriaException(const std::string& error_msg) : error_msg_(error_msg) {}

    // Override the what() function to return the error message
    const char* what() const noexcept override {
        return error_msg_.c_str();
    }

private:
    std::string error_msg_;
};

// Function to check user criteria
void check_user_criteria(int age, float income, const std::string& city, const std::string& vehicle) {
    if (age < 18 || age > 55) {
        throw UserCriteriaException("Age criterion not met");
    }
    if (income < 50000 || income > 100000) {
        throw UserCriteriaException("Income criterion not met");
    }
    if (city != "Pune" && city != "Mumbai" && city != "Bangalore" && city != "Chennai") {
        throw UserCriteriaException("City criterion not met");
    }
    if (vehicle != "4-wheeler") {
        throw UserCriteriaException("Vehicle criterion not met");
    }
}

int main() {
    // Accept input from user
    int age;
    float income;
    std::string city, vehicle;
    std::cout << "Enter age: ";
    std::cin >> age;
    std::cout << "Enter income: ";
    std::cin >> income;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
    std::cout << "Enter city: ";
    std::getline(std::cin, city);
    std::cout << "Enter vehicle type: ";
    std::cin >> vehicle;

    try {
        // Call the check_user_criteria function
        check_user_criteria(age, income, city, vehicle);
        std::cout << "User meets all criteria" << std::endl;
    } catch (const UserCriteriaException& e) {
        std::cout << "Exception occurred: " << e.what() << std::endl;
    }

    return 0;
}
