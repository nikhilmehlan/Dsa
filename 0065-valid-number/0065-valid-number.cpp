class Solution {
public:
    bool isNumber(string s) {
        int state = 1;
        bool isNum = 0;
        for(char c : s){
            bool a; // a -> acceptable
            if(state == 1){
                a = isSign(c) || c == '.' || isdigit(c);
                if(!a) return 0;
                if(isSign(c)) state = 2;
                if(c == '.') state = 3;
                if(isdigit(c)) state = 4;
            }
            else if(state == 2){
                a = c == '.' || isdigit(c);
                if(!a) return 0;
                if(c == '.') state = 3;
                if(isdigit(c)) state = 4;
            }else if(state == 3){
                a = isdigit(c) || (isExp(c) && isNum);
                if(!a) return 0;
                if(isdigit(c)) state = 5;
                if(isExp(c)) state = 6;
            }else if(state == 4){
                a = isdigit(c) || c == '.' || isExp(c);
                if(!a) return 0;
                if(c == '.'){
                    state = 3;
                    isNum = 1;
                }
                if(isExp(c)) state = 6;
            }else if(state == 5){
                a = isdigit(c) || isExp(c);
                if(!a) return 0;
                if(isExp(c)) state = 6;
            }else if(state == 6){
                a = isdigit(c) || isSign(c);
                if(!a) return 0;
                if(isdigit(c)) state = 8;
                if(isSign(c)) state = 7;
            }else if(state == 7){
                a = isdigit(c);
                if(!a) return 0;
                state = 8;
            }else if(state == 8){
                a = isdigit(c);
                if(!a) return 0;
            }
        }
        if((state == 3 && isNum == 1) || state == 4 || state == 5 || state == 8)
            return 1;
        return 0;
    }

private:
    bool isSign(char c){
        return c == '+' || c == '-';
    }
    
    bool isExp(char c){
        return c == 'e' || c == 'E';
    }
};