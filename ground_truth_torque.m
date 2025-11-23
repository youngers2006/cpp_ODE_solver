clear 
clc

satellite_dynamics()

function satellite_dynamics()
    Ix = 100; 
    Iy = 1000;
    Iz = 400;

    % [omega_x; omega_y; omega_z]
    w0 = [20.0; 50.0; 10.0]; 
    tau = [0.5, 0.3, 0.1];
    t_span = [0 100];
    ode_fun = @(t, w) euler_equations(t, w, Ix, Iy, Iz, tau);

    options = odeset('RelTol', 1e-6, 'AbsTol', 1e-6);
    [T, W] = ode45(ode_fun, t_span, w0, options);

    figure('Name', 'Satellite Attitude Dynamics', 'Color', 'w');
    
    plot(T, W(:,1), 'r', 'LineWidth', 1.5, 'DisplayName', '\omega_x'); hold on;
    plot(T, W(:,2), 'g', 'LineWidth', 1.5, 'DisplayName', '\omega_y');
    plot(T, W(:,3), 'b', 'LineWidth', 1.5, 'DisplayName', '\omega_z');
    
    title('Satellite Angular Velocities vs Time');
    xlabel('Time (s)');
    ylabel('Angular Velocity (rad/s)');
    legend('show');
    grid on;
end

function dw_dt = euler_equations(~, w, Ix, Iy, Iz, tau)
    wx = w(1);
    wy = w(2);
    wz = w(3);

    taux = tau(1);
    tauy = tau(2);
    tauz = tau(3);

    dwx_dt = (((Iy - Iz) * wy * wz) / Ix) + taux;
    dwy_dt = (((Iz - Ix) * wz * wx) / Iy) + tauy;
    dwz_dt = (((Ix - Iy) * wx * wy) / Iz) + tauz;

    dw_dt = [dwx_dt; dwy_dt; dwz_dt];
end