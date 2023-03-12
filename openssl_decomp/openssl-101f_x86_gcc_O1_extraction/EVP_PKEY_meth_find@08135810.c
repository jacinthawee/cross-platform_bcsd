
EVP_PKEY_METHOD * EVP_PKEY_meth_find(int type)

{
  int iVar1;
  EVP_PKEY_METHOD **ppEVar2;
  EVP_PKEY_METHOD *pEVar3;
  int in_GS_OFFSET;
  int *local_80;
  int local_7c [27];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_80 = local_7c;
  local_7c[0] = type;
  if (app_pkey_methods != (_STACK *)0x0) {
    iVar1 = sk_find(app_pkey_methods,local_80);
    if (-1 < iVar1) {
      pEVar3 = (EVP_PKEY_METHOD *)sk_value(app_pkey_methods,iVar1);
      goto LAB_08135873;
    }
  }
  ppEVar2 = (EVP_PKEY_METHOD **)
            OBJ_bsearch_(&local_80,standard_methods,6,4,pmeth_cmp_BSEARCH_CMP_FN);
  if (ppEVar2 == (EVP_PKEY_METHOD **)0x0) {
    pEVar3 = (EVP_PKEY_METHOD *)0x0;
  }
  else {
    pEVar3 = *ppEVar2;
  }
LAB_08135873:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pEVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

