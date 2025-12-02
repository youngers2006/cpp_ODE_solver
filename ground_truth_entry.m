clc
clear

run()

function run()
rho0 = 1.225;
h0 = 100000.0;
v0 = 1000.0;
gamma0 = 180.0;
gamma0 = (pi / 180.0) * gamma0;
y0 = [h0; v0; gamma0];
Cl = 0.6;
Cd = 0.8;
m = 100.0;
g = 9.81;
S = 0.5;

T = [0 1000];

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
end

function dydt = reentry_equations(y, rho0, Cl, Cd, m, g, S)
h = y(1);
v = y(2);
gamma = y(3);
rho = rho0 * exp(-h / 7200);
dyn_p = 0.5 * rho * (v ^ 2);
D = Cd * S * dyn_p;
L = Cl * S * dyn_p;
h_dot = v .* sin(gamma);
v_dot = - (D / m) - g .* sin(gamma);
gamma_dot = - (L / (m .* v)) - (g .* cos(gamma)) ./ v;
dydt = [h_dot; v_dot; gamma_dot];
end 