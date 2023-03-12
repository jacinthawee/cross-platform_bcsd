
/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __regparm3 ssleay_rand_bytes(undefined *param_1,size_t param_2,int param_3)

{
  byte bVar1;
  double dVar2;
  size_t sVar3;
  EVP_MD *pEVar4;
  uint uVar5;
  size_t cnt;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  undefined *puVar11;
  undefined *puVar12;
  int in_GS_OFFSET;
  uint local_a4;
  int *local_a0;
  int *local_9c;
  size_t local_98;
  int local_8c;
  __pid_t local_70;
  EVP_MD_CTX local_6c;
  EVP_MD_CTX local_54;
  int local_3c;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20 [4];
  
  local_20[0] = *(int *)(in_GS_OFFSET + 0x14);
  local_70 = getpid();
  if (0 < (int)param_2) {
    EVP_MD_CTX_init(&local_6c);
    iVar7 = (((int)(param_2 - 1) / 10) * 5 + 5) * 2;
    iVar9 = iVar7;
    CRYPTO_lock(iVar7,9,(char *)0x12,(int)"md_rand.c");
    CRYPTO_lock(iVar9,9,(char *)0x13,(int)"md_rand.c");
    CRYPTO_THREADID_current((CRYPTO_THREADID *)&locking_threadid);
    CRYPTO_lock(iVar9,10,(char *)0x13,(int)"md_rand.c");
    crypto_lock_rand = 1;
    if (initialized == 0) {
      RAND_poll();
      initialized = 1;
    }
    dVar2 = entropy;
    if ((entropy < (double)_DAT_0823ab48) && (entropy = entropy - (double)param_2, entropy < 0.0)) {
      entropy = 0.0;
    }
    if (stirred_pool_8615 == 0) {
      local_8c = 0x34;
      do {
        uVar5 = crypto_lock_rand;
        if (crypto_lock_rand == 0) {
LAB_081c8f6d:
          CRYPTO_lock(uVar5,9,(char *)0x12,(int)"md_rand.c");
          local_a4 = 0;
        }
        else {
          CRYPTO_THREADID_current((CRYPTO_THREADID *)&local_54);
          CRYPTO_lock(uVar5,5,(char *)0x13,(int)"md_rand.c");
          iVar9 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&locking_threadid,
                                      (CRYPTO_THREADID *)&local_54);
          local_a4 = (uint)(iVar9 == 0);
          uVar5 = local_a4;
          CRYPTO_lock(local_a4,6,(char *)0x13,(int)"md_rand.c");
          if (iVar9 != 0) goto LAB_081c8f6d;
        }
        iVar9 = state_index;
        local_3c = (int)md_count;
        state_index = state_index + 0x14;
        local_38 = md_count._4_4_;
        local_34 = md._0_4_;
        local_30 = md._4_4_;
        local_2c = md._8_4_;
        local_28 = md._12_4_;
        local_24 = md._16_4_;
        if (state_index < 0x3ff) {
          if ((state_num < state_index) && (state_num < 0x3ff)) {
            state_num = state_index;
          }
        }
        else {
          state_num = 0x3ff;
          state_index = state_index % 0x3ff;
        }
        md_count._4_4_ = md_count._4_4_ + 1;
        if (local_a4 == 0) {
          CRYPTO_lock(0,10,(char *)0x12,(int)"md_rand.c");
        }
        local_a0 = &local_34;
        sVar3 = iVar9 - 0x3eb;
        EVP_MD_CTX_init(&local_54);
        pEVar4 = EVP_sha1();
        EVP_DigestInit_ex(&local_54,pEVar4,(ENGINE *)0x0);
        EVP_DigestUpdate(&local_54,local_a0,0x14);
        if ((int)sVar3 < 1) {
          EVP_DigestUpdate(&local_54,state + iVar9,0x14);
        }
        else {
          EVP_DigestUpdate(&local_54,state + iVar9,0x14 - sVar3);
          EVP_DigestUpdate(&local_54,state,sVar3);
        }
        local_9c = &local_3c;
        local_a0 = &local_34;
        EVP_DigestUpdate(&local_54,"....................",0x14);
        EVP_DigestUpdate(&local_54,local_9c,8);
        EVP_DigestFinal_ex(&local_54,(uchar *)local_a0,(uint *)0x0);
        local_38 = local_38 + 1;
        do {
          iVar6 = iVar9 + 1;
          bVar1 = *(byte *)local_a0;
          if (0x3fe < iVar6) {
            iVar6 = 0;
          }
          local_a0 = (int *)((int)local_a0 + 1);
          state[iVar9] = state[iVar9] ^ bVar1;
          iVar9 = iVar6;
        } while (local_20 != local_a0);
        iVar9 = EVP_MD_CTX_cleanup(&local_54);
        if (local_a4 == 0) {
          CRYPTO_lock(iVar9,9,(char *)0x12,(int)"md_rand.c");
        }
        md._0_4_ = md._0_4_ ^ local_34;
        md._4_4_ = md._4_4_ ^ local_30;
        md._8_4_ = md._8_4_ ^ local_2c;
        md._12_4_ = md._12_4_ ^ local_28;
        md._16_4_ = md._16_4_ ^ local_24;
        if (entropy < (double)_DAT_0823ab48) {
          entropy = entropy + (double)_DAT_081f7380;
        }
        if (local_a4 == 0) {
          CRYPTO_lock(md._16_4_,10,(char *)0x12,(int)"md_rand.c");
        }
        local_8c = local_8c + -1;
      } while (local_8c != 0);
      if (_DAT_0823ab48 <= (float)dVar2) {
        stirred_pool_8615 = 1;
      }
    }
    iVar6 = state_num;
    iVar9 = state_index;
    local_9c = &local_3c;
    local_a0 = &local_34;
    iVar7 = iVar7 + state_index;
    local_3c = (int)md_count;
    local_38 = md_count._4_4_;
    local_34 = md._0_4_;
    local_30 = md._4_4_;
    local_2c = md._8_4_;
    local_28 = md._12_4_;
    local_24 = md._16_4_;
    state_index = iVar7;
    if (state_num < iVar7) {
      state_index = iVar7 % state_num;
      iVar7 = iVar7 / state_num;
    }
    md_count._0_4_ = (int)md_count + 1;
    crypto_lock_rand = 0;
    CRYPTO_lock(iVar7,10,(char *)0x12,(int)"md_rand.c");
    local_98 = param_2;
    do {
      sVar3 = local_98;
      if (10 < (int)local_98) {
        sVar3 = 10;
      }
      local_98 = local_98 - sVar3;
      pEVar4 = EVP_sha1();
      EVP_DigestInit_ex(&local_6c,pEVar4,(ENGINE *)0x0);
      if (local_70 != 0) {
        EVP_DigestUpdate(&local_6c,&local_70,4);
        local_70 = 0;
      }
      EVP_DigestUpdate(&local_6c,local_a0,0x14);
      EVP_DigestUpdate(&local_6c,local_9c,8);
      EVP_DigestUpdate(&local_6c,param_1,sVar3);
      cnt = (iVar9 + 10) - iVar6;
      if ((int)cnt < 1) {
        EVP_DigestUpdate(&local_6c,state + iVar9,10);
      }
      else {
        EVP_DigestUpdate(&local_6c,state + iVar9,10 - cnt);
        EVP_DigestUpdate(&local_6c,state,cnt);
      }
      EVP_DigestFinal_ex(&local_6c,(uchar *)local_a0,(uint *)0x0);
      iVar7 = iVar9 + 1;
      iVar8 = iVar9 + 2;
      state[iVar9] = state[iVar9] ^ (byte)local_34;
      if (iVar6 <= iVar7) {
        iVar8 = 1;
        iVar7 = 0;
      }
      *param_1 = local_2c._2_1_;
      state[iVar7] = state[iVar7] ^ local_34._1_1_;
      iVar7 = iVar8 + 1;
      if (iVar6 <= iVar8) {
        iVar7 = 1;
        iVar8 = 0;
      }
      if (sVar3 == 1) {
        puVar11 = param_1 + 1;
        state[iVar8] = state[iVar8] ^ local_34._2_1_;
        if (iVar7 < iVar6) {
LAB_081c8e00:
          iVar9 = iVar7 + 1;
          goto LAB_081c8afe;
        }
        iVar9 = 1;
        state[0] = state[0] ^ local_34._3_1_;
        if (1 < iVar6) goto LAB_081c8df8;
        iVar7 = 1;
        iVar9 = 0;
        puVar12 = puVar11;
      }
      else {
        puVar11 = param_1 + 2;
        param_1[1] = local_2c._3_1_;
        state[iVar8] = state[iVar8] ^ local_34._2_1_;
        if (iVar7 < iVar6) goto LAB_081c8e00;
        iVar9 = 1;
        iVar7 = 0;
LAB_081c8afe:
        if (2 < (int)sVar3) {
          *puVar11 = (undefined)local_28;
          puVar11 = puVar11 + 1;
        }
        state[iVar7] = state[iVar7] ^ local_34._3_1_;
        if (iVar9 < iVar6) {
LAB_081c8df8:
          iVar7 = iVar9 + 1;
        }
        else {
          iVar7 = 1;
          iVar9 = 0;
        }
        puVar12 = puVar11;
        if (3 < (int)sVar3) {
          puVar12 = puVar11 + 1;
          *puVar11 = local_28._1_1_;
        }
      }
      state[iVar9] = state[iVar9] ^ (byte)local_30;
      iVar9 = iVar7 + 1;
      if (iVar6 <= iVar7) {
        iVar9 = 1;
        iVar7 = 0;
      }
      puVar11 = puVar12;
      if (4 < (int)sVar3) {
        puVar11 = puVar12 + 1;
        *puVar12 = local_28._2_1_;
      }
      state[iVar7] = state[iVar7] ^ local_30._1_1_;
      iVar7 = iVar9 + 1;
      if (iVar6 <= iVar9) {
        iVar7 = 1;
        iVar9 = 0;
      }
      puVar12 = puVar11;
      if (5 < (int)sVar3) {
        puVar12 = puVar11 + 1;
        *puVar11 = local_28._3_1_;
      }
      state[iVar9] = state[iVar9] ^ local_30._2_1_;
      iVar9 = iVar7 + 1;
      if (iVar6 <= iVar7) {
        iVar9 = 1;
        iVar7 = 0;
      }
      puVar11 = puVar12;
      if (6 < (int)sVar3) {
        puVar11 = puVar12 + 1;
        *puVar12 = (undefined)local_24;
      }
      state[iVar7] = state[iVar7] ^ local_30._3_1_;
      iVar7 = iVar9 + 1;
      if (iVar6 <= iVar9) {
        iVar7 = 1;
        iVar9 = 0;
      }
      puVar12 = puVar11;
      if (7 < (int)sVar3) {
        puVar12 = puVar11 + 1;
        *puVar11 = local_24._1_1_;
      }
      state[iVar9] = state[iVar9] ^ (byte)local_2c;
      iVar9 = iVar7 + 1;
      if (iVar6 <= iVar7) {
        iVar9 = 1;
        iVar7 = 0;
      }
      puVar11 = puVar12;
      if (8 < (int)sVar3) {
        puVar11 = puVar12 + 1;
        *puVar12 = local_24._2_1_;
      }
      state[iVar7] = state[iVar7] ^ local_2c._1_1_;
      if (iVar6 <= iVar9) {
        iVar9 = 0;
      }
      param_1 = puVar11;
      if (sVar3 == 10) {
        param_1 = puVar11 + 1;
        *puVar11 = local_24._3_1_;
      }
    } while (0 < (int)local_98);
    pEVar4 = EVP_sha1();
    EVP_DigestInit_ex(&local_6c,pEVar4,(ENGINE *)0x0);
    EVP_DigestUpdate(&local_6c,local_9c,8);
    iVar7 = EVP_DigestUpdate(&local_6c,local_a0,0x14);
    CRYPTO_lock(iVar7,9,(char *)0x12,(int)"md_rand.c");
    EVP_DigestUpdate(&local_6c,md,0x14);
    iVar7 = EVP_DigestFinal_ex(&local_6c,md,(uint *)0x0);
    CRYPTO_lock(iVar7,10,(char *)0x12,(int)"md_rand.c");
    EVP_MD_CTX_cleanup(&local_6c);
    if ((float)dVar2 < _DAT_0823ab48) {
      uVar10 = 0;
      if (param_3 == 0) {
        ERR_put_error(0x24,100,100,"md_rand.c",0x21b);
        ERR_add_error_data(1,
                           "You need to read the OpenSSL FAQ, http://www.openssl.org/support/faq.html"
                          );
      }
      goto LAB_081c8f01;
    }
  }
  uVar10 = 1;
LAB_081c8f01:
  if (local_20[0] != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10;
}

