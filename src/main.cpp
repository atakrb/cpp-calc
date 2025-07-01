#include <iostream>
#include <cstdlib>
#include <cctype>
using namespace std;

bool isNumber(const string& s) {
    bool dotFound = false;
    for (char ch : s) {
        if (!isdigit(ch) && ch != '.') return false;
        if (ch == '.') {
            if (dotFound) return false;
            dotFound = true;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cout << "Kullanim: " << argv[0] << " <sayi1> <+ - * /> <sayi2>\n";
        return 1;
    }

    string sa = argv[1];
    string sb = argv[3];
    char op = argv[2][0];

    if (!isNumber(sa) || !isNumber(sb)) {
        cout << "Hata: Girdiler sayi olmali!\n";
        return 2;
    }

    double a = atof(argv[1]);
    double b = atof(argv[3]);
    double result = 0.0;
    bool valid = true;

    switch (op) {
        case '+': result = a + b; break;
        case '-': result = a - b; break;
        case '*': result = a * b; break;
        case '/':
            if (b == 0) {
                cout << "Hata: 0'a bolme!\n";
                return 3;
            }
            result = a / b; break;
        default:
            valid = false;
    }

    if (!valid) {
        cout << "Hata: Gecersiz operator '" << op << "'\n";
        return 4;
    }

    cout << "Sonuc: " << result << endl;
    return 0;
}
