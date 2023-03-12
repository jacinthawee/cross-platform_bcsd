
bool rand_serial(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  if (param_1 == 0) {
    iVar1 = (*(code *)PTR_BN_new_006a71b4)();
    if (iVar1 == 0) {
      return false;
    }
    iVar2 = (*(code *)PTR_BN_pseudo_rand_006a7bec)(iVar1,0x40,0,0);
    if (iVar2 == 0) {
      bVar3 = false;
      goto LAB_0045cb28;
    }
    if (param_2 == 0) {
      bVar3 = true;
      goto LAB_0045cb28;
    }
  }
  else {
    iVar1 = (*(code *)PTR_BN_pseudo_rand_006a7bec)(param_1,0x40,0,0);
    if (iVar1 == 0) {
      return false;
    }
    iVar1 = param_1;
    if (param_2 == 0) {
      return true;
    }
  }
  iVar2 = (*(code *)PTR_BN_to_ASN1_INTEGER_006a70f4)(iVar1,param_2);
  bVar3 = iVar2 != 0;
  if (param_1 != 0) {
    return bVar3;
  }
LAB_0045cb28:
  (*(code *)PTR_BN_free_006a701c)(iVar1);
  return bVar3;
}

