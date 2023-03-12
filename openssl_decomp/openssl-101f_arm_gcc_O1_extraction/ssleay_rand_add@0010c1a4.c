
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void ssleay_rand_add(void *param_1,int param_2)

{
  bool bVar1;
  EVP_MD *type;
  int iVar2;
  size_t cnt;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  size_t cnt_00;
  double in_d0;
  undefined4 local_68;
  int local_64;
  undefined auStack_60 [23];
  byte bStack_49;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  int local_34;
  
  local_34 = __TMC_END__;
  if (crypto_lock_rand != 0) {
    CRYPTO_THREADID_current((CRYPTO_THREADID *)(EVP_MD_CTX *)auStack_60);
    CRYPTO_lock(5,0x13,"md_rand.c",0xdd);
    iVar5 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&locking_threadid,
                                (CRYPTO_THREADID *)(EVP_MD_CTX *)auStack_60);
    CRYPTO_lock(6,0x13,"md_rand.c",0xdf);
    if (iVar5 == 0) {
      bVar1 = true;
      goto LAB_0010c1ec;
    }
  }
  bVar1 = false;
  CRYPTO_lock(9,0x12,"md_rand.c",0xe4);
LAB_0010c1ec:
  iVar5 = state_index;
  state_index = state_index + param_2;
  local_48 = md._0_4_;
  local_44 = md._4_4_;
  local_40 = md._8_4_;
  local_3c = md._12_4_;
  local_68 = (undefined4)md_count;
  local_38 = md._16_4_;
  local_64 = md_count._4_4_;
  if (state_index < 0x3ff) {
    if ((state_num < 0x3ff) && (state_num < state_index)) {
      state_num = state_index;
    }
  }
  else {
    state_num = 0x3ff;
    state_index = state_index % 0x3ff;
  }
  iVar2 = param_2 / 0x14;
  if (0 < param_2 % 0x14) {
    iVar2 = iVar2 + 1;
  }
  md_count._4_4_ = md_count._4_4_ + iVar2;
  if (!bVar1) {
    CRYPTO_lock(10,0x12,"md_rand.c",0x104);
  }
  EVP_MD_CTX_init((EVP_MD_CTX *)auStack_60);
  if (0 < param_2) {
    iVar2 = 0;
    do {
      type = EVP_sha1();
      cnt_00 = param_2 - iVar2;
      EVP_DigestInit_ex((EVP_MD_CTX *)auStack_60,type,(ENGINE *)0x0);
      if (0x13 < (int)cnt_00) {
        cnt_00 = 0x14;
      }
      EVP_DigestUpdate((EVP_MD_CTX *)auStack_60,&local_48,0x14);
      cnt = (iVar5 + cnt_00) - 0x3ff;
      if ((int)cnt < 1) {
        EVP_DigestUpdate((EVP_MD_CTX *)auStack_60,PTR_state_0010c460 + iVar5,cnt_00);
      }
      else {
        EVP_DigestUpdate((EVP_MD_CTX *)auStack_60,PTR_state_0010c460 + iVar5,cnt_00 - cnt);
        EVP_DigestUpdate((EVP_MD_CTX *)auStack_60,PTR_state_0010c460,cnt);
      }
      EVP_DigestUpdate((EVP_MD_CTX *)auStack_60,param_1,cnt_00);
      EVP_DigestUpdate((EVP_MD_CTX *)auStack_60,&local_68,8);
      EVP_DigestFinal_ex((EVP_MD_CTX *)auStack_60,(uchar *)&local_48,(uint *)0x0);
      local_64 = local_64 + 1;
      if (0 < (int)cnt_00) {
        pbVar3 = &bStack_49;
        iVar4 = iVar5;
        do {
          pbVar3 = pbVar3 + 1;
          iVar5 = iVar4 + 1;
          if (0x3fe < iVar5) {
            iVar5 = 0;
          }
          state[iVar4] = *pbVar3 ^ state[iVar4];
          iVar4 = iVar5;
        } while (pbVar3 != &bStack_49 + cnt_00);
      }
      iVar2 = iVar2 + 0x14;
      param_1 = (void *)((int)param_1 + cnt_00);
    } while (iVar2 < param_2);
  }
  EVP_MD_CTX_cleanup((EVP_MD_CTX *)auStack_60);
  if (!bVar1) {
    CRYPTO_lock(9,0x12,"md_rand.c",0x137);
  }
  md._0_4_ = local_48 ^ md._0_4_;
  md._4_4_ = local_44 ^ md._4_4_;
  md._8_4_ = local_40 ^ md._8_4_;
  md._12_4_ = local_3c ^ md._12_4_;
  md._16_4_ = local_38 ^ md._16_4_;
  if ((int)((uint)(entropy < DAT_0010c458) << 0x1f) < 0) {
    entropy = entropy + in_d0;
  }
  if (!bVar1) {
    CRYPTO_lock(10,0x12,"md_rand.c",0x142);
  }
  if (local_34 == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

