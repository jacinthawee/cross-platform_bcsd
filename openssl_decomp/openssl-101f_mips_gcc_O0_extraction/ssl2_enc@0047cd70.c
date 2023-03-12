
void ssl2_enc(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x54);
  if (param_2 == 0) {
    piVar2 = *(int **)(param_1 + 0x80);
    iVar3 = *(int *)(iVar1 + 0x40);
  }
  else {
    piVar2 = *(int **)(param_1 + 0x8c);
    iVar3 = *(int *)(iVar1 + 0x48);
  }
  if (piVar2 != (int *)0x0) {
    if (*(int *)(*piVar2 + 4) == 8) {
                    /* WARNING: Could not recover jumptable at 0x0047cdd4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_EVP_Cipher_006a90b0)
                (piVar2,*(undefined4 *)(iVar1 + 0x58),*(undefined4 *)(iVar1 + 0x58),
                 iVar3 + 7U & 0xfffffff8);
      return;
    }
                    /* WARNING: Could not recover jumptable at 0x0047cda4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_EVP_Cipher_006a90b0)(piVar2,*(undefined4 *)(iVar1 + 0x58));
    return;
  }
  return;
}

