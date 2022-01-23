#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool onQuery = false;
vector<char> tempvect;
vector<vector<char> > puzzle;
int i, j, k, n, m, row, col, NRow, NCol, dirPrint;
//barat laut = 0, barat = 1, barat daya = 2, utara = 3, selatan = 4, timur laut = 5, timur = 6, tenggara = 7    
int dirX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dirY[] = {-1, 0, 1, -1, 1, -1, 0, 1};
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

bool searchWord(vector<vector<char> > puzzle, int row, int col, string line, int NRow, int Ncol){
    if (puzzle[row][col] != line[0]){
        return false;
    }
    int len = line.length();
    for (int dir = 0; dir < 8; dir++){
        int rowArrow = row + dirY[dir];
        int colArrow = col + dirX[dir];

        for (k = 1; k < len; k++){
            if (rowArrow >= NRow || rowArrow < 0 || colArrow >= NCol || colArrow < 0){
                break;
            }
            if (puzzle[rowArrow][colArrow] != line[k]){
                break;
            }
            rowArrow += dirY[dir];
            colArrow += dirX[dir];
        }
        
        if (k == len){ // kata ditemukan
            rowArrow = row;
            colArrow = col;
            char printFound[puzzle.size()][puzzle[0].size()];
            for (int i = 0; i < puzzle.size(); i++){
                for (int j = 0; j < puzzle[i].size(); j++){
                    printFound[i][j] = '-';
                }
            }
            for (k = 0; k < len; k++){
                printFound[rowArrow][colArrow] = puzzle[rowArrow][colArrow];
                rowArrow += dirY[dir];
                colArrow += dirX[dir];
            }
            for (int i = 0; i < puzzle.size(); i++) {
                for (int j = 0; j < puzzle[i].size(); j++){
                    cout << printFound[i][j];
                }
                cout << endl;        
            }
            return true;
        }
    }
    return false;
}


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
                NRow = puzzle.size();
                NCol = puzzle[0].size();
                for (row = 0; row < NRow; row++){
                    for (col = 0; col < NCol; col++){
                        if (searchWord(puzzle, row, col, line, NRow, NCol)){
                            cout << "kata ditemukan di  "<< row << ", " << col << endl;
                        }
                    }
                }

            }

        } 
        //printPuzzle();
        myfile.close();
    }
    else cout << "Unable to open test file";

    return 0;
}