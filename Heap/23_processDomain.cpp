// Problem Statement
/*
You are tasked to write a function processDomainOperations that processes a series of domain-related operations represented in a matrix.

The function takes an input argument, which is a list of operations, where each operation is represented as a vector of strings. Each row represents an operation and must be executed sequentially.

Each operation has at most three string elements:

1. OP (Operation Type)
2. Domain Name
3. IP Address (only applicable for "PUT" operation)

Operations:
1. PUT domain IP - Store the given domain with its corresponding IP address.
2. GET domain - Retrieve the IP address for the given domain. If it does not exist, return "404".
3. COUNT domain - Return the count of subdomains under the given domain.
*/

// Example 
/*

Input:

[
    ["PUT", "www.apple.com", "10.20.30.40"],
    ["PUT", "jobs.apple.com", "10.20.30.50"],
    ["PUT", "sites.google.com", "142.58.145.693"],
    ["GET", "sample.com"],
    ["GET", "www.apple.com"],
    ["COUNT", "apple.com"],
    ["COUNT", "com"]
]


Output:

["404", "10.20.30.40", "2", "3"]

Explanation:

1. First three instructions (PUT) store the domain-IP mappings:

"www.apple.com" → "10.20.30.40"
"jobs.apple.com" → "10.20.30.50"
"sites.google.com" → "142.58.145.693"

2. GET "sample.com" → Not found → return "404".

3. GET "www.apple.com" → Found → return "10.20.30.40".

4. COUNT "apple.com" → "www.apple.com" & "jobs.apple.com" exist under "apple.com" → return "2".

5. COUNT "com" → "apple.com", "jobs.apple.com", "sites.google.com" exist under "com" → return "3".
*/


#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


unordered_map<string, string> domainIP;
unordered_map<string, int> domainCount;


void insertIntoTries(string &domain){
    vector<string> parts;
    stringstream ss(domain);

    string token;

    while(getline(ss, token, '.')){
        cout << "token = " << token << endl;
        parts.push_back(token);
    }

    reverse(parts.begin(), parts.end());

    string curr = "";
    for(string &part: parts){
        if(!curr.empty()) curr = part + "." + curr;
        else curr = part;
        cout << "curr = " << curr << endl;
        domainCount[curr]++;
    }
}

vector<string> processDomainOperations(vector<vector<string>> &operations){
    vector<string> result;

    for(auto &ops: operations){
        if(ops[0] == "PUT"){
            string domain = ops[1], ip = ops[2];
            domainIP[domain] = ip;
            insertIntoTries(domain);
        }
        else if(ops[0] == "GET"){
            string domain = ops[1];
            result.push_back(domainIP.count(domain) ? domainIP[domain] : "404");
        }
        else if (ops[0] == "COUNT") {
            string domain = ops[1];
            result.push_back(to_string(domainCount[domain]));
        }
    }
    return result;
}
int main()
{
    eff;

    vector<vector<string>> operations = {
        {"PUT", "www.apple.com", "10.20.30.40"},
        {"PUT", "jobs.apple.com", "10.20.30.50"},
        {"PUT", "sites.google.com", "142.58.145.693"},
        {"GET", "sample.com"},
        {"GET", "www.apple.com"},
        {"COUNT", "apple.com"},
        {"COUNT", "com"}
    };

    vector<string> result = processDomainOperations(operations);

    for (const string &res : result) {
        cout << res << " ";
    }
    cout << endl;
    
    return 0;
}