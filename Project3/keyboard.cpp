//
//  main.cpp
//  project3
//
//  Created by Megha Ilango on 10/29/17.
//  Copyright © 2017 Megha Ilango. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
using namespace std;

bool hasCorrectSyntax(string song);
bool isNoteLetter(char c);
bool isAccidental(char c);
bool isNote(string note);
int encodeSong(string song, string& instructions, int& badBeat);
char encodeNote(int octave, char noteLetter, char accidentalSign);
string formatNote(string note);

int main() {
    // insert code here...
    /*
    assert(hasCorrectSyntax(""));
    assert(hasCorrectSyntax("/"));
    assert(hasCorrectSyntax("///"));
    assert(hasCorrectSyntax("A/"));
    assert(hasCorrectSyntax("A#/"));
    assert(hasCorrectSyntax("A3/"));
    assert(hasCorrectSyntax("A#3/"));
    assert(hasCorrectSyntax("A/B/"));
    assert(hasCorrectSyntax("A/B//"));
    assert(hasCorrectSyntax("A#2C/B#//"));
    assert(hasCorrectSyntax("A//G/"));
  
    
    cout << hasCorrectSyntax("A2#C/B#3//") << endl;
    
    cout << hasCorrectSyntax("A") << endl;
   
    
    assert(hasCorrectSyntax("D5//D/"));
    assert(!hasCorrectSyntax("D5//Z/"));
    string instrs;
    int badb;
    instrs = "xxx"; badb = -999; // so we can detect whether these get changed
    assert(encodeSong("D5//D/", instrs, badb) == 0  &&  instrs == "R H"  &&  badb == -999);
    instrs = "xxx"; badb = -999; // so we can detect whether these get changed
    assert(encodeSong("D5//Z/", instrs, badb) == 1  &&  instrs == "xxx"  &&  badb == -999);
    assert(encodeSong("D5//D8/", instrs, badb) == 2  &&  instrs == "xxx"  &&  badb == 3);
    cerr << "All tests succeeded" << endl;
    
    instrs = "xxx";
    badb = 8;
    int i = encodeSong("D3/F#3/A3/D4//D3F#3A3D4/", instrs, badb);
    cout << instrs << endl;
    cout << badb << endl;
    cout << i;
     */

}

/* Given a string song, this function returns true if the string is in correct conventional naming format (is a song string). Else, it returns false.*/
bool hasCorrectSyntax(string song){
    if(song=="") return true;
    if(song[song.size()-1]!='/') return false;
    
    //going through the song
    for(int i = song.size()-1; i>0; i--){
        //finding a beat
        if(song[i]=='/'){
            int j = i-1;
            while(j>=0 && song[j]!='/'){
                j--;
            }
            string notes = song.substr(j+1,i-j-1);
            //going through the notes belonging to the beat
            for(int k = 0; k<notes.size(); k++){
                //checking if the note is valid
                if(isNoteLetter(notes[k])){
                    int tracker = k+1;
                    while(tracker<notes.size() && !isNoteLetter(notes[tracker])) tracker++;
                    string note = notes.substr(k, tracker-k);

                    if(!isNote(note)) return false;
                    k = tracker-1;
                }else return false;
            }
            i=j+1;
        }
    }
    return true;
}

/*Given a string containing a complete sequence of note letter and symbols/digits, return true if the sequence is a note and false if does not have the correct syntax to be a note.*/
bool isNote(string note){
    if(note.size()==1 && isNoteLetter(note[0])) return true;
    if(note.size()==2 && isNoteLetter(note[0])){
        if(isdigit(note[1])) return true;
        if(isAccidental(note[1])) return true;
    }
    if(note.size()==3 && isNoteLetter(note[0]) && isAccidental(note[1]) && isdigit(note[2])) return true;
    return false;
}

/*Given a string containing a complete note, return a string with the octave of the note, the letter of the note, and the accidental sign of the note, in that order. If there is no specified octave, return with the digit 4 in the octaves. If the accidental sign is not specified, use a space in place of an accidental sign.*/
string formatNote(string note){
    string ans = "";
    if(note.size()==1 && isNoteLetter(note[0])){
        ans+='4';
        ans+=note[0];
        ans+=" ";
    }
    if(note.size()==2 && isNoteLetter(note[0])){
        if(isdigit(note[1])){
            ans+=note[1];
            ans+=note[0];
            ans+=" ";
        }
        if(isAccidental(note[1])){
            ans+='4';
            ans+=note[0];
            ans+=note[1];
        }
    }
    if(note.size()==3 && isNoteLetter(note[0]) && isAccidental(note[1]) && isdigit(note[2])){
        ans+=note[2];
        ans+=note[0];
        ans+=note[1];
    }
    return ans;
}
/*Given a character, determine whether it is a note letter. */
bool isNoteLetter(char c){
    if(c=='A' || c=='B' || c=='C' || c=='D' || c=='E'|| c=='F' || c=='G') return true;
    return false;
}


/*Given a letter, determine whether it is an accidental sign.*/
bool isAccidental(char c){
    if(c=='b' || c=='#') return true;
    return false;
}

/*Encodes a song in conventional naming to Button Bass software's naming schema.*/
int encodeSong(string song, string& instructions, int& badBeat){
    //returning 1 if the string song is not a song string
    if(!hasCorrectSyntax(song)) return 1;
    string ans = "";
    int numBeats = 0;
    //going through the song
    for(int i = 0; i<song.size(); i++){
        //finding a beat
        if(song[i]=='/'){
            numBeats++;
            int j = i-1;
            while(j>=0 && song[j]!='/'){
                j--;
            }
            string notes = song.substr(j+1,i-j-1);
            string encodedNotes = "";
            //adding a space to the set of encoded notes if no notes belong to the beat
            if(notes.size()==0) encodedNotes+=' ';
            int numNotes = 0;
            //going through the notes belonging to the beat
            for(int k = 0; k<notes.size(); k++){
                if(isNoteLetter(notes[k])){
                    numNotes++;
                    int tracker = k+1;
                    while(tracker<notes.size() && !isNoteLetter(notes[tracker])) tracker++;
                    //encoding the note
                    string note = notes.substr(k, tracker-k);
                    string notef = formatNote(note);
                    char encodedNote = encodeNote(notef[0] - '0', notef[1], notef[2]);
                    //updating bad beats and returning 2 if the note is unplayable
                    if(encodedNote==' '){
                        badBeat = numBeats;
                        return 2;
                    }
                    encodedNotes+=encodedNote;
                    k = tracker-1;
                }
            }
            //adding brackets around the notes belonging to the beat if more than one note belong to the beat
            if(numNotes>1){
                ans+='[';
                ans+=encodedNotes;
                ans+=']';
            }else{
                ans+=encodedNotes;
            }
        }
    }
    //setting instructions to the encoded song and returning 0
    instructions = ans;
    return 0;
}

//*************************************
//  encodeNote
//*************************************

// Given an octave number, a note letter, and an accidental sign, return
// the character that the indicated note is encoded as if it is playable.
// Return a space character if it is not playable.
//
// First parameter:   the octave number (the integer 4 is the number of the
//                    octave that starts with middle C, for example).
// Second parameter:  an upper case note letter, 'A' through 'G'
// Third parameter:   '#', 'b', or ' ' (meaning no accidental sign)
//
// Examples:  encodeNote(4, 'A', ' ') returns 'Q'
//            encodeNote(4, 'A', '#') returns '%'
//            encodeNote(4, 'H', ' ') returns ' '

char encodeNote(int octave, char noteLetter, char accidentalSign)
{
    // This check is here solely to report a common CS 31 student error.
    if (octave > 9)
    {
        cerr << "********** encodeNote was called with first argument = "
        << octave << endl;
    }
    
    // Convert Cb, C, C#/Db, D, D#/Eb, ..., B, B#
    //      to -1, 0,   1,   2,   3, ...,  11, 12
    
    int note;
    switch (noteLetter)
    {
        case 'C':  note =  0; break;
        case 'D':  note =  2; break;
        case 'E':  note =  4; break;
        case 'F':  note =  5; break;
        case 'G':  note =  7; break;
        case 'A':  note =  9; break;
        case 'B':  note = 11; break;
        default:   return ' ';
    }
    switch (accidentalSign)
    {
        case '#':  note++; break;
        case 'b':  note--; break;
        case ' ':  break;
        default:   return ' ';
    }
    
    // Convert ..., A#1, B1, C2, C#2, D2, ... to
    //         ..., -2,  -1, 0,   1,  2, ...
    
    int sequenceNumber = 12 * (octave - 2) + note;
    
    string keymap = "Z1X2CV3B4N5M,6.7/A8S9D0FG!H@JK#L$Q%WE^R&TY*U(I)OP";
    if (sequenceNumber < 0  ||  sequenceNumber >= keymap.size())
        return ' ';
    return keymap[sequenceNumber];
}
