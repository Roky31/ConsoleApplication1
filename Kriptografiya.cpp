#include <iostream>
#include <string>

using namespace std;

// Harfi kaydiran fonksiyon
char shiftChar(char c, int shift) {
    if (c >= 'A' && c <= 'Z') {
        // Büyük harf ise
        return (c - 'A' + shift) % 26 + 'A';
    } else if (c >= 'a' && c <= 'z') {
        // Küçük harf ise
        return (c - 'a' + shift) % 26 + 'a';
    } else {
        // Harf degilse degistirme
        return c;
    }
}

// Mesaji sifreleyen fonksiyon
string encrypt(string text, int shift) {
    string result = "";
    for (char c : text) {
        result += shiftChar(c, shift);
    }
    return result;
}

// Mesaji çözen fonksiyon
string decrypt(string text, int shift) {
    // Sifreyi çözerken kaydirmayi ters yapiyoruz
    return encrypt(text, 26 - shift);
}

int main() {
    string message;
    int shift;

    cout << "Bir mesaj gir: ";
    getline(cin, message);

    cout << "Kaydirma miktarini gir (1-25): ";
    cin >> shift;

    string encrypted = encrypt(message, shift);
    cout << "Sifrelenmis mesaj: " << encrypted << endl;

    string decrypted = decrypt(encrypted, shift);
    cout << "Cozulmus mesaj: " << decrypted << endl;

    return 0;
}
