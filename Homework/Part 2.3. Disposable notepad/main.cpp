#include <iostream>
#include <string>

int main() {
    int selectedWorkMode;

    std::string open_text, encrypted_text, key;

    std::cout << "Select the program operation mode: " << std::endl
              << "1) Encryption " << std::endl
              << "2) Decryption" << std::endl
              << "Enter your choice here: ";
    std::cin >> selectedWorkMode;

    switch (selectedWorkMode) {
        case 1:
            std::cout << "Please enter your open text: ";
            std::cin >> open_text;

            std::cout << open_text.size();

            for (int i = 0; i < open_text.size(); i++)
                key.push_back((char) (rand() % 255));

            for (int i = 0; i < open_text.length(); i++)
                encrypted_text.push_back(open_text[i] ^ key[i]);

            std::cout << "Your encrypted text is: " << encrypted_text << std::endl
                      << "Your encryption key is: " << key;
            break;
        case 2:
            std::cout << "Please enter your encrypted text: ";
            std::cin >> encrypted_text;

            std::cout << "Please enter your encryption key: ";
            std::cin >> key;

            for (int i = 0; i < encrypted_text.length(); i++)
                open_text.push_back(encrypted_text[i] ^ key[i]);

            std::cout << "Your decrypted text is: " << open_text;
            break;
        default:
            std::cout << "Error: You entered a non-existent program mode.";
            return -1;
    }
}





