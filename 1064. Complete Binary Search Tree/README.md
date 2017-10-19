- 对一个完全BST进行中序遍历，得到的刚好是一个非递减的序列，这是因为中序遍历特点：左->中->右，而BST中左->中->右功耗是非递减的
- 如果按照层次遍历的顺序给完全BST各节点标上序号，并对此序号进行中序遍历，就能得到一个序列（存的是节点序号），其标识了完全BST中各节点的大小顺序，只要把准备用来构建完全BST的数组升序排序后，一一映射过去，就能够完成完全BST的构造
- 例如，一个节点数量为7的完全BST，对其节点序号进行中序遍历得到3 1 4 0 5 2 6，这意味着这棵树中最小的节点是3号节点，次小是1号节点，以此类推