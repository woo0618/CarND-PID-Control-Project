# Overview 
This project uses a PID controller in C++ to maneuver the vehicle around the track as safely as fast as possible . The simulator provides the cross track error (CTE) and the velocity (mph) in order to compute the appropriate steering angle. 

![](video/kp_09_ki_0005_kd_20.gif)

# Implementing the PID Controller 
The proportional controller itself steer the car in proportion to the cross-track error. When used alone, the controller itself oscialltes the car. As the proportional gain value increases, the vehicle oscillates faster as shown in.The integral portion reduces a possible bias on the vehicle. The simulator vehicle appears to be bias free or have very small bias. The differential controller reduces the over steering and reduces the oscialltion by counter steering as the error becomes smaller. The implementation is completed in the telemetry section in the file [main.cpp](./src/main.cpp) between lines 60 and 78, and in the file [PID.cpp](./src/PID.cpp). 



### Describe how the final hyperparameters were chosen.

Both manual tuning and twiddle methods are used for final hyperparameters. First, only the P controller was used to tune. Different gain values were tested to see what appears to be the best for following the road. Then the D controller was added afterwards to reduce the over steering. PD controller was tested until the increasing D gain did not stop the oscillations. Lastly, the I gain was added to reduce the cross track error around curves.  The final parameters are [P: 0.09, I: 0.0005, D: 2.0].

