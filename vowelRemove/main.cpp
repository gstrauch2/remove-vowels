// George Strauch
// removes vowels
// 04/19/2018

/* gets string from user
 * converts to char array
 * passes array into function that removes vowels
 * returns vowelless sting
 * prints it
 * deletes array
 * */


#include <iostream>
#include <cstring>
#include <string>
using namespace std;


bool isVowel(char chrTest){

    switch (toupper(chrTest)){
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        case 'Y':
            return true;
        default:
            return false;
    }

}


/* removes vowels
 * ideally, i would only pass the string in the function, create the array in it, then delete it at the end
 * however as noted in the main function, the delete function throws an error and stopping the program here would
 * cause the output not to print */
string vowelRemove(char *chrptr, int intlength) {

    string strNoVowel = "";

    for (int i = 0; i < intlength ; ++i) {
        if(!isVowel(chrptr[i])){
            strNoVowel += chrptr[i];
        }
    }
    return strNoVowel;

}

int main() {

    string strInput = "";
    string strNoVowels = "";

    cout << "enter a string" << endl;
    cin >> strInput;

    char chrArray[strInput.length()];
    strcpy(chrArray, strInput.c_str());
    strNoVowels =  vowelRemove(chrArray, (int)strInput.length());

    cout << "That string without any vowels is: " << endl;
    cout << strNoVowels << endl;

/*   this is still throwing an error that I cannot figure out how to solve
     it is at least giving the output string
     the program will work fine if i comment out the line
     note i am using gcc compiler in linux if that may have something to do with the problem*/
    delete [] chrArray;

    return 0;

}