#include <stdio.h>
#include <stdlib.h>

typedef unsigned char uint8_t;
typedef int int32_t;

int longestConsecutive(int* nums, int numsSize) {
	int*** parst_NumTable = (int***)malloc(sizeof(int**) * numsSize);
	int32_t s32_NumString = 0, s32_RetVal = 0, s32_MaxVal = 0;

	if (numsSize == 0)
	{
		return 0;
	}

	for (int32_t s32_I_String = 0; s32_I_String < numsSize; s32_I_String++)
	{
		parst_NumTable[s32_I_String] = (int**)malloc(sizeof(int*) * 2);
		parst_NumTable[s32_I_String][0] = NULL;
		parst_NumTable[s32_I_String][1] = NULL;
	}


	for (int32_t s32_I_num = 0; s32_I_num < numsSize; s32_I_num++)
	{
		if (s32_NumString == 0)
		{
			parst_NumTable[s32_NumString][0] = &nums[s32_I_num];
			parst_NumTable[s32_NumString][1] = &nums[s32_I_num];
			s32_NumString++;
		}
		else
		{
			for (int32_t s32_I_String = 0; s32_I_String < s32_NumString; s32_I_String++)
			{
				if (nums[s32_I_num] == *parst_NumTable[s32_I_String][0] - 1)
				{
					parst_NumTable[s32_I_String][0] = &(nums[s32_I_num]);
					break;
				}
				else if (nums[s32_I_num] == *parst_NumTable[s32_I_String][1] + 1)
				{
					parst_NumTable[s32_I_String][1] = &(nums[s32_I_num]);
					break;
				}
				else if (nums[s32_I_num] == *parst_NumTable[s32_I_String][0]
					|| nums[s32_I_num] == *parst_NumTable[s32_I_String][1])
				{
					break;
				}
				else
				{
					if (s32_NumString == numsSize)
					{
						break;
					}
					if (s32_I_String == s32_NumString - 1)
					{
						parst_NumTable[s32_NumString][0] = &(nums[s32_I_num]);
						parst_NumTable[s32_NumString][1] = &(nums[s32_I_num]);
						s32_NumString++;
						break;
					}
				}
			}
		}
	}

	for (int32_t s32_I_String = 0; s32_I_String < s32_NumString - 1; s32_I_String++)
	{
		for (int32_t s32_I_String2 = s32_I_String + 1; s32_I_String2 < s32_NumString; s32_I_String2++)
		{
			if ((*parst_NumTable[s32_I_String][1] < *parst_NumTable[s32_I_String2][0] - 1)
				|| (*parst_NumTable[s32_I_String][0] - 1 > * parst_NumTable[s32_I_String2][1]))
			{
				;
			}
			else
			{
				if (*parst_NumTable[s32_I_String][0] < *parst_NumTable[s32_I_String2][0])
				{
					(parst_NumTable[s32_I_String2][0]) = (parst_NumTable[s32_I_String][0]);
				}
				else
				{
					(parst_NumTable[s32_I_String][0]) = (parst_NumTable[s32_I_String2][0]);
				}

				if (*parst_NumTable[s32_I_String][1] < *parst_NumTable[s32_I_String2][1])
				{
					parst_NumTable[s32_I_String][1] = parst_NumTable[s32_I_String2][1];
				}
				else
				{
					parst_NumTable[s32_I_String2][1] = parst_NumTable[s32_I_String][1];
				}
			}

		}
	}

	for (int32_t s32_I_String = 0; s32_I_String < s32_NumString; s32_I_String++)
	{
		if (*parst_NumTable[s32_I_String][1] - *parst_NumTable[s32_I_String][0] > s32_MaxVal)
		{
			s32_MaxVal = *parst_NumTable[s32_I_String][1] - *parst_NumTable[s32_I_String][0];
		}
	}
	s32_RetVal = s32_MaxVal + 1;

	return s32_RetVal;
}

int main(void)
{
	int32_t ars32_List[10] = { 100,2,3,55,33,4,6,5,7,11 };
	int32_t s32_ret = 0;
	s32_ret = longestConsecutive(ars32_List, 10);
	printf("%d\n", s32_ret);

}