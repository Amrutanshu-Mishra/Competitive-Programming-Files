# 📝 Dynamic Programming Problems

| Difficulty | Problem | Hint | Solution |
|------------|---------|------|----------|

| 1500 | [CF704C](https://codeforces.com/contest/1492/problem/C) | [Editorial](https://codeforces.com/blog/entry/87792) |
| 1600 | [CF122D](https://codeforces.com/contest/1555/problem/D) | [Editorial](https://codeforces.com/blog/entry/93389) | observe what type of strings which are made of a,b,c are such that no substrings of it are palindromes
| 1500 | [CF906B](https://codeforces.com/problemset/problem/1889/B) | [Editorial](https://codeforces.com/blog/entry/121813) | check this again it was very hard
| 1500 | [CF906B](https://codeforces.com/problemset/problem/1842/C) | [Editorial](https://codeforces.com/blog/entry/117606) | i know that if you want to delete a ball you may have multiple balls of the same color previously so which previous ball should you choose? the answer is for which the dp1's value is minimum(and this value is stored in dp2);
| Hard | [CF906B](https://leetcode.com/problems/binary-tree-cameras/description/?envType=problem-list-v2&envId=nbx4mwx6) | [Editorial]() | here 0 = no camera , 1=not needed and 2=has camera
| 1500 | [CF906B](https://codeforces.com/problemset/problem/1114/B) | [Editorial](https://codeforces.com/blog/entry/65136) | the highest possible sum for a given array will be if the sum=sum of the last m*k elements of the array(if the array is sorted) so the idea is enable this case to happen
| Med | [2768](https://leetcode.com/problems/number-of-black-blocks/?envType=problem-list-v2&envId=nbx4mwx6) | try this again
| 1600 | [CF906B](https://codeforces.com/contest/2136/problem/D) | [Editorial](https://codeforces.com/blog/entry/145796) | the idea is to make the robot go to the edge of the board(very intresting)
| 1700 | [CF870D](https://codeforces.com/contest/1826/problem/D) | [Editorial](https://codeforces.com/blog/entry/115892) | the main idea is to spot that in the formula val=bi1+bi2+bi3−(r−l) if i1<i2<i3 then i1=l and i3=r since if this not the case then val won't be maximum then the formula rearranges to val=(bi1+l) + bi2 + (bi3-r) and for that we need three arrays. 
| 1500 | [CF870D](https://codeforces.com/problemset/problem/2107/C) | [Editorial](https://codeforces.com/blog/entry/142642) | try this again as you couldn't solve it
| medium | [1733](https://leetcode.com/problems/minimum-number-of-people-to-teach/?envType=daily-question&envId=2025-09-10) | this was a very good adhoc which i couldn't solve
| hard | [VK round 1 D](https://codeforces.com/contest/161/problem/D) | dp on tree + (inclusion - exclusion)