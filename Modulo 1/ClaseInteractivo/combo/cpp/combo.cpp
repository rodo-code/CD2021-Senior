#include "combo.h"

using namespace std;

string guess_sequence(int N) {
  string S="";
  if(N==3){
    if(press("A")==1) S=S+"A";
    else if(press("B")==1) S=S+"B";
    else if(press("X")==1) S=S+"X";
    else S="Y";

    if(press(S+"A")==2) S=S+"A";
    else if(press(S+"B")==2) S=S+"B";
    else if(press(S+"X")==2) S=S+"X";
    else S=S+"Y";

    if(press(S+"A")==3) S=S+"A";
    else if(press(S+"B")==3) S=S+"B";
    else if(press(S+"X")==3) S=S+"X";
    else S=S+"Y";
  }
  return S;
}
