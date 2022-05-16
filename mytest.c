int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = (low - 1);
    int j = low;
    int temp = 0;
    for (j = low; j < high; j=j+1)
    {
        if (array[j] <= pivot)
        {
            i = i + 1;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return (i + 1);
}

int quickSort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
    return 0;
}