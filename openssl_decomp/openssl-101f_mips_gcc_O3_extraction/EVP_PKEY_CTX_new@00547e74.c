
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
  undefined1 *unaff_s3;
  code *pcVar10;
  int *piStack_144;
  int aiStack_140 [27];
  int *piStack_d4;
  void **ppvStack_d0;
  EVP_PKEY *pEStack_cc;
  ENGINE *pEStack_c8;
  undefined1 *puStack_c4;
  undefined *puStack_c0;
  code *pcStack_bc;
  void ***local_94;
  void **local_90 [27];
  int local_24;
  
  puStack_c0 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  ppvVar7 = (void **)0x0;
  pEStack_cc = unaff_s1;
  if (pkey != (EVP_PKEY *)0x0) {
    pEStack_cc = pkey;
    if ((int **)pkey->ameth != (int **)0x0) {
      unaff_s0 = *(void ***)pkey->ameth;
      unaff_s2 = pkey->engine;
      if ((pkey->engine == (ENGINE *)0x0) && (unaff_s2 = e, e == (ENGINE *)0x0)) {
        unaff_s2 = (ENGINE *)(*(code *)PTR_ENGINE_get_pkey_meth_engine_006a9db4)(unaff_s0);
        if (unaff_s2 == (ENGINE *)0x0) {
          unaff_s3 = &_ITM_registerTMCloneTable;
          local_94 = local_90;
          local_90[0] = unaff_s0;
          if ((app_pkey_methods != (_STACK *)0x0) &&
             (iVar2 = sk_find(app_pkey_methods,local_94), -1 < iVar2)) {
            unaff_s3 = (undefined1 *)sk_value(app_pkey_methods,iVar2);
            goto LAB_00547ef8;
          }
          puVar3 = (undefined4 *)
                   (*(code *)PTR_OBJ_bsearch__006a9488)(&local_94,standard_methods,6,4);
          if (puVar3 != (undefined4 *)0x0) {
            unaff_s3 = (undefined1 *)*puVar3;
            goto LAB_00547ef8;
          }
        }
        else {
LAB_00547ee0:
          unaff_s3 = (undefined1 *)(*(code *)PTR_ENGINE_get_pkey_meth_006a9db0)(unaff_s2,unaff_s0);
LAB_00547ef8:
          if (unaff_s3 != (undefined1 *)0x0) {
            unaff_s0 = (void **)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x28,"pmeth_lib.c",0xa8);
            puVar1 = PTR_CRYPTO_add_lock_006a9080;
            if (unaff_s0 == (void **)0x0) {
              if (unaff_s2 != (ENGINE *)0x0) {
                (*(code *)PTR_ENGINE_finish_006a80c4)(unaff_s2);
              }
              e = (ENGINE *)&DAT_0000009d;
              ERR_put_error(6,0x9d,0x41,"pmeth_lib.c",0xaf);
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
                  (*(code *)PTR_ENGINE_finish_006a80c4)();
                }
                (*(code *)PTR_CRYPTO_free_006a7f88)(unaff_s0);
                ppvVar7 = (void **)0x0;
              }
            }
            goto LAB_00547f7c;
          }
        }
        iVar4 = 0x9c;
        iVar2 = 0xa4;
      }
      else {
        iVar2 = (*(code *)PTR_ENGINE_init_006a8e68)(unaff_s2);
        if (iVar2 != 0) goto LAB_00547ee0;
        iVar4 = 0x26;
        iVar2 = 0x91;
      }
      e = (ENGINE *)&DAT_0000009d;
      ERR_put_error(6,0x9d,iVar4,"pmeth_lib.c",iVar2);
    }
    ppvVar7 = (void **)0x0;
  }
LAB_00547f7c:
  if (local_24 == *(int *)puStack_c0) {
    return (EVP_PKEY_CTX *)ppvVar7;
  }
  pcStack_bc = EVP_PKEY_CTX_new_id;
  iVar2 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  piStack_d4 = *(int **)PTR___stack_chk_guard_006aabf0;
  ppvVar7 = (void **)0x0;
  ppvStack_d0 = unaff_s0;
  pEStack_c8 = unaff_s2;
  puStack_c4 = unaff_s3;
  if (iVar2 == -1) goto LAB_00548250;
  if (e == (ENGINE *)0x0) {
    e = (ENGINE *)(*(code *)PTR_ENGINE_get_pkey_meth_engine_006a9db4)();
    if (e != (ENGINE *)0x0) goto LAB_005481d4;
    piStack_144 = aiStack_140;
    aiStack_140[0] = iVar2;
    if ((app_pkey_methods == (_STACK *)0x0) ||
       (iVar2 = sk_find(app_pkey_methods,piStack_144), iVar2 < 0)) {
      ppvVar7 = (void **)(*(code *)PTR_OBJ_bsearch__006a9488)
                                   (&piStack_144,standard_methods,6,4,pmeth_cmp_BSEARCH_CMP_FN);
      if (ppvVar7 != (void **)0x0) {
        pvVar5 = *ppvVar7;
        goto LAB_005481ec;
      }
    }
    else {
      pvVar5 = sk_value(app_pkey_methods,iVar2);
LAB_005481ec:
      if (pvVar5 != (void *)0x0) {
        ppvVar7 = (void **)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x28,"pmeth_lib.c",0xa8);
        if (ppvVar7 == (void **)0x0) {
          if (e != (ENGINE *)0x0) {
            (*(code *)PTR_ENGINE_finish_006a80c4)(e);
          }
          ERR_put_error(6,0x9d,0x41,"pmeth_lib.c",0xaf);
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
              (*(code *)PTR_ENGINE_finish_006a80c4)();
            }
            (*(code *)PTR_CRYPTO_free_006a7f88)(ppvVar7);
            ppvVar7 = (void **)0x0;
          }
        }
        goto LAB_00548250;
      }
    }
    iVar4 = 0x9c;
    iVar2 = 0xa4;
  }
  else {
    iVar4 = (*(code *)PTR_ENGINE_init_006a8e68)(e);
    if (iVar4 != 0) {
LAB_005481d4:
      pvVar5 = (void *)(*(code *)PTR_ENGINE_get_pkey_meth_006a9db0)(e,iVar2);
      goto LAB_005481ec;
    }
    iVar4 = 0x26;
    iVar2 = 0x91;
  }
  ERR_put_error(6,0x9d,iVar4,"pmeth_lib.c",iVar2);
  ppvVar7 = (void **)0x0;
LAB_00548250:
  if (piStack_d4 == *(int **)puVar1) {
    return (EVP_PKEY_CTX *)ppvVar7;
  }
  piVar8 = piStack_d4;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if ((*piVar8 != 0) && (*(int *)(*piVar8 + 0xc) != 0)) {
    if ((piVar8[1] == 0) || (iVar2 = (*(code *)PTR_ENGINE_init_006a8e68)(), iVar2 != 0)) {
      piVar6 = (int *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x28,"pmeth_lib.c",0x140);
      if (piVar6 != (int *)0x0) {
        iVar2 = piVar8[1];
        iVar4 = piVar8[2];
        *piVar6 = *piVar8;
        piVar6[1] = iVar2;
        if (iVar4 != 0) {
          (*(code *)PTR_CRYPTO_add_lock_006a9080)(iVar4 + 8,1,10,"pmeth_lib.c",0x14a);
          iVar4 = piVar8[2];
        }
        iVar2 = piVar8[3];
        piVar6[2] = iVar4;
        if (iVar2 != 0) {
          (*(code *)PTR_CRYPTO_add_lock_006a9080)(iVar2 + 8,1,10,"pmeth_lib.c",0x14f);
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
          (*(code *)PTR_ENGINE_finish_006a80c4)();
        }
        (*(code *)PTR_CRYPTO_free_006a7f88)(piVar6);
        return (EVP_PKEY_CTX *)0x0;
      }
    }
    else {
      ERR_put_error(6,0x9c,0x26,"pmeth_lib.c",0x13c);
    }
    return (EVP_PKEY_CTX *)0x0;
  }
  return (EVP_PKEY_CTX *)0x0;
}

