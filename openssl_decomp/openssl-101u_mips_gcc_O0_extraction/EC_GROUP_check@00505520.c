
int EC_GROUP_check(EC_GROUP *group,BN_CTX *ctx)

{
  BIGNUM *order;
  int iVar1;
  EC_POINT *r;
  undefined4 uVar2;
  undefined4 uVar3;
  BN_CTX *c;
  
  if (ctx == (BN_CTX *)0x0) {
    ctx = BN_CTX_new();
    c = ctx;
    if (ctx == (BN_CTX *)0x0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xaa,0x41,"ec_check.c",0x45);
      return 0;
    }
  }
  else {
    c = (BN_CTX *)0x0;
  }
  BN_CTX_start(ctx);
  order = BN_CTX_get(ctx);
  if (order == (BIGNUM *)0x0) {
LAB_0050566c:
    iVar1 = 0;
    BN_CTX_end(ctx);
    if (c == (BN_CTX *)0x0) {
      return 0;
    }
    r = (EC_POINT *)0x0;
  }
  else {
    iVar1 = EC_GROUP_check_discriminant(group,ctx);
    if (iVar1 == 0) {
      uVar3 = 0x76;
      uVar2 = 0x4f;
LAB_00505658:
      (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xaa,uVar3,"ec_check.c",uVar2);
      goto LAB_0050566c;
    }
    if (*(EC_POINT **)(group + 4) == (EC_POINT *)0x0) {
      uVar3 = 0x71;
      uVar2 = 0x55;
      goto LAB_00505658;
    }
    iVar1 = EC_POINT_is_on_curve(group,*(EC_POINT **)(group + 4),ctx);
    if (iVar1 < 1) {
      uVar3 = 0x6b;
      uVar2 = 0x59;
      goto LAB_00505658;
    }
    r = EC_POINT_new(group);
    if (r == (EC_POINT *)0x0) goto LAB_0050566c;
    iVar1 = EC_GROUP_get_order(group,order,ctx);
    if (iVar1 == 0) {
LAB_00505624:
      iVar1 = 0;
    }
    else {
      if (order->top == 0) {
        uVar3 = 0x80;
        uVar2 = 99;
LAB_00505610:
        (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xaa,uVar3,"ec_check.c",uVar2);
        goto LAB_00505624;
      }
      iVar1 = EC_POINT_mul(group,r,order,(EC_POINT *)0x0,(BIGNUM *)0x0,ctx);
      if (iVar1 == 0) goto LAB_00505624;
      iVar1 = EC_POINT_is_at_infinity(group,r);
      if (iVar1 == 0) {
        uVar3 = 0x7a;
        uVar2 = 0x6a;
        goto LAB_00505610;
      }
      iVar1 = 1;
    }
    BN_CTX_end(ctx);
    if (c == (BN_CTX *)0x0) goto LAB_005056a0;
  }
  BN_CTX_free(c);
  if (r == (EC_POINT *)0x0) {
    return iVar1;
  }
LAB_005056a0:
  EC_POINT_free(r);
  return iVar1;
}

