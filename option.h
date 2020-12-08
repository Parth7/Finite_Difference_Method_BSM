//
// Created by Parth Parakh on 06/12/20.
//

#ifndef EULER_FINITE_DIFFERENCE_METHOD_BSM_OPTION_H
#define EULER_FINITE_DIFFERENCE_METHOD_BSM_OPTION_H

#include"payoff.h"

class VanillaOption
{
public:
    PayOff* payoff;

    double K;
    double r;
    double T;
    double sigma;

    VanillaOption();
    VanillaOption( double K_, double r_, double T_, double sigma_, PayOff* payoff_);
};

#endif //EULER_FINITE_DIFFERENCE_METHOD_BSM_OPTION_H
