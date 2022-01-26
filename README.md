# Tugas Kecil 1 IF2211 Strategi Algoritma - word-search-puzzle
## Deskripsi
_word-search-puzzle_ merupakan sebuah permainan untuk mencari sebuah kata pada puzzle huruf yang dirangkai secara acak pada matrix dua dimensi. Program dalam repository ini bertujuan untuk menyelesaikan puzzle dengan metode brute force. Program akan menerima masukan berupa nama file yang berisikan puzzle dan kata kunci yang akan dicari. Apabila ditemukan, maka program akan menampilkan kata yang ditemukan ke layar.

## Fitur
- Menerima input nama file untuk melakukan test
- Melakukan pencarian kata kunci dan memberikan output ke layar apabila ditemukan
- Menampilkan total banyaknya perbandingan kata dan lama waktu pencarian kata kunci

## Persyaratan
Program _word search puzzle_ ini dibuat dengan bahasa c++ dan compiler **GNU C++ versi 4.2.**. Progra ini dibuat dan diuji dalam _operating System_ MAC OS 12 Catalina. Apabila ingin menjalankan program ini, hendaknya melakukan _compile_ ulang pada program `main.cpp`

## Cara Menjalankan Program
Sebelum menjalankan program, _clone repository_ ke dalam folder lokal.
untuk melakukan `compile` ulang pada program `main.cpp` masuk ke parent apabila menggunakan Mac, gunakan perintah `g++ -o bin/main src/main.cpp` , apabila menggunakan windows gunakan perintah `g++ -o bin/main.exe src/main.cpp`

## Menjalankan executable file
1. Buka folder program pada terminal 
2. Lalu masuk ke dalam folder bin dengan perintah `cd bin`
3. Jalankan file `main` dengan perintah `./main` atau `main.exe` dengan perintah `main.exe`
4. Masukkan nama file, contohnya `test1.txt`

## File test
1. Small: test1.txt, test3.txt, test9.txt
2. Medium: test2.txt, test4.txt, test5.txt
3. Large: test6.txt, test7.txt, test8.txt

### Status
Program ini telah selesai dibuat dan dikembangkan untuk memenuhi spesifikasi Tugas Kecil 1 IF2211 Strategi Algoritma

| Poin | Ya | Tidak |
|---|---|---|
| Program berhasil dikompilasi tanpa kesalahan (no syntax error) | v | |
| Program berhasil running | v | |
| Program dapat membaca file masukan dan menuliskan luaran | v | |
| Program berhasil menemukan semua kata di dalam puzzle | v | |

## Pembuat
Nama   : Fikri Khoiron Fadhila\
NIM    : 13520056\
Kelas  : K02