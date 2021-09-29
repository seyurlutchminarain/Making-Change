#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <sstream>

using namespace std;

vector<int> tokenize(string s, string del = " ")
{
    vector<int> coins;
    int num;

    int start = 0;
    int end = s.find(del);
    while (end != -1)
    {
        string temp = s.substr(start, end - start);
        stringstream ss;
        ss << temp;
        ss >> num;
        coins.push_back(num);

        start = end + del.size();
        end = s.find(del, start);
    }

    string last = s.substr(start, end - start);
    stringstream ss;
    ss << last;
    ss >> num;
    coins.push_back(num);
    coins.erase(coins.begin());

    return coins;
}

vector<int> greedy(vector<int> coins, int test)
{
  int largest = coins[0];
  vector<int> sol_set;

  while (test > 0){
  for (int i = 0; i < coins.size(); i++)
  {
      if (coins[i] >= largest && coins[i] <= test)
      {
          largest = coins[i];
      }
  }
 //cout << "Largest is:" << largest << endl;
  sol_set.push_back(largest);
  test = test - largest;
  //cout <<"Updated: "<< test << endl;
  largest = coins[0];
  //cout << "Largest:" << largest << endl;

  }

    return sol_set; 
}

int main()
{
string coins, tests;
   getline(cin, coins);
   getline(cin, tests);

    // coins = "7 1 2 5 10 20 50 100";
    // tests = "3 21 83 60";

    vector<int> coin_set = tokenize(coins);
    vector<int> test_cases = tokenize(tests);

    for (int test : test_cases)
    {
        vector<int> solutions = greedy(coin_set, test);
        cout << solutions.size() << endl;
        solutions.clear();
    }
 


    
}
