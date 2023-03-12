
int X509_VERIFY_PARAM_set1(X509_VERIFY_PARAM *to,X509_VERIFY_PARAM *from)

{
  uint uVar1;
  _STACK *p_Var2;
  ASN1_OBJECT *pAVar3;
  ulong uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  time_t tVar8;
  int iVar9;
  _STACK *p_Var10;
  uint uVar11;
  bool bVar12;
  
  uVar11 = to->inh_flags;
  to->inh_flags = uVar11 | 1;
  if (from == (X509_VERIFY_PARAM *)0x0) goto LAB_000cdbe2;
  uVar4 = from->inh_flags;
  uVar6 = uVar11 | 1 | uVar4;
  bVar12 = (int)(uVar6 << 0x1b) < 0;
  if (bVar12) {
    uVar4 = 0;
  }
  if (bVar12) {
    to->inh_flags = uVar4;
  }
  if ((int)(uVar6 << 0x1c) < 0) goto LAB_000cdbe2;
  if ((int)(uVar6 << 0x1e) < 0) {
    uVar1 = 1;
    iVar9 = from->purpose;
    iVar7 = from->trust;
    to->depth = from->depth;
    uVar5 = to->flags;
    to->purpose = iVar9;
    to->trust = iVar7;
LAB_000cdb74:
    tVar8 = from->check_time;
    uVar5 = uVar5 & 0xfffffffd;
    to->flags = uVar5;
    to->check_time = tVar8;
  }
  else {
    if (from->purpose != 0) {
      to->purpose = from->purpose;
    }
    if (from->trust != 0) {
      to->trust = from->trust;
    }
    if (from->depth != -1) {
      to->depth = from->depth;
    }
    uVar5 = to->flags;
    uVar1 = uVar5 & 2;
    if (uVar1 == 0) goto LAB_000cdb74;
    uVar1 = 0;
  }
  bVar12 = (int)(uVar6 << 0x1d) < 0;
  p_Var10 = (_STACK *)from->policies;
  if (bVar12) {
    uVar5 = 0;
  }
  if (bVar12) {
    to->flags = uVar5;
  }
  to->flags = uVar5 | from->flags;
  if ((uVar1 != 0) || (p_Var10 != (_STACK *)0x0)) {
    if ((_STACK *)to->policies != (_STACK *)0x0) {
      sk_pop_free((_STACK *)to->policies,ASN1_OBJECT_free);
    }
    if (p_Var10 != (_STACK *)0x0) {
      p_Var2 = sk_new_null();
      to->policies = (stack_st_ASN1_OBJECT *)p_Var2;
      if (p_Var2 != (_STACK *)0x0) {
        iVar7 = 0;
        do {
          iVar9 = sk_num(p_Var10);
          if (iVar9 <= iVar7) {
            to->flags = to->flags | 0x80;
            goto LAB_000cdbe2;
          }
          pAVar3 = (ASN1_OBJECT *)sk_value(p_Var10,iVar7);
          pAVar3 = OBJ_dup(pAVar3);
          if (pAVar3 == (ASN1_OBJECT *)0x0) goto LAB_000cdc14;
          iVar9 = sk_push((_STACK *)to->policies,pAVar3);
          iVar7 = iVar7 + 1;
        } while (iVar9 != 0);
        ASN1_OBJECT_free(pAVar3);
      }
LAB_000cdc14:
      to->inh_flags = uVar11;
      return 0;
    }
    to->policies = (stack_st_ASN1_OBJECT *)0x0;
  }
LAB_000cdbe2:
  to->inh_flags = uVar11;
  return 1;
}

