
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
  undefined *puVar5;
  int in_GS_OFFSET;
  BIGNUM *local_13d0;
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
    a = (BIGNUM *)0x0;
    local_13d0 = (BIGNUM *)0x0;
    puVar5 = (undefined *)0x0;
LAB_0819c041:
    if (param_5 == 0) goto LAB_0819c05c;
  }
  else {
    if (param_5 == 0) {
      puVar3 = (undefined4 *)SRP_get_default_gN(param_6);
      if (puVar3 == (undefined4 *)0x0) {
        puVar5 = (undefined *)0x0;
        goto LAB_0819c05c;
      }
      local_13d0 = (BIGNUM *)puVar3[2];
      a = (BIGNUM *)puVar3[1];
      puVar5 = (undefined *)*puVar3;
LAB_0819bf59:
      if (*param_3 == (void *)0x0) {
        RAND_pseudo_bytes(local_9e4,0x14);
        local_13b0 = BN_bin2bn(local_9e4,0x14,(BIGNUM *)0x0);
LAB_0819bf95:
        iVar1 = SRP_create_verifier_BN(param_1,param_2,&local_13b0,&local_13ac,local_13d0,a);
        if (iVar1 != 0) {
          BN_bn2bin(local_13ac,local_13a8);
          iVar2 = BN_num_bits(local_13ac);
          iVar1 = iVar2 + 7;
          if (iVar2 + 7 < 0) {
            iVar1 = iVar2 + 0xe;
          }
          ptr = CRYPTO_malloc((iVar1 >> 3) * 2,"srp_vfy.c",0x240);
          if (ptr != (void *)0x0) {
            BN_num_bits(local_13ac);
            t_tob64();
            *param_4 = ptr;
            if (*param_3 == (void *)0x0) {
              pvVar4 = CRYPTO_malloc(0x28,"srp_vfy.c",0x249);
              if (pvVar4 == (void *)0x0) {
                puVar5 = (undefined *)0x0;
                CRYPTO_free(ptr);
              }
              else {
                t_tob64();
                *param_3 = pvVar4;
              }
            }
            goto LAB_0819c041;
          }
        }
      }
      else {
        iVar1 = t_fromb64();
        if (iVar1 != 0) {
          local_13b0 = BN_bin2bn(local_9e4,iVar1,(BIGNUM *)0x0);
          goto LAB_0819bf95;
        }
      }
      puVar5 = (undefined *)0x0;
      goto LAB_0819c041;
    }
    iVar1 = t_fromb64();
    if (iVar1 == 0) {
      local_13d0 = (BIGNUM *)0x0;
    }
    else {
      local_13d0 = BN_bin2bn(local_13a8,iVar1,(BIGNUM *)0x0);
      iVar1 = t_fromb64();
      if (iVar1 != 0) {
        puVar5 = &DAT_08234410;
        a = BN_bin2bn(local_13a8,iVar1,(BIGNUM *)0x0);
        goto LAB_0819bf59;
      }
    }
    a = (BIGNUM *)0x0;
    puVar5 = (undefined *)0x0;
  }
  BN_free(local_13d0);
  BN_free(a);
LAB_0819c05c:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return puVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

