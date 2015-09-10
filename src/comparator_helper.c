int compare_char(void* left, void* right)
{
  char* left_value = (char*)left;
  char* right_value = (char*)right;

  if (*left_value < *right_value) {
    return -1;
  } else if (*left_value > *right_value) {
    return 1;
  } else {
    return 0;
  }
}

int compare_double(void* left, void* right)
{
  double* left_value = (double*)left;
  double* right_value = (double*)right;

  if (*left_value < *right_value) {
    return -1;
  } else if (*left_value > *right_value) {
    return 1;
  } else {
    return 0;
  }
}

int compare_float(void* left, void* right)
{
  float* left_value = (float*)left;
  float* right_value = (float*)right;

  if (*left_value < *right) {
    return -1;
  } else if (*left_value > *right) {
    return 1;
  } else {
    return 0;
  }
}

int compare_int(void* left, void* right)
{
  int* left_value = (int*)left;
  int* right_value = (int*)right;

  if (*left_value < *right_value) {
    return -1;
  } else if (*left_value > *right_value) {
    return 1;
  } else {
    return 0;
  }
}
