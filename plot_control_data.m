
save_state=1;
save_name = 'jag_ar_en_sparad_fil';
grid_state=1;
legends = ["Control signal","Temperature 1","Temperature 2"];
labels = ['x-axel','y-axel','title'];
symbols=['-*r','-+'];
plot_data([control_signal_from_simulink Temp_from_simulink] , labels , legends , grid_state , save_state,save_name,[1920 1080])