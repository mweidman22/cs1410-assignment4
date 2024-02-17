#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <array>
#include <random>
#include <sstream>
using namespace std;
stringstream sout;
enum class DieSide { // Lists the sides of a die
  One, Two, Three, Four, Five, Six
};
struct HistBar {// Represents a bar in a histogram
  int count;
  enum DieSide label;
};
default_random_engine en;
uniform_int_distribution<> r{0, 5};
void rollDice(HistBar h[], int n);
void rollDice(HistBar h[], int n = 100){
  //uniform_int_distribution<> r{0, 5};
  for(int i = 1; i < n; i++){
    h[r(en)].count++;
  }
}
string histogram(HistBar h[], char c);
string histogram(HistBar h[], char c = '*'){
  sout.str("") ;
  for(int i =0 ; i < 5; i++){
    if(i == 1) {sout << h[i].count << " TWOs: ";}
      else if(i == 2) {sout << h[i].count <<" THREEs: ";}
      else if(i == 0) {sout << h[i].count << " ONEs: ";}
      else if(i == 3) {sout << h[i].count << " FOURs: ";}
      else if(i == 4) {sout << h[i].count << " FIVES: ";}
      else if (i == 5){sout <<h[i].count << " SIXes: ";}
    sout <<string(h[i].count, c) << endl;
    }
    return sout.str();
}
void reset(HistBar h[]);
void reset(HistBar h[]){
for(int i =0 ; i < 5; i++){
  h[i].count = 0;
}
}
int main (){
  int setting;
  struct HistBar h[6]= {{0, DieSide::One},{0, DieSide::Two},{0, DieSide::Three},{3, DieSide::Four},{4, DieSide::Five},{5, DieSide::Six}};
  do{
    cout << "DICE ROLLING SIMULATION" <<endl;
    cout << "=======================" <<endl;
    cout << "1. Roll dice" <<endl;
    cout << "2. Display histogram"<< endl;
    cout << "3. Reset histogram" << endl;
    cout << "4. Quit program" << endl;
    cin >> setting;
    if (setting == 1){rollDice(h);}
    else if (setting == 2){cout << histogram(h);}
    else if (setting == 3){reset(h);}
  } while(setting != 4);
}