#include<bits/stdc++.h>
using namespace std;

// Split the string into words (Alphanumeric only)
void split(string &str, vector<string> &cont) {
    string regex = ".,;!? \t\n"; // Add here if needed to split at other symbols
    string word = "";
    for (int i = 0; i < str.length(); ++i) {
        if (regex.find(str[i]) != -1) {
            if (!word.empty()) {
                cont.push_back(word);
                word = "";
            }
        } else {
            word += tolower(str[i]);
        }
    }
}
// Read the file as string sream and split it into words in a String array
vector<string> readFile(string &filename) {
    vector<string> words;
    ifstream file;
    file.open(filename, ios::in);
    if (!file) {
        cout << "Couldn't open file" << endl;
        throw std::exception();
    }
    ostringstream ss;
    ss << file.rdbuf();
    string str = ss.str();
    split(str, words);
    file.close();
    return words;
}
// Count the frequency of each wor in the document
map<string, long long> countFrequency(string path) {
    const vector<string> &words = readFile(path);
    map<string, long long> count;
    for (int i = 0; i < words.size(); ++i) {
        ++count[words[i]];
    }
    return count;
}
// Find the inner product (dot product) between the two vectors and return dd'
long long innerProduct(map<string, long long> &first, map<string, long long> &second) {
    long long total = 0;
    auto fIterator = first.begin();
    auto sIterator = second.begin();

    while (fIterator != first.end() && sIterator != second.end()) {
        if (fIterator->first == sIterator->first) {
            total += (fIterator->second * sIterator->second);
        }
        if (fIterator->first <= sIterator->first) {
            ++fIterator;
        } else {
            ++sIterator;
        }
    }
    return total;
}
// Converting from radian to degree
double convert(double radian) {
    double pi = 3.14159;
    return (radian * (180 / pi));
}
/* Finding the angle(rad) between the two vectors that represents the document based on the words it has */
double compare(map<string, long long> &d1, map<string, long long> &d2) {
    double numerator = innerProduct(d1, d2);
    double denominator = sqrt(innerProduct(d1, d1) * innerProduct(d2, d2));

    return convert(acos(numerator / denominator));
}


int main() {
    string f1 = "f1.txt", f2 = "f2.txt"; // Change to path of the files needed for comparison

    map<string, long long> d1 = countFrequency(f1);
    map<string, long long> d2 = countFrequency(f2);

    double angle = compare(d1, d2);

    printf("The angle is: %0.1f\n", angle);
    printf("Similarity percentage: %0.2f%%", ((90 - angle) / 90) * 100);
}