#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int pr;
    char ch;
    Node *left;
    Node *right;

    Node(char val, int freq) 
    {
        pr = freq;
        ch = val;
        left = NULL;
        right = NULL;
    }
    
    Node(char value, int priority, Node *l, Node *r)
    {
        pr = priority;
        ch = value;
        left = l;
        right = r;
    }
};


struct Pr_queue{
    vector<Node*> arr;
    int sz;

    Pr_queue(int n) 
    {
        arr.resize(n + 1); 
        sz = 0;
    }

    void heapify(int node) 
    {
        int left = node * 2;
        int right = node * 2 + 1;
        int smaller = node;

        if (left <= sz && (arr[left]->pr < arr[smaller]->pr))
            smaller = left;
        if (right <= sz && (arr[right]->pr < arr[smaller]->pr))
            smaller = right;

        if (smaller != node) 
        {
            swap(arr[node], arr[smaller]);
            heapify(smaller);
        }
    }

    void insert(Node *val)
    {
        sz++;
        arr[sz] = val;
        int cur = sz;

        while (cur > 1 && (arr[cur]->pr < arr[cur / 2]->pr)) 
        {
            swap(arr[cur], arr[cur / 2]);
            cur /= 2;
        }
    }

    Node* top() 
    {
        if (sz >= 1)
            return arr[1];
        
        return NULL;
    }

    void pop() 
    {
        if (sz < 1) return;

        swap(arr[1], arr[sz]);
        sz--;
        heapify(1);
    }

    bool empty() 
    {
        return sz == 0;
    }
};

Node* buildHuffman(string s)
{
    map<char, int> count;

    for (int i = 0; i < s.size(); i++)
    {
        count[s[i]]++;
    }

    Pr_queue pq(2 * s.size());

    for (auto prs: count)
    {
        pq.insert(new Node(prs.first, prs.second));
    }

    while (pq.sz > 1)
    {
        Node *l = pq.top();
        pq.pop();
        
        Node *r = pq.top();
        pq.pop();

        Node *temp = new Node('\0', l->pr + r->pr, l, r);

        pq.insert(temp);
    }

    Node *head = pq.top();
    pq.pop();

    return head;
}

void fillCodes(Node *head, map<char, string> &codes, string cur)
{
    if (head == NULL)
    return;

    if (head->ch != '\0')
    {
        if (cur == "")
        {
            cur = "0";
        }

        codes[head->ch] = cur;
        return;
    } 

    fillCodes(head->left, codes, cur + "0");
    fillCodes(head->right, codes, cur + "1");
}

void prepareInput()
{
    FILE *inFile = fopen("dummy.txt", "r");

    if (inFile == NULL)
    {
        cout << "Dummy file Not found" << endl;
        return;
    }

    FILE *outFile = fopen("input.txt", "w");

    if (outFile == NULL)
    {
        cout << "Error creating file" << endl;
        return;
    }

    int c;

    while ((c = fgetc(inFile)) != EOF) 
    {  
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ' || c == '\n') {
            fputc(c, outFile);
        }
    }

    fclose(inFile);
    fclose(outFile);
}

int main() 
{
    prepareInput();

    FILE *inFile = fopen("input.txt", "r");

    if (inFile == NULL)
    {
        cout << "No input file found" << endl;
        return 1;
    }

    string s;
    int c;

    while ((c = fgetc(inFile)) != EOF) 
    {  
        s += (char)c;
    }

    fclose(inFile);

    Node *head = buildHuffman(s);

    map<char, string> codes;

    fillCodes(head, codes, "");
    
    for (auto prs : codes) 
    {
        char ch = prs.first;
        string code = prs.second;

        if (ch == '\n')
        cout << "\"\\n\": " << code << endl;
        else
        cout << "\"" << ch << "\": " << code << endl;
    }


    FILE *outFile = fopen("output.txt", "w");

    if (outFile == NULL)
    {
        cout << "File cannot be opened" << endl;
        return 1;
    }

    string encoded = "";

    for (auto ch: s) encoded += codes[ch];

    for (auto ch: encoded) fputc(ch, outFile);

    fclose(outFile);

    return 0;
}
