
X509_VERIFY_PARAM * X509_VERIFY_PARAM_lookup(char *name)

{
  int iVar1;
  X509_VERIFY_PARAM *pXVar2;
  int in_GS_OFFSET;
  char *local_30 [8];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_30[0] = name;
  if (param_table != (_STACK *)0x0) {
    iVar1 = sk_find(param_table,local_30);
    if (iVar1 != -1) {
      pXVar2 = (X509_VERIFY_PARAM *)sk_value(param_table,iVar1);
      goto LAB_08167325;
    }
  }
  pXVar2 = (X509_VERIFY_PARAM *)OBJ_bsearch_(local_30,default_table,5,0x20,table_cmp_BSEARCH_CMP_FN)
  ;
LAB_08167325:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pXVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

