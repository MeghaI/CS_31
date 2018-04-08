//
//  main.cpp
//  project4
//
//  Created by Megha Ilango on 11/1/17.
//  Copyright © 2017 Megha Ilango. All rights reserved.
//

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int appendToAll(string a[], int n, string value);
int lookup(const string a[], int n, string target);
int positionOfMax(const string a[], int n);
int rotateLeft(string a[], int n, int pos); //no additional arrays
int rotateRight(string a[], int n, int pos); //no additional arrays
int countRuns(const string a[], int n);
int flip(string a[], int n); //no additional arrays
int differ(const string a1[], int n1, const string a2[], int n2);
int subsequence(const string a1[], int n1, const string a2[], int n2);
int lookupAny(const string a1[], int n1, const string a2[], int n2);
int split(string a[], int n, string splitter); //no additional arrays


/*int main() {
   // TEST CASES
    string h[7] = { "selina", "reed", "diana", "tony", "", "logan", "peter" };
    string z[7] = { "peter", "selina", "reed", "diana", "tony", "", "logan"};
    assert(lookup(h, 7, "logan") == 5);
    assert(lookup(h, 7, "diana") == 2);
    assert(lookup(h, 2, "diana") == -1);
    string l[10] = {"a", "", "b", "", "c", "d", "e", "fgh"};
    assert(lookup(l, 5, "") == 1);
    
    assert(positionOfMax(h, 7) == 3);
    assert(positionOfMax(l, 8) == 7);
    
    string m[5] = {"a", "", "b", "", "d"};

    
    string g[4] = { "selina", "reed", "peter", "sue" };
    assert(differ(h, 4, g, 4) == 2);
    assert(differ(l, 7, m, 4) == 4);
    assert(differ(l, 7, g, 4) == 0);
    assert(appendToAll(g, 4, "?") == 4 && g[0] == "selina?" && g[3] == "sue?");
    assert(rotateLeft(g, 4, 1) == 1 && g[1] == "peter?" && g[3] == "reed?");
    
    string e[4] = { "diana", "tony", "", "logan" };
    assert(subsequence(h, 7, e, 4) == 2);
    
    string r[5] = { "reed", "reed", "reed", "tony", "tony" };
    assert(countRuns(r, 5) == 2);
    
    string f[3] = { "peter", "diana", "steve" };
    assert(lookupAny(h, 7, f, 3) == 2);
    assert(flip(f, 3) == 3 && f[0] == "steve" && f[2] == "peter");

    assert(split(h, 7, "peter") == 3);
    assert(split(z, 7, "peter")==3);
    assert(split(z, 7, "selina")==5);
    
    
    string people[5] = { "clark", "peter", "diana", "tony", "selina" };
    assert(appendToAll(people, 5, "!!!")==5);
    assert(people[4]=="selina!!!");
    string hero[6] = { "clark", "peter", "reed", "tony", "diana", "bruce" };
    assert(positionOfMax(hero, 6)==3);
    string super[5] = { "logan", "clark", "peter", "sue", "reed" };
    assert(rotateLeft(super, 5, 1)==1);
    assert(super[3]=="reed");
    string d[9] = {"tony", "bruce", "steve", "steve", "diana", "diana", "diana", "steve", "steve"};
    assert(countRuns(d, 9)==5);
    
    string folks[6] = { "bruce", "steve", "", "tony", "sue", "clark" };
    assert(flip(folks, 4)==4);
    assert(folks[1]=="");
    
    string folks2[6] = { "bruce", "steve", "", "tony", "sue", "clark" };
    assert(flip(folks2, 1)==1 && folks2[3]=="tony");
    assert(folks2[0]=="bruce");
    string group[5] = { "bruce", "steve", "clark", "", "tony" };
    assert(differ(folks2, 6, group, 5)==2);
    assert(differ(folks2, 2, group, 1)==1);
    
    string names[10] = { "logan", "reed", "sue", "selina", "bruce", "peter" };
    string names1[10] = { "reed", "sue", "selina" };
    assert(subsequence(names, 6, names1, 3)==1);
    string names2[10] = { "logan", "selina" };
    assert(subsequence(names, 5, names2, 2)==-1);
    
    string names3[10] = { "logan", "reed", "sue", "selina", "bruce", "peter" };
    string set1[10] = { "clark", "bruce", "selina", "reed" };
    assert(lookupAny(names3, 6, set1, 4)==1);  // returns 1 (a1 has "reed" there)
    string set2[10] = { "tony", "diana" };
    assert(lookupAny(names3, 6, set2, 2)==-1);  // returns -1 (a1 has none)
    
    string hero4[6] = { "clark", "peter", "reed", "tony", "diana", "bruce" };
    assert(split(hero4, 6, "logan")==3);
    assert(hero4[0]<"logan" && hero4[5]>"logan");
    string hero5[4] = { "reed", "sue", "peter", "steve" };
    assert(split(hero5, 4, "steve")==2);
    assert(hero5[2]=="steve");
    
    cout << "All tests succeeded" << endl;

}*/

//loops through array, appending value to each element
int appendToAll(string a[], int n, string value){
    if (n<0) return -1;
    for (int i = 0; i<n; i++){
        a[i]+=value;
    }
    return n;
}

//loops through array, returning index if target is found
int lookup(const string a[], int n, string target){
    for (int i = 0; i<n; i++){
        if (a[i]==target) return i;
    }
    return -1;
}

//have variable max to keep track of max element, compare each element to max, making it max if max if less than it; return max
int positionOfMax(const string a[], int n){
    if (n<0) return -1;
    int max = 0;
    for(int i = 0; i<n; i++){
        if(a[i]>a[max]) max = i;
    }
    return max;
}

//save the value at pos, replace pos with element in front of it, and so on until the second to last element. replace second to last element with value at pos
int rotateLeft(string a[], int n, int pos){
    if (pos>n || n<0) return -1;
    string saved = a[pos];
    int i;
    for(i = pos; i<n-1; i++){
        a[i] = a[i+1];
    }
    a[i] = saved;
    return pos;
}

int rotateRight(string a[], int n, int pos){
    if (pos>n || n<0) return -1;
    string saved = a[n-1];
    int i;
    for(i = n-1; i>0; i--){
        a[i] = a[i-1];
    }
    if(n>0) a[0] = saved;
    return pos;
}

//have a value called stored. loop through array and if elements are not equal to stored, make stored equal them and increase the number of runs
int countRuns(const string a[], int n){
    if (n<0) return -1;
    string stored;
    int runs = 0;
    for(int i = 0; i<n; i++){
        if(a[i]!=stored){
            stored = a[i];
            runs++;
        }
    }
    return runs;
}

//go from start to middle of array, swapping elements with other elements that are same distance from middle
int flip(string a[], int n){
    if (n<0) return -1;
    for(int i = 0; i<n/2; i++){
        string temp = a[0];
        a[i] = a[n-1-i];
        a[n-1-i] = temp;
    }
    return n;
}

//save which array is smaller. loop through array, and if an element differs return that element. return smaller array if elements run out.
int differ(const string a1[], int n1, const string a2[], int n2){
    if(n1<0 || n2<0) return -1;
    int small = n1<=n2 ? n1 : n2;
    for(int i = 0; i<small; i++){
        if(a1[i]!=a2[i]) return i;
    }
    return small;
}

int subsequence(const string a1[], int n1, const string a2[], int n2){
    if (n1<0 || n2<0) return -1;
    if(n2==0) return 0;
    //boolean keeps track of whether subsequence exists
    bool isSub = false;
    //loop through array
    for(int i = 0; i<n1; i++){
        if(a1[i]==a2[0]){ //element of a1 is equal to element of a2
            isSub = true;
            for(int j = 0; j<n2; j++){
                if(i+j<n1 && a1[i+j]!=a2[j]){ //if element differs
                    isSub = false;
                    break;
                }
            }
            if(isSub) return i; //if subsequence has been found, no elements have differed
        }
    }
    return -1; //only reaches this if isSub is false
}

int lookupAny(const string a1[], int n1, const string a2[], int n2){
    if (n1<0 || n2<0) return -1;
    //loop through first array
    for(int i = 0; i<n1; i++){
        for(int j = 0; j<n2; j++){
            if (a1[i]==a2[j]) return i; //if element in first array is equal to any elements in second array
        }
    }
    return -1; //if no equal elements have been found
}

int split(string a[], int n, string splitter){
    if(n<0) return -1;
    int ntemp = n;
    for(int i = 0; i<ntemp; i++){
        if(a[i]>splitter){
            rotateLeft(a, n, i); //if an element is greater than splitter, it goes to the end of the array through rotateLeft
            i--;
            ntemp-=1;
            
        }
    }
    //if splitter was in array, the following loop brings it between elements less than and greater than it
    int split;
    for(int i = 0; i<n; i++){
        if(a[i]>=splitter){
            split = i;
        }
    }
    for(int i =0; i<n; i++){
        if (a[i]==splitter) rotateLeft(a, split, i);
    }
    
    for(int i = 0; i<n; i++){
        if(a[i]>=splitter){
            return i; //return least element greater than or equal to splitter
        }
    }
    return n;
}

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cassert>

using namespace std;

string c[6] = {
    "alpha", "beta", "beta", "delta", "gamma", "gamma"
};

bool splitcheck(const string a[], int n, int p, string splitter)
{
    for (int k = 0; k < p; k++)
        if (a[k] >= splitter)
            return false;
    for ( ; p < n  &&  a[p] == splitter; p++)
        ;
    for (int k = p; k < n; k++)
        if (a[k] <= splitter)
            return false;
    string b[100];
    copy(a, a+n, b);
    sort(b, b+n);
    return equal(b, b+n, c);
}

void testone(int n)
{
    const int N = 6;
    
    // Act as if  a  were declared:
    //   string a[N] = {
    //       "alpha", "beta", "gamma", "gamma", "beta", "delta"
    //   };
    // This is done in a way that will probably cause a crash if
    // a[-1] or a[N] is accessed:  We place garbage in those positions.
    string aa[1+N+1] = {
        "", "alpha", "beta", "gamma", "gamma", "beta", "delta", ""
    };
    string* a = &aa[1];
    string* z = aa;
    a[-1].string::~string();
    a[N].string::~string();
    fill_n(reinterpret_cast<char*>(&a[-1]), sizeof(a[-1]), 0xEF);
    fill_n(reinterpret_cast<char*>(&a[N]), sizeof(a[N]), 0xEF);
    
    string b[N] = {
        "alpha", "beta", "gamma", "delta", "beta", "delta"
    };
    
    string d[9] = {
        "alpha", "beta",  "beta", "beta", "alpha",
        "alpha", "delta", "beta", "beta"
    };
    
    switch (n)
    {
        case  1: {
            assert(appendToAll(z, -1, "rho") == -1 && a[0] == "alpha");
        } break; case  2: {
            assert(appendToAll(z, 0, "rho") == 0 && a[0] == "alpha");
        } break; case  3: {
            assert(appendToAll(a, 1, "rho") == 1 && a[0] == "alpharho" &&
                   a[1] == "beta");
        } break; case  4: {
            assert(appendToAll(a, 6, "rho") == 6 && a[0] == "alpharho" &&
                   a[1] == "betarho" && a[2] == "gammarho" &&
                   a[3] == "gammarho" && a[4] == "betarho" &&
                   a[5] == "deltarho");
        } break; case  5: {
            assert(lookup(z, -1, "alpha") == -1);
        } break; case  6: {
            assert(lookup(z, 0, "alpha") == -1);
        } break; case  7: {
            assert(lookup(a, 1, "alpha") == 0);
        } break; case  8: {
            assert(lookup(a, 6, "delta") == 5);
        } break; case  9: {
            assert(lookup(a, 6, "beta") == 1);
        } break; case 10: {
            assert(lookup(a, 6, "zeta") == -1);
        } break; case 11: {
            assert(positionOfMax(z, -1) == -1);
        } break; case 12: {
            assert(positionOfMax(z, 0) == -1);
        } break; case 13: {
            assert(positionOfMax(a, 1) == 0);
        } break; case 14: {
            assert(positionOfMax(a, 3) == 2);
        } break; case 15: {
            assert(positionOfMax(a, 6) == 2);
        } break; case 16: {
            assert(positionOfMax(a+3, 3) == 0);
        } break; case 17: {
            a[0] = "";
            a[1] = " ";
            a[2] = "";
            assert(positionOfMax(a, 3) == 1);
        } break; case 18: {
            assert(rotateLeft(z, -1, 0) == -1 &&
                   a[0] == "alpha" && a[1] == "beta");
        } break; case 19: {
            assert(rotateLeft(a, 6, -1) == -1 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 20: {
            assert(rotateLeft(a, 6, 6) == -1 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 21: {
            assert(rotateLeft(z, 0, 0) == -1 &&
                   a[0] == "alpha" && a[1] == "beta");
        } break; case 22: {
            assert(rotateLeft(a, 1, 0) == 0 &&
                   a[0] == "alpha" && a[1] == "beta");
        } break; case 23: {
            assert(rotateLeft(a, 6, 0) == 0 &&
                   a[0] == "beta" && a[1] == "gamma" && a[2] == "gamma" &&
                   a[3] == "beta" && a[4] == "delta" && a[5] == "alpha");
        } break; case 24: {
            assert(rotateLeft(a, 6, 5) == 5 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 25: {
            assert(rotateLeft(a, 6, 3) == 3 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "beta" && a[4] == "delta" && a[5] == "gamma");
        } break; case 26: {
            assert(rotateLeft(a, 5, 3) == 3 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "beta" && a[4] == "gamma" && a[5] == "delta");
        } break; case 27: {
            assert(countRuns(z, -1) == -1);
        } break; case 28: {
            assert(countRuns(z, 0) == 0);
        } break; case 29: {
            assert(countRuns(a, 1) == 1);
        } break; case 30: {
            assert(countRuns(a, 3) == 3);
        } break; case 31: {
            assert(countRuns(a, 4) == 3);
        } break; case 32: {
            assert(countRuns(a+2, 4) == 3);
        } break; case 33: {
            assert(countRuns(d, 9) == 5);
        } break; case 34: {
            assert(flip(z, -1) == -1 && a[0] == "alpha");
        } break; case 35: {
            assert(flip(z, 0) == 0 && a[0] == "alpha");
        } break; case 36: {
            assert(flip(a, 1) == 1 && a[0] == "alpha" &&
                   a[1] == "beta");
        } break; case 37: {
            assert(flip(a, 2) == 2 && a[0] == "beta" &&
                   a[1] == "alpha" && a[2] == "gamma");
        } break; case 38: {
            assert(flip(a, 5) == 5 && a[0] == "beta" &&
                   a[1] == "gamma" && a[2] == "gamma" && a[3] == "beta" &&
                   a[4] == "alpha" && a[5] == "delta");
        } break; case 39: {
            a[2] = "zeta";
            assert(flip(a,6) == 6 && a[0] == "delta" && a[1] == "beta" &&
                   a[2] == "gamma" && a[3] == "zeta" && a[4] == "beta" &&
                   a[5] == "alpha");
        } break; case 40: {
            assert(differ(z, -1, b, 6) == -1);
        } break; case 41: {
            assert(differ(a, 6, z, -1) == -1);
        } break; case 42: {
            assert(differ(z, 0, b, 0) == 0);
        } break; case 43: {
            assert(differ(a, 3, b, 3) == 3);
        } break; case 44: {
            assert(differ(a, 3, b, 2) == 2);
        } break; case 45: {
            assert(differ(a, 2, b, 3) == 2);
        } break; case 46: {
            assert(differ(a, 6, b, 6) == 3);
        } break; case 47: {
            assert(subsequence(z, -1, b, 6) == -1);
        } break; case 48: {
            assert(subsequence(a, 6, z, -1) == -1);
        } break; case 49: {
            assert(subsequence(z, 0, b, 6) == -1);
        } break; case 50: {
            assert(subsequence(a, 6, z, 0) == 0);
        } break; case 51: {
            assert(subsequence(a, 6, b, 1) == 0);
        } break; case 52: {
            assert(subsequence(a, 6, b+4, 2) == 4);
        } break; case 53: {
            assert(subsequence(a, 6, b+3, 1) == 5);
        } break; case 54: {
            assert(subsequence(a, 6, b+3, 2) == -1);
        } break; case 55: {
            assert(subsequence(a, 6, b+2, 2) == -1);
        } break; case 56: {
            assert(subsequence(a, 6, a, 6) == 0);
        } break; case 57: {
            assert(lookupAny(a, 6, z, -1) == -1);
        } break; case 58: {
            assert(lookupAny(z, -1, b, 6) == -1);
        } break; case 59: {
            assert(lookupAny(z, 0, b, 1) == -1);
        } break; case 60: {
            assert(lookupAny(a, 6, z, 0) == -1);
        } break; case 61: {
            assert(lookupAny(a, 1, b, 1) == 0);
        } break; case 62: {
            assert(lookupAny(a, 6, b+3, 3) == 1);
        } break; case 63: {
            assert(lookupAny(a, 4, b+3, 3) == 1);
        } break; case 64: {
            assert(lookupAny(a, 2, b+2, 2) == -1);
        } break; case 65: {
            assert(split(z, -1, "beta") == -1 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 66: {
            assert(split(z, 0, "beta") == 0 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 67: {
            assert(split(a, 1, "aaa") == 0 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 68: {
            assert(split(a, 1, "alpha") == 0 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 69: {
            assert(split(a, 1, "zeta") == 1 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 70: {
            assert(split(a, 2, "aaa") == 0 &&
                   splitcheck(a, 2, 0, "aaa") && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 71: {
            assert(split(a, 2, "alpha") == 0 &&
                   splitcheck(a, 2, 0, "alpha") && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 72: {
            assert(split(a, 2, "beta") == 1 &&
                   splitcheck(a, 2, 1, "beta") && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 73: {
            assert(split(a, 2, "zeta") == 2 &&
                   splitcheck(a, 2, 2, "zeta") && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 74: {
            assert(split(a, 6, "aaa") == 0 && splitcheck(a, 6, 0, "aaa"));
        } break; case 75: {
            assert(split(a, 6, "alpha") == 0 &&
                   splitcheck(a, 6, 0, "alpha"));
        } break; case 76: {
            assert(split(a, 6, "beta") == 1 &&
                   splitcheck(a, 6, 1, "beta"));
        } break; case 77: {
            assert(split(a, 6, "delta") == 3 &&
                   splitcheck(a, 6, 3, "delta"));
        } break; case 78: {
            assert(split(a, 6, "gamma") == 4 &&
                   splitcheck(a, 6, 4, "gamma"));
        } break; case 79: {
            assert(split(a, 6, "zeta") == 6 &&
                   splitcheck(a, 6, 6, "zeta"));
        } break; case 80: {
            a[2] = "mu";
            c[5] = "mu";
            assert(split(a, 6, "mu") == 5 && splitcheck(a, 6, 5, "mu"));
        } break; case 81: {
            assert(split(a, 6, "chi") == 3 && splitcheck(a, 6, 3, "chi"));
        } break; case 82: {
            // To earn the bonus point for rotateLeft, this and all other
            // rotateLeft tests must pass, and that function must not
            // use any additional arrays.
            const int BIG = 500;
            string h[BIG];
            for (int k = 0; k < BIG; k++)
                h[k] = (k % 2 == 0 ? "alpha" : "beta");
            h[BIG-2] = "gamma";
            h[BIG-1] = "delta";
            rotateLeft(h, BIG, 0);
            assert(h[BIG-3] == "gamma"  &&  h[BIG-2] == "delta");
        } break; case 83: {
            // To earn the bonus point for flip, this and all other
            // flip tests must pass, and that function must not
            // use any additional arrays.
            const int BIG = 500;
            string h[BIG];
            for (int k = 0; k < BIG; k++)
                h[k] = (k % 2 == 0 ? "alpha" : "beta");
            h[0] = "gamma";
            h[BIG-1] = "delta";
            flip(h, BIG);
            assert(h[0] == "delta"  &&  h[BIG-1] == "gamma");
        } break; case 84: {
            // To earn the bonus point for split, this and all other
            // split tests must pass, and that function must not
            // use any additional arrays.
            const int BIG = 500;
            string h[BIG];
            string i[3] = { "alpha", "beta", "gamma" };
            for (int k = 0; k < BIG; k++)
                h[k] = i[k % 3];
            split(h, BIG, "beta");
            int m = 0;
            for (m = 0; m < (BIG+2)/3; m++)
                assert(h[m] == "alpha");
            for ( ; m < (BIG+1)/3; m++)
                assert(h[m] == "beta");
            for ( ; m < BIG/3; m++)
                assert(h[m] == "gamma");
        } break;
    }
    
    new (&a[-1]) string;
    new (&a[N]) string;
}

int main()
{
    cout << "Enter a test number (1 to 84): ";
    int n;
    cin >> n;
    if (n < 1  ||  n > 84)
    {
        cout << "Bad test number" << endl;
        return 1;
    }
    testone(n);
    cout << "Passed test " << n << endl;
}




