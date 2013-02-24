#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	enum week {
		Monday = 1,
		Tuesday,
		Wednesday,
		Thursday,
		Friday,
		Saturday,
		Sunday
	};

	// enum to string
	char *weekstr[] = {
		"INVALID", "Monday", "Tuesday", "Wednesday",
		"Thursday", "Friday", "Saturday", "Sunday" };

	typedef enum week Day;

	// declare and init enum week type
	enum week day = Monday;
	printf("today is %d %s\n", day, weekstr[day]);

	Day tomorrow = Tuesday;
	printf("tomorrow is %d %s\n", tomorrow, weekstr[tomorrow]);

	// printf enum week string value
	int i;
	for (i = Monday; i <= Sunday; i++)
		printf("%d %s\n", i, weekstr[i]);

	return EXIT_SUCCESS;
}
