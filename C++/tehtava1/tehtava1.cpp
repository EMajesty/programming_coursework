/**
 * @file main.cpp
 * @brief Teht�v� 1.
 * @author Jari Isohanni
 * Contact: jari.isohanni@centria.fi
 */

#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

//M��ritell��n PII
#define PII 3.1415

/** �L� MUUTA N�IT� - ALKU **/
bool areFloatsEquals(double a, double b);
void testaaTehtava1(double r, double pii);
double testaaTehtava2(double kanta, double korkeus);
void testaaTehtava3(int tulos);

/** �L� MUUTA N�IT� - LOPPU **/
int main()
{
    cout << "Hei, t�ss� ensimm�iset teht�v�t, t�m� koodi pit�isi saada tulostamaan 10 kertaa OK" << endl;

    /*T�ss� riviss� on jotain vikaa, pit�isi tulostaa "T1. - OK" */
    cout << "T1. - OK << endl";

    /*Korjaa seuraava rivi niin, ett� m��rittelet muuttujan (arvolla 5.0) sek� luot vakion PII (arvolla 3.1415), 
    jotta laskuri laskee oikein ympyr�n s�teen*/
    double ympyr�n_s�de = 5.0;
    testaaTehtava1(ympyr�n_s�de, PII);

    int x, y;
    x = (int) 5.0;
    y = (int) 5.0;
    double z = testaaTehtava2(x, y); //T�ss� on joitain vikaa, yrit�mme laskea kolmion korkeutta



    int a = 10;
    int b = 190;
    int c = 4;
    int tulos = (a + b) * c; //T�st� pit�isi saada tulos 800
    testaaTehtava3(tulos);


    float ika = 11; //T�ss� on jotain vikaa, pit�isi luoda muuttuja jossa henkil�n ik�
    cout << "T4. - OK" << endl;


    cout << "Anna lukuarvo: ";
    // Toteuta t�h�n lauseke joka ottaa sy�teen k�ytt�j�lt� numero (cin), muuttujaan syote
    int syote;
    cin >> syote;

    cout << "Annoit numeron: " << syote << endl;
    cout << "T5. - OK" << endl;


    return 0; // Palautetaan 0 jos ohjelma suoriutui onnistuneesti
}

/** �L� MUUTA T�ST� ALASP�IN **/

void testaaTehtava3(int tulos)
{
    if (tulos == 800)
    {
        cout << "T3. - OK" << endl;
    }
    else
        cout << "T3. - FAILED" << endl;
}

double testaaTehtava2(double kanta, double korkeus)
{
    double ala = (kanta * korkeus) / 2.0;
    cout << "T2. - OK" << endl;
    return ala;
}

void testaaTehtava1(double r, double pii)
{
    if (areFloatsEquals(2 * r * pii, 2 * 5.0 * pii))
    {
        cout << "T1. - OK" << endl;
    }
    else
        cout << "T1. - FAILED" << endl;
}

bool areFloatsEquals(double a, double b)
{
    return fabs(a - b) <= std::numeric_limits<double>::epsilon();
}