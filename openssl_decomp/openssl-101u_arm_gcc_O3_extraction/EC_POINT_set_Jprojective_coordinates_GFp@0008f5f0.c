
int EC_POINT_set_Jprojective_coordinates_GFp
              (EC_GROUP *group,EC_POINT *p,BIGNUM *x,BIGNUM *y,BIGNUM *z,BN_CTX *ctx)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)group + 0x3c);
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    ERR_put_error(0x10,0x7e,0x42,"ec_lib.c",0x30a);
  }
  else {
    if (*(int *)group == *(int *)p) {
                    /* WARNING: Could not recover jumptable at 0x0008f632. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*UNRECOVERED_JUMPTABLE)();
      return iVar1;
    }
    ERR_put_error(0x10,0x7e,0x65,"ec_lib.c",0x30f);
  }
  return 0;
}

