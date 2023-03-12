
void NETSCAPE_SPKAC_free(NETSCAPE_SPKAC *a)

{
  uint *puVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  ASN1_IA5STRING *pAVar5;
  NETSCAPE_SPKAC *pNVar6;
  undefined1 *puVar7;
  undefined4 in_a3;
  int iVar8;
  NETSCAPE_SPKAC NStack_34;
  int iStack_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  puVar1 = NETSCAPE_SPKAC_it._8_4_;
  puVar7 = NETSCAPE_SPKAC_it;
  uVar3 = (uint)NETSCAPE_SPKAC_it[0];
  iStack_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  pNVar6 = a;
  NStack_34.pubkey = (X509_PUBKEY *)a;
  if (uVar3 == 0) {
    if (NETSCAPE_SPKAC_it._16_4_ == (undefined4 *)0x0) {
      pNVar6 = &NStack_34;
      if (NETSCAPE_SPKAC_it._8_4_ == (uint *)0x0) {
        ASN1_primitive_free((ASN1_VALUE **)pNVar6,(ASN1_ITEM *)NETSCAPE_SPKAC_it);
      }
      else {
        iVar8 = 0;
        if ((*NETSCAPE_SPKAC_it._8_4_ & 6) == 0) {
          puVar7 = (undefined1 *)NETSCAPE_SPKAC_it._8_4_[4];
          pNVar6 = &NStack_34;
          asn1_item_combine_free(pNVar6,puVar7,*NETSCAPE_SPKAC_it._8_4_ & 0x400);
        }
        else {
          puVar7 = (undefined1 *)NETSCAPE_SPKAC_it._16_4_;
          for (; iVar4 = (*(code *)PTR_sk_num_006a7f2c)(a), iVar8 < iVar4; iVar8 = iVar8 + 1) {
            NStack_34.challenge = (ASN1_IA5STRING *)(*(code *)PTR_sk_value_006a7f24)(a,iVar8);
            puVar7 = (undefined1 *)puVar1[4];
            asn1_item_combine_free(&NStack_34.challenge,puVar7,0);
          }
          (*(code *)PTR_sk_free_006a7f80)();
          pNVar6 = a;
        }
      }
      goto switchD_0055fb90_caseD_0;
    }
  }
  else {
    puVar7 = (undefined1 *)NETSCAPE_SPKAC_it._16_4_;
    if (a == (NETSCAPE_SPKAC *)0x0) goto switchD_0055fb90_caseD_0;
    if (NETSCAPE_SPKAC_it._16_4_ == (undefined4 *)0x0) {
      if ((uVar3 & 0xff) < 7) {
                    /* WARNING: Could not recover jumptable at 0x0055fb90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(&switchD_0055fb90::switchdataD_0066aa70)[uVar3 & 0xff])();
        return;
      }
      goto switchD_0055fb90_caseD_0;
    }
  }
  if (NETSCAPE_SPKAC_it._16_4_[4] == 0) {
    puVar7 = (undefined1 *)NETSCAPE_SPKAC_it._16_4_;
    if ((uVar3 & 0xff) < 7) {
                    /* WARNING: Could not recover jumptable at 0x0055fdcc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&switchD_0055fdcc::switchdataD_0066aa8c)[uVar3 & 0xff])();
      return;
    }
  }
  else {
    puVar7 = (undefined1 *)NETSCAPE_SPKAC_it._16_4_;
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
  pAVar5 = pNVar6->challenge;
  if ((int)*(ASN1_IA5STRING **)((int)puVar7 + 4) <= (int)pNVar6->challenge) {
    pAVar5 = *(ASN1_IA5STRING **)((int)puVar7 + 4);
  }
  (*(code *)PTR_memcmp_006aabd8)(pNVar6->pubkey,*(undefined4 *)puVar7,pAVar5,in_a3,&_gp);
  return;
}

