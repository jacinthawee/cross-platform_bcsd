
void X509_REVOKED_free(X509_REVOKED *a)

{
  uint *puVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  ASN1_TIME *pAVar5;
  X509_REVOKED *pXVar6;
  undefined1 *puVar7;
  undefined4 in_a3;
  int iVar8;
  X509_REVOKED *pXStack_34;
  ASN1_TIME *pAStack_30;
  stack_st_X509_EXTENSION *psStack_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  puVar1 = X509_REVOKED_it._8_4_;
  puVar7 = X509_REVOKED_it;
  uVar3 = (uint)X509_REVOKED_it[0];
  psStack_2c = *(stack_st_X509_EXTENSION **)PTR___stack_chk_guard_006a9ae8;
  pXVar6 = a;
  pXStack_34 = a;
  if (uVar3 == 0) {
    if (X509_REVOKED_it._16_4_ == (undefined4 *)0x0) {
      pXVar6 = (X509_REVOKED *)&pXStack_34;
      if (X509_REVOKED_it._8_4_ == (uint *)0x0) {
        ASN1_primitive_free((ASN1_VALUE **)pXVar6,(ASN1_ITEM *)X509_REVOKED_it);
      }
      else {
        iVar8 = 0;
        if ((*X509_REVOKED_it._8_4_ & 6) == 0) {
          puVar7 = (undefined1 *)X509_REVOKED_it._8_4_[4];
          pXVar6 = (X509_REVOKED *)&pXStack_34;
          asn1_item_combine_free(pXVar6,puVar7,*X509_REVOKED_it._8_4_ & 0x400);
        }
        else {
          puVar7 = (undefined1 *)X509_REVOKED_it._16_4_;
          for (; iVar4 = (*(code *)PTR_sk_num_006a6e2c)(a), iVar8 < iVar4; iVar8 = iVar8 + 1) {
            pAStack_30 = (ASN1_TIME *)(*(code *)PTR_sk_value_006a6e24)(a,iVar8);
            puVar7 = (undefined1 *)puVar1[4];
            asn1_item_combine_free(&pAStack_30,puVar7,0);
          }
          (*(code *)PTR_sk_free_006a6e80)();
          pXVar6 = a;
        }
      }
      goto switchD_0055c4c0_caseD_0;
    }
  }
  else {
    puVar7 = (undefined1 *)X509_REVOKED_it._16_4_;
    if (a == (X509_REVOKED *)0x0) goto switchD_0055c4c0_caseD_0;
    if (X509_REVOKED_it._16_4_ == (undefined4 *)0x0) {
      if ((uVar3 & 0xff) < 7) {
                    /* WARNING: Could not recover jumptable at 0x0055c4c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(&switchD_0055c4c0::switchdataD_00669fb0)[uVar3 & 0xff])();
        return;
      }
      goto switchD_0055c4c0_caseD_0;
    }
  }
  if (X509_REVOKED_it._16_4_[4] == 0) {
    puVar7 = (undefined1 *)X509_REVOKED_it._16_4_;
    if ((uVar3 & 0xff) < 7) {
                    /* WARNING: Could not recover jumptable at 0x0055c6fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&switchD_0055c6fc::switchdataD_00669fcc)[uVar3 & 0xff])();
      return;
    }
  }
  else {
    puVar7 = (undefined1 *)X509_REVOKED_it._16_4_;
    if ((uVar3 & 0xff) < 7) {
                    /* WARNING: Could not recover jumptable at 0x0055c3bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&switchD_0055c3bc::switchdataD_00669f94)[uVar3 & 0xff])();
      return;
    }
  }
switchD_0055c4c0_caseD_0:
  if (psStack_2c == *(stack_st_X509_EXTENSION **)puVar2) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  pAVar5 = pXVar6->revocationDate;
  if ((int)*(ASN1_TIME **)((int)puVar7 + 4) <= (int)pXVar6->revocationDate) {
    pAVar5 = *(ASN1_TIME **)((int)puVar7 + 4);
  }
  (*(code *)PTR_memcmp_006a9ad0)(pXVar6->serialNumber,*(undefined4 *)puVar7,pAVar5,in_a3,&_gp);
  return;
}
