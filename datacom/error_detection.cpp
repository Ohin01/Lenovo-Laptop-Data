#include<bits/stdc++.h>
using namespace std;

int main()
{
    while (true)
    {
        cout << "Main Menu: " << endl;
        cout << "1. Encode Data" << endl;
        cout << "2. Error Detection" << endl;
        cout << "3. Exit" << endl;

        int n;
        cin >> n;

        if (n == 1)
        {
            cout << "Input you data to encode: ";

            string s;
            cin >> s;

            int one = 0;

            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == '1')
                one++;
            }

            cout << "Your encoded data is: ";

            if (one % 2 == 0)
            cout << s + "0" << endl;

            else
            cout << s + "1" << endl;

            cout << endl;
        }

        else if (n == 2)
        {
            cout << "Input your data to check for error: ";
            string s;
            cin >> s;

            int one = 0;

            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == '1')
                one++;
            }

            if (one % 2 == 0)
            cout << "Your code is Correct" << endl;

            else
            cout << "Error Detected" << endl;

            cout << endl;
        }

        else
        break;
    }

    

    return 0;
}