
int ASN1_STRING_to_UTF8(uchar **out,ASN1_STRING *in)

{
  char cVar1;
  int iVar2;
  int in_GS_OFFSET;
  ASN1_STRING *local_24;
  ASN1_STRING local_20;
  int local_10;
  
  local_24 = &local_20;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (((in == (ASN1_STRING *)0x0) || (0x1e < (uint)in->type)) ||
     (cVar1 = tag2nbyte[in->type], cVar1 == -1)) {
    iVar2 = -1;
  }
  else {
    local_20.data = (uchar *)0x0;
    local_20.length = 0;
    local_20.flags = 0;
    iVar2 = ASN1_mbstring_copy(&local_24,in->data,in->length,
                               CONCAT22((undefined2)(cVar1 >> 7),(short)cVar1) | 0x1000,0x2000);
    if (-1 < iVar2) {
      *out = local_20.data;
      iVar2 = local_20.length;
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

