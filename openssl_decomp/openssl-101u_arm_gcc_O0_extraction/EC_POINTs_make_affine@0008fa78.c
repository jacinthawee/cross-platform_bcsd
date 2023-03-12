
int EC_POINTs_make_affine(EC_GROUP *group,size_t num,EC_POINT **points,BN_CTX *ctx)

{
  size_t sVar1;
  int iVar2;
  
  iVar2 = *(int *)group;
  if (*(code **)(iVar2 + 0x74) == (code *)0x0) {
    ERR_put_error(0x10,0x88,0x42,"ec_lib.c",0x3df);
  }
  else {
    if (num == 0) {
LAB_0008faaa:
                    /* WARNING: Could not recover jumptable at 0x0008fab2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar2 = (**(code **)(iVar2 + 0x74))();
      return iVar2;
    }
    if (iVar2 == *(int *)*points) {
      sVar1 = 0;
      do {
        sVar1 = sVar1 + 1;
        if (sVar1 == num) goto LAB_0008faaa;
        points = (EC_POINT **)((int **)points + 1);
      } while (iVar2 == *(int *)*points);
    }
    ERR_put_error(0x10,0x88,0x65,"ec_lib.c",0x3e4);
  }
  return 0;
}

