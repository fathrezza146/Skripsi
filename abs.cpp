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
  int iterasi = 1;
  
  int g = 1;
  
  ifstream myfile ("rb.tra");
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
 	//for(int g=0;g<5;g++) cout << baris[g]<< " " << kolom[g]<<" "<<isi[g]<<" "<<barisnew[g]<<'\n';
	selesai = clock();
	double waktu = double(selesai - mulai) / double(CLOCKS_PER_SEC);
	free(baris);
	double* tra1;
 	 double* tra2;
  	tra1 = (double*) malloc(states*sizeof(double));
  	tra2 = (double*) malloc(states*sizeof(double));
	tra2[0] = 1;
 	double epsilon = 1e-6;
	double error;
	double* absolut;
 	absolut = (double*) malloc(states*sizeof(double));
	double nunut;
	double iter;
	double rata2;
	clock_t it1, it2;
	clock_t start, end;
	start = clock();
	do{
		it1 = clock();
 		for(int q=0; q<states;q++){tra1[q] = tra2[q]; tra2[q] = 0;}

  		for(int q=0; q<states;q++){
  			for(int r = barisnew[q]; r < barisnew[q+1]; r++){
  				if(tra1[q]!=0){
  				tra2[kolom[r]] += (isi[r] * tra1[q]);
				}
			
			}
			
			
  		}
		error = 0;
		for(int ber = 0; ber<states;ber++){
			//konvergensi absolut
				absolut[ber] = tra2[ber]-tra1[ber];
				nunut += (absolut[ber]*absolut[ber]);
				}
			error = sqrt(nunut);
			nunut = 0;
	it2 = clock();
	iter += double(it2 - it1) / double(CLOCKS_PER_SEC); 
	cout << error << '\n';
	iterasi++;
 	} while(error > epsilon && iterasi < 10000);
	
	end = clock();
	rata2 = iter/iterasi;
	double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
	cout << states << " " << elem << '\n';
    	cout << "Waktu menyimppan matrix dalam array : " << fixed 
         <<waktu << '\n' << "Stationary ditemukan dalam "<< iterasi <<  " dengan durasi : " << fixed << time_taken; 
    	cout << " sec " << '\n'; 
	cout << "rata-rata per iterasi : " << rata2 << '\n';
	cout << "total : " << waktu + time_taken << '\n';

  return 0;
}
