
void X509_CERT_PAIR_free(X509_CERT_PAIR *a)

{
  uint *puVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  X509 *pXVar5;
  X509_CERT_PAIR *pXVar6;
  undefined1 *puVar7;
  undefined4 in_a3;
  int iVar8;
  X509_CERT_PAIR XStack_34;
  int iStack_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  puVar1 = X509_CERT_PAIR_it._8_4_;
  puVar7 = X509_CERT_PAIR_it;
  uVar3 = (uint)X509_CERT_PAIR_it[0];
  iStack_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  pXVar6 = a;
  XStack_34.forward = (X509 *)a;
  if (uVar3 == 0) {
    if (X509_CERT_PAIR_it._16_4_ == (undefined4 *)0x0) {
      pXVar6 = &XStack_34;
      if (X509_CERT_PAIR_it._8_4_ == (uint *)0x0) {
        ASN1_primitive_free((ASN1_VALUE **)pXVar6,(ASN1_ITEM *)X509_CERT_PAIR_it);
      }
      else {
        iVar8 = 0;
        if ((*X509_CERT_PAIR_it._8_4_ & 6) == 0) {
          puVar7 = (undefined1 *)X509_CERT_PAIR_it._8_4_[4];
          pXVar6 = &XStack_34;
          asn1_item_combine_free(pXVar6,puVar7,*X509_CERT_PAIR_it._8_4_ & 0x400);
        }
        else {
          puVar7 = (undefined1 *)X509_CERT_PAIR_it._16_4_;
          for (; iVar4 = (*(code *)PTR_sk_num_006a7f2c)(a), iVar8 < iVar4; iVar8 = iVar8 + 1) {
            XStack_34.reverse = (X509 *)(*(code *)PTR_sk_value_006a7f24)(a,iVar8);
            puVar7 = (undefined1 *)puVar1[4];
            asn1_item_combine_free(&XStack_34.reverse,puVar7,0);
          }
          (*(code *)PTR_sk_free_006a7f80)();
          pXVar6 = a;
        }
      }
      goto switchD_0055fb90_caseD_0;
    }
  }
  else {
    puVar7 = (undefined1 *)X509_CERT_PAIR_it._16_4_;
    if (a == (X509_CERT_PAIR *)0x0) goto switchD_0055fb90_caseD_0;
    if (X509_CERT_PAIR_it._16_4_ == (undefined4 *)0x0) {
      if ((uVar3 & 0xff) < 7) {
                    /* WARNING: Could not recover jumptable at 0x0055fb90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(&switchD_0055fb90::switchdataD_0066aa70)[uVar3 & 0xff])();
        return;
      }
      goto switchD_0055fb90_caseD_0;
    }
  }
  if (X509_CERT_PAIR_it._16_4_[4] == 0) {
    puVar7 = (undefined1 *)X509_CERT_PAIR_it._16_4_;
    if ((uVar3 & 0xff) < 7) {
                    /* WARNING: Could not recover jumptable at 0x0055fdcc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&switchD_0055fdcc::switchdataD_0066aa8c)[uVar3 & 0xff])();
      return;
    }
  }
  else {
    puVar7 = (undefined1 *)X509_CERT_PAIR_it._16_4_;
    if ((uVar3 & 0xff) < 7) {
                    /* WARNING: Could not recover jumptable at 0x0055fa8c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&switchD_0055fa8c::switchdataD_0066aa54)[uVar3 & 0xff])();
      return;
    }
  }
switchD_0055fb90_caseD_0:
  if (iStack_2c == *(int *)puVar2) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  pXVar5 = pXVar6->reverse;
  if ((int)*(X509 **)((int)puVar7 + 4) <= (int)pXVar6->reverse) {
    pXVar5 = *(X509 **)((int)puVar7 + 4);
  }
  (*(code *)PTR_memcmp_006aabd8)(pXVar6->forward,*(undefined4 *)puVar7,pXVar5,in_a3,&_gp);
  return;
}

