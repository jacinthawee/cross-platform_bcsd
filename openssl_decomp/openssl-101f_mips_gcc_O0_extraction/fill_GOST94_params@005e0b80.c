
undefined4 fill_GOST94_params(int param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = *(int *)PTR_R3410_paramset_006aa708;
  piVar3 = (int *)PTR_R3410_paramset_006aa708;
  while( true ) {
    if (iVar2 == 0) {
      (*(code *)PTR_ERR_GOST_error_006aa6f0)(0x66,0x82,"gost_sign.c",0xdd);
      return 0;
    }
    if (param_2 == iVar2) break;
    piVar3 = piVar3 + 4;
    iVar2 = *piVar3;
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    (*(code *)PTR_BN_free_006a811c)();
  }
  puVar1 = PTR_BN_dec2bn_006a8f20;
  iVar2 = piVar3[2];
  *(undefined4 *)(param_1 + 0xc) = 0;
  (*(code *)puVar1)(param_1 + 0xc,iVar2);
  if (*(int *)(param_1 + 0x10) != 0) {
    (*(code *)PTR_BN_free_006a811c)();
  }
  puVar1 = PTR_BN_dec2bn_006a8f20;
  iVar2 = piVar3[3];
  *(undefined4 *)(param_1 + 0x10) = 0;
  (*(code *)puVar1)(param_1 + 0x10,iVar2);
  if (*(int *)(param_1 + 0x14) != 0) {
    (*(code *)PTR_BN_free_006a811c)();
  }
  puVar1 = PTR_BN_dec2bn_006a8f20;
  iVar2 = piVar3[1];
  *(undefined4 *)(param_1 + 0x14) = 0;
  (*(code *)puVar1)(param_1 + 0x14,iVar2);
  return 1;
}

