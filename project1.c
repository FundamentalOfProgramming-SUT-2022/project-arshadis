// بسم الله الرحمن الرحیم
// Besmellah
#include <stdio.h>
#include <conio.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
char c, adress[] = {"C:\\Users\\ArShAdI\\Desktop\\projet"};
const char backeslash[] = {"\\"};
char c1[1000], c2[1000], c4[1000];
int x, y, z, zz = 0;
// z in getcharacter
void ADRES();
void mkfil(char *, char *);
void createfile();
void insert();
void bekhon();
void show();
void pakkon();
void copyclip();
void cut();
void paste();
void find();
void nokhostin();
void getcharacter();
void grep();
void compare();
void replace();
void undo();
void auto_indent();
void tree();
void redo(char *);
int main()
{
    bekhon();
}
void bekhon()
{
    for (int i = 0; i < 1000; i++)
    {
        c1[i] = c2[i] = c4[i] = '\0';
    }
    c = getchar();
    for (int i = 0; (c != ' ') && (c != '\n'); i++)
    {
        c1[i] = c;
        c = getchar();
    }
    if (0 == strcmp(c1, "createfile"))
    {
        createfile();
    }

    else if (0 == strcmp(c1, "insertstr"))
    {
        insert();
    }
    else if (0 == strcmp(c1, "cat"))
    {
        show();
    }
    else if (0 == strcmp(c1, "removestr"))
    {
        pakkon();
    }
    else if (0 == strcmp(c1, "copystr"))
    {
        copyclip();
    }
    else if (0 == strcmp(c1, "cutstr"))
    {
        cut();
    }
    else if (0 == strcmp(c1, "pastestr"))
    {
        paste();
    }
    else if (0 == strcmp(c1, "find"))
    {
        find();
    }
    else if (0 == strcmp(c1, "undo"))
    {
        undo();
    }
    else if (0 == strcmp(c1, "replace"))
    {
        printf("sharmande labtabam kharab shod ino tonestam bezanam\n");
    }
    else if (0 == strcmp(c1, "grep"))
    {
        grep();
    }
    else if (0 == strcmp(c1, "auto-indent"))
    {
        auto_indent();
    }
    else if (0 == strcmp(c1, "compare"))
    {
        compare();
    }
    else if (0 == strcmp(c1, "tree"))
    {
        tree();
    }
    else
        printf("sobhan %c\n", 3);
}
void ADRES()
{
    char c3[1000];
    for (int i = 0; i < 1000; i++)
    {
        *(c1 + i) = c2[i] = c3[i] = '\0';
    }
    c = getchar();
    int x1 = 1, z1 = 0;
    for (int i = 0; c != '\n'; i++)
    {
        if (c == '"')
        {
            x1 *= 2;
            if (x1 % 4 == 0)
            {
                z1 = 1;
            }
            continue;
        }
        if (z1 == 1 && (c == ' '))
        {
            break;
        }
        if (c == '/')
        {
            c = '\\';
        }

        c3[i] = c;
        c = getchar();
        if (x1 == 1 && (c == ' '))
        {
            break;
        }
    }
    strcat(c1, adress);
    strcat(c1, backeslash);
    strcat(c1, c3);
    // printf("%s\n", c1);
    FILE *dirr = fopen(c1, "r");
    if (dirr == NULL)
    {
        printf("Eror:File is not exists\n");
        return;
    }
    redo(c3);
}
void createfile()
{
    char c, c1[1000], c2[1000], c3[1000], c4[1000];
    for (int i = 0; i < 1000; i++)
    {
        c1[i] = c2[i] = c3[i] = c4[i] = '\0';
    }
    c = getchar();
    for (int i = 0; (c != ' ') && (c != '\n'); i++)
    {
        c2[i] = c;
        c = getchar();
    }
    if (!(0 == strcmp(c2, "--file")))
    {
        printf("invalid command");
    }
    else
    {
        int x = 1;
        c = getchar();
        for (int i = 0; c != '\n'; i++)
        {
            c3[i] = c;
            c = getchar();
            if (c3[i] == '"')
            {
                x *= 2;
            }
        }
        for (int i = 0;; i++)
        {
            if (x != 1 && x != 4)
            {
                break;
            }
            if (c3[i] == '"')
            {
                i++;
            }
            if (c3[i] == '/' || c3[i] == '\\' || c3[i - 1] == '/' || c3[i - 1] == '\\' || c3[i - 2] == '/' || c3[i - 2] == '\\')
            {
                if (c3[i] == '/' || c3[i] == '\\')
                {
                    i++;
                }
                for (int j = 0; (c3[i] != '/') && (c3[i] != '\\') && (c3[i] != '\0'); j++, i++)
                {
                    if (c3[i] == '"')
                    {
                    }
                    else
                        c4[j] = c3[i];
                }
                // printf("bs: %s, adress: %s, c4: %s\n", backeslash, adress, c4);

                if (c3[i] == '/' || c3[i] == '\\')
                {
                    strcat(adress, backeslash);
                    strcat(adress, c4);
                    mkdir(adress);
                }
                else if (c3[i] == '\0' || c3[i] == '"')
                {
                    strcat(adress, backeslash);
                    strcat(adress, c4);
                    // printf("%s  %s", c4, adress);
                    mkfil(adress, c4);
                    break;
                }
                for (int i = 0; i < 1000; i++)
                {
                    c4[i] = '\0';
                }
                if (c3[i] == '"')
                {
                    i++;
                }
            }
        }
    }
}
void mkfil(char dir[], char *c4)
{
    FILE *dirr = fopen(dir, "r");
    if (!(dirr == NULL))
    {
        printf("Eror:File [%s] exists\n", c4);
    }
    else
    {
        FILE *mkfile1 = fopen(dir, "w");
        if (mkfile1 == 0)
        {
            printf("EROR: [%s] cant be created\n", c4);
        }
        else
            printf("[%s] created\n", c4);
        fclose(mkfile1);
    }
}
void getcharacter()
{
    int x1 = 1, v = -1;
    char c, c3[1000];
    c = getchar();
    for (int i = 0;; i++)
    {
        if (c == '"' && i == 0)
        {
            x1 *= 2;
            i--;
            c = getchar();
            continue;
        }
        if (x1 % 2 == 1 && c == ' ')
        {
            break;
        }
        if (c == '"' && c4[i - 1] != '\\')
        {
            break;
        }
        if (z == 9124837)
        {
            if (c == '*' && c4[i - 1] == '\\')
            {
                c4[i - 1] = '*';
                i--;
                v = i;
                c = getchar();
                continue;
            }
            if (c == '*' && c4[i - 1] != '\\')
            {
                if (c4[i - 1] == ' ' || i < 1)
                {
                    // printf("%d\n,,,", i);
                    z = 9124839;
                    zz = i + 1;
                    i--;
                    v = i;
                    c = getchar();
                    continue;
                }
                else
                {
                    // printf("ss");
                    z = 9124830;
                    zz = i;
                    // printf("%s\n%d  ;", c4, zz);
                    i--;
                    v = i;
                    c = getchar();
                    continue;
                }
            }
        }
        if (c == 'n' && c4[i - 1] == '\\')
        {
            if (v == i - 1)
            {
                c4[i] = 'n';
            }
            else
            {
                c4[i - 1] = '\n';
                i--;
            }
            c = getchar();
            continue;
        }
        if (c == '\\' && c4[i - 1] == '\\')
        {
            i--;
            v = i;
            c = getchar();
            continue;
        }
        c4[i] = c;
        c = getchar();
    }
}
void insert()
{
    char c, c3[1000];
    for (int i = 0; i < 1000; i++)
    {
        c2[i] = c3[i] = c4[i] = '\0';
    }
    c = getchar();
    for (int i = 0; (c != ' ') && (c != '\n'); i++)
    {
        c2[i] = c;
        c = getchar();
    }
    if (!(0 == strcmp(c2, "--file")))
    {
        printf("invalid command");
        return;
    }
    else
    {
        ADRES();
    }
    // c1 for adress
    // c2 --
    // c4 string

    for (int i = 0; i < 1000; i++)
    {
        c3[i] = c2[i] = '\0';
    }
    c = getchar();
    for (int i = 0; (c != ' ') && (c != '\n'); i++)
    {
        c2[i] = c;
        c = getchar();
    }
    if (!(0 == strcmp(c2, "--str")))
    {
        printf("invalid command");
        return;
    }
    else
    {
        getcharacter();
    }
    for (int i = 0; i < 1000; i++)
    {
        c2[i] = '\0';
    }
    c = getchar();
    if (c != '-')
    {
        c = getchar();
    }
    for (int i = 0; (c != ' ') && (c != '\n'); i++)
    {
        c2[i] = c;
        c = getchar();
    }
    if (!(0 == strcmp(c2, "--pos")))
    {
        printf("invalid command\n");
        return;
    }
    else
    {
        int POS = 0, tedadchar = strlen(c4);
        char c5[1000], c6[2000];
        for (int i = 0; i < 100; i++)
        {
            c5[i] = '\0';
        }
        scanf("%d:%d", &x, &y);
        FILE *fail = fopen(c1, "r");
        for (int i = 0; !feof(fail); i++)
        {

            c5[i] = fgetc(fail);
        }
        for (int i = 0, j = 1; i < 1000; i++)
        {
            if (c5[i] == '\n')
            {
                j++;
            }
            if (j == x)
            {
                POS = i;
                break;
            }
        }
        for (int i = 0; i < z + y + POS + 1; i++)
        {
            c6[i] = c5[i];
        }
        for (int i = z + y + POS + 1, j = 0; i < POS + 1 + z + y + tedadchar; i++, j++)
        {
            c6[i] = c4[j];
        }
        int i;
        for (i = z + y + tedadchar + POS + 1;; i++)
        {
            if (c5[i - tedadchar] == '\0')
            {
                break;
            }
            c6[i] = c5[i - tedadchar];
        }
        c6[i - 1] = '\0';
        fclose(fail);
        FILE *fail2 = fopen(c1, "w");
        fprintf(fail2, c6);
        fclose(fail2);
    }
}
void show()
{
    char c3[1000];
    for (int i = 0; i < 1000; i++)
    {
        *(c1 + i) = c2[i] = c3[i] = '\0';
    }
    c = getchar();
    for (int i = 0; (c != ' ') && (c != '\n'); i++)
    {
        c2[i] = c;
        c = getchar();
    }
    if (!(0 == strcmp(c2, "--file")))
    {
        printf("invalid command");
    }
    else
    {
        ADRES();
        FILE *fail = fopen(c1, "r");
        for (int i = 0; !feof(fail); i++)
        {
            c3[i] = fgetc(fail);
        }
        printf("%s\n", c3);
    }
}
void pakkon()
{
    int POS = 0;
    char c, c2[1000], c3[1000], c4[1000], c5[1000];
    char *c1 = (char *)calloc(1000, sizeof(char));
    for (int i = 0; i < 1000; i++)
    {
        *(c1 + i) = c2[i] = c3[i] = c4[i] = c5[i] = '\0';
    }
    c = getchar();
    for (int i = 0; (c != ' ') && (c != '\n'); i++)
    {
        c2[i] = c;
        c = getchar();
    }
    if (!(0 == strcmp(c2, "--file")))
    {
        printf("invalid command");
        return;
    }
    else
    {
        ADRES();
    }
    for (int i = 0; i < 1000; i++)
    {
        c3[i] = c2[i] = '\0';
    }
    c = getchar();
    for (int i = 0; (c != ' ') && (c != '\n'); i++)
    {
        c2[i] = c;
        c = getchar();
    }
    if (!(0 == strcmp(c2, "--pos")))
    {
        printf("invalid command");
        return;
    }
    else
    {
        scanf("%d:%d", &x, &y);
    }
    for (int i = 0; i < 1000; i++)
    {
        c3[i] = c2[i] = '\0';
    }
    c = getchar();
    if (c != '-')
    {
        c = getchar();
    }
    for (int i = 0; (c != ' ') && (c != '\n'); i++)
    {
        c2[i] = c;
        c = getchar();
    }
    if (!(0 == strcmp(c2, "-size")))
    {
        printf("invalid command");
        return;
    }
    else
    {
        scanf("%d", &z);
    }
    for (int i = 0; i < 1000; i++)
    {
        c3[i] = c2[i] = '\0';
    }
    c = getchar();
    if (c != '-')
    {
        c = getchar();
    }
    for (int i = 0; (c != ' ') && (c != '\n'); i++)
    {
        c2[i] = c;
        c = getchar();
    }
    if (!(0 == strcmp(c2, "-b") || 0 == strcmp(c2, "-f")))
    {
        printf("invalid command");
        return;
    }
    else
    {
        FILE *fail = fopen(c1, "r");
        for (int i = 0; !feof(fail); i++)
        {
            c4[i] = fgetc(fail);
        }
        for (int i = 0, j = 1; i < 1000; i++)
        {
            if (c4[i] == '\n')
            {
                j++;
            }
            if (j == x)
            {
                POS = i;
                break;
            }
        }
        for (int i = 0; i < POS + y; i++)
        {
            c5[i] = c4[i];
        }
        int i;
        if (0 == strcmp(c2, "-b"))
        {
            for (i = POS + y;; i++)
            {
                if (c4[i + 1] == '\0')
                {
                    break;
                }
                c5[i - z + 1] = c4[i + 1];
            }
            c5[i - z] = '\0';
        }
        else
        {
            for (i = POS + y + z;; i++)
            {
                if (c4[i - 1] == '\0')
                {
                    break;
                }
                c5[i - z] = c4[i - 1];
            }
            c5[i - z - 1] = '\0';
        }
        fclose(fail);
        FILE *fail2 = fopen(c1, "w");
        fprintf(fail2, c5);
        fclose(fail2);
    }
}
void copyclip()
{
    int POS = 0;
    char c, c3[1000], c4[1000], c5[1000];
    for (int i = 0; i < 1000; i++)
    {
        *(c1 + i) = c2[i] = c3[i] = c4[i] = c5[i] = '\0';
    }
    c = getchar();
    for (int i = 0; (c != ' ') && (c != '\n'); i++)
    {
        c2[i] = c;
        c = getchar();
    }
    if (!(0 == strcmp(c2, "--file")))
    {
        printf("invalid command");
        return;
    }
    else
    {
        ADRES();
    }
    for (int i = 0; i < 1000; i++)
    {
        c3[i] = c2[i] = '\0';
    }
    c = getchar();
    for (int i = 0; (c != ' ') && (c != '\n'); i++)
    {
        c2[i] = c;
        c = getchar();
    }
    if (!(0 == strcmp(c2, "--pos")))
    {
        printf("invalid command");
        return;
    }
    else
    {
        scanf("%d:%d", &x, &y);
        // y += 1;
    }
    for (int i = 0; i < 1000; i++)
    {
        c3[i] = c2[i] = '\0';
    }
    c = getchar();
    if (c != '-')
    {
        c = getchar();
    }
    for (int i = 0; (c != ' ') && (c != '\n'); i++)
    {
        c2[i] = c;
        c = getchar();
    }
    if (!(0 == strcmp(c2, "-size")))
    {
        printf("invalid command");
        return;
    }
    else
    {
        scanf("%d", &z);
    }
    for (int i = 0; i < 1000; i++)
    {
        c3[i] = c2[i] = '\0';
    }
    c = getchar();
    if (c != '-')
    {
        c = getchar();
    }
    for (int i = 0; (c != ' ') && (c != '\n'); i++)
    {
        c2[i] = c;
        c = getchar();
    }
    if (!(0 == strcmp(c2, "-b") || 0 == strcmp(c2, "-f")))
    {
        printf("invalid command");
        return;
    }
    else
    {
        FILE *fail = fopen(c1, "r");
        for (int i = 0; !feof(fail); i++)
        {
            c4[i] = fgetc(fail);
        }
        for (int i = 0, j = 1; i < 1000; i++)
        {
            if (c4[i] == '\n')
            {
                j++;
            }
            if (j == x)
            {
                POS = i;
                break;
            }
        }
        int i, j = 0;
        if (0 == strcmp(c2, "-b"))
        {
            for (i = POS + y - z + 1; i < POS + y + 1; i++, j++)
            {
                c5[j] = c4[i];
            }
            // c5[i - z] = '\0';
        }
        else
        {
            for (i = POS + y; i < POS + y + z; i++, j++)
            {
                c5[j] = c4[i];
            }
            // c5[i - z - 1] = '\0';
        }
        fclose(fail);
        strcat(adress, "\\clipboard.txt");
        FILE *fail2 = fopen(adress, "w");
        fprintf(fail2, c5);
        fclose(fail2);
    }
}
void cut()
{
    int POS = 0;
    char c, c3[1000], c5[1000];
    for (int i = 0; i < 1000; i++)
    {
        c3[i] = c4[i] = c5[i] = '\0';
    }
    copyclip();
    FILE *fail = fopen(c1, "r");
    for (int i = 0; !feof(fail); i++)
    {
        c4[i] = fgetc(fail);
    }
    for (int i = 0, j = 1; i < 1000; i++)
    {
        if (c4[i] == '\n')
        {
            j++;
        }
        if (j == x)
        {
            POS = i;
            break;
        }
    }
    for (int i = 0; i < POS + y; i++)
    {
        c5[i] = c4[i];
    }
    int i;
    if (0 == strcmp(c2, "-b"))
    {
        for (i = POS + y;; i++)
        {
            if (c4[i + 1] == '\0')
            {
                break;
            }
            c5[i - z + 1] = c4[i + 1];
        }
        c5[i - z] = '\0';
    }
    else
    {
        for (i = POS + y + z;; i++)
        {
            if (c4[i - 1] == '\0')
            {
                break;
            }
            c5[i - z] = c4[i];
        }
        c5[i - z - 2] = '\0';
    }
    fclose(fail);
    FILE *fail2 = fopen(c1, "w");
    fprintf(fail2, c5);
    fclose(fail2);
}
void paste()
{
    int POS = 0;
    char c, c3[1000], c5[1000];
    for (int i = 0; i < 1000; i++)
    {
        *(c1 + i) = c2[i] = c3[i] = c4[i] = c5[i] = '\0';
    }
    c = getchar();
    for (int i = 0; (c != ' ') && (c != '\n'); i++)
    {
        c2[i] = c;
        c = getchar();
    }
    if (!(0 == strcmp(c2, "--file")))
    {
        printf("invalid command");
        return;
    }
    else
    {
        ADRES();
    }
    for (int i = 0; i < 1000; i++)
    {
        c3[i] = c2[i] = '\0';
    }
    c = getchar();
    for (int i = 0; (c != ' ') && (c != '\n'); i++)
    {
        c2[i] = c;
        c = getchar();
    }
    if (!(0 == strcmp(c2, "--pos")))
    {
        printf("invalid command");
        return;
    }
    else
    {
        strcat(adress, "\\clipboard.txt");
        FILE *fail3 = fopen(adress, "r");
        for (int i = 0; !feof(fail3); i++)
        {
            c4[i] = fgetc(fail3);
        }
        fclose(fail3);

        int tedadchar = strlen(c4);
        c4[tedadchar - 1] = '\0';
        char c6[2000];
        for (int i = 0; i < 100; i++)
        {
            c5[i] = '\0';
        }
        scanf("%d:%d", &x, &y);
        FILE *fail = fopen(c1, "r");
        for (int i = 0; !feof(fail); i++)
        {

            c5[i] = fgetc(fail);
        }
        for (int i = 0, j = 1; i < 1000; i++)
        {
            if (c5[i] == '\n')
            {
                j++;
            }
            if (j == x)
            {
                POS = i;
                break;
            }
        }
        for (int i = 0; i < POS + y; i++)
        {
            c6[i] = c5[i];
        }
        for (int i = POS + y; i < POS + y + tedadchar; i++)
        {
            c6[i] = c4[i - POS - y];
        }
        int i;
        for (i = POS + y + tedadchar;; i++)
        {
            if (c5[i - tedadchar] == '\0')
            {
                break;
            }
            c6[i - 1] = c5[i - tedadchar];
            // printf(",%c", c5[i - tedadchar]);
            // printf(".%c", c6[i]);
            // printf("%s\n", c6);
        }
        c6[i - 2] = '\0';
        fclose(fail);
        FILE *fail2 = fopen(c1, "w");
        fprintf(fail2, c6);
        fclose(fail2);
    }
}
void find()
{
    char c3[1000];
    for (int i = 0; i < 1000; i++)
    {
        c2[i] = c3[i] = c4[i] = '\0';
    }

    // c1 for adress
    // c2 --
    // c4 string
    c = getchar();
    for (int i = 0; (c != ' ') && (c != '\n'); i++)
    {
        c2[i] = c;
        c = getchar();
    }
    if (!(0 == strcmp(c2, "--str")))
    {
        printf("invalid command");
        return;
    }
    else
    {
        z = 9124837;
        getcharacter();
    }
    for (int i = 0; i < 1000; i++)
    {
        c3[i] = c2[i] = '\0';
    }
    c = getchar();
    if (c != '-')
    {
        c = getchar();
    }
    for (int i = 0; (c != ' ') && (c != '\n'); i++)
    {
        c2[i] = c;
        c = getchar();
        // printf("%d ",c);
    }
    if (!(0 == strcmp(c2, "--file")))
    {
        printf("invalid command");
        return;
    }
    else
    {
        ADRES();
    }
    if (c == ' ')
    {
        // printf("ll");
        c = getchar();
    }
    // if (c != '\n')
    // {
    //     // vijegi
    // }
    // else
    {
        nokhostin();
    }
}
void nokhostin()
{
    int vaziat = 0;
    char c, c5[1000], c3[1000], c6[1000], c7[1000], c8[1000];
    for (int i = 0; i < 1000; i++)
    {
        c3[i] = c5[i] = c6[i] = c7[i] = c8[i] = '\0';
    }
    FILE *fail = fopen(c1, "r");
    for (int i = 0; !feof(fail); i++)
    {
        c3[i] = fgetc(fail);
    }
    fclose(fail);
    // printf("%s\n%d", c4, zz);
    int tedadchar2 = strlen(c4);
    int spaceghabl = -1, spacebaad = tedadchar2;
    for (int i = zz - 1; i > -1; i--)
    {
        if (c4[i] == ' ')
        {
            // printf("pp");
            spaceghabl = i;
        }
    }
    for (int i = zz;; i++)
    {
        if (c4[i] == ' ')
        {
            // printf("pop");
            spacebaad = i;
            break;
        }
        if (c4[i] == '\0')
        {
            spacebaad = i;
            break;
        }
    }
    if (z == 9124839)
    {
        for (int i = 0; i <= spaceghabl; i++)
        {
            c6[i] = c4[i];
        }
        for (int i = spaceghabl + 1; i < spacebaad; i++)
        {
            c8[i - spaceghabl - 1] = c4[i];
        }
        for (int i = spacebaad;; i++)
        {
            c7[i - spacebaad] = c4[i];
            // printf("%d  %c  %d",spacebaad,c4[i],zz);
            if (c4[i] == '\0')
            {
                break;
            }
        }
    }
    if (z == 9124830)
    {
        for (int i = 0; i < spaceghabl; i++)
        {
            c6[i] = c4[i];
        }
        for (int i = spaceghabl; i < spacebaad; i++)
        {
            // printf(";;");
            c8[i - spaceghabl] = c4[i];
        }
        for (int i = spacebaad;; i++)
        {
            c7[i - spacebaad] = c4[i];
            if (c4[i] == '\0')
            {
                break;
            }
        }
    }
    // printf("%s;%s;%s;",c6,c7,c8);

    int k = 0;
    for (int i = 0;; i++)
    {
        if (z == 9124837)
        {
            // printf("//%c   %d//", c3[i], i);
            if (c3[i] == c4[0])
            {
                // printf("kk");
                for (int j = 0; j < tedadchar2; j++)
                {
                    c5[j] = c3[i];
                    i++;
                    // printf("%c %d", 2, tedadchar2);
                    if (c3[i] == '\0')
                    {
                        break;
                    }
                }
            }
            // printf("|%s;%s|", c4, c5);
            // return;
            if (0 == strcmp(c5, c4))
            {
                vaziat = 1;
                printf("%d\n", i - tedadchar2 + 1);
                for (int i = 0; i < 1000; i++)
                {
                    c5[i] = '\0';
                }
                break;
            }
            else
            { // printf("jj");

                for (int i = 0; i < 1000; i++)
                {
                    c5[i] = '\0';
                }
                if (c3[i] == '\0')
                {
                    break;
                }
            }
        }
        else if (z == 9124839)
        {
            printf("%d\n", i);
            if (c6[0] == '\0')
            {
                vaziat = 1;
                k = 1;
            }
            // printf("'%c'\n",c6[0]);
            if (c3[i] == c6[0])
            {
                // printf("%dkk",i);
                for (int j = 0; j < spaceghabl + 1; j++)
                {
                    c5[j] = c3[i];
                    i++;
                    if (c3[i] == '\0')
                    {
                        break;
                    }
                }
            }
            else
            {
                if (c6[0] != '\0')
                {
                    continue;
                }
            }
            // printf(";%s;%s;%s;\n",c6, c8, c7);
            // break;

            if (0 == strcmp(c5, c6))
            {
                vaziat = 1;
                k = 1;
                // printf("%d\n", i - tedadchar2 + 1);
                for (int u = 0; u < 1000; u++)
                {
                    c5[u] = '\0';
                }
            }
            else
            {
                for (int u = 0; u < 1000; u++)
                {
                    c5[u] = '\0';
                }
                if (c3[i] == '\0')
                {
                    break;
                }
            }
            if (vaziat != 1 && vaziat != 2)
            {
                vaziat = 0;
                continue;
            }
            int ay;
            return;
            printf("%d\n", i);

            while (c3[i] != ' ')
            {
                i++;
            }
            i -= 1;
            printf("%d\n", i);
            ay = i;
            printf("'%c'  |  %c\n%d", c3[i], c8[spacebaad - zz], i);
            // break;
            if (c3[i] == c8[spacebaad - zz])
            {
                for (int j = spacebaad - zz; j >= 0; j--)
                {
                    // printf("%d", j);
                    c5[j] = c3[i];
                    i--;
                    if (c3[i] == '\0')
                    {
                        break;
                    }
                }
            }
            printf(";|%s;%s;%s;\n", c5, c7, c8);
            if (0 == strcmp(c5, c8))
            {
                vaziat *= 2;
                // printf("%d\n", i - tedadchar2 + 1);
                for (int u = 0; u < 1000; u++)
                {
                    c5[u] = '\0';
                }
            }
            else
            {
                for (int u = 0; u < 1000; u++)
                {
                    c5[u] = '\0';
                }
                if (c3[i] == '\0')
                {
                    break;
                }
            }
            if (vaziat != 2)
            {
                vaziat = 0;

                continue;
            }
            /// @brief ///
            i = ay + 1;
            if (c3[i] == c7[0])
            {
                for (int j = 0; j < tedadchar2 - spacebaad; j++)
                {
                    c5[j] = c3[i];
                    i++;
                    if (c3[i] == '\0')
                    {
                        break;
                    }
                }
            }
            printf("%s;%s;%s;\n", c6, c5, c7);
            // printf("%c  |  %c\n", c3[i], c8[spacebaad - zz]);
            // break;
            if (0 == strcmp(c5, c7))
            {
                vaziat *= 2;
                // printf("%d\n", i - tedadchar2 + 1);
                for (int i = 0; i < 1000; i++)
                {
                    c5[i] = '\0';
                }
                // printf("%d", vaziat);
                if (vaziat == 4)
                {
                    printf("%d\n", ay - zz + 1);
                }
                break;
            }
            else
            {
                for (int u = 0; u < 1000; u++)
                {
                    c5[u] = '\0';
                }
                if (c3[i] == '\0')
                {
                    break;
                }
            }
        }
        else
        {
        }
    }
    if (vaziat == 0)
    {
        printf("-1");
    }
}
void grep()
{
}
void compare() {}
void replace() {}
void undo() 
{
    char c3[1000];
    for (int i = 0; i < 1000; i++)
    {
        *(c1 + i) = c2[i] = c3[i] = '\0';
    }
    c = getchar();
    for (int i = 0; (c != ' ') && (c != '\n'); i++)
    {
        c2[i] = c;
        c = getchar();
    }
    if (!(0 == strcmp(c2, "--file")))
    {
        printf("invalid command");
    }
    else
    {
        char c2[1000], c3[1000];
        for (int i = 0; i < 1000; i++)
        {
            *(c1 + i) = c2[i] = c3[i] = '\0';
        }
        c = getchar();
        int x1 = 1, z1 = 0;
        for (int i = 0; c != '\n'; i++)
        {
            if (c == '"')
            {
                x1 *= 2;
                if (x1 % 4 == 0)
                {
                    z1 = 1;
                }
                continue;
            }
            if (z1 == 1 && (c == ' '))
            {
                break;
            }
            if (c == '/')
            {
                c = '\\';
            }

            c3[i] = c;
            c = getchar();
            if (x1 == 1 && (c == ' '))
            {
                break;
            }
        }
        strcat(c1, adress);
        strcat(c1, backeslash);
        strcat(c1, c3);
        FILE *dirr = fopen(c1, "r");
        if (dirr == NULL)
        {
            printf("Eror:File is not exists\n");
            return;
        }
        // printf("%s", c3);
        char b[1000], d[1000];
        for (int i = 0; i < 1000; i++)
        {
            b[i] = d[i] = c1[i] = '\0';
        }
        b[0] = '\\';
        b[1] = 'r';
        b[2] = 'o';
        b[3] = 'o';
        b[4] = 't';
        b[5] = '2';
        for (int i = 0; i < 1000; i++)
        {
            b[i + 6] = c3[i + 5];
        }

        strcat(c1, adress);
        strcat(c1, backeslash);
        strcat(c1, b);int t=0;
        FILE *fail = fopen(c1, "r");
        for (int i = 0; !feof(fail); i++)
        {
            d[i] = fgetc(fail);
            t=i;
        }d[t]='\0';
        fclose(fail);
        for (int i = 0; i < 1000; i++)
        {
            c1[i] = '\0';
        }
        strcat(c1, adress);
        strcat(c1, backeslash);
        strcat(c1, c3);
        FILE *fail2 = fopen(c1, "w");
        fprintf(fail2, d);
        fclose(fail2);
        // printf("'%s','%s','%s'", c1, c3, d);
        printf("you are GOOD %c\n",1);
    }
}
void auto_indent() {}
void tree() {}
void redo(char *a)
{
    char d[1000], b[1000], c3[1000];
    for (int i = 0; i < 1000; i++)
    {
        b[i] = d[i] = '\0';
    }

    b[0] = '\\';
    b[1] = 'r';
    b[2] = 'o';
    b[3] = 'o';
    b[4] = 't';
    b[5] = '2';
    for (int i = 5;; i++)
    {
        if (*(a + i) == '\0')
        {
            break;
        }
        b[i + 1] = *(a + i);
    }
    FILE *fail = fopen(c1, "r");
    int t = 0;
    for (int i = 0; !feof(fail); i++)
    {
        c3[i] = fgetc(fail);
        t = i;
    }
    c3[t] = '\0';
    fclose(fail);
    strcat(d, adress);
    strcat(d, backeslash);
    strcat(d, b);
    c4[0] = b[0];

    for (int i = 1, j = 1;; j++, i++)
    {

        if (b[i] == '\0')
        {
            break;
        }
        if (b[i] == '/' || b[i] == '\\')
        {
            // strcat(adress, backeslash);
            strcat(adress, c4);
            // printf("%s;\n", c4);
            mkdir(adress);
            for (int k = 0; k < 1000; k++)
            {
                c4[k] = '\0';
            }
            j = 0;
            c4[j] = b[i];
            // printf("Q");
        }
        else
            c4[j] = b[i];
    }
    FILE *dirr = fopen(d, "w");
    fprintf(dirr, c3);
    fclose(dirr);
}
