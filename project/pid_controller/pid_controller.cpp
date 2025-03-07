/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#include "pid_controller.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kpi, double Kii, double Kdi, double output_lim_maxi, double output_lim_mini) {
   /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   **/
   _Kpi = Kpi; 
   _Kii = Kii;
   _Kdi = Kdi;
   _output_lim_maxi = output_lim_maxi;
   _output_lim_mini = output_lim_mini;
  //  _dKpi = 1; 
  //  _dKii = 1;
  //  _dKdi = 1;
  //  _dKpi = 1; 
  //  _dKii = 1;
  //  _dKdi = 1;
}


void PID::UpdateError(double cte) {
   /**
   * TODO: Update PID errors based on cte.
   **/
  if(_delta_time != 0){
    _diff_cte = (cte - _cte)/_delta_time;
    
  
  }
  else {
    _diff_cte = 0;
  }
  _cte = cte;
  _icte += _cte;

}

double PID::TotalError() {
   /**
   * TODO: Calculate and return the total error
    * The code should return a value in the interval [output_lim_mini, output_lim_maxi]
   */

    double control = (-_Kpi * _cte) - (_Kdi * _diff_cte) - (_Kii * _icte);

    if(control > _output_lim_maxi){
      control = _output_lim_maxi;
    }
    else if(control < _output_lim_mini){
      control = _output_lim_mini;
    }
    return control;
}

void PID::UpdateDeltaTime(double new_delta_time) {
   /**
   * TODO: Update the delta time with new value
   */
  _delta_time = new_delta_time;
}
