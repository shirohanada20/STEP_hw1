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
  std::unordered_map<char, Word_block*> next;
  void release();
  //~Word_block();

  /*Word_block(){
    std::cout << h << '\n';
    if (h < 6.70904e+19) {
    for (int i = 65; i < 91; i++) {
      h++;
      next[char(i)] = new Word_block;
    }

  }

}*/
};

int Word_block::h = 0; //やばそう
int Word_block::h2 = 0;

/*Word_block::~Word_block(){
  if (next.at('A') != NULL) {
    for (int i = 65; i < 91; i++) {
      delete next.at(char(i));
    }
  }
}*/
/*Word_block::release(){
  delete
}*/


void quicksort(std::string& word, int first, int last) {
  if (last - first <= 1) {//これなんか怪しい
    return;
  }
  int i = first, j = last - 1;//これ注意
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
      //record.push_back()
    }
    }
  }
  return record;
}

class Word_map {
  private:
    std::unordered_map<char, std::unordered_map<char, Word_block*>* > dictionary;
    std::vector<std::string> stock;

  public:
    void getwords(std::string filename);
    void addwords(std::string word);
    void setwords(std::string filename);
    void searchword(std::string characters);
    void searchword2(std::string characters);
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
    }

  };

void Word_map::getwords(std::string filename) {
  std::ifstream ifs(filename);
}

void Word_map::addwords(std::string word){
  char c,c2;
  std::string record = word;
  std::transform(word.begin(), word.end(), word.begin(), toupper);
  quicksort(word, 0, word.length());
  //std::cout << record << '\n';
  c = word[0];
  c2 = word[1];
  dictionary.at(c) -> at(c2)->words.push_back(record);
  //std::cout << dictionary.at(c) -> at(c2)->words[0] << '\n';

}

void Word_map::searchword(std::string characters) {//16文字を受け取る
  char c,c2;
  Word_block* wordblock;
  std::vector<std::string>* v;
  std::string comp;
  std::transform(characters.begin(), characters.end(), characters.begin(), toupper);
  quicksort(characters, 0, characters.length());

  c = characters[0];
  c2 = characters[1];
  v = &(dictionary.at(c) -> at(c2)->words);
  for (int i = 0; i != v->size(); i++) {
    comp = v->at(i);
    std::transform(comp.begin(), comp.end(), comp.begin(), toupper);
    quicksort(comp, 0, comp.length());
    if (comp == characters) {
      stock.push_back(v->at(i));
      std::cout << v->at(i) << '\n';
    }
  }

}
void Word_map::searchword2(std::string characters){
  std::vector<std::string> comb;
  comb = combination(characters);
  for (int i = 0; i != comb.size(); i++) {
    searchword(comb[i]);
  }

}

void Word_map::release(){
  /*for (int i = 65; i < 91; i++) {
    for (int j = 65; j < 91; j++) {
      delete dictionary.at(char(i)) -> at(char(j));
    }
  }
  for (int i = 65; i < 91; i++) {
    delete dictionary.at(char(i));
  }*/
}

int main() {
  char buf[512];
  char buf2[512];
  std::string str;
  std::string characters = "abcd";
  std::vector<std::string> result;
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
    wordmap->searchword2(characters);
  }
  /*result = combination(characters);
  for (int i = 0; i != result.size(); i++) {
    std::cout << result[i] << '\n';
  }*/
  /*ifs.getline(buf, sizeof(buf));
  ifs.getline(buf2, sizeof(buf2));
  std::cout << buf2 << std::endl;*/
  /*std::unordered_map<char, std::unordered_map<char, Wordblock> > dictionary;*/
  /*wordmap -> getwords("mydictionary.txt");
  std::string tester = "aaa";
  wordmap -> addwords(tester);
  wordmap -> addwords(buf);
  wordmap -> addwords(buf2);*/
  //std::transform(tester.begin(), tester.end(), tester.begin(), toupper);
  //std::cout << tester << std::endl;
  //quicksort(tester, 0, tester.length());
  //std::cout << tester << std::endl;
  /*while (c != 'a') {
    c = std::getchar();
  }*/
  wordmap->release();
  delete wordmap;
  return 0;
}
