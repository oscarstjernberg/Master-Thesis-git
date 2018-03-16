% Slope of the sigmoid function
sig_slope = 1;
% Point of 1/2 output from the sigmoid function
sig_half= 5; 
e=-10:0.1:10;
duty_cycle_weight_sigmf = sigmf(e,[sig_slope,sig_half]);
plot(e,duty_cycle_weight_sigmf)