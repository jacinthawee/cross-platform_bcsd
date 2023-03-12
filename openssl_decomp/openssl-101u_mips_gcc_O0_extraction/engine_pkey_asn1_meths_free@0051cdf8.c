
int engine_pkey_asn1_meths_free(int *param_1,int **param_2,int *param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  code *unaff_s0;
  int *unaff_s1;
  code *unaff_s2;
  int **unaff_s3;
  int iStack_b4;
  int iStack_b0;
  int **ppiStack_ac;
  int *piStack_a8;
  int iStack_a4;
  code *pcStack_a0;
  int *piStack_9c;
  code *pcStack_98;
  code *pcStack_94;
  undefined *puStack_80;
  int iStack_74;
  int *piStack_70;
  int *piStack_6c;
  code *pcStack_68;
  int *piStack_64;
  code *pcStack_60;
  int **ppiStack_5c;
  undefined *puStack_58;
  int *local_24;
  int local_20;
  int local_1c;
  
  puStack_58 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  piVar6 = param_1;
  piStack_64 = unaff_s1;
  if ((code *)param_1[0xc] != (code *)0x0) {
    param_3 = &local_20;
    param_2 = (int **)0x0;
    unaff_s2 = (code *)(*(code *)param_1[0xc])();
    piStack_64 = param_1;
    if (0 < (int)unaff_s2) {
      unaff_s0 = (code *)0x0;
      unaff_s3 = &local_24;
      do {
        while( true ) {
          param_3 = (int *)0x0;
          piVar6 = param_1;
          param_2 = unaff_s3;
          iVar3 = (*(code *)param_1[0xc])();
          if (iVar3 == 0) break;
          unaff_s0 = unaff_s0 + 1;
          piVar6 = local_24;
          (*(code *)PTR_EVP_PKEY_asn1_free_006a886c)();
          if (unaff_s2 == unaff_s0) goto LAB_0051ceb0;
        }
        unaff_s0 = unaff_s0 + 1;
      } while (unaff_s2 != unaff_s0);
    }
  }
LAB_0051ceb0:
  iVar3 = *(int *)puStack_58;
  if (local_1c == iVar3) {
    return iVar3;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  pcStack_a0 = (code *)piVar6[0xc];
  puStack_80 = &_gp;
  piStack_6c = *(int **)PTR___stack_chk_guard_006a9ae8;
  ppiStack_ac = param_2;
  piStack_9c = piStack_64;
  pcStack_68 = unaff_s0;
  pcStack_60 = unaff_s2;
  ppiStack_5c = unaff_s3;
  if (pcStack_a0 != (code *)0x0) {
    piStack_9c = param_3;
    if (param_3 == (int *)0xffffffff) {
      piStack_9c = (int *)(*(code *)PTR_strlen_006a9a24)(param_2);
    }
    param_3 = &iStack_74;
    ppiStack_ac = (int **)0x0;
    unaff_s2 = (code *)(*pcStack_a0)(piVar6,0,param_3,0);
    if (0 < (int)unaff_s2) {
      pcStack_a0 = (code *)0x0;
      do {
        param_3 = (int *)0x0;
        ppiStack_ac = &piStack_70;
        (*(code *)piVar6[0xc])
                  (piVar6,&piStack_70,0,*(undefined4 *)(iStack_74 + (int)pcStack_a0 * 4));
        piVar4 = piStack_70;
        iVar3 = piStack_70[3];
        piVar5 = (int *)(**(code **)(puStack_80 + -0x53bc))(iVar3);
        if ((piStack_9c == piVar5) &&
           (ppiStack_ac = param_2, param_3 = piStack_9c,
           iVar3 = (**(code **)(puStack_80 + -0x540c))(iVar3), iVar3 == 0)) break;
        pcStack_a0 = pcStack_a0 + 1;
        piVar4 = (int *)0x0;
      } while (unaff_s2 != pcStack_a0);
      goto LAB_0051cff0;
    }
  }
  piVar4 = (int *)0x0;
LAB_0051cff0:
  if (piStack_6c == *(int **)puVar2) {
    return (int)piVar4;
  }
  pcStack_94 = ENGINE_pkey_asn1_find_str;
  piVar6 = piStack_6c;
  (**(code **)(puStack_80 + -0x5330))();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  iStack_b4 = 0;
  iStack_b0 = 0;
  iStack_a4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  piStack_a8 = param_3;
  pcStack_98 = unaff_s2;
  (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"tb_asnmth.c",0xec);
  (*(code *)PTR_engine_table_doall_006a8870)(pkey_asn1_meth_table,look_str_cb,&iStack_b4);
  if (iStack_b4 != 0) {
    *(int *)(iStack_b4 + 0x58) = *(int *)(iStack_b4 + 0x58) + 1;
  }
  puVar1 = PTR_CRYPTO_lock_006a8144;
  *piVar6 = iStack_b4;
  (*(code *)puVar1)(10,0x1e,"tb_asnmth.c",0xf4);
  if (iStack_a4 != *(int *)puVar2) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    return 0;
  }
  return iStack_b0;
}

