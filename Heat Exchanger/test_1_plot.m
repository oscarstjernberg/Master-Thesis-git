close all
plot((run1pidtuning.Time-run1pidtuning.Time(1))/1000, run1pidtuning.Temp,'linewidth',1.5)
ylabel("Temperature [C]")
ylim([15 25])
hold on
yyaxis right
ylim([])
plot((run1pidtuning.Time-run1pidtuning.Time(1))/1000, run1pidtuning.PID,'linewidth',1.5)
ylabel("PWM-signal")
grid on

set(gca,'fontsize',18)
set(gca,'LineWidth',2)
xlabel("Time [s]")
title("Temperature and control signal")
xlim([0 800])
yyaxis left
plot([0 800], [35 35],'--','linewidth',2)
%legend("T_1","C_1","T_2","C_2","T_3","C_3",'location','best')
legend("Temperature","Temperature reference",'location','best')