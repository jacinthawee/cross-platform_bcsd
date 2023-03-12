
int EC_POINT_copy(EC_POINT *dst,EC_POINT *src)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)dst + 0x34);
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    uVar3 = 0x42;
    uVar1 = 0x2f2;
  }
  else {
    if (*(int *)dst == *(int *)src) {
      if (dst == src) {
        return 1;
      }
                    /* WARNING: Could not recover jumptable at 0x00504a2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar2 = (*UNRECOVERED_JUMPTABLE)();
      return iVar2;
    }
    uVar3 = 0x65;
    uVar1 = 0x2f7;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x72,uVar3,"ec_lib.c",uVar1);
  return 0;
}

