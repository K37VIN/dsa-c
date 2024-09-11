 #include <stdio.h>

struct Employee {
    int emp_id;
    char name[50];
    float salary, hra, da;
};

int main() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    struct Employee employees[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);
        printf("Employee ID: ");
        scanf("%d", &employees[i].emp_id);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
        printf("HRA (%): ");
        scanf("%f", &employees[i].hra);
        printf("DA (%): ");
        scanf("%f", &employees[i].da);
    }

    printf("\nEmployee Information with Gross Salary:\n");
    for (int i = 0; i < n; i++) {
        float hra_amount = (employees[i].hra / 100) * employees[i].salary;
        float da_amount = (employees[i].da / 100) * employees[i].salary;
        float gross_salary = employees[i].salary + hra_amount + da_amount;

        printf("\nEmployee ID: %d\n", employees[i].emp_id);
        printf("Name: %s\n", employees[i].name);
        printf("Basic Salary: %.2f\n", employees[i].salary);
        printf("HRA: %.2f\n", hra_amount);
        printf("DA: %.2f\n", da_amount);
        printf("Gross Salary: %.2f\n", gross_salary);
    }

    return 0;
}