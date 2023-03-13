
int EC_POINT_is_on_curve(EC_GROUP *group,EC_POINT *point,BN_CTX *ctx)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)group + 0x68);
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    ERR_put_error(0x10,0x77,0x42,"ec_lib.c",0x3b4);
  }
  else {
    if (*(int *)group == *(int *)point) {
                    /* WARNING: Could not recover jumptable at 0x081007e9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*UNRECOVERED_JUMPTABLE)();
      return iVar1;
    }
    ERR_put_error(0x10,0x77,0x65,"ec_lib.c",0x3b8);
  }
  return 0;
}

