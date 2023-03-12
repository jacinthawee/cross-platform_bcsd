
int i2d_ASN1_BOOLEAN(int a,uchar **pp)

{
  int iVar1;
  int in_GS_OFFSET;
  uchar *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = ASN1_object_size(0,1,1);
  if (pp != (uchar **)0x0) {
    local_14 = *pp;
    ASN1_put_object(&local_14,0,1,1,0);
    *local_14 = (uchar)a;
    *pp = local_14 + 1;
    local_14 = local_14 + 1;
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

