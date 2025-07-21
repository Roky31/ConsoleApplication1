#include <iostream>
#include <string>

using namespace std;


char shiftChar(char c, int shift) {
    if (c >= 'A' && c <= 'Z') {
        
        return (c - 'A' + shift) % 26 + 'A';
    } else if (c >= 'a' && c <= 'z') {
        
        return (c - 'a' + shift) % 26 + 'a';
    } else {
        
        return c;
    }
}


string encrypt(string text, int shift) {
    string result = "";
    for (char c : text) {
        result += shiftChar(c, shift);
    }
    return result;
}


string decrypt(string text, int shift) {
    
    return encrypt(text, 26 - shift);
}

int main() {
    string message;
    int shift;

    cout << "Write massage: ";
    getline(cin, message);

    cout << "Choose one number (1-25): ";
    cin >> shift;

    string encrypted = encrypt(message, shift);
    cout << "Encrypted: " << encrypted << endl;

    string decrypted = decrypt(encrypted, shift);
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}
