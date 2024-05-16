FILE *file;
file = fopen("file.csv", "w")
    for (int i = 0; i < recordsNum; i++) {
        fprintf(file,
                "%s, %s, %d, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
                students[i].lastName,
                students[i].firstName,
                students[i].studentsID,
                students[i].math101,
                students[i].cmpsc113,
                students[i].comm01,
                students[i].math01,
                students[i].nstp02,
                students[i].math16,
                students[i].cmpsc112,
                students[i].pathfit2,
                students[i].GWA ;

        if (ferror(file)) {
            printf("Error writing to file.\n");
            return 1;
        }
    }

    fclose(file);
