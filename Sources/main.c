#include "../include/Vector3d.h"


int main() {

    int c;
    Vertex *C_t = NULL;
    Vertex *u = NULL;
    printf("1 - complex vector\n2 - double vector\n3 - test values\n");
    scanf("%d", &c);
    if (c == 1) {
        do {
            printf("\n1 - scan\n2 - sum\n3 - scalar\n4 - cross\n5 - print\n0 - end\n");
            scanf("%d", &c);
            switch (c) {
                case 1:
                    C_t = scan_Complex();
                    print_Complex(C_t);
                    break;
                case 2:
                    printf("enter a second vector\n");
                    u = scan_Complex();
                    Vertex *tmp = sum_Complex(C_t, u);
                    print_Complex(tmp);
                    deleteVertex(C_t);
                    deleteVertex(u);
                    C_t = tmp;
                    break;

                case 3:
                    printf("enter a second vector\n");
                    u = scan_Complex();
                    double complex res = scalar_Complex(C_t, u);
                    printf("{%.3lf + %.3lf * I}", __real__(res), __imag__(res));
                    deleteVertex(u);
                    break;
                case 4:
                    printf("enter a second vector\n");
                    u = scan_Complex();
                    Vertex *tmp1 = cross_Complex(C_t, u);
                    print_Complex(tmp1);
                    deleteVertex(C_t);
                    deleteVertex(u);
                    C_t = tmp1;
                    break;

                case 5:
                    print_Complex(C_t);
                    break;
                case 0:
                    return 0;
                default:
                    continue;
            }
        } while (c != 0);

    } else if (c == 2) {
        do {
            printf("\n1 - scan\n2 - sum\n3 - scalar\n4 - cross\n5 - print\n0 - end\n");
            scanf("%d", &c);
            switch (c) {
                case 1:
                    C_t = scan_double();
                    print_double(C_t);
                    break;
                case 2:
                    printf("enter a second vector\n");
                    u = scan_double();
                    Vertex *tmp = sum_double(C_t, u);
                    print_double(tmp);
                    deleteVertex(C_t);
                    deleteVertex(u);
                    C_t = tmp;
                    break;

                case 3:
                    printf("enter a second vector\n");
                    u = scan_double();
                    double res = scalar_double(C_t, u);
                    printf("%.3lf", res);
                    deleteVertex(u);
                    break;
                case 4:
                    printf("enter a second vector\n");
                    u = scan_double();
                    Vertex *tmp2 = cross_double(C_t, u);
                    print_double(tmp2);
                    deleteVertex(C_t);
                    deleteVertex(u);
                    C_t = tmp2;
                    break;

                case 5:
                    print_double(C_t);
                    break;
                case 0:
                    return 0;
                default:
                    continue;
            }
        } while (c != 0);
    }
    else if (c == 3)
        test();
    while (C_t) {
        deleteVertex(C_t);
    }
    return 0;
}
