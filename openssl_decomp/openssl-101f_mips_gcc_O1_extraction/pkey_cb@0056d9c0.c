
undefined4 pkey_cb(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  
  if ((param_1 == 2) &&
     (puVar1 = *(undefined4 **)(*(int *)(*param_2 + 0xc) + 4), puVar1 != (undefined4 *)0x0)) {
    (*(code *)PTR_OPENSSL_cleanse_006a8174)(puVar1[2],*puVar1,param_3,param_4,&_gp);
    return 1;
  }
  return 1;
}

