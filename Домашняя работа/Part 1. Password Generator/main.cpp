#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>

int number_of_passwords;
int password_length;
std::vector <char> Alphabet;
std::string file_name;

void fillingTheAlphabet(){
    for (int i = 48; i < 58; ++i) {
        Alphabet.push_back((char)i);
    }
    for (int i = 65; i < 91; ++i) {
        Alphabet.push_back((char)i);
    }
    for (int i = 97; i < 123; ++i) {
        Alphabet.push_back((char)i);
    }
    for (int i = 35; i < 39; ++i) {
        Alphabet.push_back((char)i);
    }
    Alphabet.push_back('-');
}

std::vector <char> generatePassword(int call_number){
    std::vector <char> password;
    srand((unsigned)time(nullptr)/call_number);
    password.reserve(password_length);
    for (int i = 0; i < password_length; ++i) {
        password.push_back(Alphabet[(rand() % Alphabet.size())]);
    }
    return password;
}

int main() {
    std::ofstream passwords_file;

    fillingTheAlphabet();

    std::cout << "Welcome to a password generator!" << std::endl
    << "Please, enter the desired number of generated passwords: ";
    std::cin >> number_of_passwords;

    std::cout << "Please, enter the desired password length: ";
    std::cin >> password_length;

    std::cout << "Please, enter the desired filename with the generated passwords: ";
    std::cin >> file_name;

    file_name += ".pass";

    passwords_file.open(file_name);
    if(!passwords_file.is_open()){
        std::cout << "ERROR: The program was unable to create an output file for passwords." << std::endl
        << "The program ended with an error";
        return 0;
    }

    for (int i = 1; i < number_of_passwords + 1; ++i) {
        for (auto symbol:generatePassword(i)) {
            passwords_file << symbol;
        }
        passwords_file << std::endl;
    }

    std::cout << "File " << file_name  << " successfully generated.";

    return 0;
}
