
int d2i_ASN1_BOOLEAN(int *a,uchar **pp,long length)

{
  uint uVar1;
  int reason;
  int in_GS_OFFSET;
  byte *local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_20 = *pp;
  uVar1 = ASN1_get_object(&local_20,&local_1c,&local_18,&local_14,length);
  if ((uVar1 & 0x80) == 0) {
    if (local_18 == 1) {
      if (local_1c == 1) {
        uVar1 = (uint)*local_20;
        if (a != (int *)0x0) {
          *a = uVar1;
        }
        *pp = local_20 + 1;
        local_20 = local_20 + 1;
        goto LAB_081ce587;
      }
      reason = 0x6a;
    }
    else {
      reason = 0x75;
    }
  }
  else {
    reason = 0x66;
  }
  ERR_put_error(0xd,0x8e,reason,"a_bool.c",0x6e);
  uVar1 = 0xffffffff;
LAB_081ce587:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

