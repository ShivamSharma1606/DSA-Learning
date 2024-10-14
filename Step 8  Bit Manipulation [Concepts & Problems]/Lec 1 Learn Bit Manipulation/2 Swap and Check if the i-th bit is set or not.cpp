//swap the number without using third variable
//using xor
void swapNumber(int &a, int &b) {
	// Write your code here.
	a=a^b;
	b=a^b;//b=(a^b)^b=a
	a=a^b;//a=(a^b)^a=b
}

//Check if the i-th bit is set or not
//without converting into binary form

//using left shift operator
bool checkKthBit(int n, int k) {

    //using left shift
    if((n&(1<<k))!=0){
        return true;
    }
    false;
}

//using right shift operator
bool isKthBitSet(int n, int k)
{
    if(((n>>k-1) &1)==1){
        //we take k-1 because it take counting from 1
        return true;
    }
    return false;
}