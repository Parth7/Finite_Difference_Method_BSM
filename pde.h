//
// Created by Parth Parakh on 06/12/20.
//

#ifndef EULER_FINITE_DIFFERENCE_METHOD_BSM_PDE_H
#define EULER_FINITE_DIFFERENCE_METHOD_BSM_PDE_H

#include"option.h"

class ConvectionDiffusionPDE
{
public :
    virtual double diff_coeff(double t, double x) const =0;
    virtual double conv_coeff(double t, double x) const =0;
    virtual double zero_coeff(double t, double x) const =0;
    virtual double source_coeff(double t, double x) const =0;

    virtual double boundary_left(double t, double x) const =0;
    virtual double boundary_right(double t, double x) const = 0;
    virtual double init_cond(double x)const =0;
};

class BlackScholesPDE : public ConvectionDiffusionPDE
{
public :
    VanillaOption* option;
    BlackScholesPDE(VanillaOption* _option);

    double diff_coeff(double t, double x) const;
    double conv_coeff(double t, double x) const;
    double zero_coeff(double t, double x) const;
    double source_coeff(double t, double x) const;

    double boundary_left(double t, double x) const;
    double boundary_right(double t, double x) const;
    double init_cond(double x) const;
};

#endif //EULER_FINITE_DIFFERENCE_METHOD_BSM_PDE_H
