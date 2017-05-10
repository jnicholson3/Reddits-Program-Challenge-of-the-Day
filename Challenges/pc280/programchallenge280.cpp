#include <iostream>
#include <regex>
#include <string>

using namespace std;

bool check_hand(string hand)
{
    regex gap_regex(".*101*.");
    regex gap_regex2(".*100*.");
    if(regex_match(hand, gap_regex) || regex_match(hand, gap_regex2))
        return false;
    return true;
}

int sum_left_hand(string l_hand, int total)
{
    if(l_hand[l_hand.length()-1] == '1')
    {
        total += 50;
    }
    for(int i =0; i < (int)l_hand.length()-1; i++)
    {
        if(l_hand[i] == '1')
        {
            total +=10;
        }
    }
    return total;
}

int sum_right_hand(string r_hand, int total)
{
    if(r_hand[0] == '1')
    {
        total += 5;
    }
    for(int i =1; i < (int)r_hand.length(); i++)
    {
        if(r_hand[i] == '1')
        {
            total +=1;
        }
    }
    return total;
}

int main()
{
    //string values = "0111011100"; //-> 37
    //string values = "1010010000"; //-> Invalid
    //string values = "0011101110"; //-> 73
    string values = "0000110000"; //-> 55
    //string values = "1111110001"; //-> Invalid
    string l_hand ="";
    string r_hand="";
    int len = values.length()-1;
    int length = (len/2);
    int total = 0;


    for(int i= 0; i<=length; i++)
    {
        l_hand += values[i];
        r_hand += values[len-i];
    }

    if(!check_hand(l_hand) || !check_hand(r_hand))
    {
        cout << "Invalid input." << endl;
        return 1;
    }
    std::reverse(r_hand.begin(), r_hand.end());
    total = sum_left_hand(l_hand, total);
    total = sum_right_hand(r_hand, total);
    cout << total << endl;

    return 0;
}
