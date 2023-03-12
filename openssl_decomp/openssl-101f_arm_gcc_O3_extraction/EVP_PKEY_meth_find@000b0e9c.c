
EVP_PKEY_METHOD * EVP_PKEY_meth_find(int type)

{
  int iVar1;
  undefined4 *puVar2;
  EVP_PKEY_METHOD *pEVar3;
  int *local_78;
  int local_74 [27];
  
  local_78 = local_74;
  local_74[0] = type;
  if ((app_pkey_methods != (_STACK *)0x0) &&
     (iVar1 = sk_find(app_pkey_methods,local_78), -1 < iVar1)) {
    pEVar3 = (EVP_PKEY_METHOD *)sk_value(app_pkey_methods,iVar1);
    return pEVar3;
  }
  puVar2 = (undefined4 *)OBJ_bsearch_(&local_78,&standard_methods,6,4,pmeth_cmp_BSEARCH_CMP_FN + 1);
  if (puVar2 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*puVar2;
  }
  return (EVP_PKEY_METHOD *)puVar2;
}

