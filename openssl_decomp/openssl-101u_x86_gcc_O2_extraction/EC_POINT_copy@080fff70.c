
int EC_POINT_copy(EC_POINT *dst,EC_POINT *src)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  int line;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)dst + 0x34);
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    line = 0x2d1;
    iVar1 = 0x42;
  }
  else {
    if (*(int *)dst == *(int *)src) {
      if (dst == src) {
        return 1;
      }
                    /* WARNING: Could not recover jumptable at 0x080fffc2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*UNRECOVERED_JUMPTABLE)();
      return iVar1;
    }
    line = 0x2d5;
    iVar1 = 0x65;
  }
  ERR_put_error(0x10,0x72,iVar1,"ec_lib.c",line);
  return 0;
}

