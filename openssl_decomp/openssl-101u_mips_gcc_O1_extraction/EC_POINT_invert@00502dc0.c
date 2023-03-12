
int EC_POINT_invert(EC_GROUP *group,EC_POINT *a,BN_CTX *ctx)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)group + 0x60);
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    uVar3 = 0x42;
    uVar1 = 0x391;
  }
  else {
    if (*(int *)group == *(int *)a) {
                    /* WARNING: Could not recover jumptable at 0x00502e20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar2 = (*UNRECOVERED_JUMPTABLE)();
      return iVar2;
    }
    uVar3 = 0x65;
    uVar1 = 0x395;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xd2,uVar3,"ec_lib.c",uVar1);
  return 0;
}

