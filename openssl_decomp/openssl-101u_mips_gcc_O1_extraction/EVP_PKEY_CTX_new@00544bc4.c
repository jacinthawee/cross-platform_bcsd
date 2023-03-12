
EVP_PKEY_CTX * EVP_PKEY_CTX_new(EVP_PKEY *pkey,ENGINE *e)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  void *pvVar5;
  int *piVar6;
  void **ppvVar7;
  int *piVar8;
  int iVar9;
  void **unaff_s0;
  EVP_PKEY *unaff_s1;
  ENGINE *unaff_s2;
  undefined *unaff_s3;
  code *pcVar10;
  int *piStack_144;
  int aiStack_140 [27];
  int *piStack_d4;
  void **ppvStack_d0;
  EVP_PKEY *pEStack_cc;
  ENGINE *pEStack_c8;
  undefined *puStack_c4;
  undefined *puStack_c0;
  code *pcStack_bc;
  void ***local_94;
  void **local_90 [27];
  int local_24;
  
  puStack_c0 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  ppvVar7 = (void **)0x0;
  pEStack_cc = unaff_s1;
  if (pkey != (EVP_PKEY *)0x0) {
    pEStack_cc = pkey;
    if ((int **)pkey->ameth != (int **)0x0) {
      unaff_s0 = *(void ***)pkey->ameth;
      unaff_s2 = pkey->engine;
      if ((pkey->engine == (ENGINE *)0x0) && (unaff_s2 = e, e == (ENGINE *)0x0)) {
        unaff_s2 = (ENGINE *)(*(code *)PTR_ENGINE_get_pkey_meth_engine_006a8c94)(unaff_s0);
        if (unaff_s2 == (ENGINE *)0x0) {
          unaff_s3 = &_gp_1;
          local_94 = local_90;
          local_90[0] = unaff_s0;
          if ((app_pkey_methods != (_STACK *)0x0) &&
             (iVar2 = sk_find(app_pkey_methods,local_94), -1 < iVar2)) {
            unaff_s3 = (undefined *)sk_value(app_pkey_methods,iVar2);
            goto LAB_00544c48;
          }
          puVar3 = (undefined4 *)
                   (*(code *)PTR_OBJ_bsearch__006a8368)(&local_94,standard_methods,6,4);
          if (puVar3 != (undefined4 *)0x0) {
            unaff_s3 = (undefined *)*puVar3;
            goto LAB_00544c48;
          }
        }
        else {
LAB_00544c30:
          unaff_s3 = (undefined *)(*(code *)PTR_ENGINE_get_pkey_meth_006a8c90)(unaff_s2,unaff_s0);
LAB_00544c48:
          if (unaff_s3 != (undefined *)0x0) {
            unaff_s0 = (void **)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x28,"pmeth_lib.c",0xa4);
            puVar1 = PTR_CRYPTO_add_lock_006a805c;
            if (unaff_s0 == (void **)0x0) {
              if (unaff_s2 != (ENGINE *)0x0) {
                (*(code *)PTR_ENGINE_finish_006a6fc4)(unaff_s2);
              }
              e = (ENGINE *)0x9d;
              ERR_put_error(6,0x9d,0x41,"pmeth_lib.c",0xaa);
              ppvVar7 = (void **)0x0;
            }
            else {
              unaff_s0[1] = unaff_s2;
              *unaff_s0 = unaff_s3;
              e = (ENGINE *)0x1;
              unaff_s0[4] = (void *)0x0;
              unaff_s0[2] = pkey;
              unaff_s0[3] = (void *)0x0;
              unaff_s0[7] = (void *)0x0;
              (*(code *)puVar1)(&pkey->references,1,10,"pmeth_lib.c");
              pcVar10 = *(code **)(unaff_s3 + 8);
              unaff_s0[5] = (void *)0x0;
              ppvVar7 = unaff_s0;
              if ((pcVar10 != (code *)0x0) && (iVar2 = (*pcVar10)(unaff_s0), iVar2 < 1)) {
                if ((*unaff_s0 != (void *)0x0) &&
                   (pcVar10 = *(code **)((int)*unaff_s0 + 0x10), pcVar10 != (code *)0x0)) {
                  (*pcVar10)(unaff_s0);
                }
                if ((EVP_PKEY *)unaff_s0[2] != (EVP_PKEY *)0x0) {
                  EVP_PKEY_free((EVP_PKEY *)unaff_s0[2]);
                }
                if ((EVP_PKEY *)unaff_s0[3] != (EVP_PKEY *)0x0) {
                  EVP_PKEY_free((EVP_PKEY *)unaff_s0[3]);
                }
                if (unaff_s0[1] != (void *)0x0) {
                  (*(code *)PTR_ENGINE_finish_006a6fc4)();
                }
                (*(code *)PTR_CRYPTO_free_006a6e88)(unaff_s0);
                ppvVar7 = (void **)0x0;
              }
            }
            goto LAB_00544ccc;
          }
        }
        iVar4 = 0x9c;
        iVar2 = 0xa0;
      }
      else {
        iVar2 = (*(code *)PTR_ENGINE_init_006a7d78)(unaff_s2);
        if (iVar2 != 0) goto LAB_00544c30;
        iVar4 = 0x26;
        iVar2 = 0x8e;
      }
      e = (ENGINE *)0x9d;
      ERR_put_error(6,0x9d,iVar4,"pmeth_lib.c",iVar2);
    }
    ppvVar7 = (void **)0x0;
  }
LAB_00544ccc:
  if (local_24 == *(int *)puStack_c0) {
    return (EVP_PKEY_CTX *)ppvVar7;
  }
  pcStack_bc = EVP_PKEY_CTX_new_id;
  iVar2 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  piStack_d4 = *(int **)PTR___stack_chk_guard_006a9ae8;
  ppvVar7 = (void **)0x0;
  ppvStack_d0 = unaff_s0;
  pEStack_c8 = unaff_s2;
  puStack_c4 = unaff_s3;
  if (iVar2 == -1) goto LAB_00544fa0;
  if (e == (ENGINE *)0x0) {
    e = (ENGINE *)(*(code *)PTR_ENGINE_get_pkey_meth_engine_006a8c94)();
    if (e != (ENGINE *)0x0) goto LAB_00544f24;
    piStack_144 = aiStack_140;
    aiStack_140[0] = iVar2;
    if ((app_pkey_methods == (_STACK *)0x0) ||
       (iVar2 = sk_find(app_pkey_methods,piStack_144), iVar2 < 0)) {
      ppvVar7 = (void **)(*(code *)PTR_OBJ_bsearch__006a8368)
                                   (&piStack_144,standard_methods,6,4,pmeth_cmp_BSEARCH_CMP_FN);
      if (ppvVar7 != (void **)0x0) {
        pvVar5 = *ppvVar7;
        goto LAB_00544f3c;
      }
    }
    else {
      pvVar5 = sk_value(app_pkey_methods,iVar2);
LAB_00544f3c:
      if (pvVar5 != (void *)0x0) {
        ppvVar7 = (void **)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x28,"pmeth_lib.c",0xa4);
        if (ppvVar7 == (void **)0x0) {
          if (e != (ENGINE *)0x0) {
            (*(code *)PTR_ENGINE_finish_006a6fc4)(e);
          }
          ERR_put_error(6,0x9d,0x41,"pmeth_lib.c",0xaa);
          ppvVar7 = (void **)0x0;
        }
        else {
          pcVar10 = *(code **)((int)pvVar5 + 8);
          ppvVar7[1] = e;
          *ppvVar7 = pvVar5;
          ppvVar7[4] = (void *)0x0;
          ppvVar7[2] = (void *)0x0;
          ppvVar7[3] = (void *)0x0;
          ppvVar7[7] = (void *)0x0;
          ppvVar7[5] = (void *)0x0;
          if ((pcVar10 != (code *)0x0) && (iVar2 = (*pcVar10)(ppvVar7), iVar2 < 1)) {
            if ((*ppvVar7 != (void *)0x0) &&
               (pcVar10 = *(code **)((int)*ppvVar7 + 0x10), pcVar10 != (code *)0x0)) {
              (*pcVar10)(ppvVar7);
            }
            if ((EVP_PKEY *)ppvVar7[2] != (EVP_PKEY *)0x0) {
              EVP_PKEY_free((EVP_PKEY *)ppvVar7[2]);
            }
            if ((EVP_PKEY *)ppvVar7[3] != (EVP_PKEY *)0x0) {
              EVP_PKEY_free((EVP_PKEY *)ppvVar7[3]);
            }
            if (ppvVar7[1] != (void *)0x0) {
              (*(code *)PTR_ENGINE_finish_006a6fc4)();
            }
            (*(code *)PTR_CRYPTO_free_006a6e88)(ppvVar7);
            ppvVar7 = (void **)0x0;
          }
        }
        goto LAB_00544fa0;
      }
    }
    iVar4 = 0x9c;
    iVar2 = 0xa0;
  }
  else {
    iVar4 = (*(code *)PTR_ENGINE_init_006a7d78)(e);
    if (iVar4 != 0) {
LAB_00544f24:
      pvVar5 = (void *)(*(code *)PTR_ENGINE_get_pkey_meth_006a8c90)(e,iVar2);
      goto LAB_00544f3c;
    }
    iVar4 = 0x26;
    iVar2 = 0x8e;
  }
  ERR_put_error(6,0x9d,iVar4,"pmeth_lib.c",iVar2);
  ppvVar7 = (void **)0x0;
LAB_00544fa0:
  if (piStack_d4 == *(int **)puVar1) {
    return (EVP_PKEY_CTX *)ppvVar7;
  }
  piVar8 = piStack_d4;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if ((*piVar8 != 0) && (*(int *)(*piVar8 + 0xc) != 0)) {
    if ((piVar8[1] == 0) || (iVar2 = (*(code *)PTR_ENGINE_init_006a7d78)(), iVar2 != 0)) {
      piVar6 = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x28,"pmeth_lib.c",0x138);
      if (piVar6 != (int *)0x0) {
        iVar2 = piVar8[1];
        iVar4 = piVar8[2];
        *piVar6 = *piVar8;
        piVar6[1] = iVar2;
        if (iVar4 != 0) {
          (*(code *)PTR_CRYPTO_add_lock_006a805c)(iVar4 + 8,1,10,"pmeth_lib.c",0x142);
          iVar4 = piVar8[2];
        }
        iVar2 = piVar8[3];
        piVar6[2] = iVar4;
        if (iVar2 != 0) {
          (*(code *)PTR_CRYPTO_add_lock_006a805c)(iVar2 + 8,1,10,"pmeth_lib.c",0x147);
          iVar2 = piVar8[3];
        }
        iVar4 = *piVar8;
        iVar9 = piVar8[4];
        piVar6[3] = iVar2;
        piVar6[5] = 0;
        piVar6[6] = 0;
        piVar6[4] = iVar9;
        iVar2 = (**(code **)(iVar4 + 0xc))(piVar6,piVar8);
        if (0 < iVar2) {
          return (EVP_PKEY_CTX *)piVar6;
        }
        if ((*piVar6 != 0) && (pcVar10 = *(code **)(*piVar6 + 0x10), pcVar10 != (code *)0x0)) {
          (*pcVar10)(piVar6);
        }
        if ((EVP_PKEY *)piVar6[2] != (EVP_PKEY *)0x0) {
          EVP_PKEY_free((EVP_PKEY *)piVar6[2]);
        }
        if ((EVP_PKEY *)piVar6[3] != (EVP_PKEY *)0x0) {
          EVP_PKEY_free((EVP_PKEY *)piVar6[3]);
        }
        if (piVar6[1] != 0) {
          (*(code *)PTR_ENGINE_finish_006a6fc4)();
        }
        (*(code *)PTR_CRYPTO_free_006a6e88)(piVar6);
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

