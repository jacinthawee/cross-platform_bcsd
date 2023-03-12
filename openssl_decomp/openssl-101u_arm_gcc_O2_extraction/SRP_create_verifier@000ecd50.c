
void SRP_create_verifier(int param_1,int param_2,BIGNUM **param_3,BIGNUM **param_4,int param_5,
                        ulong *param_6)

{
  bool bVar1;
  ulong *puVar2;
  int iVar3;
  BIGNUM *a;
  int iVar4;
  BIGNUM *pBVar5;
  BIGNUM *ptr;
  BIGNUM *len;
  BIGNUM *pBVar6;
  bool bVar7;
  BIGNUM *local_13c8;
  uchar *local_13c4;
  BIGNUM *local_13bc;
  BIGNUM *local_13b8;
  uchar auStack_13b4 [2500];
  uchar auStack_9f0 [2500];
  int local_2c;
  
  puVar2 = param_6;
  bVar7 = param_2 == 0;
  bVar1 = param_1 == 0;
  local_2c = __stack_chk_guard;
  ptr = (BIGNUM *)&param_6;
  if (bVar7 || bVar1) {
    ptr = (BIGNUM *)0x1;
  }
  local_13bc = (BIGNUM *)0x0;
  if (!bVar7 && !bVar1) {
    ptr = (BIGNUM *)0x0;
  }
  local_13b8 = (BIGNUM *)0x0;
  if (bVar7 || bVar1) {
    local_13c8 = (BIGNUM *)0x0;
    ptr = (BIGNUM *)0x0;
    len = (BIGNUM *)0x0;
    pBVar5 = (BIGNUM *)0x0;
    a = (BIGNUM *)0x0;
LAB_000ece8e:
    if (param_5 == 0) goto LAB_000ecea0;
  }
  else {
    len = ptr;
    pBVar5 = ptr;
    a = ptr;
    local_13c8 = ptr;
    if (param_4 == (BIGNUM **)0x0 || param_3 == (BIGNUM **)0x0) goto LAB_000ece8e;
    if (param_5 == 0) {
      ptr = (BIGNUM *)SRP_get_default_gN(param_6);
      len = ptr;
      pBVar5 = ptr;
      if (ptr == (BIGNUM *)0x0) goto LAB_000ecea0;
      local_13c8 = (BIGNUM *)ptr->dmax;
      pBVar6 = (BIGNUM *)ptr->d;
      a = (BIGNUM *)ptr->top;
LAB_000ecdf8:
      ptr = *param_3;
      if (ptr == (BIGNUM *)0x0) {
        iVar3 = RAND_bytes(auStack_9f0,0x14);
        len = ptr;
        pBVar5 = ptr;
        if (0 < iVar3) {
          local_13bc = BN_bin2bn(auStack_9f0,0x14,(BIGNUM *)0x0);
          goto LAB_000ece1e;
        }
      }
      else {
        ptr = (BIGNUM *)t_fromb64(auStack_9f0,ptr);
        len = ptr;
        pBVar5 = ptr;
        if (ptr != (BIGNUM *)0x0) {
          local_13bc = BN_bin2bn(auStack_9f0,(int)ptr,(BIGNUM *)0x0);
LAB_000ece1e:
          local_13c4 = auStack_9f0;
          ptr = (BIGNUM *)
                SRP_create_verifier_BN(param_1,param_2,&local_13bc,&local_13b8,local_13c8,a);
          len = ptr;
          pBVar5 = ptr;
          if (ptr != (BIGNUM *)0x0) {
            BN_bn2bin(local_13b8,auStack_13b4);
            iVar4 = BN_num_bits(local_13b8);
            iVar3 = iVar4 + 0xe;
            if (-1 < iVar4 + 7) {
              iVar3 = iVar4 + 7;
            }
            len = (BIGNUM *)((iVar3 >> 3) << 1);
            ptr = (BIGNUM *)CRYPTO_malloc((int)len,"srp_vfy.c",0x267);
            pBVar5 = ptr;
            if (ptr != (BIGNUM *)0x0) {
              iVar4 = BN_num_bits(local_13b8);
              iVar3 = iVar4 + 0xe;
              if (-1 < iVar4 + 7) {
                iVar3 = iVar4 + 7;
              }
              t_tob64(ptr,auStack_13b4,iVar3 >> 3);
              if (*param_3 == (BIGNUM *)0x0) {
                pBVar5 = (BIGNUM *)CRYPTO_malloc(0x28,"srp_vfy.c",0x26e);
                if (pBVar5 == (BIGNUM *)0x0) goto LAB_000ece8e;
                t_tob64(pBVar5,local_13c4,0x14);
                *param_3 = pBVar5;
              }
              *param_4 = ptr;
              ptr = (BIGNUM *)0x0;
              pBVar5 = pBVar6;
            }
          }
        }
      }
      goto LAB_000ece8e;
    }
    local_13c8 = (BIGNUM *)t_fromb64(auStack_13b4,param_5);
    if (local_13c8 != (BIGNUM *)0x0) {
      local_13c8 = BN_bin2bn(auStack_13b4,(int)local_13c8,(BIGNUM *)0x0);
      iVar3 = t_fromb64(auStack_13b4,puVar2);
      if (iVar3 != 0) {
        a = BN_bin2bn(auStack_13b4,iVar3,(BIGNUM *)0x0);
        pBVar6 = (BIGNUM *)&DAT_0016e2a8;
        goto LAB_000ecdf8;
      }
    }
    ptr = (BIGNUM *)0x0;
    len = ptr;
    pBVar5 = ptr;
    a = ptr;
  }
  BN_free(local_13c8);
  BN_free(a);
LAB_000ecea0:
  OPENSSL_cleanse(ptr,(size_t)len);
  CRYPTO_free(ptr);
  BN_clear_free(local_13bc);
  BN_clear_free(local_13b8);
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(pBVar5);
  }
  return;
}

