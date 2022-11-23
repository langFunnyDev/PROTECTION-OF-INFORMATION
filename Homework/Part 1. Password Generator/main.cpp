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

void Generator(){
    std::ofstream passwords_file;

    fillingTheAlphabet();

    std::cout << "Welcome to a password generator!" << std::endl
              << "Please, enter the desired number of generated passwords: ";
    std::cin >> number_of_passwords;

    std::cout << "Please, enter the desired password length: ";
    std::cin >> password_length;

    std::cout << "Please, enter the desired filename with the generated passwords: ";
    std::cin >> file_name;

    passwords_file.open(file_name + ".pass");

    if(!passwords_file.is_open()){
        std::cout << "ERROR: The program was unable to create an output file for passwords." << std::endl
                  << "The program ended with an error";
        return;
    }

    for (int i = 1; i <= number_of_passwords; ++i) {
        for (auto symbol:generatePassword(i)) {
            passwords_file << symbol;
        }
        passwords_file << " ";
    }

    std::cout << "File " << file_name + ".pass"  << " successfully generated." << std::endl;

    passwords_file.close();
}

void Encryptor(){
    int encryptionKey;

    std::ifstream passwords_file;
    std::ofstream encrypted_passwords_file;

    passwords_file.open(file_name + ".pass");

    if(!passwords_file.is_open()){
        std::cout << "ERROR: The program was unable to create an output file for passwords." << std::endl
                  << "The program ended with an error";
        return;
    }

    encrypted_passwords_file.open(file_name + ".encpass");

    if(!encrypted_passwords_file.is_open()){
        std::cout << "ERROR: The program was unable to create an output file for passwords." << std::endl
                  << "The program ended with an error";
        return;
    }

    std::cout << "Enter number - encryption key: ";
    std::cin >> encryptionKey;

    while (!passwords_file.eof()){
        char buffer = (char) passwords_file.get();
        encrypted_passwords_file << ((char) ((int) buffer + (encryptionKey % 127)));
    }

    passwords_file.close();
    encrypted_passwords_file.close();

    std::string remove_file_name = file_name + ".pass";
    remove(remove_file_name.c_str());

    std::cout << "Complete.";
}

void Decrypter(){
    int decryptionKey;

    std::ifstream encrypted_passwords_file;
    std::ofstream passwords_file;

    std::cout << "Enter a filename without extension: ";
    std::cin >> file_name;

    encrypted_passwords_file.open(file_name + ".encpass");

    if(!encrypted_passwords_file.is_open()){
        std::cout << "ERROR: The program was unable to create an output file for passwords." << std::endl
                  << "The program ended with an error";
        return;
    }

    passwords_file.open(file_name + ".pass");

    if(!passwords_file.is_open()){
        std::cout << "ERROR: The program was unable to create an output file for passwords." << std::endl
                  << "The program ended with an error";
        return;
    }

    std::cout << "Enter number - decryption key: ";
    std::cin >> decryptionKey;

    while (!encrypted_passwords_file.eof()){
        char buffer = (char) encrypted_passwords_file.get();
        passwords_file << ((char) ((int) buffer - (decryptionKey % 127)));
    }

    passwords_file.close();
    encrypted_passwords_file.close();

    std::string remove_file_name = file_name + ".encpass";
    remove(remove_file_name.c_str());

    std::cout << "Complete.";
}

int main() {

    int workMode = 0;
    bool wantsEncrypt = 0;

    std::cout << "Hello, please select work mode: " << std::endl << "    1) Generate passwords" << std::endl << "    2) Decrypt passwords" << std::endl << "Enter work mode here:";

    std::cin >> workMode;

    switch (workMode) {
        case 1:
            Generator();
            std::cout << "If you want to encrypt the received file enter 1 otherwise enter 0: ";
            std::cin >> wantsEncrypt;
            if (wantsEncrypt){
                Encryptor();
            } else {
                std::cout << "Thank you for using this program. Good day.";
            }
            break;
        case 2:
            Decrypter();
            break;
        default:
            std::cout << "You are entered wrong number of work mode !";
    }

    return 0;
}
