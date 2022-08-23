#include "maji.h"

using namespace std;

bool tile_compare_function(Tile tile_1, Tile tile_2);
bool tile_compare(Tile tile_1, Tile tile_2);
vector<string> string_divide(string input_line);
bool check_length_valid(vector<string> maj_string);
vector<Tile> tile_judge(vector<string> maj_string, bool *valid_flag);
Tile tile_judge_num(string str, bool *valid_flag);
Tile tile_judge_word(string str, bool *valid_flag);
void show_tiles(vector<Tile> tiles);
bool check_win(vector<Tile> tiles);
bool check_DDH(vector<Tile> tiles);

int main()
{
    string input_line;
    vector<string> maj_string;
    vector<Tile> tiles;
    bool valid_flag;
    bool *flag = 0;
    bool if_win;
    cout << "Welcome to the maj-winning judgement system! Please input the tiles and press enter according to the rules!" << endl;
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
                //show_tiles(tiles);
                sort(tiles.begin(), tiles.end(), tile_compare_function);
                //show_tiles(tiles);
                if(check_win(tiles)==true)
                {
                    cout << "You have won the game!" << endl;
                }
                else
                {
                    cout << "You haven't won the game yet!" << endl;
                }
            }
        }
    }
    return 0;
}

bool tile_compare_function(Tile tile_1, Tile tile_2)
{
    if (tile_1.type < tile_2.type)
    {
        return true;
    }
    else if (tile_1.type > tile_2.type)
    {
        return false;
    }
    else if (tile_1.type == tile_2.type)
    {
        if (tile_1.value < tile_2.value)
        {
            return true;
        }
        else if (tile_1.value > tile_2.value)
        {
            return false;
        }
        else if (tile_1.value == tile_2.value)
        {
            return true;
        }
    }
    return true;
}

bool tile_compare(Tile tile_1, Tile tile_2)
{
    if (tile_1.value == tile_2.value && tile_1.type == tile_2.type)
    {
        return true;
    }
    else
    {
        return false;
    }
}

vector<string> string_divide(string input_line)
{
    istringstream sstream(input_line);
    string str;
    vector<string> maj_string;
    while (sstream >> str)
    {
        maj_string.push_back(str);
        // cout << str << endl;
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
    // cout << tile.value << tile.type << endl;
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
    // cout << tile.value << tile.type << endl;
    return tile;
}

void show_tiles(vector<Tile> tiles)
{
    vector<Tile>::iterator iter;
    for (iter = tiles.begin(); iter != tiles.end(); iter++)
    {
        cout << iter->value << " " << iter->type << endl;
    }
}

bool check_win(vector<Tile> tiles)
{
    if (check_DDH(tiles) == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool check_DDH(vector<Tile> tiles)
{
    vector<Tile>::iterator iter;
    for (iter = tiles.begin(); iter != tiles.end(); iter += 2)
    {
        if (tile_compare(*iter, *(iter + 1)) == false)
        {
            return false;
        }
    }
    return true;
}