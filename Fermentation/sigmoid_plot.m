close all
a=3;
c=0.45;
e = -1.5:0.1:2.5;
plot(e,sigmf(e,[a c]),'linewidth',1.5)
grid on
xlabel("Error from PID")
ylabel("Fraction active phase")
ylim([-0.1 1.1])
title("Sigmoid function for duty cycle fraction")
set(gca,'fontsize',18)
set(gca,'LineWidth',2)