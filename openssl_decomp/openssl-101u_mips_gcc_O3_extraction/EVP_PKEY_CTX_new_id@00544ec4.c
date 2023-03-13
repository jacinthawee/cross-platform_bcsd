
EVP_PKEY_CTX * EVP_PKEY_CTX_new_id(int id,ENGINE *e)

{
  undefined *puVar1;
  int iVar2;
  void *pvVar3;
  int *piVar4;
  void **ppvVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  code *pcVar9;
  int *local_8c;
  int local_88 [27];
  int *local_1c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int **)PTR___stack_chk_guard_006a9ae8;
  ppvVar5 = (void **)0x0;
  if (id == -1) goto LAB_00544fa0;
  if (e == (ENGINE *)0x0) {
    e = (ENGINE *)(*(code *)PTR_ENGINE_get_pkey_meth_engine_006a8c94)();
    if (e != (ENGINE *)0x0) goto LAB_00544f24;
    local_8c = local_88;
    local_88[0] = id;
    if ((app_pkey_methods == (_STACK *)0x0) ||
       (iVar2 = sk_find(app_pkey_methods,local_8c), iVar2 < 0)) {
      ppvVar5 = (void **)(*(code *)PTR_OBJ_bsearch__006a8368)
                                   (&local_8c,standard_methods,6,4,pmeth_cmp_BSEARCH_CMP_FN);
      if (ppvVar5 != (void **)0x0) {
        pvVar3 = *ppvVar5;
        goto LAB_00544f3c;
      }
    }
    else {
      pvVar3 = sk_value(app_pkey_methods,iVar2);
LAB_00544f3c:
      if (pvVar3 != (void *)0x0) {
        ppvVar5 = (void **)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x28,"pmeth_lib.c",0xa4);
        if (ppvVar5 == (void **)0x0) {
          if (e != (ENGINE *)0x0) {
            (*(code *)PTR_ENGINE_finish_006a6fc4)(e);
          }
          ERR_put_error(6,0x9d,0x41,"pmeth_lib.c",0xaa);
          ppvVar5 = (void **)0x0;
        }
        else {
          pcVar9 = *(code **)((int)pvVar3 + 8);
          ppvVar5[1] = e;
          *ppvVar5 = pvVar3;
          ppvVar5[4] = (void *)0x0;
          ppvVar5[2] = (void *)0x0;
          ppvVar5[3] = (void *)0x0;
          ppvVar5[7] = (void *)0x0;
          ppvVar5[5] = (void *)0x0;
          if ((pcVar9 != (code *)0x0) && (iVar2 = (*pcVar9)(ppvVar5), iVar2 < 1)) {
            if ((*ppvVar5 != (void *)0x0) &&
               (pcVar9 = *(code **)((int)*ppvVar5 + 0x10), pcVar9 != (code *)0x0)) {
              (*pcVar9)(ppvVar5);
            }
            if ((EVP_PKEY *)ppvVar5[2] != (EVP_PKEY *)0x0) {
              EVP_PKEY_free((EVP_PKEY *)ppvVar5[2]);
            }
            if ((EVP_PKEY *)ppvVar5[3] != (EVP_PKEY *)0x0) {
              EVP_PKEY_free((EVP_PKEY *)ppvVar5[3]);
            }
            if (ppvVar5[1] != (void *)0x0) {
              (*(code *)PTR_ENGINE_finish_006a6fc4)();
            }
            (*(code *)PTR_CRYPTO_free_006a6e88)(ppvVar5);
            ppvVar5 = (void **)0x0;
          }
        }
        goto LAB_00544fa0;
      }
    }
    iVar7 = 0x9c;
    iVar2 = 0xa0;
  }
  else {
    iVar2 = (*(code *)PTR_ENGINE_init_006a7d78)(e);
    if (iVar2 != 0) {
LAB_00544f24:
      pvVar3 = (void *)(*(code *)PTR_ENGINE_get_pkey_meth_006a8c90)(e,id);
      goto LAB_00544f3c;
    }
    iVar7 = 0x26;
    iVar2 = 0x8e;
  }
  ERR_put_error(6,0x9d,iVar7,"pmeth_lib.c",iVar2);
  ppvVar5 = (void **)0x0;
LAB_00544fa0:
  if (local_1c == *(int **)puVar1) {
    return (EVP_PKEY_CTX *)ppvVar5;
  }
  piVar6 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if ((*piVar6 != 0) && (*(int *)(*piVar6 + 0xc) != 0)) {
    if ((piVar6[1] == 0) || (iVar2 = (*(code *)PTR_ENGINE_init_006a7d78)(), iVar2 != 0)) {
      piVar4 = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x28,"pmeth_lib.c",0x138);
      if (piVar4 != (int *)0x0) {
        iVar2 = piVar6[1];
        iVar7 = piVar6[2];
        *piVar4 = *piVar6;
        piVar4[1] = iVar2;
        if (iVar7 != 0) {
          (*(code *)PTR_CRYPTO_add_lock_006a805c)(iVar7 + 8,1,10,"pmeth_lib.c",0x142);
          iVar7 = piVar6[2];
        }
        iVar2 = piVar6[3];
        piVar4[2] = iVar7;
        if (iVar2 != 0) {
          (*(code *)PTR_CRYPTO_add_lock_006a805c)(iVar2 + 8,1,10,"pmeth_lib.c",0x147);
          iVar2 = piVar6[3];
        }
        iVar7 = *piVar6;
        iVar8 = piVar6[4];
        piVar4[3] = iVar2;
        piVar4[5] = 0;
        piVar4[6] = 0;
        piVar4[4] = iVar8;
        iVar2 = (**(code **)(iVar7 + 0xc))(piVar4,piVar6);
        if (0 < iVar2) {
          return (EVP_PKEY_CTX *)piVar4;
        }
        if ((*piVar4 != 0) && (pcVar9 = *(code **)(*piVar4 + 0x10), pcVar9 != (code *)0x0)) {
          (*pcVar9)(piVar4);
        }
        if ((EVP_PKEY *)piVar4[2] != (EVP_PKEY *)0x0) {
          EVP_PKEY_free((EVP_PKEY *)piVar4[2]);
        }
        if ((EVP_PKEY *)piVar4[3] != (EVP_PKEY *)0x0) {
          EVP_PKEY_free((EVP_PKEY *)piVar4[3]);
        }
        if (piVar4[1] != 0) {
          (*(code *)PTR_ENGINE_finish_006a6fc4)();
        }
        (*(code *)PTR_CRYPTO_free_006a6e88)(piVar4);
        return (EVP_PKEY_CTX *)0x0;
      }
    }
    else {
      ERR_put_error(6,0x9c,0x26,"pmeth_lib.c",0x134);
    }
    return (EVP_PKEY_CTX *)0x0;
  }
  return (EVP_PKEY_CTX *)0x0;
}

