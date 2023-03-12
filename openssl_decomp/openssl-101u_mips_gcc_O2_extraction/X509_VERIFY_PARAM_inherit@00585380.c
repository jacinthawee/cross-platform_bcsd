
int X509_VERIFY_PARAM_inherit(X509_VERIFY_PARAM *to,X509_VERIFY_PARAM *from)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  stack_st_ASN1_OBJECT *psVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  stack_st_ASN1_OBJECT *psVar10;
  
  if (from == (X509_VERIFY_PARAM *)0x0) {
    return 1;
  }
  uVar1 = to->inh_flags | from->inh_flags;
  if ((uVar1 & 0x10) != 0) {
    to->inh_flags = 0;
  }
  if ((uVar1 & 8) != 0) {
    return 1;
  }
  uVar7 = uVar1 & 1;
  if ((uVar1 & 2) == 0) {
    if (from->purpose == 0) {
LAB_00585548:
      iVar8 = from->trust;
      if (iVar8 != 0) {
        if (uVar7 == 0) goto LAB_005855e4;
LAB_0058555c:
        to->trust = iVar8;
      }
LAB_00585560:
      iVar8 = from->depth;
      if (iVar8 != -1) {
        if (uVar7 == 0) {
LAB_005855fc:
          if (to->depth == -1) {
            to->depth = iVar8;
          }
        }
        else {
          to->depth = iVar8;
        }
      }
    }
    else {
      if ((uVar7 != 0) || (to->purpose == 0)) {
        to->purpose = from->purpose;
        goto LAB_00585548;
      }
      iVar8 = from->trust;
      if (iVar8 == 0) goto LAB_00585560;
LAB_005855e4:
      if (to->trust == 0) goto LAB_0058555c;
      iVar8 = from->depth;
      if (iVar8 != -1) goto LAB_005855fc;
    }
    uVar4 = to->flags;
    uVar5 = uVar4 & 2;
    if (uVar5 == 0) goto LAB_005853fc;
    uVar5 = 0;
    if ((uVar1 & 4) == 0) {
      to->flags = from->flags | uVar4;
      goto LAB_00585428;
    }
LAB_00585598:
    to->flags = 0;
    to->flags = from->flags;
    if (uVar5 == 0) goto LAB_00585428;
LAB_005855b0:
    psVar6 = to->policies;
    psVar10 = from->policies;
    if (psVar6 != (stack_st_ASN1_OBJECT *)0x0) goto LAB_00585448;
  }
  else {
    uVar5 = 1;
    iVar9 = from->trust;
    iVar8 = from->depth;
    uVar4 = to->flags;
    to->purpose = from->purpose;
    to->trust = iVar9;
    to->depth = iVar8;
LAB_005853fc:
    to->check_time = from->check_time;
    to->flags = uVar4 & 0xfffffffd;
    if ((uVar1 & 4) != 0) goto LAB_00585598;
    to->flags = from->flags | uVar4 & 0xfffffffd;
    if (uVar5 != 0) goto LAB_005855b0;
LAB_00585428:
    psVar10 = from->policies;
    if (psVar10 == (stack_st_ASN1_OBJECT *)0x0) {
      return 1;
    }
    if (uVar7 == 0) {
      if (to->policies != (stack_st_ASN1_OBJECT *)0x0) {
        return 1;
      }
      goto LAB_00585468;
    }
    psVar6 = to->policies;
    if (psVar6 == (stack_st_ASN1_OBJECT *)0x0) goto LAB_00585468;
LAB_00585448:
    (*(code *)PTR_sk_pop_free_006a7058)(psVar6,PTR_ASN1_OBJECT_free_006a7004);
  }
  if (psVar10 == (stack_st_ASN1_OBJECT *)0x0) {
    to->policies = (stack_st_ASN1_OBJECT *)0x0;
    return 1;
  }
LAB_00585468:
  psVar6 = (stack_st_ASN1_OBJECT *)(*(code *)PTR_sk_new_null_006a6fa4)();
  to->policies = psVar6;
  if (psVar6 != (stack_st_ASN1_OBJECT *)0x0) {
    iVar8 = 0;
    do {
      iVar9 = (*(code *)PTR_sk_num_006a6e2c)(psVar10);
      if (iVar9 <= iVar8) {
        to->flags = to->flags | 0x80;
        return 1;
      }
      uVar2 = (*(code *)PTR_sk_value_006a6e24)(psVar10,iVar8);
      iVar9 = (*(code *)PTR_OBJ_dup_006a8494)(uVar2);
      if (iVar9 == 0) {
        return 0;
      }
      iVar3 = (*(code *)PTR_sk_push_006a6fa8)(to->policies,iVar9);
      iVar8 = iVar8 + 1;
    } while (iVar3 != 0);
    (*(code *)PTR_ASN1_OBJECT_free_006a7004)(iVar9);
  }
  return 0;
}

