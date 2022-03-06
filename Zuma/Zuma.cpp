
#include <iostream>
#include <vector>


void Zuma(std::vector<int> sir)
{

	int n; // Numarul de bile din secventa
	std::cin >> n;
	std::cout << "Introduce-ti pe rand culoarea bilelor(0-9) apasand enter dupa fiecare\n";
	for (int i = 1; i <= n; i++)
	{
		int l;
		std::cin >> l;
		sir.push_back(l);	
	}

	std::cout << "Sirul dvs. este: \n";
	for (int i = 0; i <= n - 1; i++)
	{
		std::cout << sir[i]<<" ";
	}

	std::cout << std::endl;
	int contor=1 ;
	int smax=1 ;// lungimea secventei maxime
	int pozitie = 1;//Pozitia din vector a ultimului element din secventa maxima

	do
	{
		smax = 0;
		// Parcurgem vectorul si comparam elementul din dreapta cu cel din stanga
		//Daca sunt egale, contorul se incrementeaza, apoi se compara smax(secventa maxima);
		for (int i = 1; i < n; i++)
		{
			if (sir[i] == sir[i - 1])
				contor++;
			else 
				contor = 1;
			if (smax < contor)
			{
				smax = contor;
				pozitie = i;
			}
		}

		// Daca avem o secvanta de lungime cel putin egala cu 3 elemente iteram vectorul de la pozitia inceputului de secventa de smax ori;
		if (smax >= 3)
		{
			 
			for (int i = 0; i <smax; i++)
			{
				int k = i;
				for (int j = pozitie-smax+1 ; j < n-1; j++)
				{
					sir[j] = sir[j+1];	
				}
				n--;
			}	
			std::cout << "Secventa devine \n";
			for (int i = 0; i <= n - 1; i++)
			{
					std::cout << sir[i]<<" ";
			}
				std::cout<<std::endl;
		}
		else
		{
				std::cout << " Jocul s-a terminat";
		}
	} while (smax>= 3);

}


int main()
{
	std::vector<int>sir;
	std::cout << "Introduce-ti numarul de bile ce-l va contine sirul \n";
	Zuma(sir);
	return 0;
}



//Irinuca a descoperit un nou joc pe calculator.
// Pe ecran sunt plasate pe o linie n bile colorate.
// Culorile bilelor sunt codificate cu numere naturale.
// Un sub?ir de bile al?turate având toate aceea?i culoare se nume?te secven??.
// O secven?? va con?ine num?rul maxim de bile al?turate având aceea?i culoare.
// Lungimea unei secven?e este egal? cu num?rul de bile din care este compus?.
//Irinuca are la dispozi?ie un arc special.Tr?gând cu arcul asupra unei bile, 
// dac? aceasta face parte dintr - o secven?? de lungime cel pu?in egal? cu 3, 
// întreaga secven?? va fi eliminat?, iar bilele din dreapta secven?ei se vor deplasa spre stânga pentru a
//  umple “golul” l?sat de bilele eliminate.
// Dac? imediat în stânga ?i în dreapta secven?ei eliminate se g?seau dou? secven?e având aceea?i 
// culoare ?i dac? secven?a ob?inut? din unirea acestora dup? eliminare are o lungime cel pu?in egal? cu 3,
//  atunci va fi ?i ea eliminat? la rândul ei.Procesul continu? pân? când secven?ele din stânga 
// ?i dreapta unei secven?e tocmai eliminate au culori diferite sau pân? când lungimea secven?ei 
// ob?inute prin al?turare este mai mic? decât 3 sau pân? când în stânga ori în dreapta unei secven?e eliminat
// e nu se mai g?sesc bile sau pân? sunt eliminate toate bilele de pe ecran.
//Scopul jocului este de a elimina cât mai multe bile de pe ecran.
// Cum Irinuca înc? nu se pricepe prea bine la acest joc ?i 
// - a stabilit o strategie.
// Va trage cu arcul întotdeauna asupra unei bile ce 
// face parte din secven?a de lungime maxim? de pe ecran.
// Dac? sunt mai multe astfel de secven?e,
//  ea va alege cea mai din 
// stânga secven?? de lungime maxim?.
// Dac? toate secven?ele de pe ecran au lungimi mai mici decât 3, Irinuca nu va mai putea elimina nici una din ele ?i jocul se încheie.
//De exemplu, dac? ?irul ini?ial de bile este :
//5 1 3 3 2 2 2 2 3 1 1 5 6 4 4 4 4 4 7
//Irinuca va ac?iona asupra unei bile de culoare 2.  Prin eliminare se ob?ine ?irul de bile
//5 1 3 3 3 1 1 5 6 4 4 4 4 7
//din care se elimin? ?i secven?a de bile de culoare 3 ob?inându - se ?irul de bile
//5 1 1 1 5 6 4 4 4 4 7
//din care se elimin? ?i secven?a de culoare 1.
//5 5 6 4 4 4 4 7
//Cum secven?a de bile de culoare 5 nu este suficient de lung?, aceasta nu se mai elimin?.Acum Irinuca trage asupra unei bile de culoare 4 ?i ob?ine
//5 5 6 7
//dar cum în stânga ?i în dreapta secven?ei eliminate sunt secven?e de culori diferite, nu se va mai elimina nici o secven??.Jocul se încheie deoarece nu mai exist? nici o secven?? de lungime cel pu?in 3 asupra c?reia s? se poat? trage.
//Cerin??:
//Cunoscând num?rul de bile ?i culorile fiec?rei bile de pe ecran se cere s? se determine :
//1. num?rul de secven?e de bile care se aflau ini?ial pe ecran;
//2. num?rul de bile care r?mân neeliminate de pe ecran ?i culorile bilelor r?mase în ordine pe ecran la finalul jocului.
//Date de intrare :
//Se citesc N numere de la tastatur? care reprezinta ?irul de bile de la începutul jocului.
//Numarul maxim de culori este de 10(0-9)