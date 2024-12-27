/*

Rev a linked list

ListNode *reverse(ListNode* b){
    ListNode *a = NULL;

    while(b){
        ListNode *c = b->next;
        b->next = a;
        a = b;
        b = c;
    }   
}

Pseudo Code :

    prev, curr;

    while(curr){
        Next = curr->next;  // isko temp var me store karlo

        curr->next = prev; // curr k next pointer ko prev par direct kardo.

        prev = curr;  // prev ka ptr ++
        curr = Next;  // cur ka ptr ++

        Note : prev & curr aren't connect 
        
        [ 1<--2<--(prev)  (curr)-->5-->6... ] esa hai.
                              
                             / \
                             /
                            /
        [ 1<--2<--(prev)  (curr)   5-->6... ]

                           / \
                            |
                            |
        [ 1<--2<--(prev)  (curr)   5-->6... ]

                         / \
                           \
                            \
        [ 1<--2<--(prev)  (curr)   5-->6... ]

        [ 1<--2<--(prev)<--(curr)   5-->6...]

        [ 1<--2<--(3)<--(prev)      5-->6...]   // prev = curr

        [ 1<--2<--(3)<--(prev) (curr)-->6...]  // curr = Next

    }


    Next Greater Element.

    vector<int> v = {1,4,2,7,3,1,8}

    vector<int> NGE(vector<int>&v){
        int n = v.size();
        vector<int> nge(n, inf);
        stack<int> st;

        for(int i=n-1; i>=0; i--){
            
            while(!st.empty() && st.top()<v[i]){
                st.pop();
            }

            if(!st.empty()){
                nge[i] = st.top();
            }

            st.push(v[i]);
        }

        retun nge;
    }

    vector<int> NSE(vector<int>&v){
        int n = v.size();
        vector<int> nse(n, -inf);
        stack<int> st;

        for(int i=n-1; i>=0; i--){
            
            while(!st.empty() && st.top()>v[i]){
                st.pop();
            }

            if(!st.empty()){
                nse[i] = st.top();
            }

            st.push(v[i]);
        }

        return nse;
    }

    vector<int> PGE(vector<int>&v){
        int n = v.size();
        vector<int> pge(n, inf);
        stack<int> st;

        for(int i=0; i<n; i++){

            while(!st.empty() && st.top()<=v[i]){
                st.pop();
            }

            if(!st.empty()){pge[i] = st.top();}

            st.push(v[i]);
        }

        return pge;
    }


    Sorting Algos ->
    Merge Sort :
    Selection Sort : (select the min & move it left)
    Insertion Sort : Shifting of integers, make sorted from left to right.
    Bubble Sort :  Adjacent Element Swap , make sorted from right to left.
    Quick Sort : 

    !MERGE SORT

    void mergeArr(vector<int> &v, int l, int mid, int r){
        vector<int> left, right;

        for(int i=l; i<mid; i++){
            left.push_back(v[i]);
        }
        for(int i=mid; i<r; i++){
            right.push_back(v[i]);
        }

        int a = 0, b = 0, ptr = l;
        while(a<left.size() && b<right.size()){
            if(left[a]<=right[b]){
                v[ptr++] = left[a++];
            }
            else{
                v[ptr++] = right[b++];
            }
        }

        while(a<left.size()){
            v[ptr++] = left[a++];
        }
        while(b<right.size()){
            v[ptr++] = right[b++];
        }
    
    }

    void mergeSort(vector<int>&v, int l, int r){
        if(r-l<2){return;}

        int mid = (l+r)/2;
        mergeSort(v, l, mid-1);
        mergeSort(v, mid, r);
        mergeArr(v, l, mid, r);
    }

    !SELECTION SORT

    void selectionSort(vector<int> &v){
        int n = v.size();

        for(int i=0; i<n; i++){
            int min = v[i], minIdx = i;

            for(int j=i; j<n; j++){
                if(v[j]<min){
                    min = v[j];
                    minIdx = j;
                }
            }

            swap(v[i], v[minIdx]);
        }
    }

    !INSERTION SORT

    void insertionSort(vector<int> &v){
        int n = v.size();

        for(int i=1; i<n; i++){
            int key = v[i], j = i;
            while(j>0 && v[j-1]>key){
                v[j] = v[j-1];
                j--;
            } 
            v[j] = key;
        }
    }

    ! Bubble Sort.

    void bubbleSort(vector<int> &v){
        int n = v.size();

        for(int i=0; i<n-1; i++){
            for(int j=0; j<n-1-i; j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j], arr[j+1]);
                }
            }
        }
    }

    !Quick Sort

    1. Divide & conquer.
    2. pick a pivot element(1st element), place it in its correct position,
    3. move all element smaller to pivot element in its left(i.e all element greater than pivot is automatically at right) -> order of left & right part can be random.
    2. Repeat step 2+3 untill arr size is 1.

    ctMini = 2; 
    {3,6,5,2,1,4} -> {5,6,3,2,1,4};


    int partition(vector<int>&v, int lo, int hi){
        int pivot = v[lo], ctMini = 0;    // Take 1st element as pivot.

        for(int i=lo+1; i<=hi; i++){
            if(v[i]<=pivot){ctMini++;}// elements equal to pivot should be left of pivot 
        }

        int pivotIdx = lo + ctMini;
        swap(v[lo], v[pivotIdx]);  // placing pivot at its correct position.

        while(lo<pivotIdx && hi>pivotIdx){
            while(lo<pivotIdx && v[lo]<=pivot){
                lo++;
            }

            while(hi>pivotIdx && v[hi]>pivot){
                hi--;
            }

            if(lo<pivotIdx && hi>pivotIdx){
                swap(v[lo], v[hi]);
                lo++; hi--;
            }
        }

        return pivotIdx;
    }

    void quickSort(vector<int>&v, int lo, int hi){
        if(lo>=hi){return;}

        int idx = partition(v, lo, hi);
        quickSort(v, lo, idx-1);
        quickSort(v, idx+1, hi);
    }
























    
*/