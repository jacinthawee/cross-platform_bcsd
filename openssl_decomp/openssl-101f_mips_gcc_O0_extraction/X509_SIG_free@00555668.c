
void X509_SIG_free(X509_SIG *a)

{
  uint *puVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  ASN1_OCTET_STRING *pAVar5;
  X509_SIG *pXVar6;
  undefined1 *puVar7;
  undefined4 in_a3;
  int iVar8;
  X509_SIG XStack_34;
  int iStack_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  puVar1 = X509_SIG_it._8_4_;
  puVar7 = X509_SIG_it;
  uVar3 = (uint)X509_SIG_it[0];
  iStack_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  pXVar6 = a;
  XStack_34.algor = (X509_ALGOR *)a;
  if (uVar3 == 0) {
    if (X509_SIG_it._16_4_ == (undefined4 *)0x0) {
      pXVar6 = &XStack_34;
      if (X509_SIG_it._8_4_ == (uint *)0x0) {
        ASN1_primitive_free((ASN1_VALUE **)pXVar6,(ASN1_ITEM *)X509_SIG_it);
      }
      else {
        iVar8 = 0;
        if ((*X509_SIG_it._8_4_ & 6) == 0) {
          puVar7 = (undefined1 *)X509_SIG_it._8_4_[4];
          pXVar6 = &XStack_34;
          asn1_item_combine_free(pXVar6,puVar7,*X509_SIG_it._8_4_ & 0x400);
        }
        else {
          puVar7 = (undefined1 *)X509_SIG_it._16_4_;
          for (; iVar4 = (*(code *)PTR_sk_num_006a7f2c)(a), iVar8 < iVar4; iVar8 = iVar8 + 1) {
            XStack_34.digest = (ASN1_OCTET_STRING *)(*(code *)PTR_sk_value_006a7f24)(a,iVar8);
            puVar7 = (undefined1 *)puVar1[4];
            asn1_item_combine_free(&XStack_34.digest,puVar7,0);
          }
          (*(code *)PTR_sk_free_006a7f80)();
          pXVar6 = a;
        }
      }
      goto switchD_0055fb90_caseD_0;
    }
  }
  else {
    puVar7 = (undefined1 *)X509_SIG_it._16_4_;
    if (a == (X509_SIG *)0x0) goto switchD_0055fb90_caseD_0;
    if (X509_SIG_it._16_4_ == (undefined4 *)0x0) {
      if ((uVar3 & 0xff) < 7) {
                    /* WARNING: Could not recover jumptable at 0x0055fb90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(&switchD_0055fb90::switchdataD_0066aa50)[uVar3 & 0xff])();
        return;
      }
      goto switchD_0055fb90_caseD_0;
    }
  }
  if (X509_SIG_it._16_4_[4] == 0) {
    puVar7 = (undefined1 *)X509_SIG_it._16_4_;
    if ((uVar3 & 0xff) < 7) {
                    /* WARNING: Could not recover jumptable at 0x0055fdcc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&switchD_0055fdcc::switchdataD_0066aa6c)[uVar3 & 0xff])();
      return;
    }
  }
  else {
    puVar7 = (undefined1 *)X509_SIG_it._16_4_;
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
  pAVar5 = pXVar6->digest;
  if ((int)*(ASN1_OCTET_STRING **)((int)puVar7 + 4) <= (int)pXVar6->digest) {
    pAVar5 = *(ASN1_OCTET_STRING **)((int)puVar7 + 4);
  }
  (*(code *)PTR_memcmp_006aabd8)(pXVar6->algor,*(undefined4 *)puVar7,pAVar5,in_a3,&_gp);
  return;
}
