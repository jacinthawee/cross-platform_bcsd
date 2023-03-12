
/* WARNING: Heritage AFTER dead removal. Example location: r0x00194c40 : 0x0010abca */
/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void ssleay_rand_bytes(undefined *param_1,size_t param_2,uint param_3,int param_4)

{
  bool bVar1;
  double dVar2;
  double dVar3;
  undefined *puVar4;
  ENGINE *pEVar5;
  EVP_MD *pEVar6;
  uint uVar7;
  int extraout_r1;
  size_t cnt;
  byte *pbVar8;
  int iVar9;
  size_t cnt_00;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int local_b8;
  undefined *local_b4;
  undefined4 *local_b0;
  __pid_t local_8c;
  EVP_MD *local_88;
  ENGINE *local_84;
  EVP_MD_CTX EStack_80;
  undefined local_68 [24];
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  int local_3c;
  
  local_3c = __stack_chk_guard;
  local_8c = getpid();
  if (0 < (int)param_2) {
    EVP_MD_CTX_init(&EStack_80);
    if (param_4 != 0) {
      CRYPTO_lock(9,0x12,"md_rand.c",0x182);
    }
    CRYPTO_lock(9,0x13,"md_rand.c",0x185);
    CRYPTO_THREADID_current((CRYPTO_THREADID *)&locking_threadid);
    CRYPTO_lock(10,0x13,"md_rand.c",0x187);
    crypto_lock_rand = 1;
    if (initialized == 0) {
      RAND_poll();
      initialized = 1;
    }
    puVar4 = PTR_state_0010aedc;
    dVar3 = DAT_0010aed0;
    dVar2 = DAT_0010aec8;
    uVar7 = (uint)(DAT_0010ab68 <= entropy);
    if ((uVar7 == 0) &&
       (entropy = entropy - (double)(longlong)(int)param_2, (int)((uint)(entropy < 0.0) << 0x1f) < 0
       )) {
      entropy = 0.0;
    }
    if (stirred_pool_11275 == 0) {
      local_b4 = PTR_state_0010aedc;
      local_b8 = 0x34;
      do {
        if (crypto_lock_rand == 0) {
LAB_0010ac14:
          bVar1 = false;
          CRYPTO_lock(9,0x12,"md_rand.c",0xe6);
        }
        else {
          bVar1 = true;
          CRYPTO_THREADID_current((CRYPTO_THREADID *)(EVP_MD_CTX *)local_68);
          CRYPTO_lock(5,0x13,"md_rand.c",0xdf);
          iVar12 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)PTR_locking_threadid_0010aee0,
                                       (CRYPTO_THREADID *)(EVP_MD_CTX *)local_68);
          CRYPTO_lock(6,0x13,"md_rand.c",0xe1);
          if (iVar12 != 0) goto LAB_0010ac14;
        }
        iVar12 = state_index;
        local_50 = *(uint *)PTR_md_0010aed8;
        local_4c = *(uint *)(PTR_md_0010aed8 + 4);
        local_48 = *(uint *)(PTR_md_0010aed8 + 8);
        local_44 = *(uint *)(PTR_md_0010aed8 + 0xc);
        state_index = state_index + 0x14;
        local_40 = *(uint *)(PTR_md_0010aed8 + 0x10);
        local_88 = (EVP_MD *)md_count;
        local_84 = md_count._4_4_;
        if (state_index < 0x3ff) {
          if ((state_num < 0x3ff) && (state_num < state_index)) {
            state_num = state_index;
          }
        }
        else {
          state_num = 0x3ff;
          state_index = state_index % 0x3ff;
        }
        pEVar5 = md_count._4_4_ + 1;
        if (!bVar1) {
          md_count._4_4_ = md_count._4_4_ + 1;
          CRYPTO_lock(10,0x12,"md_rand.c",0x106);
          pEVar5 = md_count._4_4_;
        }
        md_count._4_4_ = pEVar5;
        EVP_MD_CTX_init((EVP_MD_CTX *)local_68);
        pEVar6 = EVP_sha1();
        EVP_DigestInit_ex((EVP_MD_CTX *)local_68,pEVar6,(ENGINE *)0x0);
        EVP_DigestUpdate((EVP_MD_CTX *)local_68,&local_50,0x14);
        if ((int)(iVar12 - 0x3ebU) < 1) {
          EVP_DigestUpdate((EVP_MD_CTX *)local_68,puVar4 + iVar12,0x14);
        }
        else {
          EVP_DigestUpdate((EVP_MD_CTX *)local_68,puVar4 + iVar12,0x3ff - iVar12);
          EVP_DigestUpdate((EVP_MD_CTX *)local_68,PTR_state_0010aedc,iVar12 - 0x3ebU);
        }
        EVP_DigestUpdate((EVP_MD_CTX *)local_68,"....................",0x14);
        EVP_DigestUpdate((EVP_MD_CTX *)local_68,&local_88,8);
        EVP_DigestFinal_ex((EVP_MD_CTX *)local_68,(uchar *)&local_50,(uint *)0x0);
        pbVar8 = local_68 + 0x17;
        local_84 = local_84 + 1;
        do {
          pbVar8 = pbVar8 + 1;
          iVar9 = iVar12 + 1;
          if (0x3fe < iVar9) {
            iVar9 = 0;
          }
          state[iVar12] = *pbVar8 ^ state[iVar12];
          iVar12 = iVar9;
        } while (pbVar8 != (byte *)((int)&local_40 + 3));
        EVP_MD_CTX_cleanup((EVP_MD_CTX *)local_68);
        if (!bVar1) {
          CRYPTO_lock(9,0x12,"md_rand.c",0x137);
        }
        md._0_4_ = local_50 ^ md._0_4_;
        md._4_4_ = md._4_4_ ^ local_4c;
        md._8_4_ = md._8_4_ ^ local_48;
        md._12_4_ = md._12_4_ ^ local_44;
        md._16_4_ = md._16_4_ ^ local_40;
        if ((int)((uint)(entropy < dVar2) << 0x1f) < 0) {
          entropy = entropy + dVar3;
        }
        if (!bVar1) {
          CRYPTO_lock(10,0x12,"md_rand.c",0x144);
        }
        local_b8 = local_b8 + -1;
      } while (local_b8 != 0);
      if (uVar7 != 0) {
        stirred_pool_11275 = 1;
      }
    }
    else {
      local_b4 = PTR_state_0010ab70;
    }
    pEVar6 = (EVP_MD *)md_count;
    iVar12 = state_index;
    iVar9 = state_num;
    local_b0 = &local_50;
    iVar13 = ((int)(param_2 - 1) / 10 + 1) * 10 + state_index;
    local_50 = md._0_4_;
    local_4c = md._4_4_;
    local_48 = md._8_4_;
    local_44 = md._12_4_;
    local_40 = md._16_4_;
    local_68._0_4_ = (EVP_MD *)md_count;
    if (iVar13 <= state_num) {
      state_index = iVar13;
    }
    local_68._4_4_ = md_count._4_4_;
    if (state_num < iVar13) {
      __aeabi_idivmod(iVar13,state_num);
      state_index = extraout_r1;
    }
    md_count._0_4_ = (EVP_MD *)((int)&pEVar6->type + 1);
    crypto_lock_rand = 0;
    if (param_4 != 0) {
      CRYPTO_lock(10,0x12,"md_rand.c",0x1d2);
    }
    do {
      pEVar6 = EVP_sha1();
      cnt_00 = 10;
      if ((int)param_2 < 0xb) {
        cnt_00 = param_2;
      }
      param_2 = param_2 - cnt_00;
      EVP_DigestInit_ex(&EStack_80,pEVar6,(ENGINE *)0x0);
      if (local_8c != 0) {
        EVP_DigestUpdate(&EStack_80,&local_8c,4);
        local_8c = 0;
      }
      EVP_DigestUpdate(&EStack_80,local_b0,0x14);
      EVP_DigestUpdate(&EStack_80,local_68,8);
      EVP_DigestUpdate(&EStack_80,param_1,cnt_00);
      cnt = (iVar12 + 10) - iVar9;
      if ((int)cnt < 1) {
        EVP_DigestUpdate(&EStack_80,local_b4 + iVar12,10);
      }
      else {
        EVP_DigestUpdate(&EStack_80,local_b4 + iVar12,10 - cnt);
        EVP_DigestUpdate(&EStack_80,PTR_state_0010ab70,cnt);
      }
      EVP_DigestFinal_ex(&EStack_80,(uchar *)local_b0,(uint *)0x0);
      iVar13 = iVar12 + 1;
      iVar10 = iVar12;
      if (iVar13 < iVar9) {
        iVar10 = iVar12 + 2;
      }
      state[iVar12] = (byte)local_50 ^ state[iVar12];
      if (iVar9 <= iVar13) {
        iVar13 = 0;
        iVar10 = 1;
      }
      *param_1 = local_48._2_1_;
      iVar11 = iVar10;
      if (iVar9 <= iVar10) {
        iVar11 = 0;
      }
      state[iVar13] = local_50._1_1_ ^ state[iVar13];
      if (iVar10 < iVar9) {
        iVar13 = iVar11 + 1;
      }
      else {
        iVar13 = 1;
      }
      iVar12 = (int)&crypto_lock_rand + iVar11;
      if (cnt_00 == 1) {
        param_1 = param_1 + 1;
      }
      else {
        param_1[1] = local_48._3_1_;
        param_1 = param_1 + 2;
      }
      iVar10 = iVar13;
      if (iVar9 <= iVar13) {
        iVar10 = 0;
      }
      state[iVar11] = local_50._2_1_ ^ state[iVar11];
      if (iVar13 < iVar9) {
        iVar13 = iVar10 + 1;
      }
      else {
        iVar13 = 1;
      }
      if (2 < (int)cnt_00) {
        *param_1 = (undefined)local_44;
        param_1 = param_1 + 1;
      }
      iVar11 = iVar13;
      if (iVar9 <= iVar13) {
        iVar11 = 0;
      }
      state[iVar10] = local_50._3_1_ ^ state[iVar10];
      if (iVar13 < iVar9) {
        iVar13 = iVar11 + 1;
      }
      else {
        iVar13 = 1;
      }
      if (3 < (int)cnt_00) {
        *param_1 = local_44._1_1_;
        param_1 = param_1 + 1;
      }
      iVar10 = iVar13;
      if (iVar9 <= iVar13) {
        iVar10 = 0;
      }
      state[iVar11] = (byte)local_4c ^ state[iVar11];
      if (iVar13 < iVar9) {
        iVar13 = iVar10 + 1;
      }
      else {
        iVar13 = 1;
      }
      if (4 < (int)cnt_00) {
        *param_1 = local_44._2_1_;
        param_1 = param_1 + 1;
      }
      iVar11 = iVar13;
      if (iVar9 <= iVar13) {
        iVar11 = 0;
      }
      state[iVar10] = local_4c._1_1_ ^ state[iVar10];
      if (iVar13 < iVar9) {
        iVar13 = iVar11 + 1;
      }
      else {
        iVar13 = 1;
      }
      if (5 < (int)cnt_00) {
        *param_1 = local_44._3_1_;
        param_1 = param_1 + 1;
      }
      iVar10 = iVar13;
      if (iVar9 <= iVar13) {
        iVar10 = 0;
      }
      state[iVar11] = local_4c._2_1_ ^ state[iVar11];
      if (iVar13 < iVar9) {
        iVar13 = iVar10 + 1;
      }
      else {
        iVar13 = 1;
      }
      if (6 < (int)cnt_00) {
        *param_1 = (undefined)local_40;
        param_1 = param_1 + 1;
      }
      iVar11 = iVar13;
      if (iVar9 <= iVar13) {
        iVar11 = 0;
      }
      state[iVar10] = local_4c._3_1_ ^ state[iVar10];
      if (iVar13 < iVar9) {
        iVar13 = iVar11 + 1;
      }
      else {
        iVar13 = 1;
      }
      if (7 < (int)cnt_00) {
        *param_1 = local_40._1_1_;
        param_1 = param_1 + 1;
      }
      if (iVar13 < iVar9) {
        iVar12 = iVar13 + 1;
      }
      if (iVar9 <= iVar13) {
        iVar12 = 1;
        iVar13 = 0;
      }
      state[iVar11] = (byte)local_48 ^ state[iVar11];
      if (8 < (int)cnt_00) {
        *param_1 = local_40._2_1_;
        param_1 = param_1 + 1;
      }
      if (iVar9 <= iVar12) {
        iVar12 = 0;
      }
      state[iVar13] = local_48._1_1_ ^ state[iVar13];
      if (cnt_00 == 10) {
        *param_1 = local_40._3_1_;
        param_1 = param_1 + 1;
      }
    } while (0 < (int)param_2);
    pEVar6 = EVP_sha1();
    EVP_DigestInit_ex(&EStack_80,pEVar6,(ENGINE *)0x0);
    EVP_DigestUpdate(&EStack_80,local_68,8);
    EVP_DigestUpdate(&EStack_80,local_b0,0x14);
    if (param_4 == 0) {
      EVP_DigestUpdate(&EStack_80,PTR_md_0010aed8,0x14);
      EVP_DigestFinal_ex(&EStack_80,PTR_md_0010aed8,(uint *)0x0);
    }
    else {
      CRYPTO_lock(9,0x12,"md_rand.c",0x203);
      EVP_DigestUpdate(&EStack_80,PTR_md_0010aed8,0x14);
      EVP_DigestFinal_ex(&EStack_80,PTR_md_0010aed8,(uint *)0x0);
      CRYPTO_lock(10,0x12,"md_rand.c",0x207);
    }
    EVP_MD_CTX_cleanup(&EStack_80);
    if (uVar7 == 0) {
      if (param_3 == 0) {
        ERR_put_error(0x24,100,100,"md_rand.c",0x20f);
        ERR_add_error_data(1,
                           "You need to read the OpenSSL FAQ, http://www.openssl.org/support/faq.html"
                          );
        uVar7 = param_3;
      }
      if (local_3c == __stack_chk_guard) {
        return;
      }
      goto LAB_0010abe6;
    }
  }
  uVar7 = 1;
  if (local_3c == __stack_chk_guard) {
    return;
  }
LAB_0010abe6:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar7);
}

