class ProductOfNumbers {
public:
    
    vector<int> products;
    
    int last_zero;
    
    ProductOfNumbers() {
        products.push_back(1);
    }
    
    void add(int num) {
        if(num!=0){
            products.push_back(products.back()*num);
        } else {
            products = {1};
        }
    }
    
    int getProduct(int k) {
        int n = products.size();
        return (n-k-1 >= 0) ? (products.back()/products[n-k-1]) : 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */