
int X509_NAME_add_entry(X509_NAME *name,X509_NAME_ENTRY *ne,int loc,int set)

{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  stack_st_X509_NAME_ENTRY *psVar6;
  
  if (name == (X509_NAME *)0x0) {
    return 0;
  }
  psVar6 = name->entries;
  iVar3 = (*(code *)PTR_sk_num_006a6e2c)(psVar6);
  if ((iVar3 < loc) || (loc < 0)) {
    name->modified = 1;
    loc = iVar3;
    if (set == -1) goto LAB_0057cf88;
    if (iVar3 != 0) goto LAB_0057d064;
LAB_0057cf14:
    bVar1 = true;
    iVar5 = 0;
  }
  else {
    name->modified = 1;
    if (set == -1) {
LAB_0057cf88:
      iVar3 = loc;
      if (iVar3 == 0) goto LAB_0057cf14;
      bVar1 = false;
      iVar5 = (*(code *)PTR_sk_value_006a6e24)(psVar6,iVar3 + -1);
      iVar5 = *(int *)(iVar5 + 8);
    }
    else {
      if (loc < iVar3) {
        iVar3 = (*(code *)PTR_sk_value_006a6e24)(psVar6,loc);
        iVar5 = *(int *)(iVar3 + 8);
        bVar1 = iVar5 == 0;
        iVar4 = (*(code *)PTR_X509_NAME_ENTRY_dup_006a8f30)(ne);
        goto joined_r0x0057cf2c;
      }
      iVar3 = loc;
      if (loc == 0) goto LAB_0057cf14;
LAB_0057d064:
      iVar3 = (*(code *)PTR_sk_value_006a6e24)(psVar6,loc + -1);
      iVar5 = *(int *)(iVar3 + 8) + 1;
      bVar1 = iVar5 == 0;
      iVar3 = loc;
    }
  }
  iVar4 = (*(code *)PTR_X509_NAME_ENTRY_dup_006a8f30)(ne);
  loc = iVar3;
joined_r0x0057cf2c:
  puVar2 = PTR_sk_insert_006a87bc;
  if (iVar4 == 0) {
    return 0;
  }
  *(int *)(iVar4 + 8) = iVar5;
  iVar3 = (*(code *)puVar2)(psVar6,iVar4,loc);
  if (iVar3 == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x71,0x41,"x509name.c",0x10d);
    (*(code *)PTR_X509_NAME_ENTRY_free_006a7150)(iVar4);
    return 0;
  }
  if ((bVar1) && (iVar3 = (*(code *)PTR_sk_num_006a6e2c)(psVar6), loc + 1 < iVar3)) {
    do {
      iVar4 = loc + 1;
      iVar5 = (*(code *)PTR_sk_value_006a6e24)(psVar6,loc);
      *(int *)(iVar5 + 8) = *(int *)(iVar5 + 8) + 1;
      loc = iVar4;
    } while (iVar3 + -1 != iVar4);
  }
  return 1;
}

