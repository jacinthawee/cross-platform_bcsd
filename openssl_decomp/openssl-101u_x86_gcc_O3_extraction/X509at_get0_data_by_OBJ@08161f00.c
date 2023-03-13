
void * X509at_get0_data_by_OBJ(stack_st_X509_ATTRIBUTE *x,ASN1_OBJECT *obj,int lastpos,int type)

{
  int iVar1;
  ASN1_OBJECT **ppAVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  ASN1_TYPE *a;
  
  if (x == (stack_st_X509_ATTRIBUTE *)0x0) {
    return (void *)0x0;
  }
  iVar5 = 0;
  if (-1 < lastpos + 1) {
    iVar5 = lastpos + 1;
  }
  iVar1 = sk_num(&x->stack);
  if (iVar1 <= iVar5) {
    return (void *)0x0;
  }
  while( true ) {
    ppAVar2 = (ASN1_OBJECT **)sk_value(&x->stack,iVar5);
    iVar3 = OBJ_cmp(*ppAVar2,obj);
    if (iVar3 == 0) break;
    iVar5 = iVar5 + 1;
    if (iVar1 == iVar5) {
      return (void *)0x0;
    }
  }
  if (iVar5 == -1) {
    return (void *)0x0;
  }
  if (lastpos < -1) {
    if (-1 < iVar5 + 1) {
      iVar3 = iVar5 + 1;
    }
    iVar1 = sk_num(&x->stack);
    if (iVar3 < iVar1) {
      do {
        ppAVar2 = (ASN1_OBJECT **)sk_value(&x->stack,iVar3);
        iVar6 = OBJ_cmp(*ppAVar2,obj);
        if (iVar6 == 0) {
          if (iVar3 != -1) {
            return (void *)0x0;
          }
          break;
        }
        iVar3 = iVar3 + 1;
      } while (iVar1 != iVar3);
    }
  }
  iVar1 = sk_num(&x->stack);
  if ((iVar5 < 0) || (iVar1 <= iVar5)) {
    pvVar4 = (void *)0x0;
    if (-3 < lastpos) {
      return (void *)0x0;
    }
LAB_08161fb1:
    if (*(int *)((int)pvVar4 + 4) == 0) {
      iVar5 = sk_num(*(_STACK **)((int)pvVar4 + 8));
      if (iVar5 != 1) {
        return (void *)0x0;
      }
      goto LAB_08162064;
    }
  }
  else {
    pvVar4 = sk_value(&x->stack,iVar5);
    if (lastpos < -2) goto LAB_08161fb1;
    if (pvVar4 == (void *)0x0) {
      return (void *)0x0;
    }
LAB_08162064:
    if (*(int *)((int)pvVar4 + 4) == 0) {
      iVar5 = sk_num(*(_STACK **)((int)pvVar4 + 8));
      if (iVar5 < 1) {
        return (void *)0x0;
      }
      if (*(int *)((int)pvVar4 + 4) == 0) {
        a = (ASN1_TYPE *)sk_value(*(_STACK **)((int)pvVar4 + 8),0);
      }
      else {
        a = *(ASN1_TYPE **)((int)pvVar4 + 8);
      }
      goto joined_r0x0816209c;
    }
  }
  a = *(ASN1_TYPE **)((int)pvVar4 + 8);
joined_r0x0816209c:
  if (a != (ASN1_TYPE *)0x0) {
    iVar5 = ASN1_TYPE_get(a);
    if (type == iVar5) {
      return (a->value).ptr;
    }
    ERR_put_error(0xb,0x8b,0x7a,"x509_att.c",0x170);
  }
  return (void *)0x0;
}

