
int EC_POINT_copy(EC_POINT *dst,EC_POINT *src)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)dst + 0x34);
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    ERR_put_error(0x10,0x72,0x42,"ec_lib.c",0x2f2);
  }
  else if (*(int *)dst == *(int *)src) {
    if (dst != src) {
                    /* WARNING: Could not recover jumptable at 0x00090f26. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*UNRECOVERED_JUMPTABLE)();
      return iVar1;
    }
    UNRECOVERED_JUMPTABLE = (code *)0x1;
  }
  else {
    ERR_put_error(0x10,0x72,0x65,"ec_lib.c",0x2f7);
    UNRECOVERED_JUMPTABLE = (code *)0x0;
  }
  return (int)UNRECOVERED_JUMPTABLE;
}

