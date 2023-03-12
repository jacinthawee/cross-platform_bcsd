
void SRP_create_verifier(int param_1,int param_2,BIGNUM **param_3,BIGNUM **param_4,int param_5,
                        ulong *param_6)

{
  bool bVar1;
  ulong *puVar2;
  int iVar3;
  BIGNUM *len;
  int iVar4;
  BIGNUM *ptr;
  BIGNUM *a;
  BIGNUM *pBVar5;
  bool bVar6;
  BIGNUM *local_13c8;
  uchar *local_13c4;
  BIGNUM *local_13bc;
  BIGNUM *local_13b8;
  uchar auStack_13b4 [2500];
  uchar auStack_9f0 [2500];
  int local_2c;
  
  puVar2 = param_6;
  bVar6 = param_2 == 0;
  bVar1 = param_1 == 0;
  local_2c = __TMC_END__;
  a = (BIGNUM *)&param_6;
  if (bVar6 || bVar1) {
    a = (BIGNUM *)0x1;
  }
  local_13bc = (BIGNUM *)0x0;
  if (!bVar6 && !bVar1) {
    a = (BIGNUM *)0x0;
  }
  local_13b8 = (BIGNUM *)0x0;
  if (bVar6 || bVar1) {
    a = (BIGNUM *)0x0;
    local_13c8 = (BIGNUM *)0x0;
    len = (BIGNUM *)0x0;
LAB_000eed12:
    if (param_5 == 0) goto LAB_000eed24;
  }
  else {
    len = a;
    local_13c8 = a;
    if (param_4 == (BIGNUM **)0x0 || param_3 == (BIGNUM **)0x0) goto LAB_000eed12;
    if (param_5 == 0) {
      len = (BIGNUM *)SRP_get_default_gN(param_6);
      if (len == (BIGNUM *)0x0) goto LAB_000eed24;
      local_13c8 = (BIGNUM *)len->dmax;
      pBVar5 = (BIGNUM *)len->d;
      a = (BIGNUM *)len->top;
LAB_000eec82:
      if (*param_3 == (BIGNUM *)0x0) {
        RAND_pseudo_bytes(auStack_9f0,0x14);
        local_13bc = BN_bin2bn(auStack_9f0,0x14,(BIGNUM *)0x0);
      }
      else {
        len = (BIGNUM *)t_fromb64(auStack_9f0,*param_3);
        if (len == (BIGNUM *)0x0) goto LAB_000eed12;
        local_13bc = BN_bin2bn(auStack_9f0,(int)len,(BIGNUM *)0x0);
      }
      local_13c4 = auStack_9f0;
      len = (BIGNUM *)SRP_create_verifier_BN(param_1,param_2,&local_13bc,&local_13b8,local_13c8,a);
      if (len != (BIGNUM *)0x0) {
        BN_bn2bin(local_13b8,auStack_13b4);
        iVar4 = BN_num_bits(local_13b8);
        iVar3 = iVar4 + 7;
        if (iVar4 + 7 < 0) {
          iVar3 = iVar4 + 0xe;
        }
        ptr = (BIGNUM *)CRYPTO_malloc((iVar3 >> 3) << 1,"srp_vfy.c",0x240);
        len = ptr;
        if (ptr != (BIGNUM *)0x0) {
          iVar4 = BN_num_bits(local_13b8);
          iVar3 = iVar4 + 0xe;
          if (-1 < iVar4 + 7) {
            iVar3 = iVar4 + 7;
          }
          t_tob64(ptr,auStack_13b4,iVar3 >> 3);
          *param_4 = ptr;
          len = pBVar5;
          if (*param_3 == (BIGNUM *)0x0) {
            len = (BIGNUM *)CRYPTO_malloc(0x28,"srp_vfy.c",0x249);
            if (len == (BIGNUM *)0x0) {
              CRYPTO_free(ptr);
            }
            else {
              t_tob64(len,local_13c4,0x14);
              *param_3 = len;
              len = pBVar5;
            }
          }
        }
      }
      goto LAB_000eed12;
    }
    local_13c8 = (BIGNUM *)t_fromb64(auStack_13b4,param_5);
    if (local_13c8 != (BIGNUM *)0x0) {
      local_13c8 = BN_bin2bn(auStack_13b4,(int)local_13c8,(BIGNUM *)0x0);
      iVar3 = t_fromb64(auStack_13b4,puVar2);
      if (iVar3 != 0) {
        a = BN_bin2bn(auStack_13b4,iVar3,(BIGNUM *)0x0);
        pBVar5 = (BIGNUM *)&DAT_0016f59c;
        goto LAB_000eec82;
      }
    }
    a = (BIGNUM *)0x0;
    len = (BIGNUM *)0x0;
  }
  BN_free(local_13c8);
  BN_free(a);
LAB_000eed24:
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(len);
  }
  return;
}

