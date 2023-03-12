
void PBKDF2PARAM_free(PBKDF2PARAM *a)

{
  uint *puVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  ASN1_INTEGER *pAVar5;
  PBKDF2PARAM *pPVar6;
  undefined1 *puVar7;
  undefined4 in_a3;
  int iVar8;
  PBKDF2PARAM *pPStack_34;
  ASN1_INTEGER *pAStack_30;
  ASN1_INTEGER *pAStack_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  puVar1 = PBKDF2PARAM_it._8_4_;
  puVar7 = PBKDF2PARAM_it;
  uVar3 = (uint)PBKDF2PARAM_it[0];
  pAStack_2c = *(ASN1_INTEGER **)PTR___stack_chk_guard_006aabf0;
  pPVar6 = a;
  pPStack_34 = a;
  if (uVar3 == 0) {
    if (PBKDF2PARAM_it._16_4_ == (undefined4 *)0x0) {
      pPVar6 = (PBKDF2PARAM *)&pPStack_34;
      if (PBKDF2PARAM_it._8_4_ == (uint *)0x0) {
        ASN1_primitive_free((ASN1_VALUE **)pPVar6,(ASN1_ITEM *)PBKDF2PARAM_it);
      }
      else {
        iVar8 = 0;
        if ((*PBKDF2PARAM_it._8_4_ & 6) == 0) {
          puVar7 = (undefined1 *)PBKDF2PARAM_it._8_4_[4];
          pPVar6 = (PBKDF2PARAM *)&pPStack_34;
          asn1_item_combine_free(pPVar6,puVar7,*PBKDF2PARAM_it._8_4_ & 0x400);
        }
        else {
          puVar7 = (undefined1 *)PBKDF2PARAM_it._16_4_;
          for (; iVar4 = (*(code *)PTR_sk_num_006a7f2c)(a), iVar8 < iVar4; iVar8 = iVar8 + 1) {
            pAStack_30 = (ASN1_INTEGER *)(*(code *)PTR_sk_value_006a7f24)(a,iVar8);
            puVar7 = (undefined1 *)puVar1[4];
            asn1_item_combine_free(&pAStack_30,puVar7,0);
          }
          (*(code *)PTR_sk_free_006a7f80)();
          pPVar6 = a;
        }
      }
      goto switchD_0055fb90_caseD_0;
    }
  }
  else {
    puVar7 = (undefined1 *)PBKDF2PARAM_it._16_4_;
    if (a == (PBKDF2PARAM *)0x0) goto switchD_0055fb90_caseD_0;
    if (PBKDF2PARAM_it._16_4_ == (undefined4 *)0x0) {
      if ((uVar3 & 0xff) < 7) {
                    /* WARNING: Could not recover jumptable at 0x0055fb90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(&switchD_0055fb90::switchdataD_0066aa70)[uVar3 & 0xff])();
        return;
      }
      goto switchD_0055fb90_caseD_0;
    }
  }
  if (PBKDF2PARAM_it._16_4_[4] == 0) {
    puVar7 = (undefined1 *)PBKDF2PARAM_it._16_4_;
    if ((uVar3 & 0xff) < 7) {
                    /* WARNING: Could not recover jumptable at 0x0055fdcc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&switchD_0055fdcc::switchdataD_0066aa8c)[uVar3 & 0xff])();
      return;
    }
  }
  else {
    puVar7 = (undefined1 *)PBKDF2PARAM_it._16_4_;
    if ((uVar3 & 0xff) < 7) {
                    /* WARNING: Could not recover jumptable at 0x0055fa8c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&switchD_0055fa8c::switchdataD_0066aa54)[uVar3 & 0xff])();
      return;
    }
  }
switchD_0055fb90_caseD_0:
  if (pAStack_2c == *(ASN1_INTEGER **)puVar2) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  pAVar5 = pPVar6->iter;
  if ((int)*(ASN1_INTEGER **)((int)puVar7 + 4) <= (int)pPVar6->iter) {
    pAVar5 = *(ASN1_INTEGER **)((int)puVar7 + 4);
  }
  (*(code *)PTR_memcmp_006aabd8)(pPVar6->salt,*(undefined4 *)puVar7,pAVar5,in_a3,&_gp);
  return;
}

