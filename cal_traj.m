clc;clear;clf

v   = 2; 
del = -30;
del = deg2rad(del);
L   = 4;
m = v/L;

x0 = [10 10 0]';
t  = 0:0.1:20;
options = odeset('AbsTol',1e-6,'RelTol',1e-6);
[T, X] = ode45(@car_move, t, x0, options, v, del, L);

% del = 0;
% del = deg2rad(del);
% x0 = X(length(t),:)';
% [T, X2] = ode45(@car_move, t, x0, options, v, del, L);
% 
% del = -30;
% del = deg2rad(del);
% % v=-1;
% x0 = X2(length(t),:)';
% [T, X3] = ode45(@car_move, t, x0, options, v, del, L);
% 
% T = [T;T;T];
% X = [X;X2;X3];


%%
car_kin(T,X)
figure(1)
% hold on
% plot(X(:,1),X(:,2))
