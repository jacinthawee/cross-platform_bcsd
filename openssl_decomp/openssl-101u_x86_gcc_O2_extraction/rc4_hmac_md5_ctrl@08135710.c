
undefined4 rc4_hmac_md5_ctrl(int param_1,int param_2,size_t param_3,void *param_4)

{
  MD5_CTX *c;
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  uint *puVar6;
  undefined4 *puVar7;
  int in_GS_OFFSET;
  uint local_60 [4];
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = *(int *)(param_1 + 0x60);
  if (param_2 == 0x16) {
    if (param_3 == 0xd) {
      uVar3 = (uint)(ushort)(*(ushort *)((int)param_4 + 0xb) << 8 |
                            *(ushort *)((int)param_4 + 0xb) >> 8);
      if (*(int *)(param_1 + 8) == 0) {
        uVar3 = uVar3 - 0x10;
        *(char *)((int)param_4 + 0xc) = (char)uVar3;
        *(char *)((int)param_4 + 0xb) = (char)(uVar3 >> 8);
      }
      *(uint *)(iVar1 + 0x218) = uVar3;
      puVar5 = (undefined4 *)(iVar1 + 0x104);
      puVar7 = (undefined4 *)(iVar1 + 0x1bc);
      for (iVar4 = 0x17; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar7 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar7 = puVar7 + 1;
      }
      MD5_Update((MD5_CTX *)(iVar1 + 0x1bc),param_4,0xd);
      uVar2 = 0x10;
      goto LAB_08135746;
    }
  }
  else if (param_2 == 0x17) {
    puVar6 = local_60;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    if ((int)param_3 < 0x41) {
      __memcpy_chk(local_60,param_4,param_3,0x40);
    }
    else {
      c = (MD5_CTX *)(iVar1 + 0x104);
      MD5_Init(c);
      MD5_Update(c,param_4,param_3);
      MD5_Final((uchar *)local_60,c);
    }
    local_60[0] = local_60[0] ^ 0x36363636;
    local_60[1] = local_60[1] ^ 0x36363636;
    local_60[2] = local_60[2] ^ 0x36363636;
    local_60[3] = local_60[3] ^ 0x36363636;
    local_50 = local_50 ^ 0x36363636;
    local_4c = local_4c ^ 0x36363636;
    local_48 = local_48 ^ 0x36363636;
    local_44 = local_44 ^ 0x36363636;
    local_40 = local_40 ^ 0x36363636;
    local_3c = local_3c ^ 0x36363636;
    local_38 = local_38 ^ 0x36363636;
    local_34 = local_34 ^ 0x36363636;
    local_30 = local_30 ^ 0x36363636;
    local_2c = local_2c ^ 0x36363636;
    local_28 = local_28 ^ 0x36363636;
    local_24 = local_24 ^ 0x36363636;
    MD5_Init((MD5_CTX *)(iVar1 + 0x104));
    MD5_Update((MD5_CTX *)(iVar1 + 0x104),local_60,0x40);
    local_60[0] = local_60[0] ^ 0x6a6a6a6a;
    local_60[1] = local_60[1] ^ 0x6a6a6a6a;
    local_60[2] = local_60[2] ^ 0x6a6a6a6a;
    local_60[3] = local_60[3] ^ 0x6a6a6a6a;
    local_50 = local_50 ^ 0x6a6a6a6a;
    local_4c = local_4c ^ 0x6a6a6a6a;
    local_48 = local_48 ^ 0x6a6a6a6a;
    local_44 = local_44 ^ 0x6a6a6a6a;
    local_40 = local_40 ^ 0x6a6a6a6a;
    local_3c = local_3c ^ 0x6a6a6a6a;
    local_38 = local_38 ^ 0x6a6a6a6a;
    local_34 = local_34 ^ 0x6a6a6a6a;
    local_30 = local_30 ^ 0x6a6a6a6a;
    local_2c = local_2c ^ 0x6a6a6a6a;
    local_28 = local_28 ^ 0x6a6a6a6a;
    local_24 = local_24 ^ 0x6a6a6a6a;
    MD5_Init((MD5_CTX *)(iVar1 + 0x160));
    MD5_Update((MD5_CTX *)(iVar1 + 0x160),local_60,0x40);
    uVar2 = 1;
    goto LAB_08135746;
  }
  uVar2 = 0xffffffff;
LAB_08135746:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

