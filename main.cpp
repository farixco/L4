#include <iostream>
using std::cout;
using std::endl;
using std::cin;
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
      return reverseR(charAr, length, ndx + 1);
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
   if (n <= 1) {
      return 1;
   }
   int b = 0;
   int c = 1;
   int d = 1 * b + c;
   /*
    * La función solo se puede replicar eficientemente utilizando es
    * tructuras de datos. Esto es debido a que el cálculo de c recur
    * sivo requiere de memoria más allá de la inmediata (a diferenci
    * a de lo que sucede con a). Por esta razón, no se puede adaptar
    * perfectamente a una estructura lineal con límites de memoria
    * bien conocidos. Podría hacer el array lo suficientemente grand
    * e para cualquier número de iteraciones pero no sé si está dent
    * ro de los lineamientos del ejercicio añadir más argumentos.
    */

   // Me acabo de dar cuenta que igual supera el límite de int despu
   // és de la 16va iteración, entonces tiene más que suficiente esp
   // acio como para demostrar igualdad.
   
   int* aStorage = new int[100];
   int nTmp = 1;
   while (nTmp < n) {
      aStorage[nTmp - 1] = d;
      if ((nTmp - 1) % 2 == 0) {
	 c = aStorage[b];
	 ++b;
      }
      d = aStorage[nTmp - 1] * b + c;
      ++nTmp;
   }
   return d;
}

int main() {
   std::string txt;
   int n1, n2;
   cout << "E1: Ingrese números de MCD." << endl;
   getline(cin, txt);
   n1 = std::stoi(txt);
   getline(cin, txt);
   n2 = std::stoi(txt);
   cout << "MCD de " << n1 << " y " << n2 << ": " << mcd(n1, n2) << endl;
   cout << "E2: ¿Qué tan largo quiere su arreglo?" << endl;
   getline(cin, txt);
   n2 = std::stoi(txt);
   int* arNum = new int[n2];
   for (int i = 0; i < n2; ++i) {
      cout << "Ingrese el No. " << i << "." << endl;
      getline(cin, txt);
      arNum[i] = std::stoi(txt);
   }
   arNum = triangleSum(arNum, n2);
   cout << "E3: Ingrese texto." << endl;
   getline(cin, txt);
   char* charAr = new char[txt.length()];
   for (int i = 0; i < txt.length(); ++i) {
      charAr[i] = txt[i];
   }
   charAr = reverseR(charAr, txt.length());
   for (int i = 0; i < txt.length(); ++i) {
      cout << charAr[i];
   }
   cout << endl;
   cout << "E4: Ingrese un número para verificar si es primo o no." << endl;
   getline(cin, txt);
   n1 = std::stoi(txt);
   cout << "¿Primo? " << prime(n1) << endl;
   cout << "E5: Ingrese número de iteraciones para revisar." << endl;
   getline(cin, txt);
   n2 = std::stoi(txt);
   for (int i = 0; i < n2; ++i) {
      cout << i << ". It: " << f(i) << " Re: " << fR(i) << endl;
   }
   return 0;
}
