
uint check_policy(int param_1)

{
  int iVar1;
  void *pvVar2;
  uint uVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x7c) == 0) {
    iVar1 = X509_policy_check((X509_POLICY_TREE **)(param_1 + 0x58),(int *)(param_1 + 0x5c),
                              *(stack_st_X509 **)(param_1 + 0x54),
                              *(stack_st_ASN1_OBJECT **)(*(int *)(param_1 + 0x14) + 0x1c),
                              *(uint *)(*(int *)(param_1 + 0x14) + 0xc));
    if (iVar1 == 0) {
      ERR_put_error(0xb,0x91,0x41,"x509_vfy.c",0x631);
      *(undefined4 *)(param_1 + 100) = 0x11;
      return 0;
    }
    iVar4 = 1;
    if (iVar1 == -1) {
      for (; iVar1 = sk_num(*(_STACK **)(param_1 + 0x54)), iVar4 < iVar1; iVar4 = iVar4 + 1) {
        pvVar2 = sk_value(*(_STACK **)(param_1 + 0x54),iVar4);
        if ((*(byte *)((int)pvVar2 + 0x29) & 8) != 0) {
          *(void **)(param_1 + 0x68) = pvVar2;
          *(undefined4 *)(param_1 + 100) = 0x2a;
          iVar1 = (**(code **)(param_1 + 0x20))(0,param_1);
          if (iVar1 == 0) {
            return 0;
          }
        }
      }
    }
    else {
      if (iVar1 == -2) {
        *(undefined4 *)(param_1 + 0x68) = 0;
        *(undefined4 *)(param_1 + 100) = 0x2b;
        uVar3 = (**(code **)(param_1 + 0x20))(0,param_1);
        return uVar3;
      }
      if ((*(byte *)(*(int *)(param_1 + 0x14) + 0xd) & 8) != 0) {
        *(undefined4 *)(param_1 + 0x68) = 0;
        iVar1 = (**(code **)(param_1 + 0x20))(2,param_1);
        return (uint)(iVar1 != 0);
      }
    }
  }
  return 1;
}

