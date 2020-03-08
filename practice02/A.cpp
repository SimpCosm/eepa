#include <iostream>
#include <map>
using namespace std;

int main() {
  string player, computer;
  map<string, int> prority;
  prority["Rock"] = 0;
  prority["Scissors"] = 1;
  prority["Paper"] = 2;
  string sentences[] = {"Continue again!", "You lose!", "You win!"};
  while(cin>>player>>computer) {
    int p = prority[player];
    int c = prority[computer];
    cout<<sentences[(p-c+3)%3]<<endl;
  }
  return 0;
}
