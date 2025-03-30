
#include "task4.h"
#include <iostream>
void calculare_timp_optim(int n, int m, const OrderedSet<Duck>& ducks, const OrderedSet<Lane>& lanes, double timpi[])
{
	int index = 0;
	for (int i = 0; i < n;i++)
		for (int j = 0;j < m;j++)
		{
			Duck d = ducks.getElem(i);
			Lane l = lanes.getElem(j);
			timpi[index++] =(double) (2.0 * l.getLength() / d.getSpeed());

		}
	bubbleSort_timp(timpi, index);

}
void bubbleSort_timp(double timp[], int n)
{
	for (int i = 0;i < n;i++)
		for (int j = 0; j < n - i - 1;j++)
			if (timp[j] > timp[j + 1])
			{
				double aux = timp[j];
				timp[j] = timp[j+1];
				timp[j+1] = aux;
			}
}
bool valid(double timp ,int n, int m, const OrderedSet<Duck>& ducks, const OrderedSet<Lane>& lanes)
{

	bool culoar[100] = { 0 };  //vectorul de culoare, semnificatia valoriilor:ocupat sau nu
	int count = 0;      //contor de M rate
	for (int i = 0; i < n; i++) { //parcurgem ratele

		Duck d = ducks.getElem(i);
		for (int j = 0; j < m; j++) {     //parcurgem culoarele

			Lane l = lanes.getElem(j);

			double t = (double)(l.getLength() + l.getLength()) / d.getSpeed();    //timpul calculat ca distanta de pe pozitia j, si viteza ratei respective
			if (t <= timp && !culoar[j]) {       // Dacă timpul e valid și culoarul nu este ocupat
				culoar[j] = true;       // Ocupăm culoarul
				count++;          // Incrementăm numărul de rațe alese
				break;     //ne oprim ca nu folosim aceiasi rata de mai multe ori
			}
		}
		if (count >= m) break;  // Dacă am selectat deja M rațe, ieșim
	}
	return count >= m;  // Returnăm true dacă am selectat M rațe, altfel false

}

double cautare(int n, int m, const OrderedSet<Duck>& ducks, const OrderedSet<Lane>& lanes, double timpi[])
{
	calculare_timp_optim(n,m, ducks,lanes,timpi);
	double st = 0, dr = timpi[n * m - 1], timp_valid=0.0;
	//dr ia ultima valoare din lista de timpi
	while (dr - st > 0.0001) {  // fac asta ca sa fie diferenta de timp ff mica
		double t = (st + dr) / 2.0;
		if (valid( t,  n, m, ducks,lanes)) {
			timp_valid = t;
			dr = t;  // daca timpul e valid inseamna  ca e posibil sa mai gasim un timp mai mic deci cautam in [st,t]
		}
		else {
			st = t;  // analogie inversa
		}
	}

	return timp_valid;
}
