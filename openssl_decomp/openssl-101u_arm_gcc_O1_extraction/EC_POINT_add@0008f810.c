
int EC_POINT_add(EC_GROUP *group,EC_POINT *r,EC_POINT *a,EC_POINT *b,BN_CTX *ctx)

{
  int iVar1;
  
  iVar1 = *(int *)group;
  if (*(code **)(iVar1 + 0x58) == (code *)0x0) {
    ERR_put_error(0x10,0x70,0x42,"ec_lib.c",0x375);
  }
  else {
    if (((iVar1 == *(int *)r) && (iVar1 == *(int *)a)) && (iVar1 == *(int *)b)) {
                    /* WARNING: Could not recover jumptable at 0x0008f85a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (**(code **)(iVar1 + 0x58))();
      return iVar1;
    }
    ERR_put_error(0x10,0x70,0x65,"ec_lib.c",0x37a);
  }
  return 0;
}

