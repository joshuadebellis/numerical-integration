//
//  main.cpp
//  numerical integration
//
//  Created by Joshua on 7/4/14.
//  Copyright (c) 2014 Joshua. All rights reserved.
//

#include <iostream>
#include <cmath>
#include "integration.h"




using namespace std ;

















double integrand(double x){
    double answer = x * x;
    return answer ;
}


int main(int argc, const char * argv[])
{
    double n = 1000000;
    integration integrate ;
    double a ;
    double b;
    double (*my_pointer) (double x) ;
    my_pointer = &integrand ;
  
    
    
    cout << "Enter integration bounds \n " ;
    cin >> a ;
    cin >> b ;
    
    cout << "The crude MC integral of the function is " << integrate.MC_crude(my_pointer,a,b,n) << endl ;
     cout << "The  stratified integral of the function is " << integrate.MC_stratified(my_pointer,a,b ,n) << endl ;
    return 0 ;
}


