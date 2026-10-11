#include <bits/stdc++.h>
using namespace std;

double g_to_int(string &g){
    if(g == "A+") return 4.0; if(g == "A") return 3.75;
    if(g == "B+") return 3.5; if(g == "B") return 3.0;
    if(g == "C+") return 2.5; if(g == "C") return 2.0;
    if(g == "D+") return 1.5; if(g == "D") return 1.0;
    return 0.0;
}

double calculate_gpa(int m) {  
    double sum_gpa = 0, sum_cred = 0;
    while(m--) {
        string g; int cred;
        cin >> g >> cred;

        double grade = g_to_int(g);
        sum_gpa += (grade * cred);
        sum_cred += cred;
    }
    if (sum_cred == 0) return 0.0; 
    return sum_gpa / sum_cred;
}

void quicksort(vector<tuple<double, string, string>> &arr, int l , int r) {
    tuple<double, string, string> p = arr[l + (r - l) / 2];
    int i = l, j = r;

    while(i < j) {
        while(p < arr[j]) j--;
        while(p > arr[i]) i++;

        if(i <= j) {
            swap(arr[i], arr[j]);
            i++; j--;
        }
    }

    if(l < j) quicksort(arr, l, j);
    if(r > i) quicksort(arr, i, r);
}

int main() {

    int n, m;
    cin >> n;
    string name, last;
    vector<tuple<double, string, string>> wsp(n);

    for(int i = 0; i < n; i++) {
        cin >> last >> name >> m;
        get<2>(wsp[i]) = name;
        get<1>(wsp[i]) = last;
        get<0>(wsp[i]) = calculate_gpa(m);
    }

    quicksort(wsp, 0, n-1);

    for(auto &[gpa, las, nam] : wsp) {
        cout << las << " " << nam << " ";
        printf("%.3f", gpa); cout << "\n";
    }

    return 0;
}