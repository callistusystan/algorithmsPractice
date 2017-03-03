class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        bitList = []
        for i in range(num+1):
            nBits = 0
            j = i
            while j > 0:
                if j < len(bitList):
                    nBits += bitList[j]
                    break
                if j & 1:
                    nBits += 1
                j >>= 1

            bitList.append(nBits)
        return bitList

print(Solution().countBits(5))