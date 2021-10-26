class Solution {
public:
    
    bool out_of_range(string num, string intMax, string intMin , bool negative){
        
        string compare_str; 
     
        if(negative)//負的 
            compare_str = intMin;//-2147483648
        else//正的
           compare_str = intMax;//2147483647
            
        for(int i=0;i<num.size();i++){
                if(num[i] > compare_str[i])// -3 -2 
                    return true;
                else if(num[i] < compare_str[i])
                    return false;
        }
        return false;
    }
        
    int reverse(int x) {
        if(x==0) // =0 
            return 0;
        
        int num =x;
        string reverseNum;//翻轉的數字字串
        string intMin = "2147483648" , intMax = "2147483647";//分別臨界點 -2^31 , 2^31-1
        //min的'-' 直接省略 比數字
        
        bool negative = false;//是否為負數
        
        if(x<0)
            negative = true;
        
        
        while(num % 10 == 0)
            num/=10;
        
       while(num){// 1230 -> 123
           char ch;
           if(negative)//負數的話
                ch = (num%10)*-1 + '0'; //%10 會是負的 先轉正 再變成char
           else
                ch = (num%10) + '0';
           //cout << " " << ch << " " ;
           reverseNum += ch;
                      
            if(reverseNum.size() == 10 ){ // size= 10 比較是否reverse後會超過臨界值
                
               if(out_of_range(reverseNum,intMax,intMin,negative))
                   return 0;
               else//沒超過
                   break;
           }
           num/=10;
        }
        
        int ans = stoi(reverseNum);//string to int
        
        if(negative) //負數
            ans = -ans; //最後要變回負的
        
        return ans;
    }
};
