- 当0位于零点时，需要向后找第一个不在其正确位置上的数，如果每次都从pos = 1的位置开始往后遍历，则时间复杂度会很高（测试点1/2挂掉），可以把每次遍历得到的那个位置保存下来，作为下次遍历的起点，这是因为每次遍历找到的位置都能保证在此之前所有的数（除0外）都在其正确的位置上