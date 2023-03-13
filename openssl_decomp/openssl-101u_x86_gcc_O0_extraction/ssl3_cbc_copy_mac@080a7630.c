
void ssl3_cbc_copy_mac(byte *param_1,int param_2,uint param_3,uint param_4)

{
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  int iVar8;
  byte *__s;
  uint uVar9;
  int iVar10;
  uint uVar11;
  byte *pbVar12;
  uint uVar13;
  int iVar14;
  int in_GS_OFFSET;
  byte local_a0 [128];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar3 = *(int *)(param_2 + 4);
  iVar8 = iVar3 - param_3;
  if (param_4 < param_3) {
    OpenSSLDie("s3_cbc.c",0xf8,"orig_len >= md_size");
  }
  if (0x40 < param_3) {
    OpenSSLDie("s3_cbc.c",0xf9,"md_size <= EVP_MAX_MD_SIZE");
  }
  uVar13 = 0;
  __s = local_a0 + (-(int)local_a0 & 0x3f);
  if (param_3 + 0x100 < param_4) {
    uVar13 = (param_4 - 0x100) - param_3;
  }
  uVar11 = (((param_3 >> 1) * 0x1000000 + iVar8) - uVar13) % param_3;
  memset(__s,0,param_3);
  if (uVar13 < param_4) {
    iVar4 = *(int *)(param_2 + 0xc);
    uVar9 = 0;
    do {
      uVar1 = uVar9 + 1;
      iVar10 = uVar13 - iVar8;
      bVar6 = (byte)((uint)iVar8 >> 0x18);
      bVar5 = (byte)(uVar13 >> 0x18);
      pbVar2 = (byte *)(iVar4 + uVar13);
      iVar14 = uVar13 - iVar3;
      bVar7 = (byte)((uint)iVar3 >> 0x18);
      uVar13 = uVar13 + 1;
      __s[uVar9] = __s[uVar9] |
                   ~((char)((bVar6 ^ bVar5 | (byte)((uint)iVar10 >> 0x18) ^ bVar6) ^ bVar5) >> 7) &
                   *pbVar2 & (char)((bVar7 ^ bVar5 | (byte)((uint)iVar14 >> 0x18) ^ bVar7) ^ bVar5)
                             >> 7;
      uVar9 = (int)((param_3 ^ uVar1 | uVar1 - param_3 ^ param_3) ^ uVar1) >> 0x1f & uVar1;
    } while (param_4 != uVar13);
  }
  pbVar2 = param_1 + param_3;
  if (param_3 != 0) {
    do {
      pbVar12 = param_1 + 1;
      uVar13 = uVar11 + 1;
      *param_1 = __s[uVar11];
      uVar11 = (int)((uVar13 - param_3 ^ param_3 | param_3 ^ uVar13) ^ uVar13) >> 0x1f & uVar13;
      param_1 = pbVar12;
    } while (pbVar12 != pbVar2);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

