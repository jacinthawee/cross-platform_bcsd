
int EC_POINT_is_at_infinity(EC_GROUP *group,EC_POINT *p)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)group + 100);
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    ERR_put_error(0x10,0x76,0x42,"ec_lib.c",0x39f);
  }
  else {
    if (*(int *)group == *(int *)p) {
                    /* WARNING: Could not recover jumptable at 0x0810076c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*UNRECOVERED_JUMPTABLE)();
      return iVar1;
    }
    ERR_put_error(0x10,0x76,0x65,"ec_lib.c",0x3a3);
  }
  return 0;
}

