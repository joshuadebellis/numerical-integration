//
//  integration.cpp
//  numerical integration
//
//  Created by Joshua on 7/5/14.
//  Copyright (c) 2014 Joshua. All rights reserved.
//

#include "integration.h"
#include <ctime>
#include <cstdlib>
#include <random>



using namespace std;



double integration::trapezoidal_rule( double (* pointer) (double x ),  double a , double b, int n){
    double h = (b - a) / ( n - 1) ;
    // evaluation of the endpoints
    double answer =(pointer(a) + pointer(b))  ;
    // evaluate the midpoints
    for(int k = 2; k <= (n-1); k++){
        answer += pointer(a + (k-1)*h) ;
    }
    answer *= h / 2 ;
    return answer ;
}

double integration::simpsons_rule( double ( * pointer) (double x ), double a, double b, int n){
    double h = (b - a) / (n) ;
    // evaluation of the endpoints
    double answer = (pointer(a) + pointer(b));
    // evaluation of odd terms
    for(int k = 1; k <= (n - 1) ; k+=2){
    answer += 4*pointer(a+k*h) ;
    }

    // evaluation of even terms
    for(int k = 2; k <= (n - 2) ; k+=2){
        answer += 2*pointer(a+k*h) ;
    }
    answer *= h / 3 ;
    return answer ;
}

double integration::MC_crude( double (* pointer) (double x ), double a, double b, double n){
    random_device rd; // obtain a random number from hardware
    mt19937 eng(rd());
    uniform_real_distribution<> distr(a, b);
    double total = 0 ;
    
    double range = b-a ;
    int counter = 1 ;
    
    while (counter <= n) {
        double random = distr(eng) ;
        double function = pointer(random);
        total += function ;
        counter++ ;
        
    }
    return (total / n) * range   ;
}

double integration::MC_stratified( double (* pointer) (double x ), double a, double b, double n){
    // find midpoint
    double midpoint = (b-a) / 2 ;
    
    double total_1 = 0 ;
    double total_2 = 0 ;
    
    double range_1 = midpoint - a ;
    double range_2 = b - midpoint ;
    
    double counter = 1 ;
    
    random_device rd; // obtain a random number from hardware
    mt19937 eng(rd());
    uniform_real_distribution<> distr_1(a, midpoint) ;
    uniform_real_distribution<> distr_2(midpoint, b);
    
    while (counter <= n) {
        double random = distr_1(eng) ;
        double function = pointer(random);
        total_1 += function ;
        counter++ ;
        
    }
    double result_1 =  (total_1 / n) * range_1;
    counter = 1;

    while (counter <= n) {
        double random = distr_2(eng) ;
        double function = pointer(random);
        total_2 += function ;
        counter++ ;
    }
    double result_2 =  (total_2 / n) * range_2;

    return result_1 + result_2 ;

}

double integration::gaussian_twopoint( double (* pointer) (double x ), double a, double b){
    double x_1 = 0.57735502691896257 ;
    double x_2 = -0.5773502691896257 ;
    double f_1 = b-a ;
    double f_2 = b+a ;
    double answer = pointer((f_1*x_1+f_2)/2) + pointer((f_1*x_2+f_2)/2) ;
    answer = f_1/2 * answer ;
    return answer ;
    
    
}








