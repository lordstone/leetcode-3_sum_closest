class Solution {
public:

    vector<int> mysort(vector<int>& x){ //non-descending order
        vector<int> arr = x;
        if(arr.size() == 1){
            return arr;
        }
        if(arr.size() == 2){
            if(arr[0]>arr[1]){
                int tmp = arr[0];
                arr[0] = arr[1];
                arr[1] = tmp;
            }
            return arr;
        }
        int midpoint = arr.size() / 2;
        vector<int> lo (arr.begin(),arr.begin() + midpoint);
        vector<int> hi (arr.begin() + midpoint, arr.end());
        lo = mysort(lo);
        hi = mysort(hi);
        vector<int> retval;
        retval.reserve(lo.size()+hi.size());
        int ptr1 = 0, ptr2 = 0;
        while(lo.size() > ptr1  && hi.size() > ptr2){
            if(lo[ptr1]<hi[ptr2]){
                retval.push_back((int)lo[ptr1]);
                ptr1++;
                if(ptr1 >= lo.size()){
                    retval.insert(retval.end(), hi.begin() + ptr2, hi.end());
                }//end if
            }else{
                retval.push_back((int)hi[ptr2]);
                ptr2++;
                if(ptr2 >= hi.size()){
                    retval.insert(retval.end(), lo.begin() + ptr1, lo.end());
                }//end if
            }//end if lo and hi
        }//end while
        return retval;
    }//end mysort

    int absVal(int x){
        if(x >= 0) return x;
        else return -x;
    }

    int threeSumClosest(vector<int>& nums, int target) {
        vector<int> myarr = mysort(nums);
        int temp = INT_MAX;
        int sum = 0;
        for(int i = 0; i < myarr.size() - 2; i ++){
            int start = i + 1, end = myarr.size() - 1;
            int neg = target - myarr[i];
            
            while(start < end){
                int dif = myarr[start] + myarr[end] - neg;
                if(absVal(dif) < temp) {
                    sum = myarr[i] + myarr[start] + myarr[end];
                    temp = absVal(dif);
                }
                if(dif > 0){
                    end --;
                }else{
                    start ++;
                }
                
                
            }//end while
        }//end for i
        return sum;
        
    }
};
