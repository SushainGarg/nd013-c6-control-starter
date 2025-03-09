## Steer Plot
![alt text](<Screenshot 2025-03-09 170315.png>)

Steer PID kp , ki , kd = [(0.25 , 0.025 , 0.025]
The plot depict the performance of a PID controller in a steering control system. The 'steer error' plot shows the deviation of the vehicle's actual heading from the desired heading over time. As we can see the steering error is minimised as the iterations progress, we can also see a very high deviation after 300 iterations, suspected to be caused due to the waypoints defined by the system. The PID controller, tries to decrease this error as much as possible , we cn see this from the interval of 300-350 iterations. It is also seen that as the effort is put to decrease error, the erro instead increase, which indicates sign flipping/ flipping of orientation of the motor.

## Throttle PLot
![](<Screenshot 2025-03-09 170326.png>)

The plots shows the performance of the PID controller in a throttle control system. The 'throttle error' shows the difference between the desired vehicle speed and the actual vehicle speed over time. The 'throttle output' displays the signal by the PID controller to adjust and maintain the desired speed. We can see a very discontinous graph, due to the nature of throttle as a parameter, but as is observed, as the throttle error increase, it is adjusted to bring it back to target.

## Explanation of PID behaviour on PLots to be expected: 

The Proportional (P) term reacts to the current error, providing immediate corrective action. The Integral (I) term addresses accumulated errors over time, eliminating steady-state errors. The Derivative (D) term anticipates future error by considering the rate of change of the error, preventing overshoot and improving stability. we observe that the P-term provides initial correction, the I-term ensures the error converges to zero, and the D-term smooths the control signal and prevents oscillations.

## automatically tune the PID parameters:

As taught in the course Twiddle would be a great method or choice of algorithm for automatic tuning of parameters, It can be implemented, in the update_error function, running a  loop over the error, and trying to find best error. A limitation would be the decreasing referesh rate of the algorithm due to increased computation which may affect performance.



## Pros of Model-Free (PID) Controllers:

Simplicity and Ease of Implementation - minimal knowledge of the system's internal dynamics. This simplicity makes them suitable for a wide range of applications where complex modeling is impractical or unnecessary.
Robusteness to model uncertainities -  PID controllers can be more robust to uncertainties and variations in system parameters. This makes them suitable for systems where the exact model is difficult to obtain or may change over time.

## Cons:

Limited Performance -  PID controllers may have limitations in achieving optimal performance, especially in complex systems with nonlinearities or time-varying dynamics.
Tuning Challenges - Tuning the PID gains (Proportional, Integral, and Derivative) can be challenging and time-consuming. 


## Improvement of PID controller:

Auto-tuning methods: algorithms like Ziegler-Nichols or relay auto-tuning to automatically determine initial PID gains.   
Gain scheduling: Adjust PID gains based on operating conditions (e.g., speed, steer).
Fuzzy logic: Employ fuzzy logic rules to dynamically adjust gains based on system performance and error signals.

## Feedforward Control:

This involves using a model of the system (even a simplified one) to predict the effect of disturbances and proactively adjust the control signal. For example, in a vehicle speed control system, feedforward control can anticipate the effect of an incline and adjust the throttle accordingly before significant speed errors occur.

## Artificial Intelligence (AI) Techniques:

Reinforcement learning: Train an agent to learn optimal PID gains through interaction with the system.
Neural networks: Develop neural network-based controllers that can learn complex control strategies from data.
