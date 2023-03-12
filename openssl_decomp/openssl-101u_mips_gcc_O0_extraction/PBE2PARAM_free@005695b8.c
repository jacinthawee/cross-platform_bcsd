
void PBE2PARAM_free(PBE2PARAM *a)

{
  uint *puVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  X509_ALGOR *pXVar5;
  PBE2PARAM *pPVar6;
  undefined1 *puVar7;
  undefined4 in_a3;
  int iVar8;
  PBE2PARAM PStack_34;
  int iStack_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  puVar1 = PBE2PARAM_it._8_4_;
  puVar7 = PBE2PARAM_it;
  uVar3 = (uint)PBE2PARAM_it[0];
  iStack_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pPVar6 = a;
  PStack_34.keyfunc = (X509_ALGOR *)a;
  if (uVar3 == 0) {
    if (PBE2PARAM_it._16_4_ == (undefined4 *)0x0) {
      pPVar6 = &PStack_34;
      if (PBE2PARAM_it._8_4_ == (uint *)0x0) {
        ASN1_primitive_free((ASN1_VALUE **)pPVar6,(ASN1_ITEM *)PBE2PARAM_it);
      }
      else {
        iVar8 = 0;
        if ((*PBE2PARAM_it._8_4_ & 6) == 0) {
          puVar7 = (undefined1 *)PBE2PARAM_it._8_4_[4];
          pPVar6 = &PStack_34;
          asn1_item_combine_free(pPVar6,puVar7,*PBE2PARAM_it._8_4_ & 0x400);
        }
        else {
          puVar7 = (undefined1 *)PBE2PARAM_it._16_4_;
          for (; iVar4 = (*(code *)PTR_sk_num_006a6e2c)(a), iVar8 < iVar4; iVar8 = iVar8 + 1) {
            PStack_34.encryption = (X509_ALGOR *)(*(code *)PTR_sk_value_006a6e24)(a,iVar8);
            puVar7 = (undefined1 *)puVar1[4];
            asn1_item_combine_free(&PStack_34.encryption,puVar7,0);
          }
          (*(code *)PTR_sk_free_006a6e80)();
          pPVar6 = a;
        }
      }
      goto switchD_0055c4c0_caseD_0;
    }
  }
  else {
    puVar7 = (undefined1 *)PBE2PARAM_it._16_4_;
    if (a == (PBE2PARAM *)0x0) goto switchD_0055c4c0_caseD_0;
    if (PBE2PARAM_it._16_4_ == (undefined4 *)0x0) {
      if ((uVar3 & 0xff) < 7) {
                    /* WARNING: Could not recover jumptable at 0x0055c4c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(&switchD_0055c4c0::switchdataD_00669fb0)[uVar3 & 0xff])();
        return;
      }
      goto switchD_0055c4c0_caseD_0;
    }
  }
  if (PBE2PARAM_it._16_4_[4] == 0) {
    puVar7 = (undefined1 *)PBE2PARAM_it._16_4_;
    if ((uVar3 & 0xff) < 7) {
                    /* WARNING: Could not recover jumptable at 0x0055c6fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&switchD_0055c6fc::switchdataD_00669fcc)[uVar3 & 0xff])();
      return;
    }
  }
  else {
    puVar7 = (undefined1 *)PBE2PARAM_it._16_4_;
    if ((uVar3 & 0xff) < 7) {
                    /* WARNING: Could not recover jumptable at 0x0055c3bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&switchD_0055c3bc::switchdataD_00669f94)[uVar3 & 0xff])();
      return;
    }
  }
switchD_0055c4c0_caseD_0:
  if (iStack_2c == *(int *)puVar2) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  pXVar5 = pPVar6->encryption;
  if ((int)*(X509_ALGOR **)((int)puVar7 + 4) <= (int)pPVar6->encryption) {
    pXVar5 = *(X509_ALGOR **)((int)puVar7 + 4);
  }
  (*(code *)PTR_memcmp_006a9ad0)(pPVar6->keyfunc,*(undefined4 *)puVar7,pXVar5,in_a3,&_gp);
  return;
}

