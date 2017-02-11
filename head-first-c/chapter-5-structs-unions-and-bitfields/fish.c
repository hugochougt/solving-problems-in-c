#include <stdio.h>

typedef struct {
    const char *name;
    const char *species;
    int teeth;
    int age;
} fish;

void catalog(fish f) {
    printf("%s is a %s with %i teeth. It is %i\n", f.name, f.species, f.teeth, f.age);
}

void label(fish f) {
    printf("Name: %s\nSpecies: %s\n%i years old\n%i teeth\n", f.name, f.species, f.age, f.teeth);
}

void happy_birthday(fish *f) {
    f->age++;
    printf("Happy Birthday %s! You are now %i years old!\n", f->name, f->age);
}

int main() {
    fish snappy = {"Snappy", "Piranha", 69, 4};
    catalog(snappy);
    happy_birthday(&snappy);
    label(snappy);

    return 0;
}
