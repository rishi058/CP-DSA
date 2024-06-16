#include <bits/stdc++.h>
using namespace std;

#define int long long
#define tuple array<int, 3>
#define all(v) v.begin(), v.end()
#define F(a,b,i) for (int i = a; i < b; i++)
#define Rev(a,b,i) for (int i = a; i >= b; i--)
#define RISHI ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

template <typename dStruct>
void print(dStruct& vName){for(auto &it : vName){cout<<it<<" ";} cout<<"\n";}
template <typename dStruct>
void print2(dStruct& vName){for(auto &it : vName){cout<<"{"<<it.first<<", "<<it.second<<"} ";} cout<<"\n";}

const int mod = 1e9 + 7;
#define inf LONG_LONG_MAX
#define Min LONG_LONG_MIN

typedef long double ld;
typedef vector<int> vi;

//!------------------------ Practice like you've never won. Perform like you've never lost. ------------------------

/*
Condtion for checking if a '-' is unary minus.
1. If it is present at 0th index.
2. If it present after after a operator.
3. If it is present after '(' bracket.
*/

bool isdigit(char x){   // overwriting existing func for '.'
    vector<char> v = {'.','0','1','2','3','4','5','6','7','8','9'};
    if(binary_search(v.begin(), v.end(), x)){return 1;}
    return 0;
}

int prec(char x){
    if(x=='+' || x=='-'){return 1;}
    else if(x=='*' || x=='/' || x=='%'){return 2;}
    else if(x=='^'){return 3;}
    else if(x=='~'){return 10;}   // unary minus has highest precedence.
	return 0;
}

vector<string> infixToPostfix(string s) {
    vector<string> postfixExp;
    stack<char> st;  // use to store operators.
    string num;
    
    for(int i=0; i<s.size(); i++){
        if(isdigit(s[i])){
            num.push_back(s[i]);
        }
        else{  // if it is a operator.
            if(!num.empty()){postfixExp.push_back(num); num.clear();}
            if((s[i]=='-') && ( (i==0) || prec(s[i-1])!=0 || s[i-1]=='(')){  // checking for unary minus.
                st.push('~');
            }
            else if(st.empty() || s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                while(st.top()!='('){
                    postfixExp.push_back(string(1, st.top()));
                    st.pop();
                }
                st.pop();
            }
            else if(prec(st.top())>=prec(s[i])){
                while( !st.empty() && (prec(st.top())>=prec(s[i])) ){
                    postfixExp.push_back(string(1, st.top()));
                    st.pop();
                }
                st.push(s[i]);
            }
            else{st.push(s[i]);}
        }
        
    }

    if(!num.empty()){postfixExp.push_back(num);}
    
    while(!st.empty()){
        postfixExp.push_back(string(1, st.top()));
        st.pop();
    }
    
    return postfixExp;
}

long double applyOp(long double val1, long double val2, char op) {
    switch (op) {
        case '+': return val1 + val2;
        case '-': return val2 - val1;
        case '*': return val1 * val2;
        case '/': return val2 / val1;
        case '^': return pow(val1, val2);
        case '%': return (long long)val2 % (long long)val1;
        default : return -1; // Invalid operator
    }
}

long double calculate(string s){
    string infix;
    for(char x : s){if(x!=' '){infix.push_back(x);}}

    vector<string> exp = infixToPostfix(infix);
    stack<long double> st;
	
    for(int i=0; i<exp.size(); i++){
        if(exp[i].size()==1 && prec(exp[i][0])!=0){  // if it is a operator.
			long double val1 = st.top(); st.pop();
			if(exp[i][0]=='~'){  // if the operator is unary minus.
				st.push(-val1);
			}
			else{
				long double val2 = st.top(); st.pop();
                long double newVal = applyOp(val1, val2, exp[i][0]);
                st.push(newVal);
			}
        }
        else{
            st.push(stold(exp[i]));
        }
    }
    return st.top();
}

int32_t main()
{
	RISHI
	int T = 1;
	// cin>>T;
	while(T--)
	{
		string s;
		getline(cin, s);
		cout<<calculate(s);
	    
	}

}

// 2-(5-6)
// - (3 + (4 + 5))