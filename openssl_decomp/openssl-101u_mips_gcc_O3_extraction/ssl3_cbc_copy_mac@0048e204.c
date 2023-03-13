
int ssl3_cbc_copy_mac(byte *param_1,int param_2,uint param_3,uint param_4)

{
  byte bVar1;
  byte bVar2;
  undefined *puVar3;
  byte bVar5;
  undefined4 uVar4;
  int iVar6;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  byte *pbVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  byte abStack_ac [128];
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  iVar12 = *(int *)(param_2 + 4);
  uVar13 = iVar12 - param_3;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (param_4 < param_3) {
    (*(code *)PTR_OpenSSLDie_006a7c5c)("s3_cbc.c",0xf8,"orig_len >= md_size");
  }
  if (0x40 < param_3) {
    (*(code *)PTR_OpenSSLDie_006a7c5c)("s3_cbc.c",0xf9,"md_size <= EVP_MAX_MD_SIZE");
  }
  pbVar11 = abStack_ac + (-(int)abStack_ac & 0x3f);
  if (param_3 + 0x100 < param_4) {
    uVar10 = (param_4 - 0x100) - param_3;
  }
  else {
    uVar10 = 0;
  }
  if (param_3 == 0) {
    trap(7);
  }
  uVar14 = (((param_3 >> 1) * 0x1000000 + uVar13) - uVar10) % param_3;
  (*(code *)PTR_memset_006a99f4)(pbVar11,0,param_3);
  if (uVar10 < param_4) {
    uVar9 = 0;
    pbVar7 = (byte *)(*(int *)(param_2 + 0xc) + uVar10);
    do {
      bVar5 = *pbVar7;
      iVar6 = uVar10 - iVar12;
      if ((int)((uVar10 - uVar13 ^ uVar13 | uVar13 ^ uVar10) ^ uVar10) < 0) {
        bVar5 = 0;
      }
      uVar8 = uVar9 + 1;
      bVar1 = (byte)((uint)iVar12 >> 0x18);
      bVar2 = (byte)(uVar10 >> 0x18);
      uVar10 = uVar10 + 1;
      pbVar11[uVar9] =
           bVar5 & (char)(((byte)((uint)iVar6 >> 0x18) ^ bVar1 | bVar1 ^ bVar2) ^ bVar2) >> 7 |
           pbVar11[uVar9];
      pbVar7 = pbVar7 + 1;
      uVar9 = uVar8 & (int)((uVar8 - param_3 ^ param_3 | param_3 ^ uVar8) ^ uVar8) >> 0x1f;
    } while (param_4 != uVar10);
  }
  if (param_3 != 0) {
    pbVar7 = param_1 + param_3;
    do {
      uVar13 = uVar14 + 1;
      *param_1 = pbVar11[uVar14];
      param_1 = param_1 + 1;
      uVar14 = uVar13 & (int)((uVar13 - param_3 ^ param_3 | param_3 ^ uVar13) ^ uVar13) >> 0x1f;
    } while (param_1 != pbVar7);
  }
  if (local_2c != *(int *)puVar3) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    uVar4 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)();
    iVar12 = (*(code *)PTR_EVP_MD_type_006a73cc)(uVar4);
    if (iVar12 != 0x40) {
      if (iVar12 < 0x41) {
        if (iVar12 != 4) {
          return 0;
        }
      }
      else if (3 < iVar12 - 0x2a0U) {
        return 0;
      }
    }
    return 1;
  }
  return *(int *)puVar3;
}

