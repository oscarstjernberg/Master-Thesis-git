close all
plot((run1pidtuning.Time-run1pidtuning.Time(1))/1000, smooth(run1pidtuning.Temp,15),'linewidth',1.5)
ylabel("Temperature [C]")
%ylim([15 35])
hold on
% yyaxis right
% %ylim([0 900])
% plot((run1pidtuning.Time-run1pidtuning.Time(1))/1000, run1pidtuning.PID,'linewidth',1.5)
% ylabel("PWM-signal")
grid on
legend("Temperature","Control signal")
set(gca,'fontsize',18)
set(gca,'LineWidth',2)
xlabel("Time [s]")
title("Temperature and control signal")
%xlim([0 350])