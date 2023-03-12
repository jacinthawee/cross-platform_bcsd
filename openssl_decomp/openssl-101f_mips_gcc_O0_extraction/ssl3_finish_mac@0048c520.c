
void ssl3_finish_mac(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  
  puVar1 = *(uint **)(param_1 + 0x58);
  if ((puVar1[0x5e] != 0) && ((*puVar1 & 0x20) == 0)) {
                    /* WARNING: Could not recover jumptable at 0x0048c5ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_BIO_write_006a7f14)(puVar1[0x5e]);
    return;
  }
  iVar3 = 0;
  while( true ) {
    piVar2 = (int *)(puVar1[0x5f] + iVar3);
    iVar3 = iVar3 + 4;
    if (*piVar2 != 0) {
      (*(code *)PTR_EVP_DigestUpdate_006a8674)(*piVar2,param_2,param_3);
    }
    if (iVar3 == 0x18) break;
    puVar1 = *(uint **)(param_1 + 0x58);
  }
  return;
}

