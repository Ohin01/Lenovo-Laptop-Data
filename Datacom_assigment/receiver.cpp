#include <bits/stdc++.h>
#include <sys/socket.h>
#include <netinet/in.h>

using namespace std;

string divisor = "10001000000100001";
const int PORT = 5051;

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

string decode_manchester(string encoded) 
{
    string decoded = "";

    if (encoded.length() % 2 != 0) 
    {
        cout << "Manchester-encoded data has Error." << endl;
        return "";
    }

    for (int i = 0; i < encoded.length(); i += 2) 
    {
        if (encoded[i] == '0' && encoded[i + 1] == '1') 
            decoded += "1";

        else if (encoded[i] == '1' && encoded[i + 1] == '0')
            decoded += "0";

        else
        {
            cout << "Manchester-encoded data has Error." << endl;
            return "";
        }   
    }

    return decoded;
}

int main() 
{
    int server_fd, new_socket;
    sockaddr_in address;
    int opt = 1;
    socklen_t len = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (sockaddr *)&address, sizeof(address));
    listen(server_fd, 1);

    cout << "Waiting for data..." << endl;
    new_socket = accept(server_fd, (sockaddr *)&address, &len);

    char buffer[1005];
    int bytes_read = read(new_socket, buffer, 1004);

    if (bytes_read <= 0)
    {
        cout << "Read failed!" << endl;
        return 0;
    }

    buffer[bytes_read] = '\0';
    
    string received_manchester(buffer);
    string decoded_bits = decode_manchester(received_manchester);

    if (decoded_bits.empty())
    {
        close(new_socket);
        close(server_fd);
        return 0;
    }

    string remainder = CRC16(decoded_bits, divisor);

    bool error_found = false;

    cout << "Decoded Bits: " << decoded_bits << endl;
    cout << "Remainder:    " << remainder << endl;

    for (int i = 0; i < remainder.size(); i++)
    {
        if (remainder[i] == '1')
        {
            error_found = true;
            break;
        }
    }

    if (!error_found) 
    cout << "NO ERROR DETECTED." << endl;
    else 
    cout << "ERROR DETECTED!" << endl;

    close(new_socket);
    close(server_fd);
    return 0;
}