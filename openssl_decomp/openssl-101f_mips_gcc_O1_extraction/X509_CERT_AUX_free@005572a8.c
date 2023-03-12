
void X509_CERT_AUX_free(X509_CERT_AUX *a)

{
  uint *puVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  stack_st_ASN1_OBJECT *psVar5;
  X509_CERT_AUX *pXVar6;
  undefined1 *puVar7;
  undefined4 in_a3;
  int iVar8;
  X509_CERT_AUX *pXStack_34;
  stack_st_ASN1_OBJECT *psStack_30;
  ASN1_UTF8STRING *pAStack_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  puVar1 = X509_CERT_AUX_it._8_4_;
  puVar7 = X509_CERT_AUX_it;
  uVar3 = (uint)X509_CERT_AUX_it[0];
  pAStack_2c = *(ASN1_UTF8STRING **)PTR___stack_chk_guard_006aabf0;
  pXVar6 = a;
  pXStack_34 = a;
  if (uVar3 == 0) {
    if (X509_CERT_AUX_it._16_4_ == (undefined4 *)0x0) {
      pXVar6 = (X509_CERT_AUX *)&pXStack_34;
      if (X509_CERT_AUX_it._8_4_ == (uint *)0x0) {
        ASN1_primitive_free((ASN1_VALUE **)pXVar6,(ASN1_ITEM *)X509_CERT_AUX_it);
      }
      else {
        iVar8 = 0;
        if ((*X509_CERT_AUX_it._8_4_ & 6) == 0) {
          puVar7 = (undefined1 *)X509_CERT_AUX_it._8_4_[4];
          pXVar6 = (X509_CERT_AUX *)&pXStack_34;
          asn1_item_combine_free(pXVar6,puVar7,*X509_CERT_AUX_it._8_4_ & 0x400);
        }
        else {
          puVar7 = (undefined1 *)X509_CERT_AUX_it._16_4_;
          for (; iVar4 = (*(code *)PTR_sk_num_006a7f2c)(a), iVar8 < iVar4; iVar8 = iVar8 + 1) {
            psStack_30 = (stack_st_ASN1_OBJECT *)(*(code *)PTR_sk_value_006a7f24)(a,iVar8);
            puVar7 = (undefined1 *)puVar1[4];
            asn1_item_combine_free(&psStack_30,puVar7,0);
          }
          (*(code *)PTR_sk_free_006a7f80)();
          pXVar6 = a;
        }
      }
      goto switchD_0055fb90_caseD_0;
    }
  }
  else {
    puVar7 = (undefined1 *)X509_CERT_AUX_it._16_4_;
    if (a == (X509_CERT_AUX *)0x0) goto switchD_0055fb90_caseD_0;
    if (X509_CERT_AUX_it._16_4_ == (undefined4 *)0x0) {
      if ((uVar3 & 0xff) < 7) {
                    /* WARNING: Could not recover jumptable at 0x0055fb90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(&switchD_0055fb90::switchdataD_0066aa70)[uVar3 & 0xff])();
        return;
      }
      goto switchD_0055fb90_caseD_0;
    }
  }
  if (X509_CERT_AUX_it._16_4_[4] == 0) {
    puVar7 = (undefined1 *)X509_CERT_AUX_it._16_4_;
    if ((uVar3 & 0xff) < 7) {
                    /* WARNING: Could not recover jumptable at 0x0055fdcc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&switchD_0055fdcc::switchdataD_0066aa8c)[uVar3 & 0xff])();
      return;
    }
  }
  else {
    puVar7 = (undefined1 *)X509_CERT_AUX_it._16_4_;
    if ((uVar3 & 0xff) < 7) {
                    /* WARNING: Could not recover jumptable at 0x0055fa8c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&switchD_0055fa8c::switchdataD_0066aa54)[uVar3 & 0xff])();
      return;
    }
  }
switchD_0055fb90_caseD_0:
  if (pAStack_2c == *(ASN1_UTF8STRING **)puVar2) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  psVar5 = pXVar6->reject;
  if ((int)*(stack_st_ASN1_OBJECT **)((int)puVar7 + 4) <= (int)pXVar6->reject) {
    psVar5 = *(stack_st_ASN1_OBJECT **)((int)puVar7 + 4);
  }
  (*(code *)PTR_memcmp_006aabd8)(pXVar6->trust,*(undefined4 *)puVar7,psVar5,in_a3,&_gp);
  return;
}

