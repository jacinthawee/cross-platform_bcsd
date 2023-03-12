
X509_POLICY_NODE * X509_policy_level_get0_node(X509_POLICY_LEVEL *level,int i)

{
  bool bVar1;
  X509_POLICY_NODE *pXVar2;
  
  if (level == (X509_POLICY_LEVEL *)0x0) {
    pXVar2 = (X509_POLICY_NODE *)0x0;
  }
  else {
    pXVar2 = *(X509_POLICY_NODE **)(level + 8);
    if ((pXVar2 == (X509_POLICY_NODE *)0x0) || (bVar1 = i != 0, i = i + -1, bVar1)) {
                    /* WARNING: Could not recover jumptable at 0x0059d0a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pXVar2 = (X509_POLICY_NODE *)(*(code *)PTR_sk_value_006a7f24)(*(undefined4 *)(level + 4),i);
      return pXVar2;
    }
  }
  return pXVar2;
}

