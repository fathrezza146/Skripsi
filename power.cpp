//============================================================================
// Name        : luna.cpp
// Author      : mesmileyface
// Version     : more than C++11
// Copyright   : Sponsor me TANO*C
// Description : Fuckponsor me tank* you D:
//============================================================================

#include <stdio.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <math.h>


using namespace std;



int main (){

  int* baris;
  int* kolom;
  double* isi;
  int states;
  int elem;
  int iterasi = 10000;
  
  int g = 1;
  
  ifstream myfile ("crowd.tra");
  myfile.is_open();
  clock_t mulai, selesai;
  mulai = clock();
  myfile >> states >> elem;
kolom = (int*) malloc(elem*sizeof(int));
  baris = (int*) malloc(elem*sizeof(int));
  isi = (double*) malloc(elem*sizeof(double));
  int* barisnew;
  barisnew = (int*) malloc(elem*sizeof(int));
  for (int z = 0; z < elem; z++){
	myfile >> baris[z];
	myfile >> kolom[z];
	myfile >> isi[z];
		}
	


  
 
  	for (int z=0; z<=elem; z++){
  		if(baris[z] > baris[z-1]){
  			barisnew[g] = z;

  			g++;
  		}
  		if(z==elem){
  			barisnew[g] = elem; g++;}
  	}
 	//for(int b=0;b<5;b++) if(barisnew[b]!=0) cout <<barisnew[b]<<'\n';
	selesai = clock();
	double waktu = double(selesai - mulai) / double(CLOCKS_PER_SEC);
	free(baris);
	double* tra1;
	double* tra2;
	tra1 = (double*) malloc(states*sizeof(double));
	tra2 = (double*) malloc(states*sizeof(double));
	tra2[10633590] = 1;
	double rata2;
	double iter;
	double what;
	clock_t it1, it2;
	clock_t start, end;
	start = clock();
 	for(int lol=0;lol<iterasi;lol++){
		it1 = clock();
 		for(int q=0; q<states;q++){tra1[q] = tra2[q]; tra2[q] = 0;}

  		for(int q=0; q<states;q++){


  			for(int r = barisnew[q]; r < barisnew[q+1]; r++){

  				if(tra1[q]!=0){
  				tra2[kolom[r]] += (isi[r] * tra1[q]);
					}
			
			}	
  		}
		it2 = clock();
		iter += double(it2 - it1) / double(CLOCKS_PER_SEC); 
		if(lol == 5){
		rata2 = iter/lol;
		cout << "rata-rata waktu saat "<< lol<<"adalah" << rata2<<'\n';
		what =  double(it2 - start)/double(CLOCKS_PER_SEC);
		cout << what << '\n';
		continue;} 
		else if(lol == 50){
		rata2 = iter/lol;
		cout << "rata-rata waktu saat "<< lol<<"adalah" << rata2<<'\n';
		what =  double(it2 - start)/double(CLOCKS_PER_SEC);
		cout << what<< '\n';
		continue;} 
		else if(lol == 100){
		rata2 = iter/lol;
		cout << "rata-rata waktu saat "<< lol<<"adalah" << rata2<<'\n';
		what =  double(it2 - start)/double(CLOCKS_PER_SEC);
		cout << what<<'\n';
		continue;} 
		else if(lol == 500){
		rata2 = iter/lol;
		cout << "rata-rata waktu saat "<< lol<<"adalah" << rata2<<'\n';
		what =  double(it2 - start)/double(CLOCKS_PER_SEC);
		cout << what<<'\n';
		continue;} 
		else if(lol == 1000){
		rata2 = iter/lol;
		cout << "rata-rata waktu saat "<< lol<<"adalah" << rata2<<'\n';
		what =  double(it2 - start)/double(CLOCKS_PER_SEC);
		cout << what<<'\n';
		continue;} 
		else if(lol == 3000){
		rata2 = iter/lol;
		cout << "rata-rata waktu saat "<< lol<<"adalah" << rata2<<'\n';
		what =  double(it2 - start)/double(CLOCKS_PER_SEC);
		cout << what<<'\n';
		continue;} 
		else if(lol == 5000){
		rata2 = iter/lol;
		cout << "rata-rata waktu saat "<< lol<<"adalah" << rata2<<'\n';
		what =  double(it2 - start)/double(CLOCKS_PER_SEC);
		cout << what<<'\n';
		continue;} 
		else if(lol == 10000){
		rata2 = iter/lol;
		cout << "rata-rata waktu saat "<< lol<<"adalah" << rata2<<'\n';
		what =  double(it2 - start)/double(CLOCKS_PER_SEC);
		cout << what<<'\n';
		continue;} 
 	}	
	rata2 = iter/iterasi;
	end = clock();
	double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
	cout << states << " " << elem << '\n';
    	cout << "Waktu menyimppan matrix dalam array : " << fixed 
         <<waktu << " Waktu dalam "<< iterasi <<  " iterasi : " << fixed << time_taken; 
    	cout << " sec " << '\n'; 
	cout << "rata-rata per iterasi : " << rata2 << '\n';
	cout << "total : " << waktu + time_taken << '\n';

  return 0;
}
