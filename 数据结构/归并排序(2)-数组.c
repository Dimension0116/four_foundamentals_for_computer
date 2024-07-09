/*
巴拉巴拉巴拉，其实和链表的实现一样的，只是存储结构变了。思路还是一样的，改成左右指针即可。
1、合并函数
2、归并排序
*/


// 合并两个已排序的子数组为一个有序数组
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;  // 左子数组的长度
    int n2 = r - m;      // 右子数组的长度

    int L[n1], R[n2];    // 用于存储左右子数组

    // 复制数据到辅助数组
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;  // 初始化指针

    // 合并两个子数组回到原数组
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // 复制剩余的元素
    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}
// 归并排序函数
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;  // 找到中间位置

        // 对左边的子数组进行归并排序
        mergeSort(arr, l, m);
        // 对右边的子数组进行归并排序
        mergeSort(arr, m + 1, r);

        // 合并两个已排序的子数组
        merge(arr, l, m, r);
    }
}
