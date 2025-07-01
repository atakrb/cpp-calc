#include <iostream>
#undef UNICODE

#include <cstdlib>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cout << "Kullanim: " << argv[0] << " <sayi1> <+ - * /> <sayi2>\n";
        return 1;
    }

    double a = atof(argv[1]);
    char   op = argv[2][0];
    double b = atof(argv[3]);

    double result = 0.0;
    bool   valid  = true;

    switch (op) {
        case '+': result = a + b; break;
        case '-': result = a - b; break;
        case '*': result = a * b; break;
        case '/':
            if (b == 0) { cout << "Hata: 0'a bolme!\n"; return 2; }
            result = a / b; break;
        default:  valid = false;
    }

    if (!valid) {
        cout << "Hata: Gecersiz operator '" << op << "'\n";
        return 3;
    }

    cout << "Sonuc: " << result << endl;
    return 0;
}
