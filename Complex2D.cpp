#include "Complex2D.h"
#include <cmath>
#include <stdexcept>


Complex2D::Complex2D()
{
    reel = 0.0;
    imaginaire = 0.0;
}


Complex2D::Complex2D(double reel, double imaginaire)
{
    this->reel = reel;
    this->imaginaire = imaginaire;
}


Complex2D::Complex2D(double valeur)
{
    reel = valeur;
    imaginaire = valeur;
}


Complex2D::Complex2D(const Complex2D& autre)
{
    reel = autre.reel;
    imaginaire = autre.imaginaire;
}


double Complex2D::getReel() const
{
    return reel;
}


double Complex2D::getImaginaire() const
{
    return imaginaire;
}


void Complex2D::setReel(double reel)
{
    this->reel = reel;
}


void Complex2D::setImaginaire(double imaginaire)
{
    this->imaginaire = imaginaire;
}


Complex2D Complex2D::operator+(const Complex2D& autre) const
{
    return Complex2D(
        reel + autre.reel,
        imaginaire + autre.imaginaire
    );
}


Complex2D Complex2D::operator-(const Complex2D& autre) const
{
    return Complex2D(
        reel - autre.reel,
        imaginaire - autre.imaginaire
    );
}


Complex2D Complex2D::operator*(const Complex2D& autre) const
{
    double nouveauReel =
        reel * autre.reel - imaginaire * autre.imaginaire;

    double nouvelleImaginaire =
        reel * autre.imaginaire + imaginaire * autre.reel;

    return Complex2D(nouveauReel, nouvelleImaginaire);
}


Complex2D Complex2D::operator/(const Complex2D& autre) const
{
    double denominateur =
        autre.reel * autre.reel +
        autre.imaginaire * autre.imaginaire;

    if (denominateur == 0)
    {
        throw std::runtime_error("Division par zero");
    }

    double nouveauReel =
        (reel * autre.reel +
         imaginaire * autre.imaginaire) / denominateur;

    double nouvelleImaginaire =
        (imaginaire * autre.reel -
         reel * autre.imaginaire) / denominateur;

    return Complex2D(nouveauReel, nouvelleImaginaire);
}


bool Complex2D::operator<(const Complex2D& autre) const
{
    double module1 = reel * reel + imaginaire * imaginaire;
    double module2 = autre.reel * autre.reel +
                     autre.imaginaire * autre.imaginaire;

    return module1 < module2;
}


bool Complex2D::operator>(const Complex2D& autre) const
{
    double module1 = reel * reel + imaginaire * imaginaire;
    double module2 = autre.reel * autre.reel +
                     autre.imaginaire * autre.imaginaire;

    return module1 > module2;
}