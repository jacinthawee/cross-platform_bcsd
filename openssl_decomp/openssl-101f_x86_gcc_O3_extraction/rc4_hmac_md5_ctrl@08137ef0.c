
undefined4 rc4_hmac_md5_ctrl(int param_1,int param_2,size_t param_3,void *param_4)

{
  MD5_CTX *c;
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint *puVar8;
  undefined4 *puVar9;
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
  iVar3 = *(int *)(param_1 + 0x60);
  if (param_2 == 0x16) {
    puVar1 = (undefined *)((int)param_4 + (param_3 - 2));
    puVar2 = (undefined *)((int)param_4 + (param_3 - 1));
    uVar6 = (uint)CONCAT11(*puVar1,*puVar2);
    if (*(int *)(param_1 + 8) == 0) {
      uVar6 = uVar6 - 0x10;
      *puVar1 = (char)(uVar6 >> 8);
      *puVar2 = (char)uVar6;
    }
    *(uint *)(iVar3 + 0x218) = uVar6;
    puVar7 = (undefined4 *)(iVar3 + 0x104);
    puVar9 = (undefined4 *)(iVar3 + 0x1bc);
    for (iVar5 = 0x17; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
    MD5_Update((MD5_CTX *)(iVar3 + 0x1bc),param_4,param_3);
    uVar4 = 0x10;
  }
  else {
    uVar4 = 0xffffffff;
    if (param_2 == 0x17) {
      puVar8 = local_60;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar8 = 0;
        puVar8 = puVar8 + 1;
      }
      if ((int)param_3 < 0x41) {
        __memcpy_chk(local_60,param_4,param_3,0x40);
      }
      else {
        c = (MD5_CTX *)(iVar3 + 0x104);
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
      MD5_Init((MD5_CTX *)(iVar3 + 0x104));
      MD5_Update((MD5_CTX *)(iVar3 + 0x104),local_60,0x40);
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
      MD5_Init((MD5_CTX *)(iVar3 + 0x160));
      MD5_Update((MD5_CTX *)(iVar3 + 0x160),local_60,0x40);
      uVar4 = 1;
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

