
EVP_PKEY_ASN1_METHOD * EVP_PKEY_asn1_find(ENGINE **pe,int type)

{
  EVP_PKEY_ASN1_METHOD **ppEVar1;
  int iVar2;
  EVP_PKEY_ASN1_METHOD *pEVar3;
  ENGINE *e;
  int in_GS_OFFSET;
  int *local_90;
  int local_8c [27];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  do {
    local_90 = local_8c;
    local_8c[0] = type;
    if (app_methods == (_STACK *)0x0) {
LAB_0814eb78:
      ppEVar1 = (EVP_PKEY_ASN1_METHOD **)
                OBJ_bsearch_(&local_90,standard_methods,0xb,4,ameth_cmp_BSEARCH_CMP_FN);
      if ((ppEVar1 == (EVP_PKEY_ASN1_METHOD **)0x0) ||
         (pEVar3 = *ppEVar1, pEVar3 == (EVP_PKEY_ASN1_METHOD *)0x0)) {
        pEVar3 = (EVP_PKEY_ASN1_METHOD *)0x0;
LAB_0814ebe7:
        if (pe != (ENGINE **)0x0) {
          e = ENGINE_get_pkey_asn1_meth_engine(type);
          if (e == (ENGINE *)0x0) {
            *pe = (ENGINE *)0x0;
          }
          else {
            *pe = e;
            pEVar3 = ENGINE_get_pkey_asn1_meth(e,type);
          }
        }
        if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
          return pEVar3;
        }
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
    }
    else {
      iVar2 = sk_find(app_methods,local_8c);
      if (iVar2 < 0) goto LAB_0814eb78;
      pEVar3 = (EVP_PKEY_ASN1_METHOD *)sk_value(app_methods,iVar2);
      if (pEVar3 == (EVP_PKEY_ASN1_METHOD *)0x0) goto LAB_0814ebe7;
    }
    if (((byte)pEVar3[8] & 1) == 0) goto LAB_0814ebe7;
    type = *(int *)(pEVar3 + 4);
  } while( true );
}

