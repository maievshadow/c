#include <stdio.h>
#include <stdlib.h>

#include <error.h>
#include <string.h>

#include <shadow.h>
#include <grp.h>
#include <pwd.h>

#include <unistd.h>
#include <crypt.h>

void ex(void)
{
    printf("exit\n");
}

int
test()
{
    printf("ex %p\n", ex);
    printf("&ex %p\n", &ex);
    atexit(ex);

    /*
    struct spwd user;
    struct spwd *pUser;

    struct group *pgr;
    struct passwd *pwd;

    char * u = "redredmaple";
    pUser = getspnam(u);
    pgr = getgrnam(u);
    pwd = getpwnam(u);

    printf("%s\n", pUser->sp_namp);
    printf("%s\n", pgr->gr_name);
    printf("%s\n", pwd->pw_dir);

    char name[32] = "", *pwd;
    struct spwd *p;
    size_t namelen = 0;

    printf("enter your name:\n");
    fgets(name, 32, stdin);
    pwd = getpass("enter you pwd:\n");

    namelen = strlen(name);
    name[namelen - 1] = 0;

    p = getspnam(name);
    
    if (!p){
        perror("no name");
        //fpritnf(stderr, " error \n");
        return -1;
    }

    if (!strcmp(crypt(pwd, p->sp_pwdp), p->sp_pwdp))
        printf("erro\n");
    else
        perror("error");
        //fprintf(stderr, "erro\n");
    */
}