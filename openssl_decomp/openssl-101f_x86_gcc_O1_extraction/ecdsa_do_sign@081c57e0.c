
ECDSA_SIG *
ecdsa_do_sign(uchar *param_1,int param_2,BIGNUM *param_3,BIGNUM *param_4,EC_KEY *param_5)

{
  BIGNUM *r;
  int iVar1;
  EC_GROUP *group;
  BIGNUM *a;
  ECDSA_SIG *sig;
  BN_CTX *ctx;
  BIGNUM *order;
  BIGNUM *r_00;
  uint uVar2;
  BIGNUM *pBVar3;
  ECDSA_SIG *pEVar4;
  int in_GS_OFFSET;
  BIGNUM *local_50;
  BIGNUM *local_24;
  int local_20;
  
  local_24 = (BIGNUM *)0x0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = ecdsa_check(param_5);
  group = EC_KEY_get0_group(param_5);
  a = EC_KEY_get0_private_key(param_5);
  if ((group == (EC_GROUP *)0x0 || a == (BIGNUM *)0x0) || (iVar1 == 0)) {
    sig = (ECDSA_SIG *)0x0;
    ERR_put_error(0x2a,0x65,0x43,"ecs_ossl.c",0xf0);
    goto LAB_081c5a0a;
  }
  sig = ECDSA_SIG_new();
  if (sig == (ECDSA_SIG *)0x0) {
    ERR_put_error(0x2a,0x65,0x41,"ecs_ossl.c",0xf7);
    goto LAB_081c5a0a;
  }
  r = sig->s;
  ctx = BN_CTX_new();
  if ((ctx == (BN_CTX *)0x0) || (order = BN_new(), order == (BIGNUM *)0x0)) {
    order = (BIGNUM *)0x0;
    r_00 = (BIGNUM *)0x0;
LAB_081c5984:
    ERR_put_error(0x2a,0x65,0x41,"ecs_ossl.c",0xff);
    pEVar4 = (ECDSA_SIG *)0x0;
    ECDSA_SIG_free(sig);
    local_50 = (BIGNUM *)0x0;
    sig = pEVar4;
    if (ctx != (BN_CTX *)0x0) goto LAB_081c59b6;
  }
  else {
    r_00 = BN_new();
    if ((r_00 == (BIGNUM *)0x0) || (local_50 = BN_new(), local_50 == (BIGNUM *)0x0))
    goto LAB_081c5984;
    iVar1 = EC_GROUP_get_order(group,order,ctx);
    if (iVar1 == 0) {
      ERR_put_error(0x2a,0x65,0x10,"ecs_ossl.c",0x105);
      goto LAB_081c5a43;
    }
    uVar2 = BN_num_bits(order);
    if ((int)uVar2 < param_2 * 8) {
      iVar1 = uVar2 + 7;
      if ((int)(uVar2 + 7) < 0) {
        iVar1 = uVar2 + 0xe;
      }
      pBVar3 = BN_bin2bn(param_1,iVar1 >> 3,local_50);
      if (pBVar3 == (BIGNUM *)0x0) {
LAB_081c5c45:
        iVar1 = 0x110;
      }
      else {
        if (((iVar1 >> 3) * 8 <= (int)uVar2) ||
           (iVar1 = BN_rshift(local_50,local_50,8 - (uVar2 & 7)), iVar1 != 0)) goto LAB_081c5a7f;
        iVar1 = 0x116;
      }
LAB_081c5960:
      ERR_put_error(0x2a,0x65,3,"ecs_ossl.c",iVar1);
LAB_081c5a43:
      ECDSA_SIG_free(sig);
      sig = (ECDSA_SIG *)0x0;
    }
    else {
      pBVar3 = BN_bin2bn(param_1,param_2,local_50);
      if (pBVar3 == (BIGNUM *)0x0) goto LAB_081c5c45;
LAB_081c5a7f:
      if ((param_4 == (BIGNUM *)0x0) || (param_3 == (BIGNUM *)0x0)) {
        if (param_4 != (BIGNUM *)0x0 && param_3 != (BIGNUM *)0x0) {
          iVar1 = ECDSA_sign_setup(param_5,ctx,&local_24,&sig->r);
          param_3 = local_24;
          if (iVar1 == 0) {
LAB_081c5c25:
            ERR_put_error(0x2a,0x65,0x2a,"ecs_ossl.c",0x11f);
          }
          else {
            iVar1 = BN_mod_mul(r_00,a,sig->r,order,ctx);
            if (iVar1 == 0) {
LAB_081c5d11:
              iVar1 = 0x130;
              goto LAB_081c5960;
            }
            iVar1 = BN_mod_add_quick(r,r_00,local_50,order);
            if (iVar1 == 0) goto LAB_081c5d22;
LAB_081c5cd1:
            iVar1 = BN_mod_mul(r,r,param_3,order,ctx);
            if (iVar1 == 0) {
LAB_081c5d33:
              iVar1 = 0x13a;
              goto LAB_081c5960;
            }
            if (r->top != 0) goto LAB_081c59b6;
            ERR_put_error(0x2a,0x65,0x6a,"ecs_ossl.c",0x143);
          }
          goto LAB_081c5a43;
        }
        do {
          iVar1 = ECDSA_sign_setup(param_5,ctx,&local_24,&sig->r);
          pBVar3 = local_24;
          if (iVar1 == 0) goto LAB_081c5c25;
          iVar1 = BN_mod_mul(r_00,a,sig->r,order,ctx);
          if (iVar1 == 0) goto LAB_081c5d11;
          iVar1 = BN_mod_add_quick(r,r_00,local_50,order);
          if (iVar1 == 0) goto LAB_081c5d22;
          iVar1 = BN_mod_mul(r,r,pBVar3,order,ctx);
          if (iVar1 == 0) goto LAB_081c5d33;
        } while (r->top == 0);
      }
      else {
        if (param_4 != (BIGNUM *)0x0 && param_3 != (BIGNUM *)0x0) {
          pBVar3 = BN_copy(sig->r,param_4);
          if (pBVar3 != (BIGNUM *)0x0) {
            iVar1 = BN_mod_mul(r_00,a,sig->r,order,ctx);
            if (iVar1 == 0) goto LAB_081c5d11;
            iVar1 = BN_mod_add_quick(r,r_00,local_50,order);
            if (iVar1 != 0) goto LAB_081c5cd1;
LAB_081c5d22:
            iVar1 = 0x135;
            goto LAB_081c5960;
          }
LAB_081c5b38:
          ERR_put_error(0x2a,0x65,0x41,"ecs_ossl.c",0x129);
          goto LAB_081c5a43;
        }
        do {
          pBVar3 = BN_copy(sig->r,param_4);
          if (pBVar3 == (BIGNUM *)0x0) goto LAB_081c5b38;
          iVar1 = BN_mod_mul(r_00,a,sig->r,order,ctx);
          if (iVar1 == 0) goto LAB_081c5d11;
          iVar1 = BN_mod_add_quick(r,r_00,local_50,order);
          if (iVar1 == 0) goto LAB_081c5d22;
          iVar1 = BN_mod_mul(r,r,param_3,order,ctx);
          if (iVar1 == 0) goto LAB_081c5d33;
        } while (r->top == 0);
      }
    }
LAB_081c59b6:
    BN_CTX_free(ctx);
    pEVar4 = sig;
    if (local_50 != (BIGNUM *)0x0) {
      BN_clear_free(local_50);
    }
  }
  if (r_00 != (BIGNUM *)0x0) {
    BN_clear_free(r_00);
  }
  if (order != (BIGNUM *)0x0) {
    BN_free(order);
  }
  sig = pEVar4;
  if (local_24 != (BIGNUM *)0x0) {
    BN_clear_free(local_24);
  }
LAB_081c5a0a:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return sig;
}

