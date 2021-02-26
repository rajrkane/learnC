#include <stdio.h>

int main(int agrc, char* argv[]) {
	
	// create arrays	
	int ages[] = {20, 21, 22, 23, 24};
	char *names[] = {
		"Alice", "Bob", "Carol", "Dave", "Eve"
	};

	// get size of ages
	int count = sizeof(ages) / sizeof(int);
	int i = 0;

	// first way using indexing
	for (i = 0; i < count; i++) {
		printf("%s has completed %d years.\n", names[i], ages[i]);
	}

	printf("---\n");

	// set pointers to start of arrays
	int *cur_age = ages;
	char **cur_name = names;

	// second way using pointers
	for (i = 0; i < count; i++) {
		printf("%s is %d years old.\n", *(cur_name + i), *(cur_age + i));
	}

	printf("---\n");

	// third way where pointers are just arrays
	for (i = 0; i < count; i++) {
		printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
	}

	printf("---\n");

	// fourth way which is dumb
	for (cur_name = names, cur_age = ages; (cur_age - ages) < count; 
		cur_name++, cur_age++) {
		printf("%s lives %d years so far.\n", *cur_name, *cur_age);
	}

	return 0;
}
