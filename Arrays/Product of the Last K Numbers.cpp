////////////////////////////////////////Brute force//////////////////////////////////////
class ProductOfNumbers {
public:
    ProductOfNumbers() {
        
    }
    vector<int>nums;
    void add(int num) {
        nums.push_back(num);
    }
 
    
    int getProduct(int k) {
        int product = 1;
        int n = nums.size();
        for(int i =n-k; i<n; i++){
          product*=nums[i];
        }
        return product;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
////////////////Optimized Approach/////////////////////////////////////////////////////////////////
class ProductOfNumbers {
public:
    vector<int>nums;
    ProductOfNumbers() {
        nums.clear();        
    }
    int n = nums.size();
    void add(int num) {
        if(num==0){
          nums = {};
          n=0;
        }else{
            if(nums.empty()){
                nums.push_back(num);
            }else{
                nums.push_back(num*nums[n-1]);
            }
            n++;
        }        
    }
     
    int getProduct(int k) {
        int product = 1;
        if(k>n){
            return 0;
        }else if(k==n){
            return nums[n-1];
        }
        return nums[n-1]/nums[n-k-1];
    }
};
