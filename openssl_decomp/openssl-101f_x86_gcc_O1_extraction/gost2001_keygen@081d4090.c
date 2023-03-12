
undefined4 gost2001_keygen(EC_KEY *param_1)

{
  BIGNUM *order;
  BIGNUM *rnd;
  EC_GROUP *group;
  int iVar1;
  undefined4 uVar2;
  
  order = BN_new();
  rnd = BN_new();
  group = EC_KEY_get0_group(param_1);
  EC_GROUP_get_order(group,order,(BN_CTX *)0x0);
  do {
    iVar1 = BN_rand_range(rnd,order);
    if (iVar1 == 0) {
      ERR_GOST_error(0x6b,0x7d,"gost2001.c",0x14b);
      BN_free(rnd);
      BN_free(order);
      return 0;
    }
  } while (rnd->top == 0);
  EC_KEY_set_private_key(param_1,rnd);
  BN_free(rnd);
  BN_free(order);
  uVar2 = gost2001_compute_public();
  return uVar2;
}

