
int ASN1_item_ndef_i2d(ASN1_VALUE *val,uchar **out,ASN1_ITEM *it)

{
  int iVar1;
  int num;
  uchar *puVar2;
  int in_GS_OFFSET;
  ASN1_VALUE *local_28;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_28 = val;
  if ((out == (uchar **)0x0) || (*out != (uchar *)0x0)) {
    iVar1 = ASN1_item_ex_i2d(&local_28,out,it,-1,0x800);
  }
  else {
    num = ASN1_item_ex_i2d(&local_28,(uchar **)0x0,it,-1,0x800);
    iVar1 = num;
    if (0 < num) {
      puVar2 = (uchar *)CRYPTO_malloc(num,"tasn_enc.c",0x71);
      iVar1 = -1;
      if (puVar2 != (uchar *)0x0) {
        local_24 = puVar2;
        ASN1_item_ex_i2d(&local_28,&local_24,it,-1,0x800);
        *out = puVar2;
        iVar1 = num;
      }
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

