//
// Created by Parth Parakh on 06/12/20.
//

#include"option.h"

VanillaOption::VanillaOption() {}
VanillaOption::VanillaOption(double K_, double r_, double T_, double sigma_, PayOff *payoff_) :
K(K_), r(r_), T(T_), sigma(sigma_), payoff(payoff_) {}

