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
  
  ifstream myfile ("crowd.tra");
  myfile.is_open();
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
	cout << g << '\n';
	free(baris);
	double* tra1;
	double* tra2;
	tra1 = (double*) malloc(states*sizeof(double));
	tra2 = (double*) malloc(states*sizeof(double));
	tra2[10633590] = 1;
	double rata2;
	double iter;
	double what = 0;
	cout << "oi";
 	do{
	what = 0;
 		for(int q=0; q<states;q++){tra1[q] = tra2[q]; tra2[q] = 0;}

  		for(int q=0; q<states;q++){


  			for(int r = barisnew[q]; r < barisnew[q+1]; r++){

  				if(tra1[q]!=0){
  				tra2[kolom[r]] += (isi[r] * tra1[q]);
				what++;
					}
			
			}	
  		}
	iterasi++;
	cout << what<< '\n';	
 	}while(iterasi < 10000);	
	cout << states << " " << elem << '\n';
    	

  return 0;
}
