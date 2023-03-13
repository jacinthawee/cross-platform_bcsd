
DSA_SIG * gost2001_do_sign(undefined4 param_1,int param_2,EC_KEY *param_3)

{
  bool bVar1;
  BIGNUM *pBVar2;
  BIGNUM *m;
  BN_CTX *ctx;
  EC_GROUP *group;
  BIGNUM *pBVar3;
  int iVar4;
  BIGNUM *a;
  BIGNUM *rem;
  BIGNUM *rnd;
  EC_POINT *r;
  BIGNUM *x;
  BIGNUM *r_00;
  DSA_SIG *pDVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  BIGNUM *local_38;
  BIGNUM *local_34;
  BIGNUM *local_30;
  DSA_SIG *local_20;
  
  m = (BIGNUM *)hashsum2bn(param_1);
  ctx = BN_CTX_new();
  bVar1 = ctx == (BN_CTX *)0x0 || m == (BIGNUM *)0x0;
  if (bVar1) {
    ERR_GOST_error(0x69,0x41,"gost2001.c",0x8a);
    if (ctx != (BN_CTX *)0x0) {
      BN_CTX_end(ctx);
      BN_CTX_free(ctx);
    }
    if (m == (BIGNUM *)0x0) {
      return (DSA_SIG *)0x0;
    }
    bVar1 = false;
    local_20 = (DSA_SIG *)0x0;
    pDVar5 = (DSA_SIG *)0x0;
  }
  else {
    BN_CTX_start(ctx);
    if (param_2 != 0x20) {
      OpenSSLDie("gost2001.c",0x8e,"dlen == 32");
    }
    local_20 = DSA_SIG_new();
    if (local_20 == (DSA_SIG *)0x0) {
      ERR_GOST_error(0x69,0x76,"gost2001.c",0x91);
    }
    else {
      group = EC_KEY_get0_group(param_3);
      if (group == (EC_GROUP *)0x0) {
        uVar7 = 0x96;
      }
      else {
        pBVar3 = BN_CTX_get(ctx);
        if ((pBVar3 == (BIGNUM *)0x0) || (iVar4 = EC_GROUP_get_order(group,pBVar3,ctx), iVar4 == 0))
        {
          uVar7 = 0x9b;
        }
        else {
          a = EC_KEY_get0_private_key(param_3);
          if (a == (BIGNUM *)0x0) {
            uVar7 = 0xa0;
          }
          else {
            rem = BN_CTX_get(ctx);
            if ((rem != (BIGNUM *)0x0) &&
               (iVar4 = BN_div((BIGNUM *)0x0,rem,m,pBVar3,ctx), iVar4 != 0)) {
              if (rem->top == 0) {
                BN_set_word(rem,1);
              }
              rnd = BN_CTX_get(ctx);
              r = EC_POINT_new(group);
              bVar1 = rnd == (BIGNUM *)0x0 || r == (EC_POINT *)0x0;
              if (bVar1) {
                pDVar5 = (DSA_SIG *)0x0;
                ERR_GOST_error(0x69,0x41,"gost2001.c",0xb5);
                BN_CTX_end(ctx);
                BN_CTX_free(ctx);
                if (r == (EC_POINT *)0x0) goto LAB_081d3981;
              }
              else {
                local_34 = (BIGNUM *)0x0;
                local_38 = (BIGNUM *)0x0;
                x = (BIGNUM *)0x0;
                local_30 = (BIGNUM *)0x0;
                r_00 = (BIGNUM *)0x0;
                do {
                  do {
                    iVar4 = BN_rand_range(rnd,pBVar3);
                    if (iVar4 == 0) {
                      uVar6 = 0xbc;
                      uVar7 = 0x7d;
LAB_081d3a30:
                      bVar1 = true;
                      ERR_GOST_error(0x69,uVar7,"gost2001.c",uVar6);
                      pDVar5 = (DSA_SIG *)0x0;
                      goto LAB_081d3a41;
                    }
                    iVar4 = EC_POINT_mul(group,r,rnd,(EC_POINT *)0x0,(BIGNUM *)0x0,ctx);
                    if (iVar4 == 0) {
                      uVar6 = 0xc0;
LAB_081d3b1d:
                      uVar7 = 0x10;
                      goto LAB_081d3a30;
                    }
                    if (x == (BIGNUM *)0x0) {
                      x = BN_CTX_get(ctx);
                    }
                    if (r_00 == (BIGNUM *)0x0) {
                      r_00 = BN_CTX_get(ctx);
                    }
                    bVar1 = r_00 == (BIGNUM *)0x0 || x == (BIGNUM *)0x0;
                    if (bVar1) {
                      uVar7 = 200;
                      goto LAB_081d3b37;
                    }
                    iVar4 = EC_POINT_get_affine_coordinates_GFp(group,r,x,(BIGNUM *)0x0,ctx);
                    if (iVar4 == 0) {
                      uVar6 = 0xcc;
                      goto LAB_081d3b1d;
                    }
                    iVar4 = BN_nnmod(r_00,x,pBVar3,ctx);
                    if (iVar4 == 0) {
                      uVar6 = 0xd1;
                      uVar7 = 0x44;
                      goto LAB_081d3a30;
                    }
                  } while (r_00->top == 0);
                  if (local_38 == (BIGNUM *)0x0) {
                    local_38 = BN_CTX_get(ctx);
                  }
                  if (local_34 == (BIGNUM *)0x0) {
                    local_34 = BN_CTX_get(ctx);
                  }
                  if (local_30 == (BIGNUM *)0x0) {
                    local_30 = BN_CTX_get(ctx);
                    pBVar2 = local_30;
                    if (local_38 != (BIGNUM *)0x0 && local_34 != (BIGNUM *)0x0)
                    goto joined_r0x081d3a1a;
LAB_081d3a20:
                    uVar6 = 0xde;
                    uVar7 = 0x41;
                    goto LAB_081d3a30;
                  }
                  pBVar2 = local_38;
                  if (local_34 == (BIGNUM *)0x0) goto LAB_081d3a20;
joined_r0x081d3a1a:
                  if (pBVar2 == (BIGNUM *)0x0) goto LAB_081d3a20;
                  iVar4 = BN_mod_mul(local_38,a,r_00,pBVar3,ctx);
                  if (((iVar4 == 0) || (iVar4 = BN_mod_mul(local_34,rnd,rem,pBVar3,ctx), iVar4 == 0)
                      ) || (iVar4 = BN_mod_add(local_30,local_38,local_34,pBVar3,ctx), iVar4 == 0))
                  {
                    uVar6 = 0xe5;
                    uVar7 = 0x44;
                    goto LAB_081d3a30;
                  }
                } while (local_30->top == 0);
                pBVar3 = BN_dup(local_30);
                local_20->s = pBVar3;
                pBVar3 = BN_dup(r_00);
                local_20->r = pBVar3;
                bVar1 = local_20->s == (BIGNUM *)0x0 || pBVar3 == (BIGNUM *)0x0;
                pDVar5 = local_20;
                if (bVar1) {
                  uVar7 = 0xee;
LAB_081d3b37:
                  ERR_GOST_error(0x69,0x41,"gost2001.c",uVar7);
                  pDVar5 = (DSA_SIG *)0x0;
                }
LAB_081d3a41:
                BN_CTX_end(ctx);
                BN_CTX_free(ctx);
              }
              EC_POINT_free(r);
              goto LAB_081d3981;
            }
            uVar7 = 0xa5;
          }
        }
      }
      bVar1 = true;
      ERR_GOST_error(0x69,0x44,"gost2001.c",uVar7);
    }
    pDVar5 = (DSA_SIG *)0x0;
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
  }
LAB_081d3981:
  BN_free(m);
  if (bVar1) {
    DSA_SIG_free(local_20);
  }
  return pDVar5;
}

