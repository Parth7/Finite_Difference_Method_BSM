#include "payoff.h"
#include "option.h"
#include "pde.h"
#include "fdm.h"

int main()
{
    double K = 0.5;
    double r = 0.05;
    double v = 0.2;
    double T = 1.00;

    double x_dom = 1.0;
    unsigned long J = 20;
    double t_dom = T;
    unsigned long N = 20;

    PayOff* pay_off_call = new PayOffCall(K);
    VanillaOption* call_option = new VanillaOption(K, r, T, v, pay_off_call);

    BlackScholesPDE* bs_pde = new BlackScholesPDE(call_option);
    FDMEulerExplicit fdm_euler(x_dom, J, t_dom, N, bs_pde);

    fdm_euler.step_march();

    delete bs_pde;
    delete call_option;
    delete pay_off_call;

    return 0;
}