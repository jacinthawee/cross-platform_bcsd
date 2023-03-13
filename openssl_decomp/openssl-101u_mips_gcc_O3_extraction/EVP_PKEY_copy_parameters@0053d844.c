
int EVP_PKEY_copy_parameters(EVP_PKEY *to,EVP_PKEY *from)

{
  EVP_PKEY_ASN1_METHOD *pEVar1;
  int iVar2;
  int reason;
  
  if (to->type == from->type) {
    pEVar1 = from->ameth;
    if (pEVar1 == (EVP_PKEY_ASN1_METHOD *)0x0) {
      return 0;
    }
    if (*(code **)(pEVar1 + 0x40) != (code *)0x0) {
      iVar2 = (**(code **)(pEVar1 + 0x40))(from);
      if (iVar2 != 0) {
        reason = 0x67;
        iVar2 = 0x82;
        goto LAB_0053d8d4;
      }
      pEVar1 = from->ameth;
      if (pEVar1 == (EVP_PKEY_ASN1_METHOD *)0x0) {
        return 0;
      }
    }
    if (*(code **)(pEVar1 + 0x44) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0053d8b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar2 = (**(code **)(pEVar1 + 0x44))(to);
      return iVar2;
    }
  }
  else {
    reason = 0x65;
    iVar2 = 0x7d;
LAB_0053d8d4:
    ERR_put_error(6,0x67,reason,"p_lib.c",iVar2);
  }
  return 0;
}

