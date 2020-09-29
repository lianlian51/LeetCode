bool recur(int* postorder, int left, int right)
{
    int temp = left;
    if(left >= right)
        return true;
    while(postorder[left] < postorder[right])
        left++;
    for(int i = left; i < right; i++)
        if(postorder[i] < postorder[right])
            return false;
    return recur(postorder, temp, left-1)&&recur(postorder,left,right -1);
}

bool verifyPostorder(int* postorder, int postorderSize){
    return recur(postorder, 0, postorderSize -1);
}
