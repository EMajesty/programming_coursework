#include <iostream>
using namespace std;

class Point
{
    public:
        int x;
        int y;

    Point()
    {
        alustaPiste();
    }

    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    Point(Point& p)
    {
        this->x = p.x;
        this->y = p.y;
    }

    void alustaPiste()
    {
        x = 0;
        y = 0;
    }
};

//Määritellään Vector luokka
class Vector
{
    private: //Yksityiset jäsenmuuttujat
        Point start;
        Point end;


    public: //Julkiset jäsenfunktiot

    //Perusrakentaja, alustaa arvot 0:lla
    Vector()
    {
        alustaVektori();
    }

    //Rakentaja, alustaa arvot parametreilla
    Vector(Point start, Point end)
    {
        this->start = start;
        this->end = end;
    }

    //Rakentaja, kopioi arvot toisesta oliosta
    Vector(Vector& v)
    {
        this->start = v.start;
        this->end = v.end;
    }

    //MUUT
    void tulostaVektori()
    {
        //cout << "start:" << start << "," << " end:" << end << "," << endl;
    }

    void alustaVektori()
    {
        start.alustaPiste();
        end.alustaPiste();

        tulostaVektori();
    }

    //HUOMAA, jos parametrit ovat samannimiset kuin jäsenmuuttujat
    // viitataan jäsenmuuttujiin this-> operaatiolla
    void aseta(Point start, Point end)
    {
        this->start = start;
        this->end = end;
    }



}; // <-- HUOM! Luokan määrittely päättyy ;


int main()
{
    Vector v1; //Olio v1



    //v1.x = 0; << EI SALLITTU ENÄÄ

    //v1.alustaVektori();

    v1.aseta(///);
    v1.tulostaVektori();

    Vector v2(v1); //Alustetaan uusi vektori V1 arvoilla
    v2.tulostaVektori();


    Vector v3(///); //Alustetaan uusi määritetyillä arvoilla
    v3.tulostaVektori();
}
