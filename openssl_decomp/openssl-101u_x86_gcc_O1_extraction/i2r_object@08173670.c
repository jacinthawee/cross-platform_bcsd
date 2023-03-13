
bool i2r_object(undefined4 param_1,ASN1_OBJECT *param_2,BIO *param_3,undefined4 param_4)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = BIO_printf(param_3,"%*s",param_4,&DAT_081eca46);
  bVar2 = false;
  if (0 < iVar1) {
    iVar1 = i2a_ASN1_OBJECT(param_3,param_2);
    bVar2 = 0 < iVar1;
  }
  return bVar2;
}

