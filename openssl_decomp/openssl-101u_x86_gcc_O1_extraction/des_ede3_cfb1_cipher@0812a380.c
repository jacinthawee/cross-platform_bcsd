
undefined4 des_ede3_cfb1_cipher(int param_1,int param_2,int param_3,uint param_4)

{
  byte *pbVar1;
  DES_key_schedule *ks1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  int in_GS_OFFSET;
  byte local_22;
  byte local_21;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_4 != 0) {
    uVar3 = 0;
    do {
      uVar4 = uVar3 >> 3;
      bVar2 = (byte)uVar3;
      local_22 = -((byte)((int)(uint)*(byte *)(param_3 + uVar4) >> (~bVar2 & 7)) & 1) & 0x80;
      ks1 = *(DES_key_schedule **)(param_1 + 0x60);
      DES_ede3_cfb_encrypt
                (&local_22,&local_21,1,1,ks1,ks1 + 1,ks1 + 2,(DES_cblock *)(param_1 + 0x20),
                 *(int *)(param_1 + 8));
      uVar3 = uVar3 + 1;
      bVar2 = bVar2 & 7;
      pbVar1 = (byte *)(param_2 + uVar4);
      *pbVar1 = (byte)((int)(local_21 & 0x80) >> bVar2) | ~(byte)(0x80 >> bVar2) & *pbVar1;
    } while (param_4 != uVar3);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return 1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

