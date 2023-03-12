
undefined4 __regparm3
VKO_compute_key_isra_0(undefined4 param_1_00,EC_POINT *param_2,EC_KEY *param_3,undefined *param_1)

{
  undefined uVar1;
  BIGNUM *a;
  EC_GROUP *pEVar2;
  EC_POINT *r;
  BN_CTX *ctx;
  BIGNUM *b;
  BIGNUM *r_00;
  BIGNUM *order;
  BIGNUM *x;
  BIGNUM *y;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  int in_GS_OFFSET;
  undefined local_118 [112];
  undefined local_a8;
  undefined local_a7;
  undefined local_a6;
  undefined local_a5;
  undefined local_a4;
  undefined local_a3;
  undefined local_a2;
  undefined local_a1;
  undefined local_a0 [32];
  undefined local_80 [31];
  undefined local_61;
  undefined local_60 [64];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  a = EC_KEY_get0_private_key(param_3);
  pEVar2 = EC_KEY_get0_group(param_3);
  r = EC_POINT_new(pEVar2);
  ctx = BN_CTX_new();
  local_a1 = *param_1;
  local_a2 = param_1[1];
  local_a3 = param_1[2];
  local_a4 = param_1[3];
  local_a5 = param_1[4];
  local_a6 = param_1[5];
  local_a7 = param_1[6];
  local_a8 = param_1[7];
  BN_CTX_start(ctx);
  b = (BIGNUM *)getbnfrombuf(&local_a8,8);
  r_00 = BN_CTX_get(ctx);
  order = BN_CTX_get(ctx);
  x = BN_CTX_get(ctx);
  y = BN_CTX_get(ctx);
  pEVar2 = EC_KEY_get0_group(param_3);
  EC_GROUP_get_order(pEVar2,order,ctx);
  BN_mod_mul(r_00,a,b,order,ctx);
  pEVar2 = EC_KEY_get0_group(param_3);
  EC_POINT_mul(pEVar2,r,(BIGNUM *)0x0,param_2,r_00,ctx);
  pEVar2 = EC_KEY_get0_group(param_3);
  EC_POINT_get_affine_coordinates_GFp(pEVar2,r,x,y,ctx);
  puVar5 = local_a0;
  store_bignum(y,puVar5,0x20);
  store_bignum(x,local_80,0x20);
  puVar3 = local_60 + 0x3f;
  do {
    uVar1 = *puVar5;
    puVar4 = puVar3 + -1;
    puVar5 = puVar5 + 1;
    *puVar3 = uVar1;
    puVar3 = puVar4;
  } while (&local_61 != puVar4);
  init_gost_hash_ctx(local_118,GostR3411_94_CryptoProParamSet);
  start_hash(local_118);
  hash_block(local_118,local_60,0x40);
  finish_hash(local_118,param_1_00);
  done_gost_hash_ctx(local_118);
  BN_free(b);
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  EC_POINT_free(r);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return 0x20;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

