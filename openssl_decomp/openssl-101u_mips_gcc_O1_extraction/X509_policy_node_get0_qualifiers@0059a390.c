
stack_st_POLICYQUALINFO * X509_policy_node_get0_qualifiers(X509_POLICY_NODE *node)

{
  if (node != (X509_POLICY_NODE *)0x0) {
    return *(stack_st_POLICYQUALINFO **)(*(int *)node + 8);
  }
  return (stack_st_POLICYQUALINFO *)0x0;
}

