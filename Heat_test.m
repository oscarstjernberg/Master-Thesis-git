t1 = 21.8; t2 = 36.0;
tau = 3/2 * ( t2 - t1 );
theta = t2 - tau;

s = tf('s');
Gp = exp(-theta*s)/(1+tau*s);

hold on, step(Gp), hold off
title('Experimental vs. simulated response to step change');

Kc = 0.859 * (theta / tau)^(-0.977);
tauc = ( tau / 0.674 ) * ( theta / tau )^0.680;
C = Kc * (1 + 1/(tauc*s));

Tfb = feedback(ss(Gp*C),1);
step(Tfb), grid on;
title('Response to step change in temperature setpoint T_{sp}');
ylabel('Tank temperature');

