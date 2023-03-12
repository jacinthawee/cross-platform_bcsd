
void VKO_compute_key_isra_0(undefined4 param_1,EC_POINT *param_2,EC_KEY *param_3,undefined *param_4)

{
  BIGNUM *a;
  EC_GROUP *pEVar1;
  EC_POINT *r;
  BN_CTX *ctx;
  BIGNUM *b;
  BIGNUM *r_00;
  BIGNUM *order;
  BIGNUM *x;
  BIGNUM *y;
  undefined *puVar2;
  undefined *puVar3;
  undefined local_128;
  undefined local_127;
  undefined local_126;
  undefined local_125;
  undefined local_124;
  undefined local_123;
  undefined local_122;
  undefined local_121;
  undefined local_120 [64];
  undefined auStack_e0 [63];
  undefined local_a1 [117];
  int local_2c;
  
  local_2c = __TMC_END__;
  a = EC_KEY_get0_private_key(param_3);
  pEVar1 = EC_KEY_get0_group(param_3);
  r = EC_POINT_new(pEVar1);
  ctx = BN_CTX_new();
  local_121 = *param_4;
  local_124 = param_4[3];
  local_126 = param_4[5];
  local_122 = param_4[1];
  local_123 = param_4[2];
  local_125 = param_4[4];
  local_127 = param_4[6];
  local_128 = param_4[7];
  BN_CTX_start(ctx);
  b = (BIGNUM *)getbnfrombuf(&local_128,8);
  r_00 = BN_CTX_get(ctx);
  order = BN_CTX_get(ctx);
  x = BN_CTX_get(ctx);
  y = BN_CTX_get(ctx);
  pEVar1 = EC_KEY_get0_group(param_3);
  EC_GROUP_get_order(pEVar1,order,ctx);
  BN_mod_mul(r_00,a,b,order,ctx);
  pEVar1 = EC_KEY_get0_group(param_3);
  EC_POINT_mul(pEVar1,r,(BIGNUM *)0x0,param_2,r_00,ctx);
  pEVar1 = EC_KEY_get0_group(param_3);
  EC_POINT_get_affine_coordinates_GFp(pEVar1,r,x,y,ctx);
  store_bignum(y,local_120,0x20);
  store_bignum(x,local_120 + 0x20,0x20);
  puVar3 = &local_121;
  puVar2 = local_a1 + 1;
  do {
    puVar3 = puVar3 + 1;
    puVar2 = puVar2 + -1;
    *puVar2 = *puVar3;
  } while (puVar3 != local_120 + 0x3f);
  init_gost_hash_ctx(local_a1 + 1,GostR3411_94_CryptoProParamSet);
  start_hash(local_a1 + 1);
  hash_block(local_a1 + 1,auStack_e0,0x40);
  finish_hash(local_a1 + 1,param_1);
  done_gost_hash_ctx(local_a1 + 1);
  BN_free(b);
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  EC_POINT_free(r);
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(0x20);
}

