#include <iostream>

int main(){
    int selectedWorkMode;
    std::string open_text, encrypted_text, buffer;

    std::cout << "Select the program operation mode: " << std::endl
              << "1) Encryption " << std::endl
              << "2) Decryption" << std::endl
              << "Enter your choice here: ";
    std::cin >> selectedWorkMode;

    switch (selectedWorkMode) {
        case 1:
            std::cout << "Please enter your open text: ";
            std::cin >> open_text;

            for (int i = 0; i < open_text.length() / 4 + 1; i++) {
                buffer.push_back(open_text[i * 4 + 2]);
                buffer.push_back(open_text[i * 4]);
                buffer.push_back(open_text[i * 4 + 3]);
                buffer.push_back(open_text[i * 4 + 1]);

                encrypted_text.append(buffer);

                buffer.clear();
            }

            std::cout << "Your encrypted text is: " << encrypted_text;
            break;
        case 2:
            std::cout << "Please enter your encrypted text: ";
            std::cin >> encrypted_text;

            for (int i = 0; i < encrypted_text.length() / 4 + 1; i++) {
                buffer.push_back(encrypted_text[i * 4 + 1]);
                buffer.push_back(encrypted_text[i * 4 + 3]);
                buffer.push_back(encrypted_text[i * 4]);
                buffer.push_back(encrypted_text[i * 4 + 2]);

                open_text.append(buffer);

                buffer.clear();
            }

            std::cout << "Your decrypted text is: " << open_text;
            break;
        default:
            std::cout << "Error: You entered a non-existent program mode.";
            return -1;
    }
}