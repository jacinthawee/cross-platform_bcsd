
int X509_policy_level_node_count(X509_POLICY_LEVEL *level)

{
  int iVar1;
  uint uVar2;
  
  if (level != (X509_POLICY_LEVEL *)0x0) {
    uVar2 = (uint)(*(int *)(level + 8) != 0);
    if (*(_STACK **)(level + 4) != (_STACK *)0x0) {
      iVar1 = sk_num(*(_STACK **)(level + 4));
      uVar2 = uVar2 + iVar1;
    }
    return uVar2;
  }
  return 0;
}

