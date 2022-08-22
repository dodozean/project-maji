#include "maji.h"

using namespace std;

vector<string> string_divide(string input_line);
bool check_length_valid(vector<string> maj_string);
vector<Tile> tile_judge(vector<string> maj_string, bool *valid_flag);
Tile tile_judge_num(string str, bool *valid_flag);
Tile tile_judge_word(string str, bool *valid_flag);

int main()
{
    string input_line;
    vector<string> maj_string;
    vector<Tile> tiles;
    bool valid_flag;
    bool *flag = 0;
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
            flag = &valid_flag;
            tiles = tile_judge(maj_string, flag);
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
        //cout << str << endl;
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

vector<Tile> tile_judge(vector<string> maj_string, bool *valid_flag)
{
    vector<string>::iterator iter;
    vector<Tile> tiles;
    if (*valid_flag == true)
    {

        for (iter = maj_string.begin(); iter != maj_string.end(); iter++)
        {
            if (iter->at(0) <= 57 && iter->at(0) >= 49)
            {
                if (iter->length() != 2)
                {
                    *valid_flag = false;
                    break;
                }
                else
                {
                    tiles.push_back(tile_judge_num(*iter, valid_flag));
                }
            }
            else
            {
                tiles.push_back(tile_judge_word(*iter, valid_flag));
            }
        }
    }
    return tiles;
}

Tile tile_judge_num(string str, bool *valid_flag)
{
    Tile tile;
    tile.value = str.at(0) - 48;
    if (str.at(1) == 83 || str.at(1) == 115)
    {
        tile.type = S;
    }
    else if (str.at(1) == 77 || str.at(1) == 109)
    {
        tile.type = M;
    }
    else if (str.at(1) == 80 || str.at(1) == 112)
    {
        tile.type = P;
    }
    else
    {
        tile.type = Error;
        *valid_flag = false;
        return tile;
    }
    //cout << tile.value << tile.type << endl;
    return tile;
}

Tile tile_judge_word(string str, bool *valid_flag)
{
    Tile tile;
    tile.value = 0;
    if (str.compare("East") == 0)
    {
        tile.type = East;
    }
    else if (str.compare("West") == 0)
    {
        tile.type = West;
    }
    else if (str.compare("South") == 0)
    {
        tile.type = South;
    }
    else if (str.compare("North") == 0)
    {
        tile.type = North;
    }
    else if (str.compare("ZH") == 0)
    {
        tile.type = ZH;
    }
    else if (str.compare("FA") == 0)
    {
        tile.type = FA;
    }
    else if (str.compare("BA") == 0)
    {
        tile.type = BA;
    }
    else
    {
        tile.type = Error;
        *valid_flag = false;
        return tile;
    }
    //cout << tile.value << tile.type << endl;
    return tile;
}