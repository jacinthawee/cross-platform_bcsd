
X509_VERIFY_PARAM * X509_VERIFY_PARAM_lookup(char *name)

{
  int iVar1;
  X509_VERIFY_PARAM *pXVar2;
  char *local_30 [9];
  
  local_30[0] = name;
  if ((param_table != (_STACK *)0x0) && (iVar1 = sk_find(param_table,local_30), iVar1 != -1)) {
    pXVar2 = (X509_VERIFY_PARAM *)sk_value(param_table,iVar1);
    return pXVar2;
  }
  pXVar2 = (X509_VERIFY_PARAM *)
           OBJ_bsearch_(local_30,&default_table,5,0x20,table_cmp_BSEARCH_CMP_FN + 1);
  return pXVar2;
}

