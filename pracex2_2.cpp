#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;

void sort(float x[], int N){
	for(int i = 1; i < N; i++){
		for(int j = i; j > 0; j--){
			if(x[j] < x[j-1]){
				float temp = x[j];
				x[j] = x[j-1];
				x[j-1] = temp;
			}else{
				break;
			} 
		}
	}
}

int main(){
	float x[]={};
	ifstream source("score3.txt");
	string line;
	int i=0,n=0;
	while(getline(source,line)){
		x[i]=atof(line.c_str());
		i++;
	}
	sort(x,i);
	ofstream dest("rank.txt");
	//dest << x[i-1]<<"="<<n+1<<"\n";
	for(int j=i-1;j>=0;j--){
		if(x[j]==x[j+1]){
			dest << x[j]<<"="<<n<<"\n";
		}
		else{
			dest << x[j]<<"="<<i-j<<"\n";
			n=i-j;
		}
	}
	dest.close();
	return 0;
}

