
bool i2r_ocsp_nonce(undefined4 param_1,ASN1_STRING *param_2,BIO *param_3,undefined4 param_4)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = BIO_printf(param_3,"%*s",param_4,&DAT_081ec74a);
  bVar2 = false;
  if (0 < iVar1) {
    iVar1 = i2a_ASN1_STRING(param_3,param_2,4);
    bVar2 = 0 < iVar1;
  }
  return bVar2;
}

