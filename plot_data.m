function plot_data(indata, labels , legends , grid_state , save_state , save_name , save_resolution)
% Plots data from simulink with the same format
%
% plot_data(indata, labels,legends, grid_state,save_state,save_name,save_resolution)
%
% indata [L,n] - Indata to be plotted as a vector of n timeseries
% labels [1,3] - Labels for x,y - label and the title of the plot
% legend [1,n] - legend for the different timeseries
% grid_state - binary value if the grid should be visable in the plot
% save_state - binary value if to save the file
% save_name - name for save file
% save_resolution - resolution to save plot as
close all

% Number of plots
n = length(indata);

% Check if save_name exists
if nargin > 5
    if nargin == 6
        error('No save name')
    end
end

% Check for non-standard resolution
if nargin < 7
    save_resolution =[1920 1080];
end

% Plot the given indata
for i=1:n
    plot(indata(i),'linewidth',1.5)
    hold on
end

% Write labels for the axis and the title
xlabel = labels(1);
ylabel = labels(2);
title=labels(3);
legend(legends,'location','best')

% Add grid
if grid_state
    grid on
else
    grid off
end

set(gca,'fontsize',18)
set(gca,'LineWidth',2)
set(gcf, 'Position', [1           1        save_resolution(1)        save_resolution(2)]);

if save_state
    saveas(gcf,save_name,'epsc')
end

end

