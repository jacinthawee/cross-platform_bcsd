
EVP_PKEY_ASN1_METHOD * EVP_PKEY_asn1_find(ENGINE **pe,int type)

{
  EVP_PKEY_ASN1_METHOD **ppEVar1;
  int iVar2;
  EVP_PKEY_ASN1_METHOD *pEVar3;
  ENGINE *e;
  int *local_90;
  int local_8c [27];
  
  do {
    local_90 = local_8c;
    local_8c[0] = type;
    if ((app_methods == (_STACK *)0x0) || (iVar2 = sk_find(app_methods,local_8c), iVar2 < 0)) {
      ppEVar1 = (EVP_PKEY_ASN1_METHOD **)
                OBJ_bsearch_(&local_90,&standard_methods,0xb,4,ameth_cmp_BSEARCH_CMP_FN + 1);
      if ((ppEVar1 == (EVP_PKEY_ASN1_METHOD **)0x0) ||
         (pEVar3 = *ppEVar1, pEVar3 == (EVP_PKEY_ASN1_METHOD *)0x0)) {
        pEVar3 = (EVP_PKEY_ASN1_METHOD *)0x0;
LAB_000bd210:
        if (pe != (ENGINE **)0x0) {
          e = ENGINE_get_pkey_asn1_meth_engine(type);
          *pe = e;
          if (e != (ENGINE *)0x0) {
            pEVar3 = ENGINE_get_pkey_asn1_meth(e,type);
          }
        }
        return pEVar3;
      }
    }
    else {
      pEVar3 = (EVP_PKEY_ASN1_METHOD *)sk_value(app_methods,iVar2);
      if (pEVar3 == (EVP_PKEY_ASN1_METHOD *)0x0) goto LAB_000bd210;
    }
    if (-1 < *(int *)(pEVar3 + 8) << 0x1f) goto LAB_000bd210;
    type = *(int *)(pEVar3 + 4);
  } while( true );
}

