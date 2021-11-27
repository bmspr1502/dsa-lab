#include<stdio.h>

void cuboid(){
    float l,b,h;
    printf("Enter the length, breadth, height: ");
    scanf("%f%f%f", &l, &b, &h);

    float volume = l*b*h;
    float surface= 2*(l*b+ b*h + h*l);
    printf("Volume = %f\nSurface area = %f\n", volume, surface);
}

void sphere(){
    float r;
    printf("\nEnter the radius of sphere: ");
    scanf("%f",&r);

    float volume = 1.33*3.14*r*r*r;
    float surface = 4*3.14*r*r;
    printf("Volume = %f\nSurface area = %f\n", volume, surface);
}

void cube(){
    float x;
    printf("\nEnter the side of cube: ");
    scanf("%f",&x);

    float volume = x*x*x;
    float surface = 6*x*x;
    printf("Volume = %f\nSurface area = %f\n", volume, surface);
}

int main(){
    int ch;
    while(1){
        printf("1.Cuboid\n2.Sphere\n3.Cube\n4.Exit\nEnter your choice:");
        scanf("%d", &ch);
        if(ch==4)break;
        switch (ch)
        {
        case 1:
            cuboid();
            break;
        case 2:
            sphere();
            break;

        case 3:
            cube();
            break;
        
        default:
            break;
        }
    }
    return 0;
}