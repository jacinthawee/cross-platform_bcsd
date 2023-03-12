
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
LAB_005882b0:
      iVar8 = from->trust;
      if (iVar8 != 0) {
        if (uVar7 == 0) goto LAB_0058834c;
LAB_005882c4:
        to->trust = iVar8;
      }
LAB_005882c8:
      iVar8 = from->depth;
      if (iVar8 != -1) {
        if (uVar7 == 0) {
LAB_00588364:
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
        goto LAB_005882b0;
      }
      iVar8 = from->trust;
      if (iVar8 == 0) goto LAB_005882c8;
LAB_0058834c:
      if (to->trust == 0) goto LAB_005882c4;
      iVar8 = from->depth;
      if (iVar8 != -1) goto LAB_00588364;
    }
    uVar4 = to->flags;
    uVar5 = uVar4 & 2;
    if (uVar5 == 0) goto LAB_00588164;
    uVar5 = 0;
    if ((uVar1 & 4) == 0) {
      to->flags = from->flags | uVar4;
      goto LAB_00588190;
    }
LAB_00588300:
    to->flags = 0;
    to->flags = from->flags;
    if (uVar5 == 0) goto LAB_00588190;
LAB_00588318:
    psVar6 = to->policies;
    psVar10 = from->policies;
    if (psVar6 != (stack_st_ASN1_OBJECT *)0x0) goto LAB_005881b0;
  }
  else {
    uVar5 = 1;
    iVar9 = from->trust;
    iVar8 = from->depth;
    uVar4 = to->flags;
    to->purpose = from->purpose;
    to->trust = iVar9;
    to->depth = iVar8;
LAB_00588164:
    to->check_time = from->check_time;
    to->flags = uVar4 & 0xfffffffd;
    if ((uVar1 & 4) != 0) goto LAB_00588300;
    to->flags = from->flags | uVar4 & 0xfffffffd;
    if (uVar5 != 0) goto LAB_00588318;
LAB_00588190:
    psVar10 = from->policies;
    if (psVar10 == (stack_st_ASN1_OBJECT *)0x0) {
      return 1;
    }
    if (uVar7 == 0) {
      if (to->policies != (stack_st_ASN1_OBJECT *)0x0) {
        return 1;
      }
      goto LAB_005881d0;
    }
    psVar6 = to->policies;
    if (psVar6 == (stack_st_ASN1_OBJECT *)0x0) goto LAB_005881d0;
LAB_005881b0:
    (*(code *)PTR_sk_pop_free_006a8158)(psVar6,PTR_ASN1_OBJECT_free_006a8104);
  }
  if (psVar10 == (stack_st_ASN1_OBJECT *)0x0) {
    to->policies = (stack_st_ASN1_OBJECT *)0x0;
    return 1;
  }
LAB_005881d0:
  psVar6 = (stack_st_ASN1_OBJECT *)(*(code *)PTR_sk_new_null_006a80a4)();
  to->policies = psVar6;
  if (psVar6 != (stack_st_ASN1_OBJECT *)0x0) {
    iVar8 = 0;
    do {
      iVar9 = (*(code *)PTR_sk_num_006a7f2c)(psVar10);
      if (iVar9 <= iVar8) {
        to->flags = to->flags | 0x80;
        return 1;
      }
      uVar2 = (*(code *)PTR_sk_value_006a7f24)(psVar10,iVar8);
      iVar9 = (*(code *)PTR_OBJ_dup_006a95b4)(uVar2);
      if (iVar9 == 0) {
        return 0;
      }
      iVar3 = (*(code *)PTR_sk_push_006a80a8)(to->policies,iVar9);
      iVar8 = iVar8 + 1;
    } while (iVar3 != 0);
    (*(code *)PTR_ASN1_OBJECT_free_006a8104)(iVar9);
  }
  return 0;
}

