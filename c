sort each participants weight

two pointer 1 in beginning, 1 in end

loop until b>e
if w[b] + w[e] > quota
   e--
   count++
else
   b++, e--
   count++