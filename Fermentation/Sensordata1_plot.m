% Plot from first fermentation at 14 C
%
% TODO! fixe font size and linewidth!!!!!
%
clc
close all
tdfread('Sensordata1.tsv');

Current_measurement(581:1154) = Current_measurement(581:1154) + 4.082;
Current_measurement(1155:1693) = Current_measurement(1155:1693) + 12.4;
Current_measurement(1694:2500) = Current_measurement(1694:2500) + 18.78;

Current_measurement(1:2500) = smooth(Current_measurement(1:2500),10);

% Convert to ABV
Current_measurement = Current_measurement*(4.33/20.5);

x = linspace(0,160,length(Current_measurement(286:2500)));



plot(x,Current_temperature(286:2500))
%hold on


title('Fermentation at 14 degree Celcius')
xlabel('Time (hours)')
ylabel('Temperature (C)')

axis([0 160 10 18])
yyaxis right
plot(x,Current_measurement(286:2500))
ylabel('ABV (%)')
axis([0 160 0 5])
legend('Temperature', 'ABV', 'location','northwest')


