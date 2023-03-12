
int EC_POINT_invert(EC_GROUP *group,EC_POINT *a,BN_CTX *ctx)

{
  int iVar1;
  
  iVar1 = *(int *)group;
  if (*(int *)(iVar1 + 0x5c) == 0) {
    ERR_put_error(0x10,0xd2,0x42,"ec_lib.c",0x3b3);
  }
  else {
    if (iVar1 == *(int *)a) {
                    /* WARNING: Could not recover jumptable at 0x000913a6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (**(code **)(iVar1 + 0x60))();
      return iVar1;
    }
    ERR_put_error(0x10,0xd2,0x65,"ec_lib.c",0x3b8);
  }
  return 0;
}

