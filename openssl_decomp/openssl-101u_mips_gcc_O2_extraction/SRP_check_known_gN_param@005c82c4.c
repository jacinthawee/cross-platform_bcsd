
undefined4 SRP_check_known_gN_param(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    puVar3 = knowngN;
    iVar2 = 0;
    while ((iVar1 = (*(code *)PTR_BN_cmp_006a7960)(*(undefined4 *)(puVar3 + 4),param_1), iVar1 != 0
           || (iVar1 = (*(code *)PTR_BN_cmp_006a7960)(*(undefined4 *)(puVar3 + 8),param_2),
              iVar1 != 0))) {
      iVar2 = iVar2 + 1;
      puVar3 = puVar3 + 0xc;
      if (iVar2 == 7) {
        return 0;
      }
    }
    return *(undefined4 *)(knowngN + iVar2 * 0xc);
  }
  return 0;
}

