
void ssl3_init_finished_mac(int param_1)

{
  undefined *UNRECOVERED_JUMPTABLE;
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 0x58);
  if (*(int *)(iVar5 + 0x178) != 0) {
    (*(code *)PTR_BIO_free_006a7f70)();
    iVar5 = *(int *)(param_1 + 0x58);
  }
  piVar2 = *(int **)(iVar5 + 0x17c);
  if (piVar2 != (int *)0x0) {
    iVar5 = 0;
    piVar3 = piVar2;
    do {
      iVar5 = iVar5 + 4;
      if (*piVar2 != 0) {
        (*(code *)PTR_EVP_MD_CTX_destroy_006a91c8)(*piVar2);
        piVar3 = *(int **)(*(int *)(param_1 + 0x58) + 0x17c);
      }
      piVar2 = (int *)((int)piVar3 + iVar5);
    } while (iVar5 != 0x18);
    (*(code *)PTR_CRYPTO_free_006a7f88)(piVar3);
    iVar5 = *(int *)(param_1 + 0x58);
    *(undefined4 *)(iVar5 + 0x17c) = 0;
  }
  uVar1 = (*(code *)PTR_BIO_s_mem_006a8d04)();
  uVar1 = (*(code *)PTR_BIO_new_006a7fa4)(uVar1);
  UNRECOVERED_JUMPTABLE = PTR_BIO_ctrl_006a7f18;
  iVar4 = *(int *)(param_1 + 0x58);
  *(undefined4 *)(iVar5 + 0x178) = uVar1;
                    /* WARNING: Could not recover jumptable at 0x0048c478. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)(*(undefined4 *)(iVar4 + 0x178),9,1,0);
  return;
}

