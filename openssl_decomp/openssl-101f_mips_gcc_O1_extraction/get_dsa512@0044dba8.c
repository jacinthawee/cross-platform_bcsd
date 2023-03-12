
int get_dsa512(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = (*(code *)PTR_DSA_new_006a8624)();
  if (iVar1 != 0) {
    uVar2 = (*(code *)PTR_BN_bin2bn_006a89f0)(dsa512_priv,0x14,0);
    *(undefined4 *)(iVar1 + 0x1c) = uVar2;
    uVar2 = (*(code *)PTR_BN_bin2bn_006a89f0)(dsa512_pub,0x41,0);
    *(undefined4 *)(iVar1 + 0x18) = uVar2;
    uVar2 = (*(code *)PTR_BN_bin2bn_006a89f0)(dsa512_p,0x40,0);
    *(undefined4 *)(iVar1 + 0xc) = uVar2;
    uVar2 = (*(code *)PTR_BN_bin2bn_006a89f0)(dsa512_q,0x14,0);
    *(undefined4 *)(iVar1 + 0x10) = uVar2;
    iVar3 = (*(code *)PTR_BN_bin2bn_006a89f0)(dsa512_g,0x40,0);
    *(int *)(iVar1 + 0x14) = iVar3;
    if ((((*(int *)(iVar1 + 0x1c) != 0) && (*(int *)(iVar1 + 0x18) != 0)) &&
        (*(int *)(iVar1 + 0xc) != 0)) && ((*(int *)(iVar1 + 0x10) != 0 && (iVar3 != 0)))) {
      return iVar1;
    }
  }
  return 0;
}

