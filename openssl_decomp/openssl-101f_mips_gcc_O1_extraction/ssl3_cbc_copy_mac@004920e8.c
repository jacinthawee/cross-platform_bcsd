
int ssl3_cbc_copy_mac(byte *param_1,int param_2,uint param_3,uint param_4)

{
  undefined *puVar1;
  int iVar2;
  byte bVar4;
  undefined4 uVar3;
  uint uVar5;
  byte *pbVar6;
  uint uVar7;
  byte *pbVar8;
  byte *pbVar9;
  uint uVar10;
  int iVar11;
  byte *pbVar12;
  uint uVar13;
  byte abStack_ac [128];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iVar11 = *(int *)(param_2 + 4) - param_3;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (param_4 < param_3) {
    (*(code *)PTR_OpenSSLDie_006a8d4c)("s3_cbc.c",0x113,"orig_len >= md_size");
  }
  if (0x40 < param_3) {
    (*(code *)PTR_OpenSSLDie_006a8d4c)("s3_cbc.c",0x114,"md_size <= EVP_MAX_MD_SIZE");
  }
  pbVar12 = abStack_ac + (-(int)abStack_ac & 0x3f);
  if (param_3 + 0x100 < param_4) {
    uVar10 = (param_4 - 0x100) - param_3;
  }
  else {
    uVar10 = 0;
  }
  if (param_3 == 0) {
    trap(7);
  }
  uVar13 = (((param_3 >> 1) * 0x1000000 + iVar11) - uVar10) % param_3;
  (*(code *)PTR_memset_006aab00)(pbVar12,0,param_3);
  if (uVar10 < param_4) {
    iVar2 = *(int *)(param_2 + 0xc);
    uVar5 = 0;
    uVar7 = ~(uVar10 - iVar11);
    pbVar6 = (byte *)(iVar2 + uVar10);
    do {
      pbVar8 = pbVar12 + uVar5;
      bVar4 = (byte)((int)uVar7 >> 0x1f) & *pbVar6;
      if ((int)(param_3 + uVar7) < 0) {
        bVar4 = 0;
      }
      pbVar6 = pbVar6 + 1;
      uVar7 = uVar7 - 1;
      uVar5 = uVar5 + 1 & (int)((uVar5 + 1) - param_3) >> 0x1f;
      *pbVar8 = bVar4 | *pbVar8;
    } while ((byte *)(iVar2 + param_4) != pbVar6);
  }
  pbVar6 = param_1;
  if (param_3 != 0) {
    do {
      pbVar8 = pbVar12 + uVar13;
      pbVar9 = pbVar6 + 1;
      uVar13 = uVar13 + 1 & (int)((uVar13 + 1) - param_3) >> 0x1f;
      *pbVar6 = *pbVar8;
      pbVar6 = pbVar9;
    } while (pbVar9 != param_1 + param_3);
  }
  if (local_2c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    uVar3 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)();
    iVar11 = (*(code *)PTR_EVP_MD_type_006a84cc)(uVar3);
    if (iVar11 != 0x40) {
      if (iVar11 < 0x41) {
        if (iVar11 != 4) {
          return 0;
        }
      }
      else if (3 < iVar11 - 0x2a0U) {
        return 0;
      }
    }
    return 1;
  }
  return *(int *)puVar1;
}

