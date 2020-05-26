#include <bits/stdc++.h>
using namespace std;

vector<int> input,output,Count;

void countSort (int k) {

    Count.resize(k+1);
    for (int i=0;i<input.size();++i) {
        ++Count[input[i]];
    }
    for (int i=1;i<k+1;++i) {
        Count[i]+=Count[i-1];
    }
    for (int i=input.size()-1;i>=0 and Count[input[i]]; --i) {
        output[Count[input[i]]-1] = input[i];
        --Count[input[i]];
    }
}
int main() {
    int n;
    cin>>n;
    input.resize(n);
    output.resize(n);
    int maxx = 0;
    for (int i=0;i<n;++i)
    {
        cin>>input[i];
        maxx = max(maxx,input[i]);
    }
    countSort(maxx);
    for (int i=0;i<n;++i)
        cout<<output[i]<<" ";
    cout<<endl;
    return 0;
}
