int max_recursive(int a[], int n) {
    if (n == 1) {
        return a[0];
    }
    int max = max_recursive(a + 1, n-1);
    if (max > a[0]) {
        return max;
    } else {
        return a[0];
    }
}