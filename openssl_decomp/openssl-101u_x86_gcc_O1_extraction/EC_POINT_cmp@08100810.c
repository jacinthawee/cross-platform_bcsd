
int EC_POINT_cmp(EC_GROUP *group,EC_POINT *a,EC_POINT *b,BN_CTX *ctx)

{
  int iVar1;
  
  iVar1 = *(int *)group;
  if (*(code **)(iVar1 + 0x6c) == (code *)0x0) {
    ERR_put_error(0x10,0x71,0x42,"ec_lib.c",0x3c2);
  }
  else {
    if ((iVar1 == *(int *)a) && (iVar1 == *(int *)b)) {
                    /* WARNING: Could not recover jumptable at 0x08100847. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (**(code **)(iVar1 + 0x6c))();
      return iVar1;
    }
    ERR_put_error(0x10,0x71,0x65,"ec_lib.c",0x3c6);
  }
  return -1;
}

