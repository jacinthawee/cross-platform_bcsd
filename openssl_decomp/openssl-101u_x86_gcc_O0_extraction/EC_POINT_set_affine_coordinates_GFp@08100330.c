
int EC_POINT_set_affine_coordinates_GFp(EC_GROUP *group,EC_POINT *p,BIGNUM *x,BIGNUM *y,BN_CTX *ctx)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)group + 0x44);
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    ERR_put_error(0x10,0x7c,0x42,"ec_lib.c",0x32f);
  }
  else {
    if (*(int *)group == *(int *)p) {
                    /* WARNING: Could not recover jumptable at 0x0810039b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*UNRECOVERED_JUMPTABLE)();
      return iVar1;
    }
    ERR_put_error(0x10,0x7c,0x65,"ec_lib.c",0x334);
  }
  return 0;
}

