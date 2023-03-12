
int i2d_PrivateKey(EVP_PKEY *a,uchar **pp)

{
  EVP_PKEY_ASN1_METHOD *pEVar1;
  int iVar2;
  undefined4 uVar3;
  
  pEVar1 = a->ameth;
  if (pEVar1 != (EVP_PKEY_ASN1_METHOD *)0x0) {
    if (*(code **)(pEVar1 + 0x60) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00608990. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar2 = (**(code **)(pEVar1 + 0x60))();
      return iVar2;
    }
    if (*(int *)(pEVar1 + 0x28) != 0) {
      uVar3 = (*(code *)PTR_EVP_PKEY2PKCS8_006a8e9c)();
      iVar2 = (*(code *)PTR_i2d_PKCS8_PRIV_KEY_INFO_006a8ea4)(uVar3,pp);
      (*(code *)PTR_PKCS8_PRIV_KEY_INFO_free_006a722c)(uVar3);
      return iVar2;
    }
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xa3,0xa7,"i2d_pr.c",0x4c);
  return -1;
}

