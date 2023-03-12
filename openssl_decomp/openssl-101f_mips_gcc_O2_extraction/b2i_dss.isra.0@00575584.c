
int b2i_dss_isra_0(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined4 uVar5;
  undefined *puVar6;
  int iVar7;
  undefined *puVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  
  iVar9 = *param_1;
  iVar1 = (*(code *)PTR_DSA_new_006a8624)();
  iVar2 = (*(code *)PTR_EVP_PKEY_new_006a8710)();
  if (iVar1 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(9,0x7f,0x41,FUN_0066ce6c,0x167);
    if (iVar2 == 0) {
      return 0;
    }
LAB_00575820:
    iVar10 = 0;
  }
  else {
    if (iVar2 != 0) {
      uVar11 = param_2 + 7U >> 3;
      iVar10 = uVar11 - 1;
      puVar3 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a8108)(uVar11,FUN_0066ce6c,0x60);
      if (puVar3 != (undefined *)0x0) {
        puVar6 = puVar3;
        puVar8 = (undefined *)(iVar9 + iVar10);
        if (uVar11 != 0) {
          do {
            puVar4 = puVar6 + 1;
            *puVar6 = *puVar8;
            puVar6 = puVar4;
            puVar8 = puVar8 + -1;
          } while (puVar4 != puVar3 + uVar11);
        }
        uVar5 = (*(code *)PTR_BN_bin2bn_006a89f0)(puVar3,uVar11,0);
        puVar6 = PTR_CRYPTO_free_006a7f88;
        *(undefined4 *)(iVar1 + 0xc) = uVar5;
        (*(code *)puVar6)(puVar3);
        if (*(int *)(iVar1 + 0xc) != 0) {
          iVar9 = iVar9 + uVar11;
          puVar3 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x14,FUN_0066ce6c,0x60);
          if (puVar3 != (undefined *)0x0) {
            puVar6 = (undefined *)(iVar9 + 0x13);
            puVar8 = puVar3;
            do {
              puVar4 = puVar6 + -1;
              *puVar8 = *puVar6;
              puVar6 = puVar4;
              puVar8 = puVar8 + 1;
            } while ((undefined *)(iVar9 + -1) != puVar4);
            uVar5 = (*(code *)PTR_BN_bin2bn_006a89f0)(puVar3,0x14,0);
            puVar6 = PTR_CRYPTO_free_006a7f88;
            *(undefined4 *)(iVar1 + 0x10) = uVar5;
            (*(code *)puVar6)(puVar3);
            if (*(int *)(iVar1 + 0x10) != 0) {
              puVar3 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a8108)(uVar11,FUN_0066ce6c,0x60);
              if (puVar3 != (undefined *)0x0) {
                puVar6 = puVar3;
                puVar8 = (undefined *)(iVar9 + 0x14 + iVar10);
                if (uVar11 != 0) {
                  do {
                    puVar4 = puVar6 + 1;
                    *puVar6 = *puVar8;
                    puVar6 = puVar4;
                    puVar8 = puVar8 + -1;
                  } while (puVar4 != puVar3 + uVar11);
                }
                uVar5 = (*(code *)PTR_BN_bin2bn_006a89f0)(puVar3,uVar11,0);
                puVar6 = PTR_CRYPTO_free_006a7f88;
                *(undefined4 *)(iVar1 + 0x14) = uVar5;
                (*(code *)puVar6)(puVar3);
                if (*(int *)(iVar1 + 0x14) != 0) {
                  iVar9 = iVar9 + 0x14 + uVar11;
                  if (param_3 == 0) {
                    puVar3 = (undefined *)
                             (*(code *)PTR_CRYPTO_malloc_006a8108)(0x14,FUN_0066ce6c,0x60);
                    if (puVar3 != (undefined *)0x0) {
                      puVar6 = puVar3;
                      puVar8 = (undefined *)(iVar9 + 0x13);
                      do {
                        puVar4 = puVar8 + -1;
                        *puVar6 = *puVar8;
                        puVar6 = puVar6 + 1;
                        puVar8 = puVar4;
                      } while (puVar4 != (undefined *)(iVar9 + -1));
                      uVar5 = (*(code *)PTR_BN_bin2bn_006a89f0)(puVar3,0x14,0);
                      puVar6 = PTR_CRYPTO_free_006a7f88;
                      *(undefined4 *)(iVar1 + 0x1c) = uVar5;
                      (*(code *)puVar6)(puVar3);
                      if (*(int *)(iVar1 + 0x1c) != 0) {
                        iVar10 = (*(code *)PTR_BN_new_006a82b4)();
                        *(int *)(iVar1 + 0x18) = iVar10;
                        if ((iVar10 == 0) ||
                           (iVar10 = (*(code *)PTR_BN_CTX_new_006a8a38)(), iVar10 == 0))
                        goto LAB_00575878;
                        iVar7 = (*(code *)PTR_BN_mod_exp_006a8a48)
                                          (*(undefined4 *)(iVar1 + 0x18),
                                           *(undefined4 *)(iVar1 + 0x14),
                                           *(undefined4 *)(iVar1 + 0x1c),
                                           *(undefined4 *)(iVar1 + 0xc),iVar10);
                        if (iVar7 != 0) {
                          iVar9 = iVar9 + 0x14;
                          (*(code *)PTR_BN_CTX_free_006a8a40)(iVar10);
                          goto LAB_005759bc;
                        }
                        goto LAB_0057587c;
                      }
                    }
                  }
                  else {
                    puVar3 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a8108)(uVar11);
                    if (puVar3 != (undefined *)0x0) {
                      puVar6 = puVar3;
                      puVar8 = (undefined *)(iVar9 + iVar10);
                      if (uVar11 != 0) {
                        do {
                          puVar4 = puVar6 + 1;
                          *puVar6 = *puVar8;
                          puVar6 = puVar4;
                          puVar8 = puVar8 + -1;
                        } while (puVar4 != puVar3 + uVar11);
                      }
                      uVar5 = (*(code *)PTR_BN_bin2bn_006a89f0)(puVar3,uVar11,0);
                      puVar6 = PTR_CRYPTO_free_006a7f88;
                      iVar9 = iVar9 + uVar11;
                      *(undefined4 *)(iVar1 + 0x18) = uVar5;
                      (*(code *)puVar6)(puVar3);
                      if (*(int *)(iVar1 + 0x18) != 0) {
LAB_005759bc:
                        (*(code *)PTR_EVP_PKEY_set1_DSA_006a8758)(iVar2,iVar1);
                        (*(code *)PTR_DSA_free_006a862c)(iVar1);
                        *param_1 = iVar9;
                        return iVar2;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      (*(code *)PTR_ERR_put_error_006a9030)(9,0x7f,0x41,FUN_0066ce6c,0x167);
      (*(code *)PTR_DSA_free_006a862c)(iVar1);
      goto LAB_00575820;
    }
LAB_00575878:
    iVar10 = 0;
LAB_0057587c:
    (*(code *)PTR_ERR_put_error_006a9030)(9,0x7f,0x41,FUN_0066ce6c,0x167);
    (*(code *)PTR_DSA_free_006a862c)(iVar1);
    if (iVar2 == 0) goto LAB_00575830;
  }
  (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar2);
LAB_00575830:
  if (iVar10 != 0) {
    (*(code *)PTR_BN_CTX_free_006a8a40)(iVar10);
  }
  return 0;
}

