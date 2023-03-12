
void rc4_hmac_md5_ctrl(int param_1,int param_2,size_t param_3,void *param_4)

{
  undefined4 uVar1;
  uint uVar2;
  MD5_CTX *c;
  int iVar3;
  uint local_6c;
  uint local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  int local_2c;
  
  iVar3 = *(int *)(param_1 + 0x60);
  local_2c = __stack_chk_guard;
  if (param_2 == 0x16) {
    if (param_3 == 0xd) {
      uVar2 = (uint)CONCAT11(*(undefined *)((int)param_4 + 0xb),*(undefined *)((int)param_4 + 0xc));
      if (*(int *)(param_1 + 8) == 0) {
        uVar2 = uVar2 - 0x10;
        *(char *)((int)param_4 + 0xc) = (char)uVar2;
        *(char *)((int)param_4 + 0xb) = (char)(uVar2 >> 8);
      }
      *(uint *)(iVar3 + 0x218) = uVar2;
      memcpy((MD5_CTX *)(iVar3 + 0x1bc),(void *)(iVar3 + 0x104),0x5c);
      MD5_Update((MD5_CTX *)(iVar3 + 0x1bc),param_4,0xd);
      uVar1 = 0x10;
      goto LAB_000af95e;
    }
  }
  else if (param_2 == 0x17) {
    memset(&local_6c,0,0x40);
    if ((int)param_3 < 0x41) {
      __memcpy_chk(&local_6c,param_4,param_3,0x40);
    }
    else {
      c = (MD5_CTX *)(iVar3 + 0x104);
      MD5_Init(c);
      MD5_Update(c,param_4,param_3);
      MD5_Final((uchar *)&local_6c,c);
    }
    local_68 = local_68 ^ 0x36363636;
    local_6c = local_6c ^ 0x36363636;
    local_5c = local_5c ^ 0x36363636;
    local_60 = local_60 ^ 0x36363636;
    local_58 = local_58 ^ 0x36363636;
    local_54 = local_54 ^ 0x36363636;
    local_50 = local_50 ^ 0x36363636;
    local_4c = local_4c ^ 0x36363636;
    local_48 = local_48 ^ 0x36363636;
    local_64 = local_64 ^ 0x36363636;
    local_44 = local_44 ^ 0x36363636;
    local_3c = local_3c ^ 0x36363636;
    local_38 = local_38 ^ 0x36363636;
    local_40 = local_40 ^ 0x36363636;
    local_30 = local_30 ^ 0x36363636;
    local_34 = local_34 ^ 0x36363636;
    MD5_Init((MD5_CTX *)(iVar3 + 0x104));
    MD5_Update((MD5_CTX *)(iVar3 + 0x104),&local_6c,0x40);
    local_68 = local_68 ^ 0x6a6a6a6a;
    local_58 = local_58 ^ 0x6a6a6a6a;
    local_5c = local_5c ^ 0x6a6a6a6a;
    local_6c = local_6c ^ 0x6a6a6a6a;
    local_54 = local_54 ^ 0x6a6a6a6a;
    local_50 = local_50 ^ 0x6a6a6a6a;
    local_4c = local_4c ^ 0x6a6a6a6a;
    local_48 = local_48 ^ 0x6a6a6a6a;
    local_60 = local_60 ^ 0x6a6a6a6a;
    local_44 = local_44 ^ 0x6a6a6a6a;
    local_64 = local_64 ^ 0x6a6a6a6a;
    local_40 = local_40 ^ 0x6a6a6a6a;
    local_38 = local_38 ^ 0x6a6a6a6a;
    local_3c = local_3c ^ 0x6a6a6a6a;
    local_34 = local_34 ^ 0x6a6a6a6a;
    local_30 = local_30 ^ 0x6a6a6a6a;
    MD5_Init((MD5_CTX *)(iVar3 + 0x160));
    MD5_Update((MD5_CTX *)(iVar3 + 0x160),&local_6c,0x40);
    uVar1 = 1;
    goto LAB_000af95e;
  }
  uVar1 = 0xffffffff;
LAB_000af95e:
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar1);
}

