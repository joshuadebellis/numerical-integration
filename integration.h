//
//  integration.h
//  numerical integration
//
//  Created by Joshua on 7/5/14.
//  Copyright (c) 2014 Joshua. All rights reserved.
//

#ifndef __numerical_integration__integration__
#define __numerical_integration__integration__

class integration{
    
public:
    double trapezoidal_rule( double (* pointer) (double x ),  double a , double b, int n) ;
    double simpsons_rule( double (* pointer) (double x ),  double a , double b, int n) ;
    double MC_crude( double (* pointer) (double x ), double a, double b, double n) ;
    double MC_stratified( double (* pointer) (double x ), double a, double b, double n) ;
    double gaussian_twopoint( double (* pointer) (double x ), double a, double b) ;
   
};


#endif /* defined(__numerical_integration__integration__) */
