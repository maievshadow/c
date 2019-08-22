//
// Created by redredmaple on 1/3/19.
//

void sum_test(int argc, char ** argv)
{
    if (argc < 1){
        printf("Usage:\n");
    }

    int nums[4] = {2, 7, 11, 15};

    pr(nums, 4);
    int * answer = twoSum(nums, 4, 20);
    pr(answer, 2);
}

