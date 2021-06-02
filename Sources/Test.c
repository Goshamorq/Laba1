#include <Vector3d.h>

int isequal_double(Vertex *a, Vertex *b) {
    if (fabs(gd(a, x) - gd(b, x)) < 0.001 && fabs(gd(a, y) - gd(b, y)) < 0.001 && fabs(gd(a, z) - gd(b, z)) < 0.001)
        return 1;
    else
        return 0;
}

int isequal_complex(Vertex *a, Vertex *b) {
    if (cabs(gc(a, x) - gc(b, x)) < 0.001 && cabs(gc(a, y) - gc(b, y)) < 0.001 && cabs(gc(a, z) - gc(b, z)) < 0.001)
        return 1;
    else
        return 0;
}

void test() {
    Vertex *V_C = create_Complex();
    Vertex *V_D = create_double();
    Vertex *v_c = create_Complex();
    Vertex *v_d = create_double();

    Vertex *sumc = create_Complex();/// полученные в программе значения
    Vertex *crossc = create_Complex();
    Vertex *sumc_t = create_Complex();/// теоретические
    Vertex *crossc_t = create_Complex();

    Vertex *sumd = create_double();/// полученные в программе значения
    Vertex *crossd = create_double();
    Vertex *sumd_t = create_double();/// теоретические
    Vertex *crossd_t = create_double();

    double scald, scalc, scald_t, scalc_t;/// полученные в программе значения, теоретические
    double a, b;
    FILE *k = fopen("D:\\C Lion\\Vans\\Data.txt", "r");
    if (k == NULL) {
        printf("RIP");
    }
    /// считываю все теоретические значения из файла
    fscanf(k, "%lf", &gd(V_D, x));
    fscanf(k, "%lf", &gd(V_D, y));
    fscanf(k, "%lf", &gd(V_D, z));

    fscanf(k, "%lf", &gd(v_d, x));
    fscanf(k, "%lf", &gd(v_d, y));
    fscanf(k, "%lf", &gd(v_d, z));

    fscanf(k, "%lf", &gd(sumd_t, x));
    fscanf(k, "%lf", &gd(sumd_t, y));
    fscanf(k, "%lf", &gd(sumd_t, z));

    fscanf(k, "%lf", &scald_t);

    fscanf(k, "%lf", &gd(crossd_t, x));
    fscanf(k, "%lf", &gd(crossd_t, y));
    fscanf(k, "%lf", &gd(crossd_t, z));

    fscanf(k, "%lf%lf", &a, &b);
    gc(V_C, x) = a + b * I;
    fscanf(k, "%lf%lf", &a, &b);
    gc(V_C, y) = a + b * I;
    fscanf(k, "%lf%lf", &a, &b);
    gc(V_C, z) = a + b * I;

    fscanf(k, "%lf%lf", &a, &b);
    gc(v_c, x) = a + b * I;
    fscanf(k, "%lf%lf", &a, &b);
    gc(v_c, y) = a + b * I;
    fscanf(k, "%lf%lf", &a, &b);
    gc(v_c, z) = a + b * I;

    fscanf(k, "%lf%lf", &a, &b);
    gc(sumc_t, x) = a + b * I;
    fscanf(k, "%lf%lf", &a, &b);
    gc(sumc_t, y) = a + b * I;
    fscanf(k, "%lf%lf", &a, &b);
    gc(sumc_t, z) = a + b * I;


    fscanf(k, "%lf%lf", &a, &b);
    scalc_t = a + b * I;

    fscanf(k, "%lf%lf", &a, &b);
    gc(crossc_t, x) = a + b * I;
    fscanf(k, "%lf%lf", &a, &b);
    gc(crossc_t, y) = a + b * I;
    fscanf(k, "%lf%lf", &a, &b);
    gc(crossc_t, z) = a + b * I;

    fclose(k);

    sumd = sum_double(V_D, v_d);
    scald = scalar_double(V_D, v_d);
    crossd = cross_double(V_D, v_d);

    sumc = sum_Complex(V_C, v_c);
    scalc = scalar_Complex(V_C, v_c);
    crossc = cross_Complex(V_C, v_c);

    if (isequal_double(sumd, sumd_t) && abs(scald - scald_t) < 0.001 && isequal_double(crossd, crossd_t))
        printf("There aren't any errors in double values\n\n");
    else
        printf("RIP\n\n");

    if (isequal_complex(sumc, sumc_t) && cabs(scalc-scalc_t) < 0.001 && isequal_complex(crossc, crossc_t))
        printf("There aren't any errors in complex values\n");
    else
        printf("RIP\n");
}

