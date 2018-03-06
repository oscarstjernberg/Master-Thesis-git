%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%           A script that downloads data from the fiels in the ThingSpeak 
%           channel.
%       
%           Written by: Oscar Stjernberg and Alexander Lydh
%           VT2018 Chalmers
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Retrives data from field 1 in the ThingSpeak channel.
data = thingSpeakRead(420692,'Fields',1,'NumPoints',8000,'Timeout',10);
figure(1)
plot(data)
figure(2)
histogram(data)
[data,time] = thingSpeakRead(420692,'Fields',1,'NumMinutes',length(data));

% Retrives data from field 2 in the ThingSpeak channel
data1 = thingSpeakRead(420692,'Fields',2,'NumPoints',8000,'Timeout',10);
figure(3)
plot(data1)
figure(4)
histogram(data1)
[data1,time1] = thingSpeakRead(420692,'Fields',2,'NumMinutes',length(data));