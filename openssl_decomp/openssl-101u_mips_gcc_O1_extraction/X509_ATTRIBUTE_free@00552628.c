
void X509_ATTRIBUTE_free(X509_ATTRIBUTE *a)

{
  uint *puVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  X509_ATTRIBUTE *pXVar5;
  undefined1 *puVar6;
  undefined4 in_a3;
  int iVar7;
  X509_ATTRIBUTE XStack_34;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  puVar1 = X509_ATTRIBUTE_it._8_4_;
  puVar6 = X509_ATTRIBUTE_it;
  uVar3 = (uint)X509_ATTRIBUTE_it[0];
  XStack_34.value = *(_union_330 *)PTR___stack_chk_guard_006a9ae8;
  pXVar5 = a;
  XStack_34.object = (ASN1_OBJECT *)a;
  if (uVar3 == 0) {
    if (X509_ATTRIBUTE_it._16_4_ == (undefined4 *)0x0) {
      pXVar5 = &XStack_34;
      if (X509_ATTRIBUTE_it._8_4_ == (uint *)0x0) {
        ASN1_primitive_free((ASN1_VALUE **)pXVar5,(ASN1_ITEM *)X509_ATTRIBUTE_it);
      }
      else {
        iVar7 = 0;
        if ((*X509_ATTRIBUTE_it._8_4_ & 6) == 0) {
          puVar6 = (undefined1 *)X509_ATTRIBUTE_it._8_4_[4];
          pXVar5 = &XStack_34;
          asn1_item_combine_free(pXVar5,puVar6,*X509_ATTRIBUTE_it._8_4_ & 0x400);
        }
        else {
          puVar6 = (undefined1 *)X509_ATTRIBUTE_it._16_4_;
          for (; iVar4 = (*(code *)PTR_sk_num_006a6e2c)(a), iVar7 < iVar4; iVar7 = iVar7 + 1) {
            XStack_34.single = (*(code *)PTR_sk_value_006a6e24)(a,iVar7);
            puVar6 = (undefined1 *)puVar1[4];
            asn1_item_combine_free(&XStack_34.single,puVar6,0);
          }
          (*(code *)PTR_sk_free_006a6e80)();
          pXVar5 = a;
        }
      }
      goto switchD_0055c4c0_caseD_0;
    }
  }
  else {
    puVar6 = (undefined1 *)X509_ATTRIBUTE_it._16_4_;
    if (a == (X509_ATTRIBUTE *)0x0) goto switchD_0055c4c0_caseD_0;
    if (X509_ATTRIBUTE_it._16_4_ == (undefined4 *)0x0) {
      if ((uVar3 & 0xff) < 7) {
                    /* WARNING: Could not recover jumptable at 0x0055c4c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(&switchD_0055c4c0::switchdataD_00669fb0)[uVar3 & 0xff])();
        return;
      }
      goto switchD_0055c4c0_caseD_0;
    }
  }
  if (X509_ATTRIBUTE_it._16_4_[4] == 0) {
    puVar6 = (undefined1 *)X509_ATTRIBUTE_it._16_4_;
    if ((uVar3 & 0xff) < 7) {
                    /* WARNING: Could not recover jumptable at 0x0055c6fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&switchD_0055c6fc::switchdataD_00669fcc)[uVar3 & 0xff])();
      return;
    }
  }
  else {
    puVar6 = (undefined1 *)X509_ATTRIBUTE_it._16_4_;
    if ((uVar3 & 0xff) < 7) {
                    /* WARNING: Could not recover jumptable at 0x0055c3bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&switchD_0055c3bc::switchdataD_00669f94)[uVar3 & 0xff])();
      return;
    }
  }
switchD_0055c4c0_caseD_0:
  if (XStack_34.value.ptr == *(char **)puVar2) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar7 = pXVar5->single;
  if (*(int *)((int)puVar6 + 4) <= pXVar5->single) {
    iVar7 = *(int *)((int)puVar6 + 4);
  }
  (*(code *)PTR_memcmp_006a9ad0)(pXVar5->object,*(undefined4 *)puVar6,iVar7,in_a3,&_gp);
  return;
}

