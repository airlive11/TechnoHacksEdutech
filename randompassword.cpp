/**
 * Technohacks edutech C++ Internship 
 * Task Number - 9
 * Task Name - Random Password generator
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

std::string generateRandomPassword(int length) {
    const std::string lowercaseLetters = "abcdefghijklmnopqrstuvwxyz";
    const std::string uppercaseLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string digits = "0123456789";
    const std::string specialCharacters = "!@#$%^&*";

    const std::string allCharacters = lowercaseLetters + uppercaseLetters + digits + specialCharacters;
    const int allCharactersLength = allCharacters.length();

    std::string password;
    srand(time(0));

    for (int i = 0; i < length; ++i) {
        int randomIndex = rand() % allCharactersLength;
        password += allCharacters[randomIndex];
    }

    return password;
}

int main() {
    int passwordLength;
    std::cout << "Enter the desired password length: ";
    std::cin >> passwordLength;

    if (passwordLength <= 0) {
        std::cout << "Password length should be greater than 0.\n";
        return 1;
    }

    std::string randomPassword = generateRandomPassword(passwordLength);
    std::cout << "Generated random password: " << randomPassword << "\n";

    return 0;
}
