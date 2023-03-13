
undefined4 gost2001_keygen(EC_KEY *param_1)

{
  BIGNUM *order;
  BIGNUM *rnd;
  EC_GROUP *group;
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  order = BN_new();
  rnd = BN_new();
  group = EC_KEY_get0_group(param_1);
  if ((group == (EC_GROUP *)0x0) ||
     (iVar1 = EC_GROUP_get_order(group,order,(BN_CTX *)0x0), iVar1 == 0)) {
    uVar3 = 0x1b8;
  }
  else {
    do {
      iVar1 = BN_rand_range(rnd,order);
      if (iVar1 == 0) {
        uVar3 = 0x1c1;
        uVar2 = 0x7d;
        goto LAB_081d41d4;
      }
    } while (rnd->top == 0);
    iVar1 = EC_KEY_set_private_key(param_1,rnd);
    if (iVar1 != 0) {
      BN_free(rnd);
      BN_free(order);
      uVar2 = gost2001_compute_public();
      return uVar2;
    }
    uVar3 = 0x1ca;
  }
  uVar2 = 0x44;
LAB_081d41d4:
  ERR_GOST_error(0x6b,uVar2,"gost2001.c",uVar3);
  BN_free(rnd);
  BN_free(order);
  return 0;
}

