
int X509_VERIFY_PARAM_inherit(X509_VERIFY_PARAM *to,X509_VERIFY_PARAM *from)

{
  uint uVar1;
  _STACK *p_Var2;
  ASN1_OBJECT *pAVar3;
  ulong uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  time_t tVar9;
  int iVar10;
  _STACK *p_Var11;
  bool bVar12;
  
  if (from == (X509_VERIFY_PARAM *)0x0) {
    return 1;
  }
  uVar4 = from->inh_flags;
  uVar6 = to->inh_flags | uVar4;
  bVar12 = (int)(uVar6 << 0x1b) < 0;
  if (bVar12) {
    uVar4 = 0;
  }
  if (bVar12) {
    to->inh_flags = uVar4;
  }
  if ((int)(uVar6 << 0x1c) < 0) {
    return 1;
  }
  uVar1 = uVar6 & 1;
  if ((int)(uVar6 << 0x1e) < 0) {
    uVar7 = 1;
    iVar10 = from->purpose;
    iVar8 = from->trust;
    to->depth = from->depth;
    uVar5 = to->flags;
    to->purpose = iVar10;
    to->trust = iVar8;
LAB_000cfaca:
    tVar9 = from->check_time;
    uVar5 = uVar5 & 0xfffffffd;
    to->flags = uVar5;
    to->check_time = tVar9;
  }
  else if (from->purpose == 0) {
LAB_000cfb4e:
    iVar8 = from->trust;
    if (iVar8 != 0) {
      if (uVar1 == 0) goto LAB_000cfb54;
LAB_000cfb58:
      to->trust = iVar8;
    }
LAB_000cfb5a:
    iVar8 = from->depth;
    if (iVar8 == -1) goto LAB_000cfb68;
    if (uVar1 == 0) {
LAB_000cfb62:
      if (to->depth != -1) goto LAB_000cfb68;
    }
    to->depth = iVar8;
    uVar5 = to->flags;
    uVar7 = uVar5 & 2;
    if (uVar7 == 0) goto LAB_000cfaca;
    uVar7 = 0;
  }
  else {
    if ((uVar1 != 0) || (to->purpose == 0)) {
      to->purpose = from->purpose;
      goto LAB_000cfb4e;
    }
    iVar8 = from->trust;
    if (iVar8 == 0) goto LAB_000cfb5a;
LAB_000cfb54:
    if (to->trust == 0) goto LAB_000cfb58;
    iVar8 = from->depth;
    if (iVar8 != -1) goto LAB_000cfb62;
LAB_000cfb68:
    uVar5 = to->flags;
    uVar7 = uVar5 & 2;
    if (uVar7 == 0) goto LAB_000cfaca;
    uVar7 = 0;
  }
  bVar12 = (int)(uVar6 << 0x1d) < 0;
  p_Var11 = (_STACK *)from->policies;
  if (bVar12) {
    uVar5 = 0;
  }
  if (bVar12) {
    to->flags = uVar5;
  }
  to->flags = uVar5 | from->flags;
  if (uVar7 == 0) {
    if (p_Var11 == (_STACK *)0x0) {
      return 1;
    }
    if (uVar1 == 0) {
      if (to->policies != (stack_st_ASN1_OBJECT *)0x0) {
        return 1;
      }
      goto LAB_000cfb00;
    }
  }
  if ((_STACK *)to->policies != (_STACK *)0x0) {
    sk_pop_free((_STACK *)to->policies,ASN1_OBJECT_free);
  }
  if (p_Var11 == (_STACK *)0x0) {
    to->policies = (stack_st_ASN1_OBJECT *)0x0;
    return 1;
  }
LAB_000cfb00:
  p_Var2 = sk_new_null();
  to->policies = (stack_st_ASN1_OBJECT *)p_Var2;
  if (p_Var2 != (_STACK *)0x0) {
    iVar8 = 0;
    do {
      iVar10 = sk_num(p_Var11);
      if (iVar10 <= iVar8) {
        to->flags = to->flags | 0x80;
        return 1;
      }
      pAVar3 = (ASN1_OBJECT *)sk_value(p_Var11,iVar8);
      pAVar3 = OBJ_dup(pAVar3);
      if (pAVar3 == (ASN1_OBJECT *)0x0) {
        return 0;
      }
      iVar10 = sk_push((_STACK *)to->policies,pAVar3);
      iVar8 = iVar8 + 1;
    } while (iVar10 != 0);
    ASN1_OBJECT_free(pAVar3);
  }
  return 0;
}

