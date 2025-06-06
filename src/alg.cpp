// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int counter_1 = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        counter_1;
      }
    }
  }
  return counter_1;
}
int countPairs2(int *arr, int len, int value) {
  int counter_2 = 0, left = 0, right = len - 1;
  for (int i = 0; i < right; ++i) {
    for (int j = right - 1; j > left; --j) {
      if (arr[j] > value) {
        right -= 1;
      }
      if (arr[i] + arr[j] == value) {
        counter_2 += 1;
      }
    }
    left += 1;
  }
  return counter_2;
}
int binSearch(int* array, int start, int end, int val) {
  int firstCase = -1, lastCase = -1;
  int low = start, high = end;
  while (low <= high) {
    int middle = low + (high - low) / 2;
    if (array[middle] >= val) {
      if (array[middle] == val) {
        firstCase = middle;
      }
      high = middle - 1;
    } else {
      low = middle + 1;
    }
  }
  if (firstCase == -1) return 0;
  low = firstCase;
  high = end;
  while (low <= high) {
    int middle = low + (high - low) / 2;
    if (array[middle] <= val) {
      if (array[middle] == val) {
        lastCase = middle;
      }
      low = middle + 1;
    } else {
      high = middle - 1;
    }
  }
  return (lastCase - firstCase) + 1;
}
int countPairs3(int* arr, int len, int value) {
  int pairs = 0;
  for (int i = 0; i < len; i++) {
    pairs += binSearch(arr, i + 1, len - 1, value - arr[i]);
  }
  return pairs;
}
