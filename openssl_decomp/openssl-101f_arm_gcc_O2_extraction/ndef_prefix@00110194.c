
bool ndef_prefix(undefined4 param_1,ASN1_VALUE **param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  ASN1_VALUE **ppAVar2;
  ASN1_VALUE *local_14;
  
  if (param_4 == (undefined4 *)0x0) {
    return false;
  }
  ppAVar2 = (ASN1_VALUE **)*param_4;
  iVar1 = ASN1_item_ndef_i2d(*ppAVar2,(uchar **)0x0,(ASN1_ITEM *)ppAVar2[1]);
  local_14 = (ASN1_VALUE *)CRYPTO_malloc(iVar1,"bio_ndef.c",0xa7);
  ppAVar2[5] = local_14;
  *param_2 = local_14;
  ASN1_item_ndef_i2d(*ppAVar2,(uchar **)&local_14,(ASN1_ITEM *)ppAVar2[1]);
  iVar1 = *(int *)ppAVar2[4];
  if (iVar1 != 0) {
    *param_3 = iVar1 - (int)*param_2;
  }
  return iVar1 != 0;
}

