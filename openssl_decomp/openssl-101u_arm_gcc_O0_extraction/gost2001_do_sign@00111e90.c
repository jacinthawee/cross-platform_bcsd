
BIGNUM * gost2001_do_sign(undefined4 param_1,int param_2,EC_KEY *param_3)

{
  BIGNUM *m;
  BIGNUM *ctx;
  BIGNUM *pBVar1;
  BIGNUM *pBVar2;
  int iVar3;
  BIGNUM *a;
  BIGNUM *rem;
  BIGNUM *rnd;
  BIGNUM *r;
  BIGNUM *pBVar4;
  BIGNUM *x;
  BIGNUM *pBVar5;
  BIGNUM *r_00;
  BIGNUM *local_44;
  BIGNUM *local_40;
  BIGNUM *local_3c;
  BIGNUM *local_2c;
  
  m = (BIGNUM *)hashsum2bn();
  ctx = (BIGNUM *)BN_CTX_new();
  if (ctx == (BIGNUM *)0x0 || m == (BIGNUM *)0x0) {
    ERR_GOST_error(0x69,0x41,"gost2001.c",0x8a);
    pBVar5 = ctx;
    local_2c = ctx;
    if (ctx != (BIGNUM *)0x0) {
      BN_CTX_end((BN_CTX *)ctx);
      BN_CTX_free((BN_CTX *)ctx);
      ctx = (BIGNUM *)0x0;
      local_2c = (BIGNUM *)0x0;
      pBVar5 = (BIGNUM *)0x0;
    }
  }
  else {
    pBVar5 = (BIGNUM *)0x0;
    BN_CTX_start((BN_CTX *)ctx);
    if (param_2 != 0x20) {
      OpenSSLDie("gost2001.c",0x8e,"dlen == 32");
    }
    local_2c = (BIGNUM *)DSA_SIG_new();
    if (local_2c == (BIGNUM *)0x0) {
      ERR_GOST_error(0x69,0x76,"gost2001.c",0x91);
      pBVar1 = local_2c;
      a = local_2c;
    }
    else {
      pBVar1 = (BIGNUM *)EC_KEY_get0_group(param_3);
      if (pBVar1 == (BIGNUM *)0x0) {
        ERR_GOST_error(0x69,0x44,"gost2001.c",0x96);
        pBVar5 = (BIGNUM *)0x1;
        a = pBVar1;
      }
      else {
        pBVar2 = BN_CTX_get((BN_CTX *)ctx);
        if ((pBVar2 == (BIGNUM *)0x0) ||
           (iVar3 = EC_GROUP_get_order((EC_GROUP *)pBVar1,pBVar2,(BN_CTX *)ctx), iVar3 == 0)) {
          ERR_GOST_error(0x69,0x44,"gost2001.c",0x9b);
          pBVar5 = (BIGNUM *)0x1;
          pBVar1 = (BIGNUM *)0x0;
          a = (BIGNUM *)0x0;
        }
        else {
          a = EC_KEY_get0_private_key(param_3);
          if (a == (BIGNUM *)0x0) {
            ERR_GOST_error(0x69,0x44,"gost2001.c",0xa0);
            pBVar5 = (BIGNUM *)0x1;
            pBVar1 = a;
          }
          else {
            rem = BN_CTX_get((BN_CTX *)ctx);
            if ((rem == (BIGNUM *)0x0) ||
               (iVar3 = BN_div((BIGNUM *)0x0,rem,m,pBVar2,(BN_CTX *)ctx), iVar3 == 0)) {
              ERR_GOST_error(0x69,0x44,"gost2001.c",0xa5);
              pBVar5 = (BIGNUM *)0x1;
              pBVar1 = (BIGNUM *)0x0;
              a = (BIGNUM *)0x0;
            }
            else {
              if (rem->top == 0) {
                BN_set_word(rem,1);
              }
              rnd = BN_CTX_get((BN_CTX *)ctx);
              r = (BIGNUM *)EC_POINT_new((EC_GROUP *)pBVar1);
              if (rnd == (BIGNUM *)0x0 || r == (BIGNUM *)0x0) {
                pBVar5 = (BIGNUM *)0x1;
                ERR_GOST_error(0x69,0x41,"gost2001.c",0xb5);
                pBVar1 = (BIGNUM *)0x0;
                a = r;
              }
              else {
                r_00 = (BIGNUM *)0x0;
                local_44 = (BIGNUM *)0x0;
                local_3c = (BIGNUM *)0x0;
                local_40 = (BIGNUM *)0x0;
                x = r_00;
                do {
                  do {
                    pBVar4 = (BIGNUM *)BN_rand_range(rnd,pBVar2);
                    if (pBVar4 == (BIGNUM *)0x0) {
                      pBVar5 = (BIGNUM *)0x1;
                      ERR_GOST_error(0x69,0x7d,"gost2001.c",0xbc);
                      pBVar1 = pBVar4;
                      a = r;
                      goto LAB_00112066;
                    }
                    pBVar4 = (BIGNUM *)
                             EC_POINT_mul((EC_GROUP *)pBVar1,(EC_POINT *)r,rnd,(EC_POINT *)0x0,
                                          (BIGNUM *)0x0,(BN_CTX *)ctx);
                    if (pBVar4 == (BIGNUM *)0x0) {
                      pBVar5 = (BIGNUM *)0x1;
                      ERR_GOST_error(0x69,0x10,"gost2001.c",0xc0);
                      pBVar1 = pBVar4;
                      a = r;
                      goto LAB_00112066;
                    }
                    if (x == (BIGNUM *)0x0) {
                      x = BN_CTX_get((BN_CTX *)ctx);
                    }
                    if (r_00 == (BIGNUM *)0x0) {
                      r_00 = BN_CTX_get((BN_CTX *)ctx);
                    }
                    if (x == (BIGNUM *)0x0 || r_00 == (BIGNUM *)0x0) {
                      pBVar5 = (BIGNUM *)0x1;
                      ERR_GOST_error(0x69,0x41,"gost2001.c",200);
                      pBVar1 = (BIGNUM *)0x0;
                      a = r;
                      goto LAB_00112066;
                    }
                    pBVar5 = (BIGNUM *)0x0;
                    pBVar4 = (BIGNUM *)
                             EC_POINT_get_affine_coordinates_GFp
                                       ((EC_GROUP *)pBVar1,(EC_POINT *)r,x,(BIGNUM *)0x0,
                                        (BN_CTX *)ctx);
                    if (pBVar4 == (BIGNUM *)0x0) {
                      pBVar5 = (BIGNUM *)0x1;
                      ERR_GOST_error(0x69,0x10,"gost2001.c",0xcc);
                      pBVar1 = pBVar4;
                      a = r;
                      goto LAB_00112066;
                    }
                    pBVar4 = (BIGNUM *)BN_nnmod(r_00,x,pBVar2,(BN_CTX *)ctx);
                    if (pBVar4 == (BIGNUM *)0x0) {
                      pBVar5 = (BIGNUM *)0x1;
                      ERR_GOST_error(0x69,0x44,"gost2001.c",0xd1);
                      pBVar1 = pBVar4;
                      a = r;
                      goto LAB_00112066;
                    }
                  } while (r_00->top == 0);
                  if (local_3c == (BIGNUM *)0x0) {
                    local_3c = BN_CTX_get((BN_CTX *)ctx);
                  }
                  if (local_44 == (BIGNUM *)0x0) {
                    local_44 = BN_CTX_get((BN_CTX *)ctx);
                  }
                  if (local_40 == (BIGNUM *)0x0) {
                    local_40 = BN_CTX_get((BN_CTX *)ctx);
                    pBVar4 = local_40;
                    if (local_44 != (BIGNUM *)0x0 && local_3c != (BIGNUM *)0x0)
                    goto joined_r0x001120b2;
LAB_00112010:
                    pBVar5 = (BIGNUM *)0x1;
                    ERR_GOST_error(0x69,0x41,"gost2001.c",0xde);
                    pBVar1 = (BIGNUM *)0x0;
                    a = r;
                    goto LAB_00112066;
                  }
                  pBVar4 = local_3c;
                  if (local_44 == (BIGNUM *)0x0) goto LAB_00112010;
joined_r0x001120b2:
                  if (pBVar4 == (BIGNUM *)0x0) goto LAB_00112010;
                  iVar3 = BN_mod_mul(local_3c,a,r_00,pBVar2,(BN_CTX *)ctx);
                  if (((iVar3 == 0) ||
                      (iVar3 = BN_mod_mul(local_44,rnd,rem,pBVar2,(BN_CTX *)ctx), iVar3 == 0)) ||
                     (iVar3 = BN_mod_add(local_40,local_3c,local_44,pBVar2,(BN_CTX *)ctx),
                     iVar3 == 0)) {
                    pBVar5 = (BIGNUM *)0x1;
                    ERR_GOST_error(0x69,0x44,"gost2001.c",0xe5);
                    pBVar1 = (BIGNUM *)0x0;
                    a = r;
                    goto LAB_00112066;
                  }
                } while (local_40->top == 0);
                pBVar1 = BN_dup(local_40);
                local_2c->top = (int)pBVar1;
                pBVar2 = BN_dup(r_00);
                local_2c->d = (ulong *)pBVar2;
                if (((BIGNUM *)local_2c->top == (BIGNUM *)0x0) ||
                   (pBVar1 = local_2c, a = r, pBVar2 == (BIGNUM *)0x0)) {
                  pBVar5 = (BIGNUM *)0x1;
                  ERR_GOST_error(0x69,0x41,"gost2001.c",0xee);
                  pBVar1 = (BIGNUM *)0x0;
                  a = r;
                }
              }
            }
          }
        }
      }
    }
LAB_00112066:
    BN_CTX_end((BN_CTX *)ctx);
    BN_CTX_free((BN_CTX *)ctx);
    ctx = pBVar1;
    if (a != (BIGNUM *)0x0) {
      EC_POINT_free((EC_POINT *)a);
    }
  }
  if (m != (BIGNUM *)0x0) {
    BN_free(m);
  }
  if (pBVar5 != (BIGNUM *)0x0) {
    DSA_SIG_free((DSA_SIG *)local_2c);
  }
  return ctx;
}

