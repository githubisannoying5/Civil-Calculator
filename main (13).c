#include <stdio.h>
#include <stdlib.h>

float calculateYoungsModulus(float stress[], float strain[], int n) {
    float sumStress = 0, sumStrain = 0;
    for (int i = 0; i < n; i++) {
        sumStress += stress[i];
        sumStrain += strain[i];
    }
    return sumStress / sumStrain;
}

float calculateTBeam(float b, float h, float d) {
    return (b * h * h * d) / 6;
}

float calculateDeformation(float E, float L, float F) {
    return (F * L) / E;
}

int main() {
    int n;
    printf("Enter the number of stress-strain pairs: ");
    scanf("%d", &n);

    float stress[n], strain[n];
    for (int i = 0; i < n; i++) {
        printf("Enter stress and strain for pair %d separated by space: ", i + 1);
        scanf("%f %f", &stress[i], &strain[i]);
    }

    float youngsModulus = calculateYoungsModulus(stress, strain, n);
    float tBeam = calculateTBeam(20, 30, 10);
    float deformation = calculateDeformation(youngsModulus, 100, 50);

    printf("The Young's Modulus is: %.2f\n", youngsModulus);
    printf("The T-Beam value is: %.2f\n", tBeam);
    printf("The deformation value is: %.2f\n", deformation);

    return 0;
}