
int EC_POINT_dbl(EC_GROUP *group,EC_POINT *r,EC_POINT *a,BN_CTX *ctx)

{
  int iVar1;
  
  iVar1 = *(int *)group;
  if (*(code **)(iVar1 + 0x5c) == (code *)0x0) {
    ERR_put_error(0x10,0x73,0x42,"ec_lib.c",900);
  }
  else {
    if ((iVar1 == *(int *)r) && (iVar1 == *(int *)a)) {
                    /* WARNING: Could not recover jumptable at 0x0810066f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (**(code **)(iVar1 + 0x5c))();
      return iVar1;
    }
    ERR_put_error(0x10,0x73,0x65,"ec_lib.c",0x388);
  }
  return 0;
}

