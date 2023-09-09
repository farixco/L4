#include <iostream>
using std::cout;
using std::endl;
using std::getline;

int mcd(int a, int b) {
   if (a > b && b == 0) {
      return a;
   } else {
      return mcd(b, a % b);
   }
}

void printArR(int* arSum, int length, int ndx = 0) {
   if (ndx == length) {
      cout << "]" <<endl;
   } else {
      if (ndx == 0) {
	 cout << "[ ";
      }
      cout << arSum[ndx] << " ";
      return printArR(arSum, length, ndx + 1);
   }
}

int* triangleSum(int* arSum, int length, int ndx = 1, int* arTemp = NULL) {
   if (length == 1) {
      cout << "[" << *arSum << "]" << endl;
      return arSum;
   } else if (ndx < length) {
      if (arTemp == NULL) {
	 printArR(arSum, length);
	 arTemp = new int[length - 1];
      }
      arTemp[ndx - 1] = arSum[ndx] + arSum[ndx - 1];
      return triangleSum(arSum, length, ndx + 1, arTemp);
   } else {
      return triangleSum(arTemp, length - 1, 1, NULL);
   }
}

char* reverseR(char* charAr, int length, int ndx = 0) {
   if (ndx == 0) {
      ndx = length / 2;
   }
   if (ndx == length) {
      return charAr;
   } else {
      char hodl = charAr[ndx];
      charAr[ndx] = charAr[length - 1 - ndx];
      charAr[length - 1 - ndx] = hodl;
      return reverseR(charAr, ndx + 1);
   }
}

bool prime(int num, int div = 2) {
   if (num % div == 0 && div < num) {
      return false;
   } else if (div == num) {
      return true;
   } else {
      return prime(num, div + 1);
   }
}

int fR(int n) {
    if (n < 1) return 1;
    int a = fR(n-1);
    int b = n / 2;
    int c = fR(b);
    int d = a * b + c;
    return d;
}

int f(int n) {
   int a = 1;
   for (int i = 0; i < n; ++i) {
      
   }
}
int main() {
   return 0;
}
