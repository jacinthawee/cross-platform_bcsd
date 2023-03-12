
undefined4 def_crl_lookup(int *param_1,int *param_2,ASN1_INTEGER *param_3,int param_4)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  ASN1_INTEGER **ppAVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  uint uVar8;
  ASN1_INTEGER *pAVar9;
  ASN1_INTEGER *pAVar10;
  ASN1_INTEGER local_44;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_44.length = (int)param_3;
  iVar2 = (*(code *)PTR_sk_is_sorted_006a8d34)(*(undefined4 *)(*param_1 + 0x14));
  if (iVar2 == 0) {
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,6,"x_crl.c",0x1b8);
    (*(code *)PTR_sk_sort_006a83bc)(*(undefined4 *)(*param_1 + 0x14));
    (*(code *)PTR_CRYPTO_lock_006a8144)(10,6,"x_crl.c",0x1ba);
  }
  pAVar9 = &local_44;
  iVar2 = (*(code *)PTR_sk_find_006a8044)(*(undefined4 *)(*param_1 + 0x14));
  if ((-1 < iVar2) &&
     (iVar3 = (*(code *)PTR_sk_num_006a6e2c)(*(undefined4 *)(*param_1 + 0x14)), iVar2 < iVar3)) {
    while( true ) {
      ppAVar4 = (ASN1_INTEGER **)
                (*(code *)PTR_sk_value_006a6e24)(*(undefined4 *)(*param_1 + 0x14),iVar2);
      pAVar9 = param_3;
      iVar3 = ASN1_INTEGER_cmp(*ppAVar4,param_3);
      if (iVar3 != 0) break;
      if (ppAVar4[3] == (ASN1_INTEGER *)0x0) {
        if (param_4 != 0) {
          pAVar9 = *(ASN1_INTEGER **)(*param_1 + 8);
          iVar3 = (*(code *)PTR_X509_NAME_cmp_006a8030)(param_4);
          if (iVar3 != 0) goto LAB_00554f40;
        }
LAB_00554fb8:
        if (param_2 != (int *)0x0) {
          *param_2 = (int)ppAVar4;
        }
        uVar7 = 2;
        if (ppAVar4[4] != (ASN1_INTEGER *)&DAT_00000008) {
          uVar7 = 1;
        }
        goto LAB_00554f60;
      }
      iVar3 = param_4;
      if (param_4 == 0) {
        iVar3 = *(int *)(*param_1 + 8);
      }
      pAVar10 = (ASN1_INTEGER *)0x0;
      iVar5 = (*(code *)PTR_sk_num_006a6e2c)();
      if (0 < iVar5) {
        do {
          pAVar9 = pAVar10;
          piVar6 = (int *)(*(code *)PTR_sk_value_006a6e24)(ppAVar4[3]);
          if (*piVar6 == 4) {
            pAVar9 = (ASN1_INTEGER *)piVar6[1];
            iVar5 = (*(code *)PTR_X509_NAME_cmp_006a8030)(iVar3);
            if (iVar5 == 0) goto LAB_00554fb8;
          }
          pAVar10 = (ASN1_INTEGER *)((int)&pAVar10->length + 1);
          iVar5 = (*(code *)PTR_sk_num_006a6e2c)(ppAVar4[3]);
        } while ((int)pAVar10 < iVar5);
      }
LAB_00554f40:
      iVar2 = iVar2 + 1;
      iVar3 = (*(code *)PTR_sk_num_006a6e2c)(*(undefined4 *)(*param_1 + 0x14));
      if (iVar3 <= iVar2) break;
    }
  }
  uVar7 = 0;
LAB_00554f60:
  if (local_2c == *(int *)puVar1) {
    return uVar7;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  piVar6 = *(int **)PTR___stack_chk_guard_006a9ae8;
  uVar8 = (uint)X509_REVOKED_it[0];
  if (X509_REVOKED_it._16_4_ == 0) {
    if (uVar8 < 7) {
                    /* WARNING: Could not recover jumptable at 0x005619f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar7 = (*(code *)(&switchD_005619f8::switchdataD_0066a17c)[uVar8])();
      return uVar7;
    }
  }
  else if (uVar8 < 7) {
                    /* WARNING: Could not recover jumptable at 0x00561550. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar7 = (*(code *)(&switchD_00561550::switchdataD_0066a160)[uVar8])();
    return uVar7;
  }
  if (piVar6 == *(int **)PTR___stack_chk_guard_006a9ae8) {
    return 0;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  return *(undefined4 *)(*piVar6 + pAVar9->type);
}

