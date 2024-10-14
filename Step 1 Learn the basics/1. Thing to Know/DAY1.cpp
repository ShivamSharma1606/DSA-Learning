#include <iostream>
#include <bits/stdc++.h> // it include all  the library of the c++
using namespace std;
// endl and \n are used to come in next line

void IntOut();
void DataType();
void IfCondition();
void SwitchCase();
void String();
void ForLoop();
void WhileLoop();

int main()
{
    // USER INPUT AND OUTPUT
    if (false)
    {
        IntOut();
    }
    if (false)
    {
        DataType();
    }
    if (false)
    {
        IfCondition();
    }
    if (false)
    {
        SwitchCase();
    }
    if (false)
    {
        String();
    }
    if (false)
    {
        ForLoop();
    }
    if (true)
    {
        WhileLoop();
    }

    //array are alway send by call by reference not by call by value
    return 0;
}

void IntOut()
{
    // USER INPUT AND OUTPUT
    cout << "my name is shivam "
         << "sharma" << endl;
    // std::cout<<" My name is shivam"<<" sharma"<<std::endl;
    int x, y;
    std::cin >> x >> y;
    std::cout << x;
}

void DataType()
{

    // int , long, long long are used for integers

    // float and double are used for decimal values

    // string and getline

    string z;
    cout << "enter the paragraph";
    cin >> z;
    // Input : my name is shviam
    // Output: my
    // this is because string only print the values before first space
    cout << z;
    // getline to overcome this string
    string x;
    cout << "enter the paragraph";
    getline(cin, x);
    cout << x;

    // char // single alphabhet with single quotation
}

void IfCondition()
{

    int age;
    if (age > 18)
    {
        cout << "you are adult";
    }
    else
    {
        cout << "you are not adult";
    }
}

void SwitchCase()
{
    int ch, r, l, b;
    cin >> r >> l >> b;
    cin >> ch;

    switch (ch)
    {
    case 1:
        cout << 3.14159265359 * r * r;
        break;
    case 2:
        cout << l * b;
        break;
    default:
        cout << "WrongValue";
    }
}

void String()
{
    string z = "shivam";
    int len = z.size();

    z[len - 1] = 'k';
    cout << z;
}

void ForLoop()
{
    int n1, n2;
    n1 = 1;
    n2 = 1;
    int result = 0;
    int n;
    cin >> n;

    if (n == 0)
    {
        result = 0;
    }
    else if (n == 1)
    {
        result = 1;
    }
    else
    {
        for (int i = 0; i < n - 2; i++)
        {
            result = n1 + n2;
            n1 = n2;
            n2 = result;
        }
    }

    cout << result;
}

void WhileLoop()
{

    int n, z;
    int resultE = 0;
    int resultO = 0;
    cin >> n;

    while (n != 0)
    {
        z = n % 10;
        if (z % 2 == 0)
        {
            resultE = resultE + z;
        }
        else
        {
            resultO = resultO + z;
        }

        n = n / 10;
    }
    cout << resultE << " " << resultO;
}


