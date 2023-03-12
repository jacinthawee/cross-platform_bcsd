
int X509_policy_tree_level_count(X509_POLICY_TREE *tree)

{
  if (tree != (X509_POLICY_TREE *)0x0) {
    return *(int *)(tree + 4);
  }
  return 0;
}

