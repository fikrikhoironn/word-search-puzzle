#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool onQuery = false;
vector<char> tempvect;
vector<vector<char> > puzzle;
int i, j, k, n, m;
bool found;


void isOnQuery(string line){
    if (line == ""){
        onQuery = true;
    }
}

void printPuzzle(){
    for (int i = 0; i < puzzle.size(); i++) {
        for (int j = 0; j < puzzle[i].size(); j++){
            cout << puzzle[i][j];
        }
        cout << endl;        
    }
}

// void horizontalRight(string line){
// secara horizontal ke kanan
//     for (k = 0; k < puzzle.size(); k+=1){
//         n = puzzle[k].size();
//         m = line.length();
//         i = 0;
//         found = false;
//         while((i <= n-m) && !found) {
//             j = 0;
//             while ((j <= m) && (line[j] == puzzle[k][i+j])){
//                 j += 1;
//             }
//             if (j == m){
//                 found = true;
//             }
//             else{
//                 i += 1;
//             } 
//         }
//         if (found){
//             for (j = i; j < m+i; j++)
//             {
//                 cout << puzzle[k][j];
//             }
//             cout << endl;
//         }
//     }    

// }

int main(){
    string line;

    ifstream myfile ("test.txt");
    if (myfile.is_open()){
        while (getline(myfile, line)){
            isOnQuery(line);
            if (!onQuery){
                for(i = 0; i != line.length(); i++){
                    if (line[i] != ' '){
                        tempvect.push_back(line[i]);
                    }
                }
                puzzle.push_back(tempvect);
                tempvect.clear();

            }
            else if(onQuery && line != ""){
                // horizontalRight(line);
            }

        } 
        printPuzzle();
        myfile.close();
    }
    else cout << "Unable to open test file";

    return 0;
}