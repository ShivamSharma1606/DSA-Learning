#include<bits/stdc++.h>

using namespace std;

void nForest(int n);
void nForest1(int n);
void triangle(int n);
void ntriangle(int n);
void seeding(int n);
void nNumberTriangle(int n);
void nStarTriangle(int n);
void nStarTriangle2(int n);
void nStarDiamond(int n);
void nStarTriangle3(int n);
void nBinaryTriangle(int n);
void numberCrown(int n);
void nNumberTriangle2(int n);
void nLetterTriangle(int n);
void nLetterTriangle2(int n);
void alphaRamp(int n);
void alphaHill(int n);
void alphaTriangle(int n);
void symmetry(int n);
void symmetry2(int n);
void getStarPattern(int n);
void getNumberPattern(int n);

int main()
{
    int n;
    cin>>n;

    if(false){
        nForest(n);
    }
    if(false){
        nForest1(n);
    }
    if(false){
        triangle(n);
    }
    if(false){
        ntriangle(n);
    }
    if(false){
        seeding(n);
    }
    if(false){
        nNumberTriangle(n);
    }
    if(false){
        nStarTriangle(n);
    }
    if(false){
        nStarTriangle2(n);
    }
    if(false){
        nStarDiamond(n);
    }
    if(false){
        nStarTriangle3(n);
    }
    if(false){
        nBinaryTriangle(n);
    }
    if(false){
        numberCrown(n);
    }
    if(false){
        nNumberTriangle2(n);
    }
    if(false){
        nLetterTriangle(n);
    }
    if(false){
        nLetterTriangle2(n);
    }
    if(false){
        alphaRamp(n);
    }
    if(false){
        alphaHill(n);
    }
    if(false){
        alphaTriangle(n);
    }
    if(false){
        symmetry(n);
    }
    if(false){
        symmetry2(n);
    }
    if(false){
        getStarPattern(n);
    }
    if(true){
        getNumberPattern(n);
    }

    
    return 0;
}


void nForest(int n) {

	for(int i=0;i<n;i++){
          for (int j = 0; j < n; j++) {
            cout << "* ";
        }
		cout<<"\n";
    }	
}

void nForest1(int n) {
	
	for(int i=1;i<=n;i++){
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
		for (int j = 1; j <( n-i)*2; j++) {
            cout << "  ";
        }
		cout<<"\n";
    }
}

void triangle(int n) {
	for(int i=1;i<=n;i++){
        for (int j = 1; j <= i; j++) {
            cout << i<<" ";
        }
		for (int j = 1; j <( n-i)*2; j++) {
            cout << "  ";
        }
		cout<<"\n";
    }
}

void ntriangle(int n) {
	for(int i=1;i<=n;i++){
        for (int j = 1; j <= i; j++) {
            cout << j<<" ";
        }
		for (int j = 1; j <( n-i)*2; j++) {
            cout << "  ";
        }
		cout<<"\n";
    }
}

void seeding(int n) {
	for(int i=1;i<=n;i++){
        for (int j = 1; j <= n-i+1; j++) {
            cout << "* ";
        }
		for (int j = 1; j <i; j++) {
            cout << "  ";
        }
		cout<<"\n";
    }
}

void nNumberTriangle(int n) {
    for(int i=1;i<=n;i++){
        for (int j = 1; j <= n-i+1; j++) {
            cout << j<<" ";
        }
		for (int j = 1; j <i; j++) {
            cout << "  ";
        }
		cout<<"\n";
    }
}

void nStarTriangle(int n) {

	for(int i=1;i<=n;i++){
        for (int j = 1; j <= n-i; j++) {
            cout << " ";
        }
		for (int j = 1; j<=i; j++) {
            cout << "*";
        }
        for (int j = 2; j <= i; j++) {
            cout << "*";
        }
		for (int j = 2; j <n-i+1; j++) {
            cout << "  ";
        }
		cout<<"\n";
    }
    
}

void nStarTriangle2(int n) {
    for(int i=1;i<=n;i++){
        for (int j = 1; j < i; j++) {
            cout << " ";
        }
		for (int j = 1; j<=n-i; j++) {
            cout << "*";
        }
        for (int j = 0; j <= n-i; j++) {
            cout << "*";
        }
		for (int j = 1; j <i; j++) {
            cout << " ";
        }
		cout<<"\n";
    }
}

void nStarDiamond(int n) {
    // Write your code here.
    for(int i=1;i<=n;i++){
        for (int j = 1; j <= n-i; j++) {
            cout << " ";
        }
		for (int j = 1; j<=i; j++) {
            cout << "*";
        }
        for (int j = 2; j <= i; j++) {
            cout << "*";
        }
		for (int j = 2; j <n-i+1; j++) {
            cout << "  ";
        }
		cout<<"\n";
    }
    for(int i=1;i<=n;i++){
        for (int j = 1; j < i; j++) {
            cout << " ";
        }
		for (int j = 1; j<=n-i; j++) {
            cout << "*";
        }
        for (int j = 0; j <= n-i; j++) {
            cout << "*";
        }
		for (int j = 1; j <i; j++) {
            cout << " ";
        }
		cout<<"\n";
    }
}

void nStarTriangle3(int n) {
    for(int i=1;i<=n;i++){
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
		for (int j = 1; j <= (n-i); j++) {
            cout << " ";
        }
		cout<<"\n";
    }
    for(int i=1;i<=n;i++){
        for (int j = 1; j <=n-i; j++) {
            cout << "*";
        }
		for (int j = 1; j < (n-i); j++) {
            cout << " ";
        }
		cout<<"\n";
    }
}

void nBinaryTriangle(int n) {
    // Write your code here.
    int start=1;
    for(int i=1;i<=n;i++){
        if(i%2==0){
                start=0;
            }else{
                start=1; 
            }
        for (int j = 1; j <= i; j++) {
            cout<<start<<" ";
            start=1-start;
        }
		for (int j = 2; j <( n-i); j++) {
            cout << " ";
        }
		cout<<"\n";
        
    }
}

void numberCrown(int n) {
    // Write your code here.
    for(int i=1;i<=n;i++){
        for (int j = 1; j <= i; j++) {
            cout << j<<" ";
        }
		for (int j = 1; j <( n-i)*2; j++) {
            cout << " ";
        }
        for (int j = 0; j <=( n-i)*2; j++) {
            cout << " ";
        }
        for (int j = i; j >= 1; j--) {
            cout <<j  <<" ";
        }
		
		cout<<"\n";
    }
}

void nNumberTriangle2(int n) {
    int k=1;
    for(int i=1;i<=n;i++){
        for (int j = 1; j <= i; j++) {
            cout << k<<" ";
            k++;
        }
		for (int j = 1; j <( n-i)*2; j++) {
            cout << "  ";
        }
		cout<<"\n";
    }
}

void nLetterTriangle(int n) {
    for(int i=1;i<=n;i++){
        for (int j = 1; j <= i; j++) {
            char z='A';
            char k=z+j-1;
            cout << k <<" ";
        }
		for (int j = 1; j <( n-i)*2; j++) {
            cout << "  ";
        }
		cout<<"\n";
    }
}

void nLetterTriangle2(int n) {
    for(int i=1;i<=n;i++){
        for (int j = 1; j <= n-i+1; j++) {
            char z='A';
            char k=z+j-1;
            cout << k <<" ";
        }
		for (int j = 1; j <i; j++) {
            cout << "  ";
        }
		cout<<"\n";
    }
}

void alphaRamp(int n) {
    for(int i=1;i<=n;i++){
        for (int j = 1; j <= i; j++) {
            char z='A';
            char k=z+i-1;
            cout << k <<" ";
        }
		for (int j = 1; j <( n-i)*2; j++) {
            cout << "  ";
        }
		cout<<"\n";
    }
}

void alphaHill(int n) {
    for(int i=1;i<=n;i++){
        char a='A';        
        
        for (int j = 1; j <= n-i; j++) {
            cout << "  ";
        }
		for (int j = 1; j<=i; j++) {
            char k=a+j-1;
            cout << k<<" " ;
        }
        for (int j = i; j >= 2; j--) {
            char k=a+j-2;
            cout << k<<" ";
        }
		for (int j = 1; j <n-i+1; j++) {
            cout << "  ";
        }
		cout<<"\n";
    }
}

void alphaTriangle(int n) {
    
    for(int i=1;i<=n;i++){
        int m=n;
        for (int j = 1; j <= i; j++) {
            char z='A';
            char k=z+m-1;
            cout << k <<" ";
            m--;
        }
		
		cout<<"\n";
    }
}

void symmetry(int n) {
    for(int i=1;i<=n;i++){
        for (int j = 1; j <= n-i+1; j++) {
            cout << "* ";
        }
		for (int j = 1; j <i; j++) {
            cout << "  ";
        }
        for (int j = 1; j < i; j++) {
            cout << " ";
        }
        for (int j = 1; j < i; j++) {
            cout << " ";
        }
		for (int j = 1; j<=n-i+1; j++) {
            cout << "* ";
        }
		cout<<"\n";
    }
    for(int i=1;i<=n;i++){
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
		for (int j = 1; j <i-n+1; j++) {
            cout << "  ";
        }
        for (int j = 1; j < i-n; j++) {
            cout << " ";
        }
		for (int j = 1; j<=i; j++) {
            cout << "* ";
        }
		cout<<"\n";
    }
}

void symmetry2(int n) {
    for(int i=1;i<=n;i++){
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
		for (int j = 1; j <= (n-i)*2; j++) {
            cout << " ";
        }
        for (int j = 1; j <= (n-i)*2; j++) {
            cout << " ";
        }
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }		
		cout<<"\n";
		
    }
    for(int i=1;i<=n;i++){
        for (int j = 1; j <=n-i; j++) {
            cout << "* ";
        }
		for (int j = 1; j <= (n-i)*2; j++) {
            cout << " ";
        }
        for (int j = 1; j <= (n-i)*2; j++) {
            cout << " ";
        }
         for (int j = 1; j <=n-i; j++) {
            cout << "* ";
        }
		cout<<"\n";
    }
}

void getStarPattern(int n) {
   for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           if(i==0 || j==0||i==n-1||j==n-1){
               cout<<"*";
           }else{
               cout<<" ";
           }
       }
       cout<<endl;
       
   }
}

void getNumberPattern(int n) {
    int great=0;
    for(int i=0;i<2*n-1;i++){
            for (int j = 0; j <2* n-1; j++) {
                int x=(2*n-2)-i;
                int y=(2*n-2)-j;

                cout<<(n-min(min(i,j),min(x,y)));
        }
		cout<<"\n";
    }
}