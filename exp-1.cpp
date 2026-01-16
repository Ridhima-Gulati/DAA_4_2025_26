#include <bits/stdc++.h>
using namespace std;

using namespace std::chrono;

long long operations=0;
int maxdepth;
int maxvalue=0;
int maxcount=0;

void complexRec(int n) {
    maxcount++;
    maxdepth=max(maxvalue, maxcount);


   if (n <= 2) {
       return;
   }


   int p = n;
   while (p > 0) {
       vector<int> temp(n);
       for (int i = 0; i < n; i++) {
           temp[i] = i ^ p;
           operations++;
       }
       p >>= 1;
       
   }


   vector<int> small(n);
   for (int i = 0; i < n; i++) {
       small[i] = i * i;
       operations++;
   }


   if (n % 3 == 0) {
       reverse(small.begin(), small.end());
        operations += n;
   } else {
       reverse(small.begin(), small.end());
   }


   complexRec(n / 2);
   complexRec(n / 2);
   complexRec(n / 2);
}

int main()
{
    int n = 3000;
    auto start = high_resolution_clock::now();

    complexRec(n);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cout << "Number of operations: " << operations << endl;
    cout << "Execution time (milliseconds): " << duration.count() << endl;
    cout<<"max Depth: "<<maxdepth<<endl;
}

//relation 3T(n/2)+nlogn

//asymptotic nototain O(n^1.58)

//24BCY70132