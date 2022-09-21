#include <stdio.h>

int main() {
    float edge, volume, side_surf_area;
    printf("Enter the length of the edge of the kube:");
    if(scanf_s("%f", &edge) != 1)
    {
        printf("Wrong input");
        return 0;
    }
    volume = edge * edge * edge;
    side_surf_area = edge * edge * 4;
    printf("Volume = %1.3f\n", volume);
    printf("Side surface area = %1.3f\n", side_surf_area);
    return 0;
}





