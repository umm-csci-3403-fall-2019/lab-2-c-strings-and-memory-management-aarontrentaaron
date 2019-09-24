#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "disemvowel.h"

char *disemvowel(char *str) {
  char* novowels; //What we intend to return
  int inputlen;
  int outputlen;
  char vowels[10] = {'a','e','i','o','u','A','E','I','O','U'};
  inputlen = strlen(str); //Length of input, which doesn't include the null terminator
  outputlen = inputlen;
  for (int i=0; i<inputlen; i++) { //We go through the input string...
    for (int v=0; v<10; v++) { //Check if that character is a vowel...
       if (str[i] == vowels[v]) {
         outputlen--; //And shrink the size of the output string appropriately
       }
    }
  }
  int novindex = 0; //This variable tracks what index we're inserting characters into our output string novowels
  novowels = (char*)calloc(outputlen + 1, sizeof(char)); //Size is outputlen + 1 to account for the null terminator
  for (int i=0; i<inputlen; i++) {
	  bool isvowel = false; //We assume the character isn't a vowel until proven otherwise
	  for (int v=0; v<10; v++) {
		  if (str[i] == vowels[v]) { //We check if the character is a particular vowel
			  isvowel = true;
		  } if (isvowel) { //If it is, we exit the loop
			  break;
		  }
	  }
	  if (!isvowel) { //If the character is not a vowel, we put it in the appropriate space in our output string, then increment that index
		  novowels[novindex] = str[i];
		  novindex++;
	  }
  }
  novowels[outputlen] = '\0'; //We add the null terminator
  return novowels;
}
