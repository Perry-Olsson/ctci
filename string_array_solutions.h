#include <iostream>
#include <bits/stdc++.h>

bool checkForRepeatingCharacters(std::string str, bool case_sensitive = true) {
  if (str.length() > 256) return true;

  std::bitset<256> hasChar;
  for (int i = 0; i < str.length(); i++) {
    int code = int(str[i]);
    if (!case_sensitive) {
      if (code >= 65 && code <= 90) {
        std::cout << char(code + 32) << std::endl;
        code += 32;
      } 
    }
    if (hasChar[int(code)] == 1) return true;
    hasChar.flip(int(code));
  } 
  return false;
}

bool checkPermutation(std::string one, std::string two) {
  if (one.length() != two.length()) return false;
  std::map<char, int> characters;
  std::map<char, int>::iterator it;

  for (int i = 0; i < one.length(); i++) {
    if (characters.find(one[i]) != characters.end()) {
      characters.at(one[i]) = characters.at(one[i]) + 1;
    } else {
      characters.insert(std::make_pair(one[i], 1));
    }
  }

  for (int i = 0; i < two.length(); i++) {
    it = characters.find(two[i]);
    if (it != characters.end()) {
      if (it->second == 0) return false;
      it->second -= 1;
    } else {
      return false;
    }
  }
  return true;
}

const char p20[] = "02%";

void insertPercent20(char ** url, int i) {
  for (char c : p20) {
    (*url)[i--] = c;
  }
}

char *  URLify(char * url) {
  int shiftRight = 0;
  int i = strlen(url) - 1;


  while (url[i] == ' ') {
    shiftRight++;
    i--;
  }

  int j = i + shiftRight;
  while (i > 0) {
    if (url[i] == ' '){
      j = i + shiftRight;
        for (int k = 0; k < strlen(p20); k++) {
          url[j] = p20[k];
          j--;
        }
      shiftRight -= 2;
    } else {
      url[i + shiftRight] = url[i];
    }
    i--;
  }
  return url;
}

