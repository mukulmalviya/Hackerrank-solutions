#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the matrixRotation function below.



void matrixRotation(vector<vector<int>> matrix, int r) {
    int rows = matrix.size();
    int coloumns = matrix[0].size();
    int mlb=0;
    int nlb=0;
    int mub = rows-1;
    int nub = coloumns-1;
    vector<int> ring;
    vector<int> buffer;
    
    for(int a=nlb;a<=nub;a++)
    {
        ring.push_back(matrix[mlb][a]);
    }
    for(int b=mlb+1;b<=mub;b++)
    {
        ring.push_back(matrix[b][nub]);
    }
    for(int c=nub;c>=nlb;c--)
    {
        ring.push_back(matrix[mub][c]);
    }
    for(int d=mub-1;d>=mlb+1;d--)
    {
        ring.push_back(matrix[d][nlb]);
    }
    
    for(int w=0;w<r;w++)
    {
        buffer.push_back(ring[w]);
    }
    for(int e=0;e<ring.size();e++)
    {
        if((e+r)<ring.size())
            ring[e] = ring[e+r];
        else
            ring[e] = buffer[e-ring.size()];
    }
    //copy it back to matrix
    
    /*for(int q=0;q<ring.size();q++)
        cout<<ring[q]<<endl;
    */
    
    
    /*
    int rows = matrix.size();
    int coloumns = matrix[0].size();
    int mlb=0;
    int nlb=0;
    int mub = rows-1;
    int nub = coloumns-1;
    vector<int> buffer;
    int c=0
    
    while((mub-mlb)/2>=0 || (nub-nlb)/2>=0)
    {
        // comb of extrem+range and range+extreme elements
        //all elements of a[extremes][range] to a[range][extremes] moves r times ahead
        for(int i=mlb;i<mub;i++)
        {
            for(int j=nlb;j<nub;j++)
            {
                if(c<r)
                    buffer.push_back(a[mlb][j]);  
                a[]
                
            }
        }
        mlb++;
        nlb++;
        mub--;
        nub--;
    }
    */
}

int main()
{
    string mnr_temp;
    getline(cin, mnr_temp);

    vector<string> mnr = split(rtrim(mnr_temp));

    int m = stoi(mnr[0]);

    int n = stoi(mnr[1]);

    int r = stoi(mnr[2]);

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, r);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
