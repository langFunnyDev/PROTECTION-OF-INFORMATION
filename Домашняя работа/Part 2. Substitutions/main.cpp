#include <iostream>
#include <fstream>

std::ifstream original_file;
std::ofstream encrypted_file;

int main() {
    int selectedWorkMode = 0;
    int selectedInputFromFile = 0;
    int selectedOutputToFile = 0;

    char encryptionKey;
    std::string originalText;
    std::string encryptedText;

    std::cout << "Hello, the encryption program using monoalphabetic substitution welcomes you." << std::endl
              << "Select the program operation mode: " << std::endl
              << "1) Encryption " << std::endl
              << "2) Decryption" << std::endl
              << "Enter your choice here: ";
    std::cin >> selectedWorkMode;

    if (selectedWorkMode == 1) {
        std::cout << "Select the source of the original text to be encrypted: " << std::endl
                  << "1) Input from console " << std::endl
                  << "2) Input from file " << std::endl
                  << "Enter your choice here: ";
        std::cin >> selectedInputFromFile;

        std::cout << "Select the ciphertext output mode: " << std::endl
                  << "1) Output to the console " << std::endl
                  << "2) Output to file" << std::endl
                  << "Enter your choice here: ";
        std::cin >> selectedOutputToFile;

        if (selectedInputFromFile == 1) {
            std::cout << "Enter your text: ";
            std::cin >> originalText;
        } else if (selectedInputFromFile == 2) {
            std::string inputFileName;

            std::cout << "Enter the name or path to the file to be encrypted: ";
            std::cin >> inputFileName;

            original_file.open(inputFileName);

            if(!original_file.is_open()){
                std::cout << "Error: The program cannot access the specified file";
                return -1;
            }

            while (!original_file.eof()){
                originalText += (char) original_file.get();
            }
        } else {
            std::cout << "Error: You entered a non-existent program mode.";
            return -1;
        }

        std::cout << "Enter the encryption key: ";
        std::cin >> encryptionKey;

        for (char i : originalText) {
            encryptedText += (char)(((int)i + (int)encryptionKey) % 127);
        }

        if (selectedOutputToFile == 1) {
            std::cout << "Your encrypted string: " << encryptedText;
        } else if (selectedOutputToFile == 2){
            std::string outputFileName;

            std::cout << "Enter the name or path to the encryption result file: ";
            std::cin >> outputFileName;

            encrypted_file.open(outputFileName);

            if(!encrypted_file.is_open()){
                std::cout << "Error: The program cannot create or rewrite the specified file";
                return -1;
            }

            encrypted_file << encryptedText;
        } else {
            std::cout << "Error: You entered a non-existent program mode.";
            return -1;
        }
    } else if (selectedWorkMode == 2) {
        std::cout << "Select the source of the encrypted text to be decrypted: " << std::endl
                  << "1) Input from console " << std::endl
                  << "2) Input from file " << std::endl
                  << "Enter your choice here: ";
        std::cin >> selectedInputFromFile;

        std::cout << "Select the original text output mode: " << std::endl
                  << "1) Output to the console " << std::endl
                  << "2) Output to file" << std::endl
                  << "Enter your choice here: ";
        std::cin >> selectedOutputToFile;

        if (selectedInputFromFile == 1) {
            std::cout << "Enter encrypted text: ";
            std::cin >> encryptedText;
        } else if (selectedInputFromFile == 2) {
            std::string inputFileName;

            std::cout << "Enter the name or path to the file to be decrypted: ";
            std::cin >> inputFileName;

            original_file.open(inputFileName);

            if(!original_file.is_open()){
                std::cout << "Error: The program cannot access the specified file";
                return -1;
            }

            while (!original_file.eof()){
                encryptedText += (char) original_file.get();
            }
        } else {
            std::cout << "Error: You entered a non-existent program mode.";
            return -1;
        }

        std::cout << "Enter the decryption key: ";
        std::cin >> encryptionKey;

        for (char i : encryptedText) {
            originalText += (char)(((int)i - (int)encryptionKey) % 127);
        }

        if (selectedOutputToFile == 1) {
            std::cout << "Your decrypted string: " << originalText;
        } else if (selectedOutputToFile == 2){
            std::string outputFileName;

            std::cout << "Enter the name or path to the decryption result file: ";
            std::cin >> outputFileName;

            encrypted_file.open(outputFileName);

            if(!encrypted_file.is_open()){
                std::cout << "Error: The program cannot create or rewrite the specified file";
                return -1;
            }

            encrypted_file << originalText;
        } else {
            std::cout << "Error: You entered a non-existent program mode.";
            return -1;
        }
    } else {
        std::cout << "Error: You entered a non-existent program mode.";
        return -1;
    }




    return 0;
}
