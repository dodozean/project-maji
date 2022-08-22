#include "maji.h"

using namespace std;

vector<string> string_divide(string input_line);
bool check_length_valid(vector<string> maj_string);

int main()
{
    string input_line;
    vector<string> maj_string;
    bool valid_flag;
    while (1)
    {
        getline(cin, input_line);
        if (input_line.compare("exit") == 0)
        {
            break;
        }
        else
        {
            maj_string = string_divide(input_line);
            valid_flag = check_length_valid(maj_string);
            if (valid_flag == false)
            {
                cout << "Invalid input!" << endl;
            }
            else
            {
                cout << "continue!" << endl;
            }
        }
    }
    return 0;
}

vector<string> string_divide(string input_line)
{
    istringstream sstream(input_line);
    string str;
    vector<string> maj_string;
    while (sstream >> str)
    {
        maj_string.push_back(str);
        cout << str << endl;
    }
    return maj_string;
}

bool check_length_valid(vector<string> maj_string)
{
    if (maj_string.size() == 14)
    {
        return true;
    }
    else
    {
        return false;
    }
}