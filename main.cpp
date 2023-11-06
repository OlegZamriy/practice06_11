#include <iostream>
#include <ctime>
#include <Windows.h>
#include <conio.h>

using namespace std;

int main()
{
    srand(time(NULL));
    rand();
    setlocale(LC_ALL, "Rus");
    int rand_num, num;
    int arr_rand_system[4] = {}, arr_inputs_guess[4] = {};
    int arr_count, count_cow, count_ox, count, attempt_num;
    bool continue_ = true;
    char n;

    cout << "This is the game of \"Bulls and Cows\"\n";
    cout << "The program generates a random 4-digit number;\n"
        "Your task is to guess this number;\n"
        "For each correctly guessed digit in the right place, you'll get a \"cow\";\n"
        "If the digit is in the wrong place, you get a \"bull\";\n"
        "You win when you guess the entire number.\n";


    while (continue_ != false)
    {
        arr_count = 0, count_cow = 0, count_ox = 0, count = 0, attempt_num = 0;
        srand(time(NULL));
        rand();

        rand_num = (1000 + rand() % 9000);
        for (int i = 1000; i >= 1; i /= 10)
        {
            arr_rand_system[arr_count] = (rand_num / i) % 10;
            arr_count++;
        }
        while (count != 4)
        {
            count_cow = 0, count_ox = 0, count = 0;
            while (true)
            {
                cout << "\n\nEnter a 4-digit number: ";
                cin >> num;
                if (cin.fail() || num < 1000 || num > 9999)
                {
                    cin.clear();
                    cin.ignore(32767, '\n');
                    cout << "You entered an invalid number. Please try again.\n";
                }
                else break;
            }
            arr_count = 0;
            for (int i = 1000; i >= 1; i /= 10)
            {
                arr_inputs_guess[arr_count] = (num / i) % 10;
                arr_count++;
            }

            for (int i = 0; i < 4; i++) // Game logic 
            {
                for (int j = 0; j < 4; j++)
                {
                    if (arr_rand_system[i] == arr_inputs_guess[j] && i == j) // Count cows
                    {
                        count_cow++;
                        count++;
                        continue;
                    }
                    else if (arr_rand_system[i] == arr_inputs_guess[j] && i != j) // Count bulls
                        count_ox++;
                }
            }

            cout << count_cow << (count_cow == 1 ? " cow, " : (count_cow == 0 ? " cows, " : " cows, "));
            cout << count_ox << (count_ox == 1 ? " bull\n" : (count_ox == 0 ? " bulls\n" : " bulls\n"));
            attempt_num++;
        }
        auto name_attempt = (attempt_num == 1 ? " attempt." :
            (attempt_num > 1 && attempt_num < 5 ? " attempts." : " attempts."));
        cout << "\n\nCongratulations, you won. It took you " << attempt_num
            << name_attempt << "\nDo you want to continue? If yes - press Enter, if no - any other key.";
        if (!_kbhit())
        {
            n = _getch();
            if (n == 13)
                continue_ = true;
            else
                continue_ = false;
        }
    }

    return 0;
}
