function xdot = car_move(t,x,v,del,L)

theta=x(3);


xdot(1) = v*cos(theta);
xdot(2) = v*sin(theta);
xdot(3) = (v/L)*tan(del);

xdot       = xdot(:);

return