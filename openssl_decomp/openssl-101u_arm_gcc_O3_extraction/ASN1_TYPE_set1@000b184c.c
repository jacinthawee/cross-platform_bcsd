
int ASN1_TYPE_set1(ASN1_TYPE *a,int type,void *value)

{
  ASN1_STRING *pAVar1;
  ASN1_OBJECT *pAVar2;
  ASN1_BOOLEAN AVar3;
  uint uVar4;
  uint uVar5;
  ASN1_TYPE *local_24;
  ASN1_TYPE *local_20;
  ASN1_TYPE *local_1c [2];
  
  uVar5 = count_leading_zeroes(type + -1);
  uVar5 = uVar5 >> 5;
  uVar4 = uVar5;
  if (value == (void *)0x0) {
    uVar4 = uVar5 | 1;
  }
  if (uVar4 == 0) {
    if (type == 6) {
      pAVar2 = OBJ_dup((ASN1_OBJECT *)value);
      if (pAVar2 != (ASN1_OBJECT *)0x0) {
        if ((a->value).ptr != (char *)0x0) {
          local_20 = a;
          ASN1_primitive_free((ASN1_VALUE **)&local_20,(ASN1_ITEM *)0x0);
          a = local_20;
        }
        (a->value).object = pAVar2;
        a->type = 6;
        return 1;
      }
    }
    else {
      pAVar1 = ASN1_STRING_dup((ASN1_STRING *)value);
      if (pAVar1 != (ASN1_STRING *)0x0) {
        if ((a->value).ptr != (char *)0x0) {
          local_1c[0] = a;
          ASN1_primitive_free((ASN1_VALUE **)local_1c,(ASN1_ITEM *)0x0);
          a = local_1c[0];
        }
        a->type = type;
        (a->value).asn1_string = pAVar1;
        return 1;
      }
    }
    return 0;
  }
  if ((a->value).ptr != (char *)0x0) {
    local_24 = a;
    ASN1_primitive_free((ASN1_VALUE **)&local_24,(ASN1_ITEM *)0x0);
    a = local_24;
  }
  a->type = type;
  if (uVar5 != 0) {
    if (value == (void *)0x0) {
      AVar3 = 0;
    }
    else {
      AVar3 = 0xff;
    }
    (a->value).boolean = AVar3;
    return 1;
  }
  (a->value).ptr = (char *)value;
  return 1;
}

