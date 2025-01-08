#include <stdio.h>

struct studentsem1 {
    int maths;
    int physics;
    int elective1; 
    int elective2;
    int bio;
    int evs;
    int programming;
    int physicslab;
    int edgraphics;
};

struct studentsem2 {
    int maths;
    int chemistry;
    int elective1;
    int english;
    int betc;
    int bee;
    int chemlab;
    int workshop;
    int yoga;
    int englab;
};

float cgpa1(struct studentsem1 s1) {
    return (((s1.maths) * 4) + ((s1.physics) * 3) + ((s1.elective1) * 2) + ((s1.elective2) * 2) + ((s1.bio) * 2) + ((s1.evs) * 2) + ((s1.programming) * 4) + ((s1.physicslab) * 1) + ((s1.edgraphics) * 1)) / 21.0;
}

float cgpa2(struct studentsem2 s2) {
    return (((s2.maths) * 4) + ((s2.chemistry) * 3) + ((s2.elective1) * 2) + ((s2.english) * 2) + ((s2.betc) * 2) + ((s2.bee) * 2) + ((s2.chemlab) * 1) + ((s2.workshop) * 1) + ((s2.yoga) * 1) + ((s2.englab) * 1)) / 21.0;
}

int main() {
    struct studentsem1 s1;
    struct studentsem2 s2;

    printf("Enter the grades of the subjects of semester 1 (maths, physics, elective1, elective2, bio, evs, programming, physicslab, edgraphics): ");
    scanf("%d %d %d %d %d %d %d %d %d", 
        &s1.maths, &s1.physics, &s1.elective1, &s1.elective2, &s1.bio, 
        &s1.evs, &s1.programming, &s1.physicslab, &s1.edgraphics);

    printf("Enter the grades of the subjects of semester 2 (maths, chemistry, elective1, english, betc, bee, chemlab, workshop, yoga, englab): ");
    scanf("%d %d %d %d %d %d %d %d %d %d", 
        &s2.maths, &s2.chemistry, &s2.elective1, &s2.english, &s2.betc, 
        &s2.bee, &s2.chemlab, &s2.workshop, &s2.yoga, &s2.englab);

    float cgpa_sem1 = cgpa1(s1);
    float cgpa_sem2 = cgpa2(s2);

    printf("The CGPA of semester 1 is %.2f and the CGPA of semester 2 is %.2f\n", cgpa_sem1, cgpa_sem2);
    printf("The overall CGPA is %.2f\n", (cgpa_sem1 + cgpa_sem2) / 2.0);

    return 0;
}
