#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <time.h>

using namespace std;

bool onQuery = false;
vector<char> tempvect;
vector<vector<char> > puzzle;
int i, j, k, n, m, row, col, NRow, NCol, arahPrint;
int perbandingan = 0;
//array yang menunjukan arah pergerakan huruf, barat laut = 0, barat = 1, barat daya = 2, utara = 3, selatan = 4, timur laut = 5, timur = 6, tenggara = 7    
int arahX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int arahY[] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool found;

// prosedur untuk mengecek apakah sudah masuk query word yang harus diacri
void isOnQuery(string line){
    if (line == ""){
        onQuery = true;
    }
}

//prosedur untuk mencetak puzzle ke layar
void printPuzzle(){
    for (int i = 0; i < puzzle.size(); i++) {
        for (int j = 0; j < puzzle[i].size(); j++){
            cout << puzzle[i][j];
        }
        cout << endl;        
    }
}

//fungsi untuk mencari kata yang dicari
bool searchWord(vector<vector<char> > puzzle, int row, int col, string line, int NRow, int Ncol){
    // apabila huruf pertama yang dicek pada puzzle tidak cocok dengan huruf pertama masukan, maka return false
    perbandingan++;
    if (puzzle[row][col] != line[0]){
        return false;
    }
    int len = line.length();
    // mengecek kata dalam 8 arah
    for (int arah = 0; arah < 8; arah++){
        int rowArrow = row + arahY[arah];
        int colArrow = col + arahX[arah];

        for (k = 1; k < len; k++){
            perbandingan++;
            // apabila keluar dari batas row atau column, maka break
            if (rowArrow >= NRow || rowArrow < 0 || colArrow >= NCol || colArrow < 0){
                break;
            }
            // apabila huruf yang dicek tidak cocok, maka break
            if (puzzle[rowArrow][colArrow] != line[k]){
                break;
            }
            // lakukan penggeseran huruf sesuai dengan arah
            rowArrow += arahY[arah];
            colArrow += arahX[arah];
        }
        
        if (k == len){ // kata ditemukan apabila panjangnya sama
            rowArrow = row;
            colArrow = col;
            // inisiasi matrix yang akan ditampilkan
            char printFound[puzzle.size()][puzzle[0].size()];
            for (int i = 0; i < puzzle.size(); i++){
                for (int j = 0; j < puzzle[i].size(); j++){
                    printFound[i][j] = '-';
                }
            }
            // mengisi matrix yang ditampikan sesuai dengan kata yang ditemukan
            for (k = 0; k < len; k++){
                printFound[rowArrow][colArrow] = puzzle[rowArrow][colArrow];
                rowArrow += arahY[arah];
                colArrow += arahX[arah];
            }
            // mencetak matrix dengan kata yang ditemukan sesuai posisi
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
    // melakukan pembacaan file
    string filename;
    string directory = "../test/";
    cout << "masukkan nama file: ";
    cin >> filename;
    ifstream myfile (directory+filename);
    clock_t start;
    if (myfile.is_open()){
        // melakukan pembacaan setiap baris masukan
        while (getline(myfile, line)){
            // cek apakah sudah masuk query words
            isOnQuery(line);
            if (!onQuery){
                // jika belum, maka lakukan pengisian vector puzzle
                for(i = 0; i != line.length(); i++){
                    // jika huruf yang dibaca bukan spasi, maka masukkan ke vector
                    if (line[i] != ' '){
                        tempvect.push_back(line[i]);
                    }
                }
                puzzle.push_back(tempvect);
                tempvect.clear();

            }
            // jika sudah masuk query dan bukan sebuah baris kosong, maka lakukan pengecekan mulai dari huruf ke huruf dalam puzzle
            else if(onQuery && line != ""){
                NRow = puzzle.size();
                NCol = puzzle[0].size();
                start = clock();
                for (row = 0; row < NRow; row++){
                    for (col = 0; col < NCol; col++){
                        if (searchWord(puzzle, row, col, line, NRow, NCol)){
                            cout << "Kata " << line << " ditemukan di  "<< row << ", " << col << endl;
                        }
                    }
                }

            }

        }
        cout << "Total perbandingan huruf yang dilakukan " << perbandingan << " kali"<< endl;
        clock_t end = clock();
        double elapsed = double(end - start)/CLOCKS_PER_SEC;
        cout << "Time measured: "<< elapsed/(0.000001) << " microseconds" << endl;
        
        myfile.close();
    }
    else cout << "Terjadi kesalahan saat membuka file, mungkin salah nama file.";

    return 0;
}