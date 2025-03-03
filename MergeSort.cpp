void merge(int dizi[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = dizi[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = dizi[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            dizi[k] = L[i];
            i++;
        }
        else
        {
            dizi[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        dizi[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        dizi[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int dizi[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(dizi, left, mid);
        mergeSort(dizi, mid + 1, right);
        merge(dizi, left, mid, right);
    }
}

// Usage: mergeSort(dizi, 0, size - 1);
