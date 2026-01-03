#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define REPO_URL "https://github.com/YOURNAME/bpm-repo.git"
#define PREFIX   "/usr/local"
#define TMPDIR   "/tmp/bpm-build"

void die(const char *msg) {
    fprintf(stderr, "[bpm] ERROR: %s\n", msg);
    system("rm -rf " TMPDIR);
    exit(1);
}

int file_exists(const char *path) {
    return access(path, F_OK) == 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("usage: bpm install <package>\n");
        return 1;
    }

    if (strcmp(argv[1], "install") != 0)
        die("unknown command");

    const char *pkg = argv[2];
    char cmd[512];
    char pkgpath[512];
    char makefile[512];

    /* Clean previous build */
    system("rm -rf " TMPDIR);

    /* Clone repo */
    printf("[bpm] cloning repo...\n");
    snprintf(cmd, sizeof(cmd),
             "git clone %s %s", REPO_URL, TMPDIR);
    if (system(cmd) != 0)
        die("git clone failed");

    /* Package path */
    snprintf(pkgpath, sizeof(pkgpath),
             "%s/%s", TMPDIR, pkg);
    if (!file_exists(pkgpath))
        die("package not found");

    /* Check Makefile */
    snprintf(makefile, sizeof(makefile),
             "%s/Makefile", pkgpath);
    if (!file_exists(makefile))
        die("Makefile missing");

    /* Build */
    printf("[bpm] building...\n");
    snprintf(cmd, sizeof(cmd),
             "cd %s && make", pkgpath);
    if (system(cmd) != 0)
        die("build failed");

    /* Install */
    printf("[bpm] installing...\n");
    snprintf(cmd, sizeof(cmd),
             "cd %s && make install PREFIX=%s",
             pkgpath, PREFIX);
    if (system(cmd) != 0)
        die("install failed");

    /* Cleanup */
    printf("[bpm] cleaning up\n");
    system("rm -rf " TMPDIR);

    printf("[bpm] %s installed successfully\n", pkg);
    return 0;
}
