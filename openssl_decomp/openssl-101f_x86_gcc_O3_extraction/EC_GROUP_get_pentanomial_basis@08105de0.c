
undefined4
EC_GROUP_get_pentanomial_basis
          (EC_GROUP *param_1,int *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  EC_METHOD *meth;
  int iVar2;
  
  uVar1 = 0;
  if (param_1 != (EC_GROUP *)0x0) {
    meth = EC_GROUP_method_of(param_1);
    iVar2 = EC_METHOD_get_field_type(meth);
    if ((((iVar2 == 0x197) && (*(int *)(param_1 + 0x5c) != 0)) && (*(int *)(param_1 + 0x60) != 0))
       && (((*(int *)(param_1 + 100) != 0 && (*(int *)(param_1 + 0x68) != 0)) &&
           (*(int *)(param_1 + 0x6c) == 0)))) {
      if (param_2 != (int *)0x0) {
        *param_2 = *(int *)(param_1 + 0x68);
      }
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = *(undefined4 *)(param_1 + 100);
      }
      if (param_4 == (undefined4 *)0x0) {
        uVar1 = 1;
      }
      else {
        *param_4 = *(undefined4 *)(param_1 + 0x60);
        uVar1 = 1;
      }
    }
    else {
      ERR_put_error(0x10,0xc1,0x42,"ec_asn1.c",0x73);
      uVar1 = 0;
    }
  }
  return uVar1;
}

