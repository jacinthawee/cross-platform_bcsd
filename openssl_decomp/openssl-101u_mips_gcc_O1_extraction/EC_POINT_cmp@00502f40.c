
int EC_POINT_cmp(EC_GROUP *group,EC_POINT *a,EC_POINT *b,BN_CTX *ctx)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)group;
  if (*(code **)(iVar1 + 0x6c) == (code *)0x0) {
    uVar3 = 0x42;
    uVar2 = 0x3c2;
  }
  else {
    if ((iVar1 == *(int *)a) && (iVar1 == *(int *)b)) {
                    /* WARNING: Could not recover jumptable at 0x00502f78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (**(code **)(iVar1 + 0x6c))();
      return iVar1;
    }
    uVar3 = 0x65;
    uVar2 = 0x3c6;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x71,uVar3,"ec_lib.c",uVar2);
  return -1;
}

