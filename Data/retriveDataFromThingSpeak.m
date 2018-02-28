
data = thingSpeakRead(420692,'Fields',1,'NumPoints',8000,'Timeout',10);
figure1
plot(data)
figure2
histogram(data)
[data,time] = thingSpeakRead(420692,'Fields',1,'NumMinutes',length(data));