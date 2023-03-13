
int NAME_CONSTRAINTS_check(X509 *x,NAME_CONSTRAINTS *nc)

{
  int iVar1;
  X509_NAME *name;
  int iVar2;
  X509_NAME_ENTRY *ne;
  ASN1_STRING *pAVar3;
  int iVar4;
  int in_GS_OFFSET;
  
  iVar1 = *(int *)(in_GS_OFFSET + 0x14);
  name = X509_get_subject_name(x);
  iVar2 = X509_NAME_entry_count(name);
  if (iVar2 < 1) {
LAB_08174770:
    for (iVar4 = 0; iVar2 = sk_num((_STACK *)x->altname), iVar4 < iVar2; iVar4 = iVar4 + 1) {
      sk_value((_STACK *)x->altname,iVar4);
      iVar2 = nc_match();
      if (iVar2 != 0) goto LAB_081747a9;
    }
    iVar2 = 0;
  }
  else {
    iVar2 = nc_match();
    if (iVar2 == 0) {
      iVar4 = -1;
      do {
        iVar4 = X509_NAME_get_index_by_NID(name,0x30,iVar4);
        if (iVar4 == -1) goto LAB_08174770;
        ne = X509_NAME_get_entry(name,iVar4);
        pAVar3 = X509_NAME_ENTRY_get_data(ne);
        if (pAVar3->type != 0x16) {
          iVar2 = 0x35;
          break;
        }
        iVar2 = nc_match();
      } while (iVar2 == 0);
    }
  }
LAB_081747a9:
  if (iVar1 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}

