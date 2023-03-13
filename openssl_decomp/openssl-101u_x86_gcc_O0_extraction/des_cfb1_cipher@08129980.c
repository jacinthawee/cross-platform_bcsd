
undefined4 des_cfb1_cipher(int param_1,int param_2,int param_3,uint param_4)

{
  byte *pbVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  int in_GS_OFFSET;
  int local_3c;
  byte local_22;
  byte local_21;
  int local_20;
  
  local_3c = param_2;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar2 = 0x8000000;
  if (param_4 < 0x8000000) {
    uVar2 = param_4;
  }
  if (param_4 != 0) {
    do {
      if (uVar2 << 3 != 0) {
        uVar5 = 0;
        do {
          uVar4 = uVar5 >> 3;
          bVar3 = (byte)uVar5;
          local_22 = -((byte)((int)(uint)*(byte *)(param_3 + uVar4) >> (~bVar3 & 7)) & 1) & 0x80;
          DES_cfb_encrypt(&local_22,&local_21,1,1,*(DES_key_schedule **)(param_1 + 0x60),
                          (DES_cblock *)(param_1 + 0x20),*(int *)(param_1 + 8));
          uVar5 = uVar5 + 1;
          bVar3 = bVar3 & 7;
          pbVar1 = (byte *)(local_3c + uVar4);
          *pbVar1 = ~(byte)(0x80 >> bVar3) & *pbVar1 | (byte)((int)(local_21 & 0x80) >> bVar3);
        } while (uVar5 != uVar2 << 3);
      }
      param_4 = param_4 - uVar2;
      local_3c = local_3c + uVar2;
      param_3 = param_3 + uVar2;
      if (param_4 < uVar2) {
        uVar2 = param_4;
      }
    } while ((param_4 != 0) && (uVar2 <= param_4));
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}

