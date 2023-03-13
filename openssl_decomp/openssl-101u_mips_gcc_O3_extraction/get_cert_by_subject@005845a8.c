
undefined4
get_cert_by_subject(X509_LOOKUP *param_1,int param_2,X509_NAME *param_3,undefined4 *param_4)

{
  uint uVar1;
  uint *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined4 uVar5;
  int iVar6;
  char *pcVar7;
  ulong uVar8;
  int iVar9;
  undefined4 *puVar10;
  int iVar11;
  undefined4 *puVar12;
  ulong *puVar13;
  uint uVar14;
  int *piVar15;
  undefined4 uVar16;
  char *pcVar17;
  ulong uVar18;
  int local_184;
  int local_174;
  int local_168;
  undefined **local_164;
  ulong local_160 [2];
  undefined auStack_158 [144];
  undefined *local_c8 [19];
  undefined auStack_7c [8];
  X509_NAME *local_74;
  undefined auStack_60 [20];
  X509_NAME *local_4c;
  int *local_2c;
  
  puVar4 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int **)PTR___stack_chk_guard_006a9ae8;
  if (param_3 != (X509_NAME *)0x0) {
    local_168 = param_2;
    if (param_2 == 1) {
      local_164 = local_c8;
      local_c8[0] = auStack_60;
      pcVar17 = "";
      local_4c = param_3;
      iVar6 = (*(code *)PTR_BUF_MEM_new_006a749c)();
      if (iVar6 != 0) goto LAB_005846b4;
LAB_00584bac:
      uVar16 = 7;
      uVar5 = 0x127;
    }
    else {
      if (param_2 == 2) {
        local_164 = local_c8;
        local_c8[0] = auStack_7c;
        pcVar17 = "r";
        local_74 = param_3;
        iVar6 = (*(code *)PTR_BUF_MEM_new_006a749c)();
        if (iVar6 == 0) goto LAB_00584bac;
LAB_005846b4:
        pcVar7 = param_1->method_data;
        uVar8 = X509_NAME_hash(param_3);
        local_184 = 0;
        iVar9 = (*(code *)PTR_sk_num_006a6e2c)(*(undefined4 *)(pcVar7 + 4));
        if (0 < iVar9) {
          do {
            puVar10 = (undefined4 *)
                      (*(code *)PTR_sk_value_006a6e24)(*(undefined4 *)(pcVar7 + 4),local_184);
            iVar9 = (*(code *)PTR_strlen_006a9a24)(*puVar10);
            iVar9 = (*(code *)PTR_BUF_MEM_grow_006a74a0)(iVar6,iVar9 + 0x11);
            if (iVar9 == 0) {
              uVar5 = 0;
              (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x67,0x41,"by_dir.c",0x135);
              goto LAB_00584878;
            }
            if (param_2 == 2) {
              if (puVar10[2] == 0) {
                local_174 = 0;
                uVar18 = 0;
              }
              else {
                local_160[0] = uVar8;
                (*(code *)PTR_CRYPTO_lock_006a8144)(5,0xb,"by_dir.c",0x13a);
                iVar9 = (*(code *)PTR_sk_find_006a8044)(puVar10[2],local_160);
                if (iVar9 < 0) {
                  local_174 = 0;
                  uVar18 = 0;
                }
                else {
                  local_174 = (*(code *)PTR_sk_value_006a6e24)(puVar10[2],iVar9);
                  uVar18 = *(ulong *)(local_174 + 4);
                }
                (*(code *)PTR_CRYPTO_lock_006a8144)(6,0xb,"by_dir.c",0x143);
              }
              while( true ) {
                (*(code *)PTR_BIO_snprintf_006a6f60)
                          (*(undefined4 *)(iVar6 + 4),*(undefined4 *)(iVar6 + 8),"%s%c%08lx.%s%d",
                           *puVar10,0x2f,uVar8,pcVar17,uVar18);
                iVar9 = (*(code *)PTR___xstat_006a9a84)(3,*(undefined4 *)(iVar6 + 4),auStack_158);
                if ((iVar9 < 0) ||
                   (iVar9 = X509_load_crl_file(param_1,*(char **)(iVar6 + 4),puVar10[1]), iVar9 == 0
                   )) break;
                uVar18 = uVar18 + 1;
              }
              (*(code *)PTR_CRYPTO_lock_006a8144)(9,0xb,"by_dir.c",0x17c);
              iVar9 = (*(code *)PTR_sk_find_006a8044)(param_1->store_ctx->objs,&local_168);
              if (iVar9 == -1) {
                puVar12 = (undefined4 *)0x0;
                (*(code *)PTR_CRYPTO_lock_006a8144)(10,0xb,"by_dir.c",0x182);
              }
              else {
                puVar12 = (undefined4 *)
                          (*(code *)PTR_sk_value_006a6e24)(param_1->store_ctx->objs,iVar9);
                (*(code *)PTR_CRYPTO_lock_006a8144)(10,0xb,"by_dir.c",0x182);
              }
              (*(code *)PTR_CRYPTO_lock_006a8144)(9,0xb,"by_dir.c",0x187);
              if ((local_174 == 0) &&
                 ((local_160[0] = uVar8,
                  iVar9 = (*(code *)PTR_sk_find_006a8044)(puVar10[2],local_160), iVar9 < 0 ||
                  (local_174 = (*(code *)PTR_sk_value_006a6e24)(puVar10[2],iVar9), local_174 == 0)))
                 ) {
                puVar13 = (ulong *)(*(code *)PTR_CRYPTO_malloc_006a7008)(8,"by_dir.c",0x193);
                uVar5 = puVar10[2];
                *puVar13 = uVar8;
                puVar3 = PTR_sk_push_006a6fa8;
                puVar13[1] = uVar18;
                iVar9 = (*(code *)puVar3)(uVar5,puVar13);
                if (iVar9 == 0) {
                  (*(code *)PTR_CRYPTO_lock_006a8144)(10,0xb,"by_dir.c",0x197);
                  uVar5 = 0;
                  (*(code *)PTR_CRYPTO_free_006a6e88)(puVar13);
                  goto LAB_00584878;
                }
              }
              else if (*(int *)(local_174 + 4) < (int)uVar18) {
                *(ulong *)(local_174 + 4) = uVar18;
              }
              (*(code *)PTR_CRYPTO_lock_006a8144)(10,0xb,"by_dir.c",0x19f);
joined_r0x00584a68:
              if (puVar12 != (undefined4 *)0x0) {
                uVar5 = 1;
                *param_4 = *puVar12;
                uVar14 = puVar12[1];
                uVar1 = (uint)(param_4 + 1) & 3;
                puVar2 = (uint *)((int)(param_4 + 1) - uVar1);
                *puVar2 = *puVar2 & -1 << (4 - uVar1) * 8 | uVar14 >> uVar1 * 8;
                uVar1 = (int)param_4 + 7U & 3;
                puVar2 = (uint *)(((int)param_4 + 7U) - uVar1);
                *puVar2 = *puVar2 & 0xffffffffU >> (uVar1 + 1) * 8 | uVar14 << (3 - uVar1) * 8;
                goto LAB_00584878;
              }
            }
            else {
              if (param_2 == 1) {
                iVar9 = 0;
                while( true ) {
                  (*(code *)PTR_BIO_snprintf_006a6f60)
                            (*(undefined4 *)(iVar6 + 4),*(undefined4 *)(iVar6 + 8),"%s%c%08lx.%s%d",
                             *puVar10,0x2f,uVar8,pcVar17,iVar9);
                  iVar11 = (*(code *)PTR___xstat_006a9a84)(3,*(undefined4 *)(iVar6 + 4),auStack_158)
                  ;
                  if ((iVar11 < 0) ||
                     (iVar11 = X509_load_cert_file(param_1,*(char **)(iVar6 + 4),puVar10[1]),
                     iVar11 == 0)) break;
                  iVar9 = iVar9 + 1;
                }
              }
              else {
                iVar9 = 0;
                while( true ) {
                  (*(code *)PTR_BIO_snprintf_006a6f60)
                            (*(undefined4 *)(iVar6 + 4),*(undefined4 *)(iVar6 + 8),"%s%c%08lx.%s%d",
                             *puVar10,0x2f,uVar8,pcVar17,iVar9);
                  iVar11 = (*(code *)PTR___xstat_006a9a84)(3,*(undefined4 *)(iVar6 + 4),auStack_158)
                  ;
                  if (iVar11 < 0) break;
                  iVar9 = iVar9 + 1;
                }
              }
              (*(code *)PTR_CRYPTO_lock_006a8144)(9,0xb,"by_dir.c",0x17c);
              iVar9 = (*(code *)PTR_sk_find_006a8044)(param_1->store_ctx->objs,&local_168);
              if (iVar9 != -1) {
                puVar12 = (undefined4 *)
                          (*(code *)PTR_sk_value_006a6e24)(param_1->store_ctx->objs,iVar9);
                (*(code *)PTR_CRYPTO_lock_006a8144)(10,0xb,"by_dir.c",0x182);
                goto joined_r0x00584a68;
              }
              (*(code *)PTR_CRYPTO_lock_006a8144)(10,0xb,"by_dir.c",0x182);
            }
            local_184 = local_184 + 1;
            iVar9 = (*(code *)PTR_sk_num_006a6e2c)(*(undefined4 *)(pcVar7 + 4));
          } while (local_184 < iVar9);
        }
        uVar5 = 0;
LAB_00584878:
        (*(code *)PTR_BUF_MEM_free_006a7494)(iVar6);
        goto LAB_00584644;
      }
      uVar16 = 0x70;
      uVar5 = 0x122;
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x67,uVar16,"by_dir.c",uVar5);
  }
  uVar5 = 0;
LAB_00584644:
  if (local_2c == *(int **)puVar4) {
    return uVar5;
  }
  piVar15 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (*piVar15 != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
  }
  if (piVar15[2] != 0) {
    (*(code *)PTR_sk_pop_free_006a7058)(piVar15[2],by_dir_hash_free);
  }
                    /* WARNING: Could not recover jumptable at 0x00584d10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar5 = (*(code *)PTR_CRYPTO_free_006a6e88)(piVar15);
  return uVar5;
}

