#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector< vector<string> > input(3);
    vector< vector<int> > tracking(2);
    string strbuffer;
    //cout << "Please enter input:\n";

    //Get the first 2 lines
    for (int i = 0; i <= 1; i++)
    {
        getline(cin, strbuffer);
        input[i].push_back(strbuffer.substr(0, strbuffer.find(" ")));
        input[i].push_back(strbuffer.substr(strbuffer.find(" "), strbuffer.length()));
    }

    //Get # of command and resize vector to it
    getline(cin, strbuffer);
    input[2].push_back(strbuffer);
    input.resize(stoi(input[2][0]) + 3);

    //Get comand list
    for (int i = 3; i <= stoi(input[2][0]) + 2; i++)
    {
        getline(cin, strbuffer);
        input[i].push_back(strbuffer.substr(0, strbuffer.find(" ")));
        input[i].push_back(strbuffer.substr(strbuffer.find(" "), strbuffer.length()));
    }

    strbuffer.~basic_string();

    //Robot init pos
    tracking[0].push_back(stoi(input[1][0]));
    tracking[0].push_back(stoi(input[1][1]));

    //Get dirty cells
    if (stoi(input[0][0]) <= stoi(input[0][1]))
    {
        tracking.resize(stoi(input[0][0]) + 1);
        for (int i = 1; i <= stoi(input[0][0]); i++)
        {
            tracking[i].push_back(i);
            tracking[i].push_back(i);
        }
    }
    else if (stoi(input[0][0]) > stoi(input[0][1]))
    {
        tracking.resize(stoi(input[0][1]) + 1);
        for (int i = 1; i <= stoi(input[0][1]); i++)
        {
            tracking[i].push_back(i);
            tracking[i].push_back(i);
        }
    }

    //cout << "Robot's movement:\n";

    //Track robot
    for (int i = 3; i <= stoi(input[2][0]) + 2 && tracking.size() != 1; i++)
    {
        if (input[i][1].compare(" right") == 0)
        {
            for (int p = 1; p <= stoi(input[i][0]); p++)
            {
                tracking[0][0] = tracking[0][0] + 1;

                for (int n = 1; n <= tracking.size() - 1; n++)
                {
                    if (tracking[0][0] == tracking[n][0] && tracking[0][1] == tracking[n][1])
                    {
                        tracking.erase(tracking.begin() + n);
                    }
                }
            }
        }
        else if (input[i][1].compare(" left") == 0)
        {
            for (int p = 1; p <= stoi(input[i][0]); p++)
            {
                tracking[0][0] = tracking[0][0] - 1;

                for (int n = 1; n <= tracking.size() - 1; n++)
                {
                    if (tracking[0][0] == tracking[n][0] && tracking[0][1] == tracking[n][1])
                    {
                        tracking.erase(tracking.begin() + n);
                    }
                }
            }
        }
        else if (input[i][1].compare(" up") == 0)
        {
            for (int p = 1; p <= stoi(input[i][0]); p++)
            {
                tracking[0][1] = tracking[0][1] + 1;

                for (int n = 1; n <= tracking.size() - 1; n++)
                {
                    if (tracking[0][0] == tracking[n][0] && tracking[0][1] == tracking[n][1])
                    {
                        tracking.erase(tracking.begin() + n);
                    }
                }
            }
        }
        else if (input[i][1].compare(" down") == 0)
        {
            for (int p = 1; p <= stoi(input[i][0]); p++)
            {
                tracking[0][1] = tracking[0][1] - 1;

                for (int n = 1; n <= tracking.size() - 1; n++)
                {
                    if (tracking[0][0] == tracking[n][0] && tracking[0][1] == tracking[n][1])
                    {
                        tracking.erase(tracking.begin() + n);
                    }
                }
            }
        }

        if (tracking.size() != 1)
        {
            cout << tracking[0][0] << " " << tracking[0][1] << "\n";
        }
    }

    input.~vector();
    tracking.~vector();

    cout << "Press ENTER to continue...";
    cin.get();

    return EXIT_SUCCESS;
}