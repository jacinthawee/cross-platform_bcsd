
int EC_POINTs_make_affine(EC_GROUP *group,size_t num,EC_POINT **points,BN_CTX *ctx)

{
  size_t sVar1;
  int iVar2;
  
  iVar2 = *(int *)group;
  if (*(code **)(iVar2 + 0x74) == (code *)0x0) {
    ERR_put_error(0x10,0x88,0x42,"ec_lib.c",0x405);
  }
  else {
    if (num == 0) {
LAB_0810248a:
                    /* WARNING: Could not recover jumptable at 0x081024a3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar2 = (**(code **)(iVar2 + 0x74))();
      return iVar2;
    }
    if (iVar2 == *(int *)*points) {
      sVar1 = 0;
      do {
        sVar1 = sVar1 + 1;
        if (num == sVar1) goto LAB_0810248a;
      } while (iVar2 == *(int *)points[sVar1]);
    }
    ERR_put_error(0x10,0x88,0x65,"ec_lib.c",0x40c);
  }
  return 0;
}

