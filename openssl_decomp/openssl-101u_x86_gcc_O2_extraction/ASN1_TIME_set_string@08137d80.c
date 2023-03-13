
int ASN1_TIME_set_string(ASN1_TIME *s,char *str)

{
  int iVar1;
  uint uVar2;
  int in_GS_OFFSET;
  ASN1_UTCTIME local_20;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_20.length = strlen(str);
  local_20.data = (uchar *)str;
  local_20.flags = 0;
  local_20.type = 0x17;
  iVar1 = ASN1_UTCTIME_check(&local_20);
  if (iVar1 == 0) {
    local_20.type = 0x18;
    uVar2 = ASN1_GENERALIZEDTIME_check(&local_20);
    if (uVar2 == 0) goto LAB_08137de7;
  }
  uVar2 = 1;
  if (s != (ASN1_TIME *)0x0) {
    iVar1 = ASN1_STRING_copy(s,&local_20);
    uVar2 = (uint)(iVar1 != 0);
  }
LAB_08137de7:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}

