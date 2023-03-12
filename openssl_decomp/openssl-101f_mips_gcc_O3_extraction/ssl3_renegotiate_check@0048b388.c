
bool ssl3_renegotiate_check(int param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *(int *)(param_1 + 0x58);
  if (((*(int *)(iVar2 + 0x194) != 0) && (*(int *)(iVar2 + 0xf8) == 0)) &&
     (*(int *)(iVar2 + 0x108) == 0)) {
    uVar3 = (*(code *)PTR_SSL_state_006a88f4)();
    bVar1 = (uVar3 & 0x3000) == 0;
    if (bVar1) {
      iVar2 = *(int *)(param_1 + 0x58);
      *(undefined4 *)(param_1 + 0x34) = 0x3004;
      *(undefined4 *)(iVar2 + 0x194) = 0;
      *(int *)(iVar2 + 0x19c) = *(int *)(iVar2 + 0x19c) + 1;
      *(int *)(iVar2 + 0x198) = *(int *)(iVar2 + 0x198) + 1;
    }
    return bVar1;
  }
  return false;
}

