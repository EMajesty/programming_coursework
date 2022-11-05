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

//M��ritell��n Vector luokka
class Vector
{
    private: //Yksityiset j�senmuuttujat
        Point start;
        Point end;


    public: //Julkiset j�senfunktiot

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

    //HUOMAA, jos parametrit ovat samannimiset kuin j�senmuuttujat
    // viitataan j�senmuuttujiin this-> operaatiolla
    void aseta(Point start, Point end)
    {
        this->start = start;
        this->end = end;
    }



}; // <-- HUOM! Luokan m��rittely p��ttyy ;


int main()
{
    Vector v1; //Olio v1



    //v1.x = 0; << EI SALLITTU EN��

    //v1.alustaVektori();

    v1.aseta(///);
    v1.tulostaVektori();

    Vector v2(v1); //Alustetaan uusi vektori V1 arvoilla
    v2.tulostaVektori();


    Vector v3(///); //Alustetaan uusi m��ritetyill� arvoilla
    v3.tulostaVektori();
}
