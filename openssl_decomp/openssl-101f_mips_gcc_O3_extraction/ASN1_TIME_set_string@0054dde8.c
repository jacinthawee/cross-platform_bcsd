
int ASN1_TIME_set_string(ASN1_TIME *s,char *str)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  ASN1_STRING *pAVar4;
  ASN1_UTCTIME local_2c;
  ASN1_STRING *local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(ASN1_STRING **)PTR___stack_chk_guard_006aabf0;
  local_2c.length = (*(code *)PTR_strlen_006aab30)(str);
  local_2c.flags = 0;
  local_2c.type = 0x17;
  local_2c.data = (uchar *)str;
  iVar2 = ASN1_UTCTIME_check(&local_2c);
  if (iVar2 == 0) {
    local_2c.type = 0x18;
    uVar3 = ASN1_GENERALIZEDTIME_check(&local_2c);
    if (uVar3 == 0) goto LAB_0054de80;
    if (s == (ASN1_TIME *)0x0) {
      uVar3 = 1;
      goto LAB_0054de80;
    }
  }
  else {
    uVar3 = 1;
    if (s == (ASN1_TIME *)0x0) goto LAB_0054de80;
  }
  iVar2 = ASN1_STRING_copy(s,&local_2c);
  uVar3 = (uint)(iVar2 != 0);
LAB_0054de80:
  if (local_1c != *(ASN1_STRING **)puVar1) {
    pAVar4 = local_1c;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    pAVar4 = ASN1_STRING_dup(pAVar4);
    return (int)pAVar4;
  }
  return uVar3;
}

