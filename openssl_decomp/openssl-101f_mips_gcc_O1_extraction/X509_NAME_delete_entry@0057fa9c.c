
X509_NAME_ENTRY * X509_NAME_delete_entry(X509_NAME *name,int loc)

{
  int iVar1;
  X509_NAME_ENTRY *pXVar2;
  int iVar3;
  stack_st_X509_NAME_ENTRY *psVar4;
  int iVar5;
  
  if (name == (X509_NAME *)0x0) {
    return (X509_NAME_ENTRY *)0x0;
  }
  iVar1 = (*(code *)PTR_sk_num_006a7f2c)(name->entries);
  if ((loc < iVar1) && (-1 < loc)) {
    psVar4 = name->entries;
    pXVar2 = (X509_NAME_ENTRY *)(*(code *)PTR_sk_delete_006a8398)(psVar4,loc);
    iVar1 = (*(code *)PTR_sk_num_006a7f2c)(psVar4);
    name->modified = 1;
    if (loc != iVar1) {
      if (loc == 0) {
        iVar5 = pXVar2->set + -1;
      }
      else {
        iVar5 = (*(code *)PTR_sk_value_006a7f24)(psVar4,loc + -1);
        iVar5 = *(int *)(iVar5 + 8);
      }
      iVar3 = (*(code *)PTR_sk_value_006a7f24)(psVar4,loc);
      if ((iVar5 + 1 < *(int *)(iVar3 + 8)) && (loc < iVar1)) {
        do {
          iVar3 = loc + 1;
          iVar5 = (*(code *)PTR_sk_value_006a7f24)(psVar4,loc);
          *(int *)(iVar5 + 8) = *(int *)(iVar5 + 8) + -1;
          loc = iVar3;
        } while (iVar1 != iVar3);
      }
    }
    return pXVar2;
  }
  return (X509_NAME_ENTRY *)0x0;
}

