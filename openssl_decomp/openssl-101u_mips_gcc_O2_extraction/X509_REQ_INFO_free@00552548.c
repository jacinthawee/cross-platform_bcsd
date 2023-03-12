
void X509_REQ_INFO_free(X509_REQ_INFO *a)

{
  uint *puVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  X509_REQ_INFO *pXVar5;
  undefined1 *puVar6;
  undefined4 in_a3;
  int iVar7;
  X509_REQ_INFO *pXStack_34;
  long lStack_30;
  int iStack_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  puVar1 = X509_REQ_INFO_it._8_4_;
  puVar6 = X509_REQ_INFO_it;
  uVar3 = (uint)X509_REQ_INFO_it[0];
  iStack_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pXVar5 = a;
  pXStack_34 = a;
  if (uVar3 == 0) {
    if (X509_REQ_INFO_it._16_4_ == (undefined4 *)0x0) {
      pXVar5 = (X509_REQ_INFO *)&pXStack_34;
      if (X509_REQ_INFO_it._8_4_ == (uint *)0x0) {
        ASN1_primitive_free((ASN1_VALUE **)pXVar5,(ASN1_ITEM *)X509_REQ_INFO_it);
      }
      else {
        iVar7 = 0;
        if ((*X509_REQ_INFO_it._8_4_ & 6) == 0) {
          puVar6 = (undefined1 *)X509_REQ_INFO_it._8_4_[4];
          pXVar5 = (X509_REQ_INFO *)&pXStack_34;
          asn1_item_combine_free(pXVar5,puVar6,*X509_REQ_INFO_it._8_4_ & 0x400);
        }
        else {
          puVar6 = (undefined1 *)X509_REQ_INFO_it._16_4_;
          for (; iVar4 = (*(code *)PTR_sk_num_006a6e2c)(a), iVar7 < iVar4; iVar7 = iVar7 + 1) {
            lStack_30 = (*(code *)PTR_sk_value_006a6e24)(a,iVar7);
            puVar6 = (undefined1 *)puVar1[4];
            asn1_item_combine_free(&lStack_30,puVar6,0);
          }
          (*(code *)PTR_sk_free_006a6e80)();
          pXVar5 = a;
        }
      }
      goto switchD_0055c4c0_caseD_0;
    }
  }
  else {
    puVar6 = (undefined1 *)X509_REQ_INFO_it._16_4_;
    if (a == (X509_REQ_INFO *)0x0) goto switchD_0055c4c0_caseD_0;
    if (X509_REQ_INFO_it._16_4_ == (undefined4 *)0x0) {
      if ((uVar3 & 0xff) < 7) {
                    /* WARNING: Could not recover jumptable at 0x0055c4c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(&switchD_0055c4c0::switchdataD_00669fb0)[uVar3 & 0xff])();
        return;
      }
      goto switchD_0055c4c0_caseD_0;
    }
  }
  if (X509_REQ_INFO_it._16_4_[4] == 0) {
    puVar6 = (undefined1 *)X509_REQ_INFO_it._16_4_;
    if ((uVar3 & 0xff) < 7) {
                    /* WARNING: Could not recover jumptable at 0x0055c6fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&switchD_0055c6fc::switchdataD_00669fcc)[uVar3 & 0xff])();
      return;
    }
  }
  else {
    puVar6 = (undefined1 *)X509_REQ_INFO_it._16_4_;
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
  iVar7 = (pXVar5->enc).len;
  if (*(int *)((int)puVar6 + 4) <= iVar7) {
    iVar7 = *(int *)((int)puVar6 + 4);
  }
  (*(code *)PTR_memcmp_006a9ad0)((pXVar5->enc).enc,*(undefined4 *)puVar6,iVar7,in_a3,&_gp);
  return;
}

