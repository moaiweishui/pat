- 后续遍历
- 光看表达式像是中序遍历，但实际上是后续遍历
- 观察每个运算符号节点，都是需要将其左右子树的值连接起来，然后两边加上括号(root除外)，因此符合先遍历左右子树，再遍历根节点的特性，故为后续遍历