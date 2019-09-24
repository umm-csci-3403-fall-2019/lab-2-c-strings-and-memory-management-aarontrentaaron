#include <gtest/gtest.h>

#include "disemvowel.h"

TEST(Disemvowel, HandleEmptyString) {
  char* empty = disemvowel((char*) "");
  ASSERT_STREQ("", empty);
  free(empty);
}

TEST(Disemvowel, HandleNoVowels) {
  char* novowels = disemvowel((char*) "pqrst");
  ASSERT_STREQ("pqrst", novowels);
  free(novowels);
}

TEST(Disemvowel, HandleOnlyVowels) {
  char* onlyvowels = disemvowel((char*) "aeiouAEIOUOIEAuoiea");
  ASSERT_STREQ("", onlyvowels);
  free(onlyvowels);
}

TEST(Disemvowel, HandleMorrisMinnesota) {
  char* mormin = disemvowel((char*) "Morris, Minnesota");
  ASSERT_STREQ("Mrrs, Mnnst", mormin);
  free(mormin);
}

TEST(Disemvowel, HandlePunctuation) {
  char* elphnt = disemvowel((char*) "An (Unexplained) Elephant!");
  ASSERT_STREQ("n (nxplnd) lphnt!", elphnt);
  free(elphnt);
}

TEST(Disemvowel, HandleLongString) {
  char *str;
  int size;
  int i;

  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';
  
  char* nolong = disemvowel((char*) str);
  ASSERT_STREQ("xyz", nolong);
  free(nolong);
  free(str);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
