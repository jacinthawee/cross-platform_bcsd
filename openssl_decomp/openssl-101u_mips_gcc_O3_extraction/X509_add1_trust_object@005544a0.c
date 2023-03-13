
int X509_add1_trust_object(X509 *x,ASN1_OBJECT *obj)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = (*(code *)PTR_OBJ_dup_006a8494)(obj);
  if ((iVar1 != 0) && (x != (X509 *)0x0)) {
    piVar3 = *(int **)(x->sha1_hash + 0xc);
    if (piVar3 == (int *)0x0) {
      piVar3 = (int *)ASN1_item_new((ASN1_ITEM *)X509_CERT_AUX_it);
      *(int **)(x->sha1_hash + 0xc) = piVar3;
      if (piVar3 == (int *)0x0) {
        return 0;
      }
    }
    iVar2 = *piVar3;
    if (iVar2 == 0) {
      iVar2 = (*(code *)PTR_sk_new_null_006a6fa4)();
      *piVar3 = iVar2;
      if (iVar2 == 0) {
        return 0;
      }
    }
                    /* WARNING: Could not recover jumptable at 0x00554504. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*(code *)PTR_sk_push_006a6fa8)(iVar2,iVar1);
    return iVar1;
  }
  return 0;
}

