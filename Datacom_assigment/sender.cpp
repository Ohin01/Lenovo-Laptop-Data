#include <bits/stdc++.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

string divisor = "10001000000100001";
const int PORT = 5051;

void toggle(string &encoded, int pos)
{
    if (pos >= 0 && pos < encoded.size())
    {
        if (encoded[pos] == '0')
            encoded[pos] = '1';

        else
            encoded[pos] = '0';
    }

    else
        cout << "Position " << pos << " out of bounds, ignored!" << endl;
}

string xor_strings(string a, string b) 
{
    string res = "";

    for (int i = 1; i < b.length(); i++) 
    {
        if (a[i] == b[i])
            res += '0';

        else
            res += '1';
    }

    return res;
}

string CRC16(string data, string divisor) 
{
    int it = divisor.length();

    string ans = data.substr(0, it);

    int n = data.length();

    string allzero(it, '0');

    while (it < n) 
    {
        if (ans[0] == '1')
            ans = xor_strings(divisor, ans) + data[it];
        else
            ans = xor_strings(allzero, ans) + data[it];
        it++;
    }

    if (ans[0] == '1')
        ans = xor_strings(divisor, ans);
    else
        ans = xor_strings(allzero, ans);

    return ans;
}

string encode_manchester(string data) 
{
    string encoded = "";

    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] == '0')
            encoded += "10";

        else
            encoded += "01";
    }
    
    return encoded;
}

void single_bit_error(string &encoded)
{
    cout << "Enter a position for single bit error: ";

    int pos; 
    cin >> pos;
    
    toggle(encoded, pos);
}

void two_isolated_error(string &encoded)
{
    cout << "Enter positions for two isolated bit error: ";

    int pos1, pos2;
    cin >> pos1 >> pos2;

    toggle(encoded, pos1);
    toggle(encoded, pos2);
}

void odd_number_error(string &encoded)
{
    int num; 
    
    while (true)
    {
        cout << "Enter number of positions for error: ";
        cin >> num;

        if (num % 2 != 1)
        {
            cout << "Please enter a odd number!" << endl;
        }

        else
        {
            break;
        }
    }

    cout << "Enter the positions for odd number of errors: ";

    for (int i = 0; i < num; i++)
    {
        int pos;
        cin >> pos;

        toggle(encoded, pos);
    }
}

void burst_error(string &encoded)
{
    cout << "Enter range [l, r]: ";

    int l; 
    cin >> l;

    int r; 
    cin >> r;

    for (int i = l; i <= r; i++)
    {
        toggle(encoded, i);
    }
}

int main() 
{
    string data;

    cout << "Input data in Binary: ";
    cin >> data;

    string codeword = data;

    for (int i = 0; i < divisor.length() - 1; i++)
    codeword += '0';
    
    string remainder = CRC16(codeword, divisor);
    
    string encoded = data + remainder;
    cout << "Original Codeword: " << encoded << endl << endl;

    cout<< "Select error test case:" << endl;
    cout << "1. Single Bit" << endl;
    cout << "2. Two Isolated" << endl;
    cout << "3. Odd" << endl;
    cout << "4. Burst" << endl;
    cout << "5. No error" << endl;

    cout << "Enter your choice: ";

    int choice; 
    cin >> choice;

    if (choice == 1)
        single_bit_error(encoded);

    else if (choice == 2)
        two_isolated_error(encoded);

    else if (choice == 3)
        odd_number_error(encoded);

    else if (choice == 4)
        burst_error(encoded);

    cout << "Error Injected Data (according to choice): " << encoded << endl;

    string manchester = encode_manchester(encoded);
    cout << "Manchester Encoded Data: " << manchester << endl;

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);

    if (connect(sock, (sockaddr *)&server_address, sizeof(server_address)) == 0) 
    {
        int sent = send(sock, manchester.c_str(), manchester.length(), 0);

        if (sent < 0)
            cout << "Sent Failed" << endl;
        else
            cout << "Sent with your chosen error injection." << endl;
    }

    else
        cout << "Connection Failed" << endl;

    close(sock);
    return 0;
}