
undefined4 pkey_cb(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  
  if ((((param_1 == 2) && (piVar1 = *(int **)(*param_2 + 0xc), piVar1 != (int *)0x0)) &&
      (*piVar1 == 4)) && (puVar2 = (undefined4 *)piVar1[1], puVar2 != (undefined4 *)0x0)) {
    (*(code *)PTR_OPENSSL_cleanse_006a7074)(puVar2[2],*puVar2,param_3,param_4,&_gp);
    return 1;
  }
  return 1;
}

