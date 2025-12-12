clc
clear

rho0 = 1.225;
h0 = 100000.0;
v0 = 1000.0;
gamma0 = 180.0;
gamma0 = (pi / 180.0) * gamma0;
y0 = [h0; v0; gamma0];
Cl = 0.6;
Cd = 1.2;
m = 100.0;
g = 9.81;
S = 0.5;

T = [0 500];

ode_fun = @(t, y) reentry_equations(y, rho0, Cl, Cd, m, g, S);
options = odeset('RelTol', 1e-6, 'AbsTol', 1e-6);
[t, y] = ode45(ode_fun, T, y0, options);

figure('Name', 'Rentry Vehicle', 'Color', 'w');
plot(t, y(:,1), 'r', 'LineWidth', 1.5, 'DisplayName', 'altitude'); % hold on;
figure('Name', 'Rentry Vehicle', 'Color', 'w');
plot(t, y(:,2), 'g', 'LineWidth', 1.5, 'DisplayName', 'velocity');
figure('Name', 'Rentry Vehicle', 'Color', 'w');
plot(t, y(:,3), 'b', 'LineWidth', 1.5, 'DisplayName', 'angle');
    
title('Reentry dynamics vs Time');
xlabel('Time (s)');
ylabel('m / ms^-1 / radians');
legend('show');
grid on;

function dydt = reentry_equations(y, rho0, Cl, Cd, m, g, S)
    % Inputs
    h = y(1); v = y(2); gamma_deg = y(3); 
    
    % Constants from your C++ code
    deg_to_rad = 3.14159265 / 180.0;
    rad_to_deg = 180.0 / 3.14159265;
    gamma_rad = gamma_deg * deg_to_rad;
    
    % Forces
    rho = rho0 * exp(-h / 7200.0);
    dyn_p = 0.5 * rho * S * v^2;
    L = dyn_p * Cl;
    D = dyn_p * Cd;
    
    % Equations matching your re_entryODE.cpp exactly:
    % h_dot = -v * sin(gamma)
    h_dot = -v * sin(gamma_rad);
    
    % v_dot = -(D/m) + g * sin(gamma)
    v_dot = -(D/m) + g * sin(gamma_rad);
    
    % gamma_dot in deg/s
    gamma_dot_rad = (L / (m * v)) + (g / v) * cos(gamma_rad);
    gamma_dot = gamma_dot_rad * rad_to_deg;
    
    dydt = [h_dot; v_dot; gamma_dot];
end