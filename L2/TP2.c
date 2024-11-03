#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool testTri(int T[], int n){
    bool test = true;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (T[j] > T[i]) {
          test = false;
        }
      }
    }
    return test;
}

bool existVal(int T[], int n, int val){
    if(!testTri(T, n)){
        printf("Le tableau n'st pas trie");
        return false;
    } else {
        bool exist = false;
        int debut = 0;
        int fin = n-1;
        while(debut <= fin){
            int mid = (debut + fin)/2;
            if(T[mid] == val){
                exist = true;
            } else if(T[mid] > val){
                fin = mid-1;
            } else {
                debut = mid + 1;
            }
        }
        return exist;
    }
}

int occVal(int T[], int n, int val){
    if(!testTri(T, n)){
        printf("Le tableau n'st pas trie");
        return 0;
    } else {
        if(existVal(T, n, val)){
            int occ = 0;
            int debut = 0;
            int fin = n-1;
            while(debut <= fin){
                int mid = (debut + fin)/2;
                if(T[mid] == val){
                    occ++;
                } else if(T[mid] > val){
                    fin = mid-1;
                } else {
                    debut = mid + 1;
                }
            }
            return occ;
        } else {
            return 0;
        } 
    }
}

int longSeq(int T[], int n, int val){

}

int main(){
    int T[100];
    for(int i=0; i<100; i++){
        T[i] = i;
        printf("%d, ", T[i]);
    }




    return 0;
}