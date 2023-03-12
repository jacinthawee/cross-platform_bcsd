
void ASN1_STRING_free(ASN1_STRING *a)

{
  if (a == (ASN1_STRING *)0x0) {
    return;
  }
  if ((a->data != (uchar *)0x0) && ((a->flags & 0x10U) == 0)) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
                    /* WARNING: Could not recover jumptable at 0x005680e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a6e88)(a);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x005680c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_CRYPTO_free_006a6e88)(a);
  return;
}

