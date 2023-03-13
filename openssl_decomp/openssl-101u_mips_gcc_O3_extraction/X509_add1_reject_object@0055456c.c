
int X509_add1_reject_object(X509 *x,ASN1_OBJECT *obj)

{
  int iVar1;
  int iVar2;
  ASN1_VALUE *pAVar3;
  
  iVar1 = (*(code *)PTR_OBJ_dup_006a8494)(obj);
  if ((iVar1 != 0) && (x != (X509 *)0x0)) {
    pAVar3 = *(ASN1_VALUE **)(x->sha1_hash + 0xc);
    if (pAVar3 == (ASN1_VALUE *)0x0) {
      pAVar3 = ASN1_item_new((ASN1_ITEM *)X509_CERT_AUX_it);
      *(ASN1_VALUE **)(x->sha1_hash + 0xc) = pAVar3;
      if (pAVar3 == (ASN1_VALUE *)0x0) {
        return 0;
      }
    }
    iVar2 = *(int *)(pAVar3 + 4);
    if (iVar2 == 0) {
      iVar2 = (*(code *)PTR_sk_new_null_006a6fa4)();
      *(int *)(pAVar3 + 4) = iVar2;
      if (iVar2 == 0) {
        return 0;
      }
    }
                    /* WARNING: Could not recover jumptable at 0x005545d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*(code *)PTR_sk_push_006a6fa8)(iVar2,iVar1);
    return iVar1;
  }
  return 0;
}

