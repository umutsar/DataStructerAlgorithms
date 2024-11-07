void selectionSort(int dizi[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (dizi[j] < dizi[minIndex])
            {
                minIndex = j;
            }
        }
        int temp = dizi[i];
        dizi[i] = dizi[minIndex];
        dizi[minIndex] = temp;
    }
}
