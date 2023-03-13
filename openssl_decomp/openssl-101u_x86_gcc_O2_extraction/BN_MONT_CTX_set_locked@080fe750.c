
BN_MONT_CTX * BN_MONT_CTX_set_locked(BN_MONT_CTX **pmont,int lock,BIGNUM *mod,BN_CTX *ctx)

{
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *a_01;
  int iVar1;
  BN_MONT_CTX *ptr;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  uint uVar4;
  ulong uVar5;
  int in_GS_OFFSET;
  BIGNUM local_3c;
  ulong local_28;
  undefined4 local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = 0;
  CRYPTO_lock(0,5,(char *)lock,(int)"bn_mont.c");
  ptr = *pmont;
  CRYPTO_lock(iVar1,6,(char *)lock,(int)"bn_mont.c");
  if (ptr != (BN_MONT_CTX *)0x0) goto LAB_080fe7a6;
  ptr = (BN_MONT_CTX *)CRYPTO_malloc(0x4c,"bn_mont.c",0x155);
  if (ptr != (BN_MONT_CTX *)0x0) {
    ptr->ri = 0;
    a = &ptr->RR;
    BN_init(a);
    a_00 = &ptr->N;
    BN_init(a_00);
    a_01 = &ptr->Ni;
    BN_init(a_01);
    iVar1 = mod->top;
    ptr->n0[1] = 0;
    ptr->n0[0] = 0;
    ptr->flags = 1;
    if (iVar1 != 0) {
      BN_CTX_start(ctx);
      pBVar2 = BN_CTX_get(ctx);
      if ((pBVar2 != (BIGNUM *)0x0) && (pBVar3 = BN_copy(a_00,mod), pBVar3 != (BIGNUM *)0x0)) {
        (ptr->N).neg = 0;
        BN_init(&local_3c);
        local_3c.d = &local_28;
        local_3c.dmax = 2;
        local_3c.neg = 0;
        iVar1 = BN_num_bits(mod);
        uVar4 = iVar1 + 0x1fU;
        if ((int)(iVar1 + 0x1fU) < 0) {
          uVar4 = iVar1 + 0x3e;
        }
        ptr->ri = uVar4 & 0xffffffe0;
        BN_set_word(a,0);
        iVar1 = BN_set_bit(a,0x20);
        if (iVar1 != 0) {
          local_28 = *mod->d;
          local_24 = 0;
          local_3c.top = (int)(local_28 != 0);
          pBVar3 = BN_mod_inverse(pBVar2,a,&local_3c,ctx);
          if ((pBVar3 != (BIGNUM *)0x0) && (iVar1 = BN_lshift(pBVar2,pBVar2,0x20), iVar1 != 0)) {
            if (pBVar2->top == 0) {
              iVar1 = BN_set_word(pBVar2,0xffffffff);
            }
            else {
              iVar1 = BN_sub_word(pBVar2,1);
            }
            if ((iVar1 != 0) &&
               (iVar1 = BN_div(pBVar2,(BIGNUM *)0x0,pBVar2,&local_3c,ctx), iVar1 != 0)) {
              if (pBVar2->top < 1) {
                uVar5 = 0;
              }
              else {
                uVar5 = *pBVar2->d;
              }
              ptr->n0[0] = uVar5;
              ptr->n0[1] = 0;
              BN_set_word(a,0);
              iVar1 = BN_set_bit(a,ptr->ri * 2);
              if (iVar1 != 0) {
                pBVar3 = (BIGNUM *)BN_div((BIGNUM *)0x0,a,a,a_00,ctx);
                pBVar2 = pBVar3;
                BN_CTX_end(ctx);
                if (pBVar3 != (BIGNUM *)0x0) {
                  CRYPTO_lock((int)pBVar2,9,(char *)lock,(int)"bn_mont.c");
                  if (*pmont == (BN_MONT_CTX *)0x0) {
                    *pmont = ptr;
                  }
                  else {
                    pBVar2 = a;
                    BN_clear_free(a);
                    BN_clear_free(a_00);
                    BN_clear_free(a_01);
                    if ((*(byte *)&ptr->flags & 1) != 0) {
                      CRYPTO_free(ptr);
                    }
                    ptr = *pmont;
                  }
                  CRYPTO_lock((int)pBVar2,10,(char *)lock,(int)"bn_mont.c");
                  goto LAB_080fe7a6;
                }
                goto LAB_080fe830;
              }
            }
          }
        }
      }
      BN_CTX_end(ctx);
    }
LAB_080fe830:
    BN_clear_free(a);
    BN_clear_free(a_00);
    BN_clear_free(a_01);
    if ((*(byte *)&ptr->flags & 1) != 0) {
      CRYPTO_free(ptr);
      ptr = (BN_MONT_CTX *)0x0;
      goto LAB_080fe7a6;
    }
  }
  ptr = (BN_MONT_CTX *)0x0;
LAB_080fe7a6:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return ptr;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

