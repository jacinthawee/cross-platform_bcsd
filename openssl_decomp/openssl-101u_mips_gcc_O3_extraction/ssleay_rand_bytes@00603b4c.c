
/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 ssleay_rand_bytes(undefined *param_1,int param_2,int param_3,int param_4)

{
  byte bVar1;
  bool bVar2;
  undefined *puVar3;
  undefined4 uVar4;
  int iVar6;
  undefined *puVar7;
  int *piVar8;
  undefined *puVar9;
  int iVar10;
  undefined *unaff_s2;
  int iVar11;
  byte *pbVar12;
  int iVar13;
  double dVar14;
  double dVar15;
  int local_e4;
  int *local_e0;
  undefined *local_cc;
  int local_ac;
  int local_8c;
  undefined auStack_88 [24];
  undefined auStack_70 [24];
  int local_58;
  int local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  int local_3c;
  int iVar5;
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  local_3c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_8c = (*(code *)PTR_getpid_006a9a68)();
  if (param_2 < 1) goto LAB_00604310;
  unaff_s2 = auStack_88;
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(unaff_s2);
  local_ac = ((param_2 + -1) / 10 + 1) * 10;
  local_cc = (undefined *)0x680000;
  if (param_4 != 0) goto LAB_00604334;
  local_cc = (undefined *)0x680000;
  do {
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x13,local_cc + -0x6bc4,0x185);
    (*(code *)PTR_CRYPTO_THREADID_current_006a848c)(&locking_threadid);
    (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x13,local_cc + -0x6bc4,0x187);
    crypto_lock_rand = 1;
    if (initialized == 0) {
      RAND_poll();
      initialized = 1;
    }
    dVar14 = entropy;
    if ((entropy < DAT_006794e0) && (entropy = entropy - (double)param_2, entropy < 0.0)) {
      entropy = 0.0;
    }
    if (stirred_pool_8644 == 0) {
      local_e4 = 0x34;
      puVar7 = local_cc + -0x6bc4;
      dVar15 = DAT_006794e0;
      do {
        if (crypto_lock_rand == 0) {
LAB_00604460:
          bVar2 = false;
          (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x12,puVar7,0xe6);
        }
        else {
          (*(code *)PTR_CRYPTO_THREADID_current_006a848c)(auStack_70);
          (*(code *)PTR_CRYPTO_lock_006a8144)(5,0x13,puVar7,0xdf);
          iVar11 = (*(code *)PTR_CRYPTO_THREADID_cmp_006a8480)(&locking_threadid,auStack_70);
          bVar2 = iVar11 == 0;
          (*(code *)PTR_CRYPTO_lock_006a8144)(6,0x13,puVar7,0xe1);
          if (iVar11 != 0) goto LAB_00604460;
        }
        iVar11 = state_index;
        local_58 = md_count._0_4_;
        local_54 = md_count._4_4_;
        state_index = state_index + 0x14;
        local_50 = md._0_4_;
        local_4c = md._4_4_;
        local_48 = md._8_4_;
        local_44 = md._12_4_;
        local_40 = md._16_4_;
        if (state_index < 0x3ff) {
          if ((0x3fe < state_num) || (iVar13 = state_index, state_index <= state_num))
          goto LAB_00604514;
        }
        else {
          state_num = 0x3ff;
          state_index = state_index % 0x3ff;
LAB_00604514:
          iVar13 = state_num;
        }
        state_num = iVar13;
        md_count._4_4_ = md_count._4_4_ + 1;
        if (!bVar2) {
          (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x12,puVar7,0x106);
        }
        iVar13 = iVar11 + -0x3eb;
        (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(auStack_70);
        uVar4 = (*(code *)PTR_EVP_sha1_006a75d0)();
        (*(code *)PTR_EVP_DigestInit_ex_006a757c)(auStack_70,uVar4,0);
        (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_70,&local_50,0x14);
        if (iVar13 < 1) {
          (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_70,state + iVar11,0x14);
        }
        else {
          (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_70,state + iVar11,0x14 - iVar13);
          (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_70,state,iVar13);
        }
        local_e0 = &local_58;
        (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_70,"....................",0x14);
        (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_70,local_e0,8);
        (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(auStack_70,&local_50,0);
        local_54 = local_54 + 1;
        piVar8 = &local_50;
        do {
          pbVar12 = state + iVar11;
          bVar1 = *(byte *)piVar8;
          iVar11 = iVar11 + 1;
          piVar8 = (int *)((int)piVar8 + 1);
          if (0x3fe < iVar11) {
            iVar11 = 0;
          }
          *pbVar12 = *pbVar12 ^ bVar1;
        } while (&local_3c != piVar8);
        (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(auStack_70);
        if (!bVar2) {
          (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x12,puVar7,0x137);
        }
        md._0_4_ = md._0_4_ ^ local_50;
        md._4_4_ = md._4_4_ ^ local_4c;
        md._8_4_ = md._8_4_ ^ local_48;
        md._12_4_ = md._12_4_ ^ local_44;
        md._16_4_ = md._16_4_ ^ local_40;
        if (entropy < dVar15) {
          entropy = entropy + 0.0;
        }
        if (!bVar2) {
          (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x12,puVar7,0x144);
        }
        local_e4 = local_e4 + -1;
      } while (local_e4 != 0);
      if (DAT_006794e0 <= dVar14) {
        stirred_pool_8644 = 1;
      }
    }
    iVar13 = state_num;
    iVar11 = state_index;
    local_e0 = &local_58;
    local_58 = md_count._0_4_;
    local_50 = md._0_4_;
    local_54 = md_count._4_4_;
    local_4c = md._4_4_;
    local_48 = md._8_4_;
    state_index = local_ac + state_index;
    local_44 = md._12_4_;
    local_40 = md._16_4_;
    if (state_num < state_index) {
      if (state_num == 0) {
        trap(7);
      }
      state_index = state_index % state_num;
    }
    md_count._0_4_ = md_count._0_4_ + 1;
    crypto_lock_rand = 0;
    if (param_4 != 0) {
      (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x12,local_cc + -0x6bc4,0x1d2);
    }
    iVar10 = param_2;
    do {
      iVar5 = 10;
      if (iVar10 < 0xb) {
        iVar5 = iVar10;
      }
      uVar4 = (*(code *)PTR_EVP_sha1_006a75d0)();
      iVar10 = iVar10 - iVar5;
      (*(code *)PTR_EVP_DigestInit_ex_006a757c)(unaff_s2,uVar4,0);
      if (local_8c != 0) {
        (*(code *)PTR_EVP_DigestUpdate_006a7580)(unaff_s2,&local_8c,4);
        local_8c = 0;
      }
      (*(code *)PTR_EVP_DigestUpdate_006a7580)(unaff_s2,&local_50,0x14);
      (*(code *)PTR_EVP_DigestUpdate_006a7580)(unaff_s2,local_e0,8);
      (*(code *)PTR_EVP_DigestUpdate_006a7580)(unaff_s2,param_1,iVar5);
      iVar6 = (iVar11 + 10) - iVar13;
      if (iVar6 < 1) {
        (*(code *)PTR_EVP_DigestUpdate_006a7580)(unaff_s2,state + iVar11,10);
      }
      else {
        (*(code *)PTR_EVP_DigestUpdate_006a7580)(unaff_s2,state + iVar11,10 - iVar6);
        (*(code *)PTR_EVP_DigestUpdate_006a7580)(unaff_s2,state,iVar6);
      }
      (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(unaff_s2,&local_50,0);
      iVar6 = iVar11 + 1;
      state[iVar11] = state[iVar11] ^ local_50._0_1_;
      if (iVar6 < iVar13) {
        iVar11 = iVar11 + 2;
      }
      else {
        iVar11 = 1;
        iVar6 = 0;
      }
      *param_1 = local_48._2_1_;
      state[iVar6] = state[iVar6] ^ local_50._1_1_;
      if (iVar11 < iVar13) {
        iVar6 = iVar11 + 1;
      }
      else {
        iVar6 = 1;
        iVar11 = 0;
      }
      pbVar12 = state + iVar11;
      if (iVar5 == 1) {
        puVar7 = param_1 + 1;
        *pbVar12 = local_50._2_1_ ^ *pbVar12;
        if (iVar6 < iVar13) goto LAB_00604290;
        state[0] = (byte)local_50 ^ state[0];
        if (1 < iVar13) {
          iVar11 = 1;
          goto LAB_00604264;
        }
        iVar6 = 1;
        iVar11 = 0;
      }
      else {
        puVar7 = param_1 + 2;
        param_1[1] = (undefined)local_48;
        *pbVar12 = *pbVar12 ^ local_50._2_1_;
        if (iVar6 < iVar13) {
LAB_00604290:
          iVar11 = iVar6 + 1;
        }
        else {
          iVar11 = 1;
          iVar6 = 0;
        }
        if (2 < iVar5) {
          *puVar7 = local_44._0_1_;
          puVar7 = puVar7 + 1;
        }
        state[iVar6] = state[iVar6] ^ (byte)local_50;
        if (iVar11 < iVar13) {
LAB_00604264:
          iVar6 = iVar11 + 1;
          puVar9 = puVar7;
        }
        else {
          iVar6 = 1;
          iVar11 = 0;
          puVar9 = puVar7;
        }
        puVar7 = puVar9;
        if (3 < iVar5) {
          puVar7 = puVar9 + 1;
          *puVar9 = local_44._1_1_;
        }
      }
      state[iVar11] = state[iVar11] ^ local_4c._0_1_;
      if (iVar6 < iVar13) {
        iVar11 = iVar6 + 1;
      }
      else {
        iVar11 = 1;
        iVar6 = 0;
      }
      puVar9 = puVar7;
      if (4 < iVar5) {
        puVar9 = puVar7 + 1;
        *puVar7 = local_44._2_1_;
      }
      state[iVar6] = state[iVar6] ^ local_4c._1_1_;
      if (iVar11 < iVar13) {
        iVar6 = iVar11 + 1;
      }
      else {
        iVar6 = 1;
        iVar11 = 0;
      }
      puVar7 = puVar9;
      if (5 < iVar5) {
        puVar7 = puVar9 + 1;
        *puVar9 = (undefined)local_44;
      }
      state[iVar11] = state[iVar11] ^ local_4c._2_1_;
      if (iVar6 < iVar13) {
        iVar11 = iVar6 + 1;
      }
      else {
        iVar11 = 1;
        iVar6 = 0;
      }
      puVar9 = puVar7;
      if (6 < iVar5) {
        puVar9 = puVar7 + 1;
        *puVar7 = local_40._0_1_;
      }
      state[iVar6] = state[iVar6] ^ (byte)local_4c;
      if (iVar11 < iVar13) {
        iVar6 = iVar11 + 1;
      }
      else {
        iVar6 = 1;
        iVar11 = 0;
      }
      puVar7 = puVar9;
      if (7 < iVar5) {
        puVar7 = puVar9 + 1;
        *puVar9 = local_40._1_1_;
      }
      state[iVar11] = state[iVar11] ^ local_48._0_1_;
      if (iVar6 < iVar13) {
        iVar11 = iVar6 + 1;
      }
      else {
        iVar11 = 1;
        iVar6 = 0;
      }
      puVar9 = puVar7;
      if (8 < iVar5) {
        puVar9 = puVar7 + 1;
        *puVar7 = local_40._2_1_;
      }
      if (iVar13 <= iVar11) {
        iVar11 = 0;
      }
      state[iVar6] = state[iVar6] ^ local_48._1_1_;
      param_1 = puVar9;
      if (iVar5 == 10) {
        param_1 = puVar9 + 1;
        *puVar9 = (undefined)local_40;
      }
    } while (0 < iVar10);
    uVar4 = (*(code *)PTR_EVP_sha1_006a75d0)();
    (*(code *)PTR_EVP_DigestInit_ex_006a757c)(unaff_s2,uVar4,0);
    (*(code *)PTR_EVP_DigestUpdate_006a7580)(unaff_s2,local_e0,8);
    (*(code *)PTR_EVP_DigestUpdate_006a7580)(unaff_s2,&local_50,0x14);
    if (param_4 == 0) {
      (*(code *)PTR_EVP_DigestUpdate_006a7580)(unaff_s2,md,0x14);
      (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(unaff_s2,md,0);
    }
    else {
      (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x12,local_cc + -0x6bc4,0x203);
      (*(code *)PTR_EVP_DigestUpdate_006a7580)(unaff_s2,md,0x14);
      (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(unaff_s2,md,0);
      (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x12,local_cc + -0x6bc4,0x207);
      param_1 = local_cc;
    }
    (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(unaff_s2);
    if (dVar14 < DAT_006794e0) {
      if (param_3 == 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x24,100,100,local_cc + -0x6bc4,0x20f);
        (*(code *)PTR_ERR_add_error_data_006a813c)
                  (1,"You need to read the OpenSSL FAQ, http://www.openssl.org/support/faq.html");
      }
      if (local_3c == *(int *)puVar3) {
        return 0;
      }
    }
    else {
LAB_00604310:
      if (local_3c == *(int *)puVar3) {
        return 1;
      }
    }
    local_cc = (undefined *)(*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_00604334:
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x12,local_cc + -0x6bc4,0x182);
  } while( true );
}

