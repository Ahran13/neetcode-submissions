class KthLargest
{
public:
    vector<int> arr;
    int size = 0;
    int k;

    KthLargest(int k, vector<int>& nums)
    {
        this->k = k;
        for (int n : nums)
            add(n);
    }

    // Heapify Up - Min Heap
    void insert(int val)
    {
        arr.push_back(val);
        size++;

        int i = size - 1;

        while (i > 0)
        {
            int parent = (i - 1) / 2;

            if (arr[parent] <= arr[i])
                break;

            swap(arr[parent], arr[i]);
            i = parent;
        }
    }

    // Heapify Down - Min Heap
    void heapify(int i)
    {
        int smallest = i;

        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && arr[left] < arr[smallest])
            smallest = left;

        if (right < size && arr[right] < arr[smallest])
            smallest = right;

        if (smallest == i)
            return;

        swap(arr[i], arr[smallest]);

        heapify(smallest);
    }

    int delMin()
    {
        int minValue = arr[0];

        arr[0] = arr[size - 1];
        arr.pop_back();
        size--;

        if (size > 0)
            heapify(0);

        return minValue;
    }

    int add(int val)
    {
        insert(val);
        if (size > k)
            delMin();
        return arr[0];
    }
};