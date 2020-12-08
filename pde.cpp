//
// Created by Parth Parakh on 06/12/20.
//

#include"pde.h"
#include<cmath>

BlackScholesPDE ::BlackScholesPDE(VanillaOption *_option) : option(_option){}

double BlackScholesPDE::diff_coeff(double t, double x) const
{
    double vol  = option->sigma;
    return 0.5*vol*vol*x*x;
}

double BlackScholesPDE::conv_coeff(double t, double x) const
{
    return (option->r)*x;
}

double BlackScholesPDE::zero_coeff(double t, double x) const
{
    return -(option->r);
}

double BlackScholesPDE::source_coeff(double t, double x) const
{
    return 0.0;
}

double BlackScholesPDE::boundary_left(double t, double x) const
{
    return 0.0;
}

double BlackScholesPDE::boundary_right(double t, double x) const
{
    return (x-(option->K)*exp(-(option->r)*((option->T)-t)));
}

double BlackScholesPDE::init_cond(double x) const
{
    return option->payoff->operator()(x);
}

