class Solution:
    def trailingZeroes(self, n: int) -> int:
        # save = [(-1,-1) for i in range(n+1)]
        num_2 = 0
        num_5 = 0
        
        for i in range(n):
            num = i+1
            cur_2 = 0
            cur_5 = 0
            
            # 1 2 3 4 5 6 7 8 9 10
            
            while num > 1:
                if(num % 5 == 0):
                    num = num / 5
                    cur_5 += 1
                else:
                    break
            num_5 += cur_5
            
        return num_5
    
            
        