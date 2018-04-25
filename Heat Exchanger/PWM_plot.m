close all

% Start with running the PWM.slx file, then the script
%below will work

plot(amp)
hold on
plot(pwm)

grid on

axis([0 0.1 0 12]);

set(gca,'fontsize',24)
set(gca,'LineWidth',2)

title('Rise time');
xlabel('Time [s]');
ylabel('Volt');


plot([0.0018 0.0018],[0 1.288],'--black')
plot([0.031 0.031], [0 9.011],'--black')

mark1x = 0.0018;
mark1y = 1.288;
mark2x = 0.031;
mark2y = 9.011;
hold on
plot(mark1x,mark1y,'black*','LineWidth',2)
plot(mark2x,mark2y,'black*','LineWidth',2)

