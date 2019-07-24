#include "PID.h"
#include <math.h>

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_, bool run_twiddle) {
  Kp = Kp_;
  Ki = Ki_; 
  Kd = Kd_; 
  
  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;

  if (run_twiddle) {
    tol = 0.005;
    dp = -0.01;
  }

}

void PID::UpdateError(double cte) {
  double prev_cte = p_error;
  p_error = cte;
  i_error += cte; 
  d_error = (cte - prev_cte); 
 
}

double PID::TotalError() {
  return -Kp*p_error - Ki*i_error - Kd*d_error;
}

void PID::Twiddle(double total_error, double hyperparameter) {
  static double best_error = 100000;
  static bool twiddle_init = false;
  static bool twiddle_reset = false;
  static double last_hyperp = 0;
  
  if (!twiddle_init) {
  	best_error = total_error;
  	twiddle_init = true;
  }
  
  if ((fabs(dp) > tol)) {
  	if (twiddle_reset) {
  		last_hyperp = hyperparameter;
  		hyperparameter += dp;
  		twiddle_reset = false;
  	} else {
  		if (total_error < best_error) {
  			dp *= 1.1;
  			twiddle_reset = true;
  			best_error = total_error;
  		} else {
  			if (fabs(last_hyperp) < fabs(hyperparameter)) {
  				last_hyperp = hyperparameter;
  				hyperparameter -= 2.0 * dp;
  			} else {
  				last_hyperp = hyperparameter;
  				hyperparameter += dp;
  				dp *= 0.9;
  				twiddle_reset = true;
  			}
  		}
  	}
  }
}