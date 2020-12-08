//
// Created by Parth Parakh on 06/12/20.
//
#ifndef EULER_FINITE_DIFFERENCE_METHOD_BSM_FDM_H
#define EULER_FINITE_DIFFERENCE_METHOD_BSM_FDM_H

#include "pde.h"
#include <vector>

using namespace std;

class FDMBase
{
protected:
    ConvectionDiffusionPDE* pde;

    double x_dom;
    unsigned long J;
    double dx;
    vector<double> x_values;

    double t_dom;
    unsigned long N;
    double dt;

    double prev_t, cur_t;

    double alpha, beta, gamma;

    vector<double> new_result;
   vector<double> old_result;

    FDMBase(double _x_dom, unsigned long _J, double _t_dom, unsigned long _N,ConvectionDiffusionPDE* _pde);

    virtual void calculate_step_sizes() = 0;
    virtual void set_initial_conditions() = 0;
    virtual void calculate_boundary_conditions() = 0;
    virtual void calculate_inner_domain() = 0;

public:
    virtual void step_march() = 0;
};

class FDMEulerExplicit : public FDMBase
{
protected:
    void calculate_step_sizes();
    void set_initial_conditions();
    void calculate_boundary_conditions();
    void calculate_inner_domain();

public:
    FDMEulerExplicit(double _x_dom, unsigned long _J, double _t_dom, unsigned long _N,ConvectionDiffusionPDE* _pde);
    void step_march();
};

#endif //EULER_FINITE_DIFFERENCE_METHOD_BSM_FDM_H
