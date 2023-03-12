
int BN_MONT_CTX_set(BN_MONT_CTX *mont,BIGNUM *mod,BN_CTX *ctx)

{
  BIGNUM *ret;
  BIGNUM *pBVar1;
  int iVar2;
  BIGNUM *pBVar3;
  uint uVar4;
  ulong *puVar5;
  ulong uVar6;
  bool bVar7;
  ulong local_3c;
  ulong local_38;
  BIGNUM local_34;
  
  if (mod->top == 0) {
    return 0;
  }
  BN_CTX_start(ctx);
  ret = BN_CTX_get(ctx);
  if (ret != (BIGNUM *)0x0) {
    pBVar1 = BN_copy(&mont->N,mod);
    if (pBVar1 != (BIGNUM *)0x0) {
      (mont->N).neg = 0;
      pBVar1 = &mont->RR;
      BN_init(&local_34);
      local_34.d = &local_3c;
      local_34.dmax = 2;
      local_34.neg = 0;
      iVar2 = BN_num_bits(mod);
      uVar4 = iVar2 + 0x1fU;
      if ((int)(iVar2 + 0x1fU) < 0) {
        uVar4 = iVar2 + 0x3e;
      }
      mont->ri = uVar4 & 0xffffffe0;
      BN_set_word(pBVar1,0);
      iVar2 = BN_set_bit(pBVar1,0x40);
      if (iVar2 != 0) {
        local_3c = *mod->d;
        local_34.top = (int)(local_3c != 0);
        if (mod->top < 2) {
          local_38 = 0;
        }
        else {
          local_38 = mod->d[1];
          if (local_38 != 0) {
            local_34.top = 2;
          }
        }
        pBVar3 = BN_mod_inverse(ret,pBVar1,&local_34,ctx);
        if ((pBVar3 != (BIGNUM *)0x0) && (iVar2 = BN_lshift(ret,ret,0x40), iVar2 != 0)) {
          if (ret->top == 0) {
            if ((0 < ret->dmax) || (pBVar3 = bn_expand2(ret,1), pBVar3 != (BIGNUM *)0x0)) {
              puVar5 = ret->d;
              ret->neg = 0;
              *puVar5 = 0xffffffff;
              puVar5[1] = 0xffffffff;
              ret->top = 2;
LAB_0008e64c:
              iVar2 = BN_div(ret,(BIGNUM *)0x0,ret,&local_34,ctx);
              if (iVar2 != 0) {
                uVar6 = ret->top;
                if ((int)uVar6 < 1) {
                  uVar6 = 0;
                  mont->n0[0] = 0;
                }
                else {
                  puVar5 = ret->d;
                  bVar7 = uVar6 == 1;
                  if (bVar7) {
                    uVar6 = 0;
                  }
                  mont->n0[0] = *puVar5;
                  if (!bVar7) {
                    uVar6 = puVar5[1];
                  }
                }
                mont->n0[1] = uVar6;
                BN_set_word(pBVar1,0);
                iVar2 = BN_set_bit(pBVar1,mont->ri << 1);
                if (iVar2 != 0) {
                  iVar2 = BN_div((BIGNUM *)0x0,pBVar1,pBVar1,&mont->N,ctx);
                  if (iVar2 != 0) {
                    iVar2 = 1;
                  }
                  goto LAB_0008e6ac;
                }
              }
            }
          }
          else {
            iVar2 = BN_sub_word(ret,1);
            if (iVar2 != 0) goto LAB_0008e64c;
          }
        }
      }
    }
  }
  iVar2 = 0;
LAB_0008e6ac:
  BN_CTX_end(ctx);
  return iVar2;
}

