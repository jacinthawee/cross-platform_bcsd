
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
  
  iVar1 = (*(code *)PTR_sk_new_null_006a6fa4)();
  uVar2 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  iVar3 = (*(code *)PTR_BIO_new_006a6ea4)(uVar2);
  if ((iVar3 == 0) || (iVar4 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar3,0x6c,3,param_2), iVar4 < 1)) {
    local_34 = 3;
LAB_005c8e7c:
    if (iVar3 == 0) goto LAB_005c8e84;
  }
  else {
    iVar4 = (*(code *)PTR_TXT_DB_read_006a7bf0)(iVar3,6);
    if (iVar4 == 0) {
      local_34 = 1;
      goto LAB_005c8e7c;
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
LAB_005c8f64:
    iVar6 = (*(code *)PTR_sk_num_006a6e2c)(*(undefined4 *)(iVar4 + 4));
    if (iVar11 < iVar6) {
      ppcVar5 = (char **)(*(code *)PTR_sk_value_006a6e24)(*(undefined4 *)(iVar4 + 4),iVar11);
      if (**ppcVar5 == 'I') {
        piVar9 = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0xc,"srp_vfy.c",0x19c);
        if (piVar9 == (int *)0x0) goto LAB_005c8ee8;
        iVar6 = (*(code *)PTR_BUF_strdup_006a6fdc)(ppcVar5[3]);
        *piVar9 = iVar6;
        if (iVar6 == 0) {
LAB_005c8ec8:
          (*(code *)PTR_CRYPTO_free_006a6e88)(iVar6);
          (*(code *)PTR_CRYPTO_free_006a6e88)(piVar9);
          goto LAB_005c8ee8;
        }
        iVar7 = param_1[1];
        pcVar12 = ppcVar5[1];
        if (iVar7 == 0) {
LAB_005c9454:
          piVar9[2] = 0;
          goto LAB_005c8ec8;
        }
        iVar6 = 0;
        do {
          iVar10 = (*(code *)PTR_sk_num_006a6e2c)(iVar7);
          if (iVar10 <= iVar6) {
            puVar8 = (undefined4 *)SRP_gN_new_init(pcVar12);
            if (puVar8 != (undefined4 *)0x0) {
              iVar6 = (*(code *)PTR_sk_insert_006a87bc)(iVar7,puVar8,0);
              if (0 < iVar6) {
                iVar6 = puVar8[1];
                goto LAB_005c9204;
              }
              (*(code *)PTR_CRYPTO_free_006a6e88)(*puVar8);
              (*(code *)PTR_BN_free_006a701c)(puVar8[1]);
              (*(code *)PTR_CRYPTO_free_006a6e88)(puVar8);
            }
            iVar6 = *piVar9;
            goto LAB_005c9454;
          }
          puVar8 = (undefined4 *)(*(code *)PTR_sk_value_006a6e24)(iVar7,iVar6);
          iVar10 = (*(code *)PTR_strcmp_006a9b18)(*puVar8,pcVar12);
          iVar6 = iVar6 + 1;
        } while (iVar10 != 0);
        iVar6 = puVar8[1];
LAB_005c9204:
        piVar9[2] = iVar6;
        if (iVar6 == 0) {
LAB_005c8ec4:
          iVar6 = *piVar9;
          goto LAB_005c8ec8;
        }
        iVar6 = param_1[1];
        pcVar12 = ppcVar5[2];
        if (iVar6 == 0) {
LAB_005c9490:
          piVar9[1] = 0;
          iVar6 = *piVar9;
          goto LAB_005c8ec8;
        }
        iVar7 = 0;
        do {
          iVar10 = (*(code *)PTR_sk_num_006a6e2c)(iVar6);
          if (iVar10 <= iVar7) {
            puVar8 = (undefined4 *)SRP_gN_new_init(pcVar12);
            if (puVar8 == (undefined4 *)0x0) goto LAB_005c9490;
            iVar6 = (*(code *)PTR_sk_insert_006a87bc)(iVar6,puVar8,0);
            if (iVar6 < 1) {
              (*(code *)PTR_CRYPTO_free_006a6e88)(*puVar8);
              (*(code *)PTR_BN_free_006a701c)(puVar8[1]);
              (*(code *)PTR_CRYPTO_free_006a6e88)(puVar8);
              goto LAB_005c9490;
            }
            iVar6 = puVar8[1];
            goto LAB_005c92ac;
          }
          puVar8 = (undefined4 *)(*(code *)PTR_sk_value_006a6e24)(iVar6,iVar7);
          iVar10 = (*(code *)PTR_strcmp_006a9b18)(*puVar8,pcVar12);
          iVar7 = iVar7 + 1;
        } while (iVar10 != 0);
        iVar6 = puVar8[1];
LAB_005c92ac:
        piVar9[1] = iVar6;
        if (iVar6 == 0) goto LAB_005c8ec4;
        iVar6 = (*(code *)PTR_sk_insert_006a87bc)(iVar1,piVar9,0);
        if (iVar6 == 0) {
          iVar6 = *piVar9;
          goto LAB_005c8ec8;
        }
        if (param_1[2] == 0) goto LAB_005c8fb0;
        local_30 = ppcVar5[3];
        iVar11 = iVar11 + 1;
      }
      else {
        if (**ppcVar5 == 'V') {
          pcVar12 = ppcVar5[4];
          if (iVar1 != 0) {
            iVar6 = 0;
            if (pcVar12 == (char *)0x0) {
              for (; iVar7 = (*(code *)PTR_sk_num_006a6e2c)(iVar1), iVar6 < iVar7; iVar6 = iVar6 + 1
                  ) {
                puVar8 = (undefined4 *)(*(code *)PTR_sk_value_006a6e24)(iVar1,iVar6);
                if (puVar8 != (undefined4 *)0x0) goto LAB_005c905c;
              }
            }
            else {
              for (; iVar7 = (*(code *)PTR_sk_num_006a6e2c)(iVar1), iVar6 < iVar7; iVar6 = iVar6 + 1
                  ) {
                puVar8 = (undefined4 *)(*(code *)PTR_sk_value_006a6e24)(iVar1,iVar6);
                if ((puVar8 != (undefined4 *)0x0) &&
                   (iVar7 = (*(code *)PTR_strcmp_006a9b18)(*puVar8,pcVar12), iVar7 == 0))
                goto LAB_005c905c;
              }
            }
          }
          puVar8 = (undefined4 *)SRP_get_default_gN(pcVar12);
          if (puVar8 == (undefined4 *)0x0) {
            iVar11 = iVar11 + 1;
            goto LAB_005c8f64;
          }
LAB_005c905c:
          piVar9 = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x18,"srp_vfy.c",0xc9);
          if (piVar9 == (int *)0x0) {
            local_34 = 4;
            goto LAB_005c8ee8;
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
LAB_005c90c0:
            if (pcVar12 != (char *)0x0) {
              iVar6 = (*(code *)PTR_BUF_strdup_006a6fdc)(pcVar12);
              piVar9[5] = iVar6;
              if (iVar6 == 0) goto LAB_005c93ac;
            }
            iVar6 = SRP_user_pwd_set_sv_isra_4(piVar9 + 1,piVar9 + 2,ppcVar5[2],ppcVar5[1]);
            if ((iVar6 != 0) &&
               (iVar6 = (*(code *)PTR_sk_insert_006a87bc)(*param_1,piVar9,0), iVar6 != 0)) {
              iVar11 = iVar11 + 1;
              local_34 = 2;
              goto LAB_005c8f64;
            }
            local_34 = 2;
          }
          else {
            iVar6 = (*(code *)PTR_BUF_strdup_006a6fdc)();
            *piVar9 = iVar6;
            if (iVar6 != 0) goto LAB_005c90c0;
LAB_005c93ac:
            local_34 = 4;
          }
          (*(code *)PTR_BN_free_006a701c)(piVar9[1]);
          (*(code *)PTR_BN_clear_free_006a7fa8)(piVar9[2]);
          (*(code *)PTR_CRYPTO_free_006a6e88)(*piVar9);
          (*(code *)PTR_CRYPTO_free_006a6e88)(piVar9[5]);
          (*(code *)PTR_CRYPTO_free_006a6e88)(piVar9);
          goto LAB_005c8ee8;
        }
LAB_005c8fb0:
        iVar11 = iVar11 + 1;
      }
      goto LAB_005c8f64;
    }
    if (local_30 == (char *)0x0) {
      local_34 = 0;
    }
    else {
      iVar11 = 0;
      if (iVar1 == 0) {
LAB_005c94a0:
        puVar8 = (undefined4 *)SRP_get_default_gN(local_30);
        if (puVar8 == (undefined4 *)0x0) {
          local_34 = 2;
          goto LAB_005c8ee8;
        }
      }
      else {
        do {
          iVar6 = (*(code *)PTR_sk_num_006a6e2c)(iVar1);
          iVar7 = iVar11 + 1;
          if (iVar6 <= iVar11) goto LAB_005c94a0;
          puVar8 = (undefined4 *)(*(code *)PTR_sk_value_006a6e24)(iVar1,iVar11);
          iVar11 = iVar7;
        } while ((puVar8 == (undefined4 *)0x0) ||
                (iVar6 = (*(code *)PTR_strcmp_006a9b18)(*puVar8,local_30), iVar6 != 0));
      }
      uVar2 = puVar8[2];
      local_34 = 0;
      param_1[3] = puVar8[1];
      param_1[4] = uVar2;
    }
LAB_005c8ee8:
    (*(code *)PTR_TXT_DB_free_006a7bf4)(iVar4);
  }
  (*(code *)PTR_BIO_free_all_006a6e74)(iVar3);
LAB_005c8e84:
  (*(code *)PTR_sk_free_006a6e80)(iVar1);
  return local_34;
}

