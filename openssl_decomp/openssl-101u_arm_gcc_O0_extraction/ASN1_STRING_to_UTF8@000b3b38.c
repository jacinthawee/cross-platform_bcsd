
int ASN1_STRING_to_UTF8(uchar **out,ASN1_STRING *in)

{
  uint uVar1;
  ASN1_STRING *local_24;
  ASN1_STRING local_20;
  
  local_24 = &local_20;
  if ((in == (ASN1_STRING *)0x0) || (0x1e < (uint)in->type)) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = (uint)(char)tag2nbyte[in->type];
    if (uVar1 != 0xffffffff) {
      local_20.data = (uchar *)0x0;
      local_20.length = 0;
      local_20.flags = 0;
      uVar1 = ASN1_mbstring_copy(&local_24,in->data,in->length,uVar1 | 0x1000,0x2000);
      if (-1 < (int)uVar1) {
        *out = local_20.data;
        uVar1 = local_20.length;
      }
    }
  }
  return uVar1;
}

