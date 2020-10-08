int majorityElement(int* nums, int numsSize){
    // 根据题意说找到大于数组长度一般的数字并返回
    // 这里采用摩尔投票法
    // count计数，num记录数组数字
    int count = 0;  
    int num = 0;
    for(int i = 0; i < numsSize; i++)
    {
        // 对于count等于0，则用num记录这个数
        if(count == 0)
        {
            num = nums[i];
        }

        // 对于数字相同的则count++，反之--
        if(num == nums[i])
            count++;
        else 
            count--;
    }
    return num;
}
