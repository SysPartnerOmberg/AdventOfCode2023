#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long calculate_one(long long time, long long record)
{
    long long number_of_better_races{0};
    for (long long current_time = 1; current_time < time; ++current_time)
    {
        long long race_time = current_time * (time - current_time);
        if (race_time > record) number_of_better_races++;
        //cout << "Calculating iteration: " << current_time << endl;
    }
    return number_of_better_races;
}

int main()
{
    string redundant{};
    // vector<long long> times{};
    // vector<long long> records{};
    // cin >> redundant;
    // for (long long i = 0; i < 4; ++i)
    // {
    //     long long time;
    //     cin >> time;
    //     times.push_back(time);
    // }
    // cin >> redundant;
    // for (long long i = 0; i < 4; ++i)
    // {
    //     long long distance;
    //     cin >> distance;
    //     records.push_back(distance);
    // }
    long long total_answer = 1;
    for (long long i = 0; i < 1; ++i)
    {
        total_answer *= calculate_one(53916768, 250133010811025);
    }
    cout << total_answer << endl;
    return 0;
}