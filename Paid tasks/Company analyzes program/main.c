#include <stdio.h>
#include <stdlib.h>

struct Center{
    int numberOfCustomers;
    double avgPricePerItem;
    double avgWeightPerItem;
};

int calculateTotalCustomers(struct Center centers[], int totalCenters){
    int totalCustomers = 0, i;
    for(i=0; i<totalCenters; i++)
        totalCustomers += centers[i].numberOfCustomers;

    return totalCustomers;
}

double calculateTotalWeight(struct Center centers[], int totalCenters){
    double totalWeight = 0;
    int i;
    for(i=0; i<totalCenters; i++)
        totalWeight += (centers[i].numberOfCustomers * centers[i].avgWeightPerItem);

    return totalWeight;
}

double calculateTotalRevenue(struct Center centers[], int totalCenters, int totalWeight){
    double totalRevenue = 0;
    int i;
    for(i=0; i<totalCenters; i++)
        totalRevenue += (centers[i].numberOfCustomers * centers[i].avgPricePerItem);

    return totalRevenue - (totalWeight * 4.70);
}


int main()
{
    int totalCenters, totalCustomers, i;
    double totalWeight, totalRevenue, avgRevenue;

    printf("Input number of centers: \n");
    scanf("%d", &totalCenters);

    struct Center centers[totalCenters];

    printf("Input customer data for all centers: \n");
    for(i=0; i<totalCenters; i++)
        scanf("%d", &centers[i].numberOfCustomers);

    printf("Input item average price data for all centers: \n");
    for(i=0; i<totalCenters; i++)
        scanf("%lf", &centers[i].avgPricePerItem);

    printf("Input item average weight data for all centers: \n");
    for(i=0; i<totalCenters; i++)
        scanf("%lf", &centers[i].avgWeightPerItem);


    totalCustomers = calculateTotalCustomers(centers, totalCenters);
    printf("\nTotal customers: %d \n", totalCustomers);

    totalWeight = calculateTotalWeight(centers, totalCenters);
    printf("Total weight: %.0lf kg \n", totalWeight);

    totalRevenue = calculateTotalRevenue(centers, totalCenters, totalWeight);
    printf("Total revenue: $%.0lf \n", totalRevenue);


    avgRevenue = totalRevenue / totalCenters;
    printf("Average revenue: $%.0lf \n", avgRevenue);

    if(avgRevenue >= 36000)
        printf("Company is profitable \n");
    else
        printf("Company is not profitable \n");

    printf("\n");
    return 0;
}
