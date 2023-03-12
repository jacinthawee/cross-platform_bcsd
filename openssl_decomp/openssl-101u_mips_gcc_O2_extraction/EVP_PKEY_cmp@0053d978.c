
int EVP_PKEY_cmp(EVP_PKEY *a,EVP_PKEY *b)

{
  int iVar1;
  EVP_PKEY_ASN1_METHOD *pEVar2;
  
  if (a->type != b->type) {
    return -1;
  }
  pEVar2 = a->ameth;
  if (pEVar2 == (EVP_PKEY_ASN1_METHOD *)0x0) {
    return -2;
  }
  if (*(code **)(pEVar2 + 0x48) != (code *)0x0) {
    iVar1 = (**(code **)(pEVar2 + 0x48))();
    if (iVar1 < 1) {
      return iVar1;
    }
    pEVar2 = a->ameth;
  }
  if (*(code **)(pEVar2 + 0x1c) == (code *)0x0) {
    return -2;
  }
                    /* WARNING: Could not recover jumptable at 0x0053d9e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (**(code **)(pEVar2 + 0x1c))(a,b);
  return iVar1;
}

