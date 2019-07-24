#ifndef PID_H
#define PID_H

class PID {
 public:
  PID();
  virtual ~PID();

  void Init(double Kp_, double Ki_, double Kd_, bool run_twiddle);
  void Twiddle(double total_error, double hyperparameter);
  void UpdateError(double cte);
  double TotalError();

   double Kp;
  
 private:
  double p_error;
  double i_error;
  double d_error;

 
  double Ki;
  double Kd;
  
  float tol;
  double dp;
};

#endif  