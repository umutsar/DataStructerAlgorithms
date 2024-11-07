
void insertionSort(int dizi[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = dizi[i];
        int j = i - 1;
        while (j >= 0 && dizi[j] > key)
        {
            dizi[j + 1] = dizi[j];
            j--;
        }
        dizi[j + 1] = key;
    }
}
