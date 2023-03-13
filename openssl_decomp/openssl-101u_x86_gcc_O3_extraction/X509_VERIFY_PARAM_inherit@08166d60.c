
int X509_VERIFY_PARAM_inherit(X509_VERIFY_PARAM *to,X509_VERIFY_PARAM *from)

{
  time_t tVar1;
  bool bVar2;
  uint uVar3;
  _STACK *p_Var4;
  ASN1_OBJECT *pAVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  _STACK *p_Var10;
  
  if (from == (X509_VERIFY_PARAM *)0x0) {
    return 1;
  }
  uVar3 = to->inh_flags | from->inh_flags;
  if ((uVar3 & 0x10) != 0) {
    to->inh_flags = 0;
  }
  if ((uVar3 & 8) != 0) {
    return 1;
  }
  uVar8 = uVar3 & 1;
  if ((uVar3 & 2) == 0) {
    if (from->purpose == 0) {
LAB_08166eb1:
      iVar9 = from->trust;
      if (iVar9 != 0) {
        if (uVar8 == 0) goto LAB_08166f53;
LAB_08166ec0:
        to->trust = iVar9;
      }
LAB_08166ec3:
      iVar9 = from->depth;
      if (iVar9 != -1) {
        if (uVar8 == 0) {
LAB_08166f6a:
          if (to->depth != -1) goto LAB_08166ed6;
        }
        to->depth = iVar9;
      }
    }
    else {
      if ((uVar8 != 0) || (to->purpose == 0)) {
        to->purpose = from->purpose;
        goto LAB_08166eb1;
      }
      iVar9 = from->trust;
      if (iVar9 == 0) goto LAB_08166ec3;
LAB_08166f53:
      if (to->trust == 0) goto LAB_08166ec0;
      iVar9 = from->depth;
      if (iVar9 != -1) goto LAB_08166f6a;
    }
LAB_08166ed6:
    uVar7 = to->flags;
    if ((uVar7 & 2) == 0) {
      bVar2 = false;
      goto LAB_08166db4;
    }
    if ((uVar3 & 4) != 0) {
      bVar2 = false;
      goto LAB_08166dc4;
    }
    to->flags = uVar7 | from->flags;
LAB_08166ddb:
    p_Var10 = (_STACK *)from->policies;
    if (p_Var10 == (_STACK *)0x0) {
      return 1;
    }
    if (uVar8 == 0) {
      if (to->policies != (stack_st_ASN1_OBJECT *)0x0) {
        return 1;
      }
      goto LAB_08166e0e;
    }
    p_Var4 = (_STACK *)to->policies;
    if (p_Var4 == (_STACK *)0x0) goto LAB_08166e0e;
LAB_08166df5:
    sk_pop_free(p_Var4,ASN1_OBJECT_free);
  }
  else {
    bVar2 = true;
    to->purpose = from->purpose;
    to->trust = from->trust;
    to->depth = from->depth;
    uVar7 = to->flags;
LAB_08166db4:
    tVar1 = from->check_time;
    uVar7 = uVar7 & 0xfffffffd;
    to->flags = uVar7;
    to->check_time = tVar1;
    if ((uVar3 & 4) != 0) {
LAB_08166dc4:
      to->flags = 0;
      uVar7 = 0;
    }
    to->flags = uVar7 | from->flags;
    if (!bVar2) goto LAB_08166ddb;
    p_Var4 = (_STACK *)to->policies;
    p_Var10 = (_STACK *)from->policies;
    if (p_Var4 != (_STACK *)0x0) goto LAB_08166df5;
  }
  if (p_Var10 == (_STACK *)0x0) {
    to->policies = (stack_st_ASN1_OBJECT *)0x0;
    return 1;
  }
LAB_08166e0e:
  p_Var4 = sk_new_null();
  to->policies = (stack_st_ASN1_OBJECT *)p_Var4;
  if (p_Var4 == (_STACK *)0x0) {
    return 0;
  }
  iVar9 = 0;
  while( true ) {
    iVar6 = sk_num(p_Var10);
    if (iVar6 <= iVar9) {
      to->flags = to->flags | 0x80;
      return 1;
    }
    pAVar5 = (ASN1_OBJECT *)sk_value(p_Var10,iVar9);
    pAVar5 = OBJ_dup(pAVar5);
    if (pAVar5 == (ASN1_OBJECT *)0x0) break;
    iVar6 = sk_push((_STACK *)to->policies,pAVar5);
    if (iVar6 == 0) {
      ASN1_OBJECT_free(pAVar5);
      return 0;
    }
    iVar9 = iVar9 + 1;
  }
  return 0;
}

