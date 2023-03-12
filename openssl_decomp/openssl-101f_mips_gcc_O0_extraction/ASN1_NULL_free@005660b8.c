
void ASN1_NULL_free(ASN1_NULL *a)

{
  uint *puVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  ASN1_NULL *pAVar5;
  ASN1_NULL **ppAVar6;
  undefined1 *puVar7;
  undefined4 in_a3;
  int iVar8;
  ASN1_NULL *pAStack_34;
  undefined4 uStack_30;
  int iStack_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  puVar1 = ASN1_NULL_it._8_4_;
  puVar7 = ASN1_NULL_it;
  uVar3 = (uint)ASN1_NULL_it[0];
  iStack_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  ppAVar6 = (ASN1_NULL **)a;
  pAStack_34 = a;
  if (uVar3 == 0) {
    if (ASN1_NULL_it._16_4_ == (undefined4 *)0x0) {
      ppAVar6 = &pAStack_34;
      if (ASN1_NULL_it._8_4_ == (uint *)0x0) {
        ASN1_primitive_free((ASN1_VALUE **)ppAVar6,(ASN1_ITEM *)ASN1_NULL_it);
      }
      else {
        iVar8 = 0;
        if ((*ASN1_NULL_it._8_4_ & 6) == 0) {
          puVar7 = (undefined1 *)ASN1_NULL_it._8_4_[4];
          ppAVar6 = &pAStack_34;
          asn1_item_combine_free(ppAVar6,puVar7,*ASN1_NULL_it._8_4_ & 0x400);
        }
        else {
          puVar7 = (undefined1 *)ASN1_NULL_it._16_4_;
          for (; iVar4 = (*(code *)PTR_sk_num_006a7f2c)(a), iVar8 < iVar4; iVar8 = iVar8 + 1) {
            uStack_30 = (*(code *)PTR_sk_value_006a7f24)(a,iVar8);
            puVar7 = (undefined1 *)puVar1[4];
            asn1_item_combine_free(&uStack_30,puVar7,0);
          }
          (*(code *)PTR_sk_free_006a7f80)();
          ppAVar6 = (ASN1_NULL **)a;
        }
      }
      goto switchD_0055fb90_caseD_0;
    }
  }
  else {
    puVar7 = (undefined1 *)ASN1_NULL_it._16_4_;
    if (a == (ASN1_NULL *)0x0) goto switchD_0055fb90_caseD_0;
    if (ASN1_NULL_it._16_4_ == (undefined4 *)0x0) {
      if ((uVar3 & 0xff) < 7) {
                    /* WARNING: Could not recover jumptable at 0x0055fb90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(&switchD_0055fb90::switchdataD_0066aa50)[uVar3 & 0xff])();
        return;
      }
      goto switchD_0055fb90_caseD_0;
    }
  }
  if (ASN1_NULL_it._16_4_[4] == 0) {
    puVar7 = (undefined1 *)ASN1_NULL_it._16_4_;
    if ((uVar3 & 0xff) < 7) {
                    /* WARNING: Could not recover jumptable at 0x0055fdcc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&switchD_0055fdcc::switchdataD_0066aa6c)[uVar3 & 0xff])();
      return;
    }
  }
  else {
    puVar7 = (undefined1 *)ASN1_NULL_it._16_4_;
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
  pAVar5 = ppAVar6[1];
  if ((int)*(ASN1_NULL **)((int)puVar7 + 4) <= (int)ppAVar6[1]) {
    pAVar5 = *(ASN1_NULL **)((int)puVar7 + 4);
  }
  (*(code *)PTR_memcmp_006aabd8)(*ppAVar6,*(undefined4 *)puVar7,pAVar5,in_a3,&_gp);
  return;
}

