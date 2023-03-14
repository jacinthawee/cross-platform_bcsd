
int x509_name_ex_d2i(int **param_1,undefined4 *param_2,long param_3,undefined4 param_4,int param_5,
                    int param_6,char param_7,ASN1_TLC *param_8)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uchar ******ppppppuVar7;
  int *piVar8;
  uchar ******ppppppuVar9;
  uchar ******local_34;
  ASN1_VALUE *local_30;
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  if (0x100000 < param_3) {
    param_3 = 0x100000;
  }
  ppppppuVar9 = (uchar ******)*param_2;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  ppppppuVar7 = (uchar ******)&local_34;
  local_30 = (ASN1_VALUE *)0x0;
  local_34 = ppppppuVar9;
  iVar3 = ASN1_item_ex_d2i(&local_30,(uchar **)ppppppuVar7,param_3,
                           (ASN1_ITEM *)X509_NAME_INTERNAL_it,param_5,param_6,param_7,param_8);
  if (iVar3 < 1) goto LAB_00553928;
  piVar8 = *param_1;
  if (piVar8 != (int *)0x0) {
    (*(code *)PTR_BUF_MEM_free_006a7494)(piVar8[2]);
    (*(code *)PTR_sk_pop_free_006a7058)(*piVar8,X509_NAME_ENTRY_free);
    if (piVar8[3] != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(piVar8);
    *param_1 = (int *)0x0;
  }
  piVar8 = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x14,"x_name.c",0x8f);
  if (piVar8 == (int *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xab,0x41,"x_name.c",0x9d);
  }
  else {
    iVar3 = (*(code *)PTR_sk_new_null_006a6fa4)();
    *piVar8 = iVar3;
    if (iVar3 != 0) {
      iVar3 = (*(code *)PTR_BUF_MEM_new_006a749c)();
      piVar8[2] = iVar3;
      puVar1 = PTR_BUF_MEM_grow_006a74a0;
      if (iVar3 != 0) {
        piVar8[3] = 0;
        piVar8[4] = 0;
        piVar8[1] = 1;
        iVar3 = (*(code *)puVar1)(iVar3,(int)local_34 - (int)ppppppuVar9);
        if (iVar3 != 0) {
          (*(code *)PTR_memcpy_006a9aec)(*(undefined4 *)(piVar8[2] + 4));
          for (ppppppuVar7 = (uchar ******)0x0; iVar3 = (*(code *)PTR_sk_num_006a6e2c)(local_30),
              (int)ppppppuVar7 < iVar3; ppppppuVar7 = (uchar ******)((int)ppppppuVar7 + 1)) {
            ppppppuVar9 = ppppppuVar7;
            uVar4 = (*(code *)PTR_sk_value_006a6e24)(local_30);
            for (iVar3 = 0; iVar5 = (*(code *)PTR_sk_num_006a6e2c)(uVar4), iVar3 < iVar5;
                iVar3 = iVar3 + 1) {
              ppppppuVar9 = (uchar ******)(*(code *)PTR_sk_value_006a6e24)(uVar4,iVar3);
              puVar1 = PTR_sk_push_006a6fa8;
              iVar5 = *piVar8;
              ppppppuVar9[2] = (uchar *****)ppppppuVar7;
              iVar5 = (*(code *)puVar1)(iVar5);
              if (iVar5 == 0) goto LAB_005538e8;
            }
            (*(code *)PTR_sk_free_006a6e80)(uVar4);
          }
          (*(code *)PTR_sk_free_006a6e80)(local_30);
          ppppppuVar7 = ppppppuVar9;
          if (piVar8[3] != 0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
            piVar8[3] = 0;
            ppppppuVar7 = ppppppuVar9;
          }
          iVar3 = (*(code *)PTR_sk_num_006a6e2c)(*piVar8);
          if (iVar3 == 0) {
            iVar3 = 1;
            piVar8[4] = 0;
          }
          else {
            iVar3 = x509_name_canon_part_0(piVar8);
            if (iVar3 == 0) goto LAB_005538e8;
          }
          piVar8[1] = 0;
          *param_1 = piVar8;
          *param_2 = local_34;
          goto LAB_00553928;
        }
LAB_005538e8:
        ASN1_item_free((ASN1_VALUE *)piVar8,(ASN1_ITEM *)X509_NAME_it);
        goto LAB_00553900;
      }
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xab,0x41,"x_name.c",0x9d);
    if (*piVar8 != 0) {
      (*(code *)PTR_sk_free_006a6e80)();
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(piVar8);
  }
LAB_00553900:
  ppppppuVar7 = (uchar ******)&DAT_0000009e;
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x9e,0x3a,"x_name.c",0xf5);
  iVar3 = 0;
LAB_00553928:
  if (local_2c == *(int *)puVar2) {
    return iVar3;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  piVar8 = *(int **)PTR___stack_chk_guard_006a9ae8;
  uVar6 = (uint)X509_NAME_ENTRY_it[0];
  if (X509_NAME_ENTRY_it._16_4_ == 0) {
    if (uVar6 < 7) {
                    /* WARNING: Could not recover jumptable at 0x005619f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar3 = (*(code *)(&switchD_005619f8::switchdataD_0066a17c)[uVar6])();
      return iVar3;
    }
  }
  else if (uVar6 < 7) {
                    /* WARNING: Could not recover jumptable at 0x00561550. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar3 = (*(code *)(&switchD_00561550::switchdataD_0066a160)[uVar6])();
    return iVar3;
  }
  if (piVar8 == *(int **)PTR___stack_chk_guard_006a9ae8) {
    return 0;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  return *(int *)((int)ppppppuVar7[1] + *piVar8);
}
