
undefined4
dump_certs_pkeys_bags
          (undefined4 param_1,_STACK *param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    iVar2 = sk_num(param_2);
    if (iVar2 <= iVar3) {
      return 1;
    }
    pvVar1 = sk_value(param_2,iVar3);
    iVar2 = dump_certs_pkeys_bag(param_1,pvVar1,param_3,param_4,param_5,param_6);
    iVar3 = iVar3 + 1;
  } while (iVar2 != 0);
  return 0;
}

