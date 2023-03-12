
undefined4 SRP_VBASE_init(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  char **ppcVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  char *pcVar12;
  undefined4 local_34;
  char *local_30;
  
  iVar1 = (*(code *)PTR_sk_new_null_006a80a4)();
  uVar2 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  iVar3 = (*(code *)PTR_BIO_new_006a7fa4)(uVar2);
  if ((iVar3 == 0) || (iVar4 = (*(code *)PTR_BIO_ctrl_006a7f18)(iVar3,0x6c,3,param_2), iVar4 < 1)) {
    local_34 = 3;
LAB_005cb68c:
    if (iVar3 == 0) goto LAB_005cb694;
  }
  else {
    iVar4 = (*(code *)PTR_TXT_DB_read_006a8cdc)(iVar3,6);
    if (iVar4 == 0) {
      local_34 = 1;
      goto LAB_005cb68c;
    }
    if (param_1[2] == 0) {
      local_30 = (char *)0x0;
    }
    else {
      ppcVar5 = (char **)SRP_get_default_gN(0);
      local_30 = *ppcVar5;
    }
    iVar11 = 0;
    local_34 = 4;
LAB_005cb774:
    iVar6 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(iVar4 + 4));
    if (iVar11 < iVar6) {
      ppcVar5 = (char **)(*(code *)PTR_sk_value_006a7f24)(*(undefined4 *)(iVar4 + 4),iVar11);
      if (**ppcVar5 == 'I') {
        piVar9 = (int *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0xc,"srp_vfy.c",0x18e);
        if (piVar9 == (int *)0x0) goto LAB_005cb6f8;
        iVar6 = (*(code *)PTR_BUF_strdup_006a80dc)(ppcVar5[3]);
        *piVar9 = iVar6;
        if (iVar6 == 0) {
LAB_005cb6d8:
          (*(code *)PTR_CRYPTO_free_006a7f88)(iVar6);
          (*(code *)PTR_CRYPTO_free_006a7f88)(piVar9);
          goto LAB_005cb6f8;
        }
        iVar7 = param_1[1];
        pcVar12 = ppcVar5[1];
        if (iVar7 == 0) {
LAB_005cbc64:
          piVar9[2] = 0;
          goto LAB_005cb6d8;
        }
        iVar6 = 0;
        do {
          iVar10 = (*(code *)PTR_sk_num_006a7f2c)(iVar7);
          if (iVar10 <= iVar6) {
            puVar8 = (undefined4 *)SRP_gN_new_init(pcVar12);
            if (puVar8 != (undefined4 *)0x0) {
              iVar6 = (*(code *)PTR_sk_insert_006a98dc)(iVar7,puVar8,0);
              if (0 < iVar6) {
                iVar6 = puVar8[1];
                goto LAB_005cba14;
              }
              (*(code *)PTR_CRYPTO_free_006a7f88)(*puVar8);
              (*(code *)PTR_BN_free_006a811c)(puVar8[1]);
              (*(code *)PTR_CRYPTO_free_006a7f88)(puVar8);
            }
            iVar6 = *piVar9;
            goto LAB_005cbc64;
          }
          puVar8 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(iVar7,iVar6);
          iVar10 = (*(code *)PTR_strcmp_006aac20)(*puVar8,pcVar12);
          iVar6 = iVar6 + 1;
        } while (iVar10 != 0);
        iVar6 = puVar8[1];
LAB_005cba14:
        piVar9[2] = iVar6;
        if (iVar6 == 0) {
LAB_005cb6d4:
          iVar6 = *piVar9;
          goto LAB_005cb6d8;
        }
        iVar6 = param_1[1];
        pcVar12 = ppcVar5[2];
        if (iVar6 == 0) {
LAB_005cbca0:
          piVar9[1] = 0;
          iVar6 = *piVar9;
          goto LAB_005cb6d8;
        }
        iVar7 = 0;
        do {
          iVar10 = (*(code *)PTR_sk_num_006a7f2c)(iVar6);
          if (iVar10 <= iVar7) {
            puVar8 = (undefined4 *)SRP_gN_new_init(pcVar12);
            if (puVar8 == (undefined4 *)0x0) goto LAB_005cbca0;
            iVar6 = (*(code *)PTR_sk_insert_006a98dc)(iVar6,puVar8,0);
            if (iVar6 < 1) {
              (*(code *)PTR_CRYPTO_free_006a7f88)(*puVar8);
              (*(code *)PTR_BN_free_006a811c)(puVar8[1]);
              (*(code *)PTR_CRYPTO_free_006a7f88)(puVar8);
              goto LAB_005cbca0;
            }
            iVar6 = puVar8[1];
            goto LAB_005cbabc;
          }
          puVar8 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(iVar6,iVar7);
          iVar10 = (*(code *)PTR_strcmp_006aac20)(*puVar8,pcVar12);
          iVar7 = iVar7 + 1;
        } while (iVar10 != 0);
        iVar6 = puVar8[1];
LAB_005cbabc:
        piVar9[1] = iVar6;
        if (iVar6 == 0) goto LAB_005cb6d4;
        iVar6 = (*(code *)PTR_sk_insert_006a98dc)(iVar1,piVar9,0);
        if (iVar6 == 0) {
          iVar6 = *piVar9;
          goto LAB_005cb6d8;
        }
        if (param_1[2] == 0) goto LAB_005cb7c0;
        local_30 = ppcVar5[3];
        iVar11 = iVar11 + 1;
      }
      else {
        if (**ppcVar5 == 'V') {
          pcVar12 = ppcVar5[4];
          if (iVar1 != 0) {
            iVar6 = 0;
            if (pcVar12 == (char *)0x0) {
              for (; iVar7 = (*(code *)PTR_sk_num_006a7f2c)(iVar1), iVar6 < iVar7; iVar6 = iVar6 + 1
                  ) {
                puVar8 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(iVar1,iVar6);
                if (puVar8 != (undefined4 *)0x0) goto LAB_005cb86c;
              }
            }
            else {
              for (; iVar7 = (*(code *)PTR_sk_num_006a7f2c)(iVar1), iVar6 < iVar7; iVar6 = iVar6 + 1
                  ) {
                puVar8 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(iVar1,iVar6);
                if ((puVar8 != (undefined4 *)0x0) &&
                   (iVar7 = (*(code *)PTR_strcmp_006aac20)(*puVar8,pcVar12), iVar7 == 0))
                goto LAB_005cb86c;
              }
            }
          }
          puVar8 = (undefined4 *)SRP_get_default_gN(pcVar12);
          if (puVar8 == (undefined4 *)0x0) {
            iVar11 = iVar11 + 1;
            goto LAB_005cb774;
          }
LAB_005cb86c:
          piVar9 = (int *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x18,"srp_vfy.c",0xc3);
          if (piVar9 == (int *)0x0) {
            local_34 = 4;
            goto LAB_005cb6f8;
          }
          iVar6 = puVar8[1];
          iVar7 = puVar8[2];
          piVar9[1] = 0;
          piVar9[2] = 0;
          *piVar9 = 0;
          piVar9[5] = 0;
          piVar9[4] = iVar7;
          piVar9[3] = iVar6;
          pcVar12 = ppcVar5[5];
          if (ppcVar5[3] == (char *)0x0) {
LAB_005cb8d0:
            if (pcVar12 != (char *)0x0) {
              iVar6 = (*(code *)PTR_BUF_strdup_006a80dc)(pcVar12);
              piVar9[5] = iVar6;
              if (iVar6 == 0) goto LAB_005cbbbc;
            }
            iVar6 = SRP_user_pwd_set_sv_isra_4(piVar9 + 1,piVar9 + 2,ppcVar5[2],ppcVar5[1]);
            if ((iVar6 != 0) &&
               (iVar6 = (*(code *)PTR_sk_insert_006a98dc)(*param_1,piVar9,0), iVar6 != 0)) {
              iVar11 = iVar11 + 1;
              local_34 = 2;
              goto LAB_005cb774;
            }
            local_34 = 2;
          }
          else {
            iVar6 = (*(code *)PTR_BUF_strdup_006a80dc)();
            *piVar9 = iVar6;
            if (iVar6 != 0) goto LAB_005cb8d0;
LAB_005cbbbc:
            local_34 = 4;
          }
          (*(code *)PTR_BN_free_006a811c)(piVar9[1]);
          (*(code *)PTR_BN_clear_free_006a9130)(piVar9[2]);
          (*(code *)PTR_CRYPTO_free_006a7f88)(*piVar9);
          (*(code *)PTR_CRYPTO_free_006a7f88)(piVar9[5]);
          (*(code *)PTR_CRYPTO_free_006a7f88)(piVar9);
          goto LAB_005cb6f8;
        }
LAB_005cb7c0:
        iVar11 = iVar11 + 1;
      }
      goto LAB_005cb774;
    }
    if (local_30 == (char *)0x0) {
      local_34 = 0;
    }
    else {
      iVar11 = 0;
      if (iVar1 == 0) {
LAB_005cbcb0:
        puVar8 = (undefined4 *)SRP_get_default_gN(local_30);
        if (puVar8 == (undefined4 *)0x0) {
          local_34 = 2;
          goto LAB_005cb6f8;
        }
      }
      else {
        do {
          iVar6 = (*(code *)PTR_sk_num_006a7f2c)(iVar1);
          iVar7 = iVar11 + 1;
          if (iVar6 <= iVar11) goto LAB_005cbcb0;
          puVar8 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(iVar1,iVar11);
          iVar11 = iVar7;
        } while ((puVar8 == (undefined4 *)0x0) ||
                (iVar6 = (*(code *)PTR_strcmp_006aac20)(*puVar8,local_30), iVar6 != 0));
      }
      uVar2 = puVar8[2];
      local_34 = 0;
      param_1[3] = puVar8[1];
      param_1[4] = uVar2;
    }
LAB_005cb6f8:
    (*(code *)PTR_TXT_DB_free_006a8ce0)(iVar4);
  }
  (*(code *)PTR_BIO_free_all_006a7f74)(iVar3);
LAB_005cb694:
  (*(code *)PTR_sk_free_006a7f80)(iVar1);
  return local_34;
}

