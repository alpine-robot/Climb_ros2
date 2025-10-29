alpine to-do

alpine body------------------------------------------------------------------->

1) redesign pich control linear actuator, with endstops may be advised, driver already 43A more that enought, also integrate imu as feedback error with PID for driving the motor.
2) imu already pre-programed, needs custom ros message and appropriate TF.
3) use hardware timers on alpine body Esp32 (i cannot program from arduino ide; using espressif ide should solve this functionalities loss), softwarte timer are inefficent and can cause servo misfiring. 
4) use rubber feet on pistion shaft for better grip on wood panel when landing. 

winches -------------------------------------------------------------------> 

1) debug uart comunication probelm. When motor is engaged some 0 or other values arrive instead of the correct values, distorting all measurements. Alreay tried to lower the comunication frequency to 50Hz with no luck, may be interference, cable already shilded from EMI. As last resort you could ged rid of the uart entirely and connect the driver directly via usb to the pc, already tested and works fine with the provided python library, just the comunication cannot reach 200hz, but 100hz. Odrive also sells a canbus to usb adapter, that can be wired and configured natively from odrive gui. 
2) once the values arrive corectly you may start calcuating rope posirion, velocity and force, implement the variable grear ratio solution i provided in my thesis. Implement this in /ros2_ws/src/cl_arganello_interface/cl_arganello_interface/telemetry_node.py -> process_csv function. this function resposable for handling the incoming uard csv strings. If you want to clean up or better modularize the code that could be handy.for the theory and calcualtion taken into account reference to my thesis i will provide in the github repo as Luca_Hardonk_thesis.pdf

