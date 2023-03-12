
stack_st_X509_POLICY_NODE * X509_policy_tree_get0_policies(X509_POLICY_TREE *tree)

{
  if (tree != (X509_POLICY_TREE *)0x0) {
    return *(stack_st_X509_POLICY_NODE **)(tree + 0xc);
  }
  return (stack_st_X509_POLICY_NODE *)0x0;
}

