#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "disemvowel.h"

char *disemvowel(char *str) {
  char* novowels;
  int inputlen;
  int outputlen;
  char vowels[10] = {'a','e','i','o','u','A','E','I','O','U'};
  inputlen = strlen(str);
  outputlen = inputlen;
  for (int i=0; i<inputlen; i++) {
    for (int v=0; v<10; v++) {
       if (str[i] == vowels[v]) {
         outputlen--;
       }
    }
  }
  int novindex = 0;
  novowels = (char*)calloc(outputlen + 1, sizeof(char));
  for (int i=0; i<inputlen; i++) {
	  bool isvowel = false;
	  for (int v=0; v<10; v++) {
		  if (str[i] == vowels[v]) {
			  isvowel = true;
		  } if (isvowel) {
			  break;
		  }
	  }
	  if (!isvowel) {
		  novowels[novindex] = str[i];
		  novindex++;
	  }
  }
  novowels[outputlen] = '\0';
  return novowels;
}
