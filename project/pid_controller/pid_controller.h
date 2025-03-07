/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

class PID {
public:

   /**
   * TODO: Create the PID class
   **/

    /*
    * Errors
    */
//    double _dKpi;
//    double _dKii;
//    double _dKdi;
//    double _tol = P_ERR_TOLERANCE;
   double _cte = 0.0;
//    double _prev_cte;
   double _icte = 0.0;
   double _diff_cte = 0.0;
    /*
    * Coefficients
    */
   double _Kpi;
   double _Kii; 
   double _Kdi;
    /*
    * Output limits
    */
   double _output_lim_maxi;
   double _output_lim_mini;
  
    /*
    * Delta time
    */
   double _delta_time = 0.0;
   bool _first_time = true;
   double _prev_cte = 0.0;
   double _prev_diff_cte = 0.0; 

    /*
    * Constructor
    */
    PID();

    /*
    * Destructor.
    */
    virtual ~PID();

    /*
    * Initialize PID.
    */
    void Init(double Kp, double Ki, double Kd, double output_lim_max, double output_lim_min);

    /*
    * Update the PID error variables given cross track error.
    */
    void UpdateError(double cte);

    /*
    * Calculate the total PID error.
    */
    double TotalError();
  
    /*
    * Update the delta time.
    */
    void UpdateDeltaTime(double new_delta_time);
};

#endif //PID_CONTROLLER_H


