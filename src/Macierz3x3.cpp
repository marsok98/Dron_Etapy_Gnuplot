#include "Macierz3x3.hh"

Macierz3x3 InicjalizujMacierz_obrotu(char axis,double kat)
{
  double kat_w_rad;
  Macierz3x3 Macierz;
  kat_w_rad = (PI/180) * kat;
  switch(axis)
  {
    case 'z':
      Macierz[0][0] = cos(kat_w_rad);
      Macierz[0][1] = sin(kat_w_rad);
      Macierz[0][2] = 0;
      Macierz[1][0] = -sin(kat_w_rad);
      Macierz[1][1] = cos(kat_w_rad);
      Macierz[1][2] = 0;
      Macierz[2][0] = 0;
      Macierz[2][1] = 0;
      Macierz[2][2] = 1;
      break;

    case 'y':
      Macierz[0][0] = cos(kat_w_rad);
      Macierz[0][1] = 0;
      Macierz[0][2] = -sin(kat_w_rad);
      Macierz[1][0] = 0;
      Macierz[1][1] = 1;
      Macierz[1][2] = 0;
      Macierz[2][0] = sin(kat_w_rad);
      Macierz[2][1] = 0;
      Macierz[2][2] = cos(kat_w_rad);
      break;

    case 'x':
      Macierz[0][0] = 1;
      Macierz[0][1] = 0;
      Macierz[0][2] = 0;
      Macierz[1][0] = 0;
      Macierz[1][1] = cos(kat_w_rad);
      Macierz[1][2] = sin(kat_w_rad);
      Macierz[2][0] = 0;
      Macierz[2][1] = -sin(kat_w_rad);
      Macierz[2][2] = cos(kat_w_rad);
      break;
    default :
      cerr<<"Zly argument wpisany";
  }
  return Macierz;
}


Macierz3x3 operator * (const Macierz3x3 &MacierzA ,const Macierz3x3 &MacierzB)
{
  int i,j,k;
  Macierz3x3 Wynik;
  for(i=0;i<3;i++)
  {
   Wynik[i] = {};
  }
  for(i=0; i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      for(k=0;k<3;k++)
      {
        Wynik[i][j] = Wynik[i][j] + MacierzA[i][k] * MacierzB[k][j];
      }
    }
  }
	return Wynik;
}



/*
Macierz3x3 InicjalizujMacierz_jednostkowa()
{
    Macierz3x3 Macierz;
    int i,k;
    for(i=0;i<3;i++)
    {
      for(k=0;k<3;k++)
      {
        if(i==k)
        {
          Macierz[i][k] = 1;
        }
        else
        {
          Macierz[i][k] = 0;
        }
      }
    }
    
    return Macierz;
}
*/