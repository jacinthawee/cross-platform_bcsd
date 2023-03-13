
int EVP_PKEY_size(EVP_PKEY *pkey)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  
  if (((pkey != (EVP_PKEY *)0x0) && (pkey->ameth != (EVP_PKEY_ASN1_METHOD *)0x0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(pkey->ameth + 0x30), UNRECOVERED_JUMPTABLE != (code *)0x0))
  {
                    /* WARNING: Could not recover jumptable at 0x0812deb6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*UNRECOVERED_JUMPTABLE)();
    return iVar1;
  }
  return 0;
}

