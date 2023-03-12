
undefined4
EC_GROUP_get_pentanomial_basis
          (EC_GROUP *param_1,int *param_2,undefined4 *param_3,undefined4 *param_4)

{
  EC_METHOD *meth;
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 != (EC_GROUP *)0x0) {
    meth = EC_GROUP_method_of(param_1);
    iVar1 = EC_METHOD_get_field_type(meth);
    if ((((iVar1 == 0x197) && (*(int *)(param_1 + 0x5c) != 0)) && (*(int *)(param_1 + 0x60) != 0))
       && (((*(int *)(param_1 + 100) != 0 && (*(int *)(param_1 + 0x68) != 0)) &&
           (*(int *)(param_1 + 0x6c) == 0)))) {
      if (param_2 != (int *)0x0) {
        *param_2 = *(int *)(param_1 + 0x68);
      }
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = *(undefined4 *)(param_1 + 100);
      }
      if (param_4 == (undefined4 *)0x0) {
        uVar2 = 1;
      }
      else {
        uVar2 = 1;
        *param_4 = *(undefined4 *)(param_1 + 0x60);
      }
    }
    else {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xc1,0x42,"ec_asn1.c",0x77);
      uVar2 = 0;
    }
    return uVar2;
  }
  return 0;
}

