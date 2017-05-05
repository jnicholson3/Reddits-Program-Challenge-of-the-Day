#include <iostream>
#include <cstring>

using namespace std;

bool scrabble(char &pieces, char &word, int length)
{
    char *ptr_pieces = &pieces;
    char *ptr_word = &word;
    char w_word[length+1]={0};
    int question = 0;
    int j = 0;


    for(int i = 0; *(ptr_word+i); i++)
    {
        while(*(ptr_word+i) != *(ptr_pieces+j))
        {
            if(!*(ptr_pieces+j))
                break;

            j++;

        }
        w_word[i] = *(ptr_pieces+j);
        cout << *(ptr_pieces+j) << endl;
        cout << "this is w " << w_word << endl;
        cout << "this is word " << &word << endl;
        *(ptr_pieces+j) = '~';
        if(strcmp(&word, w_word)==0)
        {
            return true;
        }
        j = 0;
    }
    return false;
}

int main()
{
    char random_pieces[] = "orppgma";
    char wanted_word[] = "program";
    int len = sizeof(wanted_word)/sizeof(wanted_word[0]);
    bool result = scrabble(random_pieces[0], wanted_word[0], len-1);

    if(result)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}
