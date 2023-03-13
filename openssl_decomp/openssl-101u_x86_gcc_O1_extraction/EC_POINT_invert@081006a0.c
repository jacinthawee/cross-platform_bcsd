
int EC_POINT_invert(EC_GROUP *group,EC_POINT *a,BN_CTX *ctx)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)group + 0x60);
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    ERR_put_error(0x10,0xd2,0x42,"ec_lib.c",0x391);
  }
  else {
    if (*(int *)group == *(int *)a) {
                    /* WARNING: Could not recover jumptable at 0x081006f9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*UNRECOVERED_JUMPTABLE)();
      return iVar1;
    }
    ERR_put_error(0x10,0xd2,0x65,"ec_lib.c",0x395);
  }
  return 0;
}

