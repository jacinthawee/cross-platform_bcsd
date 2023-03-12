
int EC_POINT_is_on_curve(EC_GROUP *group,EC_POINT *point,BN_CTX *ctx)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)group + 0x68);
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    uVar3 = 0x42;
    uVar1 = 0x3b4;
  }
  else {
    if (*(int *)group == *(int *)point) {
                    /* WARNING: Could not recover jumptable at 0x00502f20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar2 = (*UNRECOVERED_JUMPTABLE)();
      return iVar2;
    }
    uVar3 = 0x65;
    uVar1 = 0x3b8;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x77,uVar3,"ec_lib.c",uVar1);
  return 0;
}

