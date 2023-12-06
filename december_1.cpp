#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int calculate(int first, int first_index, int second, int second_index, string & line)
{
    vector<string> letters_to_search_for = {"one", "two", "three", "four", "five", "six", "seven",
    "eight", "nine"};
     for (auto letter_digit : letters_to_search_for)
     {
        auto result_position = line.find(letter_digit);
        auto position = find(letters_to_search_for.begin(), letters_to_search_for.end(), letter_digit) 
                        - letters_to_search_for.begin() + 1; 
        if (result_position == string::npos) continue;
        if (result_position < first_index)
        {
            first = position;
            first_index = result_position;
        }
        result_position = line.rfind(letter_digit);
        if (result_position == string::npos) continue;
        if (result_position > second_index)
        {
            //cout << "Changing value!" << endl;
            second = position;
            second_index = result_position;
        }
        
        
     }
     //cout << first * 10 + second << endl;
     return first * 10 + second;
}

int main()
{
    string line{};
    int total_sum{};
    while (cin >> line)
    {
        int first_digit{-1};
        int second_digit{};
        int first_index = 1000;
        int second_index = 0;
        int current_index = 0;
        for (auto letter : line)
        {
            if (isdigit(letter) && first_digit == -1)
            {
                first_digit = letter - '0';
                second_digit = first_digit;
                first_index = current_index;
                second_index = current_index;
            }
            else if (isdigit(letter))
            {
                second_digit = letter - '0';
                second_index = current_index;
            }
            current_index++;
        }
        total_sum += calculate(first_digit, first_index, second_digit, second_index, line);
        //cout << first_digit * 10 + second_digit << endl;
        //total_sum +=  first_digit * 10 + second_digit;
    }
    cout << total_sum << endl;

    return 0;
}