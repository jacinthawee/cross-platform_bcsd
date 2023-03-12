
int EC_POINT_invert(EC_GROUP *group,EC_POINT *a,BN_CTX *ctx)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)group;
  if (*(int *)(iVar1 + 0x5c) == 0) {
    uVar3 = 0x42;
    uVar2 = 0x3b3;
  }
  else {
    if (iVar1 == *(int *)a) {
                    /* WARNING: Could not recover jumptable at 0x00505184. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (**(code **)(iVar1 + 0x60))();
      return iVar1;
    }
    uVar3 = 0x65;
    uVar2 = 0x3b8;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xd2,uVar3,"ec_lib.c",uVar2);
  return 0;
}

