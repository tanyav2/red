#include "libreso_redundant.h"

int storeRedundantly(char* file_path, char* buf, uint32_t buf_len, uint32_t num) {

  // Check if manifest for all manifest files exists
  char* man_root = "/man_root";
  if(access(man_root, F_OK) != -1) {
    // file exists
    printf("file exists\n");
  } else {
    // file doesn't exist so create it
    FILE *fp_man_root = fopen(man_root, "w+");
    if(fp_man_root != NULL) {
      printf("new file called man_root created\n");
    } else {
      printf("new file called man_root could not be created\n");
      return EXIT_FAILURE;
    }
  }

  int status;
  status = mkdir("/var/manifests", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
  if(status == 0) {
    printf("/var/manifests now exists\n");
  } else if (status == -1) {
    printf("/var/manifests couldnt be created\n");
  }

  // Create 3 manifest files in /var/libreso_red1,
  // /var/libreso_red2, /var/libreso_red3
  FILE *man_files[3];
  char man_file_path_const[256];
  strcpy(man_file_path_const, "/var/manifests/libreso_red");
  char* man_file_path;
  char file_num[2];

  for (int i = 0; i < 3; i++) {
    snprintf(file_num, sizeof(file_num), "%d", i+1);
    man_file_path = strcat(man_file_path_const, file_num);
    man_files[i] = fopen(man_file_path, "w+");

    if(man_files[i] == NULL) {
      printf("manifest file %d could not be created\n", i+1);
      return EXIT_FAILURE;
    }

    strcpy(man_file_path_const, "/var/manifests/libreso_red");
  }

  return EXIT_SUCCESS;

}
