
void ssl3_free_digest_list(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar1 = *(int **)(*(int *)(param_1 + 0x58) + 0x17c);
  if (piVar1 != (int *)0x0) {
    iVar3 = 0;
    piVar2 = piVar1;
    do {
      iVar3 = iVar3 + 4;
      if (*piVar1 != 0) {
        (*(code *)PTR_EVP_MD_CTX_destroy_006a8088)(*piVar1);
        piVar2 = *(int **)(*(int *)(param_1 + 0x58) + 0x17c);
      }
      piVar1 = (int *)((int)piVar2 + iVar3);
    } while (iVar3 != 0x18);
    (*(code *)PTR_CRYPTO_free_006a6e88)(piVar2);
    *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x17c) = 0;
  }
  return;
}

