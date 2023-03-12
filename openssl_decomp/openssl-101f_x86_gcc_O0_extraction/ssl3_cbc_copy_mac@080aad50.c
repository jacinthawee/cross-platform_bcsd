
void ssl3_cbc_copy_mac(byte *param_1,int param_2,uint param_3,uint param_4)

{
  byte *__s;
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  int in_GS_OFFSET;
  byte local_a0 [128];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar3 = *(int *)(param_2 + 4) - param_3;
  if (param_4 < param_3) {
    OpenSSLDie("s3_cbc.c",0x113,"orig_len >= md_size");
  }
  if (0x40 < param_3) {
    OpenSSLDie("s3_cbc.c",0x114,"md_size <= EVP_MAX_MD_SIZE");
  }
  uVar8 = 0;
  __s = local_a0 + (-(int)local_a0 & 0x3f);
  if (param_3 + 0x100 < param_4) {
    uVar8 = (param_4 - 0x100) - param_3;
  }
  uVar6 = (((param_3 >> 1) * 0x1000000 + iVar3) - uVar8) % param_3;
  memset(__s,0,param_3);
  if (uVar8 < param_4) {
    iVar2 = *(int *)(param_2 + 0xc);
    pbVar7 = (byte *)(iVar2 + uVar8);
    uVar9 = ~(uVar8 - iVar3);
    uVar8 = 0;
    do {
      bVar1 = *pbVar7;
      iVar3 = (int)uVar9 >> 0x1f;
      pbVar7 = pbVar7 + 1;
      iVar4 = param_3 + uVar9;
      uVar9 = uVar9 - 1;
      __s[uVar8] = __s[uVar8] | ~(byte)(iVar4 >> 0x1f) & (byte)iVar3 & bVar1;
      uVar8 = (int)((uVar8 + 1) - param_3) >> 0x1f & uVar8 + 1;
    } while ((byte *)(iVar2 + param_4) != pbVar7);
  }
  pbVar7 = param_1 + param_3;
  if (param_3 != 0) {
    do {
      pbVar5 = param_1 + 1;
      *param_1 = __s[uVar6];
      uVar6 = (int)((uVar6 + 1) - param_3) >> 0x1f & uVar6 + 1;
      param_1 = pbVar5;
    } while (pbVar5 != pbVar7);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

