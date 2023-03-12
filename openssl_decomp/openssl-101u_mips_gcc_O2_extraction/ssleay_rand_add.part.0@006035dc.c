
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void ssleay_rand_add_part_0(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  bool bVar2;
  undefined *puVar3;
  undefined4 uVar4;
  uint *puVar5;
  int iVar6;
  byte *pbVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  double dVar12;
  undefined auStack_68 [24];
  undefined4 local_50;
  int local_4c;
  uint local_48 [4];
  uint local_38;
  int local_34;
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  dVar12 = (double)CONCAT44(param_3,param_4);
  local_34 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (crypto_lock_rand == 0) {
LAB_00603658:
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x12,"md_rand.c",0xe6);
    bVar2 = false;
  }
  else {
    (*(code *)PTR_CRYPTO_THREADID_current_006a848c)(auStack_68);
    (*(code *)PTR_CRYPTO_lock_006a8144)(5,0x13,"md_rand.c",0xdf);
    iVar6 = (*(code *)PTR_CRYPTO_THREADID_cmp_006a8480)(&locking_threadid,auStack_68);
    bVar2 = iVar6 == 0;
    (*(code *)PTR_CRYPTO_lock_006a8144)(6,0x13,"md_rand.c",0xe1);
    if (iVar6 != 0) goto LAB_00603658;
  }
  iVar6 = state_index;
  state_index = state_index + param_2;
  local_50 = md_count._0_4_;
  local_4c = md_count._4_4_;
  local_48[0] = md._0_4_;
  local_48[1] = md._4_4_;
  local_48[2] = md._8_4_;
  local_48[3] = md._12_4_;
  local_38 = md._16_4_;
  if (state_index < 0x3ff) {
    if ((state_num < 0x3ff) && (state_num < state_index)) {
      state_num = state_index;
    }
  }
  else {
    state_num = 0x3ff;
    state_index = state_index % 0x3ff;
  }
  md_count._4_4_ = (uint)(0 < param_2 % 0x14) + param_2 / 0x14 + md_count._4_4_;
  if (bVar2) {
    (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(auStack_68);
    if (param_2 < 1) {
      (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(auStack_68);
      goto LAB_006038d4;
    }
LAB_00603778:
    iVar10 = 0;
    do {
      iVar11 = param_2 - iVar10;
      if (0x14 < iVar11) {
        iVar11 = 0x14;
      }
      uVar4 = (*(code *)PTR_EVP_sha1_006a75d0)();
      (*(code *)PTR_EVP_DigestInit_ex_006a757c)(auStack_68,uVar4,0);
      (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_68,local_48,0x14);
      iVar9 = iVar11 + iVar6 + -0x3ff;
      if (iVar9 < 1) {
        (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_68,state + iVar6,iVar11);
      }
      else {
        (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_68,state + iVar6,iVar11 - iVar9);
        (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_68,state,iVar9);
      }
      (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_68,param_1,iVar11);
      param_1 = param_1 + iVar11;
      (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_68,&local_50,8);
      (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(auStack_68,local_48,0);
      local_4c = local_4c + 1;
      if (0 < iVar11) {
        puVar5 = local_48;
        do {
          pbVar7 = state + iVar6;
          bVar1 = *(byte *)puVar5;
          iVar6 = iVar6 + 1;
          puVar5 = (uint *)((int)puVar5 + 1);
          if (0x3fe < iVar6) {
            iVar6 = 0;
          }
          *pbVar7 = *pbVar7 ^ bVar1;
        } while (puVar5 != (uint *)((int)local_48 + iVar11));
      }
      iVar10 = iVar10 + 0x14;
    } while (iVar10 < param_2);
    (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(auStack_68);
    if (bVar2) goto LAB_006038d4;
  }
  else {
    (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x12,"md_rand.c",0x106);
    (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(auStack_68);
    if (0 < param_2) goto LAB_00603778;
    (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(auStack_68);
  }
  (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x12,"md_rand.c",0x137);
LAB_006038d4:
  md._0_4_ = local_48[0] ^ md._0_4_;
  md._4_4_ = md._4_4_ ^ local_48[1];
  md._8_4_ = md._8_4_ ^ local_48[2];
  md._16_4_ = md._16_4_ ^ local_38;
  md._12_4_ = local_48[3] ^ md._12_4_;
  if (entropy < DAT_006794e0) {
    entropy = entropy + dVar12;
  }
  uVar8 = local_38;
  if (!bVar2) {
    uVar8 = 0x12;
    (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x12,"md_rand.c",0x144);
  }
  if (local_34 != *(int *)puVar3) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    if (uVar8 == 0) {
      return;
    }
    ssleay_rand_add_part_0();
    return;
  }
  return;
}

