close all

% Start with running the PWM.slx file, then the script
%below will work

plot(amp)
hold on
plot(pwm)

grid on

axis([0 8 0 12]);

set(gca,'fontsize',24)
set(gca,'LineWidth',2)

title('Output signal');
xlabel('Time ');
ylabel('Volt');

legend('Amplified control signal','Control signal')

axes('position',[0.5 0.5 0.1 0.25])
box on % put box around new pair of axes
index = [8600, 9200];
plot(index(1):index(2),amp.Data(index(1):index(2)))
axis tight
% Clear the axis values of the box
xticks([]);
yticks([]);
