close all
n=10;
k=n;
l=1;

for i=1:n
    for j = 1:k
        WMA(l) = k;
        k=k-1;
        l=l+1;
    end
end

bar(WMA)
ylim([0 n+1])
grid on
title("Triangular weighting of previous samples")
ylabel("Weight")
xlabel("Time steps from latest sample")
set(gca,'fontsize',18)
set(gca,'LineWidth',2)