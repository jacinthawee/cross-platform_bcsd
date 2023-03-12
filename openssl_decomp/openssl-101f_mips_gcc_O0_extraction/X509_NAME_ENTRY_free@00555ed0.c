
void X509_NAME_ENTRY_free(X509_NAME_ENTRY *a)

{
  uint *puVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  ASN1_STRING *pAVar5;
  X509_NAME_ENTRY *pXVar6;
  undefined1 *puVar7;
  undefined4 in_a3;
  int iVar8;
  ASN1_OBJECT *pAStack_34;
  ASN1_STRING *pAStack_30;
  int iStack_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  puVar1 = X509_NAME_ENTRY_it._8_4_;
  puVar7 = X509_NAME_ENTRY_it;
  uVar3 = (uint)X509_NAME_ENTRY_it[0];
  iStack_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  pXVar6 = a;
  pAStack_34 = (ASN1_OBJECT *)a;
  if (uVar3 == 0) {
    if (X509_NAME_ENTRY_it._16_4_ == (undefined4 *)0x0) {
      pXVar6 = (X509_NAME_ENTRY *)&pAStack_34;
      if (X509_NAME_ENTRY_it._8_4_ == (uint *)0x0) {
        ASN1_primitive_free((ASN1_VALUE **)pXVar6,(ASN1_ITEM *)X509_NAME_ENTRY_it);
      }
      else {
        iVar8 = 0;
        if ((*X509_NAME_ENTRY_it._8_4_ & 6) == 0) {
          puVar7 = (undefined1 *)X509_NAME_ENTRY_it._8_4_[4];
          pXVar6 = (X509_NAME_ENTRY *)&pAStack_34;
          asn1_item_combine_free(pXVar6,puVar7,*X509_NAME_ENTRY_it._8_4_ & 0x400);
        }
        else {
          puVar7 = (undefined1 *)X509_NAME_ENTRY_it._16_4_;
          for (; iVar4 = (*(code *)PTR_sk_num_006a7f2c)(a), iVar8 < iVar4; iVar8 = iVar8 + 1) {
            pAStack_30 = (ASN1_STRING *)(*(code *)PTR_sk_value_006a7f24)(a,iVar8);
            puVar7 = (undefined1 *)puVar1[4];
            asn1_item_combine_free(&pAStack_30,puVar7,0);
          }
          (*(code *)PTR_sk_free_006a7f80)();
          pXVar6 = a;
        }
      }
      goto switchD_0055fb90_caseD_0;
    }
  }
  else {
    puVar7 = (undefined1 *)X509_NAME_ENTRY_it._16_4_;
    if (a == (X509_NAME_ENTRY *)0x0) goto switchD_0055fb90_caseD_0;
    if (X509_NAME_ENTRY_it._16_4_ == (undefined4 *)0x0) {
      if ((uVar3 & 0xff) < 7) {
                    /* WARNING: Could not recover jumptable at 0x0055fb90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(&switchD_0055fb90::switchdataD_0066aa50)[uVar3 & 0xff])();
        return;
      }
      goto switchD_0055fb90_caseD_0;
    }
  }
  if (X509_NAME_ENTRY_it._16_4_[4] == 0) {
    puVar7 = (undefined1 *)X509_NAME_ENTRY_it._16_4_;
    if ((uVar3 & 0xff) < 7) {
                    /* WARNING: Could not recover jumptable at 0x0055fdcc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&switchD_0055fdcc::switchdataD_0066aa6c)[uVar3 & 0xff])();
      return;
    }
  }
  else {
    puVar7 = (undefined1 *)X509_NAME_ENTRY_it._16_4_;
    if ((uVar3 & 0xff) < 7) {
                    /* WARNING: Could not recover jumptable at 0x0055fa8c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&switchD_0055fa8c::switchdataD_0066aa34)[uVar3 & 0xff])();
      return;
    }
  }
switchD_0055fb90_caseD_0:
  if (iStack_2c == *(int *)puVar2) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  pAVar5 = pXVar6->value;
  if ((int)*(ASN1_STRING **)((int)puVar7 + 4) <= (int)pXVar6->value) {
    pAVar5 = *(ASN1_STRING **)((int)puVar7 + 4);
  }
  (*(code *)PTR_memcmp_006aabd8)(pXVar6->object,*(undefined4 *)puVar7,pAVar5,in_a3,&_gp);
  return;
}

