#include <iostream>
using namespace std;

int wordToNum(const string& str) {
  if(str == "Rock")
    return 0;
  else if(str == "Scissors")
    return 1;
  else 
    return 2;
}

int main() {
  string player, computer;
  string sentences[] = {"Continue again!", "You lose!", "You win!"};
  while(cin>>player>>computer) {
    int p = wordToNum(player);
    int c = wordToNum(computer);
    cout<<sentences[(p-c+3)%3]<<endl;
  }
  return 0;
}
