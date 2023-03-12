
ECDSA_SIG *
ecdsa_do_sign(uchar *param_1,int param_2,BIGNUM *param_3,BIGNUM *param_4,EC_KEY *param_5)

{
  bool bVar1;
  int iVar2;
  EC_GROUP *group;
  BIGNUM *a;
  ECDSA_SIG *sig;
  ECDSA_SIG *ctx;
  BIGNUM *order;
  BIGNUM *r;
  BIGNUM *ret;
  uint uVar3;
  BIGNUM *pBVar4;
  int iVar5;
  BIGNUM *r_00;
  int local_3c;
  BIGNUM *local_2c [2];
  
  local_2c[0] = (BIGNUM *)0x0;
  iVar2 = ecdsa_check(param_5);
  group = EC_KEY_get0_group(param_5);
  a = EC_KEY_get0_private_key(param_5);
  if ((a == (BIGNUM *)0x0 || group == (EC_GROUP *)0x0) || (iVar2 == 0)) {
    ERR_put_error(0x2a,0x65,0x43,"ecs_ossl.c",0xf0);
    return (ECDSA_SIG *)0x0;
  }
  sig = ECDSA_SIG_new();
  if (sig == (ECDSA_SIG *)0x0) {
    ERR_put_error(0x2a,0x65,0x41,"ecs_ossl.c",0xf7);
    return (ECDSA_SIG *)0x0;
  }
  r_00 = sig->s;
  ctx = (ECDSA_SIG *)BN_CTX_new();
  if ((ctx == (ECDSA_SIG *)0x0) || (order = BN_new(), order == (BIGNUM *)0x0)) {
    order = (BIGNUM *)0x0;
    r = (BIGNUM *)0x0;
LAB_0010a6f0:
    ERR_put_error(0x2a,0x65,0x41,"ecs_ossl.c",0xff);
    ECDSA_SIG_free(sig);
    if (ctx == (ECDSA_SIG *)0x0) goto LAB_0010a726;
    sig = (ECDSA_SIG *)0x0;
    ret = (BIGNUM *)0x0;
  }
  else {
    r = BN_new();
    if ((r == (BIGNUM *)0x0) || (ret = BN_new(), ret == (BIGNUM *)0x0)) goto LAB_0010a6f0;
    iVar2 = EC_GROUP_get_order(group,order,(BN_CTX *)ctx);
    if (iVar2 == 0) {
      ERR_put_error(0x2a,0x65,0x10,"ecs_ossl.c",0x105);
LAB_0010a76a:
      ECDSA_SIG_free(sig);
      sig = (ECDSA_SIG *)0x0;
    }
    else {
      uVar3 = BN_num_bits(order);
      local_3c = param_2;
      if ((int)(uVar3 + param_2 * -8) < 0 != SBORROW4(uVar3,param_2 * 8)) {
        local_3c = uVar3 + 0xe;
        if (-1 < (int)(uVar3 + 7)) {
          local_3c = uVar3 + 7;
        }
        local_3c = local_3c >> 3;
      }
      pBVar4 = BN_bin2bn(param_1,local_3c,ret);
      iVar2 = 0x110;
      if (pBVar4 == (BIGNUM *)0x0) {
LAB_0010a79a:
        ERR_put_error(0x2a,0x65,3,"ecs_ossl.c",iVar2);
        goto LAB_0010a76a;
      }
      if ((int)(uVar3 + local_3c * -8) < 0 != SBORROW4(uVar3,local_3c * 8)) {
        iVar5 = BN_rshift(ret,ret,8 - (uVar3 & 7));
        iVar2 = 0x116;
        if (iVar5 == 0) goto LAB_0010a79a;
      }
      bVar1 = param_3 != (BIGNUM *)0x0 && param_4 != (BIGNUM *)0x0;
      if (param_4 == (BIGNUM *)0x0 || param_3 == (BIGNUM *)0x0) {
        if (bVar1) {
          iVar2 = ECDSA_sign_setup(param_5,(BN_CTX *)ctx,local_2c,&sig->r);
          param_3 = local_2c[0];
          if (iVar2 != 0) {
            iVar2 = BN_mod_mul(r,a,sig->r,order,(BN_CTX *)ctx);
            if (iVar2 == 0) goto LAB_0010a84a;
            iVar2 = BN_mod_add_quick(r_00,r,ret,order);
            if (iVar2 != 0) goto LAB_0010a8b6;
LAB_0010a858:
            iVar2 = 0x135;
            goto LAB_0010a79a;
          }
LAB_0010a80e:
          ERR_put_error(0x2a,0x65,0x2a,"ecs_ossl.c",0x11f);
          goto LAB_0010a76a;
        }
        do {
          iVar2 = ECDSA_sign_setup(param_5,(BN_CTX *)ctx,local_2c,&sig->r);
          pBVar4 = local_2c[0];
          if (iVar2 == 0) goto LAB_0010a80e;
          iVar2 = BN_mod_mul(r,a,sig->r,order,(BN_CTX *)ctx);
          if (iVar2 == 0) goto LAB_0010a84a;
          iVar2 = BN_mod_add_quick(r_00,r,ret,order);
          if (iVar2 == 0) goto LAB_0010a858;
          iVar2 = BN_mod_mul(r_00,r_00,pBVar4,order,(BN_CTX *)ctx);
          if (iVar2 == 0) goto LAB_0010a792;
        } while (r_00->top == 0);
      }
      else {
        if (bVar1) {
          pBVar4 = BN_copy(sig->r,param_4);
          if (pBVar4 == (BIGNUM *)0x0) {
LAB_0010a6d2:
            ERR_put_error(0x2a,0x65,0x41,"ecs_ossl.c",0x129);
          }
          else {
            iVar2 = BN_mod_mul(r,a,sig->r,order,(BN_CTX *)ctx);
            if (iVar2 == 0) {
LAB_0010a84a:
              iVar2 = 0x130;
              goto LAB_0010a79a;
            }
            iVar2 = BN_mod_add_quick(r_00,r,ret,order);
            if (iVar2 == 0) goto LAB_0010a858;
LAB_0010a8b6:
            iVar2 = BN_mod_mul(r_00,r_00,param_3,order,(BN_CTX *)ctx);
            if (iVar2 == 0) {
LAB_0010a792:
              iVar2 = 0x13a;
              goto LAB_0010a79a;
            }
            if (r_00->top != 0) goto LAB_0010a714;
            ERR_put_error(0x2a,0x65,0x6a,"ecs_ossl.c",0x143);
          }
          goto LAB_0010a76a;
        }
        do {
          pBVar4 = BN_copy(sig->r,param_4);
          if (pBVar4 == (BIGNUM *)0x0) goto LAB_0010a6d2;
          iVar2 = BN_mod_mul(r,a,sig->r,order,(BN_CTX *)ctx);
          if (iVar2 == 0) goto LAB_0010a84a;
          iVar2 = BN_mod_add_quick(r_00,r,ret,order);
          if (iVar2 == 0) goto LAB_0010a858;
          iVar2 = BN_mod_mul(r_00,r_00,param_3,order,(BN_CTX *)ctx);
          if (iVar2 == 0) goto LAB_0010a792;
        } while (r_00->top == 0);
      }
    }
  }
LAB_0010a714:
  BN_CTX_free((BN_CTX *)ctx);
  ctx = sig;
  if (ret != (BIGNUM *)0x0) {
    BN_clear_free(ret);
  }
LAB_0010a726:
  if (r != (BIGNUM *)0x0) {
    BN_clear_free(r);
  }
  if (order != (BIGNUM *)0x0) {
    BN_free(order);
  }
  if (local_2c[0] != (BIGNUM *)0x0) {
    BN_clear_free(local_2c[0]);
    return ctx;
  }
  return ctx;
}

