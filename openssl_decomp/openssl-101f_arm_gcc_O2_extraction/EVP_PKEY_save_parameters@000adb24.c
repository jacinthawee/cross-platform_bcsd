
int EVP_PKEY_save_parameters(EVP_PKEY *pkey,int mode)

{
  int iVar1;
  
  if ((pkey->type != 0x74) && (pkey->type != 0x198)) {
    return 0;
  }
  iVar1 = pkey->save_parameters;
  if (-1 < mode) {
    pkey->save_parameters = mode;
    return iVar1;
  }
  return iVar1;
}

