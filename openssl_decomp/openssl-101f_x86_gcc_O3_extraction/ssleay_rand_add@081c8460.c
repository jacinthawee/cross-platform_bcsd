
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ssleay_rand_add(void *param_1,int param_2,double param_3)

{
  size_t cnt;
  byte bVar1;
  EVP_MD *type;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  size_t cnt_00;
  uint *puVar6;
  int in_GS_OFFSET;
  int local_74;
  void *local_70;
  uint local_68;
  EVP_MD_CTX local_54;
  undefined4 local_3c;
  int local_38;
  uint local_34 [4];
  uint local_24;
  int local_20;
  
  local_70 = param_1;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar3 = crypto_lock_rand;
  if (crypto_lock_rand == 0) {
LAB_081c849a:
    CRYPTO_lock(uVar3,9,(char *)0x12,(int)"md_rand.c");
    local_68 = 0;
  }
  else {
    CRYPTO_THREADID_current((CRYPTO_THREADID *)&local_54);
    CRYPTO_lock(uVar3,5,(char *)0x13,(int)"md_rand.c");
    iVar4 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&locking_threadid,(CRYPTO_THREADID *)&local_54);
    local_68 = (uint)(iVar4 == 0);
    uVar3 = local_68;
    CRYPTO_lock(local_68,6,(char *)0x13,(int)"md_rand.c");
    if (iVar4 != 0) goto LAB_081c849a;
  }
  iVar4 = state_index;
  local_3c = (undefined4)md_count;
  state_index = param_2 + state_index;
  local_38 = md_count._4_4_;
  local_34[0] = md._0_4_;
  local_34[1] = md._4_4_;
  local_34[2] = md._8_4_;
  local_34[3] = md._12_4_;
  local_24 = md._16_4_;
  if (state_index < 0x3ff) {
    if ((state_num < 0x3ff) && (state_num < state_index)) {
      state_num = state_index;
    }
  }
  else {
    state_num = 0x3ff;
    state_index = state_index % 0x3ff;
  }
  md_count._4_4_ =
       param_2 / 0x14 + (uint)(param_2 != (param_2 / 0x14) * 0x14 && -1 < param_2 % 0x14) +
       md_count._4_4_;
  if (local_68 == 0) {
    CRYPTO_lock(md_count._4_4_,10,(char *)0x12,(int)"md_rand.c");
    EVP_MD_CTX_init(&local_54);
    if (0 < param_2) goto LAB_081c85ae;
    iVar4 = EVP_MD_CTX_cleanup(&local_54);
  }
  else {
    EVP_MD_CTX_init(&local_54);
    if (param_2 < 1) {
      EVP_MD_CTX_cleanup(&local_54);
      goto LAB_081c86d2;
    }
LAB_081c85ae:
    local_74 = 0;
    do {
      cnt_00 = param_2 - local_74;
      if (0x14 < (int)cnt_00) {
        cnt_00 = 0x14;
      }
      type = EVP_sha1();
      EVP_DigestInit_ex(&local_54,type,(ENGINE *)0x0);
      EVP_DigestUpdate(&local_54,local_34,0x14);
      cnt = iVar4 + -0x3ff + cnt_00;
      if ((int)cnt < 1) {
        EVP_DigestUpdate(&local_54,state + iVar4,cnt_00);
      }
      else {
        EVP_DigestUpdate(&local_54,state + iVar4,cnt_00 - cnt);
        EVP_DigestUpdate(&local_54,state,cnt);
      }
      EVP_DigestUpdate(&local_54,local_70,cnt_00);
      EVP_DigestUpdate(&local_54,&local_3c,8);
      EVP_DigestFinal_ex(&local_54,(uchar *)local_34,(uint *)0x0);
      local_38 = local_38 + 1;
      local_70 = (void *)((int)local_70 + cnt_00);
      if (0 < (int)cnt_00) {
        puVar2 = local_34;
        puVar6 = (uint *)(cnt_00 + (int)puVar2);
        iVar5 = iVar4;
        do {
          iVar4 = iVar5 + 1;
          bVar1 = *(byte *)puVar2;
          if (0x3fe < iVar4) {
            iVar4 = 0;
          }
          puVar2 = (uint *)((int)puVar2 + 1);
          state[iVar5] = state[iVar5] ^ bVar1;
          iVar5 = iVar4;
        } while (puVar2 != puVar6);
      }
      local_74 = local_74 + 0x14;
    } while (local_74 < param_2);
    iVar4 = EVP_MD_CTX_cleanup(&local_54);
    if (local_68 != 0) goto LAB_081c86d2;
  }
  CRYPTO_lock(iVar4,9,(char *)0x12,(int)"md_rand.c");
LAB_081c86d2:
  md._0_4_ = md._0_4_ ^ local_34[0];
  md._4_4_ = md._4_4_ ^ local_34[1];
  md._8_4_ = md._8_4_ ^ local_34[2];
  md._12_4_ = md._12_4_ ^ local_34[3];
  md._16_4_ = md._16_4_ ^ local_24;
  if (entropy < (double)_DAT_0823ab48) {
    entropy = entropy + param_3;
  }
  if (local_68 == 0) {
    CRYPTO_lock(md._16_4_,10,(char *)0x12,(int)"md_rand.c");
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

