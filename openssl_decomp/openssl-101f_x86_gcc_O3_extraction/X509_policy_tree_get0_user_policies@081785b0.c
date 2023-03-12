
stack_st_X509_POLICY_NODE * X509_policy_tree_get0_user_policies(X509_POLICY_TREE *tree)

{
  if (tree == (X509_POLICY_TREE *)0x0) {
    return (stack_st_X509_POLICY_NODE *)0x0;
  }
  if (((byte)tree[0x14] & 2) == 0) {
    return *(stack_st_X509_POLICY_NODE **)(tree + 0x10);
  }
  return *(stack_st_X509_POLICY_NODE **)(tree + 0xc);
}

