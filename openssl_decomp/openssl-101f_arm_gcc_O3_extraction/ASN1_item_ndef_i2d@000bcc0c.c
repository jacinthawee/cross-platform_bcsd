
int ASN1_item_ndef_i2d(ASN1_VALUE *val,uchar **out,ASN1_ITEM *it)

{
  int iVar1;
  int num;
  uchar *puVar2;
  ASN1_VALUE *local_20;
  uchar *local_1c [2];
  
  local_20 = val;
  if ((out == (uchar **)0x0) || (*out != (uchar *)0x0)) {
    iVar1 = ASN1_item_ex_i2d(&local_20,out,it,-1,0x800);
  }
  else {
    num = ASN1_item_ex_i2d_constprop_0(&local_20,it,0x800);
    iVar1 = num;
    if (0 < num) {
      puVar2 = (uchar *)CRYPTO_malloc(num,"tasn_enc.c",0x71);
      iVar1 = -1;
      if (puVar2 != (uchar *)0x0) {
        local_1c[0] = puVar2;
        ASN1_item_ex_i2d(&local_20,local_1c,it,-1,0x800);
        *out = puVar2;
        iVar1 = num;
      }
    }
  }
  return iVar1;
}

