
undefined4 ndef_prefix(undefined4 param_1,ASN1_VALUE **param_2,int *param_3,int *param_4)

{
  ASN1_VALUE **ppAVar1;
  int num;
  undefined4 uVar2;
  int in_GS_OFFSET;
  ASN1_VALUE *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_4 != (int *)0x0) {
    ppAVar1 = (ASN1_VALUE **)*param_4;
    num = ASN1_item_ndef_i2d(*ppAVar1,(uchar **)0x0,(ASN1_ITEM *)ppAVar1[1]);
    local_14 = (ASN1_VALUE *)CRYPTO_malloc(num,"bio_ndef.c",0xa7);
    ppAVar1[5] = local_14;
    *param_2 = local_14;
    ASN1_item_ndef_i2d(*ppAVar1,(uchar **)&local_14,(ASN1_ITEM *)ppAVar1[1]);
    if (*(int *)ppAVar1[4] != 0) {
      *param_3 = *(int *)ppAVar1[4] - (int)*param_2;
      uVar2 = 1;
      goto LAB_081ce7a7;
    }
  }
  uVar2 = 0;
LAB_081ce7a7:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

