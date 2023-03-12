
int EVP_PKEY_copy_parameters(EVP_PKEY *to,EVP_PKEY *from)

{
  int iVar1;
  EVP_PKEY_ASN1_METHOD *pEVar2;
  
  if (to->type == from->type) {
    pEVar2 = from->ameth;
    if (pEVar2 != (EVP_PKEY_ASN1_METHOD *)0x0) {
      if (*(code **)(pEVar2 + 0x40) != (code *)0x0) {
        iVar1 = (**(code **)(pEVar2 + 0x40))(from);
        if (iVar1 != 0) {
          ERR_put_error(6,0x67,0x67,"p_lib.c",0x86);
          return 0;
        }
        pEVar2 = from->ameth;
        if (pEVar2 == (EVP_PKEY_ASN1_METHOD *)0x0) {
          return 0;
        }
      }
      if (*(code **)(pEVar2 + 0x44) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000adb74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar1 = (**(code **)(pEVar2 + 0x44))(to,from);
        return iVar1;
      }
    }
  }
  else {
    ERR_put_error(6,0x67,0x65,"p_lib.c",0x80);
  }
  return 0;
}

