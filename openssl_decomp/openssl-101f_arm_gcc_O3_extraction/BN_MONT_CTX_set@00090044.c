
int BN_MONT_CTX_set(BN_MONT_CTX *mont,BIGNUM *mod,BN_CTX *ctx)

{
  BIGNUM *ret;
  BIGNUM *pBVar1;
  int iVar2;
  uint uVar3;
  ulong *puVar4;
  ulong uVar5;
  BIGNUM *a;
  bool bVar6;
  ulong local_3c;
  ulong local_38;
  BIGNUM local_34;
  
  BN_CTX_start(ctx);
  ret = BN_CTX_get(ctx);
  if (ret != (BIGNUM *)0x0) {
    a = &mont->RR;
    pBVar1 = BN_copy(&mont->N,mod);
    if (pBVar1 != (BIGNUM *)0x0) {
      (mont->N).neg = 0;
      BN_init(&local_34);
      local_34.d = &local_3c;
      local_34.dmax = 2;
      local_34.neg = 0;
      iVar2 = BN_num_bits(mod);
      uVar3 = iVar2 + 0x3e;
      if (-1 < (int)(iVar2 + 0x1fU)) {
        uVar3 = iVar2 + 0x1fU;
      }
      mont->ri = uVar3 & 0xffffffe0;
      BN_set_word(a,0);
      iVar2 = BN_set_bit(a,0x40);
      if (iVar2 != 0) {
        local_34.top = 0;
        local_3c = *mod->d;
        if (local_3c == 0) {
          if (mod->top < 2) goto LAB_0009018e;
LAB_000900d0:
          local_38 = mod->d[1];
          if (local_38 != 0) {
            local_34.top = 2;
          }
        }
        else {
          local_34.top = 1;
          if (1 < mod->top) goto LAB_000900d0;
LAB_0009018e:
          local_38 = 0;
        }
        pBVar1 = BN_mod_inverse(ret,a,&local_34,ctx);
        if ((pBVar1 != (BIGNUM *)0x0) && (iVar2 = BN_lshift(ret,ret,0x40), iVar2 != 0)) {
          if (ret->top == 0) {
            if ((0 < ret->dmax) || (pBVar1 = bn_expand2(ret,1), pBVar1 != (BIGNUM *)0x0)) {
              puVar4 = ret->d;
              ret->neg = 0;
              *puVar4 = 0xffffffff;
              puVar4[1] = 0xffffffff;
              ret->top = 2;
LAB_00090116:
              iVar2 = BN_div(ret,(BIGNUM *)0x0,ret,&local_34,ctx);
              if (iVar2 != 0) {
                uVar5 = ret->top;
                if ((int)uVar5 < 1) {
                  uVar5 = 0;
                  mont->n0[0] = 0;
                }
                else {
                  puVar4 = ret->d;
                  bVar6 = uVar5 == 1;
                  if (bVar6) {
                    uVar5 = 0;
                  }
                  mont->n0[0] = *puVar4;
                  if (!bVar6) {
                    uVar5 = puVar4[1];
                  }
                }
                mont->n0[1] = uVar5;
                BN_set_word(a,0);
                iVar2 = BN_set_bit(a,mont->ri << 1);
                if (iVar2 != 0) {
                  iVar2 = BN_div((BIGNUM *)0x0,a,a,&mont->N,ctx);
                  if (iVar2 != 0) {
                    iVar2 = 1;
                  }
                  goto LAB_00090176;
                }
              }
            }
          }
          else {
            iVar2 = BN_sub_word(ret,1);
            if (iVar2 != 0) goto LAB_00090116;
          }
        }
      }
    }
  }
  iVar2 = 0;
LAB_00090176:
  BN_CTX_end(ctx);
  return iVar2;
}

