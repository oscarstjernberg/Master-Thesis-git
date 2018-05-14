close all
plot((run1pidtuning.Time-run1pidtuning.Time(1))/1000, run1pidtuning.Temp,'linewidth',1.5)
ylabel("Temperature [C]")
%ylim([15 35])
hold on
yyaxis right
ylim([0 900])
plot((run1pidtuning.Time-run1pidtuning.Time(1))/1000, run1pidtuning.PID,'linewidth',1.5)
ylabel("PWM-signal")
grid on

set(gca,'fontsize',18)
set(gca,'LineWidth',2)
xlabel("Time [s]")
title("Temperature and control signal")
%xlim([0 600])
yyaxis left
%plot([0 600], [20 20],'--','linewidth',2)
legend("Temperature","Temperature reference","Control signal",'location','best')