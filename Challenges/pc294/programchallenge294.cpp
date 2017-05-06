#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void print_result(bool result)
{
    if(result)
    {
        cout << "true" << endl;;
    }
    else
    {
        cout << "false" << endl;;
    }
}

bool scrabble(string pieces, string word)
{
    string tmp = "";
    string tmp_word = word;
    int w_length = word.length();
    int r_length = pieces.length();
    int count_question =0;
    int tmp_w = 0;

    for(int i =0; i < w_length; i++)
    {
        for(int j=0; j < r_length; j++)
        {

           if(word[i]==pieces[j])
           {
               tmp += pieces[j];
               pieces.erase(j,1);
               tmp_word.erase(tmp_w,1);
               if(tmp.compare(word)==0)
               {
                   return true;
               }
            break;
           }
        }
    }
    for(int i = 0; i < (int)pieces.length(); i++)
    {
        if(pieces[i] == '?')
        {
            count_question++;
        }
    }
    if(count_question == (int)tmp_word.length())
    {
        return true;
    }
    return false;
}

string longest(string rack)
{
    string words[200000];
    string line = "";
    string w_largest = "";
    int count =0;
    int largest = 0;
    bool result;

    ifstream myfile("C:\\Users\\Jeremy\\Desktop\\enable1.txt");
    if(myfile.is_open())
    {
        while(getline(myfile, line))
        {
            words[count++]=line;
        }
        myfile.close();
    }

    for(int i = 0; i < count; i++)
    {
        result = scrabble(rack, words[i]);
        if(result)
        {
            if(largest < (int)words[i].length())
            {
                largest = words[i].length();
                w_largest = words[i];
            }
        }
    }
    return w_largest;
}


int main()
{
    string w_largest = "";
    bool result;
    w_largest = longest("vaakojeaietg????????");
    cout << "The largest word is "  << w_largest << " at " << w_largest.length() << endl;

    result = scrabble("pizza??", "pizzazz");
    print_result(result);
    /*
    result = scrabble("piizza?", "pizzazz");
    print_result(result);
    result = scrabble("orrpgma", "program");
    print_result(result);
    result = scrabble("orppgma", "program");
    print_result(result);*/

    return 0;
}
