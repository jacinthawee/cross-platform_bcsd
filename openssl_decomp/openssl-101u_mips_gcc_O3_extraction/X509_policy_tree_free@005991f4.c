
void X509_policy_tree_free(X509_POLICY_TREE *tree)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  if (tree != (X509_POLICY_TREE *)0x0) {
    iVar3 = 0;
    (*(code *)PTR_sk_free_006a6e80)(*(undefined4 *)(tree + 0xc));
    (*(code *)PTR_sk_pop_free_006a7058)(*(undefined4 *)(tree + 0x10),exnode_free);
    piVar2 = *(int **)tree;
    if (0 < *(int *)(tree + 4)) {
      do {
        iVar3 = iVar3 + 1;
        if (*piVar2 != 0) {
          (*(code *)PTR_X509_free_006a6e90)();
        }
        if (piVar2[1] != 0) {
          (*(code *)PTR_sk_pop_free_006a7058)(piVar2[1],PTR_policy_node_free_006a90b8);
        }
        piVar1 = piVar2 + 2;
        piVar2 = piVar2 + 4;
        if (*piVar1 != 0) {
          (*(code *)PTR_policy_node_free_006a90b8)();
        }
      } while (iVar3 < *(int *)(tree + 4));
    }
    if (*(int *)(tree + 8) != 0) {
      (*(code *)PTR_sk_pop_free_006a7058)(*(int *)(tree + 8),PTR_policy_data_free_006a9098);
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(*(undefined4 *)tree);
                    /* WARNING: Could not recover jumptable at 0x00599300. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a6e88)(tree);
    return;
  }
  return;
}

