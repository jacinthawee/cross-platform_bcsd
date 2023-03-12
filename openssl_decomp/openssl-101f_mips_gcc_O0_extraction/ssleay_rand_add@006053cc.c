
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void ssleay_rand_add(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  bool bVar2;
  undefined *puVar3;
  undefined4 uVar4;
  uint *puVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  double dVar11;
  undefined auStack_68 [24];
  undefined4 local_50;
  int local_4c;
  uint local_48 [4];
  uint local_38;
  int local_34;
  
  puVar3 = PTR___stack_chk_guard_006aabf0;
  dVar11 = (double)CONCAT44(param_3,param_4);
  local_34 = *(int *)PTR___stack_chk_guard_006aabf0;
  if (crypto_lock_rand == 0) {
LAB_00605448:
    (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x12,"md_rand.c",0xe4);
    bVar2 = false;
  }
  else {
    (*(code *)PTR_CRYPTO_THREADID_current_006a95ac)(auStack_68);
    (*(code *)PTR_CRYPTO_lock_006a926c)(5,0x13,"md_rand.c",0xdd);
    iVar6 = (*(code *)PTR_CRYPTO_THREADID_cmp_006a95a0)(&locking_threadid,auStack_68);
    bVar2 = iVar6 == 0;
    (*(code *)PTR_CRYPTO_lock_006a926c)(6,0x13,"md_rand.c",0xdf);
    if (iVar6 != 0) goto LAB_00605448;
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
    (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(auStack_68);
    if (param_2 < 1) {
      (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(auStack_68);
      goto LAB_006056c4;
    }
LAB_00605568:
    iVar9 = 0;
    do {
      iVar10 = param_2 - iVar9;
      if (0x14 < iVar10) {
        iVar10 = 0x14;
      }
      uVar4 = (*(code *)PTR_EVP_sha1_006a86c4)();
      (*(code *)PTR_EVP_DigestInit_ex_006a8670)(auStack_68,uVar4,0);
      (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_68,local_48,0x14);
      iVar8 = iVar10 + iVar6 + -0x3ff;
      if (iVar8 < 1) {
        (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_68,state + iVar6,iVar10);
      }
      else {
        (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_68,state + iVar6,iVar10 - iVar8);
        (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_68,state,iVar8);
      }
      (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_68,param_1,iVar10);
      param_1 = param_1 + iVar10;
      (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_68,&local_50,8);
      (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(auStack_68,local_48,0);
      local_4c = local_4c + 1;
      if (0 < iVar10) {
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
        } while (puVar5 != (uint *)((int)local_48 + iVar10));
      }
      iVar9 = iVar9 + 0x14;
    } while (iVar9 < param_2);
    (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(auStack_68);
    if (bVar2) goto LAB_006056c4;
  }
  else {
    (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x12,"md_rand.c",0x104);
    (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(auStack_68);
    if (0 < param_2) goto LAB_00605568;
    (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(auStack_68);
  }
  (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x12,"md_rand.c",0x137);
LAB_006056c4:
  md._0_4_ = local_48[0] ^ md._0_4_;
  md._4_4_ = md._4_4_ ^ local_48[1];
  md._8_4_ = md._8_4_ ^ local_48[2];
  md._16_4_ = md._16_4_ ^ local_38;
  md._12_4_ = local_48[3] ^ md._12_4_;
  if (entropy < DAT_00679d70) {
    entropy = entropy + dVar11;
  }
  if (!bVar2) {
    (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x12,"md_rand.c",0x142);
  }
  if (local_34 != *(int *)puVar3) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    ssleay_rand_add();
    return;
  }
  return;
}

