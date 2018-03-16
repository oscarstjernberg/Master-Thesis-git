figure
plot(1-duty_cycle_weight,'linewidth',2)
grid on
title("Duty cycle fraction")
ylabel("Fraction of on-time")
set(gca,'fontsize',18)
set(gca,'LineWidth',2)
xlabel("Time (Hours) ")
% create a new pair of axes inside current figure
axes('position',[0.202858261550509 0.478455723542118 0.25 0.25])
box on % put box around new pair of axes
index = [7000, 90000];
plot(index(1):index(2),1-duty_cycle_weight.Data(index(1):index(2)))
axis tight