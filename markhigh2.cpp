#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <ios>

class Word_block {
private:
  static int h;
  static int h2;
public:
  std::vector<std::string> words;
  std::unordered_map<char, Word_block*>* next;
  void release();

};

int Word_block::h = 0;
int Word_block::h2 = 0;



void quicksort(std::string& word, int first, int last) {
  if (last - first <= 1) {
    return;
  }
  int i = first, j = last - 1;
  for (int pivot = first;; i++, j--) {
    while (word[i] < word[pivot]) {
      i++;
    }
    while (word[pivot] < word[j]) {
      j--;
    }
    if (i >= j) {
      break;
    }
    std::swap(word[i], word[j]);
  }
  quicksort(word, first, i);
  quicksort(word, j+1, last);
}

std::vector<std::string> combination(std::string word){
  int n = word.length();
  int result = 0;
  std::vector<std::string> record;
  for (int i = 3; i <= n; i++) {
    for (int all = 0; all < (1<<n); all++) {
      int num_characters = 0;
      for (int character = 0; character < n; character++) {
        if (all & (1<<character)) {
          num_characters++;
        }
      }
      if (num_characters == i) {
        std::string comb;
        for (int az = 0; az < n; az++) {
          if (all & (1<<az)) {
            comb.push_back(word[az]);
          }
        }
        record.push_back(comb);

      }
    }
  }
  return record;
}

int calcscore(std::string word){
  int score = 0;
  std::transform(word.begin(), word.end(), word.begin(), toupper);
  for (int i = 0; i != word.length(); i++) {
    switch (word[i]) {
      case 'C': score += 2;
      break;
      case 'F': score += 2;
      break;
      case 'H': score += 2;
      break;
      case 'L': score += 2;
      break;
      case 'M': score += 2;
      break;
      case 'P': score += 2;
      break;
      case 'V': score += 2;
      break;
      case 'W': score += 2;
      break;
      case 'Y': score += 2;
      break;
      case 'J': score += 3;
      break;
      case 'K': score += 3;
      break;
      case 'Q': score += 2;
      break;
      case 'X': score += 3;
      break;
      case 'Z': score += 3;
      break;
      default: score += 1;
    }
  }
  score = score*score;
  return score;
}

std::string selecthighword(std::vector<std::string> v){
  std::vector<std::string> m = v;
  std::string highest = v[0];
  for (int i = 1; i < v.size(); i++) {
    std::cout << highest << '\n';
    if (calcscore(highest) < calcscore(v[i])) {
      highest = v[i];
    }
    else{

    }
  }
  return highest;
}

class Word_map {
private:
  std::unordered_map<char, std::unordered_map<char, Word_block*>* > dictionary;

public:
  void getwords(std::string filename);
  void addwords(std::string word);
  void setwords(std::string filename);
  std::string searchword(std::string characters);
  std::string searchword2(std::string characters);
  void printhighword(std::vector<std::string> v);
  void release();

  Word_map(){
    for (int i = 65; i < 91; i++) {
      dictionary[char(i)] = new std::unordered_map<char, Word_block*>;
    }
    for (int i = 65; i < 91; i++) {
      for (int j = 65; j < 91; j++) {
        dictionary.at(char(i)) -> unordered_map::emplace(char(j), new Word_block);
      }
    }
    for (int i = 65; i < 91; i++) {
      for (int j = 65; j < 91; j++) {
        dictionary.at(char(i)) -> at(j)-> next = new std::unordered_map<char, Word_block*>;
      }
    }
    for (int i = 65; i < 91; i++) {
      for (int j = 65; j < 91; j++) {
        for (int k = 65; k < 91; k++) {
          dictionary.at(char(i)) -> at(j)-> next -> unordered_map::emplace(char(k), new Word_block);
        }
      }
    }
    for (int i = 65; i < 91; i++) {
      for (int j = 65; j < 91; j++) {
        for (int k = 65; k < 91; k++) {
          dictionary.at(char(i)) -> at(j)-> next -> at(k) -> next = new std::unordered_map<char, Word_block*>;
        }
      }
    }
    for (int i = 65; i < 91; i++) {
      for (int j = 65; j < 91; j++) {
        for (int k = 65; k < 91; k++) {
          for (int l = 65; l < 91; l++) {
            dictionary.at(char(i)) -> at(j)-> next -> at(k) -> next -> unordered_map::emplace(char(l), new Word_block);
          }
        }
      }
    }
    for (int i = 65; i < 91; i++) {
      for (int j = 65; j < 91; j++) {
        for (int k = 65; k < 91; k++) {
          for (int l = 65; l < 91; l++) {
            dictionary.at(char(i)) -> at(j)-> next -> at(k) -> next -> at(l) -> next = new std::unordered_map<char, Word_block*>;
          }
        }
      }
    }
    for (int i = 65; i < 91; i++) {
      for (int j = 65; j < 91; j++) {
        for (int k = 65; k < 91; k++) {
          for (int l = 65; l < 91; l++) {
            for (int m = 65; m < 91; m++) {
            dictionary.at(char(i)) -> at(j)-> next -> at(k) -> next -> at(l) -> next -> unordered_map::emplace(char(m), new Word_block);
          }
        }
      }
    }
  }
}



};

void Word_map::getwords(std::string filename) {
  std::ifstream ifs(filename);
}

void Word_map::addwords(std::string word){
  char c,c2,c3,c4,c5;
  std::string record = word;
  std::transform(word.begin(), word.end(), word.begin(), toupper);
  quicksort(word, 0, word.length());
  //std::cout << record << '\n';
  c = word[0];
  c2 = word[1];
  c3 = word[2];
  c4 = word[3];
  c5 = word[4];

  if (4 < word.length()) {
    dictionary.at(c) -> at(c2)-> next -> at(c3) -> next -> at(c4) -> next -> at(c5) -> words.push_back(record);
  }

  else if(3 < word.length()){
    dictionary.at(c) -> at(c2)-> next -> at(c3) -> next -> at(c4) -> words.push_back(record);
  }

  else if(2 < word.length()){
    dictionary.at(c) -> at(c2)-> next -> at(c3) -> words.push_back(record);
  }
  else{
    dictionary.at(c) -> at(c2)->words.push_back(record);
  }
}

std::string Word_map::searchword(std::string characters) {//16???????
  char c,c2,c3,c4,c5;
  Word_block* wordblock;
  std::vector<std::string>* v;
  std::string comp;
  std::vector<std::string> stock;
  std::string highest = "A";
  std::transform(characters.begin(), characters.end(), characters.begin(), toupper);
  quicksort(characters, 0, characters.length());

  c = characters[0];
  c2 = characters[1];
  c3 = characters[2];
  c4 = characters[3];
  c5 = characters[4];

  if (4 < characters.length()) {
    v = &(dictionary.at(c) -> at(c2)-> next -> at(c3) -> next -> at(c4) -> next -> at(c5) -> words);
  }

  else if(3 < characters.length()){
    v = &(dictionary.at(c) -> at(c2)-> next -> at(c3) -> next -> at(c4) -> words);
  }

  else if(2 < characters.length()){
    v = &(dictionary.at(c) -> at(c2)-> next -> at(c3) -> words);
  }
  else{
    v = &(dictionary.at(c) -> at(c2)->words);
  }
  for (int i = 0; i != v->size(); i++) {
    comp = v->at(i);
    std::transform(comp.begin(), comp.end(), comp.begin(), toupper);
    quicksort(comp, 0, comp.length());
    if (comp == characters) {
      if (calcscore(highest) < calcscore(comp)) {
        highest = v->at(i);
      }
      else if (calcscore(highest) == calcscore(comp)) {
        if (highest.length() < comp.length()) {
          highest = v->at(i);
        }
      }
      else{

      }
    }
  }
  return highest;
}
std::string Word_map::searchword2(std::string characters){
  std::vector<std::string> comb;
  std::vector<std::string> record;
  std::string comp;
  std::string highest = "A";
  comb = combination(characters);
  for (int i = 0; i != comb.size(); i++) {
    comp = searchword(comb[i]);
    if (calcscore(highest) < calcscore(comp)) {
      highest = comp;
    }
    else if (calcscore(highest) == calcscore(comp)) {
      if (highest.length() < comp.length()) {
        highest = comp;
      }
    }
    else{

    }
  }
  return highest;
}

void Word_map::printhighword(std::vector<std::string> v){
  for (int i = 0; i < v.size(); i++) {
    std::string str;
    std::string str2;


  }
}


void Word_map::release(){
}

int main() {
  char buf[512];
  char buf2[512];
  std::string str;
  std::string characters = "abcd";
  std::string result;
  Word_map *wordmap = new Word_map;
  //int c = 'b';
  std::ifstream ifs("mydictionary.txt");
  while (ifs.getline(buf, sizeof(str))) {
    wordmap->addwords(buf);
  }
  while (1) {
    std::cin >> characters;
    if (characters.length()<3) {
      break;
    }
    result = wordmap->searchword2(characters);
    std::cout << result << '\n';
  }
wordmap->release();
delete wordmap;
return 0;
}
