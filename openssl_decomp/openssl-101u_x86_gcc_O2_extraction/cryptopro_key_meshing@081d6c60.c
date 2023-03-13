
void cryptopro_key_meshing(uint *param_1,undefined4 *param_2)

{
  char *pcVar1;
  char *pcVar2;
  byte *pbVar3;
  int in_GS_OFFSET;
  undefined4 local_48;
  undefined4 local_44;
  byte local_40;
  byte local_3f;
  byte local_3e;
  byte local_3d;
  byte local_3c;
  byte local_3b;
  byte local_3a;
  byte local_39;
  byte local_38;
  byte local_37;
  byte local_36;
  byte local_35;
  byte local_34;
  byte local_33;
  byte local_32;
  byte local_31;
  byte local_30;
  byte local_2f;
  byte local_2e;
  byte local_2d;
  byte local_2c;
  byte local_2b;
  byte local_2a;
  byte local_29;
  byte local_28;
  byte local_27;
  byte local_26;
  byte local_25;
  byte local_24;
  byte local_23;
  byte local_22;
  byte local_21;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pcVar1 = CryptoProKeyMeshingKey;
  pbVar3 = &local_40;
  do {
    pcVar2 = pcVar1 + 8;
    gostdecrypt(param_1,pcVar1,pbVar3);
    pcVar1 = pcVar2;
    pbVar3 = pbVar3 + 8;
  } while (pcVar2 != "gost94_keyx.c");
  *param_1 = (uint)local_3f << 8 | (uint)local_3e << 0x10 | (uint)local_40 | (uint)local_3d << 0x18;
  param_1[1] = (uint)local_3b << 8 | (uint)local_3a << 0x10 | (uint)local_3c |
               (uint)local_39 << 0x18;
  param_1[2] = (uint)local_36 << 0x10 | (uint)local_37 << 8 | (uint)local_38 |
               (uint)local_35 << 0x18;
  param_1[3] = (uint)local_32 << 0x10 | (uint)local_33 << 8 | (uint)local_34 |
               (uint)local_31 << 0x18;
  param_1[4] = (uint)local_2e << 0x10 | (uint)local_2f << 8 | (uint)local_30 |
               (uint)local_2d << 0x18;
  param_1[5] = (uint)local_2a << 0x10 | (uint)local_2b << 8 | (uint)local_2c |
               (uint)local_29 << 0x18;
  param_1[6] = (uint)local_26 << 0x10 | (uint)local_27 << 8 | (uint)local_28 |
               (uint)local_25 << 0x18;
  param_1[7] = (uint)local_22 << 0x10 | (uint)local_23 << 8 | (uint)local_24 |
               (uint)local_21 << 0x18;
  gostcrypt(param_1,param_2,&local_48);
  *param_2 = local_48;
  param_2[1] = local_44;
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

