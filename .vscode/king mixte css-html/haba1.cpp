#include <math.h> 
#include <iostream>
#ifndef SPLAINE_H
#define  SPLAINE_H
Using namespace std;

int main ()
{
const  int n =  5 ; 
const  double a =  0 ; 
const  double b =  4 ; 
const  double h =  0,1 ;  // h = (ba) / n 
const  double param =  1.5 ; 
const  double arr_p_inv [ ]  =  { 0,0 , 1,0 , 2,0 , 3,0 , 4,0 ,} ; 
const  double arr_rand [ ]  =  { 0,0 ,0,5 , 0,86603 , 1,0 , 0,86603 , } ;
}


double cubic_spl ( double x ) 
{ 
    double * moments = get_moments_cub ( ) ; 
    int i = def_elem_interval ( x ) ; 
    double m_1 = moments [ i - 1 ] ; 
    double m_2 = moments [ i ] ; 
    double x_1 = a +  ( i - 1 ) * h; 
    double x_2 = a + i * h ; 
    double f_1 = f ( x_1 ) ; 
    double f_2 = f ( x_2 ) ; 
    double res = m_1 * pow ( x_2 - x, 3 ) / ( 6 * h )  + m_2 * pow ( x - x_1, 3 ) / (6 * h )  +  ( ( f_2 - f_1 ) / h -  ( m_2 - m_1 ) * h / 6 ) * ( x - x_2 )  + f_2 - m_2 * pow ( h, 2 ) / 6 ; 
    return res ; 
}
 
void print_cubic_spl ( ) 
{ 
    cout  <<  "Spline cubique"  << endl ; 
    cout  <<  "x f (x) s (x) | (fs) (x) |"   - s ) ; } cout << "La déviation maximale est égale à" << max1 << endl ;<< endl ; 
    double max1 =  0 ; 
    pour  ( int i =  0 ; i < n ; i ++ )  { 
        double x = a + i * h + param * h ; 
        doublef_ = f ( x ) ; 
        double s = cubic_spl ( x ) ; 
        cout  << x <<  ""  << f_ <<  ""  << s <<  ""  <<  fabs ( f_ - s )  << endl ; 
        si  ( fabs ( f_ - s )  > 
    
       
       "Spline cubique dans le cas où f a un écart"  << endl ; 
    cout  <<  "x f (x) s (x) | (fs) (x) |"  << endl ; 
    double max2 =  0 ; 
    pour  ( int i =  0 ; i < n ; 
        a + i * h + param * h ; 
        double f_ = f ( x ) ; 
        double s = disc_cubic_spl ( x ) ; 
        cout  << x <<  ""  << f_ <<  ""  << s <<  ""  <<  fabs ( f_ - s )  << endl ;
         s )  > max2 ) 
            max2 =  fabs ( f_ - s ) ; 
    } 
    cout  <<  "La déviation maximale est égale à"  << max2 << endl ; 
}
 
int getmax_abs_i ( int k, double ** arr ) 
{ 
    int max_i = k ; 
    double max_a =  fabs ( arr [ k ] [ k ] ) ;      
    pour  ( int i = k ; i < n - 1 ; i ++ ) 
        pour  ( int j = k ; j < n -1 ; j ++ ) 
            if  ( fabs ( arr [ i ] [ j ] )  > max_a )  { 
                max_a =  fabs ( arr [ i ] [ j ] ) ; 
                max_i = i ; 
            } 
    return max_i ; 
}
 double ** build_matr ( ) 
{ 
    double ** matr ; 
    matr =  ( double ** )  malloc ( ( n - 1 ) * sizeof ( double * ) ) ; 
    pour  ( int i =  0 ; i < n - 1 ; i ++ ) 
        matr [ i ]  =  ( double *)  malloc ( ( n - 1 ) * sizeof ( double ) ) ; 
    pour  ( int i =  0 ; i j = 0 ; j < n - 1 ; j ++ ) { 
            matr [ i ] [ j ] = 0< n - 1 ; i ++ ) 
        pour  ( int ; if ( i == j ) 
                matr [ i ] [ j ] + = 2 * h / 3 ; if ( ( i - j == 1 ) || ( j - i , B = 0 , C = 0 ; si ( i ==    
               
                 ==  1 ) ) 
                matr [ i ] [ j ]  + = h / 6 ; 
            double A =  0  
              j - 2 ) 
                A =  1 / h ; 
            si  ( i == j - 1 )  { 
                A =  - 2 / h ; 
                B =  1 / h ; 
            } 
            si  ( i == j )  { 
                A =  1 /h ; 
                B =  - 2 / h ; 
                C =  1 / h ; 
            } 
            si  ( i == j + 1 )  { 
                B =  1 / h ; 
                C =  - 2 / h ; 
            } 
            si  ( i == j + 2 ) 
                C =  1 / h ; 
            matr [ i ] [ j ]  + =  ( arr_p_inv [ j ] * A -  2 * arr_p_inv [ j + 1 ] * B + arr_p_inv [ j + 2 ] * C ) / h ; 
        } 
    return matr ; 
}
double smoothing_spl ( double x, double * moments, double * y ) 
{ 
    int i = def_elem_interval ( x ) ; 
    double m_1 = moments [ i - 1 ] ; 
    double m_2 = moments [ i ] ; 
    double x_1 = a +  ( i - 1 ) * h ; 
    doublex_2 = a + i * h ; 
    double y_1 = y [ i - 1 ] ; 
    double y_2 = y [ i ] ; 
    double res = m_1 * pow ( x_2 - x, 3 ) / ( 6 * h )  + m_2 * pow ( x - x_1, 3 ) / ( 6 * h )  +  ( y_1 -  pow ( h, 2 ) * m_1 / 6 ) * ( x_2 - x ) / h +  ( y_2 -  pow( h, 2 ) * m_2 / 6 ) * ( x - x_1 ) / h ; 
    return res ; 
}
 
double smoothing_spl ( double x ) 
{ 
    double * moments = get_moments_smooth ( ) ; 
    double * y = get_min_G ( moments ) ; 
    double res = smoothing_spl ( x, moments, y ) ; 
    return res ; 
}
 
void print_smooth_spl ( ) 
{ 
    cout  <<  "Spline de lissage"  << endl ; 
    cout  <<  "x f (x) s (x) | (fs) (x) |"  << endl ; 
    double max =  0 ; 
    pour  ( int i =  0 ; i < n ; i ++ )  { 
        double x = a + i * h + param * h ;
        double f_ = f ( x ) ; 
        double s = lissage_spl ( x ) ; 
        cout  << x <<  ""  << f_ <<  ""  << s <<  ""  <<  fabs ( f_ - s )  << endl ; 
        si  ( fabs ( f_ - s )  >  f_ - s ) ; 
    }
     cout  <<  "La déviation maximale est égale à"  << max << endl ; 
}
 
int _main ( ) 
{ 
    print_cubic_spl ( ) ; 
    print_smooth_spl ( ) ; 
    return  0 ; 
}