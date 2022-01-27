%% Creation Time
C1 = readmatrix("./creationTime103300.txt");
C2 = readmatrix("./creationTime103128.txt");

figure(1);
scatter(C1(1:28,1),C1(1:28,2),'red','filled');
set(gca,'xscale','log');
set(gca,'yscale','log');

figure(1);
scatter(C2(1:28,1),C2(1:28,2),'red','filled');
grid on;
title("Tree creation time");
xlabel("Número de pessoas");
ylabel("Tempo (segundos)");
set(gca,'xscale','log');
set(gca,'yscale','log');
legend('All Indeces');

%% Search Time
S1 = readmatrix("./searchTime0.txt");
S2 = readmatrix("./searchTime1.txt");
S3 = readmatrix("./searchTime2.txt");
S4 = readmatrix("./searchTime3.txt");

figure(2);
scatter(S1(:,1),S1(:,2),'yellow','filled')
hold on;
scatter(S2(:,1),S2(:,2),'red','filled');
hold on;
scatter(S3(:,1),S3(:,2),'blue','filled')
hold on;
scatter(S4(:,1),S4(:,2),'green','filled')
set(gca,'xscale','log');
set(gca,'yscale','log');


S5 = readmatrix("./searchTime00.txt");
S6 = readmatrix("./searchTime11.txt");
S7 = readmatrix("./searchTime22.txt");
S8 = readmatrix("./searchTime33.txt");

figure(2);
scatter(S5(:,1),S5(:,2),'yellow','filled')
hold on;
scatter(S6(:,1),S6(:,2),'red','filled');
hold on;
scatter(S7(:,1),S7(:,2),'blue','filled')
hold on;
scatter(S8(:,1),S8(:,2),'green','filled')
set(gca,'xscale','log');
set(gca,'yscale','log');

grid on;
title("Tree Search time");
xlabel("Número de pessoas");
ylabel("Tempo (segundos)");
legend('Index0','Index1','Index2', 'Index3');


%% Tree depth

S1 = readmatrix("./depthIndex0.txt");
S2 = readmatrix("./depthIndex1.txt");
S3 = readmatrix("./depthIndex2.txt");
S4 = readmatrix("./depthIndex3.txt");

figure(3);
scatter(S1(:,1)*0.9,S1(:,2),'yellow','filled')
hold on;
scatter(S2(:,1),S2(:,2),'red','filled');
hold on;
scatter(S3(:,1)*1.01,S3(:,2),'blue','filled')
hold on;
scatter(S4(:,1)*1.02,S4(:,2),'green','filled')
set(gca,'xscale','log');



S5 = readmatrix("./depthIndex00.txt");
S6 = readmatrix("./depthIndex11.txt");
S7 = readmatrix("./depthIndex22.txt");
S8 = readmatrix("./depthIndex33.txt");

figure(3);
scatter(S5(:,1),S5(:,2),'yellow','filled')
hold on;
scatter(S6(:,1),S6(:,2),'red','filled');
hold on;
scatter(S7(:,1),S7(:,2),'blue','filled')
hold on;
scatter(S8(:,1),S8(:,2),'green','filled')
set(gca,'xscale','log');


grid on;
title("Maximum Tree Depth");
xlabel("Número de pessoas");
ylabel("Depth");
legend('Index0','Index1','Index2', 'Index3');