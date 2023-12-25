#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

long getMinCost(int crew_id_count, int* crew_id, int job_id_count, int* job_id) 
{
    long totalDistance = 0;

    // Sort both arrays in ascending order
    qsort(crew_id, crew_id_count, sizeof(int), compare);
    qsort(job_id, job_id_count, sizeof(int), compare);

    // Calculate the total distance
    for (int i = 0; i < crew_id_count; i++) {
        totalDistance += abs((long)crew_id[i] - job_id[i]);
    }

    return totalDistance;
}

int main() {
    int crew_id_count, job_id_count;

    printf("Enter the number of crews: ");
    scanf("%d", &crew_id_count);

    int crew_id[crew_id_count];
    printf("Enter the positions of crews: ");
    for (int i = 0; i < crew_id_count; i++) {
        scanf("%d", &crew_id[i]);
    }

    printf("Enter the number of repair points: ");
    scanf("%d", &job_id_count);

    int job_id[job_id_count];
    printf("Enter the positions of repair points: ");
    for (int i = 0; i < job_id_count; i++) {
        scanf("%d", &job_id[i]);
    }

    long result = getMinCost(crew_id_count, crew_id, job_id_count, job_id);
    printf("Minimum total distance traveled: %ld\n", result);

    return 0;
}
