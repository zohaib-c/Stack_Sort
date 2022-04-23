#include <iostream>
#include <stack>
#include <fstream>

using namespace std;

void printStack (stack<int> s){
  if (s.empty()){
    return;
  }
  int num = s.top();
  s.pop();
  printStack(s);

  cout << num << " ";
}

void sortInsert(stack<int>& s, int valueToInsert){
  if (s.size() == 0 || valueToInsert > s.top()){
    s.push(valueToInsert);
  }
  else{
    int temp = s.top();
    s.pop();
    sortInsert(s, valueToInsert);

    s.push(temp);
  }
}

void sortStack(stack<int>& s){
  if (s.size() < 2){
    return;
  }
  else{
    int temp = s.top();
    s.pop();

    sortStack(s);
    sortInsert(s, temp);
  }
}

bool readFile(string fileName, stack<int> &s){
    ifstream file;
    file.open(fileName);

    if (!file.is_open()){
      cout << "an error occurred: could not open input file " << fileName;
      return false;
    }

    int num;
    while (!file.eof()){
      file >> num;
      if (!file.fail()){
        s.push(num);
      }
      else if (file.fail()){
        file.clear();
        file.ignore(10000000, '\n');
      }
    }

file.close();
return true;
}


int main(int argc, char *argv[]) {
  stack<int> s;
  if (argc > 1){
    string fileName(argv[1]);
    readFile(fileName, s);
  }
  else{
    cout << "an error occurred: no input file name given";
    return 1;
  }

  sortStack(s);
  printStack(s);

return 0;
}