#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function to preprocess the string (remove spaces, punctuation, and convert to lowercase)
string preprocess(const string &t)
{
    string cleanStr;
    for (char ch : t)
    {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        {
            cleanStr += tolower(ch);
        }
    }
    return cleanStr;
}

// Recursive function to check if a string is a palindrome
bool isPalindrome(const string &t, int left, int right)
{
    if (left >= right)
    {
        return true;
    }
    if (t[left] != t[right])
    {
        return false;
    }
    return isPalindrome(t, left + 1, right - 1);
}

int main()
{
    string input;

    cout << "Enter a phrase to check if it's a palindrome (or type 'exit' to quit):\n";

    while (true)
    {
        getline(cin, input);

        if (input == "exit")
        {
            break;
        }

        string processed = preprocess(input);
        bool result = isPalindrome(processed, 0, processed.size() - 1);

        if (result)
        {
            cout << "\"" << input << "\" is a palindrome.\n";
        }
        else
        {
            cout << "\"" << input << "\" is not a palindrome.\n";
        }

        cout << "Enter another phrase (or type 'exit' to quit):\n";
    }

    return 0;
}
