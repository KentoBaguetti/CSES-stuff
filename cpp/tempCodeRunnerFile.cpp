 srand(time(0));
    vector<int> arr(100);
    generate(arr.begin(), arr.end(), []() { return rand() % 100; });