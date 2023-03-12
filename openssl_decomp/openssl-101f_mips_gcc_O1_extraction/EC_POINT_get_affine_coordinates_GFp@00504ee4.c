
int EC_POINT_get_affine_coordinates_GFp(EC_GROUP *group,EC_POINT *p,BIGNUM *x,BIGNUM *y,BN_CTX *ctx)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)group + 0x48);
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    uVar3 = 0x42;
    uVar1 = 0x372;
  }
  else {
    if (*(int *)group == *(int *)p) {
                    /* WARNING: Could not recover jumptable at 0x00504f4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar2 = (*UNRECOVERED_JUMPTABLE)();
      return iVar2;
    }
    uVar3 = 0x65;
    uVar1 = 0x377;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x74,uVar3,"ec_lib.c",uVar1);
  return 0;
}

