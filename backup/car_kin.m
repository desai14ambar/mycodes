function z = car_kin(t,X)

w = 7;
h = 4;

% x = 15;
% y = 15;

k = animatedline;
p1=1;
% base1  = [x-w/2,x,x+w/2]';
% width  =  y*I;
% side1  = (x-w/2)*I;
% length = [y; y+h/2; y+h];
% width2 = (y+h)*I;
% side2  = (x+w/2)*I;
% plot(base1, width, side1, length , base1, width2, side2, length);
%rectangle('Position',[x,y,w,h]);
for t = 1:length(t)
    delete(p1);
    x = X(t,1);
    y = X(t,2);
    theta = X(t,3);
%     Rect = [x-w/2 ,x-w/2,  x+w/2,  x+w/2, x-w/2; 
            y ,y+h, y+h, y, y];
    Rect = [x, x+w, x+w, x, x;
            y-h/2 ,y-h/2, y+h/2, y+h/2, y-h/2];
%     theta = deg2rad(i);

    R = [cos(theta) -sin(theta);
         sin(theta)  cos(theta)];
    Rect2 = [Rect(1,:)-(x);Rect(2,:)-(y-h/2)];
    % car = [Rect(:,1) R*Rect(1:2,2:4) Rect(:,5)];
%     car = R*Rect;
    
    car = R*Rect2;
    car = [car(1,:)+(x);car(2,:)+(y-h/2)];

    figure(1)   
    grid on
    hold on
    p2 = plot(x,y,'b.');
    p1 = plot(car(1,:),car(2,:));
    axis([-30 30 -30 30]);

    %   addpoints(k,x,y);
    %   drawnow
    pause(0.1);
    
   end
   
   return