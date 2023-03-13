
undefined4 ndef_suffix(undefined4 param_1,ASN1_VALUE **param_2,int *param_3,int *param_4)

{
  ASN1_VALUE **ppAVar1;
  int iVar2;
  undefined4 uVar3;
  int in_GS_OFFSET;
  ASN1_VALUE *local_20;
  ASN1_VALUE *local_1c;
  ASN1_VALUE *local_18;
  ASN1_VALUE *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_4 != (int *)0x0) {
    ppAVar1 = (ASN1_VALUE **)*param_4;
    local_18 = ppAVar1[2];
    local_1c = ppAVar1[3];
    local_14 = ppAVar1[4];
    iVar2 = (**(code **)(*(int *)(ppAVar1[1] + 0x10) + 0x10))(0xb,ppAVar1,ppAVar1[1],&local_1c);
    if (0 < iVar2) {
      iVar2 = ASN1_item_ndef_i2d(*ppAVar1,(uchar **)0x0,(ASN1_ITEM *)ppAVar1[1]);
      local_20 = (ASN1_VALUE *)CRYPTO_malloc(iVar2,"bio_ndef.c",0xea);
      if (local_20 != (ASN1_VALUE *)0x0) {
        ppAVar1[5] = local_20;
        *param_2 = local_20;
        iVar2 = ASN1_item_ndef_i2d(*ppAVar1,(uchar **)&local_20,(ASN1_ITEM *)ppAVar1[1]);
        if (*(ASN1_VALUE **)ppAVar1[4] != (ASN1_VALUE *)0x0) {
          *param_2 = *(ASN1_VALUE **)ppAVar1[4];
          *param_3 = iVar2 - (*(int *)ppAVar1[4] - (int)ppAVar1[5]);
          uVar3 = 1;
          goto LAB_081cd572;
        }
      }
    }
  }
  uVar3 = 0;
LAB_081cd572:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

