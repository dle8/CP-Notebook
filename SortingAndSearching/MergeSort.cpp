const int MAXN = 10000 + 10;

vector<int> a(MAXN);

void merge_sort(vector<int> v, int left, int right) {
  if (size(v) == 1) {
    return;
  }
  int mid = (left + right) / 2;
  merge_sort(v, left, mid);
  merge_sort(v, mid + 1, right);

  int i = left, j = mid + 1;
  int cur = 0;

  while (i <= mid || j <= right) {
    if (i > mid) {
      a[curr++] = data[j++];
    } else if (j > right) {
      a[curr++] = data[i++];
    } else if (data[i] < data[j]) {
      a[curr++] = data[i++];
    } else {
      a[curr++] = data[j++];
    }
  }

  for (int i = 0; i < cur; i++) {
    data[left + i] = a[i];
  }
}
