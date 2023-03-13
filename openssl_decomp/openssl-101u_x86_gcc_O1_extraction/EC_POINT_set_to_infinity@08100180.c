
int EC_POINT_set_to_infinity(EC_GROUP *group,EC_POINT *point)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)group + 0x38);
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    ERR_put_error(0x10,0x7f,0x42,"ec_lib.c",0x2f9);
  }
  else {
    if (*(int *)group == *(int *)point) {
                    /* WARNING: Could not recover jumptable at 0x081001cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*UNRECOVERED_JUMPTABLE)();
      return iVar1;
    }
    ERR_put_error(0x10,0x7f,0x65,"ec_lib.c",0x2fd);
  }
  return 0;
}

