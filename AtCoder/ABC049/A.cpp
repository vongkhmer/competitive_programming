/*
 * author: vongkh
 * created: Sat Jan 02 2021
 */


#include <stdio.h>
#include <cstring>
using namespace std;

//char array that contains all the vowel
char* vowel ="aeiou";

void solve(){
    char c;
    scanf("%c", &c);
    int sz = strlen(vowel);
    //try to match the input character with the character in vowel array
    for(int i = 0 ; i < sz ; i++){
        if( c == vowel[i]){
            printf("vowel\n");
            return;
        }
    }
    printf("consonant\n");
}

int main(){
    solve();
}
