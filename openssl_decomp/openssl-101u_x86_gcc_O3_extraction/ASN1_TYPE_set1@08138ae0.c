
int ASN1_TYPE_set1(ASN1_TYPE *a,int type,void *value)

{
  int iVar1;
  ASN1_OBJECT *pAVar2;
  ASN1_TYPE *pAVar3;
  int in_GS_OFFSET;
  ASN1_TYPE *local_1c;
  ASN1_TYPE *local_18;
  ASN1_TYPE *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if ((value == (void *)0x0) || (type == 1)) {
    local_1c = a;
    if ((a->value).ptr != (char *)0x0) {
      ASN1_primitive_free((ASN1_VALUE **)&local_1c,(ASN1_ITEM *)0x0);
    }
    local_1c->type = type;
    pAVar3 = local_1c;
    if (type == 1) {
      (local_1c->value).boolean = ~-(uint)(value == (void *)0x0) & 0xff;
      iVar1 = 1;
      goto LAB_08138b55;
    }
LAB_08138b4d:
    (pAVar3->value).asn1_string = (ASN1_STRING *)value;
    iVar1 = 1;
  }
  else {
    if (type == 6) {
      pAVar2 = OBJ_dup((ASN1_OBJECT *)value);
      if (pAVar2 != (ASN1_OBJECT *)0x0) {
        local_18 = a;
        if ((a->value).ptr != (char *)0x0) {
          ASN1_primitive_free((ASN1_VALUE **)&local_18,(ASN1_ITEM *)0x0);
        }
        local_18->type = 6;
        (local_18->value).object = pAVar2;
        iVar1 = 1;
        goto LAB_08138b55;
      }
    }
    else {
      value = ASN1_STRING_dup((ASN1_STRING *)value);
      if ((ASN1_STRING *)value != (ASN1_STRING *)0x0) {
        local_14 = a;
        if ((a->value).ptr != (char *)0x0) {
          ASN1_primitive_free((ASN1_VALUE **)&local_14,(ASN1_ITEM *)0x0);
        }
        local_14->type = type;
        pAVar3 = local_14;
        goto LAB_08138b4d;
      }
    }
    iVar1 = 0;
  }
LAB_08138b55:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

