#pragma once

#include "Resource.hpp"

#include <iostream>

using namespace std;

class ResourceManager
{
public:
    ResourceManager() : dlugosc{ 0 }, pojemnosc{ 0 } {}

    ResourceManager(int n) : dlugosc{ n }, pojemnosc{ n }, num_tab{new double[n]}
    {
        for (int i = 0; i < n; i++)
            num_tab[i] = 0.;
    }

    ResourceManager(const ResourceManager& rs) : dlugosc{rs.dlugosc}, pojemnosc{rs.pojemnosc}
    {
        cout << "constructing" << endl;
        num_tab = new double[pojemnosc];
        for (int i = 0; i < pojemnosc; i++)
            num_tab[i] = rs.num_tab[i];
    }

    // copy by "=" operator
    //ResourceManager& operator=(const ResourceManager& rs) { return *this; }


    ~ResourceManager()
    {
        delete[] num_tab;
    }

    int getDlugosc() { return dlugosc; }

    int getPojemnosc() { return pojemnosc; }

    void print()
    {
        for (int i = 0; i < dlugosc; i++)
            cout << num_tab[i] << endl;
    }

    void zmienDlugosc(int n)
    {
        if (n > pojemnosc) {
            double* temp = new double[n];
            for (int i = 0; i < n; i++)
                temp[i] = 0.;

            for (int i = 0; i < pojemnosc; i++)
                temp[i] = num_tab[i];

            delete[] num_tab;
            num_tab = temp;
            dlugosc = n;
            pojemnosc = n;
        }
        else if (n == pojemnosc) {
            if (n > dlugosc)
                dlugosc = n;
        }
        else { // n < pojemnosc
            if (n < dlugosc) {
                for (int i = n; i < pojemnosc; i++)
                    num_tab[i] = 0.;
                dlugosc = n;
            }
            else if (n > dlugosc) {
                dlugosc = n;
            }
            else {
                // nothing happens
            }
        }
    }

    double& operator[](int n) 
    {
        if (n > dlugosc)
            zmienDlugosc(n);
        return num_tab[n]; 
    }

private:
    int dlugosc;
    int pojemnosc;
    double* num_tab;
};
