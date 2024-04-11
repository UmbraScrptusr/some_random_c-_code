#include <iostream>
#include <chrono>
#include <unistd.h>
using namespace std;
long silnia(int x)
{
    long wynik = 1;
    while(x > 1)
    {
        wynik *= x;
        x--;
    }
    return wynik;
}

long silniaRek(int x)
{
    if (x <= 1)
    {
        return 1;
    }
    else
    {
        return x * silniaRek(x - 1);
    }
}

int main()
{
    const int LICZBA = 5;
    auto start = chrono::steady_clock::now();
    cout << silnia(LICZBA) << endl;
    auto end = chrono::steady_clock::now();
    cout << "Czas" << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl  << endl;

    start = chrono::steady_clock::now();
    cout << silniaRek(LICZBA) << endl;
    end = chrono::steady_clock::now();
    cout << "Czas" << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl  << endl;
    return 0;
}
