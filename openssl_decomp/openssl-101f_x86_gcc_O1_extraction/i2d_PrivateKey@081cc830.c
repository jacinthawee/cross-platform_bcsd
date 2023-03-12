
int i2d_PrivateKey(EVP_PKEY *a,uchar **pp)

{
  EVP_PKEY_ASN1_METHOD *pEVar1;
  int iVar2;
  PKCS8_PRIV_KEY_INFO *a_00;
  
  pEVar1 = a->ameth;
  if (pEVar1 != (EVP_PKEY_ASN1_METHOD *)0x0) {
    if (*(code **)(pEVar1 + 0x60) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x081cc850. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar2 = (**(code **)(pEVar1 + 0x60))();
      return iVar2;
    }
    if (*(int *)(pEVar1 + 0x28) != 0) {
      a_00 = EVP_PKEY2PKCS8(a);
      iVar2 = i2d_PKCS8_PRIV_KEY_INFO(a_00,pp);
      PKCS8_PRIV_KEY_INFO_free(a_00);
      return iVar2;
    }
  }
  ERR_put_error(0xd,0xa3,0xa7,"i2d_pr.c",0x4d);
  return -1;
}

