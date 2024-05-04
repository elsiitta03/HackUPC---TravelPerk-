#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    char origin[50];
    char destination[50];
    int departureDay;
} User;

int matchUsers(User user1, User user2) {
    if (strcmp(user1.destination, user2.destination) == 0 &&
        user1.departureDay == user2.departureDay) {
        return 1;
    }
    return 0;
}

int main(int argc, char* argv[]) {
    User *user = malloc((argc/3) * sizeof(User));
    int y = 0;
    for (int i = 1; i < argc; i += 3) {
        strcpy(user[y].origin, argv[i]);
        strcpy(user[y].destination, argv[i+1]);
        user[y].departureDay = atoi(argv[i+2]);
        ++y;
    }

    for (int i = 0; i < argc/3; ++i) {
        for (int j = 0; j < argc/3; ++j) {
            if (i != j) {
                if (matchUsers(user[i], user[j])) {
                    printf("Users match\n");
                } else {
                    printf("Users do not match\n");
                }
            }
        }
    }

    return 0;
}