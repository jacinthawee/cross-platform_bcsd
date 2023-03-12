
int EC_POINT_add(EC_GROUP *group,EC_POINT *r,EC_POINT *a,EC_POINT *b,BN_CTX *ctx)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)group;
  if (*(code **)(iVar1 + 0x58) == (code *)0x0) {
    uVar3 = 0x42;
    uVar2 = 0x393;
  }
  else {
    if (((iVar1 == *(int *)r) && (iVar1 == *(int *)a)) && (iVar1 == *(int *)b)) {
                    /* WARNING: Could not recover jumptable at 0x00505074. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (**(code **)(iVar1 + 0x58))();
      return iVar1;
    }
    uVar3 = 0x65;
    uVar2 = 0x398;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x70,uVar3,"ec_lib.c",uVar2);
  return 0;
}

