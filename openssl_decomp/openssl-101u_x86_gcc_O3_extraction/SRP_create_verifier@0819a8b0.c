
undefined *
SRP_create_verifier(int param_1,int param_2,void **param_3,void **param_4,int param_5,
                   undefined4 param_6)

{
  int iVar1;
  BIGNUM *a;
  int iVar2;
  void *ptr;
  undefined4 *puVar3;
  void *pvVar4;
  size_t len;
  int in_GS_OFFSET;
  BIGNUM *local_13d4;
  undefined *local_13d0;
  BIGNUM *local_13b0;
  BIGNUM *local_13ac;
  uchar local_13a8 [2500];
  uchar local_9e4 [2500];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_13b0 = (BIGNUM *)0x0;
  local_13ac = (BIGNUM *)0x0;
  if ((((param_1 == 0) || (param_2 == 0)) || (param_3 == (void **)0x0)) || (param_4 == (void **)0x0)
     ) {
    len = 0;
    a = (BIGNUM *)0x0;
    local_13d4 = (BIGNUM *)0x0;
    ptr = (void *)0x0;
    local_13d0 = (undefined *)0x0;
LAB_0819aa74:
    if (param_5 == 0) goto LAB_0819aa93;
  }
  else {
    if (param_5 == 0) {
      puVar3 = (undefined4 *)SRP_get_default_gN(param_6);
      if (puVar3 == (undefined4 *)0x0) {
        len = 0;
        ptr = (void *)0x0;
        local_13d0 = (undefined *)0x0;
        goto LAB_0819aa93;
      }
      local_13d4 = (BIGNUM *)puVar3[2];
      a = (BIGNUM *)puVar3[1];
      local_13d0 = (undefined *)*puVar3;
LAB_0819a98e:
      if (*param_3 == (void *)0x0) {
        iVar1 = RAND_bytes(local_9e4,0x14);
        if (0 < iVar1) {
          local_13b0 = BN_bin2bn(local_9e4,0x14,(BIGNUM *)0x0);
          goto LAB_0819a9c9;
        }
LAB_0819ab00:
        len = 0;
        ptr = (void *)0x0;
      }
      else {
        iVar1 = t_fromb64();
        if (iVar1 == 0) goto LAB_0819ab00;
        local_13b0 = BN_bin2bn(local_9e4,iVar1,(BIGNUM *)0x0);
LAB_0819a9c9:
        iVar1 = SRP_create_verifier_BN(param_1,param_2,&local_13b0,&local_13ac,local_13d4,a);
        if (iVar1 == 0) goto LAB_0819ab00;
        BN_bn2bin(local_13ac,local_13a8);
        iVar2 = BN_num_bits(local_13ac);
        iVar1 = iVar2 + 7;
        if (iVar2 + 7 < 0) {
          iVar1 = iVar2 + 0xe;
        }
        len = (iVar1 >> 3) * 2;
        ptr = CRYPTO_malloc(len,"srp_vfy.c",0x267);
        if (ptr != (void *)0x0) {
          BN_num_bits(local_13ac);
          t_tob64();
          if (*param_3 == (void *)0x0) {
            pvVar4 = CRYPTO_malloc(0x28,"srp_vfy.c",0x26e);
            if (pvVar4 == (void *)0x0) goto LAB_0819ab04;
            t_tob64();
            *param_3 = pvVar4;
          }
          *param_4 = ptr;
          ptr = (void *)0x0;
          goto LAB_0819aa74;
        }
      }
LAB_0819ab04:
      local_13d0 = (undefined *)0x0;
      goto LAB_0819aa74;
    }
    iVar1 = t_fromb64();
    if (iVar1 == 0) {
      local_13d4 = (BIGNUM *)0x0;
    }
    else {
      local_13d4 = BN_bin2bn(local_13a8,iVar1,(BIGNUM *)0x0);
      iVar1 = t_fromb64();
      if (iVar1 != 0) {
        a = BN_bin2bn(local_13a8,iVar1,(BIGNUM *)0x0);
        local_13d0 = &DAT_082348d0;
        goto LAB_0819a98e;
      }
    }
    len = 0;
    a = (BIGNUM *)0x0;
    ptr = (void *)0x0;
    local_13d0 = (undefined *)0x0;
  }
  BN_free(local_13d4);
  BN_free(a);
LAB_0819aa93:
  OPENSSL_cleanse(ptr,len);
  CRYPTO_free(ptr);
  BN_clear_free(local_13b0);
  BN_clear_free(local_13ac);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return local_13d0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

