
int X509_policy_level_node_count(X509_POLICY_LEVEL *level)

{
  int iVar1;
  uint uVar2;
  
  if (level != (X509_POLICY_LEVEL *)0x0) {
    uVar2 = (uint)(*(int *)(level + 8) != 0);
    if (*(int *)(level + 4) != 0) {
      iVar1 = (*(code *)PTR_sk_num_006a7f2c)();
      uVar2 = iVar1 + uVar2;
    }
    return uVar2;
  }
  return 0;
}

