
/* WARNING: Removing unreachable block (ram,0x00606040) */
/* WARNING: Could not reconcile some variable overlaps */

undefined4 ssleay_rand_nopseudo_bytes(undefined *param_1,int param_2)

{
  byte bVar1;
  bool bVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar7;
  undefined *puVar8;
  int *piVar9;
  undefined *puVar10;
  int iVar11;
  undefined *unaff_s2;
  byte *pbVar12;
  int iVar13;
  double in_f20_21;
  double dVar14;
  int iStack_e4;
  int *piStack_e0;
  undefined1 *puStack_cc;
  undefined1 *puStack_c8;
  undefined *puStack_c0;
  int iStack_bc;
  int iStack_ac;
  undefined1 *puStack_a4;
  undefined1 *puStack_a0;
  int iStack_8c;
  undefined auStack_88 [24];
  undefined auStack_70 [24];
  int iStack_58;
  int iStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  int iStack_3c;
  int iVar6;
  
  puVar3 = PTR___stack_chk_guard_006aabf0;
  iStack_3c = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_8c = (*(code *)PTR_getpid_006aab70)();
  if (param_2 < 1) goto LAB_00606188;
  unaff_s2 = auStack_88;
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(unaff_s2);
  puStack_c0 = (undefined *)0x680000;
  iStack_ac = ((param_2 + -1) / 10 + 1) * 10;
  (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x12,"md_rand.c",0x183);
  (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x13,"md_rand.c",0x186);
  puStack_a4 = &_ITM_registerTMCloneTable;
  (*(code *)PTR_CRYPTO_THREADID_current_006a95ac)(&locking_threadid);
  (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x13,"md_rand.c",0x188);
  puStack_c8 = &_ITM_registerTMCloneTable;
  crypto_lock_rand = 1;
  if (initialized == 0) {
    RAND_poll();
    initialized = 1;
  }
  in_f20_21 = entropy;
  puStack_cc = &_ITM_registerTMCloneTable;
  iStack_bc = 0x680000;
  puStack_a0 = &_ITM_registerTMCloneTable;
  if ((entropy < DAT_00679d70) && (entropy = entropy - (double)param_2, entropy < 0.0)) {
    entropy = 0.0;
  }
  iVar4 = 0x680000;
  if (stirred_pool_8635 == 0) goto LAB_006061ac;
  do {
    iVar13 = state_num;
    iVar4 = state_index;
    puVar8 = PTR_CRYPTO_lock_006a926c;
    piStack_e0 = &iStack_58;
    iStack_58 = md_count._0_4_;
    uStack_50 = md._0_4_;
    iStack_54 = md_count._4_4_;
    uStack_4c = md._4_4_;
    uStack_48 = md._8_4_;
    state_index = iStack_ac + state_index;
    uStack_44 = md._12_4_;
    uStack_40 = md._16_4_;
    if (state_num < state_index) {
      if (state_num == 0) {
        trap(7);
      }
      state_index = state_index % state_num;
    }
    md_count._0_4_ = md_count._0_4_ + 1;
    *(undefined4 *)(puStack_c8 + -0xa14) = 0;
    (*(code *)puVar8)(10,0x12,puStack_c0 + -0x6338,0x1d5);
    iVar11 = param_2;
    do {
      iVar6 = 10;
      if (iVar11 < 0xb) {
        iVar6 = iVar11;
      }
      uVar5 = (*(code *)PTR_EVP_sha1_006a86c4)();
      iVar11 = iVar11 - iVar6;
      (*(code *)PTR_EVP_DigestInit_ex_006a8670)(unaff_s2,uVar5,0);
      if (iStack_8c != 0) {
        (*(code *)PTR_EVP_DigestUpdate_006a8674)(unaff_s2,&iStack_8c,4);
        iStack_8c = 0;
      }
      (*(code *)PTR_EVP_DigestUpdate_006a8674)(unaff_s2,&uStack_50,0x14);
      (*(code *)PTR_EVP_DigestUpdate_006a8674)(unaff_s2,piStack_e0,8);
      (*(code *)PTR_EVP_DigestUpdate_006a8674)(unaff_s2,param_1,iVar6);
      iVar7 = (iVar4 + 10) - iVar13;
      if (iVar7 < 1) {
        (*(code *)PTR_EVP_DigestUpdate_006a8674)(unaff_s2,state + iVar4,10);
      }
      else {
        (*(code *)PTR_EVP_DigestUpdate_006a8674)(unaff_s2,state + iVar4,10 - iVar7);
        (*(code *)PTR_EVP_DigestUpdate_006a8674)(unaff_s2,state,iVar7);
      }
      (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(unaff_s2,&uStack_50,0);
      iVar7 = iVar4 + 1;
      state[iVar4] = state[iVar4] ^ uStack_50._0_1_;
      if (iVar7 < iVar13) {
        iVar4 = iVar4 + 2;
      }
      else {
        iVar4 = 1;
        iVar7 = 0;
      }
      *param_1 = uStack_48._2_1_;
      state[iVar7] = state[iVar7] ^ uStack_50._1_1_;
      if (iVar4 < iVar13) {
        iVar7 = iVar4 + 1;
      }
      else {
        iVar7 = 1;
        iVar4 = 0;
      }
      pbVar12 = state + iVar4;
      if (iVar6 == 1) {
        puVar8 = param_1 + 1;
        *pbVar12 = uStack_50._2_1_ ^ *pbVar12;
        if (iVar7 < iVar13) goto LAB_00606114;
        state[0] = (byte)uStack_50 ^ state[0];
        if (1 < iVar13) {
          iVar4 = 1;
          goto LAB_0060610c;
        }
        iVar7 = 1;
        iVar4 = 0;
      }
      else {
        puVar8 = param_1 + 2;
        param_1[1] = (undefined)uStack_48;
        *pbVar12 = *pbVar12 ^ uStack_50._2_1_;
        if (iVar7 < iVar13) {
LAB_00606114:
          iVar4 = iVar7 + 1;
        }
        else {
          iVar4 = 1;
          iVar7 = 0;
        }
        if (2 < iVar6) {
          *puVar8 = uStack_44._0_1_;
          puVar8 = puVar8 + 1;
        }
        state[iVar7] = state[iVar7] ^ (byte)uStack_50;
        if (iVar4 < iVar13) {
LAB_0060610c:
          iVar7 = iVar4 + 1;
          puVar10 = puVar8;
        }
        else {
          iVar7 = 1;
          iVar4 = 0;
          puVar10 = puVar8;
        }
        puVar8 = puVar10;
        if (3 < iVar6) {
          puVar8 = puVar10 + 1;
          *puVar10 = uStack_44._1_1_;
        }
      }
      state[iVar4] = state[iVar4] ^ uStack_4c._0_1_;
      if (iVar7 < iVar13) {
        iVar4 = iVar7 + 1;
      }
      else {
        iVar4 = 1;
        iVar7 = 0;
      }
      puVar10 = puVar8;
      if (4 < iVar6) {
        puVar10 = puVar8 + 1;
        *puVar8 = uStack_44._2_1_;
      }
      state[iVar7] = state[iVar7] ^ uStack_4c._1_1_;
      if (iVar4 < iVar13) {
        iVar7 = iVar4 + 1;
      }
      else {
        iVar7 = 1;
        iVar4 = 0;
      }
      puVar8 = puVar10;
      if (5 < iVar6) {
        puVar8 = puVar10 + 1;
        *puVar10 = (undefined)uStack_44;
      }
      state[iVar4] = state[iVar4] ^ uStack_4c._2_1_;
      if (iVar7 < iVar13) {
        iVar4 = iVar7 + 1;
      }
      else {
        iVar4 = 1;
        iVar7 = 0;
      }
      puVar10 = puVar8;
      if (6 < iVar6) {
        puVar10 = puVar8 + 1;
        *puVar8 = uStack_40._0_1_;
      }
      state[iVar7] = state[iVar7] ^ (byte)uStack_4c;
      if (iVar4 < iVar13) {
        iVar7 = iVar4 + 1;
      }
      else {
        iVar7 = 1;
        iVar4 = 0;
      }
      puVar8 = puVar10;
      if (7 < iVar6) {
        puVar8 = puVar10 + 1;
        *puVar10 = uStack_40._1_1_;
      }
      state[iVar4] = state[iVar4] ^ uStack_48._0_1_;
      if (iVar7 < iVar13) {
        iVar4 = iVar7 + 1;
      }
      else {
        iVar4 = 1;
        iVar7 = 0;
      }
      puVar10 = puVar8;
      if (8 < iVar6) {
        puVar10 = puVar8 + 1;
        *puVar8 = uStack_40._2_1_;
      }
      if (iVar13 <= iVar4) {
        iVar4 = 0;
      }
      state[iVar7] = state[iVar7] ^ uStack_48._1_1_;
      param_1 = puVar10;
      if (iVar6 == 10) {
        param_1 = puVar10 + 1;
        *puVar10 = (undefined)uStack_40;
      }
    } while (0 < iVar11);
    uVar5 = (*(code *)PTR_EVP_sha1_006a86c4)();
    (*(code *)PTR_EVP_DigestInit_ex_006a8670)(unaff_s2,uVar5,0);
    (*(code *)PTR_EVP_DigestUpdate_006a8674)(unaff_s2,piStack_e0,8);
    (*(code *)PTR_EVP_DigestUpdate_006a8674)(unaff_s2,&uStack_50,0x14);
    (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x12,puStack_c0 + -0x6338,0x20c);
    (*(code *)PTR_EVP_DigestUpdate_006a8674)(unaff_s2,md,0x14);
    (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(unaff_s2,md,0);
    (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x12,puStack_c0 + -0x6338,0x212);
    (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(unaff_s2);
    param_1 = puStack_c0;
    if (in_f20_21 < *(double *)(iStack_bc + -0x6290)) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x24,100,100,"md_rand.c",0x21b);
      (*(code *)PTR_ERR_add_error_data_006a9264)
                (1,"You need to read the OpenSSL FAQ, http://www.openssl.org/support/faq.html");
      if (iStack_3c == *(int *)puVar3) {
        return 0;
      }
    }
    else {
LAB_00606188:
      if (iStack_3c == *(int *)puVar3) {
        return 1;
      }
    }
    iVar4 = (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_006061ac:
    dVar14 = *(double *)(iVar4 + -0x6290);
    iStack_e4 = 0x34;
    puVar8 = puStack_c0 + -0x6338;
    do {
      if (*(int *)(puStack_c8 + -0xa14) == 0) {
LAB_0060624c:
        bVar2 = false;
        (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x12,puVar8,0xe4);
      }
      else {
        (*(code *)PTR_CRYPTO_THREADID_current_006a95ac)(auStack_70);
        (*(code *)PTR_CRYPTO_lock_006a926c)(5,0x13,puVar8,0xdd);
        iVar4 = (*(code *)PTR_CRYPTO_THREADID_cmp_006a95a0)(puStack_a4 + -0xa1c,auStack_70);
        bVar2 = iVar4 == 0;
        (*(code *)PTR_CRYPTO_lock_006a926c)(6,0x13,puVar8,0xdf);
        if (iVar4 != 0) goto LAB_0060624c;
      }
      iVar4 = state_index;
      iStack_58 = md_count._0_4_;
      iStack_54 = md_count._4_4_;
      state_index = state_index + 0x14;
      uStack_50 = md._0_4_;
      uStack_4c = md._4_4_;
      uStack_48 = md._8_4_;
      uStack_44 = md._12_4_;
      uStack_40 = md._16_4_;
      if (state_index < 0x3ff) {
        if ((0x3fe < state_num) || (iVar13 = state_index, state_index <= state_num))
        goto LAB_00606300;
      }
      else {
        state_num = 0x3ff;
        state_index = state_index % 0x3ff;
LAB_00606300:
        iVar13 = state_num;
      }
      state_num = iVar13;
      md_count._4_4_ = md_count._4_4_ + 1;
      if (!bVar2) {
        (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x12,puVar8,0x104);
      }
      iVar13 = iVar4 + -0x3eb;
      (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(auStack_70);
      uVar5 = (*(code *)PTR_EVP_sha1_006a86c4)();
      (*(code *)PTR_EVP_DigestInit_ex_006a8670)(auStack_70,uVar5,0);
      (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_70,&uStack_50,0x14);
      if (iVar13 < 1) {
        (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_70,state + iVar4,0x14);
      }
      else {
        (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_70,state + iVar4,0x14 - iVar13);
        (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_70,state,iVar13);
      }
      piStack_e0 = &iStack_58;
      (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_70,"....................",0x14);
      (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_70,piStack_e0,8);
      (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(auStack_70,&uStack_50,0);
      iStack_54 = iStack_54 + 1;
      piVar9 = &uStack_50;
      do {
        pbVar12 = state + iVar4;
        bVar1 = *(byte *)piVar9;
        iVar4 = iVar4 + 1;
        piVar9 = (int *)((int)piVar9 + 1);
        if (0x3fe < iVar4) {
          iVar4 = 0;
        }
        *pbVar12 = *pbVar12 ^ bVar1;
      } while (&iStack_3c != piVar9);
      (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(auStack_70);
      if (!bVar2) {
        (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x12,puVar8,0x137);
      }
      md._0_4_ = md._0_4_ ^ uStack_50;
      md._4_4_ = md._4_4_ ^ uStack_4c;
      md._8_4_ = md._8_4_ ^ uStack_48;
      md._12_4_ = md._12_4_ ^ uStack_44;
      md._16_4_ = md._16_4_ ^ uStack_40;
      if (*(double *)(puStack_cc + -0xa08) < dVar14) {
        entropy = *(double *)(puStack_cc + -0xa08) + 0.0;
      }
      if (!bVar2) {
        (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x12,puVar8,0x142);
      }
      iStack_e4 = iStack_e4 + -1;
    } while (iStack_e4 != 0);
    if (*(double *)(iStack_bc + -0x6290) <= in_f20_21) {
      *(undefined4 *)(puStack_a0 + -0xa20) = 1;
    }
  } while( true );
}

