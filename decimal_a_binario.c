#include<stdio.h>

int main(){

	int binario(int);
	int n;

	printf("Introduzca el primer numero Binario");
	scanf("%d",&n);

	binario(n);

}
int binario(int n){
	if(n>1){
		binario(n/2);
	}
	printf("%d",n%2);
}
