
int EC_POINTs_make_affine(EC_GROUP *group,size_t num,EC_POINT **points,BN_CTX *ctx)

{
  size_t sVar1;
  undefined4 uVar2;
  int **ppiVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  
  iVar6 = *(int *)group;
  if (*(code **)(iVar6 + 0x74) == (code *)0x0) {
    uVar4 = 0x42;
    uVar2 = 0x3df;
  }
  else {
    if (num == 0) {
LAB_005030a8:
                    /* WARNING: Could not recover jumptable at 0x005030ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar6 = (**(code **)(iVar6 + 0x74))();
      return iVar6;
    }
    ppiVar3 = (int **)(points + 1);
    if (iVar6 == *(int *)*points) {
      sVar1 = 0;
      do {
        sVar1 = sVar1 + 1;
        if (num == sVar1) goto LAB_005030a8;
        piVar5 = *ppiVar3;
        ppiVar3 = ppiVar3 + 1;
      } while (iVar6 == *piVar5);
    }
    uVar4 = 0x65;
    uVar2 = 0x3e4;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x88,uVar4,"ec_lib.c",uVar2);
  return 0;
}
