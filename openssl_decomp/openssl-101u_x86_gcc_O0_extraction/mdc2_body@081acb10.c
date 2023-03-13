
void __regparm3 mdc2_body(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int in_GS_OFFSET;
  byte local_d1;
  uint local_b0;
  uint local_ac;
  uint local_a8;
  uint local_a4;
  DES_key_schedule local_a0;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_3 != 0) {
    local_d1 = *(byte *)(param_1 + 0xc);
    uVar4 = (uint)*(byte *)(param_1 + 0x14);
    uVar2 = 0;
    do {
      uVar1 = *(uint *)(param_2 + uVar2);
      uVar3 = *(uint *)(param_2 + 4 + uVar2);
      uVar2 = uVar2 + 8;
      *(byte *)(param_1 + 0xc) = local_d1 & 0x9f | 0x40;
      *(byte *)(param_1 + 0x14) = (byte)uVar4 & 0x9f | 0x20;
      local_b0 = uVar1;
      local_ac = uVar3;
      local_a8 = uVar1;
      local_a4 = uVar3;
      DES_set_odd_parity((DES_cblock *)(param_1 + 0xc));
      DES_set_key_unchecked((DES_cblock *)(param_1 + 0xc),&local_a0);
      DES_encrypt1(&local_b0,&local_a0,1);
      DES_set_odd_parity((DES_cblock *)(param_1 + 0x14));
      DES_set_key_unchecked((DES_cblock *)(param_1 + 0x14),&local_a0);
      DES_encrypt1(&local_a8,&local_a0,1);
      uVar4 = local_a8 ^ uVar1;
      uVar1 = uVar1 ^ local_b0;
      uVar5 = local_a4 ^ uVar3;
      uVar3 = uVar3 ^ local_ac;
      *(char *)(param_1 + 0x14) = (char)uVar4;
      local_d1 = (byte)uVar1;
      *(byte *)(param_1 + 0xc) = local_d1;
      *(char *)(param_1 + 0xf) = (char)(uVar1 >> 0x18);
      *(char *)(param_1 + 0x10) = (char)uVar5;
      *(char *)(param_1 + 0xd) = (char)(uVar1 >> 8);
      *(char *)(param_1 + 0x11) = (char)(uVar5 >> 8);
      *(char *)(param_1 + 0xe) = (char)(uVar1 >> 0x10);
      *(char *)(param_1 + 0x12) = (char)(uVar5 >> 0x10);
      *(char *)(param_1 + 0x13) = (char)(uVar5 >> 0x18);
      *(char *)(param_1 + 0x18) = (char)uVar3;
      *(char *)(param_1 + 0x15) = (char)(uVar4 >> 8);
      *(char *)(param_1 + 0x17) = (char)(uVar4 >> 0x18);
      *(char *)(param_1 + 0x16) = (char)(uVar4 >> 0x10);
      *(char *)(param_1 + 0x19) = (char)(uVar3 >> 8);
      *(char *)(param_1 + 0x1b) = (char)(uVar3 >> 0x18);
      *(char *)(param_1 + 0x1a) = (char)(uVar3 >> 0x10);
    } while (uVar2 < param_3);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

