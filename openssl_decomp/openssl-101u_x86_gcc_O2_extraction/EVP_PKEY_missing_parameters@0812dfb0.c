
int EVP_PKEY_missing_parameters(EVP_PKEY *pkey)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  
  if ((pkey->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(pkey->ameth + 0x40), UNRECOVERED_JUMPTABLE != (code *)0x0))
  {
                    /* WARNING: Could not recover jumptable at 0x0812dfc2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*UNRECOVERED_JUMPTABLE)();
    return iVar1;
  }
  return 0;
}

