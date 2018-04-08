#include "utilities.h"
#include <iostream>
#include <cstring>
using namespace std;

const char WORDFILENAME[] = "/Users/Megha/Documents/CS_31/project5/project5/words.txt";
const int MAXWORDS = 7625;
const int MAXWORDLENGTH = 6;

int runOneRound(const char words[][MAXWORDLENGTH+1], int nWords, int wordnum);
int numStars(char target[MAXWORDLENGTH+1], char probe[MAXWORDLENGTH+1]);
int numPlanets(char target[MAXWORDLENGTH+1], char probe[MAXWORDLENGTH+1]);
bool isLowercase(char word[MAXWORDLENGTH+1]);
bool knownWord(char word[MAXWORDLENGTH+1], const char words[][MAXWORDLENGTH+1]);
int findWord(char word[MAXWORDLENGTH+1], const char words[][MAXWORDLENGTH+1]);

int main()
{
    
    
    char w[MAXWORDS][MAXWORDLENGTH+1];
    int n = getWords(w, MAXWORDS, WORDFILENAME);
    
    if(n<1){
        cout << "No words were loaded, so I can't play the game.";
        return 0;
    }
    
    cout << "How many rounds do you want to play? ";
    int numRounds = 0;
    cin >> numRounds;
    
    cin.ignore(20000, '\n');
    double average = 0;
    int totalscore = 0;
    int minimum = MAXWORDS;
    int maximum = 0;
    for(int i = 0; i<numRounds; i++){
        int wordnum = randInt(0, n-1);
        
        char target[MAXWORDLENGTH+1] = "";
        strcpy(target, w[wordnum]);
        
        /*START SPEC TEST
         
        if(i==0){
            strcpy(target, "raven");
        }else if (i==1){
            strcpy(target, "egret");
        }else if(i==2){
            strcpy(target, "sigh");
        }
        
        for(int j = 0; j<MAXWORDS; j++){
            if(strcmp(w[j], target)==0) wordnum = j;
        }
         
        END TEST*/
        
        cout << "\nRound " << i+1 << endl;
        cout << "The secret word is " << strlen(target) << " letters long." << endl;
        int score = runOneRound(w, n, wordnum);
        totalscore+=score;
        if(score>1)
            cout << "You got it in " << score << " tries." << endl;
        else
            cout << "You got it in 1 try." << endl;
        
        if(score<=minimum){
            minimum = score;
        }
        if(score>=maximum){
            maximum = score;
        }
        
        average = static_cast<double>(totalscore)/(i+1);
        
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);
        
        cout << "Average: " << average << ", minimum: " << minimum << ", maximum: " << maximum << endl;
        
    }
}

int runOneRound(const char words[][MAXWORDLENGTH+1], int nWords, int wordnum){
    
    if(nWords<=0 || (wordnum < 0 || wordnum>=nWords)) return -1;
    char probe[100] = "";
    char target[MAXWORDLENGTH+1] = "";
    int stars = 0;
    int planets = 0;
    int score = 0;
    strcpy(target, words[wordnum]) ;
    do{
        cout << "Probe word: ";
        cin.getline(probe, 100);
        
        if(!((strlen(probe)<=6 && strlen(probe)>=4) && isLowercase(probe)))
            cout << "Your probe word must be a word of 4 to 6 lower case letters." << endl;
        else if(!knownWord(probe, words)){
            cout << "I don't know that word." << endl;
        }else{
            stars = numStars(target, probe);
            planets = numPlanets(target, probe);
            cout << "Stars: " << stars << ", Planets: " << planets << endl;
            score++;
        }
    }while(strcmp(probe, target)!=0);
    return score;
}

int numStars(char target[MAXWORDLENGTH+1], char probe[MAXWORDLENGTH+1]){
    int stars = 0;
    for(int i = 0; i<strlen(target); i++){
        if(i < strlen(probe) && target[i]==probe[i]) stars++;
    }
    return stars;
}

int numPlanets(char target[MAXWORDLENGTH+1], char probe[MAXWORDLENGTH+1]){
    int planets = 0;
    bool inPlanet[MAXWORDLENGTH+1];
    bool inStar[MAXWORDLENGTH+1];
    for(int j = 0; j<strlen(target); j++){
        inPlanet[j] = false;
        if(j<strlen(probe) && target[j]==probe[j]){
            inStar[j] = true;
        }else{
            inStar[j] = false;
        }
    }
    for(int i = 0; i<strlen(probe); i++){
        for(int j = 0; j<strlen(target); j++){
            if(target[j]==probe[i] && inPlanet[j]==false && inStar[i]==false && inStar[j]==false){
                planets++;
                inPlanet[j] = true;
                break;
            }
        }
    }
    return planets;
}

bool isLowercase(char word[]){
    for(int i = 0; i<strlen(word); i++){
        if(islower(word[i])==0) return false;
    }
    return true;
}

bool knownWord(char word[MAXWORDLENGTH+1], const char words[][MAXWORDLENGTH+1]){
    for(int i = 0; i<MAXWORDS; i++){
        if(strcmp(word, words[i])==0) return true;
    }
    return false;
}

int findWord(char word[MAXWORDLENGTH+1], const char words[][MAXWORDLENGTH+1]){
    for(int i = 0; i<MAXWORDS; i++){
        if(strcmp(word, words[i])==0) return i;
    }
    return -1;
}
