
/* WARNING: Type propagation algorithm not settling */

void * X509at_get0_data_by_OBJ(stack_st_X509_ATTRIBUTE *x,ASN1_OBJECT *obj,int lastpos,int type)

{
  uint uVar1;
  ASN1_OBJECT **ppAVar2;
  int iVar3;
  void *pvVar4;
  _STACK *a;
  uint uVar5;
  uint uVar6;
  
  if (x == (stack_st_X509_ATTRIBUTE *)0x0) {
    return (void *)0x0;
  }
  uVar1 = sk_num(&x->stack);
  uVar5 = lastpos + 1U & ~((int)(lastpos + 1U) >> 0x1f);
  if ((int)uVar1 <= (int)uVar5) {
    return (void *)0x0;
  }
  while( true ) {
    ppAVar2 = (ASN1_OBJECT **)sk_value(&x->stack,uVar5);
    iVar3 = OBJ_cmp(*ppAVar2,obj);
    if (iVar3 == 0) break;
    uVar5 = uVar5 + 1;
    if (uVar5 == uVar1) {
      return (void *)0x0;
    }
  }
  if (uVar5 == 0xffffffff) {
    return (void *)0x0;
  }
  if (lastpos < -1) {
    uVar1 = sk_num(&x->stack);
    uVar6 = uVar5 + 1 & ~((int)(uVar5 + 1) >> 0x1f);
    if ((int)uVar6 < (int)uVar1) {
      do {
        ppAVar2 = (ASN1_OBJECT **)sk_value(&x->stack,uVar6);
        uVar6 = uVar6 + 1;
        iVar3 = OBJ_cmp(*ppAVar2,obj);
        if (iVar3 == 0) {
          return (void *)0x0;
        }
      } while (uVar6 != uVar1);
    }
  }
  iVar3 = sk_num(&x->stack);
  if (((int)uVar5 < iVar3) && (-1 < (int)uVar5)) {
    pvVar4 = sk_value(&x->stack,uVar5);
    if (lastpos + 2 < 0 != SCARRY4(lastpos,2)) goto LAB_000caae0;
    if (pvVar4 == (void *)0x0) {
      return (void *)0x0;
    }
LAB_000cab2e:
    iVar3 = *(int *)((int)pvVar4 + 4);
    a = *(_STACK **)((int)pvVar4 + 8);
  }
  else {
    if (lastpos + 2 < 0 == SCARRY4(lastpos,2)) {
      return (void *)0x0;
    }
    pvVar4 = (void *)0x0;
LAB_000caae0:
    iVar3 = *(int *)((int)pvVar4 + 4);
    a = *(_STACK **)((int)pvVar4 + 8);
    if (iVar3 == 0) {
      iVar3 = sk_num(a);
      if (iVar3 != 1) {
        return (void *)0x0;
      }
      goto LAB_000cab2e;
    }
    if (a == (_STACK *)0x0) {
      return (void *)0x0;
    }
  }
  if (iVar3 == 0) {
    iVar3 = sk_num(a);
    if (0 < iVar3) {
      if (*(int *)((int)pvVar4 + 4) == 0) {
        a = (_STACK *)sk_value(*(_STACK **)((int)pvVar4 + 8),0);
      }
      else {
        a = *(_STACK **)((int)pvVar4 + 8);
      }
      goto LAB_000caaee;
    }
  }
  else if (a != (_STACK *)0x0) {
LAB_000caaee:
    if (a == (_STACK *)0x0) {
      return (void *)0x0;
    }
    iVar3 = ASN1_TYPE_get((ASN1_TYPE *)a);
    if (type == iVar3) {
      return a->data;
    }
    ERR_put_error(0xb,0x8b,0x7a,"x509_att.c",0x170);
    return (void *)0x0;
  }
  return (void *)0x0;
}

