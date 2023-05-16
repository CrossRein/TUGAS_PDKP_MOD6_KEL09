#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Calculator {
private:
    vector<int> number;

protected:
    void setNumber(vector<int> input) {
        number = input;
    }

    vector<int> getNumber() {
        return number;
    }

    void clear() {
        number.clear();
    }

public:
    virtual void open() = 0;
};


class ScientificCalculator : public Calculator {
private:
    double squareRoot() {
        double inputnum = getNumber()[0];
        return sqrt(inputnum);
    }

    void exponentiation() {
        cout << "Enter base number: ";
        enterNumber();
        int baseNumber = getNumber()[0];
        cout << "Enter power number: ";
        enterNumber();
        int power = getNumber()[0];
        cout << baseNumber << "^" << power << " Output = " << pow(baseNumber, power) << "\n\n";
    }

    int factorial() {
        int inputnum = getNumber()[0];
        int result = 1;
        for (int i = 1; i <= inputnum; i++) {
            result *= i;
        }
        return result;
    }

    void enterNumber() {
        vector<int> list;
        bool cancel = false;
        cout << "Enter number, type C to cancel: ";
        string number;
        cin >> number;
        if (number == "c" || number == "C") {
            cancel = true;
        } else {
            list.push_back(stoi(number));
        }
        setNumber(list);
        if (cancel) {
            open();
        }
    }

public:
    void open() {
        bool goback = false;
        cout << "Scientific Calculator\n";
        cout << "1. Square Root\n2. Exponentiate\n3. Factorial\n4. Exit\n";
        do {
            cout << "Select operation: ";
            string option;
            cin >> option;
            if (option == "1") {
                enterNumber();
                cout << "√" << getNumber()[0] << " = " << squareRoot() << "\n\n";
                open();
            } else if (option == "2") {
                exponentiation();
                open();
            } else if (option == "3") {
                enterNumber();
                cout << getNumber()[0] << "! = " << factorial() << "\n\n";
                open();
            } else if (option == "4") {
                goback = true;
            } else {
                cout << "Invalid input\n";
                continue;
            }
            break;
        } while (true);

        if (goback) {
            return;
        }
    }
};

class BasicCalculator : public Calculator {
private:
    int add() {
        int sum = 0;
        vector<int> arraynum = getNumber();
        for (int j : arraynum) {
            sum += j;
        }
        return sum;
    }

    int subtract() {
        vector<int> arraynum = getNumber();
        int result = arraynum[0];
        for (int i = 1; i < arraynum.size(); i++) {
            result -= arraynum[i];
        }
        return result;
    }

    int multiply() {
        vector<int> arraynum = getNumber();
        int result = arraynum[0];
        for (int i = 1; i < arraynum.size(); i++) {
            result *= arraynum[i];
        }
        return result;
    }

    double divide() {
        vector<int> arraynum = getNumber();
        double result = arraynum[0];
        for (int i = 1; i < arraynum.size(); i++) {
            result /= arraynum[i];
        }
        return result;
    }

    void enterNumber() {
        vector<int> list;
        bool cancel = false;
        for (int i = 0; i < 10; i++) {
            cout << "Enter number, type F to Finish, type C to cancel: ";
            string number;
            cin >> number;
            if (number == "f" || number == "F") {
                break;
            } else if (number == "c" || number == "C") {
                cancel = true;
                break;
            } else {
                list.push_back(stoi(number));
            }
        }
        setNumber(list);
        if (cancel) {
            open();
        }
    }

    void output(string op, double result) {
        vector<int> arraynum = getNumber();
        for (int i = 0; i < arraynum.size(); i++) {
            if (i == arraynum.size() - 1) {
                cout << arraynum[i];
                break;
            }
            cout << arraynum[i] << " " << op << " ";
        }
        cout << " = " << result << "\n\n";
        open();
    }

public:
    void open() {
        bool goback = false;
        cout << "Basic Calculator\n";
        cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Scientific Calculator\n6. Exit\n";
        ScientificCalculator scimodule;
        do {
            cout << "Select operation: ";
            string option;
            cin >> option;
            if (option == "1") {
                enterNumber();
                output("+", add());
                clear();
            } else if (option == "2") {
                enterNumber();
                output("-", subtract());
                clear();
            } else if (option == "3") {
                enterNumber();
                output("*", multiply());
                clear();
            } else if (option == "4") {
                enterNumber();
                output("/", divide());
                clear();
            } else if (option == "5") {
                clear();
                scimodule.open();
            } else if (option == "6") {
                goback = true;
            } else {
                cout << "Invalid input\n";
                continue;
            }
            break;
        } while (true);

        if (goback) {
            return;
        }
    }
};

class MirrorScientificCalculator : public Calculator {
private:
    double squareRoot() {
        double inputnum = getNumber()[0];
        return sqrt(inputnum);
    }

    void exponentiation() {
        cout << "Enter base number: ";
        enterNumber();
        int baseNumber = getNumber()[0];
        cout << "Enter power number: ";
        enterNumber();
        int power = getNumber()[0];
        cout << baseNumber << "^" << power << " Output = " << pow(baseNumber, power) << "\n\n";
    }

    int factorial() {
        int inputnum = getNumber()[0];
        int result = 1;
        for (int i = 1; i <= inputnum; i++) {
            result *= i;
        }
        return result;
    }

    void enterNumber() {
        vector<int> list;
        bool cancel = false;
        cout << "Enter number, type C to cancel: ";
        string number;
        cin >> number;
        if (number == "c" || number == "C") {
            cancel = true;
        } else {
            list.push_back(stoi(number));
        }
        setNumber(list);
        if (cancel) {
            open();
        }
    }

public:
    void open() {
        bool goback = false;
        cout << "Scientific Calculator\n";
        cout << "1. Square Root\n2. Exponentiate\n3. Factorial\n4. Basic Calculator\n5. Exit\n";
        BasicCalculator basicmodule;

        do {
            cout << "Select operation: ";
            string option;
            cin >> option;
            if (option == "1") {
                enterNumber();
                cout << "√" << getNumber()[0] << " = " << squareRoot() << "\n\n";
                open();
            } else if (option == "2") {
                exponentiation();
                open();
            } else if (option == "3") {
                enterNumber();
                cout << getNumber()[0] << "! = " << factorial() << "\n\n";
                open();
            } else if (option == "4") {
                clear();
                basicmodule.open();
            } else if (option == "5") {
                goback = true;
            } else {
                cout << "Invalid input\n";
                continue;
            }
            break;
        } while (true);

        if (goback) {
            return;
        }
    }
};

void start() {
    cout << "Calculator available:\n";
    cout << "1. Basic Calculator\n";
    cout << "2. Scientific Calculator\n";
    cout << "3. Exit\n";

    string option;
    cout << "Select calculator: ";
    cin >> option;
    cin.ignore();

    BasicCalculator basicmodule;
    MirrorScientificCalculator scimodule;

    if (option == "1") {
        basicmodule.open();
    } else if (option == "2") {
        scimodule.open();
    } else if (option == "3") {
        return;
    } else {
        cout << "Invalid input\n";
        start();
    }
}

int main() {
    start();
    cout << "Exit successfully, Thank you for using this app.\n";
    return 0;
}
