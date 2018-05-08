% Plot from fermentation "freely"

clc
close all
load('SDH')

Measurement = SDH.Measurement;
Temperature = SDH.Temperature;

Measurement(657:1293) = Measurement(657:1293) + 15.64;
Measurement(1294:1811) = Measurement(1294:1811) + 18.92;
Measurement(1812) = 19.35;
Measurement(1813:2261) = Measurement(1813:2261) + 19.35;
Measurement(2262) = 19.21;
Measurement(2263:2370) = Measurement(2263:2370) + 19.21;

Measurement = smooth(Measurement, 10);

% Convert to ABV
Measurement = Measurement*(9/19.75);

x = linspace(0,160,length(Measurement(60:2294)));

plot(x,Temperature(60:2294))

title('Test of measurement equipment')
xlabel('Time (hours)')
ylabel('Temperature (C)')

yyaxis right
plot(x,Measurement(60:2294))
ylabel('ABV (%)')
axis([0 160 0 10])

legend('Temperature', 'ABV', 'location','east')
