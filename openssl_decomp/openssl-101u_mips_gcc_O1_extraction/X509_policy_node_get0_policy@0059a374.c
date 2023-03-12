
ASN1_OBJECT * X509_policy_node_get0_policy(X509_POLICY_NODE *node)

{
  if (node != (X509_POLICY_NODE *)0x0) {
    return *(ASN1_OBJECT **)(*(int *)node + 4);
  }
  return (ASN1_OBJECT *)0x0;
}

