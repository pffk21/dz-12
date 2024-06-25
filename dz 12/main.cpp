#include <iostream>
#include <time.h>
#include <string>

using namespace std;

class Printer {
    string* statistics;
    string* ocheredpechati;
    int maxsize;
    int length;
    int razmerstitistici;
public:
    Printer(int m) : maxsize(m), length(0), razmerstitistici(0)
    {
        ocheredpechati = new string[maxsize];
        statistics = new string[maxsize];
    }
    void Pop()
    {
        if (length > 0)
        {
            string client = ocheredpechati[0];
            for (int i = 1; i < length; i++)
            {
                ocheredpechati[i - 1] = ocheredpechati[i];
            }
            length--;
            char date[50] = {};
            time_t unixTime = time(nullptr);
            ctime_s(date, sizeof(date), &unixTime);
            cout << client << " \nпечатает сейчас\n" << endl;

        }
    }
    void Add(string clientname)
    {
        if (length < maxsize) {
            ocheredpechati[length++] = clientname;
            cout << "пользователя " << clientname << " добавили в очередь " << endl;
        }

    }
    void Printstatistics()
    {
        cout << "\ncтатистика печати:\n";
        for (int i = 0; i < razmerstitistici; i++)
        {
            cout << statistics[i] << endl;
        }
    }
    void PrintOchered()
    {
        cout << " \nочередь печати:\n";
        for (int i = 0; i < length; i++)
        {
            cout << ocheredpechati[i] << " ";
        }
    }


};
int main()
{

    Printer printer(3);
    printer.Add("Пользователь 1");
    printer.Add("Пользователь 2");
    printer.Add("Пользователь 3");

    printer.PrintOchered();

    printer.Pop();
    printer.Pop();

    printer.PrintOchered();

    printer.Printstatistics();

}