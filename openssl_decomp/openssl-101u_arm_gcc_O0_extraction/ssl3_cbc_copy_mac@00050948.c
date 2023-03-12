
void ssl3_cbc_copy_mac(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  undefined4 *puVar6;
  uint extraout_r1;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  byte *__s;
  int iVar11;
  int iVar12;
  int iVar13;
  byte abStack_ac [128];
  int local_2c;
  
  puVar10 = &__stack_chk_guard;
  iVar12 = *(int *)(param_2 + 4);
  iVar13 = iVar12 - (int)param_3;
  local_2c = __stack_chk_guard;
  if (param_4 < param_3) {
    OpenSSLDie("s3_cbc.c",0xf8,"orig_len >= md_size");
  }
  if ((undefined4 *)0x40 < param_3) {
    OpenSSLDie("s3_cbc.c",0xf9,"md_size <= EVP_MAX_MD_SIZE");
  }
  puVar6 = param_3 + 0x40;
  if (puVar6 < param_4) {
    puVar10 = param_4 + -0x40;
  }
  if (puVar6 < param_4) {
    puVar10 = (undefined4 *)((int)puVar10 - (int)param_3);
  }
  if (param_4 <= puVar6) {
    puVar10 = (undefined4 *)0x0;
  }
  __s = abStack_ac + (-(int)abStack_ac & 0x3f);
  __aeabi_uidivmod((iVar13 + ((uint)param_3 >> 1) * 0x1000000) - (int)puVar10,param_3);
  memset(__s,0,(size_t)param_3);
  if (puVar10 < param_4) {
    iVar8 = *(int *)(param_2 + 0xc);
    uVar7 = 0;
    do {
      iVar5 = (int)puVar10 - iVar13;
      bVar3 = (byte)((uint)puVar10 >> 0x18);
      bVar4 = (byte)((uint)iVar13 >> 0x18);
      iVar11 = (int)puVar10 - iVar12;
      uVar9 = uVar7 + 1;
      bVar2 = (byte)((uint)iVar12 >> 0x18);
      pbVar1 = (byte *)(iVar8 + (int)puVar10);
      puVar10 = (undefined4 *)((int)puVar10 + 1);
      __s[uVar7] = *pbVar1 & ~((char)(((byte)((uint)iVar5 >> 0x18) ^ bVar4 | bVar3 ^ bVar4) ^ bVar3)
                              >> 7) &
                   (char)(((byte)((uint)iVar11 >> 0x18) ^ bVar2 | bVar3 ^ bVar2) ^ bVar3) >> 7 |
                   __s[uVar7];
      uVar7 = uVar9 & (int)((uVar9 - (int)param_3 ^ (uint)param_3 | uVar9 ^ (uint)param_3) ^ uVar9)
                      >> 0x1f;
    } while (puVar10 != param_4);
  }
  puVar10 = (undefined4 *)0x0;
  uVar7 = extraout_r1;
  if (param_3 != (undefined4 *)0x0) {
    do {
      uVar9 = uVar7 + 1;
      *(byte *)(param_1 + (int)puVar10) = __s[uVar7];
      puVar10 = (undefined4 *)((int)puVar10 + 1);
      uVar7 = uVar9 & (int)((uVar9 - (int)param_3 ^ (uint)param_3 | uVar9 ^ (uint)param_3) ^ uVar9)
                      >> 0x1f;
    } while (puVar10 != param_3);
  }
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

