// 21.  Write  a  program  to  implement  a  Hash  Table  using  quadratic  probing  as  the  collision 
// resolution strategy. The table should support the following operations: 
// a. Insert 
// b. Search 

#include <stdio.h>
#include<stdlib.h>

int* createArray(int size) {
    int* arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = 0 ;
    }
    return arr;
}

 int* insertion(int* arr,int* flag,int cnt_inputs,int size)
{
    int input[cnt_inputs];
    for (int i = 0; i < cnt_inputs; i++)
    {
        int crr_input;
        scanf("%d", &crr_input);
        input[i] = crr_input;
    }
    for (int i = 0; i < cnt_inputs; i++)
    {
        int loc = input[i] % size;
        if (flag[loc] == 1)
        {
            for (int i = 1; i < size; i++)
            {
                int new_loc;
                new_loc = (loc + (i*i)) % size;
                if (flag[new_loc] == 1)
                {
                    continue;
                }
                else
                {
                    loc=new_loc;
                    break;
                }
            }
        }
        arr[loc] = input[i];
        flag[loc] = 1;
    }
    return arr;
}

int main()
{
    int size = 10;
    int* arr = createArray(size);
    int* flag = createArray(size);

    int cnt_inputs;
    printf("Enter no. of inputs : ");
    scanf("%d", &cnt_inputs);

    insertion(arr , flag ,cnt_inputs, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}
