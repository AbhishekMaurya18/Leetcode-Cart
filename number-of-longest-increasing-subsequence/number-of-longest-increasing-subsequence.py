class Solution(object):
    def findNumberOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        n=len(nums)
        dp=[1]*n
        n_lis=[1]*n
    
        for i in range(n):
            for j in range(i):
                if nums[i]>nums[j]:
                    if dp[j]>=dp[i]:
                        dp[i]=dp[j]+1
                        n_lis[i]=n_lis[j]
                    elif dp[j]+1==dp[i]:
                        n_lis[i]+=n_lis[j]
                    
        count=0
        maxx=max(dp)
        #print(n_lis)
        for i,num in enumerate(dp):
            if num==maxx:
                count+=n_lis[i]
        return count
            
        
            
        