#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_palindrome(char word[50])
{
    unsigned int is_palindrome = 1;

    for (unsigned int i = 0; i < strlen(word) / 2; i++)
    {
        char curr_f = tolower(word[i]);
        char curr_r = word[strlen(word) -1 - i];
        if (curr_f != curr_r)
        {
            is_palindrome = 0;
            break;
        }
    }
    if (is_palindrome == 0)
    {
        printf("The word %s, is not a palindrome!\n", word);
    }
    else
    {
        printf("The word %s, is a palindrome!\n", word);
    }

    return is_palindrome;
}

int main()
{
    char word[50];
    while (true)
    {
        printf("Please enter a word or quit by typing 'q': ");
        scanf("%s", &word);
        if (word[0] == 'q' && word[1] == '\0')
        {
            break;
        }
        is_palindrome(word);
    }
}

