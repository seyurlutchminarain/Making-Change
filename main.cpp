#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <sstream>

using namespace std;

vector<int> tokenize(string s, string del = " ") // Function created to split a string using the spaces as a delimiter
{                                                // needed to organise the input into an array.
    vector<int> coins;
    int num;

    int start = 0;
    int end = s.find(del); // finding the next space in the string
    while (end != -1) 
    {
        string temp = s.substr(start, end - start);
        stringstream ss; // used to parse string as an int
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
    coins.push_back(num); // adding the number to the vector
    coins.erase(coins.begin()); // removing the first integer which is the size of the vector [not required since we can use .size()]

    return coins; // returning the vector of inputs
}

vector<int> greedy(vector<int> coins, int test) // greedy algorithm implementation
{
  int largest = coins[0]; // setting the largest value to the first coin
  vector<int> sol_set; // initialising the solution vector

  while (test > 0){ // while we still need to find change
  for (int i = 0; i < coins.size(); i++) // loop through the list of coin denominations
  {
      if (coins[i] >= largest && coins[i] <= test) // finding the largest possible coin thats smaller than the amount we need to make
      {
          largest = coins[i]; // setting that to be the largest coin
      }
  }
 //cout << "Largest is:" << largest << endl;
  sol_set.push_back(largest); // pushing the largest coin to our solution set
  test = test - largest; // updating the value of the current amount of change we need to make
  //cout <<"Updated: "<< test << endl;
  largest = coins[0]; // re-initialising the largest coin to be the first coin
  //cout << "Largest:" << largest << endl;

  }

    return sol_set; // return the set of coins needed
}

int main()
{
string coins, tests;
   getline(cin, coins); // getting the coin set
   getline(cin, tests); // test cases

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
