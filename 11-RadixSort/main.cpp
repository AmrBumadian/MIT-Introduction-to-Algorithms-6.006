#include <bits/stdc++.h>
using namespace std;

vector<int> input, output;
void countSort (int mod) {
    const int range = 10;
    output.clear();
    output.resize(input.size());
    int Count[10] = {0};
    for (int i=0;i<input.size();++i)
    {
        ++Count[(input[i]/mod)%10];
    }
    for (int i=1;i<10;++i)
    {
        Count[i]+=Count[i-1];
    }
    for (int i=input.size()-1;i>=0 and Count[(input[i]/mod)%(mod*10)];--i)
    {
        output [Count[(input[i]/mod)%10]-1]  = input[i];
        --Count[(input[i]/mod)%10];
    }
    input = output;
}
void radixSort (int maxx) {
    for (int exp = 1; maxx/exp > 0; exp *= 10)
    {
        countSort(exp);
    }
}
int main() {
    int n;
    cin>>n;
    input.resize(n);
    int maxx =0;
    for (int i=0;i<n;++i)
    {
        cin>>input[i];
        maxx = max(input[i],maxx);
    }
    radixSort(maxx);
    for (int i=0;i<input.size();++i)
        cout<<input[i]<<" ";
    cout<<endl;
    return 0;
}
