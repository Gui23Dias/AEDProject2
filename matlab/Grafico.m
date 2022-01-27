%% Gráfico 2
A2 = load ("./depthIndex0hist.txt");
B2 = load ("./depthIndex1hist.txt");
C2 = load ("./depthIndex2hist.txt");
D2 = load ("./depthIndex3hist.txt");

binc1=(34:56);

o0 = hist(A2,binc1); 
o1 = hist(B2,binc1);
o2 = hist(C2,binc1);
o3 = hist(D2,binc1);

figure(1) %Maximum Depth 100k pessoas 10k testes
x = 34:1:56;
y = [o0;o1;o2;o3];
bar(x,y);
grid on;
xlabel('Depth')
ylabel('Number of Occurrences')
legend('Index0','Index1','Index2', 'Index3')
title('Maximum depth histogram for 100000 persons and 10000 experiments');


%% Gráfico 4

A4 = load ("./creationTimehist.txt");


figure(2) %Creation time histogram 100k pessoas 10k testes
binc2=(0.21:0.0001:0.7);
histogram(A4,binc2,EdgeColor="r",FaceColor="r");
xlabel('Time')
ylabel('Number of Occurrences')
title("Tree creation time histogram for 100000 persons and 10000 experiments");
legend('All Indeces');


%% Gráfico 6

A6 = load("./searchTime0hist.txt");
B6 = load("./searchTime1hist.txt");
C6 = load("./searchTime2hist.txt");
D6 = load("./searchTime3hist.txt");



figure(3) %Search Time histogram 100k pessoas 10k testes TODO
binc3 = (0.048:0.00001:0.090);
histogram(A6,binc3,EdgeColor="r",FaceColor="r")
hold on;
histogram(B6,binc3,EdgeColor="g",FaceColor="g")
hold on;
histogram(C6,binc3,EdgeColor="b",FaceColor="b")
hold on;
histogram(D6,binc3,EdgeColor="y",FaceColor="y")
title('Tree search time histogram for 100000 persons and 10000 experiments');
legend('Index0','Index1','Index2', 'Index3');
xlabel('Time');
ylabel('Number of occurrences');
