
ASN1_OBJECT * ASN1_OBJECT_create(int nid,uchar *data,int len,char *sn,char *ln)

{
  undefined *puVar1;
  ASN1_OBJECT *pAVar2;
  ASN1_STRING *str;
  char *local_24;
  char *local_20;
  int local_1c;
  int local_18;
  uchar *local_14;
  undefined4 local_10;
  ASN1_STRING *local_c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_20 = ln;
  local_10 = 0xd;
  local_c = *(ASN1_STRING **)PTR___stack_chk_guard_006aabf0;
  local_24 = sn;
  local_1c = nid;
  local_18 = len;
  local_14 = data;
  pAVar2 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_dup_006a95b4)(&local_24);
  if (local_c == *(ASN1_STRING **)puVar1) {
    return pAVar2;
  }
  str = local_c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  pAVar2 = (ASN1_OBJECT *)ASN1_STRING_set(str,data,len);
  return pAVar2;
}

