
int ASN1_TYPE_set1(ASN1_TYPE *a,int type,void *value)

{
  bool bVar1;
  undefined *puVar2;
  ASN1_STRING *pAVar3;
  int iVar4;
  char *pcVar5;
  ASN1_BOOLEAN AVar6;
  int *piVar7;
  ASN1_TYPE *local_28;
  ASN1_TYPE *local_24;
  ASN1_TYPE *local_20;
  int *local_1c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int **)PTR___stack_chk_guard_006aabf0;
  if (value == (void *)0x0) {
    if ((a->value).ptr != (char *)0x0) goto LAB_0054ef70;
    a->type = type;
    local_28 = a;
    if (type == 1) {
      iVar4 = 1;
      (a->value).ptr = (char *)0x0;
      goto LAB_0054eee0;
    }
  }
  else {
    if (type != 1) {
      if (type == 6) {
        pcVar5 = (char *)(*(code *)PTR_OBJ_dup_006a95b4)(value);
        piVar7 = (int *)type;
        if (pcVar5 != (char *)0x0) {
          local_24 = a;
          if ((a->value).ptr != (char *)0x0) {
            type = 0;
            ASN1_primitive_free((ASN1_VALUE **)&local_24,(ASN1_ITEM *)0x0);
          }
          (local_24->value).ptr = pcVar5;
          iVar4 = 1;
          local_24->type = 6;
          goto LAB_0054eee0;
        }
      }
      else {
        piVar7 = (int *)type;
        pAVar3 = ASN1_STRING_dup((ASN1_STRING *)value);
        if (pAVar3 != (ASN1_STRING *)0x0) {
          local_20 = a;
          if ((a->value).ptr != (char *)0x0) {
            piVar7 = (int *)0x0;
            ASN1_primitive_free((ASN1_VALUE **)&local_20,(ASN1_ITEM *)0x0);
          }
          iVar4 = 1;
          local_20->type = type;
          (local_20->value).asn1_string = pAVar3;
          type = (int)piVar7;
          goto LAB_0054eee0;
        }
      }
      iVar4 = 0;
      type = (int)piVar7;
      goto LAB_0054eee0;
    }
    if ((a->value).ptr == (char *)0x0) {
      a->type = 1;
      iVar4 = 1;
      (a->value).boolean = 0xff;
      local_28 = a;
      goto LAB_0054eee0;
    }
LAB_0054ef70:
    piVar7 = (int *)0x0;
    local_28 = a;
    ASN1_primitive_free((ASN1_VALUE **)&local_28,(ASN1_ITEM *)0x0);
    bVar1 = type == 1;
    local_28->type = type;
    type = (int)piVar7;
    if (bVar1) {
      AVar6 = 0xff;
      if (value == (void *)0x0) {
        AVar6 = 0;
      }
      iVar4 = 1;
      (local_28->value).boolean = AVar6;
      goto LAB_0054eee0;
    }
  }
  (local_28->value).ptr = (char *)value;
  iVar4 = 1;
LAB_0054eee0:
  if (local_1c == *(int **)puVar2) {
    return iVar4;
  }
  piVar7 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (((piVar7 == (int *)0x0) || ((int *)type == (int *)0x0)) ||
     (iVar4 = *piVar7, iVar4 != *(int *)type)) {
    return -1;
  }
  if (iVar4 == 5) {
    return 0;
  }
  if (iVar4 == 6) {
                    /* WARNING: Could not recover jumptable at 0x0054f048. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar4 = (*(code *)PTR_OBJ_cmp_006a9de4)();
    return iVar4;
  }
  iVar4 = ASN1_STRING_cmp((ASN1_STRING *)piVar7[1],*(ASN1_STRING **)(type + 4));
  return iVar4;
}

