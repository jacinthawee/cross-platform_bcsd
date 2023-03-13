
void ASN1_OBJECT_free(ASN1_OBJECT *a)

{
  uint uVar1;
  
  if (a != (ASN1_OBJECT *)0x0) {
    uVar1 = a->flags;
    if ((uVar1 & 4) != 0) {
      if (a->sn != (char *)0x0) {
        (*(code *)PTR_CRYPTO_free_006a6e88)();
      }
      if (a->ln != (char **)0x0) {
        (*(code *)PTR_CRYPTO_free_006a6e88)();
      }
      uVar1 = a->flags;
      a->ln = (char **)0x0;
      a->sn = (char *)0x0;
    }
    if ((uVar1 & 8) != 0) {
      if (a->data != (uchar *)0x0) {
        (*(code *)PTR_CRYPTO_free_006a6e88)();
        uVar1 = a->flags;
      }
      a->data = (uchar *)0x0;
      a->length = 0;
    }
    if ((uVar1 & 1) != 0) {
                    /* WARNING: Could not recover jumptable at 0x00548998. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_CRYPTO_free_006a6e88)(a);
      return;
    }
  }
  return;
}

