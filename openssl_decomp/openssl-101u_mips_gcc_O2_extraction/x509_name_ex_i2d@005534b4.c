
undefined1 * x509_name_ex_i2d(undefined4 *param_1,int *param_2,undefined1 *param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  int *piVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  ASN1_VALUE *pAVar9;
  int **ppiVar10;
  code *pcVar11;
  uchar *******pppppppuVar12;
  undefined1 *unaff_s0;
  int unaff_s1;
  uchar *******pppppppuVar13;
  ASN1_VALUE **unaff_s2;
  int unaff_s4;
  uchar *******pppppppuStack_84;
  ASN1_VALUE *pAStack_80;
  int iStack_7c;
  undefined1 *puStack_74;
  int iStack_70;
  ASN1_VALUE **ppAStack_6c;
  undefined4 *puStack_68;
  int iStack_64;
  int *piStack_60;
  undefined *puStack_5c;
  int in_stack_ffffffc0;
  int iStack_3c;
  ASN1_TLC *pAStack_34;
  ASN1_VALUE *local_2c;
  uchar *local_28;
  int **local_24;
  
  puStack_5c = PTR___stack_chk_guard_006a9ae8;
  puStack_68 = (undefined4 *)*param_1;
  local_24 = *(int ***)PTR___stack_chk_guard_006a9ae8;
  pcVar11 = (code *)param_2;
  if (puStack_68[1] == 0) {
LAB_00553504:
    piVar3 = (int *)puStack_68[2];
    unaff_s0 = (undefined1 *)*piVar3;
joined_r0x005536e4:
    puVar4 = unaff_s0;
    if (param_2 != (int *)0x0) {
      pcVar11 = (code *)piVar3[1];
      param_3 = unaff_s0;
      (*(code *)PTR_memcpy_006a9aec)(*param_2);
      iVar8 = *param_2;
      *param_2 = (int)(unaff_s0 + iVar8);
      unaff_s0 = unaff_s0 + iVar8;
    }
  }
  else {
    local_2c = (ASN1_VALUE *)0x0;
    local_2c = (ASN1_VALUE *)(*(code *)PTR_sk_new_null_006a6fa4)();
    if (local_2c == (ASN1_VALUE *)0x0) {
      pAVar9 = (ASN1_VALUE *)0x0;
    }
    else {
      unaff_s4 = -1;
      unaff_s2 = (ASN1_VALUE **)0x0;
      for (unaff_s0 = (undefined1 *)0x0; iVar8 = (*(code *)PTR_sk_num_006a6e2c)(*puStack_68),
          (int)unaff_s0 < iVar8; unaff_s0 = unaff_s0 + 1) {
        unaff_s1 = (*(code *)PTR_sk_value_006a6e24)(*puStack_68,unaff_s0);
        if (*(int *)(unaff_s1 + 8) != unaff_s4) {
          unaff_s2 = (ASN1_VALUE **)(*(code *)PTR_sk_new_null_006a6fa4)();
          pAVar9 = local_2c;
          if ((unaff_s2 == (ASN1_VALUE **)0x0) ||
             (iVar8 = (*(code *)PTR_sk_push_006a6fa8)(local_2c,unaff_s2), pAVar9 = local_2c,
             iVar8 == 0)) goto LAB_005536f8;
          unaff_s4 = *(int *)(unaff_s1 + 8);
        }
        iVar8 = (*(code *)PTR_sk_push_006a6fa8)(unaff_s2,unaff_s1);
        pAVar9 = local_2c;
        if (iVar8 == 0) goto LAB_005536f8;
      }
      unaff_s1 = -1;
      unaff_s4 = 0x690000;
      unaff_s2 = &local_2c;
      unaff_s0 = (undefined1 *)
                 ASN1_item_ex_i2d(unaff_s2,(uchar **)0x0,(ASN1_ITEM *)X509_NAME_INTERNAL_it,-1,-1);
      iVar8 = (*(code *)PTR_BUF_MEM_grow_006a74a0)(puStack_68[2],unaff_s0);
      pAVar9 = local_2c;
      if (iVar8 != 0) {
        param_3 = X509_NAME_INTERNAL_it;
        local_28 = *(uchar **)(puStack_68[2] + 4);
        in_stack_ffffffc0 = -1;
        ASN1_item_ex_i2d(unaff_s2,&local_28,(ASN1_ITEM *)X509_NAME_INTERNAL_it,-1,-1);
        pcVar11 = local_sk_X509_NAME_ENTRY_free;
        (*(code *)PTR_sk_pop_free_006a7058)(local_2c);
        puStack_68[1] = 0;
        puVar4 = unaff_s0;
        if (-1 < (int)unaff_s0) {
          if (puStack_68[3] != 0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
            puStack_68[3] = 0;
          }
          iVar8 = (*(code *)PTR_sk_num_006a6e2c)(*puStack_68);
          if (iVar8 == 0) {
            piVar3 = (int *)puStack_68[2];
            puStack_68[4] = 0;
            unaff_s0 = (undefined1 *)*piVar3;
            goto joined_r0x005536e4;
          }
          puVar4 = (undefined1 *)x509_name_canon_part_0(puStack_68);
          if (-1 < (int)puVar4) goto LAB_00553504;
        }
        goto LAB_00553538;
      }
    }
LAB_005536f8:
    (*(code *)PTR_sk_pop_free_006a7058)(pAVar9,local_sk_X509_NAME_ENTRY_free);
    param_3 = (undefined1 *)0x41;
    in_stack_ffffffc0 = 0x143;
    pcVar11 = (code *)0xcb;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xcb,0x41,"x_name.c");
    puVar4 = (undefined1 *)0xffffffff;
  }
LAB_00553538:
  if (local_24 == *(int ***)puStack_5c) {
    return puVar4;
  }
  ppiVar10 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  if (0x100000 < (int)param_3) {
    param_3 = (undefined1 *)0x100000;
  }
  pppppppuVar13 = *(uchar ********)pcVar11;
  iStack_7c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pppppppuVar12 = (uchar *******)&pppppppuStack_84;
  pAStack_80 = (ASN1_VALUE *)0x0;
  pppppppuStack_84 = pppppppuVar13;
  puStack_74 = unaff_s0;
  iStack_70 = unaff_s1;
  ppAStack_6c = unaff_s2;
  iStack_64 = unaff_s4;
  piStack_60 = param_2;
  puVar4 = (undefined1 *)
           ASN1_item_ex_d2i(&pAStack_80,(uchar **)pppppppuVar12,(long)param_3,
                            (ASN1_ITEM *)X509_NAME_INTERNAL_it,in_stack_ffffffc0,iStack_3c,-0x20,
                            pAStack_34);
  if ((int)puVar4 < 1) goto LAB_00553928;
  piVar3 = *ppiVar10;
  if (piVar3 != (int *)0x0) {
    (*(code *)PTR_BUF_MEM_free_006a7494)(piVar3[2]);
    (*(code *)PTR_sk_pop_free_006a7058)(*piVar3,X509_NAME_ENTRY_free);
    if (piVar3[3] != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(piVar3);
    *ppiVar10 = (int *)0x0;
  }
  piVar3 = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x14,"x_name.c",0x8f);
  if (piVar3 == (int *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xab,0x41,"x_name.c",0x9d);
  }
  else {
    iVar8 = (*(code *)PTR_sk_new_null_006a6fa4)();
    *piVar3 = iVar8;
    if (iVar8 != 0) {
      iVar8 = (*(code *)PTR_BUF_MEM_new_006a749c)();
      piVar3[2] = iVar8;
      puVar1 = PTR_BUF_MEM_grow_006a74a0;
      if (iVar8 != 0) {
        piVar3[3] = 0;
        piVar3[4] = 0;
        piVar3[1] = 1;
        iVar8 = (*(code *)puVar1)(iVar8,(int)pppppppuStack_84 - (int)pppppppuVar13);
        if (iVar8 != 0) {
          (*(code *)PTR_memcpy_006a9aec)(*(undefined4 *)(piVar3[2] + 4));
          for (pppppppuVar12 = (uchar *******)0x0;
              iVar8 = (*(code *)PTR_sk_num_006a6e2c)(pAStack_80), (int)pppppppuVar12 < iVar8;
              pppppppuVar12 = (uchar *******)((int)pppppppuVar12 + 1)) {
            pppppppuVar13 = pppppppuVar12;
            uVar5 = (*(code *)PTR_sk_value_006a6e24)(pAStack_80);
            for (iVar8 = 0; iVar6 = (*(code *)PTR_sk_num_006a6e2c)(uVar5), iVar8 < iVar6;
                iVar8 = iVar8 + 1) {
              pppppppuVar13 = (uchar *******)(*(code *)PTR_sk_value_006a6e24)(uVar5,iVar8);
              puVar1 = PTR_sk_push_006a6fa8;
              iVar6 = *piVar3;
              pppppppuVar13[2] = (uchar ******)pppppppuVar12;
              iVar6 = (*(code *)puVar1)(iVar6);
              if (iVar6 == 0) goto LAB_005538e8;
            }
            (*(code *)PTR_sk_free_006a6e80)(uVar5);
          }
          (*(code *)PTR_sk_free_006a6e80)(pAStack_80);
          pppppppuVar12 = pppppppuVar13;
          if (piVar3[3] != 0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
            piVar3[3] = 0;
            pppppppuVar12 = pppppppuVar13;
          }
          iVar8 = (*(code *)PTR_sk_num_006a6e2c)(*piVar3);
          if (iVar8 == 0) {
            puVar4 = (undefined1 *)0x1;
            piVar3[4] = 0;
          }
          else {
            puVar4 = (undefined1 *)x509_name_canon_part_0(piVar3);
            if (puVar4 == (undefined1 *)0x0) goto LAB_005538e8;
          }
          piVar3[1] = 0;
          *ppiVar10 = piVar3;
          *(uchar ********)pcVar11 = pppppppuStack_84;
          goto LAB_00553928;
        }
LAB_005538e8:
        ASN1_item_free((ASN1_VALUE *)piVar3,(ASN1_ITEM *)X509_NAME_it);
        goto LAB_00553900;
      }
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xab,0x41,"x_name.c",0x9d);
    if (*piVar3 != 0) {
      (*(code *)PTR_sk_free_006a6e80)();
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(piVar3);
  }
LAB_00553900:
  pppppppuVar12 = (uchar *******)&DAT_0000009e;
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x9e,0x3a,"x_name.c",0xf5);
  puVar4 = (undefined1 *)0x0;
LAB_00553928:
  if (iStack_7c == *(int *)puVar2) {
    return puVar4;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  piVar3 = *(int **)PTR___stack_chk_guard_006a9ae8;
  uVar7 = (uint)X509_NAME_ENTRY_it[0];
  if (X509_NAME_ENTRY_it._16_4_ == 0) {
    if (uVar7 < 7) {
                    /* WARNING: Could not recover jumptable at 0x005619f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      puVar4 = (undefined1 *)(*(code *)(&switchD_005619f8::switchdataD_0066a17c)[uVar7])();
      return puVar4;
    }
  }
  else if (uVar7 < 7) {
                    /* WARNING: Could not recover jumptable at 0x00561550. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    puVar4 = (undefined1 *)(*(code *)(&switchD_00561550::switchdataD_0066a160)[uVar7])();
    return puVar4;
  }
  if (piVar3 != *(int **)PTR___stack_chk_guard_006a9ae8) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    return *(undefined1 **)((int)pppppppuVar12[1] + *piVar3);
  }
  return (undefined1 *)0x0;
}
