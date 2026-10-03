#include <iostream>
#include <cstdlib>
#include "Complex.h"

using namespace std;

Complex makeComplex(double real, double imag)
{
    Complex c;

    if (!c.Init(real, imag))
    {
        cout << "Wrong arguments!" << endl;
        exit(1);
    }

    return c;
}

void showMenu()
{
    cout << endl;
    cout << "===== MENU =====" << endl;
    cout << "1. Enter first complex number" << endl;
    cout << "2. Enter second complex number" << endl;
    cout << "3. Display first number" << endl;
    cout << "4. Display second number" << endl;
    cout << "5. Get real part of first number" << endl;
    cout << "6. Get imaginary part of first number" << endl;
    cout << "7. Set real part of first number" << endl;
    cout << "8. Set imaginary part of first number" << endl;
    cout << "9. Add numbers" << endl;
    cout << "10. Subtract numbers" << endl;
    cout << "11. Multiply numbers" << endl;
    cout << "12. Show first number as string" << endl;
    cout << "13. Show second number as string" << endl;
    cout << "14. Show array of complex numbers" << endl;
    cout << "0. Exit" << endl;
    cout << "Choose: ";
}

int main()
{
    // Створення об'єкта звичайним способом
    Complex c1;

    // Створення другого об'єкта за допомогою Init()
    Complex c2;
    c2.Init(2, 3);

    // Створення об'єкта за допомогою зовнішньої функції
    Complex c3 = makeComplex(4, -5);

    // Масив об'єктів
    Complex arr[3];

    arr[0].Init(1, 2);
    arr[1].Init(3, -4);
    arr[2].Init(-5, 6);

    int choice;

    do
    {
        showMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            c1.Read();
            break;

        case 2:
            c2.Read();
            break;

        case 3:
            cout << "First number: ";
            c1.Display();
            break;

        case 4:
            cout << "Second number: ";
            c2.Display();
            break;

        case 5:
            cout << "Real part = "
                << c1.getReal() << endl;
            break;

        case 6:
            cout << "Imaginary part = "
                << c1.getImag() << endl;
            break;

        case 7:
        {
            double value;

            cout << "Enter new real part: ";
            cin >> value;

            if (c1.setReal(value))
                cout << "Value changed successfully." << endl;
            else
                cout << "Wrong value!" << endl;

            break;
        }

        case 8:
        {
            double value;

            cout << "Enter new imaginary part: ";
            cin >> value;

            if (c1.setImag(value))
                cout << "Value changed successfully." << endl;
            else
                cout << "Wrong value!" << endl;

            break;
        }

        case 9:
        {
            Complex result = c1.add(c2);

            cout << "Addition: ";
            result.Display();

            break;
        }

        case 10:
        {
            Complex result = c1.subtract(c2);

            cout << "Subtraction: ";
            result.Display();

            break;
        }

        case 11:
        {
            Complex result = c1.multiply(c2);

            cout << "Multiplication: ";
            result.Display();

            break;
        }

        case 12:
            cout << "First number as string: "
                << c1.toString() << endl;
            break;

        case 13:
            cout << "Second number as string: "
                << c2.toString() << endl;
            break;

        case 14:
            cout << "Array of complex numbers:" << endl;

            for (int i = 0; i < 3; i++)
            {
                cout << i + 1 << ": ";
                arr[i].Display();
            }

            break;

        case 0:
            cout << "Program finished." << endl;
            break;

        default:
            cout << "Wrong menu choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}